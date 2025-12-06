module SinglePort_RAM #(
    parameter SIZE_ADDR = 8 ,
    parameter SIZE_DATA = 8 ,
    parameter PATH_RAM  = "./../03_verif/Topmodule/tools/random_hex.txt"
)(
    input logic                         i_clk       ,
    input logic                         i_rst_n     ,
    input logic                         i_rd_en     ,
    input logic                         i_wr_en     ,
    input logic [SIZE_ADDR-1:0]         i_addr      ,
    input logic [SIZE_DATA-1:0]         i_data      ,
    output logic [SIZE_DATA-1:0]        o_data          
);

parameter DEPTH     = 1 << SIZE_ADDR;   // 2^SIZE_ADDR
logic [SIZE_DATA-1:0] mem_unit [0:DEPTH-1];
initial begin
    $readmemh(PATH_RAM, mem_unit);
end

always_ff @( posedge i_clk or negedge i_rst_n) begin : proc_write_data
    if(~i_rst_n) begin
        mem_unit[i_addr]    <= '0;
    end else if(i_wr_en) begin
        mem_unit[i_addr]    <= i_data;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n) begin : proc_read_data
    if(~i_rst_n) begin
        o_data              <= '0;
    end else if(i_rd_en) begin
        o_data              <= mem_unit[i_addr];
    end
end

endmodule
