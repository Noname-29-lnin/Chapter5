// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_Selection_Sort.h for the primary calling header

#ifndef VERILATED_VTB_SELECTION_SORT___024ROOT_H_
#define VERILATED_VTB_SELECTION_SORT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_Selection_Sort__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_Selection_Sort___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    CData/*0:0*/ tb_Selection_Sort__DOT__clk;
    CData/*0:0*/ tb_Selection_Sort__DOT__rst_n;
    CData/*0:0*/ tb_Selection_Sort__DOT__start;
    CData/*3:0*/ tb_Selection_Sort__DOT__num_elems;
    CData/*0:0*/ tb_Selection_Sort__DOT__done;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_done_rd;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_done_wr;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_start_j;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_en_i;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_rd_en;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_i_data;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_i_addr;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_o_rd_en;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__w_o_wr_en;
    CData/*2:0*/ tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__state;
    CData/*2:0*/ tb_Selection_Sort__DOT__DUT__DOT__CONTROL_UNIT__DOT__n_state;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_en;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_value_j;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_J_done;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_start;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_start_done;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_done;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_I_value_i;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_en;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_select;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_UPDATE_SMALLEST_value_smallest;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__w_SWAP_compare;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_start;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_value_j;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_J_UNIT__DOT__w_pre_done;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__UPDATE_VALUE_I_UNIT__DOT__w_pre_value_i;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_i;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_i;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__i_READ_data_smallest;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_data_smallest;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_en;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_select;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_READ_rd_en_1;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_o_done_1;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_addr;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_WRITE_en_1;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_1;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__w_SELSWAP_sel_2;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT__DOT__q_next;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_1__DOT__q_next;
    CData/*0:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__TFF_UNIT_2__DOT__q_next;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_1;
    CData/*7:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_DATA_UNIT__DOT__w_data_ram_0;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_1;
    CData/*3:0*/ tb_Selection_Sort__DOT__DUT__DOT__DATAPATH_UNIT__DOT__SWAP_UNIT__DOT__SWAP_ADDR_UNIT__DOT__w_addr_ram_0;
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__tb_Selection_Sort__DOT__rst_n__0;
    CData/*0:0*/ __VactContinue;
    IData/*31:0*/ tb_Selection_Sort__DOT__dump_ram_contents__Vstatic__fd;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<CData/*7:0*/, 16> tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit;
    VlUnpacked<CData/*0:0*/, 5> __Vm_traceActivity;
    VlDelayScheduler __VdlySched;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_Selection_Sort__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_Selection_Sort___024root(Vtb_Selection_Sort__Syms* symsp, const char* v__name);
    ~Vtb_Selection_Sort___024root();
    VL_UNCOPYABLE(Vtb_Selection_Sort___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
