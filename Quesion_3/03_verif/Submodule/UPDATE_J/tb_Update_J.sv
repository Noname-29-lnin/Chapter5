`timescale 1ns/1ps

module tb_Update_J;

    // ==============================
    // Parameter
    // ==============================
    parameter SIZE_ADDR = 8;

    // ==============================
    // Clock & Reset
    // ==============================
    logic clk;
    logic rst_n;

    always #5 clk = ~clk;  // 100 MHz

    // ==============================
    // Signals cho Update_I
    // ==============================
    logic [SIZE_ADDR-1:0] num_elems;
    logic                 start_I;
    logic                 en_I;          // nối với done_J
    logic                 o_en_I;
    logic [SIZE_ADDR-1:0] o_value_i;
    logic                 o_done_I;

    // ==============================
    // Signals cho Update_J
    // ==============================
    logic                 start_J;
    logic                 en_J;
    logic                 o_en_J;
    logic [SIZE_ADDR-1:0] o_value_j;
    logic                 o_done_J;

    // ==============================
    // Instance Update_I
    // ==============================
    Update_I #(
        .SIZE_ADDR (SIZE_ADDR)
    ) u_Update_I (
        .i_clk       (clk),
        .i_rst_n     (rst_n),
        .i_num_elems (num_elems),
        .i_start     (start_I),
        .i_en        (en_I),          // en_I = done_J
        .o_en        (o_en_I),
        .o_value_i   (o_value_i),
        .o_done      (o_done_I)
    );

    // ==============================
    // Instance Update_J
    // ==============================
    Update_J #(
        .SIZE_ADDR (SIZE_ADDR)
    ) u_Update_J (
        .i_clk       (clk),
        .i_rst_n     (rst_n),
        .i_num_elems (num_elems),
        .i_value_i   (o_value_i),

        .i_start     (start_J),
        .i_en        (en_J),

        .o_en        (o_en_J),
        .o_value_j   (o_value_j),
        .o_done      (o_done_J)
    );

    // ==============================
    // KẾT NỐI HANDSHAKE GIỮA I VÀ J
    // ==============================

    // i_en của Update_I = o_done của Update_J
    assign en_I = o_done_J;

    // i_en của Update_J: luôn bật (cho phép J chạy mỗi khi nhận start)
    // assign en_J = 1'b1;

    // i_start của Update_J: được tạo tự động từ o_en_I
    // Mỗi lần Update_I update i (o_en_I = 1 một nhịp) thì J sẽ start
    always_ff @(posedge clk or negedge rst_n) begin
        if(~rst_n) begin
            start_J <= 1'b0;
        end else begin
            start_J <= o_en_I;   // CHỈ CÒN 1 NƠI ĐIỀU KHIỂN start_J
        end
    end

    // ==============================
    // Dump waveform
    // ==============================
    // initial begin
    //     $dumpfile("tb_Update_J.vcd");
    //     $dumpvars(0, tb_Update_J);
    // end
    initial begin 
        $shm_open("tb_Update_J.shm");
        $shm_probe("ASM");
    end

    // ==============================
    // Monitor
    // ==============================
    initial begin
        $display(" time \t| rst_n \t| I: \tstart  \ten  \tvalue_i   \tdone \t| J: \tstart   \ten    \tvalue_j   \tdone");
        $monitor("  %4t \t|  %b   \t| I:  \t%b    \t%b  \t%0d       \t%b   \t| J: \t%b      \t%b    \t%0d       \t%b",
                 $time, rst_n,
                 start_I, en_I, o_value_i, o_done_I,
                 start_J, en_J, o_value_j, o_done_J);
    end

    // ==============================
    // Stimulus chính
    // ==============================
    initial begin
        // Khởi tạo
        clk       = 0;
        rst_n     = 0;
        num_elems = 8'd5;     // ví dụ: 5 phần tử
        start_I   = 0;
        en_J      = 0;

        // Reset
        #20;
        rst_n = 1;

        // Khởi động I (outer index i)
        @(posedge clk);
        $display("\n>>> Pulse start_I (bắt đầu i từ 0)");
        start_I <= 1'b1;
        @(posedge clk);
        start_I <= 1'b0;

        repeat (10) begin
            @(posedge clk);
            en_J = 0;
            #30;
            @(posedge clk);
            en_J = 1;
        end

        // Sau đó để cho I & J tự chạy (handshake qua o_en_I & o_done_J)
        // Chờ một thời gian đủ dài để thấy hết các i,j
        @(posedge o_done_I);
        #100;
        $display("\n>>> Kết thúc mô phỏng");
        $finish;
    end

endmodule
