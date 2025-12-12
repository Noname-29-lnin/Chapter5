module Read_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    
    input logic                     i_start     ,
    input logic [SIZE_DATA-1:0]     i_data      ,
    
    output logic [SIZE_DATA-1:0]    o_data_a    ,
    output logic [SIZE_DATA-1:0]    o_data_b    ,
    output logic                    o_rd_en     ,
    output logic                    o_done       
);

logic [SIZE_DATA-1:0]   w_data_1;
logic [SIZE_DATA-1:0]   w_data_0;
logic                   w_en_1;

demux1to2 #(
    .SIZE_DATA      (SIZE_DATA)
) MUX_1_TO_2_UNIT (
    .din            (i_data),
    .sel            (i_sel),
    .y0             (w_data_0),
    .y1             (w_data_1)
);

always_ff @(posedge i_clk or negedge i_rst_n) begin
    if(~i_rst_n) begin
        w_en_1          <= '0;
    end else begin
        w_en_1          <= o_rd_en;
    end
end

always_ff @(posedge i_clk or negedge i_rst_n) begin
    if(~i_rst_n) begin
        o_data_a        <= '0;
        o_data_b        <= '0;
    end else if(w_en_1) begin
        o_data_a        <= w_data_1;
        o_data_b        <= w_data_0;
    end
end

always_ff @(posedge i_clk or negedge i_rst_n) begin
    if(~i_rst_n) begin
        o_rd_en         <= '0;
    end else begin
        o_rd_en         <= i_en;
    end
end

always_ff @(posedge i_clk or negedge i_rst_n) begin
    if(~i_rst_n) begin
        o_done          <= '0;
    end else begin
        o_done          <= w_en_1;
    end
end

endmodule

module demux1to2 #(
    parameter SIZE_DATA = 8
)(
    input  logic [SIZE_DATA-1:0]    din,
    input  logic sel,
    output logic [SIZE_DATA-1:0]    y0,
    output logic [SIZE_DATA-1:0]    y1
);
    always_comb begin
        y0 = 0;
        y1 = 0;
        case (sel)
            1'b0: y0 = din;
            1'b1: y1 = din;
        endcase
    end
endmodule