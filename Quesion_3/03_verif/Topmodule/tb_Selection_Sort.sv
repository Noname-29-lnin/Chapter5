`timescale 1ns/1ps

module tb_Selection_Sort;

    parameter SIZE_ADDR = 4;
    parameter SIZE_DATA = 8;
    parameter PATH_RAM  = "./../../03_verif/Topmodule/tools/random_hex.txt";

    logic                   clk;
    logic                   rst_n;
    logic                   start;
    logic [SIZE_ADDR-1:0]   num_elems;
    logic                   done;

    Selection_Sort #(
        .SIZE_ADDR (SIZE_ADDR),
        .PATH_RAM  (PATH_RAM),
        .SIZE_DATA (SIZE_DATA)
    ) DUT (
        .i_clk       (clk),
        .i_rst_n     (rst_n),
        .i_start     (start),
        .i_num_elems (num_elems),
        .o_done      (done)
    );

    always #5 clk = ~clk;   // 100 MHz

    task dump_ram_contents;
        int fd;
        fd = $fopen("./../../03_verif/Topmodule/sorted_output.txt", "w");

        $display("\n===== RAM AFTER SORT =====");
        for (int i = 0; i < (1<<SIZE_ADDR); i++) begin
            $fwrite(fd, "%02X\n", DUT.RAM_UNIT.mem_unit[i]);   // chú ý: RAM_UNIT
            $display("RAM[%0d] = %02X", i, DUT.RAM_UNIT.mem_unit[i]);
        end

        $fclose(fd);
        $display(">>> Saved sorted RAM to sorted_output.txt");
    endtask

    initial begin
        $shm_open("tb_Selection_Sort.shm");
        $shm_probe("ASM");
    end

    initial begin
        clk       = 0;
        rst_n     = 0;
        start     = 0;
        num_elems = 4'd15;            // ví dụ sort 10 phần tử: 0..9

        #20;
        rst_n = 1;

        #20;
        $display(">>> Sending START...");
        start = 1;
        #10;
        start = 0;

        // Chờ DONE
        @(posedge done);
        $display(">>> DONE received at time %0t", $time);

        dump_ram_contents();

        #20;
        $finish;
    end

endmodule
