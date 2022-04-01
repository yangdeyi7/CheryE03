/*
 * File: sLong2MultiWord.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sLong2MultiWord.h"

void sLong2MultiWord(int32_T u, uint32_T y[], int32_T n)
{
  uint32_T yi;
  int32_T i;
  y[0] = (uint32_T)u;
  yi = (u < 0) ? MAX_uint32_T : 0U;
  for (i = 1; i < n; i++) {
    y[i] = yi;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
