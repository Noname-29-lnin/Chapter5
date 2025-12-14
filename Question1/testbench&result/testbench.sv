`timescale 1ns/1ps

module tb_divider;

    logic clk;
    logic rst;
    logic start;
    logic [7:0] A, B;

    logic done;
    logic err;
    logic [7:0] Q, R;

    int total_tests = 0;
    int passed_tests = 0;
    bit global_fail = 0;

    divider8_top dut(
        .clk(clk),
        .rst(rst),
        .start(start),
        .A(A),
        .B(B),
        .done(done),
        .err(err),
        .Q(Q),
        .R(R)
    );

    always #5 clk = ~clk;

    task automatic test_div(input [7:0] a_i, input [7:0] b_i);
        int exp_q, exp_r;
        int timeout;
        bit err_seen;

        begin
            total_tests++;

            if (b_i != 0) begin
                exp_q = a_i / b_i;
                exp_r = a_i % b_i;
            end

            @(posedge clk);
            A = a_i;
            B = b_i;
            start = 1;

            @(posedge clk);
            start = 0;

            timeout = 0;
            err_seen = 0;

            // ====== WAIT DONE, CAPTURE ERR ======
            while (!done && timeout < 200) begin
                @(posedge clk);
                if (err) err_seen = 1;
                timeout++;
            end

            if (timeout == 200) begin
                $display("[FAIL][TIMEOUT] A=%0d B=%0d", a_i, b_i);
                global_fail = 1;
                return;
            end

            // ====== CHECK ======
            if (b_i == 0) begin
                if (err_seen) begin
                    $display("[PASS][DIV0] A=%0d B=0 detected", a_i);
                    passed_tests++;
                end else begin
                    $display("[FAIL][DIV0] A=%0d B=0 but err never asserted", a_i);
                    global_fail = 1;
                end
            end else begin
                if (Q !== exp_q || R !== exp_r || err_seen) begin
                    $display("[FAIL] A=%0d B=%0d | Q=%0d R=%0d err=%0b | EXP Q=%0d R=%0d",
                        a_i, b_i, Q, R, err_seen, exp_q, exp_r);
                    global_fail = 1;
                end else begin
                    $display("[PASS] A=%0d B=%0d | Q=%0d R=%0d",
                        a_i, b_i, Q, R);
                    passed_tests++;
                end
            end

            @(posedge clk);
        end
    endtask

    initial begin
        clk = 0;
        rst = 1;
        start = 0;
        A = 0;
        B = 0;

        repeat (5) @(posedge clk);
        rst = 0;
        repeat (5) @(posedge clk);

        $display("\n========================================");
        $display("   STARTING ADVANCED DIVIDER TESTBENCH");
        $display("========================================\n");

        // Special
        test_div(174,25);
        test_div(0,25);
        test_div(37,0);
        test_div(0,0);
        test_div(10,25);
        test_div(50,50);

        // Random
        for (int i = 0; i < 100; i++)
            test_div($urandom_range(0,255),
                     $urandom_range(0,255));

        $display("\n========================================");
        $display("SUMMARY");
        $display("Total  : %0d", total_tests);
        $display("Passed : %0d", passed_tests);
        $display("Failed : %0d", total_tests - passed_tests);
        $display("========================================");

        if (global_fail)
            $display("❌ SOME TESTS FAILED");
        else
            $display("✅ ALL TESTS PASSED");

        $finish;
    end

endmodule
