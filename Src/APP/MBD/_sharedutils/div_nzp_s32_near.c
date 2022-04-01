/*
 * File: div_nzp_s32_near.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "div_nzp_s32_near.h"

int32_T div_nzp_s32_near(int32_T numerator, int32_T denominator)
{
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  boolean_T quotientNeedsNegation;
  absNumerator = (numerator < 0) ? ((~((uint32_T)numerator)) + 1U) : ((uint32_T)
    numerator);
  absDenominator = (denominator < 0) ? ((~((uint32_T)denominator)) + 1U) :
    ((uint32_T)denominator);
  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  absNumerator %= absDenominator;
  absNumerator <<= 1U;
  if ((absNumerator >= absDenominator) && ((!quotientNeedsNegation) ||
       (absNumerator > absDenominator))) {
    tempAbsQuotient++;
  }

  return quotientNeedsNegation ? (-((int32_T)tempAbsQuotient)) : ((int32_T)
    tempAbsQuotient);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
