/*
 * File: eph2satpos_Function.c
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

#include "eph2satpos_mdl_types.h"
#include "rtwtypes.h"
#include "eph2satpos_Function.h"
#include "rt_powd_snf.h"
#include <math.h>
#include "rt_atan2d_snf.h"

/* Output and update for atomic system: '<Root>/Subsystem1' */

/* Const memory section */
void eph2satpos_Function(const mybus *rtu_In1, real_T rty_SV_ecef[3])
{
  real_T E_temp[19];
  real_T Ek[19];
  real_T rtb_Sum_n;
  real_T rtb_phi_k;
  int32_T ii;

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* Sum: '<S3>/Sum' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S1>/Constant6'
   *  Constant: '<S3>/Constant'
   *  Math: '<S3>/Power'
   *  Product: '<S3>/Divide'
   *  Product: '<S3>/Product'
   *  Sqrt: '<S3>/Sqrt'
   *  Sum: '<S3>/Subtract'
   *  Sum: '<S3>/Sum1'
   */
  rtb_Sum_n = (sqrt(3.986005E+14 / rt_powd_snf(rtu_In1->a, 3.0)) +
               rtu_In1->deltan) * (511218.0 - rtu_In1->toe) + rtu_In1->Mo;

  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* MATLAB Function: '<S1>/MATLAB Function1' incorporates:
   *  Constant: '<S1>/Constant5'
   */
  for (ii = 0; ii < 19; ii++) {
    E_temp[ii] = 0.0;
    Ek[ii] = 0.0;
    if (ii + 1 == 1) {
      E_temp[0] = rtb_Sum_n;
    } else {
      E_temp[ii] = Ek[ii - 1];
    }

    rtb_phi_k = rtu_In1->e * sin(E_temp[ii]) + rtb_Sum_n;
    Ek[ii] = (rtb_phi_k - E_temp[ii]) * 0.1 + rtb_phi_k;
  }

  real_T rtb_Cos;
  real_T rtb_Product3;
  real_T rtb_Sum;
  real_T rtb_rk;

  /* Outputs for Atomic SubSystem: '<S4>/Subsystem2' */
  /* Outputs for Atomic SubSystem: '<S4>/Subsystem1' */
  /* MATLAB Function: '<S10>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   */
  rtb_phi_k = cos(Ek[18]);

  /* MATLAB Function: '<S11>/MATLAB Function' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   */
  rtb_Sum_n = 1.0 - rtu_In1->e * rtb_phi_k;

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem5' */
  /* Outputs for Atomic SubSystem: '<S4>/Subsystem3' */
  /* MATLAB Function: '<S5>/MATLAB phi_k Function' incorporates:
   *  MATLAB Function: '<S10>/MATLAB Function'
   *  MATLAB Function: '<S11>/MATLAB Function'
   *  MATLAB Function: '<S1>/MATLAB Function1'
   *  Trigonometry: '<S12>/Atan2'
   */
  rtb_phi_k = rt_atan2d_snf(sqrt(1.0 - rtu_In1->e * rtu_In1->e) * sin(Ek[18]) /
    rtb_Sum_n, (rtb_phi_k - rtu_In1->e) / rtb_Sum_n) + rtu_In1->w;

  /* End of Outputs for SubSystem: '<S4>/Subsystem3' */
  /* End of Outputs for SubSystem: '<S4>/Subsystem1' */
  /* End of Outputs for SubSystem: '<S4>/Subsystem2' */

  /* MATLAB Function: '<S5>/MATLAB dphi_k Function' incorporates:
   *  MATLAB Function: '<S5>/MATLAB di_k Function'
   *  MATLAB Function: '<S5>/MATLAB dr_k Function'
   */
  rtb_Sum = sin(2.0 * rtb_phi_k);
  rtb_Cos = cos(2.0 * rtb_phi_k);

  /* MATLAB Function: '<S5>/MATLAB uk Function' incorporates:
   *  MATLAB Function: '<S5>/MATLAB dphi_k Function'
   */
  rtb_phi_k += rtu_In1->Cus * rtb_Sum + rtu_In1->Cuc * rtb_Cos;

  /* Outputs for Atomic SubSystem: '<S4>/Subsystem4' */
  /* Outputs for Atomic SubSystem: '<S4>/Subsystem2' */
  /* MATLAB Function: '<S13>/MATLAB rk Function' incorporates:
   *  MATLAB Function: '<S11>/MATLAB Function'
   *  MATLAB Function: '<S5>/MATLAB dr_k Function'
   */
  rtb_rk = (rtu_In1->Crs * rtb_Sum + rtu_In1->Crc * rtb_Cos) + rtb_Sum_n *
    rtu_In1->a;

  /* End of Outputs for SubSystem: '<S4>/Subsystem2' */
  /* End of Outputs for SubSystem: '<S4>/Subsystem4' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem5' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem6' */
  /* MATLAB Function: '<S6>/MATLAB xk_prime Function' */
  rtb_Sum_n = rtb_rk * cos(rtb_phi_k);

  /* MATLAB Function: '<S6>/MATLAB yk_prime Function' */
  rtb_phi_k = rtb_rk * sin(rtb_phi_k);

  /* End of Outputs for SubSystem: '<S1>/Subsystem6' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem7' */
  /* Outputs for Atomic SubSystem: '<S1>/Subsystem' */
  /* Outputs for Atomic SubSystem: '<S1>/Subsystem5' */
  /* Sum: '<S7>/Sum' incorporates:
   *  Constant: '<S1>/Constant6'
   *  MATLAB Function: '<S5>/MATLAB di_k Function'
   *  Product: '<S7>/Product'
   *  Sum: '<S3>/Subtract'
   *  Sum: '<S7>/Sum2'
   */
  rtb_Sum = ((511218.0 - rtu_In1->toe) * rtu_In1->didt + rtu_In1->io) +
    (rtu_In1->Cis * rtb_Sum + rtu_In1->Cic * rtb_Cos);

  /* End of Outputs for SubSystem: '<S1>/Subsystem5' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem7' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem9' */
  /* Sum: '<S9>/Subtract1' incorporates:
   *  Constant: '<S1>/Constant'
   *  Constant: '<S1>/Constant6'
   *  Product: '<S9>/Product'
   *  Product: '<S9>/Product1'
   *  Sum: '<S3>/Subtract'
   *  Sum: '<S9>/Subtract'
   *  Sum: '<S9>/Sum'
   */
  rtb_rk = ((rtu_In1->omegaD - 7.2921151467E-5) * (511218.0 - rtu_In1->toe) +
            rtu_In1->omega0) - 7.2921151467E-5 * rtu_In1->toe;

  /* End of Outputs for SubSystem: '<S1>/Subsystem9' */
  /* End of Outputs for SubSystem: '<S1>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S1>/Subsystem8' */
  /* Trigonometry: '<S8>/Cos' */
  rtb_Cos = cos(rtb_rk);

  /* Trigonometry: '<S8>/Sin' */
  rtb_rk = sin(rtb_rk);

  /* Product: '<S8>/Product3' incorporates:
   *  Trigonometry: '<S8>/Cos1'
   */
  rtb_Product3 = rtb_phi_k * cos(rtb_Sum);

  /* Sum: '<S8>/Subtract' incorporates:
   *  Product: '<S8>/Product1'
   *  Product: '<S8>/Product5'
   */
  rty_SV_ecef[0] = rtb_Sum_n * rtb_Cos - rtb_rk * rtb_Product3;

  /* Sum: '<S8>/Sum' incorporates:
   *  Product: '<S8>/Product2'
   *  Product: '<S8>/Product6'
   */
  rty_SV_ecef[1] = rtb_rk * rtb_Sum_n + rtb_Product3 * rtb_Cos;

  /* Product: '<S8>/Product4' incorporates:
   *  Trigonometry: '<S8>/Sin1'
   */
  rty_SV_ecef[2] = sin(rtb_Sum) * rtb_phi_k;

  /* End of Outputs for SubSystem: '<S1>/Subsystem8' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
