/*
 * File: look1_iu16bs16lu32n16_binlcse.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "div_nzp_repeat_u32.h"
#include "look1_iu16bs16lu32n16_binlcse.h"

uint16_T look1_iu16bs16lu32n16_binlcse(uint16_T u0, const int16_T bp0[], const
  uint16_T table[], uint32_T maxIndex)
{
  uint16_T y;
  uint32_T frac;
  int16_T uCast;
  uint16_T yR_0d0;
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
  yR_0d0 = u0;
  if (((int32_T)u0) > 32767) {
    yR_0d0 = 32767U;
  }

  uCast = (int16_T)yR_0d0;
  if (((int32_T)u0) < ((int32_T)bp0[0U])) {
    iLeft = 0U;
    frac = 0U;
  } else if (uCast < bp0[maxIndex]) {
    /* Binary Search */
    frac = (maxIndex >> 1U);
    iLeft = 0U;
    iRght = maxIndex;
    while ((iRght - iLeft) > 1U) {
      if (uCast < bp0[frac]) {
        iRght = frac;
      } else {
        iLeft = frac;
      }

      frac = ((iRght + iLeft) >> 1U);
    }

    frac = div_nzp_repeat_u32(((uint32_T)u0) - ((uint32_T)bp0[iLeft]), (uint32_T)
      ((uint16_T)((int32_T)(((int32_T)bp0[iLeft + 1U]) - ((int32_T)bp0[iLeft])))),
      16U);
  } else {
    iLeft = maxIndex - 1U;
    frac = 65536U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  yR_0d0 = table[iLeft + 1U];
  if (yR_0d0 >= table[iLeft]) {
    y = (uint16_T)(((uint32_T)((uint16_T)((((uint32_T)((uint16_T)(((uint32_T)
      yR_0d0) - ((uint32_T)table[iLeft])))) * frac) >> 16))) + ((uint32_T)
      table[iLeft]));
  } else {
    y = (uint16_T)(((uint32_T)table[iLeft]) - ((uint32_T)((uint16_T)((((uint32_T)
      ((uint16_T)(((uint32_T)table[iLeft]) - ((uint32_T)yR_0d0)))) * frac) >> 16))));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
