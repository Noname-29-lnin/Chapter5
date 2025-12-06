module Selection_Sort #(
    parameter SIZE_ADDR     = 8,
    parameter SIZE_DATA     = 8,
    parameter PATH_RAM      = "./../03_verif/Topmodule/tools/random_hex.txt"
)(
    input logic                 i_clk       ,
    input logic                 i_rst_n     ,
    input logic                 i_start     ,
    input logic [SIZE_ADDR-1:0] i_num_elems ,
    output logic                o_done         
);

logic w_done_rd;
logic w_done_wr;
logic w_done_j;
logic w_start_j;
logic w_en_i;
logic w_rd_en;

logic [SIZE_DATA-1:0] w_i_data;
logic [SIZE_DATA-1:0] w_o_data;
logic [SIZE_ADDR-1:0] w_i_addr;
logic                 w_o_rd_en;
logic                 w_o_wr_en;
ControlUnit CONTROL_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_start            (i_start),
    .i_done_rd          (w_done_rd),
    .i_done_wr          (w_done_wr),
    .i_done_j           (w_done_j),
    .o_start_j          (w_start_j),
    .o_en_i             (w_en_i),
    .o_rd_en            (w_rd_en) 
);

DataPath #(
    .SIZE_ADDR          (SIZE_ADDR),
    .SIZE_DATA          (SIZE_DATA) 
) DATAPATH_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_num_elems        (i_num_elems),
    .i_start_j          (w_start_j),
    .i_en_i             (w_en_i),
    .i_rd_en            (w_rd_en),
    .o_done_rd          (w_done_rd),
    .o_done_wr          (w_done_wr),
    .o_done_j           (w_done_j),
    .i_data_ram         (w_i_data),
    .o_rd_en            (w_o_rd_en),
    .o_wr_en            (w_o_wr_en),
    .o_addr_ram         (w_i_addr),
    .o_data_ram         (w_o_data) 
);

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) 
        o_done      <= '0;
    else 
        o_done      <= w_done_j;
end

SinglePort_RAM #(
    .SIZE_ADDR          (SIZE_ADDR),
    .SIZE_DATA          (SIZE_DATA),
    .PATH_RAM           (PATH_RAM)
) RAM_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_rd_en            (w_o_rd_en),
    .i_wr_en            (w_o_wr_en),
    .i_addr             (w_i_addr),
    .i_data             (w_o_data),
    .o_data             (w_i_data) 
);

endmodule
