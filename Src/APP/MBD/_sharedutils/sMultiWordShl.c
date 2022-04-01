/*
 * File: sMultiWordShl.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "sMultiWordShl.h"

void sMultiWordShl(const uint32_T u1[], int32_T n1, uint32_T n2, uint32_T y[],
                   int32_T n)
{
  int32_T nb;
  int32_T nc;
  int32_T i;
  uint32_T ys;
  uint32_T u1i;
  uint32_T yi;
  uint32_T nr;
  uint32_T nl;
  nb = (int32_T)((uint32_T)(n2 >> 5));
  ys = ((u1[n1 - 1] & 2147483648U) != 0U) ? MAX_uint32_T : 0U;
  nc = (nb > n) ? n : nb;
  u1i = 0U;
  for (i = 0; i < nc; i++) {
    y[i] = 0U;
  }

  if (nb < n) {
    nl = n2 - (((uint32_T)nb) << 5);
    nb += n1;
    if (nb > n) {
      nb = n;
    }

    nb -= i;
    if (nl > 0U) {
      nr = 32U - nl;
      for (nc = 0; nc < nb; nc++) {
        yi = (u1i >> nr);
        u1i = u1[nc];
        y[i] = (u1i << nl) | yi;
        i++;
      }

      if (i < n) {
        y[i] = (u1i >> nr) | (ys << nl);
        i++;
      }
    } else {
      for (nc = 0; nc < nb; nc++) {
        y[i] = u1[nc];
        i++;
      }
    }
  }

  while (i < n) {
    y[i] = ys;
    i++;
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
