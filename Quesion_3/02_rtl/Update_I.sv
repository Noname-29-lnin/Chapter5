module Update_I #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic [SIZE_ADDR-1:0]     i_num_elems ,

    input logic                     i_start     ,
    input logic                     i_en        ,

    output logic                    o_en        ,
    output logic [SIZE_ADDR-1:0]    o_value_i   ,
    output logic                    o_done       
);

logic w_start;
logic [SIZE_ADDR-1:0]   w_pre_value_i;
logic [SIZE_ADDR-1:0]   w_next_value_i;
logic w_pre_done;
logic w_enable;

assign w_start          = i_start;
assign w_enable         = w_start | (i_en & ~w_pre_done);
assign w_next_value_i   = o_value_i + 1'b1; 
assign w_pre_value_i    = w_start ? ('0) : (w_next_value_i);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_value_i
    if(~i_rst_n) begin
        o_value_i       <= '0;
    end else if(w_enable) begin 
        o_value_i       <= w_pre_value_i;
    end
end

// assign w_pre_done       = (w_pre_value_i == (i_num_elems));
assign w_pre_done       = (o_value_i == (i_num_elems));
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_done
    if(~i_rst_n) begin
        o_done          <= '0;
    end else begin 
        o_done          <= w_pre_done;
    end
end
// assign o_done          = w_pre_done;

assign o_en = w_enable;

endmodule
