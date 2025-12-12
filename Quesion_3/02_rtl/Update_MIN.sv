module Update_MIN #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic [SIZE_ADDR-1:0]     i_value_i   ,
    input logic [SIZE_ADDR-1:0]     i_value_j   ,

    input logic                     i_update_i  ,
    input logic                     i_update_min,

    output logic [SIZE_ADDR-1:0]    o_addr_min   
);

logic w_en;
assign w_en = i_update_i | i_update_min;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_addr_min
    if(~i_rst_n) begin
        o_addr_min      <= '0;
    end else if(w_en) begin
        o_addr_min      <= (i_update_min) ? i_value_j : i_value_i;
    end
end

endmodule
