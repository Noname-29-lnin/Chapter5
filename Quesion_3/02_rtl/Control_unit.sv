module Control_unit (
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_start     ,

    input logic                     i_comp_less ,
    input logic                     i_valid_wr  ,
    input logic                     i_valid_rd  ,
    input logic                     i_done_j    ,
    input logic                     i_done_sort ,

    output logic                    o_wr_en     ,
    output logic                    o_rd_en     ,
    output logic [1:0]              o_sel_addr  ,
    output logic [1:0]              o_sel_data_rd,
    output logic                    o_sel_data_wr,
    output logic                    o_update_i  ,
    output logic                    o_start_j,
    output logic                    o_update_j  ,
    output logic                    o_update_min
);

typedef enum logic [3:0] { 
    IDLE             = 4'd0,
    START            = 4'd1,
    READ_DATA_KEY    = 4'd2,
    COMPARE_I        = 4'd3,
    READ_TEMP_MIN    = 4'd4,
    COMPARE_J        = 4'd5,
    READ_TEMP_DATA   = 4'd6,
    COMP_TEMP_VALUE  = 4'd7,
    UPDATE_MIN_VALUE = 4'd8,
    UPDATE_J         = 4'd9,
    WAIT_J           = 4'd10,
    WRITE_TEMP_MIN   = 4'd11,
    WAIT_WRITE       = 4'd12,
    WRITE_DATA_KEY   = 4'd13,
    UPDATE_I         = 4'd14,
    WAIT_I           = 4'd15
} state_e;
 state_e state, n_state;

always_comb begin : proc_next_state
    case (state)
        IDLE: begin
            n_state = i_start ? START : IDLE;
        end
        START: begin
            n_state = READ_DATA_KEY;
        end
        READ_DATA_KEY: begin
            n_state = i_valid_rd ? COMPARE_I : READ_DATA_KEY;
        end
        COMPARE_I: begin
            n_state = i_done_sort ? IDLE : READ_TEMP_MIN;
        end
        READ_TEMP_MIN: begin
            n_state = i_valid_rd ? COMPARE_J : READ_TEMP_MIN;
        end
        COMPARE_J: begin
            n_state = i_done_j ? WRITE_TEMP_MIN : READ_TEMP_DATA;
        end
        READ_TEMP_DATA: begin
            n_state = i_valid_rd ? COMP_TEMP_VALUE : READ_TEMP_DATA;
        end
        COMP_TEMP_VALUE: begin
            n_state = i_comp_less ? UPDATE_MIN_VALUE : UPDATE_J;
        end
        UPDATE_MIN_VALUE: begin
            n_state = UPDATE_J;
        end
        UPDATE_J: begin
            n_state = WAIT_J;
        end
        WAIT_J: begin
            n_state = READ_TEMP_MIN;
        end
        WRITE_TEMP_MIN: begin
            n_state = i_valid_wr ? WAIT_WRITE : WRITE_TEMP_MIN;
        end
        WAIT_WRITE: begin
            n_state = WRITE_DATA_KEY;
        end
        WRITE_DATA_KEY: begin
            n_state = i_valid_wr ? UPDATE_I : WRITE_DATA_KEY;
        end
        UPDATE_I: begin
            n_state = WAIT_I;
        end
        WAIT_I: begin
            n_state = READ_DATA_KEY;
        end
        default: begin
            n_state = IDLE;
        end
    endcase
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_update_state
    if(~i_rst_n)
        state   <= IDLE;
    else 
        state   <= n_state; 
end
// always_ff @(posedge i_clk or negedge i_rst_n) begin : proc_output
//     if(~i_rst_n) begin
//         o_wr_en         <= '0;
//         o_rd_en         <= '0;
//         o_sel_addr      <= '0;
//         o_sel_data_rd   <= '0;
//         o_sel_data_wr   <= '0;
//         o_update_i      <= '0;
//         o_update_j      <= '0;
//         o_update_min    <= '0;
//     end else begin
//         case (state)
//             IDLE: begin //
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= '0;
//                 o_sel_data_rd   <= '0;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             START: begin //
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= '0;
//                 o_sel_data_rd   <= '0;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             READ_DATA_KEY: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= 1'b1;  // enable read
//                 o_sel_addr      <= 2'b10; // addr_date_key
//                 o_sel_data_rd   <= 2'b10; 
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             COMPARE_I: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= 1'b0;
//                 o_sel_addr      <= 2'b10;
//                 o_sel_data_rd   <= 2'b10;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             READ_TEMP_MIN: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= 1'b1;
//                 o_sel_addr      <= 2'b01;
//                 o_sel_data_rd   <= 2'b01;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             COMPARE_J: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b01;
//                 o_sel_data_rd   <= 2'b01;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             READ_TEMP_DATA: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= 1'b1;
//                 o_sel_addr      <= 2'b00;
//                 o_sel_data_rd   <= 2'b00;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             COMP_TEMP_VALUE: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b00;
//                 o_sel_data_rd   <= 2'b00;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             UPDATE_MIN_VALUE: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b11;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= 1'b1;
//             end
//             UPDATE_J: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b11;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= 1'b1;
//                 o_update_min    <= '0;
//             end
//             WAIT_J: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b11;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             WRITE_TEMP_MIN: begin
//                 o_wr_en         <= 1'b1;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b01;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= 1'b1;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             UPDATE_I: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b11;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= 1'b0;
//                 o_update_i      <= 1'b1;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             WRITE_DATA_KEY: begin
//                 o_wr_en         <= 1'b1;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= 2'b10;
//                 o_sel_data_rd   <= 2'b11;
//                 o_sel_data_wr   <= 1'b0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             DONE: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= '0;
//                 o_sel_data_rd   <= '0;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//             default: begin
//                 o_wr_en         <= '0;
//                 o_rd_en         <= '0;
//                 o_sel_addr      <= '0;
//                 o_sel_data_rd   <= '0;
//                 o_sel_data_wr   <= '0;
//                 o_update_i      <= '0;
//                 o_update_j      <= '0;
//                 o_update_min    <= '0;
//             end
//         endcase
//     end
// end
always_comb begin : proc_output
    // default values
    o_wr_en         = '0;
    o_rd_en         = '0;
    o_sel_addr      = '0;
    o_sel_data_rd   = '0;
    o_sel_data_wr   = '0;
    o_update_i      = '0;
    o_start_j       = '0;
    o_update_j      = '0;
    o_update_min    = '0;

    case (state)
        READ_DATA_KEY: begin
            o_start_j     = 1'b1;
            o_rd_en       = 1'b1;
            o_sel_addr    = 2'b11;
            o_sel_data_rd = 2'b01;
        end

        COMPARE_I: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
        end

        READ_TEMP_MIN: begin
            o_rd_en       = 1'b1;
            o_sel_addr    = 2'b01;
            o_sel_data_rd = 2'b11;
        end

        COMPARE_J: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
        end

        READ_TEMP_DATA: begin
            o_rd_en       = 1'b1;
            o_sel_addr    = 2'b10;
            o_sel_data_rd = 2'b10;
        end

        COMP_TEMP_VALUE: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
        end

        UPDATE_MIN_VALUE: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
            o_update_min  = 1'b1;
        end

        UPDATE_J: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
            o_update_j    = 1'b1;
        end

        WAIT_J: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
        end

        WRITE_TEMP_MIN: begin
            o_wr_en       = 1'b1;
            o_sel_addr    = 2'b11;
            o_sel_data_rd = 2'b00;
            o_sel_data_wr = 1'b1;
        end

        UPDATE_I: begin
            o_sel_addr    = 2'b00;
            o_sel_data_rd = 2'b00;
            o_update_i    = 1'b1;
        end

        WRITE_DATA_KEY: begin
            o_wr_en       = 1'b1;
            o_sel_addr    = 2'b01;
            o_sel_data_rd = 2'b00;
            o_sel_data_wr = 1'b0;
        end

        default: begin
            o_wr_en         = '0;
            o_rd_en         = '0;
            o_sel_addr      = '0;
            o_sel_data_rd   = '0;
            o_sel_data_wr   = '0;
            o_update_i      = '0;
            o_start_j       = '0;
            o_update_j      = '0;
            o_update_min    = '0;
        end
    endcase
end



endmodule
