module eq8 (
    input  logic [7:0] x,
    output logic       zero
);
    assign zero = (x == 8'd0);
endmodule
