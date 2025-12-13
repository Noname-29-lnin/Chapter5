module RAM_addr #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_rd_en     ,
    input logic                     i_wr_en     ,
    input logic [SIZE_ADDR-1:0]     i_addr_ram  ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram   
);
logic w_en;
assign w_en = i_rd_en | i_wr_en;
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_addr_ram      <= '0;
    end else if(w_en) begin
        o_addr_ram         <= i_addr_ram;
    end
end

endmodule
