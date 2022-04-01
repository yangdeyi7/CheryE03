/*
 * File: sMultiWordShrNear.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWordShr.h"
#include "sMultiWordShrNear.h"

void sMultiWordShrNear(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
  int32_T n)
{
  int32_T nb;
  uint32_T n2m1;
  boolean_T doNearest;
  n2m1 = n2 - 1U;
  nb = (int32_T)((uint32_T)(n2m1 >> 5));
  if (nb < n1) {
    doNearest = (((1U << (n2m1 - ((uint32_T)((int32_T)(nb * 32))))) & u1[nb]) !=
                 0U);
  } else {
    n2m1 = ((u1[n1 - 1] & 2147483648U) != 0U) ? MAX_uint32_T : 0U;
    doNearest = (n2m1 != 0U);
  }

  sMultiWordShr(u1, n1, n2, y, n);
  nb = 0;
  while (doNearest && (nb < n)) {
    y[nb]++;
    if (y[nb] != 0U) {
      doNearest = false;
    }

    nb++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
