// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtb_Selection_Sort.h for the primary calling header

#include "Vtb_Selection_Sort__pch.h"
#include "Vtb_Selection_Sort__Syms.h"
#include "Vtb_Selection_Sort___024root.h"

void Vtb_Selection_Sort___024root___ctor_var_reset(Vtb_Selection_Sort___024root* vlSelf);

Vtb_Selection_Sort___024root::Vtb_Selection_Sort___024root(Vtb_Selection_Sort__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , __VdlySched{*symsp->_vm_contextp__}
    , vlSymsp{symsp}
 {
    // Reset structure values
    Vtb_Selection_Sort___024root___ctor_var_reset(this);
}

void Vtb_Selection_Sort___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vtb_Selection_Sort___024root::~Vtb_Selection_Sort___024root() {
}
