/*
 * File: sMultiWordDivNear.c
 *
 * Code generated for Simulink model 'Chery_E03_Hp'.
 *
 * Model version                  : 1.13
 * Simulink Coder version         : 9.0 (R2018b) 24-May-2018
 * C/C++ source code generated on : Sat Mar 26 16:14:36 2022
 */

#include "rtwtypes.h"
#include "MultiWordNeg.h"
#include "MultiWordSetSignedMax.h"
#include "MultiWordSetSignedMin.h"
#include "sMultiWord2MultiWord.h"
#include "uMultiWordCmpShr.h"
#include "uMultiWordDiv.h"
#include "uMultiWordInc.h"
#include "sMultiWordDivNear.h"

void sMultiWordDivNear(const uint32_T u1[], int32_T n1, const uint32_T u2[],
  int32_T n2, uint32_T y1[], int32_T m1, uint32_T y2[], int32_T m2, uint32_T t1[],
  int32_T l1, uint32_T t2[], int32_T l2)
{
  boolean_T numNeg;
  boolean_T denNeg;
  int32_T cmp;
  numNeg = ((u1[n1 - 1] & 2147483648U) != 0U);
  denNeg = ((u2[n2 - 1] & 2147483648U) != 0U);
  if (numNeg) {
    MultiWordNeg(u1, t1, n1);
  } else {
    sMultiWord2MultiWord(u1, n1, t1, l1);
  }

  if (denNeg) {
    MultiWordNeg(u2, t2, n2);
  } else {
    sMultiWord2MultiWord(u2, n2, t2, l2);
  }

  if (uMultiWordDiv(t1, l1, t2, l2, y1, m1, y2, m2) < 0) {
    if (numNeg) {
      MultiWordSetSignedMin(y1, m1);
    } else {
      MultiWordSetSignedMax(y1, m1);
    }
  } else {
    cmp = uMultiWordCmpShr(y2, t2, m2);
    if ((cmp >= 0) && ((numNeg == denNeg) || (cmp > 0))) {
      uMultiWordInc(y1, m1);
    }

    if (numNeg != denNeg) {
      MultiWordNeg(y1, y1, m1);
    }
  }
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
