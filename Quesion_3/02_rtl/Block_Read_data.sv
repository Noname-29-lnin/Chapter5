module Block_Read_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,
    input logic                     i_rd_en         ,
    input logic [1:0]               i_sel_data_rd   ,
    input logic [SIZE_DATA-1:0]     i_data_ram      ,

    output logic                    o_rd_en         ,
    output logic [SIZE_DATA-1:0]    o_temp_min      ,
    output logic [SIZE_DATA-1:0]    o_temp_data     ,
    output logic [SIZE_DATA-1:0]    o_data_key      ,
    output logic                    o_done           
);

logic [SIZE_DATA-1:0] w_data_ram;
logic w_valid_rd;

logic w_rst_sel_data_rd;
logic [1:0] w_sel_data_rd;

logic w_en_temp_min;
logic w_en_temp_data;
logic w_en_data_key;

logic w_i_rd_en;
SS_detect_edge #(
    .POS_EDGE   (1)   // 1: posedge, 0: negedge
) DETECT_EDGE (
    .i_clk      (i_clk),
    .i_rst_n    (i_rst_n),
    .i_signal   (i_rd_en),
    .o_signal   (w_i_rd_en)
);

assign w_rst_sel_data_rd = (i_rst_n & ~o_done);
always_ff @( posedge i_clk or negedge w_rst_sel_data_rd ) begin
    if(~w_rst_sel_data_rd) begin
        w_sel_data_rd   <= '0;
    end else if(w_i_rd_en) begin
        w_sel_data_rd   <= i_sel_data_rd;
    end
end

RAM_read_data #(
    .SIZE_DATA      (SIZE_DATA)
) RAM_READ_DATAA (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_rd_en        (w_i_rd_en),
    .i_data_rd      (i_data_ram),
    .o_rd_en        (o_rd_en),
    .o_data_rd      (w_data_ram),
    .o_valid        (w_valid_rd) 
);

assign w_en_temp_min    = (w_sel_data_rd[1] & w_sel_data_rd[0]) & w_valid_rd;
assign w_en_temp_data   = (w_sel_data_rd[1] & ~w_sel_data_rd[0]) & w_valid_rd;
assign w_en_data_key    = (~w_sel_data_rd[1] & w_sel_data_rd[0]) & w_valid_rd;

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_temp_min      <= '0;
    end else if(w_en_temp_min) begin
        o_temp_min      <= w_data_ram;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_temp_data      <= '0;
    end else if(w_en_temp_data) begin
        o_temp_data      <= w_data_ram;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_data_key      <= '0;
    end else if(w_en_data_key) begin
        o_data_key      <= w_data_ram;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_done      <= '0;
    end else begin
        o_done      <= (w_en_temp_min | w_en_temp_data | w_en_data_key);
    end
end

endmodule
