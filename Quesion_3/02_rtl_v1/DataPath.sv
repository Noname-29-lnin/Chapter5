module DataPath #(
    parameter SIZE_ADDR = 8 ,
    parameter SIZE_DATA = 8 
)(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    input logic [SIZE_ADDR-1:0]         i_num_elems ,

    input logic                         i_start_j   ,
    input logic                         i_en_i      ,
    input logic                         i_rd_en     ,
    output logic                        o_done_rd   ,
    output logic                        o_done_wr   ,
    output logic                        o_done_j    ,
    
    input logic [SIZE_DATA-1:0]         i_data_ram  ,
    output logic                        o_rd_en     ,
    output logic                        o_wr_en     ,
    output logic [SIZE_ADDR-1:0]        o_addr_ram  ,
    output logic [SIZE_DATA-1:0]        o_data_ram   
);

logic                   w_UPDATE_J_en;
logic [SIZE_ADDR-1:0]   w_UPDATE_J_value_j;
logic                   w_UPDATE_J_done;
logic                   w_UPDATE_I_start;
logic                   w_UPDATE_I_start_start;
logic                   w_UPDATE_I_start_done;
logic                   w_UPDATE_I_done;
logic [SIZE_ADDR-1:0]   w_UPDATE_I_value_i;

logic                   w_UPDATE_SMALLEST_en;
logic                   w_UPDATE_SMALLEST_select;
logic [SIZE_ADDR-1:0]   w_UPDATE_SMALLEST_value_smallest;


logic                   w_SWAP_compare;

update_value_j #(
    .SIZE_ADDR  (SIZE_ADDR) 
) UPDATE_VALUE_J_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_num_elems        (i_num_elems),
    .i_start            (i_start_j),
    .i_en               (w_UPDATE_I_done),
    .o_en               (w_UPDATE_J_en),
    .o_value_j          (w_UPDATE_J_value_j),
    .o_done             (w_UPDATE_J_done) 
);
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_start_update_i
    if(~i_rst_n) begin
        w_UPDATE_I_start_start      <= '0;
        w_UPDATE_I_start_done       <= '0;
    end else begin
        w_UPDATE_I_start_start      <= i_start_j;
        w_UPDATE_I_start_done       <= w_UPDATE_I_done;
    end
end
assign w_UPDATE_I_start = w_UPDATE_I_start_done | w_UPDATE_I_start_start;
update_value_i #(
    .SIZE_ADDR  (SIZE_ADDR) 
) UPDATE_VALUE_I_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_num_elems        (i_num_elems),
    .i_start            (w_UPDATE_I_start),
    .i_en               (i_en_i),
    .i_value_j          (w_UPDATE_J_value_j),
    .o_value_i          (w_UPDATE_I_value_i),
    .o_done             (w_UPDATE_I_done) 
);
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_enable_update_smallest
    if(~i_rst_n) begin
        w_UPDATE_SMALLEST_en        <= '0;
    end else begin
        w_UPDATE_SMALLEST_en        <= w_UPDATE_J_en;
    end
end
update_value_smmallest #(
    .SIZE_ADDR  (SIZE_ADDR)
) UPDATE_VALUE_SMALLEST_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_value_j          (w_UPDATE_J_value_j),
    .i_value_i          (w_UPDATE_I_value_i),
    .i_en               (w_UPDATE_SMALLEST_en),
    .i_select           (w_UPDATE_SMALLEST_select), // 0 -> J | 1 -> I
    .o_value_smallest   (w_UPDATE_SMALLEST_value_smallest) 
);

Swap_unit #(
    .SIZE_ADDR          (SIZE_ADDR),
    .SIZE_DATA          (SIZE_DATA)
) SWAP_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_rd_en            (i_rd_en),
    .i_addr_i           (w_UPDATE_I_value_i),
    .i_addr_smallest    (w_UPDATE_SMALLEST_value_smallest),
    .i_data_ram         (i_data_ram),
    .o_rd_en            (o_rd_en),
    .o_wr_en            (o_wr_en),
    .o_addr_ram         (o_addr_ram),
    .o_data_ram         (o_data_ram),
    .o_compare          (w_SWAP_compare),
    .o_done_rd          (o_done_rd),
    .o_done_wr          (o_done_wr) 
);
assign w_UPDATE_SMALLEST_select = (~w_UPDATE_SMALLEST_en) & w_SWAP_compare;
assign o_done_j = w_UPDATE_J_done;
endmodule

module update_value_j #(
    parameter SIZE_ADDR = 8 
)(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    input logic [SIZE_ADDR-1:0]         i_num_elems ,
  
    input logic                         i_start     ,
    input logic                         i_en        ,


    output logic                        o_en        ,
    output logic [SIZE_ADDR-1:0]        o_value_j   ,
    output logic                        o_done       
);

logic w_start;
logic [SIZE_ADDR-1:0]   w_pre_value_j;
logic [SIZE_ADDR-1:0]   w_next_value_j;
logic w_pre_done;
logic w_enable;

assign w_pre_done       = (o_value_j == (i_num_elems - 1'b1));
assign w_start          = i_start | w_pre_done;
assign w_enable         = w_start | i_en;
assign w_next_value_j   = o_value_j + 1'b1; 
assign w_pre_value_j    = w_start ? ('0) : (w_next_value_j);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_value_j
    if(~i_rst_n) begin
        o_value_j       <= '0;
    end else if(w_enable) begin 
        o_value_j       <= w_pre_value_j;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_done
    if(~i_rst_n) begin
        o_done          <= '0;
    end else begin 
        o_done          <= w_pre_done;
    end
end

assign o_en = w_enable;

endmodule

module update_value_i #(
    parameter SIZE_ADDR = 8 
)(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    input logic [SIZE_ADDR-1:0]         i_num_elems ,
  
    input logic                         i_start     ,
    input logic                         i_en        ,
    input logic [SIZE_ADDR-1:0]         i_value_j   ,


    output logic [SIZE_ADDR-1:0]        o_value_i   ,
    output logic                        o_done       
);

logic w_enable;
logic w_start;
logic [SIZE_ADDR-1:0] w_pre_value_i;
logic [SIZE_ADDR-1:0] w_next_value_i;
logic w_pre_done;

assign w_start          = i_start;
assign w_enable         = w_start | i_en;
assign w_next_value_i   = o_value_i + 1'b1;
assign w_pre_value_i    = w_start ? (i_value_j + 1'b1) : (w_next_value_i);
assign w_pre_done       = (o_value_i == i_num_elems);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_data
    if(~i_rst_n) begin
        o_value_i       <= '0; 
    end else if(w_enable) begin
        o_value_i       <= w_pre_value_i;
    end 
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_done
    if(~i_rst_n) begin
        o_done          <= '0;
    end else begin 
        o_done          <= w_pre_done;
    end
end

endmodule

module update_value_smmallest #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,
    input logic [SIZE_ADDR-1:0]     i_value_j       ,
    input logic [SIZE_ADDR-1:0]     i_value_i       ,
    input logic                     i_en            ,
    input logic                     i_select        , // 0 -> J | 1 -> I
    output logic [SIZE_ADDR-1:0]    o_value_smallest     
);

logic w_enable;
assign w_enable = i_en | i_select;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_data
    if(~i_rst_n) begin
        o_value_smallest        <= '0; 
    end else if(w_enable) begin
        o_value_smallest        <= (i_select) ? i_value_i : i_value_j;
    end
end

endmodule

