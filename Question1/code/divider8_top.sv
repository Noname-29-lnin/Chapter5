module divider8_top (
    input  logic       clk,
    input  logic       rst,
    input  logic       start,
    input  logic [7:0] A,
    input  logic [7:0] B,

    output logic       done,
    output logic       err,
    output logic [7:0] Q,
    output logic [7:0] R
);

    logic lA, sAinit;
    logic lB, sBinit;
    logic lQ, cQ;
    logic lCNT, cINIT;
    logic eSET, eCLR;

    logic b_zero, brw, cnt_done;

    div_ctrl ctrl(
        .clk(clk), .rst(rst),
        .go(start),
        .b_zero(b_zero),
        .brw(brw),
        .done_cnt(cnt_done),
        .ldA(lA), .selA_init(sAinit),
        .ldB(lB), .selB_init(sBinit),
        .ldQ(lQ), .clrQ(cQ),
        .ldCNT(lCNT), .cntINIT(cINIT),
        .errSET(eSET), .errCLR(eCLR),
        .fin(done)
    );

    div_dp dp(
        .clk(clk), .rst(rst),
        .din_A(A), .din_B(B),
        .ld_A(lA), .sel_A_init(sAinit),
        .ld_B(lB), .sel_B_init(sBinit),
        .ld_Q(lQ), .clr_Q(cQ),
        .ld_cnt(lCNT), .cnt_init(cINIT),
        .set_err(eSET),
        .clr_err(eCLR),
        .b_is_zero(b_zero),
        .borrow_flag(brw),
        .cnt_fin(cnt_done),
        .quo(Q),
        .rem(R),
        .div_err(err)
    );
endmodule
