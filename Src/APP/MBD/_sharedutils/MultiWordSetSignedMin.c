/*
 * File: MultiWordSetSignedMin.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "MultiWordSetSignedMin.h"

void MultiWordSetSignedMin(uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T n1;
  n1 = n - 1;
  for (i = 0; i < n1; i++) {
    y[i] = 0U;
  }

  y[n1] = 2147483648U;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
