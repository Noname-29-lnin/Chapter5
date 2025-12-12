module Block_Addr #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_rd_en     ,
    input logic                     i_wr_en     ,
    input logic [1:0]               i_sel_addr  ,

    input logic [SIZE_ADDR-1:0]     i_value_i   ,
    input logic [SIZE_ADDR-1:0]     i_value_j   ,
    input logic [SIZE_ADDR-1:0]     i_value_min ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram   
);

logic [SIZE_ADDR-1:0] w_addr_ram;

assign w_addr_ram = i_sel_addr[1] ? (i_sel_addr[0] ? i_value_i : i_value_j) : (i_sel_addr[0] ? i_value_min : o_addr_ram);
RAM_addr #(
    .SIZE_ADDR      (SIZE_ADDR)
) RAM_ADDR_UNIT (
    .i_clk          (i_clk),
    .i_rst_n        (i_rst_n),
    .i_rd_en        (i_rd_en),
    .i_wr_en        (i_wr_en),
    .i_addr_ram     (w_addr_ram),
    .o_addr_ram     (o_addr_ram) 
);

endmodule
