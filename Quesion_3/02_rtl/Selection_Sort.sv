module Selection_Sort #(
    parameter SIZE_ADDR     = 8 ,
    parameter PATH_RAM  = "./../03_verif/Topmodule/tools/random_hex.txt",
    parameter SIZE_DATA     = 8 
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_start     ,
    input logic [SIZE_ADDR-1:0]     i_num_elems ,
    output logic                    o_done       
);

logic w_rd_en;
logic w_wr_en;
logic [1:0] w_sel_add;
logic [1:0] w_sel_data_rd;
logic       w_sel_data_wr;
logic w_update_i;
logic w_update_j;
logic w_update_min;

logic w_comp_less;
logic w_valid_wr;
logic w_valid_rd;
logic w_done_j;
logic w_done;

logic w_rd_en_ram;
logic w_wr_en_ram;
logic [SIZE_ADDR-1:0] w_addr_ram;
logic [SIZE_DATA-1:0] w_i_data_ram;
logic [SIZE_DATA-1:0] w_o_data_ram;

Data_path #(
    .SIZE_ADDR          (SIZE_ADDR),
    .SIZE_DATA          (SIZE_DATA)
) DATA_PATH_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_num_elems        (i_num_elems),
    .i_rd_en            (w_rd_en),
    .i_wr_en            (w_wr_en),
    .i_sel_addr         (w_sel_add),
    .i_sel_data_rd      (w_sel_data_rd),
    .i_sel_data_wr      (w_sel_data_wr),
    .i_start_i          (i_start), //i_state=>topmodule
    .i_start_j          (),
    .i_update_i         (w_update_i),
    .i_update_j         (w_update_j),
    .i_update_min       (w_update_min),
    .i_data_ram         (w_o_data_ram),
    .o_wr_en            (w_wr_en_ram),
    .o_rd_en            (w_rd_en_ram),
    .o_addr_ram         (w_addr_ram),
    .o_data_ram         (w_i_data_ram),
    .o_comp_less        (w_comp_less),
    .o_valid_wr         (w_valid_wr),
    .o_valid_rd         (w_valid_rd),
    .o_done_j           (w_done_j),
    .o_done_sort        (w_done) 
);

Control_unit CONTROL_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_start            (i_start),
    .i_comp_less        (w_comp_less),
    .i_valid_wr         (w_valid_wr),
    .i_valid_rd         (w_valid_rd),
    .i_done_j           (w_done_j),
    .i_done_sort        (w_done),
    .o_wr_en            (w_wr_en),
    .o_rd_en            (w_rd_en),
    .o_sel_addr         (w_sel_add),
    .o_sel_data_rd      (w_sel_data_rd),
    .o_sel_data_wr      (w_sel_data_wr),
    .o_update_i         (w_update_i),
    .o_start_j          (),
    .o_update_j         (w_update_j),
    .o_update_min       (w_update_min)
);

SinglePort_RAM #(
    .SIZE_ADDR          (SIZE_ADDR),
    .PATH_RAM           (PATH_RAM),
    .SIZE_DATA          (SIZE_DATA)
) RAM_UNIT (
    .i_clk              (i_clk),
    .i_rst_n            (i_rst_n),
    .i_rd_en            (w_rd_en_ram),
    .i_wr_en            (w_wr_en_ram),
    .i_addr             (w_addr_ram),
    .i_data             (w_i_data_ram),
    .o_data             (w_o_data_ram) 
);

always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n)
        o_done  <= '0;
    else 
        o_done  <= w_done;
end

endmodule
