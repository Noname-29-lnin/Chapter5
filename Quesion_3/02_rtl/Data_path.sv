// module Data_path #(
//     parameter SIZE_ADDR = 8,
//     parameter SIZE_DATA = 8
// )(
//     input logic                     i_clk           ,
//     input logic                     i_rst_n         ,
//     input logic [SIZE_ADDR-1:0]     i_num_elems     ,

//     input logic                     i_rd_en         ,
//     input logic                     i_wr_en         ,
//     input logic [1:0]               i_sel_addr      ,
//     input logic [1:0]               i_sel_data_rd   ,
//     input logic                     i_sel_data_wr   ,
//     input logic                     i_start_i       , //i_state=>topmodule
//     input logic                     i_update_i      ,
//     input logic                     i_update_j      ,
//     input logic                     i_update_min    ,

//     input logic [SIZE_DATA-1:0]     i_data_ram      ,
//     output logic                    o_wr_en         ,
//     output logic                    o_rd_en         ,
//     output logic [SIZE_ADDR-1:0]    o_addr_ram      ,
//     output logic [SIZE_DATA-1:0]    o_data_ram      ,

//     output logic                    o_comp_less     ,
//     output logic                    o_valid_wr      ,
//     output logic                    o_valid_rd      ,
//     output logic                    o_done_j        ,
//     output logic                    o_done_sort      
// );

// logic [SIZE_ADDR-1:0] value_i;
// logic                 w_o_en_i;
// logic [SIZE_ADDR-1:0] value_j;
// logic                 w_i_en_j;
// logic [SIZE_ADDR-1:0] value_min;

// logic                 w_en_temp_min;
// logic [SIZE_DATA-1:0] w_temp_min;
// logic                 w_en_temp_data;
// logic [SIZE_DATA-1:0] w_temp_data;
// logic                 w_en_data_key;
// logic [SIZE_DATA-1:0] w_data_key;

// logic [SIZE_ADDR-1:0] w_addr_ram;
// logic [SIZE_DATA-1:0] w_data_wr;
// logic [SIZE_DATA-1:0] w_data_rd;

// assign o_comp_less = w_temp_data < w_temp_min;

// Update_I #(
//     .SIZE_ADDR      (SIZE_ADDR)
// ) UPDATE_I_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_num_elems    (i_num_elems),
//     .i_start        (i_start_i),
//     .i_en           (i_update_i),
//     .o_en           (w_o_en_i),
//     .o_value_i      (value_i),
//     .o_done         (o_done_sort) 
// );

// always_ff @( posedge i_clk or negedge i_rst_n) begin 
//     if(~i_rst_n)
//         w_i_en_j    <= '0;
//     else 
//         w_i_en_j    <= w_o_en_i;
// end

// Update_J #(
//     .SIZE_ADDR      (SIZE_ADDR)
// ) UPDATE_J_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_num_elems    (i_num_elems),
//     .i_value_i      (value_i),
//     .i_start        (w_i_en_j),
//     .i_en           (i_update_j),
//     .o_en           (),
//     .o_value_j      (value_j),
//     .o_done         (o_done_j) 
// );

// Update_MIN #(
//     .SIZE_ADDR      (SIZE_ADDR)
// ) UPDATE_MIN_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_value_i      (value_i),
//     .i_value_j      (value_j),
//     .i_update_i     (w_i_en_j),
//     .i_update_min   (i_update_min),
//     .o_addr_min     (value_min) 
// );

// assign w_addr_ram = i_sel_addr[1] ? value_i : (i_sel_addr[0] ? value_min : value_j);
// RAM_addr #(
//     .SIZE_ADDR      (SIZE_ADDR)
// ) RAM_ADDR_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_rd_en        (i_rd_en),
//     .i_wr_en        (i_wr_en),
//     .i_addr_ram     (w_addr_ram),
//     .o_addr_ram     (o_addr_ram) 
// );
// RAM_read_data #(
//     .SIZE_DATA      (SIZE_DATA)
// ) RAM_READ_DATA_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_rd_en        (i_rd_en),
//     .i_data_rd      (i_data_ram),
//     .o_rd_en        (o_rd_en),
//     .o_data_rd      (w_data_rd),
//     .o_valid        (o_valid_rd) 
// );

// assign w_en_temp_min = (~i_sel_data_rd[1] & i_sel_data_rd[0]) & o_valid_rd;
// always_ff @( posedge i_clk or negedge i_rst_n ) begin
//     if(~i_rst_n) begin
//         w_temp_min      <= '0;
//     end else if(w_en_temp_min) begin
//         w_temp_min      <= w_data_rd;
//     end
// end

// assign w_en_temp_data = (~i_sel_data_rd[1] & ~i_sel_data_rd[0]) & o_valid_rd;
// always_ff @( posedge i_clk or negedge i_rst_n ) begin
//     if(~i_rst_n) begin
//         w_temp_data     <= '0;
//     end else if(w_en_temp_data) begin
//         w_temp_data     <= w_data_rd;
//     end
// end

// assign w_en_data_key = (i_sel_data_rd[1] & ~i_sel_data_rd[0]) & o_valid_rd;
// always_ff @( posedge i_clk or negedge i_rst_n ) begin
//     if(~i_rst_n) begin
//         w_data_key     <= '0;
//     end else if(w_en_data_key) begin
//         w_data_key     <= w_data_rd;
//     end
// end

// assign w_data_wr = i_sel_data_wr ? w_temp_min : w_data_key;
// RAM_write_data #(
//     .SIZE_DATA      (SIZE_DATA)
// ) RAM_WRITE_DATA_UNIT (
//     .i_clk          (i_clk),
//     .i_rst_n        (i_rst_n),
//     .i_wr_en        (i_wr_en),
//     .i_data_wr      (w_data_wr),
//     .o_wr_en        (o_wr_en),
//     .o_data_wr      (o_data_ram),
//     .o_done         (o_valid_wr) 
// );

// endmodule

module Data_path #(
    parameter SIZE_ADDR = 8,
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,
    input logic [SIZE_ADDR-1:0]     i_num_elems     ,

    input logic                     i_rd_en         ,
    input logic                     i_wr_en         ,
    input logic [1:0]               i_sel_addr      ,
    input logic [1:0]               i_sel_data_rd   ,
    input logic                     i_sel_data_wr   ,
    input logic                     i_start_i       , //i_state=>topmodule
    input logic                     i_start_j       , 
    input logic                     i_update_i      ,
    input logic                     i_update_j      ,
    input logic                     i_update_min    ,

    input logic [SIZE_DATA-1:0]     i_data_ram      ,
    output logic                    o_wr_en         ,
    output logic                    o_rd_en         ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram      ,
    output logic [SIZE_DATA-1:0]    o_data_ram      ,

    output logic                    o_comp_less     ,
    output logic                    o_valid_wr      ,
    output logic                    o_valid_rd      ,
    output logic                    o_done_j        ,
    output logic                    o_done_sort      
);

logic [SIZE_ADDR-1:0] value_i;
logic                 w_o_en_i;
logic [SIZE_ADDR-1:0] value_j;
logic                 w_i_en_j;
logic [SIZE_ADDR-1:0] value_min;

logic                 w_en_temp_min;
logic [SIZE_DATA-1:0] w_temp_min;
logic                 w_en_temp_data;
logic [SIZE_DATA-1:0] w_temp_data;
logic                 w_en_data_key;
logic [SIZE_DATA-1:0] w_data_key;

logic [SIZE_ADDR-1:0] w_addr_ram;
logic [SIZE_DATA-1:0] w_data_wr;
logic [SIZE_DATA-1:0] w_data_rd;

assign o_comp_less = w_temp_data < w_temp_min;

Update_I #(
    .SIZE_ADDR      (SIZE_ADDR)
) UPDATE_I_UNIT (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_num_elems    (i_num_elems),
    .i_start        (i_start_i),
    .i_en           (i_update_i),
    .o_en           (w_o_en_i),
    .o_value_i      (value_i),
    .o_done         (o_done_sort) 
);

always_ff @( posedge i_clk or negedge i_rst_n) begin 
    if(~i_rst_n)
        w_i_en_j    <= '0;
    else 
        w_i_en_j    <= w_o_en_i;
end

Update_J #(
    .SIZE_ADDR      (SIZE_ADDR)
) UPDATE_J_UNIT (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_num_elems    (i_num_elems),
    .i_value_i      (value_i),
    .i_start        (w_i_en_j),
    .i_en           (i_update_j),
    .o_en           (),
    .o_value_j      (value_j),
    .o_done         (o_done_j) 
);

Update_MIN #(
    .SIZE_ADDR      (SIZE_ADDR)
) UPDATE_MIN_UNIT (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_value_i      (value_i),
    .i_value_j      (value_j),
    .i_update_i     (w_i_en_j),
    .i_update_min   (i_update_min),
    .o_addr_min     (value_min) 
);

Block_Addr #(
    .SIZE_ADDR      (SIZE_ADDR)
) ADDR_RAM (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_rd_en        (i_rd_en),
    .i_wr_en        (i_wr_en),
    .i_sel_addr     (i_sel_addr),
    .i_value_i      (value_i),
    .i_value_j      (value_j),
    .i_value_min    (value_min),
    .o_addr_ram     (o_addr_ram) 
);
Block_Read_data #(
    .SIZE_DATA      (SIZE_DATA)
) READ_RAM (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_rd_en        (i_rd_en),
    .i_sel_data_rd  (i_sel_data_rd),
    .i_data_ram     (i_data_ram),
    .o_rd_en        (o_rd_en),
    .o_temp_min     (w_temp_min),
    .o_temp_data    (w_temp_data),
    .o_data_key     (w_data_key),
    .o_done         (o_valid_rd) 
);
Block_Write_data #(
    .SIZE_DATA      (SIZE_DATA)
) WRITE_DATA (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_wr_en        (i_wr_en),
    .i_sel_wr       (i_sel_data_wr),
    .i_data_key     (w_data_key),
    .i_temp_min     (w_temp_min),
    .o_wr_en        (o_wr_en),
    .o_data_ram     (o_data_ram),
    .o_done         (o_valid_wr) 
);

endmodule
