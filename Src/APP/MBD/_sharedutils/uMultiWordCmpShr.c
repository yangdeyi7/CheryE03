/*
 * File: uMultiWordCmpShr.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "uMultiWordCmpShr.h"

int32_T uMultiWordCmpShr(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T u1i;
  uint32_T u2i;
  uint32_T y1i;
  int32_T i;
  u2i = 0U;
  y = 0;
  i = n;
  while ((y == 0) && (i > 0)) {
    i--;
    u1i = u1[i];
    y1i = (u2i << 31U);
    u2i = u2[i];
    y1i |= (u2i >> 1U);
    if (u1i != y1i) {
      y = (u1i > y1i) ? 1 : -1;
    }
  }

  if ((y == 0) && ((u2i & 1U) == 1U)) {
    y = -1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
