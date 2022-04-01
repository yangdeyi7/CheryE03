/*
 * File: sMultiWord2MultiWord.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2MultiWord.h"

void sMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  uint32_T u1i;
  int32_T nm;
  int32_T i;
  nm = (n1 < n) ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    u1i = ((u1[n1 - 1] & 2147483648U) != 0U) ? MAX_uint32_T : 0U;
    for (i = nm; i < n; i++) {
      y[i] = u1i;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
