/***************************************************************************
 Public methods:
 SEXP validate(SEXP idxs, SEXP maxIdx)

 **************************************************************************/
#include <string.h>
#include "utils.h"

SEXP validate(SEXP idxs, SEXP maxIdx) {
  SEXP ans;
  int *cidxs;
  int cmaxIdx = asInteger(maxIdx);

  if (isNull(idxs)) {
    // idxs should not be NULL when used for validating idxs
    ans = PROTECT(allocVector(INTSXP, cmaxIdx));
    cidxs = INTEGER(ans);
    for (int i = 0; i < cmaxIdx; ++ i) cidxs[i] = i + 1;

  } else {
    R_xlen_t ansNidxs;
    cidxs = validateIndices(idxs, cmaxIdx, &ansNidxs);
    ans = PROTECT(allocVector(INTSXP, ansNidxs));
    memcpy(INTEGER(ans), cidxs, ansNidxs*sizeof(int));
  }

  UNPROTECT(1);
  return ans;
}
