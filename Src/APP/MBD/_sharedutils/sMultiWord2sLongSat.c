/*
 * File: sMultiWord2sLongSat.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2sMultiWordSat.h"
#include "sMultiWord2sLongSat.h"

int32_T sMultiWord2sLongSat(const uint32_T u1[], int32_T n1)
{
  uint32_T y;
  sMultiWord2sMultiWordSat(u1, n1, &y, 1);
  return (int32_T)y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
