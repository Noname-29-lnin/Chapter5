`timescale 1ns/1ps

module tb_RAM_read_data;

    parameter SIZE_DATA = 8;
    parameter SIZE_ADDR = 8;
    parameter PERIOD    = 10;
    parameter PATH_RAM  = "./../../03_verif/Topmodule/tools/random_hex.txt";
    
    logic                     i_clk;
    logic                     i_rst_n;
    logic                     i_rd_en;
    logic                     o_rd_en;
    logic [SIZE_ADDR-1:0]     i_ram_addr;
    logic [SIZE_ADDR-1:0]     o_ram_addr;
    logic [SIZE_DATA-1:0]     o_ram_data_rd; 
    logic [SIZE_DATA-1:0]     o_data_rd;
    logic                     o_valid;
    RAM_read_data #(
        .SIZE_DATA  (SIZE_DATA)
    ) DUT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_rd_en    (i_rd_en),
        .i_data_rd  (o_ram_data_rd),
        .o_rd_en    (o_rd_en),
        .o_data_rd  (o_data_rd),
        .o_valid    (o_valid)
    );
    RAM_addr #(
        .SIZE_ADDR  (SIZE_ADDR)
    ) RAM_ADDR_UNIT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_rd_en    (i_rd_en),
        .i_wr_en    (1'b0),
        .i_addr_ram (i_ram_addr),
        .o_addr_ram (o_ram_addr) 
    );
    
    SinglePort_RAM #(
        .SIZE_ADDR (SIZE_ADDR),
        .SIZE_DATA (SIZE_DATA),
        .PATH_RAM  (PATH_RAM)   
    ) RAM_UNIT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_rd_en    (o_rd_en),
        .i_wr_en    (1'b0),
        .i_addr     (o_ram_addr),
        .i_data     (),
        .o_data     (o_ram_data_rd)
    );
    initial begin
        i_clk = 0;
        forever #(PERIOD/2) i_clk = ~i_clk;
    end
    initial begin 
        $shm_open("tb_RAM_read_data.shm");
        $shm_probe("ASM");
    end
    initial begin
        i_rd_en = 0;
        i_ram_addr = 0;
        i_rst_n = 0;

        #100;
        i_rst_n = 1;

        repeat (10) begin
            @(posedge i_clk);
            i_rd_en = 1;
            @(posedge i_clk);
            i_rd_en = 0;
            @(negedge o_valid);
                $display("[ADDR = %h] DATA = %h", o_ram_addr, o_data_rd);
            @(posedge i_clk);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        $display("Finish Testbench");
        #100;
        $finish;
    end
    
endmodule
