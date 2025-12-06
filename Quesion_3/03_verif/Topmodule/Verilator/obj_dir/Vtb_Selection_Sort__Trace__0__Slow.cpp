// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_Selection_Sort__Syms.h"


VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_init_sub__TOP__0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_init_sub__TOP__0\n"); );
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->pushPrefix("tb_Selection_Sort", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+84,0,"PATH_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 751,0);
    tracep->declBit(c+67,0,"clk",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"rst_n",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"num_elems",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+17,0,"done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+71,0,"dump_ram_contents__Vstatic__fd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INT, false,-1, 31,0);
    tracep->pushPrefix("DUT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+84,0,"PATH_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 751,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"i_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"i_num_elems",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+17,0,"o_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"w_done_rd",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"w_done_wr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"w_done_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"w_start_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"w_en_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"w_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"w_i_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"w_o_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+64,0,"w_i_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+25,0,"w_o_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"w_o_wr_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("CONTROL_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+69,0,"i_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"i_done_rd",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"i_done_wr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"i_done_j",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+21,0,"o_start_j",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"o_en_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"o_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+27,0,"state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->declBus(c+73,0,"n_state",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 2,0);
    tracep->popPrefix();
    tracep->pushPrefix("DATAPATH_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"i_num_elems",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+21,0,"i_start_j",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"i_en_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"o_done_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"o_done_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+20,0,"o_done_j",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+24,0,"i_data_ram",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"o_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"o_addr_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+72,0,"o_data_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+74,0,"w_UPDATE_J_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"w_UPDATE_J_value_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+20,0,"w_UPDATE_J_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"w_UPDATE_I_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+30,0,"w_UPDATE_I_start_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+31,0,"w_UPDATE_I_start_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"w_UPDATE_I_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"w_UPDATE_I_value_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+34,0,"w_UPDATE_SMALLEST_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"w_UPDATE_SMALLEST_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"w_UPDATE_SMALLEST_value_smallest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+37,0,"w_SWAP_compare",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("SWAP_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+23,0,"i_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"i_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+36,0,"i_addr_smallest",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+24,0,"i_data_ram",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+25,0,"o_rd_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"o_wr_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"o_addr_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+72,0,"o_data_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+37,0,"o_compare",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+18,0,"o_done_rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+19,0,"o_done_wr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+65,0,"i_READ_data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+38,0,"w_READ_data_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+66,0,"i_READ_data_smallest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"w_READ_data_smallest",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+40,0,"w_READ_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"w_READ_select",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+41,0,"w_READ_rd_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+42,0,"w_READ_rd_en_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+43,0,"w_o_done_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"w_WRITE_en",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"w_WRITE_en_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+46,0,"w_WRITE_en_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"w_SELSWAP_sel",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"w_SELSWAP_sel_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"w_SELSWAP_sel_2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->pushPrefix("DEMUX_1_TO_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+24,0,"din",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBit(c+60,0,"sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+66,0,"y0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+65,0,"y1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("SWAP_ADDR_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+45,0,"i_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"i_compare",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"i_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+33,0,"i_addr_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+36,0,"i_addr_smallest",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+64,0,"o_addr_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+47,0,"w_max_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+48,0,"w_min_addr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+49,0,"w_addr_ram_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+50,0,"w_addr_ram_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->popPrefix();
    tracep->pushPrefix("SWAP_DATA_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+44,0,"i_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+37,0,"i_compare",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+61,0,"i_sel",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+38,0,"i_data_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+39,0,"i_data_smallest",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+72,0,"o_data_ram",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+51,0,"w_max_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+52,0,"w_min_data",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+53,0,"w_data_ram_1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+54,0,"w_data_ram_0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->popPrefix();
    tracep->pushPrefix("TFF_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+40,0,"t",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clrn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"prn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+60,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+75,0,"q_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("TFF_UNIT_1", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+25,0,"t",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clrn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"prn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+62,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+76,0,"q_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("TFF_UNIT_2", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+44,0,"t",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+67,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"clrn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+108,0,"prn",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+63,0,"q",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+77,0,"q_next",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("UPDATE_VALUE_I_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"i_num_elems",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+29,0,"i_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+22,0,"i_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"i_value_j",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+33,0,"o_value_i",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+32,0,"o_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+55,0,"w_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+29,0,"w_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+56,0,"w_pre_value_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+57,0,"w_next_value_i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+78,0,"w_pre_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("UPDATE_VALUE_J_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+70,0,"i_num_elems",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+21,0,"i_start",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+32,0,"i_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"o_en",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"o_value_j",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+20,0,"o_done",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+79,0,"w_start",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+80,0,"w_pre_value_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+58,0,"w_next_value_j",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+81,0,"w_pre_done",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+74,0,"w_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->pushPrefix("UPDATE_VALUE_SMALLEST_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+28,0,"i_value_j",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+33,0,"i_value_i",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+34,0,"i_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"i_select",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"o_value_smallest",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBit(c+59,0,"w_enable",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->pushPrefix("RAM_UNIT", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBus(c+82,0,"SIZE_ADDR",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+83,0,"SIZE_DATA",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declArray(c+84,0,"PATH_RAM",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 751,0);
    tracep->declBit(c+67,0,"i_clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+68,0,"i_rst_n",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+25,0,"i_rd_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+26,0,"i_wr_en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+64,0,"i_addr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 3,0);
    tracep->declBus(c+72,0,"i_data",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+24,0,"o_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 7,0);
    tracep->declBus(c+109,0,"DEPTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("mem_unit", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 16; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 7,0);
    }
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
    tracep->popPrefix();
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_init_top(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_init_top\n"); );
    // Body
    Vtb_Selection_Sort___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_Selection_Sort___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void Vtb_Selection_Sort___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_register(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd* tracep) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_register\n"); );
    // Body
    tracep->addConstCb(&Vtb_Selection_Sort___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&Vtb_Selection_Sort___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&Vtb_Selection_Sort___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&Vtb_Selection_Sort___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_const_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_const_0\n"); );
    // Init
    Vtb_Selection_Sort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_Selection_Sort___024root*>(voidSelf);
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_Selection_Sort___024root__trace_const_0_sub_0((&vlSymsp->TOP), bufp);
}

extern const VlWide<24>/*767:0*/ Vtb_Selection_Sort__ConstPool__CONST_h008f395c_0;

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_const_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_const_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+82,(4U),32);
    bufp->fullIData(oldp+83,(8U),32);
    bufp->fullWData(oldp+84,(Vtb_Selection_Sort__ConstPool__CONST_h008f395c_0),752);
    bufp->fullBit(oldp+108,(1U));
    bufp->fullIData(oldp+109,(0x10U),32);
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_full_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_full_0\n"); );
    // Init
    Vtb_Selection_Sort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_Selection_Sort___024root*>(voidSelf);
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    Vtb_Selection_Sort___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root__trace_full_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_full_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullCData(oldp+1,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[0]),8);
    bufp->fullCData(oldp+2,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[1]),8);
    bufp->fullCData(oldp+3,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[2]),8);
    bufp->fullCData(oldp+4,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[3]),8);
    bufp->fullCData(oldp+5,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[4]),8);
    bufp->fullCData(oldp+6,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[5]),8);
    bufp->fullCData(oldp+7,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[6]),8);
    bufp->fullCData(oldp+8,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[7]),8);
    bufp->fullCData(oldp+9,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[8]),8);
    bufp->fullCData(oldp+10,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[9]),8);
    bufp->fullCData(oldp+11,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[10]),8);
    bufp->fullCData(oldp+12,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[11]),8);
    bufp->fullCData(oldp+13,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[12]),8);
    bufp->fullCData(oldp+14,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[13]),8);
    bufp->fullCData(oldp+15,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[14]),8);
    bufp->fullCData(oldp+16,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[15]),8);
    bufp->fullBit(oldp+17,(vlSelf->tb_Selection_Sort__DOT__done));
    bufp->fullBit(oldp+18,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_rd));
    bufp->fullBit(oldp+19,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_wr));
    bufp->fullBit(oldp+20,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done));
    bufp->fullBit(oldp+21,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j));
    bufp->fullBit(oldp+22,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i));
    bufp->fullBit(oldp+23,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en));
    bufp->fullCData(oldp+24,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data),8);
    bufp->fullBit(oldp+25,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en));
    bufp->fullBit(oldp+26,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en));
    bufp->fullCData(oldp+27,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state),3);
    bufp->fullCData(oldp+28,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j),4);
    bufp->fullBit(oldp+29,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start));
    bufp->fullBit(oldp+30,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start));
    bufp->fullBit(oldp+31,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done));
    bufp->fullBit(oldp+32,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
    bufp->fullCData(oldp+33,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i),4);
    bufp->fullBit(oldp+34,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en));
    bufp->fullBit(oldp+35,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select));
    bufp->fullCData(oldp+36,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest),4);
    bufp->fullBit(oldp+37,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    bufp->fullCData(oldp+38,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i),8);
    bufp->fullCData(oldp+39,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest),8);
    bufp->fullBit(oldp+40,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en));
    bufp->fullBit(oldp+41,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en));
    bufp->fullBit(oldp+42,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1));
    bufp->fullBit(oldp+43,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1));
    bufp->fullBit(oldp+44,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
    bufp->fullBit(oldp+45,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr));
    bufp->fullBit(oldp+46,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1));
    bufp->fullCData(oldp+47,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                               ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest)
                               : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))),4);
    bufp->fullCData(oldp+48,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                               ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i)
                               : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest))),4);
    bufp->fullCData(oldp+49,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1),4);
    bufp->fullCData(oldp+50,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0),4);
    bufp->fullCData(oldp+51,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                               ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest)
                               : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i))),8);
    bufp->fullCData(oldp+52,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                               ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i)
                               : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest))),8);
    bufp->fullCData(oldp+53,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1),8);
    bufp->fullCData(oldp+54,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0),8);
    bufp->fullBit(oldp+55,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i) 
                            | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start))));
    bufp->fullCData(oldp+56,((0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start)
                                       ? ((IData)(1U) 
                                          + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))
                                       : ((IData)(1U) 
                                          + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))))),4);
    bufp->fullCData(oldp+57,((0xfU & ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i)))),4);
    bufp->fullCData(oldp+58,((0xfU & ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j)))),4);
    bufp->fullBit(oldp+59,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en) 
                            | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select))));
    bufp->fullBit(oldp+60,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select));
    bufp->fullBit(oldp+61,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel));
    bufp->fullBit(oldp+62,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1));
    bufp->fullBit(oldp+63,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2));
    bufp->fullCData(oldp+64,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr),4);
    bufp->fullCData(oldp+65,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i),8);
    bufp->fullCData(oldp+66,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest),8);
    bufp->fullBit(oldp+67,(vlSelf->tb_Selection_Sort__DOT__clk));
    bufp->fullBit(oldp+68,(vlSelf->tb_Selection_Sort__DOT__rst_n));
    bufp->fullBit(oldp+69,(vlSelf->tb_Selection_Sort__DOT__start));
    bufp->fullCData(oldp+70,(vlSelf->tb_Selection_Sort__DOT__num_elems),4);
    bufp->fullIData(oldp+71,(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd),32);
    bufp->fullCData(oldp+72,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel)
                               ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1)
                               : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0))),8);
    bufp->fullCData(oldp+73,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state),3);
    bufp->fullBit(oldp+74,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en));
    bufp->fullBit(oldp+75,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en) 
                            ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select))));
    bufp->fullBit(oldp+76,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
                            ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en))));
    bufp->fullBit(oldp+77,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2) 
                            ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en))));
    bufp->fullBit(oldp+78,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i) 
                            == (IData)(vlSelf->tb_Selection_Sort__DOT__num_elems))));
    bufp->fullBit(oldp+79,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start));
    bufp->fullCData(oldp+80,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start)
                               ? 0U : (0xfU & ((IData)(1U) 
                                               + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))))),4);
    bufp->fullBit(oldp+81,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
}
