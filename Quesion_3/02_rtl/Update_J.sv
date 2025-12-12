module Update_J #(
    parameter SIZE_ADDR = 8
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic [SIZE_ADDR-1:0]     i_num_elems ,
    input logic [SIZE_ADDR-1:0]     i_value_i   ,

    input logic                     i_start     ,
    input logic                     i_en        ,

    output logic                    o_en        ,
    output logic [SIZE_ADDR-1:0]    o_value_j   ,
    output logic                    o_done       
);

logic w_start;
logic [SIZE_ADDR-1:0]   w_pre_value_j;
logic [SIZE_ADDR-1:0]   w_next_value_j;
logic w_pre_done;
// logic w_pre_done_1;
// logic w_pre_done_2;
// logic w_pre_done_3;
logic w_enable;

// assign w_pre_done       = (o_value_j == (i_num_elems));
assign w_pre_done       = (o_value_j == ('0));
assign w_start          = i_start;
assign w_enable         = w_start | (i_en & ~w_pre_done);
assign w_next_value_j   = o_value_j + 1'b1; 
assign w_pre_value_j    = w_start ? (i_value_i+1'b1) : (w_next_value_j);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_output_value_j
    if(~i_rst_n) begin
        o_value_j       <= '0;
    end else if(w_enable) begin 
        o_value_j       <= w_pre_value_j;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_done
    if(~i_rst_n) begin
        o_done          <= '0;
        // w_pre_done_1    <= '0;
        // w_pre_done_2    <= '0;
        // w_pre_done_3    <= '0;
    end else begin 
        // w_pre_done_1    <= w_pre_done;
        // w_pre_done_2    <= w_pre_done_1;
        // w_pre_done_3    <= w_pre_done_2;
        o_done          <= w_pre_done;
    end
end
// assign o_done          = w_pre_done;

assign o_en = w_enable;

endmodule
