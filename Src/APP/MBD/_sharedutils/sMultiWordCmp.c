/*
 * File: sMultiWordCmp.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWordCmp.h"

int32_T sMultiWordCmp(const uint32_T u1[], const uint32_T u2[], int32_T n)
{
  int32_T y;
  uint32_T su1;
  uint32_T su2;
  int32_T i;
  su1 = u1[n - 1] & 2147483648U;
  su2 = u2[n - 1] & 2147483648U;
  if ((su1 ^ su2) != 0U) {
    y = (su1 != 0U) ? -1 : 1;
  } else {
    y = 0;
    i = n;
    while ((y == 0) && (i > 0)) {
      i--;
      su1 = u1[i];
      su2 = u2[i];
      if (su1 != su2) {
        y = (su1 > su2) ? 1 : -1;
      }
    }
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
