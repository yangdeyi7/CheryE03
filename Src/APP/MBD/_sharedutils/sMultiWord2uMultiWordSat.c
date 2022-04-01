/*
 * File: sMultiWord2uMultiWordSat.c
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2uMultiWordSat.h"

void sMultiWord2uMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  uint32_T ys;
  int32_T n1m1;
  boolean_T doSaturation;
  int32_T nc;
  n1m1 = n1 - 1;
  ys = ((u1[n1m1] & 2147483648U) != 0U) ? MAX_uint32_T : 0U;
  doSaturation = (ys != 0U);
  while ((!doSaturation) && (n1m1 >= n)) {
    doSaturation = (u1[n1m1] != 0U);
    n1m1--;
  }

  if (doSaturation) {
    ys = ~ys;
    for (n1m1 = 0; n1m1 < n; n1m1++) {
      y[n1m1] = ys;
    }
  } else {
    nc = (n1 < n) ? n1 : n;
    for (n1m1 = 0; n1m1 < nc; n1m1++) {
      y[n1m1] = u1[n1m1];
    }

    while (n1m1 < n) {
      y[n1m1] = ys;
      n1m1++;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
