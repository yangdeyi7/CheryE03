/*
 * File: Double2MultiWord.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include <math.h>
#include "Double2MultiWord.h"

void Double2MultiWord(real_T u1, uint32_T y[], int32_T n)
{
  int32_T i;
  int32_T currExp;
  int32_T prevExp;
  int32_T msl;
  real_T yn;
  real_T yd;
  boolean_T isNegative;
  uint32_T u1i;
  uint32_T cb;
  isNegative = (u1 < 0.0);
  yn = frexp(u1, &currExp);
  msl = (currExp <= 0) ? -1 : ((currExp - 1) / 32);
  cb = 1U;
  for (i = msl + 1; i < n; i++) {
    y[i] = 0U;
  }

  yn = isNegative ? (-yn) : yn;
  prevExp = 32 * msl;
  for (i = msl; i >= 0; i--) {
    yn = ldexp(yn, currExp - prevExp);
    yd = floor(yn);
    yn -= yd;
    if (i < n) {
      y[i] = (uint32_T)yd;
    }

    currExp = prevExp;
    prevExp -= 32;
  }

  if (isNegative) {
    for (i = 0; i < n; i++) {
      u1i = ~y[i];
      cb += u1i;
      y[i] = cb;
      cb = (uint32_T)((cb < u1i) ? 1 : 0);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
