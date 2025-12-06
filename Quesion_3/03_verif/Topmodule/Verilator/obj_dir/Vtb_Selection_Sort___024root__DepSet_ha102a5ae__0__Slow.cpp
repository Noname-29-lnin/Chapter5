// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_Selection_Sort.h for the primary calling header

#include "Vtb_Selection_Sort__pch.h"
#include "Vtb_Selection_Sort___024root.h"

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_static(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_final(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_final\n"); );
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__stl(Vtb_Selection_Sort___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtb_Selection_Sort___024root___eval_phase__stl(Vtb_Selection_Sort___024root* vlSelf);

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_settle(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_settle\n"); );
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelf->__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY((0x64U < __VstlIterCount))) {
#ifdef VL_DEBUG
            Vtb_Selection_Sort___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 3, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (Vtb_Selection_Sort___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelf->__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__stl(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ vlSelf->__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_Selection_Sort___024root___stl_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf);

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_stl(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_stl\n"); );
    // Body
    if ((1ULL & vlSelf->__VstlTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___stl_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
        vlSelf->__Vm_traceActivity[3U] = 1U;
        vlSelf->__Vm_traceActivity[2U] = 1U;
        vlSelf->__Vm_traceActivity[1U] = 1U;
        vlSelf->__Vm_traceActivity[0U] = 1U;
    }
}

extern const VlUnpacked<CData/*2:0*/, 128> Vtb_Selection_Sort__ConstPool__TABLE_he6ce0ab9_0;

VL_ATTR_COLD void Vtb_Selection_Sort___024root___stl_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___stl_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest = 0U;
    if ((1U & (~ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select)))) {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest 
            = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data;
    }
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i = 0U;
    if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select) {
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data;
        }
    }
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_1__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2));
    __Vtableidx1 = (((IData)(vlSelf->tb_Selection_Sort__DOT__start) 
                     << 6U) | (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_rd) 
                                << 5U) | (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_wr) 
                                           << 4U) | 
                                          (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done) 
                                            << 3U) 
                                           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state)))));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state 
        = Vtb_Selection_Sort__ConstPool__TABLE_he6ce0ab9_0
        [__Vtableidx1];
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j) 
           == (0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__num_elems) 
                       - (IData)(1U))));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i) 
           < (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_I_UNIT__DOT__w_pre_value_i 
        = (0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start)
                    ? ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))
                    : ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel)
            ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1)
            : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select 
        = ((~ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en)) 
           & (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start)
            ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_2__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
}

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_triggers__stl(Vtb_Selection_Sort___024root* vlSelf);

VL_ATTR_COLD bool Vtb_Selection_Sort___024root___eval_phase__stl(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_phase__stl\n"); );
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    Vtb_Selection_Sort___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelf->__VstlTriggered.any();
    if (__VstlExecute) {
        Vtb_Selection_Sort___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__act(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ vlSelf->__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge tb_Selection_Sort.clk or negedge tb_Selection_Sort.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(posedge tb_Selection_Sort.clk)\n");
    }
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__nba(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ vlSelf->__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge tb_Selection_Sort.clk or negedge tb_Selection_Sort.rst_n)\n");
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(posedge tb_Selection_Sort.clk)\n");
    }
    if ((4ULL & vlSelf->__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 2 is active: @([true] __VdlySched.awaitingCurrentTime())\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_Selection_Sort___024root___ctor_var_reset(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->tb_Selection_Sort__DOT__clk = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__rst_n = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__start = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__num_elems = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__done = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd = 0;
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_rd = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_wr = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state = VL_RAND_RESET_I(3);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state = VL_RAND_RESET_I(3);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_I_UNIT__DOT__w_pre_value_i = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1 = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2 = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT__DOT__q_next = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_1__DOT__q_next = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_2__DOT__q_next = VL_RAND_RESET_I(1);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1 = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0 = VL_RAND_RESET_I(8);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1 = VL_RAND_RESET_I(4);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0 = VL_RAND_RESET_I(4);
    for (int __Vi0 = 0; __Vi0 < 16; ++__Vi0) {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[__Vi0] = VL_RAND_RESET_I(8);
    }
    vlSelf->__Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__rst_n__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 5; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
