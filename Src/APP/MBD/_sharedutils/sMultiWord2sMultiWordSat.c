/*
 * File: sMultiWord2sMultiWordSat.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2sMultiWordSat.h"

void sMultiWord2sMultiWordSat(const uint32_T u1[], int32_T n1, uint32_T y[],
  int32_T n)
{
  int32_T nm1;
  uint32_T ys;
  int32_T n1m1;
  boolean_T doSaturation = false;
  nm1 = n - 1;
  n1m1 = n1 - 1;
  ys = ((u1[n1m1] & 2147483648U) != 0U) ? MAX_uint32_T : 0U;
  if (n1 > n) {
    doSaturation = (((u1[n1m1] ^ u1[nm1]) & 2147483648U) != 0U);
    while ((!doSaturation) && (n1m1 >= n)) {
      doSaturation = (u1[n1m1] != ys);
      n1m1--;
    }
  }

  if (doSaturation) {
    ys = ~ys;
    for (n1m1 = 0; n1m1 < nm1; n1m1++) {
      y[n1m1] = ys;
    }

    y[n1m1] = ys ^ 2147483648U;
  } else {
    nm1 = (n1 < n) ? n1 : n;
    for (n1m1 = 0; n1m1 < nm1; n1m1++) {
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
