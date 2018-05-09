/*
 * Generated by Bluespec Compiler, version 2014.07.A (build 34078, 2014-07-30)
 * 
 * On Wed May  9 11:32:10 KST 2018
 * 
 */

/* Generation options: */
#ifndef __mkProc_h__
#define __mkProc_h__

#include "bluesim_types.h"
#include "bs_module.h"
#include "bluesim_primitives.h"
#include "bs_vcd.h"
#include "mkCop.h"
#include "mkDMemory.h"
#include "mkIMemory.h"
#include "mkRFile.h"


/* Class declaration for the mkProc module */
class MOD_mkProc : public Module {
 
 /* Clock handles */
 private:
  tClock __clk_handle_0;
 
 /* Clock gate handles */
 public:
  tUInt8 *clk_gate[0];
 
 /* Instantiation parameters */
 public:
 
 /* Module state */
 public:
  MOD_Reg<tUInt8> INST_condFlag;
  MOD_mkCop INST_cop;
  MOD_Reg<tUWide> INST_d2r_data_0;
  MOD_Reg<tUWide> INST_d2r_data_1;
  MOD_Reg<tUInt8> INST_d2r_deqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_deqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_d2r_deqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_d2r_deqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_d2r_deqEn_lat_0;
  MOD_Wire<tUInt8> INST_d2r_deqEn_lat_1;
  MOD_Wire<tUInt8> INST_d2r_deqEn_lat_2;
  MOD_Reg<tUInt8> INST_d2r_deqEn_rl;
  MOD_Reg<tUInt8> INST_d2r_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_deqP_dummy2_1;
  MOD_Reg<tUInt8> INST_d2r_deqP_dummy2_2;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_d2r_deqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_d2r_deqP_lat_0;
  MOD_Wire<tUInt8> INST_d2r_deqP_lat_1;
  MOD_Wire<tUInt8> INST_d2r_deqP_lat_2;
  MOD_Reg<tUInt8> INST_d2r_deqP_rl;
  MOD_Reg<tUInt8> INST_d2r_enqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_enqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_d2r_enqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_d2r_enqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_d2r_enqEn_lat_0;
  MOD_Wire<tUInt8> INST_d2r_enqEn_lat_1;
  MOD_Wire<tUInt8> INST_d2r_enqEn_lat_2;
  MOD_Reg<tUInt8> INST_d2r_enqEn_rl;
  MOD_Reg<tUInt8> INST_d2r_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_enqP_dummy2_1;
  MOD_Reg<tUInt8> INST_d2r_enqP_dummy2_2;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_d2r_enqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_d2r_enqP_lat_0;
  MOD_Wire<tUInt8> INST_d2r_enqP_lat_1;
  MOD_Wire<tUInt8> INST_d2r_enqP_lat_2;
  MOD_Reg<tUInt8> INST_d2r_enqP_rl;
  MOD_Reg<tUInt8> INST_d2r_tempData_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_tempData_dummy2_1;
  MOD_Wire<tUWide> INST_d2r_tempData_dummy_0_0;
  MOD_Wire<tUWide> INST_d2r_tempData_dummy_0_1;
  MOD_Wire<tUWide> INST_d2r_tempData_dummy_1_0;
  MOD_Wire<tUWide> INST_d2r_tempData_dummy_1_1;
  MOD_Wire<tUWide> INST_d2r_tempData_lat_0;
  MOD_Wire<tUWide> INST_d2r_tempData_lat_1;
  MOD_Reg<tUWide> INST_d2r_tempData_rl;
  MOD_Reg<tUInt8> INST_d2r_tempEnqP_dummy2_0;
  MOD_Reg<tUInt8> INST_d2r_tempEnqP_dummy2_1;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_lat_0;
  MOD_Wire<tUInt8> INST_d2r_tempEnqP_lat_1;
  MOD_Reg<tUInt8> INST_d2r_tempEnqP_rl;
  MOD_mkDMemory INST_dMem;
  MOD_Reg<tUInt8> INST_eEpoch;
  MOD_Reg<tUInt64> INST_execRedirect_data_0;
  MOD_Reg<tUInt8> INST_execRedirect_deqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_deqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_execRedirect_deqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_lat_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_lat_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqEn_lat_2;
  MOD_Reg<tUInt8> INST_execRedirect_deqEn_rl;
  MOD_Reg<tUInt8> INST_execRedirect_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_deqP_dummy2_1;
  MOD_Reg<tUInt8> INST_execRedirect_deqP_dummy2_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_lat_0;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_lat_1;
  MOD_Wire<tUInt8> INST_execRedirect_deqP_lat_2;
  MOD_Reg<tUInt8> INST_execRedirect_deqP_rl;
  MOD_Reg<tUInt8> INST_execRedirect_enqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_enqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_execRedirect_enqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_lat_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_lat_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqEn_lat_2;
  MOD_Reg<tUInt8> INST_execRedirect_enqEn_rl;
  MOD_Reg<tUInt8> INST_execRedirect_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_enqP_dummy2_1;
  MOD_Reg<tUInt8> INST_execRedirect_enqP_dummy2_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_lat_0;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_lat_1;
  MOD_Wire<tUInt8> INST_execRedirect_enqP_lat_2;
  MOD_Reg<tUInt8> INST_execRedirect_enqP_rl;
  MOD_Reg<tUInt8> INST_execRedirect_tempData_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_tempData_dummy2_1;
  MOD_Wire<tUWide> INST_execRedirect_tempData_dummy_0_0;
  MOD_Wire<tUWide> INST_execRedirect_tempData_dummy_0_1;
  MOD_Wire<tUWide> INST_execRedirect_tempData_dummy_1_0;
  MOD_Wire<tUWide> INST_execRedirect_tempData_dummy_1_1;
  MOD_Wire<tUInt64> INST_execRedirect_tempData_lat_0;
  MOD_Wire<tUInt64> INST_execRedirect_tempData_lat_1;
  MOD_Reg<tUInt64> INST_execRedirect_tempData_rl;
  MOD_Reg<tUInt8> INST_execRedirect_tempEnqP_dummy2_0;
  MOD_Reg<tUInt8> INST_execRedirect_tempEnqP_dummy2_1;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_lat_0;
  MOD_Wire<tUInt8> INST_execRedirect_tempEnqP_lat_1;
  MOD_Reg<tUInt8> INST_execRedirect_tempEnqP_rl;
  MOD_Reg<tUWide> INST_f2d_data_0;
  MOD_Reg<tUWide> INST_f2d_data_1;
  MOD_Reg<tUInt8> INST_f2d_deqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_deqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_f2d_deqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_f2d_deqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_f2d_deqEn_lat_0;
  MOD_Wire<tUInt8> INST_f2d_deqEn_lat_1;
  MOD_Wire<tUInt8> INST_f2d_deqEn_lat_2;
  MOD_Reg<tUInt8> INST_f2d_deqEn_rl;
  MOD_Reg<tUInt8> INST_f2d_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_deqP_dummy2_1;
  MOD_Reg<tUInt8> INST_f2d_deqP_dummy2_2;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_f2d_deqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_f2d_deqP_lat_0;
  MOD_Wire<tUInt8> INST_f2d_deqP_lat_1;
  MOD_Wire<tUInt8> INST_f2d_deqP_lat_2;
  MOD_Reg<tUInt8> INST_f2d_deqP_rl;
  MOD_Reg<tUInt8> INST_f2d_enqEn_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_enqEn_dummy2_1;
  MOD_Reg<tUInt8> INST_f2d_enqEn_dummy2_2;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_0_0;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_0_1;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_0_2;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_1_0;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_1_1;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_1_2;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_2_0;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_2_1;
  MOD_Wire<tUInt8> INST_f2d_enqEn_dummy_2_2;
  MOD_Wire<tUInt8> INST_f2d_enqEn_lat_0;
  MOD_Wire<tUInt8> INST_f2d_enqEn_lat_1;
  MOD_Wire<tUInt8> INST_f2d_enqEn_lat_2;
  MOD_Reg<tUInt8> INST_f2d_enqEn_rl;
  MOD_Reg<tUInt8> INST_f2d_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_enqP_dummy2_1;
  MOD_Reg<tUInt8> INST_f2d_enqP_dummy2_2;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_0_2;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_1_2;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_2_0;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_2_1;
  MOD_Wire<tUInt8> INST_f2d_enqP_dummy_2_2;
  MOD_Wire<tUInt8> INST_f2d_enqP_lat_0;
  MOD_Wire<tUInt8> INST_f2d_enqP_lat_1;
  MOD_Wire<tUInt8> INST_f2d_enqP_lat_2;
  MOD_Reg<tUInt8> INST_f2d_enqP_rl;
  MOD_Reg<tUInt8> INST_f2d_tempData_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_tempData_dummy2_1;
  MOD_Wire<tUWide> INST_f2d_tempData_dummy_0_0;
  MOD_Wire<tUWide> INST_f2d_tempData_dummy_0_1;
  MOD_Wire<tUWide> INST_f2d_tempData_dummy_1_0;
  MOD_Wire<tUWide> INST_f2d_tempData_dummy_1_1;
  MOD_Wire<tUWide> INST_f2d_tempData_lat_0;
  MOD_Wire<tUWide> INST_f2d_tempData_lat_1;
  MOD_Reg<tUWide> INST_f2d_tempData_rl;
  MOD_Reg<tUInt8> INST_f2d_tempEnqP_dummy2_0;
  MOD_Reg<tUInt8> INST_f2d_tempEnqP_dummy2_1;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_lat_0;
  MOD_Wire<tUInt8> INST_f2d_tempEnqP_lat_1;
  MOD_Reg<tUInt8> INST_f2d_tempEnqP_rl;
  MOD_Reg<tUInt8> INST_fEpoch;
  MOD_mkIMemory INST_iMem;
  MOD_Reg<tUInt64> INST_pc;
  MOD_mkRFile INST_rf;
  MOD_Reg<tUInt8> INST_stat;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_data_0_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_data_0_rl;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_deqP_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_deqP_rl;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_dummy2_0;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_dummy2_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_0_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_0_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_1_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_dummy_1_1;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_lat_0;
  MOD_Wire<tUInt8> INST_statRedirect_enqP_lat_1;
  MOD_Reg<tUInt8> INST_statRedirect_enqP_rl;
 
 /* Constructor */
 public:
  MOD_mkProc(tSimStateHdl simHdl, char const *name, Module *parent);
 
 /* Symbol init methods */
 private:
  void init_symbols_0();
 
 /* Reset signal definitions */
 private:
  tUInt8 PORT_RST_N;
 
 /* Port definitions */
 public:
  tUWide PORT_cpuToHost;
 
 /* Publicly accessible definitions */
 public:
  tUInt8 DEF_cop_started____d619;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_486_TO_483_106_d2r_ETC___d1109;
  tUInt8 DEF_SEL_ARR_NOT_d2r_data_0_077_BIT_258_111_112_NOT_ETC___d1116;
  tUInt8 DEF_IF_execRedirect_deqEn_dummy2_0_07_AND_execRedi_ETC___d611;
  tUInt8 DEF_d2r_deqEn_dummy2_2__h40789;
  tUInt8 DEF_d2r_enqEn_dummy2_2__h39295;
  tUInt8 DEF_f2d_deqEn_dummy2_2__h26920;
  tUInt8 DEF_f2d_enqEn_dummy2_2__h25426;
  tUInt8 DEF_execRedirect_deqEn_dummy2_2__h11128;
  tUInt8 DEF_execRedirect_enqEn_dummy2_2__h9637;
  tUWide DEF_d2r_data_1___d1079;
  tUWide DEF_d2r_data_0___d1077;
  tUInt8 DEF_upd__h50055;
  tUInt8 DEF_condFlag___d1130;
  tUInt8 DEF_upd__h52657;
  tUInt8 DEF_upd__h55328;
  tUInt8 DEF_upd__h55386;
  tUInt8 DEF_d2r_deqEn_rl__h35227;
  tUInt8 DEF_d2r_enqEn_rl__h33602;
  tUInt8 DEF_d2r_deqP_dummy2_2__h39875;
  tUInt8 DEF_d2r_deqP_dummy2_1__h50110;
  tUInt8 DEF_d2r_deqP_dummy2_0__h50098;
  tUInt8 DEF_f2d_deqEn_rl__h22771;
  tUInt8 DEF_f2d_enqEn_rl__h21146;
  tUInt8 DEF_statRedirect_deqP_dummy2_1__h52777;
  tUInt8 DEF_statRedirect_deqP_dummy2_0__h52764;
  tUInt8 DEF_statRedirect_enqP_dummy2_1__h55354;
  tUInt8 DEF_statRedirect_enqP_dummy2_0__h52583;
  tUInt8 DEF_execRedirect_deqEn_rl__h7062;
  tUInt8 DEF_execRedirect_deqEn_dummy2_1__h43517;
  tUInt8 DEF_execRedirect_deqEn_dummy2_0__h43505;
  tUInt8 DEF_execRedirect_enqEn_rl__h5437;
  tUInt8 DEF_eEpoch__h50380;
  tUInt64 DEF__read_dInst_valP__h50652;
  tUInt64 DEF_x__h51270;
  tUInt64 DEF__read_dInst_valP__h50628;
  tUInt64 DEF_x__h51267;
  tUInt8 DEF_d2r_data_1_079_BITS_479_TO_477___d1121;
  tUInt8 DEF_d2r_data_0_077_BITS_479_TO_477___d1119;
  tUInt8 DEF_condFlag_130_BIT_2___d1132;
  tUInt8 DEF_condFlag_130_BIT_1___d1143;
  tUInt8 DEF_condFlag_130_BIT_0___d1131;
  tUInt8 DEF_x__h50039;
  tUInt64 DEF_SEL_ARR_d2r_data_0_077_BITS_257_TO_194_172_d2r_ETC___d1175;
  tUInt8 DEF_x__h50326;
  tUInt64 DEF_valP__h50422;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1154;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1149;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1142;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1138;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1129;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1124;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BIT_0_078_d2r_data_1_07_ETC___d1089;
  tUInt64 DEF_IF_SEL_ARR_d2r_data_0_077_BITS_486_TO_483_106__ETC___d1190;
  tUInt64 DEF_IF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119__ETC___d1188;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_EQ__ETC___d1187;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_486_TO_483_106_d2r_ETC___d1164;
  tUInt8 DEF_y__h52810;
  tUInt8 DEF_x__h52809;
  tUInt8 DEF_IF_statRedirect_enqP_lat_0_whas__30_THEN_statR_ETC___d133;
  tUInt8 DEF_NOT_SEL_ARR_d2r_data_0_077_BITS_486_TO_483_106_ETC___d1165;
  tUInt8 DEF_NOT_condFlag_130_BIT_0_131_176_AND_condFlag_13_ETC___d1177;
  tUInt8 DEF_condFlag_130_BIT_0_131_OR_NOT_condFlag_130_BIT_ETC___d1134;
  tUInt8 DEF_NOT_condFlag_130_BIT_2_132___d1133;
  tUInt8 DEF_condFlag_130_BIT_1_143_AND_NOT_condFlag_130_BI_ETC___d1178;
  tUInt8 DEF_NOT_condFlag_130_BIT_1_143_144_OR_condFlag_130_ETC___d1145;
  tUInt8 DEF_NOT_condFlag_130_BIT_1_143_144_AND_NOT_condFla_ETC___d1180;
  tUInt8 DEF_condFlag_130_BIT_1_143_OR_condFlag_130_BIT_2_132___d1155;
  tUInt8 DEF_execRedirect_deqEn_dummy2_0_07_AND_execRedirec_ETC___d610;
  tUInt8 DEF_NOT_execRedirect_deqEn_rl_7___d94;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BITS_476_TO_413_168_d2r_ETC___d1191;
  tUInt8 DEF_SEL_ARR_d2r_data_0_077_BIT_0_078_d2r_data_1_07_ETC___d1091;
  tUInt8 DEF_NOT_SEL_ARR_d2r_data_0_077_BITS_479_TO_477_119_ETC___d1162;
  tUInt8 DEF_NOT_condFlag_130_BIT_1_143___d1144;
 
 /* Local definitions */
 private:
  tUInt8 DEF_IF_d2r_tempEnqP_lat_0_whas__82_THEN_d2r_tempEn_ETC___d487;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d355;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d388;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d421;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d454;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d459;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d437;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d442;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d426;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d404;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d409;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d393;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d371;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d376;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d360;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d338;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_NOT_d2r_te_ETC___d343;
  tUInt8 DEF_IF_d2r_tempEnqP_lat_0_whas__82_THEN_NOT_d2r_te_ETC___d492;
  tUInt8 DEF_d2r_deqEn_lat_1_whas____d302;
  tUInt8 DEF_d2r_enqEn_lat_1_whas____d292;
  tUInt8 DEF_IF_f2d_tempEnqP_lat_0_whas__92_THEN_f2d_tempEn_ETC___d197;
  tUInt8 DEF_IF_f2d_tempEnqP_lat_0_whas__92_THEN_NOT_f2d_te_ETC___d202;
  tUInt8 DEF_f2d_deqEn_lat_1_whas____d174;
  tUInt8 DEF_f2d_enqEn_lat_1_whas____d164;
  tUInt8 DEF_IF_execRedirect_tempEnqP_lat_0_whas__1_THEN_NO_ETC___d61;
  tUInt8 DEF_execRedirect_deqEn_lat_1_whas____d33;
  tUInt8 DEF_execRedirect_enqEn_lat_1_whas____d23;
  tUWide DEF_d2r_tempData_rl___d316;
  tUWide DEF_d2r_tempData_lat_1_wget____d311;
  tUWide DEF_d2r_tempData_lat_0_wget____d314;
  tUWide DEF_f2d_tempData_rl___d186;
  tUWide DEF_f2d_tempData_lat_1_wget____d183;
  tUWide DEF_f2d_tempData_lat_0_wget____d185;
  tUWide DEF_f2d_data_1___d813;
  tUWide DEF_f2d_data_0___d811;
  tUWide DEF_iMem_req_pc_24___d625;
  tUInt64 DEF_upd__h12165;
  tUInt64 DEF_upd__h12298;
  tUInt8 DEF_d2r_tempEnqP_rl___d485;
  tUInt8 DEF_d2r_tempEnqP_lat_0_wget____d483;
  tUInt8 DEF_f2d_tempEnqP_rl___d195;
  tUInt8 DEF_f2d_tempEnqP_lat_0_wget____d193;
  tUInt8 DEF_upd__h39914;
  tUInt8 DEF_upd__h39947;
  tUInt8 DEF_upd__h49432;
  tUInt8 DEF_upd__h39631;
  tUInt8 DEF_upd__h39664;
  tUInt8 DEF_upd__h46076;
  tUInt8 DEF_upd__h26045;
  tUInt8 DEF_upd__h26078;
  tUInt8 DEF_upd__h44038;
  tUInt8 DEF_upd__h25762;
  tUInt8 DEF_upd__h25795;
  tUInt8 DEF_execRedirect_tempEnqP_rl___d54;
  tUInt8 DEF_execRedirect_tempEnqP_lat_0_wget____d52;
  tUInt8 DEF_statRedirect_data_0_rl__h13880;
  tUInt8 DEF_upd__h44581;
  tUInt8 DEF_upd__h10256;
  tUInt8 DEF_upd__h10289;
  tUInt8 DEF_upd__h54146;
  tUInt8 DEF_upd__h9973;
  tUInt8 DEF_upd__h10006;
  tUInt8 DEF_d2r_tempEnqP_lat_0_whas____d482;
  tUInt8 DEF_d2r_tempData_lat_0_whas____d313;
  tUInt8 DEF_d2r_deqEn_lat_1_wget____d303;
  tUInt8 DEF_d2r_deqEn_lat_0_whas____d304;
  tUInt8 DEF_d2r_deqEn_lat_0_wget____d305;
  tUInt8 DEF_d2r_enqEn_lat_1_wget____d293;
  tUInt8 DEF_d2r_enqEn_lat_0_whas____d294;
  tUInt8 DEF_d2r_enqEn_lat_0_wget____d295;
  tUInt8 DEF_d2r_enqP_dummy2_2__h39592;
  tUInt8 DEF_f2d_tempEnqP_lat_0_whas____d192;
  tUInt8 DEF_f2d_deqEn_lat_1_wget____d175;
  tUInt8 DEF_f2d_deqEn_lat_0_whas____d176;
  tUInt8 DEF_f2d_deqEn_lat_0_wget____d177;
  tUInt8 DEF_f2d_enqEn_lat_1_wget____d165;
  tUInt8 DEF_f2d_enqEn_lat_0_whas____d166;
  tUInt8 DEF_f2d_enqEn_lat_0_wget____d167;
  tUInt8 DEF_f2d_deqP_dummy2_2__h26006;
  tUInt8 DEF_f2d_enqP_dummy2_2__h25723;
  tUInt8 DEF_execRedirect_tempEnqP_lat_0_whas____d51;
  tUInt8 DEF_execRedirect_deqEn_lat_1_wget____d34;
  tUInt8 DEF_execRedirect_deqEn_lat_0_whas____d35;
  tUInt8 DEF_execRedirect_deqEn_lat_0_wget____d36;
  tUInt8 DEF_execRedirect_enqEn_lat_1_wget____d24;
  tUInt8 DEF_execRedirect_enqEn_lat_0_whas____d25;
  tUInt8 DEF_execRedirect_enqEn_lat_0_wget____d26;
  tUInt8 DEF_execRedirect_deqP_dummy2_2__h10217;
  tUInt8 DEF_execRedirect_enqP_dummy2_2__h9934;
  tUWide DEF_d2r_tempData_rl_16_BITS_128_TO_0___d475;
  tUWide DEF_d2r_tempData_lat_1_wget__11_BITS_128_TO_0___d473;
  tUWide DEF_d2r_tempData_lat_0_wget__14_BITS_128_TO_0___d474;
  tUWide DEF__read_inst__h46563;
  tUWide DEF__read_inst__h46571;
  tUInt64 DEF__read_dInst_valP__h36540;
  tUInt64 DEF_x__h37377;
  tUInt64 DEF_x__h37515;
  tUInt64 DEF_x__h37653;
  tUInt64 DEF_x__h37785;
  tUInt64 DEF_x_wget_dInst_valP__h36516;
  tUInt64 DEF_x__h37374;
  tUInt64 DEF_x__h37512;
  tUInt64 DEF_x__h37650;
  tUInt64 DEF_x__h37782;
  tUWide DEF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2d_d_ETC___d818;
  tUInt8 DEF_x__h39027;
  tUInt8 DEF_x__h39026;
  tUInt8 DEF_x__h25158;
  tUInt8 DEF_x__h25157;
  tUInt8 DEF_x__h9369;
  tUInt8 DEF_x__h9368;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_412___d337;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_406___d354;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_400___d370;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_394___d387;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_388___d403;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_323___d420;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_258___d436;
  tUInt8 DEF_d2r_tempData_rl_16_BIT_193___d453;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_412___d336;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_406___d353;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_400___d369;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_394___d386;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_388___d402;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_323___d419;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_258___d435;
  tUInt8 DEF_d2r_tempData_lat_0_wget__14_BIT_193___d452;
  tUInt8 DEF_d2r_tempEnqP_rl_85_BIT_3___d486;
  tUInt8 DEF_d2r_tempEnqP_lat_0_wget__83_BIT_3___d484;
  tUInt8 DEF_f2d_tempEnqP_rl_95_BIT_3___d196;
  tUInt8 DEF_f2d_tempEnqP_lat_0_wget__93_BIT_3___d194;
  tUInt8 DEF_execRedirect_tempEnqP_rl_4_BIT_2___d55;
  tUInt8 DEF_execRedirect_tempEnqP_lat_0_wget__2_BIT_2___d53;
  tUWide DEF_IF_f2d_tempData_dummy2_1_60_THEN_IF_f2d_tempDa_ETC___d261;
  tUWide DEF_IF_f2d_tempData_lat_0_whas__84_THEN_f2d_tempDa_ETC___d187;
  tUWide DEF_IF_f2d_tempData_lat_1_whas__82_THEN_f2d_tempDa_ETC___d188;
  tUWide DEF_IF_d2r_tempData_dummy2_1_50_THEN_IF_d2r_tempDa_ETC___d598;
  tUWide DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d476;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d477;
  tUInt64 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d464;
  tUInt64 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d447;
  tUInt64 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d431;
  tUInt64 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d333;
  tUInt64 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d414;
  tUInt64 DEF_IF_execRedirect_tempData_lat_0_whas__3_THEN_ex_ETC___d46;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d398;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d381;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d348;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d365;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d318;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d323;
  tUInt8 DEF_IF_d2r_tempData_lat_0_whas__13_THEN_d2r_tempDa_ETC___d328;
  tUInt8 DEF_IF_d2r_tempEnqP_lat_0_whas__82_THEN_d2r_tempEn_ETC___d497;
  tUInt8 DEF_IF_d2r_deqP_lat_1_whas__82_THEN_d2r_deqP_lat_1_ETC___d288;
  tUInt8 DEF_IF_d2r_enqP_lat_1_whas__72_THEN_d2r_enqP_lat_1_ETC___d278;
  tUInt8 DEF_IF_f2d_tempEnqP_lat_0_whas__92_THEN_f2d_tempEn_ETC___d207;
  tUInt8 DEF_IF_f2d_deqP_lat_1_whas__54_THEN_f2d_deqP_lat_1_ETC___d160;
  tUInt8 DEF_IF_f2d_enqP_lat_1_whas__44_THEN_f2d_enqP_lat_1_ETC___d150;
  tUInt8 DEF_IF_statRedirect_data_0_lat_0_whas__23_THEN_sta_ETC___d126;
  tUInt8 DEF_IF_execRedirect_tempEnqP_lat_0_whas__1_THEN_ex_ETC___d66;
  tUInt8 DEF_IF_execRedirect_deqP_lat_1_whas__3_THEN_execRe_ETC___d19;
  tUInt8 DEF_IF_execRedirect_enqP_lat_1_whas_THEN_execRedir_ETC___d9;
  tUInt8 DEF_IF_execRedirect_tempEnqP_lat_0_whas__1_THEN_ex_ETC___d56;
  tUWide DEF_IF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2_ETC___d1061;
  tUWide DEF_IF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2_ETC___d1051;
  tUWide DEF_SEL_ARR_f2d_data_0_11_BITS_64_TO_1_052_f2d_dat_ETC___d1060;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d478;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d472;
  tUWide DEF_IF_d2r_tempData_dummy2_1_50_THEN_IF_d2r_tempDa_ETC___d599;
  tUWide DEF_IF_d2r_tempData_dummy2_1_50_THEN_IF_d2r_tempDa_ETC___d597;
  tUWide DEF_IF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2_ETC___d1050;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d471;
  tUWide DEF_IF_d2r_tempData_dummy2_1_50_THEN_IF_d2r_tempDa_ETC___d596;
  tUWide DEF_IF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2_ETC___d1049;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d470;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d595;
  tUWide DEF_IF_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f2_ETC___d1048;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d469;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d594;
  tUWide DEF_DONTCARE_CONCAT_NOT_SEL_ARR_f2d_data_0_11_BITS_ETC___d1047;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d417;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d468;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d578;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d593;
  tUWide DEF_iMem_req_pc_24_25_CONCAT_pc_24_CONCAT_pc_24_PL_ETC___d658;
  tUWide DEF_pc_24_PLUS_IF_iMem_req_pc_24_25_BITS_79_TO_76__ETC___d657;
  tUWide DEF_NOT_SEL_ARR_f2d_data_0_11_BITS_208_TO_129_12_f_ETC___d1046;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d450;
  tUWide DEF_IF_d2r_tempData_lat_1_whas__10_THEN_d2r_tempDa_ETC___d467;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d587;
  tUWide DEF_NOT_d2r_tempData_dummy2_1_50_55_OR_IF_d2r_temp_ETC___d592;
  tUWide DEF_NOT_SEL_ARR_d2r_data_0_077_BITS_486_TO_483_106_ETC___d1330;
  tUInt8 DEF__0_CONCAT_DONTCARE___d264;
 
 /* Rules */
 public:
  void RL_execRedirect_enqP_canon();
  void RL_execRedirect_deqP_canon();
  void RL_execRedirect_enqEn_canon();
  void RL_execRedirect_deqEn_canon();
  void RL_execRedirect_tempData_canon();
  void RL_execRedirect_tempEnqP_canon();
  void RL_execRedirect_canonicalize();
  void RL_statRedirect_data_0_canon();
  void RL_statRedirect_enqP_canon();
  void RL_statRedirect_deqP_canon();
  void RL_f2d_enqP_canon();
  void RL_f2d_deqP_canon();
  void RL_f2d_enqEn_canon();
  void RL_f2d_deqEn_canon();
  void RL_f2d_tempData_canon();
  void RL_f2d_tempEnqP_canon();
  void RL_f2d_canonicalize();
  void RL_d2r_enqP_canon();
  void RL_d2r_deqP_canon();
  void RL_d2r_enqEn_canon();
  void RL_d2r_deqEn_canon();
  void RL_d2r_tempData_canon();
  void RL_d2r_tempEnqP_canon();
  void RL_d2r_canonicalize();
  void RL_doFetch();
  void RL_doDecode();
  void RL_doRest();
  void RL_upd_Stat();
  void RL_statHLT();
  void RL_statINS();
 
 /* Methods */
 public:
  tUWide METH_cpuToHost();
  tUInt8 METH_RDY_cpuToHost();
  void METH_hostToCpu(tUInt64 ARG_hostToCpu_startpc);
  tUInt8 METH_RDY_hostToCpu();
 
 /* Reset routines */
 public:
  void reset_RST_N(tUInt8 ARG_rst_in);
 
 /* Static handles to reset routines */
 public:
 
 /* Pointers to reset fns in parent module for asserting output resets */
 private:
 
 /* Functions for the parent module to register its reset fns */
 public:
 
 /* Functions to set the elaborated clock id */
 public:
  void set_clk_0(char const *s);
 
 /* State dumping routine */
 public:
  void dump_state(unsigned int indent);
 
 /* VCD dumping routines */
 public:
  unsigned int dump_VCD_defs(unsigned int levels);
  void dump_VCD(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
  void vcd_defs(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_prims(tVCDDumpType dt, MOD_mkProc &backing);
  void vcd_submodules(tVCDDumpType dt, unsigned int levels, MOD_mkProc &backing);
};

#endif /* ifndef __mkProc_h__ */