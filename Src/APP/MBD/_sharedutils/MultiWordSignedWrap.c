/*
 * File: MultiWordSignedWrap.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "MultiWordSignedWrap.h"

void MultiWordSignedWrap(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T
  y[])
{
  int32_T n1m1;
  int32_T i;
  uint32_T mask;
  uint32_T ys;
  n1m1 = n1 - 1;
  for (i = 0; i < n1m1; i++) {
    y[i] = u1[i];
  }

  mask = (1U << (31U - n2));
  ys = ((u1[n1m1] & mask) != 0U) ? MAX_uint32_T : 0U;
  mask = (mask << 1U) - 1U;
  y[n1m1] = (u1[n1m1] & mask) | ((~mask) & ys);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
