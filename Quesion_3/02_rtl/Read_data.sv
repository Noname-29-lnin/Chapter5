module Read_data #(
    parameter SIZE_ADDR     = 8 ,
    parameter SIZE_DATA     = 8  
)(
    input logic                     i_clk       ,
    input logic                     i_rst_n     ,
    input logic                     i_rd_en     ,
    input logic [SIZE_ADDR-1:0]     i_addr_rd   ,
    input logic [SIZE_DATA-1:0]     i_data_rd   ,
    output logic [SIZE_ADDR-1:0]    o_addr_rd   ,
    output logic [SIZE_DATA-1:0]    o_data_rd   ,
    output logic                    o_rd_en     ,
    output logic                    o_valid      
);

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_rd_en
    if(~i_rst_n) begin
        o_rd_en     <= '0;
    end else if(i_rd_en) begin
        o_rd_en     <= i_rd_en;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_add_rd
    if(~i_rst_n) begin
        o_addr_rd       <= '0; 
    end else if(i_rd_en) begin
        o_addr_rd       <= i_addr_rd;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_valid
    if(~i_rst_n) begin
        o_valid         <= '0;
    end else begin
        o_valid         <= o_rd_en;
    end
end

always_ff @( posedge i_clk or negedge i_rst_n ) begin : proc_data_rd
    if(~i_rst_n) begin
        o_data_rd       <= '0;
    end else if(o_rd_en) begin
        o_data_rd       <= i_data_rd;
    end
end
endmodule
