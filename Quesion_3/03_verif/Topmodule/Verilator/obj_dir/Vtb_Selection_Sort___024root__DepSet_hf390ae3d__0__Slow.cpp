// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_Selection_Sort.h for the primary calling header

#include "Vtb_Selection_Sort__pch.h"
#include "Vtb_Selection_Sort__Syms.h"
#include "Vtb_Selection_Sort___024root.h"

extern const VlWide<24>/*767:0*/ Vtb_Selection_Sort__ConstPool__CONST_h008f395c_0;

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_initial__TOP(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_initial__TOP\n"); );
    // Init
    VlWide<6>/*191:0*/ __Vtemp_1;
    // Body
    __Vtemp_1[0U] = 0x2e766364U;
    __Vtemp_1[1U] = 0x536f7274U;
    __Vtemp_1[2U] = 0x696f6e5fU;
    __Vtemp_1[3U] = 0x6c656374U;
    __Vtemp_1[4U] = 0x625f5365U;
    __Vtemp_1[5U] = 0x74U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CVT_PACK_STR_NW(6, __Vtemp_1));
    vlSymsp->_traceDumpOpen();
    VL_READMEM_N(true, 8, 16, 0, VL_CVT_PACK_STR_NW(24, Vtb_Selection_Sort__ConstPool__CONST_h008f395c_0)
                 ,  &(vlSelf->tb_Selection_Sort__DOT__DUT__DOT__RAM_UNIT__DOT__mem_unit)
                 , 0, ~0ULL);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtb_Selection_Sort___024root___dump_triggers__stl(Vtb_Selection_Sort___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtb_Selection_Sort___024root___eval_triggers__stl(Vtb_Selection_Sort___024root* vlSelf) {
    (void)vlSelf;  // Prevent unused variable warning
    Vtb_Selection_Sort__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtb_Selection_Sort___024root___eval_triggers__stl\n"); );
    // Body
    vlSelf->__VstlTriggered.set(0U, (IData)(vlSelf->__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtb_Selection_Sort___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
