`timescale 1ns/1ps

module tb_Update_I;

    // ==============================
    // Parameter giống DUT
    // ==============================
    parameter SIZE_ADDR = 8;

    // ==============================
    // DUT I/O
    // ==============================
    logic                     clk;
    logic                     rst_n;
    logic [SIZE_ADDR-1:0]     num_elems;
    logic                     start;
    logic                     en;

    logic                     o_en;
    logic [SIZE_ADDR-1:0]     o_value_i;
    logic                     o_done;

    // ==============================
    // Instance DUT
    // ==============================
    Update_I #(
        .SIZE_ADDR (SIZE_ADDR)
    ) DUT (
        .i_clk       (clk),
        .i_rst_n     (rst_n),
        .i_num_elems (num_elems),
        .i_start     (start),
        .i_en        (en),
        .o_en        (o_en),
        .o_value_i   (o_value_i),
        .o_done      (o_done)
    );

    // ==============================
    // Clock 100 MHz
    // ==============================
    always #5 clk = ~clk;

    // ==============================
    // Dump waveform (cho GTKWave, etc.)
    // ==============================
    // initial begin
    //     $dumpfile("tb_Update_I.vcd");
    //     $dumpvars(0, tb_Update_I);
    // end
    initial begin 
        $shm_open("tb_Update_I.shm");
        $shm_probe("ASM");
    end

    // ==============================
    // Monitor
    // ==============================
    initial begin
        $display(" time | rst_n start en | o_en o_value_i o_done");
        $monitor("%4t |   %b     %b    %b |   %b    %0d      %b",
                 $time, rst_n, start, en, o_en, o_value_i, o_done);
    end

    // ==============================
    // Stimulus chính
    // ==============================
    initial begin
        // Khởi tạo
        clk       = 0;
        rst_n     = 0;
        start     = 0;
        en        = 0;
        num_elems = 8'd31;      // đếm từ 0 -> 4 rồi quay lại 0

        // Giữ reset một lúc
        #20;
        rst_n = 1;

        // Chờ một chút rồi pulse start
        #20;
        $display("\n>>> Pulse START lần 1");
        start = 1;
        en    = 1;             // cho phép đếm luôn
        #10;
        start = 0;

        // Cho chạy khoảng vài chu kỳ
        #200;

        // Tạm dừng en, xem o_value_i đứng lại
        $display("\n>>> Tắt en, counter phải đứng yên");
        en = 0;
        #100;

        // Bật en lại
        $display("\n>>> Bật en lại");
        en = 1;
        #200;

        // Pulse start lần 2 để reset lại về 0
        $display("\n>>> Pulse START lần 2 (reset lại i về 0)");
        start = 1;
        #10;
        start = 0;
        #100;

        $display("\n>>> Kết thúc mô phỏng");
        $finish;
    end

endmodule
