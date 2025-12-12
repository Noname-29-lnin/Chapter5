module ControlUnit (
    input logic                 i_clk       ,
    input logic                 i_rst_n     ,
    input logic                 i_start     ,

    input logic                 i_done_rd   ,
    input logic                 i_done_wr   ,
    input logic                 i_done_j    ,

    output logic                o_start_j   ,
    output logic                o_en_i      ,
    output logic                o_rd_en      
);

typedef enum logic [2:0] { 
    IDLE        = 3'd0,
    START       = 3'd1,
    READ        = 3'd2,
    WAIT_READ   = 3'd3,
    WRITE       = 3'd4,
    NEXT_I      = 3'd5,
    DONE        = 3'd6
} state_e;
state_e state, n_state;

always_comb begin
    case(state)
        IDLE: begin
            n_state = (i_start) ? START : IDLE;
        end
        START: begin
            n_state = READ;
        end
        READ: begin
            n_state = WAIT_READ;
        end 
        WAIT_READ: begin
            n_state = (i_done_rd) ? WRITE : WAIT_READ;
        end
        WRITE: begin
            n_state = (i_done_wr) ? NEXT_I : WRITE;
        end
        NEXT_I: begin
            n_state = DONE;
        end
        DONE: begin
            n_state = (i_done_j) ? IDLE : READ;
        end
        default: begin
            n_state = IDLE;
        end
    endcase
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        state       <= IDLE; 
    end else begin
        state       <= n_state; 
    end
end
always_ff @( posedge i_clk or negedge i_rst_n ) begin
    if(~i_rst_n) begin
        o_start_j   <= '0;
        o_en_i      <= '0;
        o_rd_en     <= '0;
    end else begin
        case(state)
            IDLE: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
            START: begin
                o_start_j   <= 1'b1;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
            READ: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= 1'b1;
            end 
            WAIT_READ: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
            WRITE: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
            NEXT_I: begin
                o_start_j   <= '0;
                o_en_i      <= 1'b1;
                o_rd_en     <= '0;
            end
            DONE: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
            default: begin
                o_start_j   <= '0;
                o_en_i      <= '0;
                o_rd_en     <= '0;
            end
        endcase
    end
end

endmodule
