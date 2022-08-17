/*
 * File: eph2satpos_mdl_types.h
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

#ifndef RTW_HEADER_eph2satpos_mdl_types_h_
#define RTW_HEADER_eph2satpos_mdl_types_h_
#include "rtwtypes.h"

/* Model Code Variants */
#ifndef DEFINED_TYPEDEF_FOR_mybus_
#define DEFINED_TYPEDEF_FOR_mybus_

typedef struct {
  real_T toc_;
  real_T af0;
  real_T af1;
  real_T af2;
  real_T Crs;
  real_T deltan;
  real_T Mo;
  real_T Cuc;
  real_T e;
  real_T Cus;
  real_T a;
  real_T toe;
  real_T Cic;
  real_T omega0;
  real_T Cis;
  real_T io;
  real_T Crc;
  real_T w;
  real_T omegaD;
  real_T didt;
  real_T tGd;
} mybus;

#endif

/* Forward declaration for rtModel */
typedef struct tag_RTM_eph2satpos_mdl_T RT_MODEL_eph2satpos_mdl_T;

#endif                                 /* RTW_HEADER_eph2satpos_mdl_types_h_ */

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
