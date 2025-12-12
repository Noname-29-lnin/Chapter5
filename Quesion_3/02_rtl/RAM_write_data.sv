module RAM_write_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_wr_en     ,
    input logic [SIZE_DATA-1:0]     i_data_wr   ,
    output logic                    o_wr_en     ,
    output logic [SIZE_DATA-1:0]    o_data_wr   ,
    output logic                    o_done       
);

// logic w_i_wr_en;
// SS_detect_edge #(
//     .POS_EDGE   (1)   // 1: posedge, 0: negedge
// ) DETECT_EDGE (
//     .i_clk      (i_clk),
//     .i_rst_n    (i_rst_n),
//     .i_signal   (i_wr_en),
//     .o_signal   (w_i_wr_en)
// );

// logic w_o_wr_en;
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        // w_o_wr_en   <= '0;
        o_wr_en     <= '0;
    end else begin
        // w_o_wr_en   <= w_i_wr_en;
        o_wr_en     <= i_wr_en;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_done     <= '0;
    end else begin
        o_done     <= o_wr_en;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_data_wr   <= '0;
    end else if (i_wr_en) begin
        o_data_wr   <= i_data_wr;
    end
end
endmodule
