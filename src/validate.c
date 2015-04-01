// WARNING: This file is just for testing 'validate'. Will be removed in the future.
#include <string.h>
#include "utils.h"

SEXP validate(SEXP idxs, SEXP N) {
  R_xlen_t IDXS;
  int *idxs_ptr;
  int n = asInteger(N);

  if (isNull(idxs) || xlength(idxs) == 0) {
    IDXS = n;
    idxs_ptr = (int*) R_alloc(n, sizeof(int));
    for (int i = 0; i < n; ++ i) idxs_ptr[i] = i + 1;

  } else {
    idxs_ptr = validateIndices(idxs, n, &IDXS);
  }

  SEXP ans = PROTECT(allocVector(INTSXP, IDXS));
  memcpy(INTEGER(ans), idxs_ptr, IDXS*sizeof(int));
  UNPROTECT(1);
  return ans;
}
