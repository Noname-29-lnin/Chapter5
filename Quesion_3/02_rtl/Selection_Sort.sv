// module Selection_Sort #(
//     parameter SIZE_ADDR     = 8,
//     parameter SIZE_DATA     = 8,
//     parameter PATH_RAM      = "./../03_verif/Topmodule/tools/random_hex.txt"
// )(
//     input logic                 i_clk       ,
//     input logic                 i_rst_n     ,
//     input logic                 i_start     ,
//     input logic [SIZE_ADDR-1:0] i_num_elems ,
//     output logic                o_done         
// );

// logic w_done_rd;
// logic w_done_wr;
// logic w_done_j;
// logic w_start_j;
// logic w_en_i;
// logic w_rd_en;

// logic [SIZE_DATA-1:0] w_i_data;
// logic [SIZE_DATA-1:0] w_o_data;
// logic [SIZE_ADDR-1:0] w_i_addr;
// logic                 w_o_rd_en;
// logic                 w_o_wr_en;
// ControlUnit CONTROL_UNIT (
//     .i_clk              (i_clk),
//     .i_rst_n            (i_rst_n),
//     .i_start            (i_start),
//     .i_done_rd          (w_done_rd),
//     .i_done_wr          (w_done_wr),
//     .i_done_j           (w_done_j),
//     .o_start_j          (w_start_j),
//     .o_en_i             (w_en_i),
//     .o_rd_en            (w_rd_en) 
// );

// DataPath #(
//     .SIZE_ADDR          (SIZE_ADDR),
//     .SIZE_DATA          (SIZE_DATA) 
// ) DATAPATH_UNIT (
//     .i_clk              (i_clk),
//     .i_rst_n            (i_rst_n),
//     .i_num_elems        (i_num_elems),
//     .i_start_j          (w_start_j),
//     .i_en_i             (w_en_i),
//     .i_rd_en            (w_rd_en),
//     .o_done_rd          (w_done_rd),
//     .o_done_wr          (w_done_wr),
//     .o_done_j           (w_done_j),
//     .i_data_ram         (w_i_data),
//     .o_rd_en            (w_o_rd_en),
//     .o_wr_en            (w_o_wr_en),
//     .o_addr_ram         (w_i_addr),
//     .o_data_ram         (w_o_data) 
// );

// always_ff @( posedge i_clk or negedge i_rst_n ) begin
//     if(~i_rst_n) 
//         o_done      <= '0;
//     else 
//         o_done      <= w_done_j;
// end

// SinglePort_RAM #(
//     .SIZE_ADDR          (SIZE_ADDR),
//     .SIZE_DATA          (SIZE_DATA),
//     .PATH_RAM           (PATH_RAM)
// ) RAM_UNIT (
//     .i_clk              (i_clk),
//     .i_rst_n            (i_rst_n),
//     .i_rd_en            (w_o_rd_en),
//     .i_wr_en            (w_o_wr_en),
//     .i_addr             (w_i_addr),
//     .i_data             (w_o_data),
//     .o_data             (w_i_data) 
// );

// endmodule

module Selection_Sort #(
    parameter SIZE_ADDR     = 8,
    parameter SIZE_DATA     = 8,
    parameter PATH_RAM      = "./../03_verif/Topmodule/tools/random_hex.txt"
)(
    input  logic                 i_clk       ,
    input  logic                 i_rst_n     ,
    input  logic                 i_start     ,
    input  logic [SIZE_ADDR-1:0] i_num_elems ,   // số phần tử cần sort (0..i_num_elems-1)
    output logic                 o_done
);

    //=========================
    // Kết nối RAM
    //=========================
    logic                        ram_rd_en;
    logic                        ram_wr_en;
    logic [SIZE_ADDR-1:0]        ram_addr;
    logic [SIZE_DATA-1:0]        ram_din;
    logic [SIZE_DATA-1:0]        ram_dout;

    SinglePort_RAM #(
        .SIZE_ADDR (SIZE_ADDR),
        .SIZE_DATA (SIZE_DATA),
        .PATH_RAM  (PATH_RAM)
    ) RAM_UNIT (
        .i_clk   (i_clk),
        .i_rst_n (i_rst_n),
        .i_rd_en (ram_rd_en),
        .i_wr_en (ram_wr_en),
        .i_addr  (ram_addr),
        .i_data  (ram_din),
        .o_data  (ram_dout)
    );

    //=========================
    // Thanh ghi điều khiển
    //=========================
    typedef enum logic [4:0] {
        S_IDLE,

        // --- khối for (j = 0; j < n-1; j++)
        S_OUTER_INIT,
        S_OUTER_CHECK,
        S_OUTER_NEXT,

        // --- khối for (i = j+1; i < n; i++)
        S_INNER_INIT,
        S_INNER_CHECK,

        // --- khối if (arr[i] < arr[smallest]) { smallest = i; swap... }
        S_READ_SM_REQ,
        S_READ_SM_WAIT,
        S_READ_I_REQ,
        S_READ_I_WAIT,
        S_COMPARE,

        // swap
        S_SWAP_READ_I_REQ,
        S_SWAP_READ_I_WAIT,
        S_SWAP_READ_SM_REQ,
        S_SWAP_READ_SM_WAIT,
        S_SWAP_WRITE_I,
        S_SWAP_WRITE_SM,

        // tăng i, kết thúc vòng trong
        S_INNER_NEXT,

        // kết thúc sort
        S_DONE
    } state_t;

    state_t                 state, next_state;

    logic [SIZE_ADDR-1:0]   j;            // outer index
    logic [SIZE_ADDR-1:0]   i;            // inner index
    logic [SIZE_ADDR-1:0]   smallest;     // index nhỏ nhất tạm thời
    logic [SIZE_ADDR-1:0]   last_index;   // = i_num_elems - 1

    logic [SIZE_DATA-1:0]   val_smallest;
    logic [SIZE_DATA-1:0]   val_i;
    logic [SIZE_DATA-1:0]   temp_i;
    logic [SIZE_DATA-1:0]   temp_sm;

    //=========================
    // last_index = i_num_elems-1
    //=========================
    always_comb begin
        if (i_num_elems == 0)
            last_index = 0;
        else
            last_index = i_num_elems - 1;
    end

    //=========================
    // State register
    //=========================
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n)
            state <= S_IDLE;
        else
            state <= next_state;
    end

    //=========================
    // Thanh ghi j, i, smallest, dữ liệu
    //=========================
    always_ff @(posedge i_clk or negedge i_rst_n) begin
        if (!i_rst_n) begin
            j            <= '0;
            i            <= '0;
            smallest     <= '0;
            val_smallest <= '0;
            val_i        <= '0;
            temp_i       <= '0;
            temp_sm      <= '0;
        end else begin
            case (state)

                //============================
                // KHỐI 1: for (j = 0; j < n-1; j++)
                //============================
                S_OUTER_INIT: begin
                    j        <= 0;
                end

                S_OUTER_NEXT: begin
                    j        <= j + 1;
                end

                //============================
                // KHỐI 2: for (i = j+1; i < n; i++)
                //============================
                S_INNER_INIT: begin
                    smallest <= j;          // smallest = j
                    i        <= j + 1;      // i = j+1
                end

                S_INNER_NEXT: begin
                    i        <= i + 1;      // i++
                end

                //============================
                // KHỐI 3: if + swap
                //============================
                // đọc arr[smallest]
                S_READ_SM_WAIT: begin
                    val_smallest <= ram_dout;
                end

                // đọc arr[i]
                S_READ_I_WAIT: begin
                    val_i <= ram_dout;
                end

                // so sánh
                S_COMPARE: begin
                    if (val_i < val_smallest) begin
                        smallest <= i;      // smallest = i;
                    end
                end

                // đọc arr[i] để swap
                S_SWAP_READ_I_WAIT: begin
                    temp_i <= ram_dout;     // arr[i]
                end

                // đọc arr[smallest] để swap
                S_SWAP_READ_SM_WAIT: begin
                    temp_sm <= ram_dout;    // arr[smallest]
                end

                default: begin
                    // giữ nguyên
                end
            endcase
        end
    end

    //=========================
    // Next state logic + điều khiển RAM
    //=========================
    always_comb begin
        // mặc định
        next_state = state;
        o_done     = 1'b0;

        // mặc định tín hiệu RAM
        ram_rd_en  = 1'b0;
        ram_wr_en  = 1'b0;
        ram_addr   = '0;
        ram_din    = '0;

        case (state)

            //--------------------------------
            // IDLE: chờ i_start
            //--------------------------------
            S_IDLE: begin
                if (i_start && (i_num_elems > 1))
                    next_state = S_OUTER_INIT;
                else if (i_start && (i_num_elems <= 1))
                    next_state = S_DONE;  // 0 hoặc 1 phần tử => coi như đã sort
            end

            //--------------------------------
            // KHỐI 1: for (j = 0; j < n-1; j++)
            //--------------------------------
            S_OUTER_INIT: begin
                next_state = S_OUTER_CHECK;
            end

            S_OUTER_CHECK: begin
                // j < last_index  (tức là j <= n-2)
                if (j < last_index)
                    next_state = S_INNER_INIT;
                else
                    next_state = S_DONE;
            end

            S_OUTER_NEXT: begin
                next_state = S_OUTER_CHECK;
            end

            //--------------------------------
            // KHỐI 2: for (i = j+1; i < n; i++)
            //--------------------------------
            S_INNER_INIT: begin
                // nếu j+1 > last_index => không có phần tử để so sánh
                if (j + 1 <= last_index)
                    next_state = S_INNER_CHECK;
                else
                    next_state = S_OUTER_NEXT;
            end

            S_INNER_CHECK: begin
                // i < i_num_elems
                if (i < i_num_elems) begin
                    // đọc arr[smallest]
                    ram_rd_en  = 1'b1;
                    ram_addr   = smallest;
                    next_state = S_READ_SM_REQ;
                end else begin
                    // kết thúc vòng trong, tăng j
                    next_state = S_OUTER_NEXT;
                end
            end

            //--------------------------------
            // KHỐI 3: if (arr[i] < arr[smallest]) ...
            //--------------------------------
            // yêu cầu đọc arr[smallest] (1 chu kỳ trước khi có data)
            S_READ_SM_REQ: begin
                // RAM đã được set addr, rd_en ở S_INNER_CHECK
                // state này chỉ là "đệm" để data xuất hiện ở chu kỳ sau
                next_state = S_READ_SM_WAIT;
            end

            // chờ data arr[smallest]
            S_READ_SM_WAIT: begin
                // bây giờ ram_dout chứa arr[smallest] và đã được latch vào val_smallest (ở always_ff)
                // gửi yêu cầu đọc arr[i]
                ram_rd_en  = 1'b1;
                ram_addr   = i;
                next_state = S_READ_I_REQ;
            end

            // yêu cầu đọc arr[i]
            S_READ_I_REQ: begin
                next_state = S_READ_I_WAIT;
            end

            // chờ data arr[i]
            S_READ_I_WAIT: begin
                // bây giờ ram_dout chứa arr[i] và đã được latch vào val_i
                next_state = S_COMPARE;
            end

            // so sánh val_i và val_smallest
            S_COMPARE: begin
                if (val_i < val_smallest) begin
                    // cần swap: đọc arr[i] để lưu
                    ram_rd_en  = 1'b1;
                    ram_addr   = i;
                    next_state = S_SWAP_READ_I_REQ;
                end else begin
                    // không swap, tăng i
                    next_state = S_INNER_NEXT;
                end
            end

            // đọc arr[i] cho swap
            S_SWAP_READ_I_REQ: begin
                next_state = S_SWAP_READ_I_WAIT;
            end

            S_SWAP_READ_I_WAIT: begin
                // đã lưu temp_i = arr[i]
                // giờ đọc arr[smallest]
                ram_rd_en  = 1'b1;
                ram_addr   = smallest;
                next_state = S_SWAP_READ_SM_REQ;
            end

            S_SWAP_READ_SM_REQ: begin
                next_state = S_SWAP_READ_SM_WAIT;
            end

            S_SWAP_READ_SM_WAIT: begin
                // đã lưu temp_sm = arr[smallest]
                // Ghi arr[i] = temp_sm
                ram_wr_en  = 1'b1;
                ram_addr   = i;
                ram_din    = temp_sm;
                next_state = S_SWAP_WRITE_I;
            end

            // ghi xong arr[i]
            S_SWAP_WRITE_I: begin
                // Ghi arr[smallest] = temp_i
                ram_wr_en  = 1'b1;
                ram_addr   = smallest;
                ram_din    = temp_i;
                next_state = S_SWAP_WRITE_SM;
            end

            // ghi xong arr[smallest], tăng i
            S_SWAP_WRITE_SM: begin
                next_state = S_INNER_NEXT;
            end

            //--------------------------------
            // tăng i, quay lại vòng trong
            //--------------------------------
            S_INNER_NEXT: begin
                next_state = S_INNER_CHECK;
            end

            //--------------------------------
            // DONE
            //--------------------------------
            S_DONE: begin
                o_done = 1'b1;
                // chờ i_start hạ xuống rồi lên lại mới sort lần nữa
                if (!i_start)
                    next_state = S_IDLE;
            end

            default: begin
                next_state = S_IDLE;
            end
        endcase
    end

endmodule
