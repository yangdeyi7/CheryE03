/*
 * File: uMultiWordInc.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "uMultiWordInc.h"

void uMultiWordInc(uint32_T y[], int32_T n)
{
  uint32_T yi;
  uint32_T carry = 1U;
  int32_T i;
  for (i = 0; i < n; i++) {
    yi = y[i] + carry;
    y[i] = yi;
    carry = (uint32_T)((yi < carry) ? 1 : 0);
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
