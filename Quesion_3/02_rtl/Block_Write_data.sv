module Block_Write_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_wr_en     ,
    input logic                     i_sel_wr    ,

    input logic [SIZE_DATA-1:0]     i_data_key  ,
    input logic [SIZE_DATA-1:0]     i_temp_min  ,

    output logic                    o_wr_en     ,
    output logic [SIZE_DATA-1:0]    o_data_ram  ,
    output logic                    o_done       
);

logic w_i_wr_en;
logic [SIZE_DATA-1:0] w_i_data_ram;
SS_detect_edge #(
    .POS_EDGE   (1)   // 1: posedge, 0: negedge
) DETECT_EDGE (
    .i_clk      (i_clk),
    .i_rst_n    (i_rst_n),
    .i_signal   (i_wr_en),
    .o_signal   (w_i_wr_en)
);

assign w_i_data_ram = i_sel_wr ? i_temp_min : i_data_key;

RAM_write_data #(
    .SIZE_DATA  (SIZE_DATA)
) RAM_WRITE_DATA (
    .i_clk      (i_clk),
    .i_rst_n    (i_rst_n),
    .i_wr_en    (w_i_wr_en),
    .i_data_wr  (w_i_data_ram),
    .o_wr_en    (o_wr_en),
    .o_data_wr  (o_data_ram),
    .o_done     (o_done) 
);

endmodule
