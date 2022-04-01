/*
 * File: div_nzp_u32_near.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "div_nzp_u32_near.h"

uint32_T div_nzp_u32_near(uint32_T numerator, uint32_T denominator)
{
  uint32_T quotient;
  quotient = numerator / denominator;
  numerator %= denominator;
  if ((numerator > 2147483647U) || ((numerator << 1U) >= denominator)) {
    quotient++;
  }

  return quotient;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
