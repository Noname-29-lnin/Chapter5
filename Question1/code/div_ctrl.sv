module div_ctrl (
    input  logic clk,
    input  logic rst,
    input  logic go,
    input  logic b_zero,
    input  logic brw,
    input  logic done_cnt,

    output logic ldA, selA_init,
    output logic ldB, selB_init,
    output logic ldQ, clrQ,
    output logic ldCNT, cntINIT,
    output logic errSET, errCLR,
    output logic fin
);

    typedef enum logic[2:0] {
        S_IDLE = 3'd0,
        S_INIT = 3'd1,
        S_COMPARE = 3'd2,
        S_SHIFT = 3'd3,
        S_DONE = 3'd4
    } st_t;

    st_t st, nxt;

    always_ff @(posedge clk or posedge rst)
        if (rst) st <= S_IDLE;
        else     st <= nxt;

    always_comb begin
        nxt = st;
        ldA=0; selA_init=0;
        ldB=0; selB_init=0;
        ldQ=0; clrQ=0;
        ldCNT=0; cntINIT=0;
        errSET=0; errCLR=0;
        fin=0;

        case(st)

        S_IDLE: begin
            clrQ = 1;
            errCLR = 1;
            if (go)
                nxt = S_INIT;
        end

        S_INIT: begin
            selA_init = 1; ldA = 1;
            selB_init = 1; ldB = 1;
            ldCNT = 1; cntINIT = 1;
            clrQ = 1;
            errCLR = 1;
            if (b_zero) begin
                errSET = 1;
                nxt = S_DONE;
            end else begin
                nxt = S_COMPARE;
            end
        end

        S_COMPARE: begin
            ldA = 1;
            ldQ = 1;
            nxt = S_SHIFT;
        end

        S_SHIFT: begin
            ldB = 1;
            ldCNT = 1;
            if (done_cnt) nxt = S_DONE;
            else nxt = S_COMPARE;
        end

        S_DONE: begin
            fin = 1;
            if (!go) nxt = S_IDLE;
        end

        endcase
    end
endmodule
