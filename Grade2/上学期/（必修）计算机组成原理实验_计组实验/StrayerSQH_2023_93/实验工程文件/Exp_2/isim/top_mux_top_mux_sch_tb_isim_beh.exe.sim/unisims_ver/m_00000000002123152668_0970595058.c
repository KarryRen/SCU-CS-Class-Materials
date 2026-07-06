/**********************************************************************/
/*   ____  ____                                                       */
/*  /   /\/   /                                                       */
/* /___/  \  /                                                        */
/* \   \   \/                                                       */
/*  \   \        Copyright (c) 2003-2009 Xilinx, Inc.                */
/*  /   /          All Right Reserved.                                 */
/* /---/   /\                                                         */
/* \   \  /  \                                                      */
/*  \___\/\___\                                                    */
/***********************************************************************/

/* This file is designed for use with ISim build 0x8ef4fb42 */

#define XSI_HIDE_SYMBOL_SPEC true
#include "xsi.h"
#include <memory.h>
#ifdef __GNUC__
#include <stdlib.h>
#else
#include <malloc.h>
#define alloca _alloca
#endif



static void Gate_29_0(char *t0)
{
    char *t1;
    char *t2;
    char *t3;
    char *t4;
    char *t5;
    char *t6;
    char *t7;
    char *t8;
    char *t9;
    char *t10;

LAB0:    t1 = (t0 + 1444U);
    t2 = *((char **)t1);
    if (t2 == 0)
        goto LAB2;

LAB3:    goto *t2;

LAB2:    t2 = (t0 + 692U);
    t3 = *((char **)t2);
    t2 = (t0 + 784U);
    t4 = *((char **)t2);
    t2 = (t0 + 1684);
    t5 = (t2 + 32U);
    t6 = *((char **)t5);
    t7 = (t6 + 40U);
    t8 = *((char **)t7);
    xsi_vlog_OrGate(t8, 2, t3, t4);
    t9 = (t0 + 1684);
    xsi_driver_vfirst_trans(t9, 0, 0);
    t10 = (t0 + 1640);
    *((int *)t10) = 1;

LAB1:    return;
}


extern void unisims_ver_m_00000000002123152668_0970595058_init()
{
	static char *pe[] = {(void *)Gate_29_0};
	xsi_register_didat("unisims_ver_m_00000000002123152668_0970595058", "isim/top_mux_top_mux_sch_tb_isim_beh.exe.sim/unisims_ver/m_00000000002123152668_0970595058.didat");
	xsi_register_executes(pe);
}
