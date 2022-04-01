/*
 * File: uMultiWordDiv.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "uMultiWordDiv.h"

int32_T uMultiWordDiv(uint32_T a[], int32_T na, uint32_T b[], int32_T nb,
                      uint32_T q[], int32_T nq, uint32_T r[], int32_T nr)
{
  int32_T y;
  int32_T nza;
  int32_T nzb;
  int32_T na1;
  int32_T nb1;
  uint32_T kba;
  uint32_T kbb;
  uint32_T nba;
  uint32_T nbb;
  uint32_T kbs;
  uint32_T nbq;
  uint32_T tnb;
  int32_T tpi;
  uint32_T t;
  uint32_T mask;
  uint32_T ak;
  uint32_T bk;
  int32_T ka;
  int32_T kr;
  nzb = nb;
  tpi = nb - 1;
  while ((nzb > 0) && (b[tpi] == 0U)) {
    nzb--;
    tpi--;
  }

  if (nzb > 0) {
    nza = na;
    for (tpi = 0; tpi < nq; tpi++) {
      q[tpi] = 0U;
    }

    tpi = na - 1;
    while ((nza > 0) && (a[tpi] == 0U)) {
      nza--;
      tpi--;
    }

    if ((nza > 0) && (nza >= nzb)) {
      nb1 = nzb - 1;
      na1 = nza - 1;
      for (kr = 0; kr < nr; kr++) {
        r[kr] = 0U;
      }

      /* Quick return if dividend and divisor fit into single word. */
      if (nza == 1) {
        ak = a[0];
        bk = b[0];
        nbq = ak / bk;
        q[0] = nbq;
        r[0] = ak - (nbq * bk);
        y = 7;
      } else {
        /* Remove leading zeros from both, dividend and divisor. */
        kbb = 1U;
        t = (b[nb1] >> 1U);
        while (t != 0U) {
          kbb++;
          t >>= 1U;
        }

        kba = 1U;
        t = (a[na1] >> 1U);
        while (t != 0U) {
          kba++;
          t >>= 1U;
        }

        /* Quick return if quotient is zero. */
        if ((nza > nzb) || (kba >= kbb)) {
          nba = (((uint32_T)na1) << 5) + kba;
          nbb = (((uint32_T)nb1) << 5) + kbb;

          /* Normalize b. */
          if (kbb != 32U) {
            bk = b[nb1];
            kbs = 32U - kbb;
            for (tpi = nb1; tpi > 0; tpi--) {
              t = (bk << kbs);
              bk = b[tpi - 1];
              t |= (bk >> kbb);
              b[tpi] = t;
            }

            b[tpi] = (bk << kbs);
            mask = ~((1U << kbs) - 1U);
          } else {
            mask = MAX_uint32_T;
          }

          /* Initialize quotient to zero. */
          tnb = 0U;
          y = 0;

          /* Until exit conditions have been met, do */
          do {
            /* Normalize a */
            if (kba != 32U) {
              kbs = 32U - kba;
              tnb += kbs;
              ak = a[na1];
              for (ka = na1; ka > 0; ka--) {
                t = (ak << kbs);
                ak = a[ka - 1];
                t |= (ak >> kba);
                a[ka] = t;
              }

              a[ka] = (ak << kbs);
            }

            /* Compare b against the a. */
            ak = a[na1];
            bk = b[nb1];
            if ((((nb1 == 0) ? mask : MAX_uint32_T) & ak) == bk) {
              kr = 0;
              ka = na1;
              tpi = nb1;
              while ((kr == 0) && (tpi > 0)) {
                ka--;
                ak = a[ka];
                tpi--;
                bk = b[tpi];
                if ((((tpi == 0) ? mask : MAX_uint32_T) & ak) != bk) {
                  kr = (ak > bk) ? 1 : -1;
                }
              }
            } else {
              kr = (ak > bk) ? 1 : -1;
            }

            /* If the remainder in a is still greater or equal to b, subtract normalized divisor from a. */
            if ((kr >= 0) || (nba > nbb)) {
              nbq = nba - nbb;

              /* If the remainder and the divisor are equal, set remainder to zero. */
              if (kr == 0) {
                ka = na1;
                for (tpi = nb1; tpi > 0; tpi--) {
                  a[ka] = 0U;
                  ka--;
                }

                a[ka] -= b[tpi];
              } else {
                /* Otherwise, subtract the divisor from the remainder */
                if (kr < 0) {
                  ak = a[na1];
                  kba = 31U;
                  for (ka = na1; ka > 0; ka--) {
                    t = (ak << 1U);
                    ak = a[ka - 1];
                    t |= (ak >> 31U);
                    a[ka] = t;
                  }

                  a[ka] = (ak << 1U);
                  tnb++;
                  nbq--;
                }

                kbs = 0U;
                ka = na1 - nb1;
                for (tpi = 0; tpi < nzb; tpi++) {
                  bk = b[tpi];
                  t = a[ka];
                  ak = (t - bk) - kbs;
                  kbs = (kbs != 0U) ? ((uint32_T)((ak >= t) ? 1 : 0)) :
                    ((uint32_T)((ak > t) ? 1 : 0));
                  a[ka] = ak;
                  ka++;
                }
              }

              /* Update the quotient. */
              tpi = (int32_T)((uint32_T)(nbq >> 5));
              q[tpi] |= (1U << (nbq - (((uint32_T)tpi) << 5)));

              /* Remove leading zeros from the remainder and check whether the exit conditions have been met. */
              tpi = na1;
              while ((nza > 0) && (a[tpi] == 0U)) {
                nza--;
                tpi--;
              }

              if (nza >= nzb) {
                na1 = nza - 1;
                kba = 1U;
                t = (a[na1] >> 1U);
                while (t != 0U) {
                  kba++;
                  t >>= 1U;
                }

                nba = ((((uint32_T)na1) << 5) + kba) - tnb;
                if (nba < nbb) {
                  y = 2;
                }
              } else if (nza == 0) {
                y = 1;
              } else {
                na1 = nza - 1;
                y = 4;
              }
            } else {
              y = 3;
            }
          } while (y == 0);

          /* Return the remainder. */
          if (y == 1) {
            r[0] = a[0];
          } else {
            tpi = (int32_T)((uint32_T)(tnb >> 5));
            nbq = tnb - (((uint32_T)tpi) << 5);
            if (nbq == 0U) {
              ka = tpi;
              for (kr = 0; kr <= nb1; kr++) {
                r[kr] = a[ka];
                ka++;
              }
            } else {
              kbs = 32U - nbq;
              ak = a[tpi];
              kr = 0;
              for (ka = tpi + 1; ka <= na1; ka++) {
                t = (ak >> nbq);
                ak = a[ka];
                t |= (ak << kbs);
                r[kr] = t;
                kr++;
              }

              r[kr] = (ak >> nbq);
            }
          }

          /* Restore b. */
          if (kbb != 32U) {
            bk = b[0];
            kbs = 32U - kbb;
            for (tpi = 0; tpi < nb1; tpi++) {
              t = (bk >> kbs);
              bk = b[tpi + 1];
              t |= (bk << kbb);
              b[tpi] = t;
            }

            b[tpi] = (bk >> kbs);
          }
        } else {
          for (kr = 0; kr < nr; kr++) {
            r[kr] = a[kr];
          }

          y = 6;
        }
      }
    } else {
      for (kr = 0; kr < nr; kr++) {
        r[kr] = a[kr];
      }

      y = 5;
    }
  } else {
    y = -1;
  }

  return y;
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
