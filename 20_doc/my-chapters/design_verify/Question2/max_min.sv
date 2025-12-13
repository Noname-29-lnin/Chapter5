module max_min #(
    parameter DEPTH = 128,
    parameter WIDTH = 8  
)(
    input  logic                              i_clk    ,
    input  logic                              i_rst_n  ,
    input  logic                              i_start  ,
    output logic                              o_rden   ,
    output logic        [$clog2(DEPTH) - 1:0] o_addr   ,
    input  logic signed [WIDTH         - 1:0] i_data   ,
    output logic                              o_done   ,
    output logic signed [WIDTH         - 1:0] o_max    ,
    output logic signed [WIDTH         - 1:0] o_min    
);

    localparam DEPTH_S = DEPTH - 1;
    localparam WIDTH_S = WIDTH - 1;

    logic [WIDTH - 1:0] max, min;
    logic flag_max, flag_min;

    typedef enum logic[2:0] { 
        IDLE    ,
        READ    ,
        COMPARE ,
        UPDATE  ,
        DONE    ,
        CLEAR
    } e_state;

    e_state pstate, nstate;
    logic [$clog2(DEPTH) - 1:0] reg_count, count, count_add;

    always_ff @(posedge i_clk, negedge i_rst_n) begin : blockName
        if(~i_rst_n) pstate <= IDLE  ;
        else         pstate <= nstate;
    end

    always_comb begin
        case(pstate)
            IDLE   : nstate = i_start ? UPDATE : pstate;
            UPDATE : nstate = (&reg_count) ? DONE : READ;
            READ   : nstate = COMPARE;
            COMPARE: nstate = UPDATE ;   
            DONE   : nstate = i_start ? CLEAR : pstate;
            CLEAR  : nstate = UPDATE;
            default: nstate = IDLE;
        endcase
    end
    
    assign count  = (pstate == COMPARE) ? count_add : ((pstate == CLEAR) ? '0 : reg_count);
    assign o_addr = count;

    assign o_done = (pstate == DONE);
    //assign o_rden = (pstate == UPDATE) | (pstate == IDLE);
    assign o_rden = (pstate == UPDATE);
    
    always_ff @(posedge i_clk, negedge i_rst_n) begin
        if(~i_rst_n) begin 
            reg_count <= '0;
            o_max     <= {1'b1, {WIDTH_S{1'b0}}};
            o_min     <= {1'b0, {WIDTH_S{1'b1}}};
        end
        else begin 
            reg_count <= count;
            o_max     <= max  ;
            o_min     <= min  ;
        end       
    end

    adder_flex_no_carry #(
        .WIDTH($clog2(DEPTH))
    ) add_1 (
        .i_a   (reg_count),
        .i_b   ({{DEPTH_S{1'b0}},1'b1}),
        .i_cin (1'b0),
        .o_s   (count_add)
    );

    assign max = (pstate == COMPARE) ? (flag_max ? i_data : o_max) : ((pstate == CLEAR) ? {1'b1, {WIDTH_S{1'b0}}} : o_max);
    assign min = (pstate == COMPARE) ? (flag_min ? i_data : o_min) : ((pstate == CLEAR) ? {1'b0, {WIDTH_S{1'b1}}} : o_min);

    lt_compare_sign #(
        .WIDTH(WIDTH)
    ) compare_max (
        .i_a (o_max),
        .i_b (i_data),
        .o_lt(flag_max) // a < b
    );

    lt_compare_sign #(
        .WIDTH(WIDTH)
    ) compare_min (
        .i_a (i_data),
        .i_b (o_min),
        .o_lt(flag_min) // a < b
    );

endmodule
