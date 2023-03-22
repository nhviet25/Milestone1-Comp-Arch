// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*2:0*/, 1024> Vtop__ConstPool__TABLE_h8f672d3f_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vtop__ConstPool__TABLE_hae71a1ea_0;
extern const VlUnpacked<CData/*0:0*/, 1024> Vtop__ConstPool__TABLE_h14183efd_0;
extern const VlUnpacked<CData/*2:0*/, 1024> Vtop__ConstPool__TABLE_hc6af825c_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    SData/*9:0*/ __Vtableidx2;
    // Body
    __Vtableidx2 = (((IData)(vlSelf->top__DOT__dut__DOT__coin) 
                     << 7U) | (((IData)(vlSelf->top__DOT__dut__DOT__state) 
                                << 4U) | (((IData)(vlSelf->top__DOT__dut__DOT__next_state) 
                                           << 1U) | (IData)(vlSelf->rst_ni))));
    vlSelf->top__DOT__dut__DOT__state = Vtop__ConstPool__TABLE_h8f672d3f_0
        [__Vtableidx2];
    if ((2U & Vtop__ConstPool__TABLE_hae71a1ea_0[__Vtableidx2])) {
        vlSelf->soda_o = Vtop__ConstPool__TABLE_h14183efd_0
            [__Vtableidx2];
    }
    if ((4U & Vtop__ConstPool__TABLE_hae71a1ea_0[__Vtableidx2])) {
        vlSelf->change_o = Vtop__ConstPool__TABLE_hc6af825c_0
            [__Vtableidx2];
    }
}

extern const VlUnpacked<CData/*2:0*/, 64> Vtop__ConstPool__TABLE_h4c9ae925_0;

VL_INLINE_OPT void Vtop___024root___combo__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___combo__TOP__0\n"); );
    // Init
    CData/*5:0*/ __Vtableidx1;
    // Body
    vlSelf->top__DOT__dut__DOT__coin = (((IData)(vlSelf->quarter_i) 
                                         << 2U) | (
                                                   ((IData)(vlSelf->dime_i) 
                                                    << 1U) 
                                                   | (IData)(vlSelf->nickle_i)));
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__dut__DOT__coin) 
                     << 3U) | (IData)(vlSelf->top__DOT__dut__DOT__state));
    vlSelf->top__DOT__dut__DOT__next_state = Vtop__ConstPool__TABLE_h4c9ae925_0
        [__Vtableidx1];
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk_i) & (~ (IData)(vlSelf->__Vclklast__TOP__clk_i)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
    }
    Vtop___024root___combo__TOP__0(vlSelf);
    // Final
    vlSelf->__Vclklast__TOP__clk_i = vlSelf->clk_i;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk_i & 0xfeU))) {
        Verilated::overWidthError("clk_i");}
    if (VL_UNLIKELY((vlSelf->rst_ni & 0xfeU))) {
        Verilated::overWidthError("rst_ni");}
    if (VL_UNLIKELY((vlSelf->nickle_i & 0xfeU))) {
        Verilated::overWidthError("nickle_i");}
    if (VL_UNLIKELY((vlSelf->dime_i & 0xfeU))) {
        Verilated::overWidthError("dime_i");}
    if (VL_UNLIKELY((vlSelf->quarter_i & 0xfeU))) {
        Verilated::overWidthError("quarter_i");}
}
#endif  // VL_DEBUG
