/*
 * File: eph2satpos_mdl.c
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

#include "eph2satpos_mdl.h"
#include "eph2satpos_Function.h"
#include "eph2satpos_mdl_types.h"
#include "rtwtypes.h"
#include <string.h>
#include "rt_nonfinite.h"

const mybus eph2satpos_mdl_rtZmybus = { 0.0,/* toc_ */
  0.0,                                 /* af0 */
  0.0,                                 /* af1 */
  0.0,                                 /* af2 */
  0.0,                                 /* Crs */
  0.0,                                 /* deltan */
  0.0,                                 /* Mo */
  0.0,                                 /* Cuc */
  0.0,                                 /* e */
  0.0,                                 /* Cus */
  0.0,                                 /* a */
  0.0,                                 /* toe */
  0.0,                                 /* Cic */
  0.0,                                 /* omega0 */
  0.0,                                 /* Cis */
  0.0,                                 /* io */
  0.0,                                 /* Crc */
  0.0,                                 /* w */
  0.0,                                 /* omegaD */
  0.0,                                 /* didt */
  0.0                                  /* tGd */
};

/* Model step function */
void eph2satpos_mdl_step(RT_MODEL_eph2satpos_mdl_T *const eph2satpos_mdl_M,
  mybus *eph2satpos_mdl_U_In1, real_T eph2satpos_mdl_Y_SV_ecef[3])
{
  /* Outputs for Atomic SubSystem: '<Root>/Subsystem1' */

  /* Outport: '<Root>/SV_ecef' incorporates:
   *  Inport: '<Root>/In1'
   */
  eph2satpos_Function(eph2satpos_mdl_U_In1, eph2satpos_mdl_Y_SV_ecef);

  /* End of Outputs for SubSystem: '<Root>/Subsystem1' */
  UNUSED_PARAMETER(eph2satpos_mdl_M);
}

/* Model initialize function */
void eph2satpos_mdl_initialize(RT_MODEL_eph2satpos_mdl_T *const eph2satpos_mdl_M,
  mybus *eph2satpos_mdl_U_In1, real_T eph2satpos_mdl_Y_SV_ecef[3])
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* external inputs */
  *eph2satpos_mdl_U_In1 = eph2satpos_mdl_rtZmybus;

  /* external outputs */
  (void)memset(&eph2satpos_mdl_Y_SV_ecef[0], 0, 3U * sizeof(real_T));
  UNUSED_PARAMETER(eph2satpos_mdl_M);
}

/* Model terminate function */
void eph2satpos_mdl_terminate(RT_MODEL_eph2satpos_mdl_T *const eph2satpos_mdl_M)
{
  /* (no terminate code required) */
  UNUSED_PARAMETER(eph2satpos_mdl_M);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
