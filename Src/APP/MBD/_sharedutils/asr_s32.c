/*
 * File: asr_s32.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"

int32_T asr_s32(int32_T u, uint32_T n)
{
  int32_T y;
  if (u >= 0) {
    y = (int32_T)((uint32_T)(((uint32_T)u) >> n));
  } else {
    y = (-((int32_T)((uint32_T)(((uint32_T)((int32_T)(-1 - u))) >> n)))) - 1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
