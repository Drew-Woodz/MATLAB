/*
 * File: eph2satpos_mdl.h
 *
 * Code generated for Simulink model 'eph2satpos_mdl'.
 *
 * Model version                  : 1.98
 * Simulink Coder version         : 9.7 (R2022a) 13-Nov-2021
 * C/C++ source code generated on : Tue Jul 26 18:31:04 2022
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Intel->x86-64 (Windows64)
 * Code generation objective: Execution efficiency
 * Validation result: Not run
 */

#ifndef RTW_HEADER_eph2satpos_mdl_h_
#define RTW_HEADER_eph2satpos_mdl_h_
#ifndef eph2satpos_mdl_COMMON_INCLUDES_
#define eph2satpos_mdl_COMMON_INCLUDES_
#include "rtwtypes.h"
#endif                                 /* eph2satpos_mdl_COMMON_INCLUDES_ */

#include "eph2satpos_mdl_types.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"

/* Real-time Model Data Structure */
struct tag_RTM_eph2satpos_mdl_T {
  char_T rt_unused;
};

/* External data declarations for dependent source files */
extern const mybus eph2satpos_mdl_rtZmybus;/* mybus ground */

/* Model entry point functions */
extern void eph2satpos_mdl_initialize(RT_MODEL_eph2satpos_mdl_T *const
  eph2satpos_mdl_M, mybus *eph2satpos_mdl_U_In1, real_T
  eph2satpos_mdl_Y_SV_ecef[3]);
extern void eph2satpos_mdl_step(RT_MODEL_eph2satpos_mdl_T *const
  eph2satpos_mdl_M, mybus *eph2satpos_mdl_U_In1, real_T
  eph2satpos_mdl_Y_SV_ecef[3]);
extern void eph2satpos_mdl_terminate(RT_MODEL_eph2satpos_mdl_T *const
  eph2satpos_mdl_M);

/*-
 * These blocks were eliminated from the model due to optimizations:
 *
 * Block '<S8>/Display' : Unused code path elimination
 */

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'eph2satpos_mdl'
 * '<S1>'   : 'eph2satpos_mdl/Subsystem1'
 * '<S2>'   : 'eph2satpos_mdl/Subsystem1/MATLAB Function1'
 * '<S3>'   : 'eph2satpos_mdl/Subsystem1/Subsystem'
 * '<S4>'   : 'eph2satpos_mdl/Subsystem1/Subsystem10'
 * '<S5>'   : 'eph2satpos_mdl/Subsystem1/Subsystem5'
 * '<S6>'   : 'eph2satpos_mdl/Subsystem1/Subsystem6'
 * '<S7>'   : 'eph2satpos_mdl/Subsystem1/Subsystem7'
 * '<S8>'   : 'eph2satpos_mdl/Subsystem1/Subsystem8'
 * '<S9>'   : 'eph2satpos_mdl/Subsystem1/Subsystem9'
 * '<S10>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem1'
 * '<S11>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem2'
 * '<S12>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem3'
 * '<S13>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem4'
 * '<S14>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem1/MATLAB Function'
 * '<S15>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem2/MATLAB Function'
 * '<S16>'  : 'eph2satpos_mdl/Subsystem1/Subsystem10/Subsystem4/MATLAB rk Function'
 * '<S17>'  : 'eph2satpos_mdl/Subsystem1/Subsystem5/MATLAB di_k Function'
 * '<S18>'  : 'eph2satpos_mdl/Subsystem1/Subsystem5/MATLAB dphi_k Function'
 * '<S19>'  : 'eph2satpos_mdl/Subsystem1/Subsystem5/MATLAB dr_k Function'
 * '<S20>'  : 'eph2satpos_mdl/Subsystem1/Subsystem5/MATLAB phi_k Function'
 * '<S21>'  : 'eph2satpos_mdl/Subsystem1/Subsystem5/MATLAB uk Function'
 * '<S22>'  : 'eph2satpos_mdl/Subsystem1/Subsystem6/MATLAB xk_prime Function'
 * '<S23>'  : 'eph2satpos_mdl/Subsystem1/Subsystem6/MATLAB yk_prime Function'
 */
#endif                                 /* RTW_HEADER_eph2satpos_mdl_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
