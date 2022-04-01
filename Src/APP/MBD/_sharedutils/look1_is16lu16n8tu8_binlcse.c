/*
 * File: look1_is16lu16n8tu8_binlcse.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "look1_is16lu16n8tu8_binlcse.h"

uint8_T look1_is16lu16n8tu8_binlcse(int16_T u0, const int16_T bp0[], const
  uint8_T table[], uint32_T maxIndex)
{
  uint8_T y;
  uint16_T frac;
  uint8_T yR_0d0;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

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
    bpIdx = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (uint16_T)((((uint32_T)((uint16_T)((int32_T)(((int32_T)u0) -
      ((int32_T)bp0[iLeft]))))) << 8) / ((uint32_T)((uint16_T)((int32_T)
      (((int32_T)bp0[iLeft + 1U]) - ((int32_T)bp0[iLeft]))))));
  } else {
    iLeft = maxIndex - 1U;
    frac = 256U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  yR_0d0 = table[iLeft + 1U];
  if (yR_0d0 >= table[iLeft]) {
    y = (uint8_T)(((uint32_T)((uint8_T)((((uint32_T)((uint8_T)(((uint32_T)yR_0d0)
      - ((uint32_T)table[iLeft])))) * ((uint32_T)frac)) >> 8))) + ((uint32_T)
      table[iLeft]));
  } else {
    y = (uint8_T)(((uint32_T)table[iLeft]) - ((uint32_T)((uint8_T)((((uint32_T)
      ((uint8_T)(((uint32_T)table[iLeft]) - ((uint32_T)yR_0d0)))) * ((uint32_T)
      frac)) >> 8))));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
