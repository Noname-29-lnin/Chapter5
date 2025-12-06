// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_Selection_Sort.h for the primary calling header

#include "Vtb_Selection_Sort__pch.h"
#include "Vtb_Selection_Sort___024root.h"

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_initial__TOP(Vtb_Selection_Sort___024root* vlSelf);
VlCoroutine Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__0(Vtb_Selection_Sort___024root* vlSelf);
VlCoroutine Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__1(Vtb_Selection_Sort___024root* vlSelf);

void Vtb_Selection_Sort___024root___eval_initial(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_initial\n"); );
    // Body
    Vtb_Selection_Sort___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__0(vlSelf);
    Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__1(vlSelf);
    vlSelf->__Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__clk__0 
        = vlSelf->tb_Selection_Sort__DOT__clk;
    vlSelf->__Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__rst_n__0 
        = vlSelf->tb_Selection_Sort__DOT__rst_n;
}

extern const VlWide<23>/*735:0*/ Vtb_Selection_Sort__ConstPool__CONST_hd55ccaf2_0;

VL_INLINE_OPT VlCoroutine Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__0(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__0\n"); );
    // Body
    vlSelf->tb_Selection_Sort__DOT__clk = 0U;
    vlSelf->tb_Selection_Sort__DOT__rst_n = 0U;
    vlSelf->tb_Selection_Sort__DOT__start = 0U;
    vlSelf->tb_Selection_Sort__DOT__num_elems = 0U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                       75);
    vlSelf->tb_Selection_Sort__DOT__rst_n = 1U;
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                       79);
    VL_WRITEF_NX(">>> Sending START...\n",0);
    vlSelf->tb_Selection_Sort__DOT__start = 1U;
    co_await vlSelf->__VdlySched.delay(0x2710ULL, nullptr, 
                                       "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                       82);
    vlSelf->tb_Selection_Sort__DOT__start = 0U;
    co_await vlSelf->__VdlySched.delay(0x989680ULL, 
                                       nullptr, "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                       87);
    VL_WRITEF_NX(">>> DONE received at time %0t\n",0,
                 64,VL_TIME_UNITED_Q(1000),-9);
    vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd 
        = VL_FOPEN_NN(VL_CVT_PACK_STR_NW(23, Vtb_Selection_Sort__ConstPool__CONST_hd55ccaf2_0)
                      , std::string{"w"});
    ;
    VL_WRITEF_NX("\n===== RAM AFTER SORT =====\n",0);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0U]);
    VL_WRITEF_NX("RAM[0] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [1U]);
    VL_WRITEF_NX("RAM[1] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [1U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [2U]);
    VL_WRITEF_NX("RAM[2] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [2U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [3U]);
    VL_WRITEF_NX("RAM[3] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [3U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [4U]);
    VL_WRITEF_NX("RAM[4] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [4U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [5U]);
    VL_WRITEF_NX("RAM[5] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [5U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [6U]);
    VL_WRITEF_NX("RAM[6] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [6U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [7U]);
    VL_WRITEF_NX("RAM[7] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [7U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [8U]);
    VL_WRITEF_NX("RAM[8] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [8U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [9U]);
    VL_WRITEF_NX("RAM[9] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [9U]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xaU]);
    VL_WRITEF_NX("RAM[10] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xaU]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xbU]);
    VL_WRITEF_NX("RAM[11] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xbU]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xcU]);
    VL_WRITEF_NX("RAM[12] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xcU]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xdU]);
    VL_WRITEF_NX("RAM[13] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xdU]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xeU]);
    VL_WRITEF_NX("RAM[14] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xeU]);
    VL_FWRITEF_NX(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd,"%02x\n",0,
                  8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                  [0xfU]);
    VL_WRITEF_NX("RAM[15] = %02x\n",0,8,vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                 [0xfU]);
    VL_FCLOSE_I(vlSelf->tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd); VL_WRITEF_NX(">>> Saved sorted RAM to sorted_output.txt\n",0);
    co_await vlSelf->__VdlySched.delay(0x4e20ULL, nullptr, 
                                       "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                       93);
    VL_FINISH_MT("/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 94, "");
}

VL_INLINE_OPT VlCoroutine Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__1(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_initial__TOP__Vtiming__1\n"); );
    // Body
    while (1U) {
        co_await vlSelf->__VdlySched.delay(0x1388ULL, 
                                           nullptr, 
                                           "/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 
                                           39);
        vlSelf->tb_Selection_Sort__DOT__clk = (1U & 
                                               (~ (IData)(vlSelf->tb_Selection_Sort__DOT__clk)));
    }
}

void Vtb_Selection_Sort___024root___act_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf);

void Vtb_Selection_Sort___024root___eval_act(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_act\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___act_sequent__TOP__0(vlSelf);
    }
}

extern const VlUnpacked<CData/*2:0*/, 128> Vtb_Selection_Sort__ConstPool__TABLE_he6ce0ab9_0;

VL_INLINE_OPT void Vtb_Selection_Sort___024root___act_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___act_sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
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
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start)
            ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))));
}

void Vtb_Selection_Sort___024root___nba_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf);
void Vtb_Selection_Sort___024root___nba_sequent__TOP__1(Vtb_Selection_Sort___024root* vlSelf);
void Vtb_Selection_Sort___024root___nba_comb__TOP__0(Vtb_Selection_Sort___024root* vlSelf);
void Vtb_Selection_Sort___024root___nba_comb__TOP__1(Vtb_Selection_Sort___024root* vlSelf);

void Vtb_Selection_Sort___024root___eval_nba(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_nba\n"); );
    // Body
    if ((1ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___nba_sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[2U] = 1U;
    }
    if ((2ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___nba_sequent__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[3U] = 1U;
    }
    if ((5ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___nba_comb__TOP__0(vlSelf);
    }
    if ((3ULL & vlSelf->__VnbaTriggered.word(0U))) {
        Vtb_Selection_Sort___024root___nba_comb__TOP__1(vlSelf);
        vlSelf->__Vm_traceActivity[4U] = 1U;
    }
}

extern const VlUnpacked<CData/*0:0*/, 16> Vtb_Selection_Sort__ConstPool__TABLE_hb00e87d1_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtb_Selection_Sort__ConstPool__TABLE_ha7d153a7_0;
extern const VlUnpacked<CData/*0:0*/, 16> Vtb_Selection_Sort__ConstPool__TABLE_hcdcefb43_0;

VL_INLINE_OPT void Vtb_Selection_Sort___024root___nba_sequent__TOP__0(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vtableidx2;
    __Vtableidx2 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0;
    __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 = 0;
    CData/*7:0*/ __Vdlyvval__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0;
    __Vdlyvval__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 = 0;
    CData/*0:0*/ __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0;
    __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 = 0;
    CData/*3:0*/ __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1;
    __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1 = 0;
    CData/*0:0*/ __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1;
    __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1 = 0;
    // Body
    __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 = 0U;
    __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1 = 0U;
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_wr 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en));
    vlSelf->tb_Selection_Sort__DOT__done = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
                                            & (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_done_rd 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
    if (vlSelf->tb_Selection_Sort__DOT__rst_n) {
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en) {
            __Vdlyvval__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 
                = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel)
                    ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1)
                    : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0));
            __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 = 1U;
            __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr;
        }
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit
                [vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr];
        }
    } else {
        __Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1 = 1U;
        __Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1 
            = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_data = 0U;
    }
    if (__Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0) {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[__Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0] 
            = __Vdlyvval__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v0;
    }
    if (__Vdlyvset__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1) {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit[__Vdlyvdim0__tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit__v1] = 0U;
    }
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i) 
               == (IData)(vlSelf->tb_Selection_Sort__DOT__num_elems)));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en));
    if (vlSelf->tb_Selection_Sort__DOT__rst_n) {
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr) {
            if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare) {
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i;
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest;
            } else {
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest;
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i;
            }
        }
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en) {
            if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare) {
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest;
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i;
            } else {
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i;
                vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0 
                    = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest;
            }
        }
        if (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en) 
             | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select))) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest 
                = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select)
                    ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i)
                    : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j));
        }
    } else {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0 = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1 = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1 = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0 = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest = 0U;
    }
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en));
    if (vlSelf->tb_Selection_Sort__DOT__rst_n) {
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i;
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest;
        }
        if (vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j;
        }
        if (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i) 
             | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start))) {
            vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i 
                = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_I_UNIT__DOT__w_pre_value_i;
        }
    } else {
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j = 0U;
        vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i = 0U;
    }
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i) 
           < (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_I_UNIT__DOT__w_pre_value_i 
        = (0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start)
                    ? ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))
                    : ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i))));
    __Vtableidx2 = (((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state) 
                     << 1U) | (IData)(vlSelf->tb_Selection_Sort__DOT__rst_n));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n)
            ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state)
            : 0U);
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j 
        = Vtb_Selection_Sort__ConstPool__TABLE_hb00e87d1_0
        [__Vtableidx2];
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_en_i 
        = Vtb_Selection_Sort__ConstPool__TABLE_ha7d153a7_0
        [__Vtableidx2];
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en 
        = Vtb_Selection_Sort__ConstPool__TABLE_hcdcefb43_0
        [__Vtableidx2];
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select 
        = ((~ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en)) 
           & (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__rst_n) 
           && (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
}

VL_INLINE_OPT void Vtb_Selection_Sort___024root___nba_sequent__TOP__1(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___nba_sequent__TOP__1\n"); );
    // Body
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select 
        = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT__DOT__q_next;
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2 
        = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_2__DOT__q_next;
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1 
        = vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_1__DOT__q_next;
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2));
}

VL_INLINE_OPT void Vtb_Selection_Sort___024root___nba_comb__TOP__0(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___nba_comb__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    __Vtableidx1 = 0;
    // Body
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j) 
           == (0xfU & ((IData)(vlSelf->tb_Selection_Sort__DOT__num_elems) 
                       - (IData)(1U))));
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
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_start_j) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start) 
           | (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start)
            ? 0U : (0xfU & ((IData)(1U) + (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j))));
}

VL_INLINE_OPT void Vtb_Selection_Sort___024root___nba_comb__TOP__1(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___nba_comb__TOP__1\n"); );
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
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_2__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_1__DOT__q_next 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1) 
           ^ (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en));
    vlSelf->tb_Selection_Sort__DOT__DUT__DOT__w_i_addr 
        = ((IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel)
            ? (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1)
            : (IData)(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0));
}

void Vtb_Selection_Sort___024root___timing_resume(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___timing_resume\n"); );
    // Body
    if ((4ULL & vlSelf->__VactTriggered.word(0U))) {
        vlSelf->__VdlySched.resume();
    }
}

void Vtb_Selection_Sort___024root___eval_triggers__act(Vtb_Selection_Sort___024root* vlSelf);

bool Vtb_Selection_Sort___024root___eval_phase__act(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_phase__act\n"); );
    // Init
    VlTriggerVec<3> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    Vtb_Selection_Sort___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelf->__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
        vlSelf->__VnbaTriggered.thisOr(vlSelf->__VactTriggered);
        Vtb_Selection_Sort___024root___timing_resume(vlSelf);
        Vtb_Selection_Sort___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool Vtb_Selection_Sort___024root___eval_phase__nba(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_phase__nba\n"); );
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelf->__VnbaTriggered.any();
    if (__VnbaExecute) {
        Vtb_Selection_Sort___024root___eval_nba(vlSelf);
        vlSelf->__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__nba(Vtb_Selection_Sort___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__act(Vtb_Selection_Sort___024root* vlSelf);
#endif  // VL_DEBUG

void Vtb_Selection_Sort___024root___eval(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval\n"); );
    // Init
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
            Vtb_Selection_Sort___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 3, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                Vtb_Selection_Sort___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("/home/noname/Documents/project_tiny/Chapter5/Quesion_3/03_verif/Topmodule/tb_Selection_Sort.sv", 3, "", "Active region did not converge.");
            }
            vlSelf->__VactIterCount = ((IData)(1U) 
                                       + vlSelf->__VactIterCount);
            vlSelf->__VactContinue = 0U;
            if (Vtb_Selection_Sort___024root___eval_phase__act(vlSelf)) {
                vlSelf->__VactContinue = 1U;
            }
        }
        if (Vtb_Selection_Sort___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void Vtb_Selection_Sort___024root___eval_debug_assertions(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_debug_assertions\n"); );
}
#endif  // VL_DEBUG
