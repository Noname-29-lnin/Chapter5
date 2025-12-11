module Write_data #(
    parameter SIZE_ADDR     = 8 ,
    parameter SIZE_DATA     = 8  
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,

    input logic                     i_wr_en     ,
    input logic [SIZE_ADDR-1:0]     i_addr_wr   ,
    input logic [SIZE_DATA-1:0]     i_data_wr   ,

    output logic                    o_wr_en     ,
    output logic [SIZE_ADDR-1:0]    o_addr_wr   ,
    output logic [SIZE_DATA-1:0]    o_data_wr   ,
    output logic                    o_valid      
);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_wr_en
    if(~i_rst_n) begin
        o_wr_en     <= '0;
    end else if(i_wr_en) begin
        o_wr_en     <= i_wr_en;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_addr_wr
    if(~i_rst_n) begin
        o_addr_wr   <= '0;
    end else if(i_wr_en) begin
        o_addr_wr   <= i_addr_wr;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_data_wr
    if(~i_rst_n) begin
        o_data_wr   <= '0;
    end else if(i_wr_en) begin
        o_data_wr   <= i_data_wr;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_valid
    if(~i_rst_n) begin
        o_valid     <= '0;
    end else begin
        o_valid     <= o_wr_en;
    end
end


endmodule
