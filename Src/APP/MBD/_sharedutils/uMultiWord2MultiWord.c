/*
 * File: uMultiWord2MultiWord.c
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 */

#include "rtwtypes.h"
#include "uMultiWord2MultiWord.h"

void uMultiWord2MultiWord(const uint32_T u1[], int32_T n1, uint32_T y[], int32_T
  n)
{
  int32_T nm;
  int32_T i;
  nm = (n1 < n) ? n1 : n;
  for (i = 0; i < nm; i++) {
    y[i] = u1[i];
  }

  if (n > n1) {
    for (i = nm; i < n; i++) {
      y[i] = 0U;
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
