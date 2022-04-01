/*
 * File: sMultiWord2uLongSat.c
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 */

#include "rtwtypes.h"
#include "sMultiWord2uMultiWordSat.h"
#include "sMultiWord2uLongSat.h"

uint32_T sMultiWord2uLongSat(const uint32_T u1[], int32_T n1)
{
  uint32_T ret;
  sMultiWord2uMultiWordSat(u1, n1, &ret, 1);
  return ret;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
