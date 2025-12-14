module alu16 (
    input  logic [15:0] a_in,
    input  logic [15:0] b_in,
    input  logic        sub,      
    output logic [15:0] s_out,
    output logic        carry_out
);
    logic [15:0] b_sel;
    logic        c_in;

    assign b_sel = sub ? ~b_in : b_in;
    assign c_in  = sub ? 1'b1 : 1'b0;

    assign {carry_out, s_out} = a_in + b_sel + c_in;
endmodule
