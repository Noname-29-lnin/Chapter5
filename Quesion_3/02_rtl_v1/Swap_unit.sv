module Swap_unit #(
    parameter SIZE_ADDR     = 8 ,
    parameter SIZE_DATA     = 8 
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,
    
    input logic                     i_rd_en         ,
    input logic [SIZE_ADDR-1:0]     i_addr_i        ,
    input logic [SIZE_ADDR-1:0]     i_addr_smallest ,
    input logic [SIZE_DATA-1:0]     i_data_ram      ,

    output logic                    o_rd_en         ,
    output logic                    o_wr_en         ,
    output logic [SIZE_ADDR-1:0]    o_addr_ram      ,
    output logic [SIZE_DATA-1:0]    o_data_ram      ,

    output logic                    o_compare       ,
    output logic                    o_done_rd       ,
    output logic                    o_done_wr         
);

logic [SIZE_DATA-1:0]   i_READ_data_i;
logic [SIZE_DATA-1:0]   w_READ_data_i;

logic [SIZE_DATA-1:0]   i_READ_data_smallest;
logic [SIZE_DATA-1:0]   w_READ_data_smallest;
logic                   w_READ_en;
logic                   w_READ_select;

logic                   w_READ_rd_en;
logic                   w_READ_rd_en_1;

logic                   w_o_done_1;

logic                   w_WRITE_en;
logic                   w_WRITE_en_addr;
logic                   w_WRITE_en_1;

logic                   w_SELSWAP_sel;
logic                   w_SELSWAP_sel_1;
logic                   w_SELSWAP_sel_2;

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_READ_data_i           <= '0;
        w_READ_data_smallest    <= '0;
    end else if(w_READ_en) begin
        w_READ_data_i           <= i_READ_data_i;
        w_READ_data_smallest    <= i_READ_data_smallest;
    end
end
TFF TFF_UNIT (
    .t                  (w_READ_en),
    .clk                (i_clk),
    .clrn               (1'b1),
    .prn                (1'b1),
    .q                  (w_READ_select) 
);
demux1to2 #(
    .SIZE_DATA          (SIZE_DATA)
) DEMUX_1_TO_2 (
    .din                (i_data_ram),
    .sel                (w_READ_select),
    .y0                 (i_READ_data_smallest),
    .y1                 (i_READ_data_i)
);
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_READ_en       <= '0;
        w_READ_rd_en_1  <= '0;    
    end else begin
        w_READ_en       <= o_rd_en;
        w_READ_rd_en_1  <= w_READ_en;    
    end
end
assign w_READ_rd_en = i_rd_en | w_READ_rd_en_1;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_rd_en
    if(~i_rst_n) begin
        o_rd_en         <= '0;
    end else begin
        o_rd_en         <= w_READ_rd_en;
    end
end

assign o_compare = w_READ_data_i < w_READ_data_smallest;

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_o_done_1      <= '0;
        o_done_rd       <= '0;
    end else begin
        w_o_done_1      <= w_READ_rd_en_1;
        o_done_rd       <= w_o_done_1;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        w_WRITE_en_1    <= '0;
    end else begin
        w_WRITE_en_1    <= o_compare;
    end 
end
assign w_WRITE_en = w_WRITE_en_1 | o_compare;

TFF TFF_UNIT_1 (
    .t                  (o_rd_en),
    .clk                (i_clk),
    .clrn               (1'b1),
    .prn                (1'b1),
    .q                  (w_SELSWAP_sel_1) 
);
TFF TFF_UNIT_2 (
    .t                  (w_WRITE_en),
    .clk                (i_clk),
    .clrn               (1'b1),
    .prn                (1'b1),
    .q                  (w_SELSWAP_sel_2) 
);
assign w_SELSWAP_sel = w_SELSWAP_sel_1 | w_SELSWAP_sel_2;

Swap_data #(
    .SIZE_DATA (SIZE_DATA)
) SWAP_DATA_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_en               (w_WRITE_en),
    .i_compare          (o_compare),
    .i_sel              (w_SELSWAP_sel),
    .i_data_i           (w_READ_data_i),
    .i_data_smallest    (w_READ_data_smallest),
    .o_data_ram         (o_data_ram) 
);
assign w_WRITE_en_addr = w_READ_rd_en | w_WRITE_en;
Swap_addr #(
    .SIZE_ADDR (SIZE_ADDR)
) SWAP_ADDR_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_en               (w_WRITE_en_addr),
    .i_compare          (o_compare),
    .i_sel              (w_SELSWAP_sel),
    .i_addr_i           (i_addr_i),
    .i_addr_smallest    (i_addr_smallest),
    .o_addr_ram         (o_addr_ram) 
);
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_wr_en         <= '0;
    end else begin
        o_wr_en         <= w_WRITE_en;
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_done_wr         <= '0;
    end else begin
        o_done_wr         <= o_wr_en;
    end
end

endmodule

module Swap_data #(
    parameter SIZE_DATA = 8
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,

    input logic                     i_en            ,
    input logic                     i_compare       ,
    input logic                     i_sel           ,

    input logic [SIZE_DATA-1:0]     i_data_i        ,
    input logic [SIZE_DATA-1:0]     i_data_smallest ,
    
    output logic [SIZE_DATA-1:0]    o_data_ram       
);

logic [SIZE_DATA-1:0] w_max_data;
logic [SIZE_DATA-1:0] w_min_data;

assign w_max_data   = (i_compare) ? i_data_smallest : i_data_i; 
assign w_min_data   = (i_compare) ? i_data_i        : i_data_smallest; 

logic [SIZE_DATA-1:0] w_data_ram_1;
logic [SIZE_DATA-1:0] w_data_ram_0;

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_data
    if(~i_rst_n) begin
        w_data_ram_1        <= '0;
        w_data_ram_0        <= '0;
    end else if(i_en) begin
        w_data_ram_1        <= w_max_data;
        w_data_ram_0        <= w_min_data;
    end
end

assign o_data_ram = (i_sel) ? w_data_ram_1 : w_data_ram_0;

endmodule
module Swap_addr #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk           ,
    input logic                     i_rst_n         ,

    input logic                     i_en            ,
    input logic                     i_compare       ,
    input logic                     i_sel           ,

    input logic [SIZE_ADDR-1:0]     i_addr_i        ,
    input logic [SIZE_ADDR-1:0]     i_addr_smallest ,
    
    output logic [SIZE_ADDR-1:0]    o_addr_ram       
);

logic [SIZE_ADDR-1:0] w_max_addr;
logic [SIZE_ADDR-1:0] w_min_addr;

assign w_max_addr   = (i_compare) ? i_addr_smallest : i_addr_i; 
assign w_min_addr   = (i_compare) ? i_addr_i        : i_addr_smallest; 

logic [SIZE_ADDR-1:0] w_addr_ram_1;
logic [SIZE_ADDR-1:0] w_addr_ram_0;

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_data
    if(~i_rst_n) begin
        w_addr_ram_1        <= '0;
        w_addr_ram_0        <= '0;
    end else if(i_en) begin
        w_addr_ram_1        <= w_max_addr;
        w_addr_ram_0        <= w_min_addr;
    end
end

assign o_addr_ram = (i_sel) ? w_addr_ram_1 : w_addr_ram_0;

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
module TFF (
    input  logic t,
    input  logic clk,
    input  logic clrn,   // active-low async clear
    input  logic prn,    // active-low async preset
    output logic q
);

    logic q_next;

    // Toggle logic bằng XOR
    assign q_next = q ^ t;

    always_ff @(posedge clk or negedge clrn or negedge prn) begin
        if (~clrn)
            q <= 1'b0;           // clear
        else if (~prn)
            q <= 1'b1;           // preset
        else
            q <= q_next;         // cập nhật bằng XOR logic
    end

endmodule
