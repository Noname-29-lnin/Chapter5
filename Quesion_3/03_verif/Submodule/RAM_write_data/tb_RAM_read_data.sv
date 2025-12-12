`timescale 1ns/1ps

module tb_RAM_write_data;

    parameter SIZE_DATA = 8;
    parameter SIZE_ADDR = 4;
    parameter PERIOD    = 10;
    parameter PATH_RAM  = "./../../03_verif/Topmodule/tools/random_hex.txt";
    
    logic                     i_clk;
    logic                     i_rst_n;
    logic                     i_wr_en;
    logic                     o_wr_en;
    logic [SIZE_ADDR-1:0]     i_ram_addr;
    logic [SIZE_ADDR-1:0]     o_ram_addr;
    logic [SIZE_DATA-1:0]     i_ram_data_wr; 
    logic [SIZE_DATA-1:0]     o_ram_data_wr;
    logic                     o_valid;
    RAM_write_data #(
        .SIZE_DATA  (SIZE_DATA)
    ) DUT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_wr_en    (i_wr_en),
        .i_data_wr  (i_ram_data_wr),
        .o_wr_en    (o_wr_en),
        .o_data_wr  (o_ram_data_wr) ,
        .o_done     (o_valid)
    );
    RAM_addr #(
        .SIZE_ADDR  (SIZE_ADDR)
    ) RAM_ADDR_UNIT (
        .i_clk      (i_clk),
        .i_rst_n    (i_rst_n),
        .i_rd_en    (1'b0),
        .i_wr_en    (i_wr_en),
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
        .i_rd_en    (1'b0),
        .i_wr_en    (o_wr_en),
        .i_addr     (o_ram_addr),
        .i_data     (o_ram_data_wr),
        .o_data     ()
    );
    initial begin
        i_clk = 0;
        forever #(PERIOD/2) i_clk = ~i_clk;
    end
    initial begin 
        $shm_open("tb_RAM_write_data.shm");
        $shm_probe("ASM");
    end
    initial begin
        i_wr_en = 0;
        i_ram_addr = 0;
        i_rst_n = 0;

        #100;
        i_rst_n = 1;

        repeat (3) begin
            @(posedge i_clk);
            i_wr_en = 1;
            i_ram_data_wr = 0;
            @(posedge i_clk);
            i_wr_en = 0;
            @(negedge o_valid);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        repeat (2) begin
            @(posedge i_clk);
            i_wr_en = 1;
            i_ram_data_wr = 10;
            @(posedge i_clk);
            i_wr_en = 0;
            @(negedge o_valid);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        repeat (1) begin
            @(posedge i_clk);
            i_wr_en = 1;
            i_ram_data_wr = 5;
            @(posedge i_clk);
            i_wr_en = 0;
            @(negedge o_valid);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        repeat (3) begin
            @(posedge i_clk);
            i_wr_en = 1;
            i_ram_data_wr = 0;
            @(posedge i_clk);
            i_wr_en = 0;
            @(negedge o_valid);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        repeat (1) begin
            @(posedge i_clk);
            i_wr_en = 1;
            i_ram_data_wr = 2;
            @(posedge i_clk);
            i_wr_en = 0;
            @(negedge o_valid);
            @(posedge i_clk);
            i_ram_addr = i_ram_addr + 1'b1;
        end
        for(int i = 0; i < 2**SIZE_ADDR; i++) begin
            $display("[ADDR = %h] DATA = %h ", i, RAM_UNIT.mem_unit[i]);
        end
        $display("Finish Testbench");
        #100;
        $finish;
    end
    
endmodule
