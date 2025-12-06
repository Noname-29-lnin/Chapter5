// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtb_Selection_Sort__Syms.h"


void Vtb_Selection_Sort___024root__trace_chg_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtb_Selection_Sort___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_chg_0\n"); );
    // Init
    Vtb_Selection_Sort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_Selection_Sort___024root*>(voidSelf);
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtb_Selection_Sort___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void Vtb_Selection_Sort___024root__trace_chg_0_sub_0(Vtb_Selection_Sort___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_chg_0_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelf->__Vm_traceActivity[1U] 
                     | vlSelf->__Vm_traceActivity[2U]))) {
        bufp->chgCData(oldp+0,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[0]),8);
        bufp->chgCData(oldp+1,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[1]),8);
        bufp->chgCData(oldp+2,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[2]),8);
        bufp->chgCData(oldp+3,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[3]),8);
        bufp->chgCData(oldp+4,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[4]),8);
        bufp->chgCData(oldp+5,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[5]),8);
        bufp->chgCData(oldp+6,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[6]),8);
        bufp->chgCData(oldp+7,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[7]),8);
        bufp->chgCData(oldp+8,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[8]),8);
        bufp->chgCData(oldp+9,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[9]),8);
        bufp->chgCData(oldp+10,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[10]),8);
        bufp->chgCData(oldp+11,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[11]),8);
        bufp->chgCData(oldp+12,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[12]),8);
        bufp->chgCData(oldp+13,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[13]),8);
        bufp->chgCData(oldp+14,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[14]),8);
        bufp->chgCData(oldp+15,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[15]),8);
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[2U])) {
        bufp->chgBit(oldp+16,(vlSelf->tb_Selection_Sort__DOT__done));
        bufp->chgBit(oldp+17,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_rd));
        bufp->chgBit(oldp+18,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_wr));
        bufp->chgBit(oldp+19,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done));
        bufp->chgBit(oldp+20,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j));
        bufp->chgBit(oldp+21,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i));
        bufp->chgBit(oldp+22,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en));
        bufp->chgCData(oldp+23,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data),8);
        bufp->chgBit(oldp+24,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en));
        bufp->chgBit(oldp+25,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en));
        bufp->chgCData(oldp+26,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state),3);
        bufp->chgCData(oldp+27,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j),4);
        bufp->chgBit(oldp+28,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start));
        bufp->chgBit(oldp+29,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start));
        bufp->chgBit(oldp+30,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done));
        bufp->chgBit(oldp+31,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
        bufp->chgCData(oldp+32,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i),4);
        bufp->chgBit(oldp+33,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en));
        bufp->chgBit(oldp+34,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select));
        bufp->chgCData(oldp+35,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest),4);
        bufp->chgBit(oldp+36,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
        bufp->chgCData(oldp+37,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i),8);
        bufp->chgCData(oldp+38,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest),8);
        bufp->chgBit(oldp+39,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en));
        bufp->chgBit(oldp+40,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en));
        bufp->chgBit(oldp+41,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1));
        bufp->chgBit(oldp+42,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1));
        bufp->chgBit(oldp+43,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
        bufp->chgBit(oldp+44,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr));
        bufp->chgBit(oldp+45,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1));
        bufp->chgCData(oldp+46,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                                  ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest)
                                  : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))),4);
        bufp->chgCData(oldp+47,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                                  ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i)
                                  : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest))),4);
        bufp->chgCData(oldp+48,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1),4);
        bufp->chgCData(oldp+49,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0),4);
        bufp->chgCData(oldp+50,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                                  ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest)
                                  : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i))),8);
        bufp->chgCData(oldp+51,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare)
                                  ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i)
                                  : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest))),8);
        bufp->chgCData(oldp+52,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1),8);
        bufp->chgCData(oldp+53,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0),8);
        bufp->chgBit(oldp+54,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i) 
                               | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start))));
        bufp->chgCData(oldp+55,((0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start)
                                          ? ((IData)(1U) 
                                             + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))
                                          : ((IData)(1U) 
                                             + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))))),4);
        bufp->chgCData(oldp+56,((0xfU & ((IData)(1U) 
                                         + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i)))),4);
        bufp->chgCData(oldp+57,((0xfU & ((IData)(1U) 
                                         + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j)))),4);
        bufp->chgBit(oldp+58,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en) 
                               | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select))));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[3U])) {
        bufp->chgBit(oldp+59,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select));
        bufp->chgBit(oldp+60,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel));
        bufp->chgBit(oldp+61,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1));
        bufp->chgBit(oldp+62,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2));
    }
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[4U])) {
        bufp->chgCData(oldp+63,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr),4);
        bufp->chgCData(oldp+64,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i),8);
        bufp->chgCData(oldp+65,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest),8);
    }
    bufp->chgBit(oldp+66,(vlSelf->tb_Selection_Sort__DOT__clk));
    bufp->chgBit(oldp+67,(vlSelf->tb_Selection_Sort__DOT__rst_n));
    bufp->chgBit(oldp+68,(vlSelf->tb_Selection_Sort__DOT__start));
    bufp->chgCData(oldp+69,(vlSelf->tb_Selection_Sort__DOT__num_elems),4);
    bufp->chgIData(oldp+70,(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd),32);
    bufp->chgCData(oldp+71,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel)
                              ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1)
                              : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0))),8);
    bufp->chgCData(oldp+72,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state),3);
    bufp->chgBit(oldp+73,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en));
    bufp->chgBit(oldp+74,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en) 
                           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select))));
    bufp->chgBit(oldp+75,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
                           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en))));
    bufp->chgBit(oldp+76,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2) 
                           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en))));
    bufp->chgBit(oldp+77,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i) 
                           == (IData)(vlSelf->tb_Selection_Sort__DOT__num_elems))));
    bufp->chgBit(oldp+78,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start));
    bufp->chgCData(oldp+79,(((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start)
                              ? 0U : (0xfU & ((IData)(1U) 
                                              + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))))),4);
    bufp->chgBit(oldp+80,(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
}

void Vtb_Selection_Sort___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root__trace_cleanup\n"); );
    // Init
    Vtb_Selection_Sort___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtb_Selection_Sort___024root*>(voidSelf);
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[2U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[3U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[4U] = 0U;
}
