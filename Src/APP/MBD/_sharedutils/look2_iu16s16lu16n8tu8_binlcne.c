/*
 * File: look2_iu16s16lu16n8tu8_binlcne.c
 *
 * Code generated for Simulink model 'Sokon_X01_Cmf'.
 *
 * Model version                  : 1.3
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:15:07 2022
 */

#include "rtwtypes.h"
#include "div_nzp_u32_near.h"
#include "look2_iu16s16lu16n8tu8_binlcne.h"

uint8_T look2_iu16s16lu16n8tu8_binlcne(uint16_T u0, int16_T u1, const uint16_T
  bp0[], const int16_T bp1[], const uint8_T table[], const uint32_T maxIndex[],
  uint32_T stride)
{
  uint8_T y;
  uint16_T frac;
  uint32_T bpIndices[2];
  uint16_T fractions[2];
  uint8_T yL_1d;
  uint8_T yR_0d0;
  uint32_T iRght;
  uint32_T bpIdx;
  uint32_T iLeft;

  /* Column-major Lookup 2-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'nearest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'nearest'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[0U] >> 1U);
    iLeft = 0U;
    iRght = maxIndex[0U];
    while ((iRght - iLeft) > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (uint16_T)div_nzp_u32_near(((uint32_T)((uint16_T)(((uint32_T)u0) -
      ((uint32_T)bp0[iLeft])))) << 8, (uint32_T)((uint16_T)(((uint32_T)bp0[iLeft
      + 1U]) - ((uint32_T)bp0[iLeft]))));
  } else {
    iLeft = maxIndex[0U] - 1U;
    frac = 256U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = iLeft;

  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'nearest'
   */
  if (u1 <= bp1[0U]) {
    iLeft = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Binary Search */
    bpIdx = (maxIndex[1U] >> 1U);
    iLeft = 0U;
    iRght = maxIndex[1U];
    while ((iRght - iLeft) > 1U) {
      if (u1 < bp1[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = ((iRght + iLeft) >> 1U);
    }

    frac = (uint16_T)div_nzp_u32_near(((uint32_T)((uint16_T)((int32_T)(((int32_T)
      u1) - ((int32_T)bp1[iLeft]))))) << 8, (uint32_T)((uint16_T)((int32_T)
      (((int32_T)bp1[iLeft + 1U]) - ((int32_T)bp1[iLeft])))));
  } else {
    iLeft = maxIndex[1U] - 1U;
    frac = 256U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Rounding mode: 'nearest'
     Overflow mode: 'wrapping'
   */
  bpIdx = (iLeft * stride) + bpIndices[0U];
  yR_0d0 = table[bpIdx + 1U];
  if (yR_0d0 >= table[bpIdx]) {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)yR_0d0) - ((uint32_T)table[bpIdx]))))
      * ((uint32_T)fractions[0U]);
    yL_1d = (uint8_T)(((uint32_T)((uint8_T)(((uint32_T)(((iRght & 128U) != 0U) ?
      1 : 0)) + (iRght >> 8)))) + ((uint32_T)table[bpIdx]));
  } else {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)table[bpIdx]) - ((uint32_T)yR_0d0))))
      * ((uint32_T)fractions[0U]);
    yL_1d = (uint8_T)(((uint32_T)table[bpIdx]) - ((uint32_T)((uint8_T)
      (((uint32_T)(((iRght & 128U) != 0U) ? 1 : 0)) + (iRght >> 8)))));
  }

  bpIdx += stride;
  yR_0d0 = table[bpIdx + 1U];
  if (yR_0d0 >= table[bpIdx]) {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)yR_0d0) - ((uint32_T)table[bpIdx]))))
      * ((uint32_T)fractions[0U]);
    yR_0d0 = (uint8_T)(((uint32_T)((uint8_T)(((uint32_T)(((iRght & 128U) != 0U) ?
      1 : 0)) + (iRght >> 8)))) + ((uint32_T)table[bpIdx]));
  } else {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)table[bpIdx]) - ((uint32_T)yR_0d0))))
      * ((uint32_T)fractions[0U]);
    yR_0d0 = (uint8_T)(((uint32_T)table[bpIdx]) - ((uint32_T)((uint8_T)
      (((uint32_T)(((iRght & 128U) != 0U) ? 1 : 0)) + (iRght >> 8)))));
  }

  if (yR_0d0 >= yL_1d) {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)yR_0d0) - ((uint32_T)yL_1d)))) *
      ((uint32_T)frac);
    y = (uint8_T)(((uint32_T)((uint8_T)(((uint32_T)(((iRght & 128U) != 0U) ? 1 :
      0)) + (iRght >> 8)))) + ((uint32_T)yL_1d));
  } else {
    iRght = ((uint32_T)((uint8_T)(((uint32_T)yL_1d) - ((uint32_T)yR_0d0)))) *
      ((uint32_T)frac);
    y = (uint8_T)(((uint32_T)yL_1d) - ((uint32_T)((uint8_T)(((uint32_T)(((iRght
      & 128U) != 0U) ? 1 : 0)) + (iRght >> 8)))));
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
