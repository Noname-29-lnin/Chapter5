module RAM_read_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_rd_en     ,
    input logic [SIZE_DATA-1:0]     i_data_rd   ,
    output logic                    o_rd_en     ,
    output logic [SIZE_DATA-1:0]    o_data_rd   ,
    output logic                    o_valid      
);
logic w_o_rd_en;
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_o_rd_en   <= '0;
        o_rd_en     <= '0;
    end else begin
        w_o_rd_en   <= i_rd_en;
        o_rd_en     <= w_o_rd_en;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_valid     <= '0;
    end else begin
        o_valid     <= o_rd_en;
    end
end
logic [SIZE_DATA-1:0] w_save_data;
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_save_data   <= '0;
    end else begin
        w_save_data   <= o_data_rd;
    end
end
assign o_data_rd = (o_valid) ? i_data_rd : w_save_data;
endmodule
