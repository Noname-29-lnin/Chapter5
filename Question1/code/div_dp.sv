module div_dp (
    input  logic        clk,
    input  logic        rst,
    input  logic [7:0]  din_A,
    input  logic [7:0]  din_B,

 
    input  logic        ld_A,
    input  logic        sel_A_init,
    input  logic        ld_B,
    input  logic        sel_B_init,
    input  logic        ld_Q,
    input  logic        clr_Q,
    input  logic        ld_cnt,
    input  logic        cnt_init,
    input  logic        set_err,
    input  logic        clr_err,

    
    output logic        b_is_zero,
    output logic        borrow_flag,
    output logic        cnt_fin,

   
    output logic [7:0]  quo,
    output logic [7:0]  rem,
    output logic        div_err
);

   
    logic [15:0] regA;
    logic [15:0] regB;
    logic [7:0]  regQ;
    logic [3:0]  regCNT;
    logic        regERR;

    
    eq8 chkB (.x(din_B), .zero(b_is_zero));

    
    logic [15:0] alu_res;
    logic        alu_cout;

    alu16 alu1 (
        .a_in(regA),
        .b_in(regB),
        .sub(1'b1),
        .s_out(alu_res),
        .carry_out(alu_cout)
    );

   
    assign borrow_flag = ~alu_cout;

    
    logic [15:0] alu_restore;
    alu16 alu2 (
        .a_in(alu_res),
        .b_in(regB),
        .sub(1'b0),
        .s_out(alu_restore),
        .carry_out()
    );

    
    logic [15:0] nxtA;
    assign nxtA =
        sel_A_init ? {8'd0, din_A} :
        (borrow_flag ? alu_restore : alu_res);

    
    logic [15:0] nxtB;
    assign nxtB =
        sel_B_init ? {din_B, 8'd0} : (regB >> 1);

    
    logic [7:0] nxtQ;
    assign nxtQ = {regQ[6:0], ~borrow_flag};

    
    logic [3:0] nxtCNT;
    assign nxtCNT  = regCNT - 1;
    assign cnt_fin = (regCNT == 4'd1);

    
    logic nxtERR;
    assign nxtERR = set_err ? 1'b1 :
                    clr_err ? 1'b0 :
                    regERR;

    
    always_ff @(posedge clk or posedge rst) begin
        if (rst) begin
            regA  <= 0;
            regB  <= 0;
            regQ  <= 0;
            regCNT<= 0;
            regERR<= 0;
        end else begin
            if (ld_A)  regA <= nxtA;
            if (ld_B)  regB <= nxtB;

            if (clr_Q) regQ <= 8'd0;
            else if (ld_Q) regQ <= nxtQ;

            if (ld_cnt) begin
                if (cnt_init) regCNT <= 4'd9;
                else regCNT <= nxtCNT;
            end

            regERR <= nxtERR;
        end
    end

    assign quo = regQ;
    assign rem = regA[7:0];
    assign div_err = regERR;

endmodule
