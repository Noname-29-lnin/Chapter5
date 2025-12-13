module clear_even #(
    parameter DEPTH = 32,
    parameter WIDTH = 8
)(
    input  logic                              i_clk    ,
    input  logic                              i_rst_n  ,
    input  logic                              i_start  ,
    output logic                              o_rden   ,
    output logic                              o_wren   ,
    output logic        [$clog2(DEPTH) - 1:0] o_addr   ,
    input  logic signed [WIDTH         - 1:0] i_data   ,
    output logic                              o_done   ,
    output logic signed [WIDTH         - 1:0] o_data   ,
    output logic        [$clog2(DEPTH) - 1:0] o_odd_ptr 
);

    localparam DEPTH_S = DEPTH - 1;
    localparam WIDTH_S = WIDTH - 1;

    typedef enum logic[2:0] { 
        IDLE    ,
        UPDATE  ,
        READ    ,
        CHECK   ,
        DONE    ,
        CLEAR
    } e_state;

    e_state pstate, nstate;
    logic [$clog2(DEPTH) - 1:0] reg_rd_ptr, rd_ptr, rd_ptr_add, reg_wr_ptr, wr_ptr, wr_ptr_add;

    logic  odd_flag, count_end;
    assign odd_flag  = i_data[0];
    assign count_end = (&reg_rd_ptr);

    always_ff @(posedge i_clk, negedge i_rst_n) begin
        if(~i_rst_n) pstate <= IDLE  ;
        else         pstate <= nstate;
    end

    always_comb begin
        case(pstate)
            IDLE   : nstate = i_start ? UPDATE : pstate;
            UPDATE : nstate = READ;
            READ   : nstate = CHECK;
            CHECK  : nstate = count_end ? DONE : UPDATE;
              
            DONE   : nstate = i_start ? CLEAR : pstate;
            CLEAR  : nstate = UPDATE;
            default: nstate = IDLE;
        endcase
    end

    always_ff @(posedge i_clk, negedge i_rst_n) begin
        if(~i_rst_n) reg_rd_ptr <= '0;
        else         reg_rd_ptr <= rd_ptr;      
    end

    always_ff @(posedge i_clk, negedge i_rst_n) begin
        if(~i_rst_n) reg_wr_ptr <= '0;
        else         reg_wr_ptr <= wr_ptr;      
    end

    assign o_rden = (pstate == UPDATE);
    assign o_wren = (pstate == CHECK) ? odd_flag : 1'b0;
    assign o_addr = (pstate == CHECK) ? reg_wr_ptr : reg_rd_ptr;

    assign rd_ptr = (pstate == CHECK) ? rd_ptr_add : ((pstate == CLEAR) ? '0 : reg_rd_ptr);
    assign wr_ptr = (pstate == CHECK) ? (odd_flag & ~count_end  ? wr_ptr_add : reg_wr_ptr) : ((pstate == CLEAR) ? '0 : reg_wr_ptr);
    
    assign o_data = i_data;

    assign o_done = (pstate == DONE);

    assign o_odd_ptr = reg_wr_ptr;

    adder_flex_no_carry #(
        .WIDTH($clog2(DEPTH))
    ) add_1 (
        .i_a   (reg_rd_ptr),
        .i_b   ({{DEPTH_S{1'b0}},1'b1}),
        .i_cin (1'b0),
        .o_s   (rd_ptr_add)
    );

    adder_flex_no_carry #(
        .WIDTH($clog2(DEPTH))
    ) add_2 (
        .i_a   (reg_wr_ptr),
        .i_b   ({{DEPTH_S{1'b0}},1'b1}),
        .i_cin (1'b0),
        .o_s   (wr_ptr_add)
    );

endmodule