/*
 * File: look1_iu8lu32n24tu16Ds32Iu8_binlcs.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "asr_s32.h"
#include "look1_iu8lu32n24tu16Ds32Iu8_binlcs.h"

uint8_T look1_iu8lu32n24tu16Ds32Iu8_binlcs(uint8_T u0, const uint8_T bp0[],
  const uint16_T table[], uint32_T maxIndex)
{
  uint32_T frac;
  uint32_T iRght;
  uint32_T iLeft;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    frac = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = ((iRght + iLeft) >> 1U);
    }

    frac = (((uint32_T)((uint8_T)(((uint32_T)u0) - ((uint32_T)bp0[iLeft])))) <<
            24) / ((uint32_T)((uint8_T)(((uint32_T)bp0[iLeft + 1U]) - ((uint32_T)
      bp0[iLeft]))));
  } else {
    iLeft = maxIndex - 1U;
    frac = 16777216U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  return (uint8_T)(((uint32_T)((uint8_T)asr_s32((((int32_T)table[iLeft + 1U]) -
    ((int32_T)table[iLeft])) * ((int32_T)frac), 24U))) + ((uint32_T)((uint8_T)
    table[iLeft])));
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
