module Update_Smallest #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk               ,
    input logic                     i_rst_n             ,
    input logic                     i_en                ,
    input logic                     i_sel               ,
    input logic [SIZE_ADDR-1:0]     i_value_i           ,
    input logic [SIZE_ADDR-1:0]     i_value_j           ,
    output logic [SIZE_ADDR-1:0]    o_value_smallest     
);

logic w_enable;
assign w_enable = i_en | i_sel;
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_data
    if(~i_rst_n) begin
        o_value_smallest        <= '0; 
    end else if(w_enable) begin
        o_value_smallest        <= (i_sel) ? i_value_i : i_value_j;
    end
end

endmodule
