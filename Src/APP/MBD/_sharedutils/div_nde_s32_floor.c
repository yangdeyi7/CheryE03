/*
 * File: div_nde_s32_floor.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "div_nde_s32_floor.h"

int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return ((((numerator < 0) != (denominator < 0)) && ((numerator % denominator)
            != 0)) ? -1 : 0) + (numerator / denominator);
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
