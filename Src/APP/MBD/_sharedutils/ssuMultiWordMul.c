/*
 * File: ssuMultiWordMul.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "ssuMultiWordMul.h"

void ssuMultiWordMul(const uint32_T u1[], int32_T n1, const uint32_T u2[],
                     int32_T n2, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T j;
  int32_T k;
  int32_T nj;
  uint32_T u1i;
  uint32_T yk;
  uint32_T a1;
  uint32_T a0;
  uint32_T b1;
  uint32_T w10;
  uint32_T w01;
  uint32_T cb;
  boolean_T isNegative1;
  uint32_T cb1;
  isNegative1 = ((u1[n1 - 1] & 2147483648U) != 0U);
  cb1 = 1U;

  /* Initialize output to zero */
  for (k = 0; k < n; k++) {
    y[k] = 0U;
  }

  for (i = 0; i < n1; i++) {
    cb = 0U;
    u1i = u1[i];
    if (isNegative1) {
      u1i = (~u1i) + cb1;
      cb1 = (uint32_T)((u1i < cb1) ? 1 : 0);
    }

    a1 = (u1i >> 16U);
    a0 = u1i & 65535U;
    k = n - i;
    nj = (n2 <= k) ? n2 : k;
    k = i;
    for (j = 0; j < nj; j++) {
      yk = y[k];
      u1i = u2[j];
      b1 = (u1i >> 16U);
      u1i &= 65535U;
      w10 = a1 * u1i;
      w01 = a0 * b1;
      yk += cb;
      cb = (uint32_T)((yk < cb) ? 1 : 0);
      u1i *= a0;
      yk += u1i;
      cb += (uint32_T)((yk < u1i) ? 1 : 0);
      u1i = (w10 << 16U);
      yk += u1i;
      cb += (uint32_T)((yk < u1i) ? 1 : 0);
      u1i = (w01 << 16U);
      yk += u1i;
      cb += (uint32_T)((yk < u1i) ? 1 : 0);
      y[k] = yk;
      cb += (w10 >> 16U);
      cb += (w01 >> 16U);
      cb += a1 * b1;
      k++;
    }

    if (k < n) {
      y[k] = cb;
    }
  }

  /* Apply sign */
  if (isNegative1) {
    cb = 1U;
    for (k = 0; k < n; k++) {
      yk = (~y[k]) + cb;
      y[k] = yk;
      cb = (uint32_T)((yk < cb) ? 1 : 0);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
