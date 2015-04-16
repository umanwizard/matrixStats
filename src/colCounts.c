/***************************************************************************
 Public methods:
 SEXP colCounts(SEXP x, SEXP value, SEXP naRm, SEXP hasNA)

 Copyright Henrik Bengtsson, 2014
 **************************************************************************/
#include <Rdefines.h>
#include "types.h"
#include "utils.h"


#define METHOD colCounts
#define RETURN_TYPE void
#define ARGUMENTS_LIST X_C_TYPE *x, R_xlen_t nrow, R_xlen_t ncol, X_C_TYPE value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols

#define X_TYPE_I
#define X_TYPE_R
#define X_TYPE_L
#include "templates-gen.h"

#undef METHOD


SEXP colCounts(SEXP x, SEXP dim, SEXP value, SEXP what, SEXP naRm, SEXP hasNA, SEXP rows, SEXP cols) {
  SEXP ans;
  int narm, hasna, what2;
  R_xlen_t nrow, ncol;

  /* Argument 'x' and 'dim': */
  assertArgMatrix(x, dim, (R_TYPE_LGL | R_TYPE_INT | R_TYPE_REAL), "x");
  nrow = INTEGER(dim)[0];
  ncol = INTEGER(dim)[1];

  /* Argument 'value': */
  if (length(value) != 1)
    error("Argument 'value' must be a single value.");

  if (!isNumeric(value))
    error("Argument 'value' must be a numeric value.");

  R_xlen_t nrows = nrow, ncols = ncol;
  int *crows = NULL, *ccols = NULL;
  BOOL hasRows = 0, hasCols = 0;

  if (!isNull(rows)) {
    crows = validateIndices(rows, nrow, &nrows);
    hasRows = 1;
  }
  if (!isNull(cols)) {
    ccols = validateIndices(cols, ncol, &ncols);
    hasCols = 1;
  }

  /* Argument 'what': */
  what2 = asInteger(what);

  /* Argument 'naRm': */
  narm = asLogicalNoNA(naRm, "na.rm");

  /* Argument 'hasNA': */
  hasna = asLogicalNoNA(hasNA, "hasNA");

  /* R allocate an integer vector of length 'ncol' */
  PROTECT(ans = allocVector(INTSXP, ncols));

  if (isReal(x)) {
    colCounts_Real[hasRows][hasCols](REAL(x), nrow, ncol, asReal(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isInteger(x)) {
    colCounts_Integer[hasRows][hasCols](INTEGER(x), nrow, ncol, asInteger(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isLogical(x)) {
    colCounts_Logical[hasRows][hasCols](LOGICAL(x), nrow, ncol, asLogical(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  }

  UNPROTECT(1);

  return(ans);
} // colCounts()


SEXP count(SEXP x, SEXP value, SEXP what, SEXP naRm, SEXP hasNA, SEXP idxs) {
  SEXP ans;
  int narm, hasna, what2;
  R_xlen_t nx;

  /* Argument 'x' and 'dim': */
  assertArgVector(x, (R_TYPE_LGL | R_TYPE_INT | R_TYPE_REAL), "x");
  nx = xlength(x);

  /* Argument 'value': */
  if (length(value) != 1)
    error("Argument 'value' must be a single value.");

  if (!isNumeric(value))
    error("Argument 'value' must be a numeric value.");

  R_xlen_t nrows = 0, ncols = nx;
  int *crows = NULL, *ccols = NULL;
  BOOL hasRows = 0, hasCols = 0;

  if (!isNull(idxs)) {
    ccols = validateIndices(idxs, nx, &ncols);
    hasCols = 1;
  }

  /* Argument 'what': */
  what2 = asInteger(what);

  /* Argument 'naRm': */
  narm = asLogicalNoNA(naRm, "na.rm");

  /* Argument 'hasNA': */
  hasna = asLogicalNoNA(hasNA, "hasNA");

  /* R allocate a integer scalar */
  PROTECT(ans = allocVector(INTSXP, 1));

  if (isReal(x)) {
    colCounts_Real[hasRows][hasCols](REAL(x), nx, 1, asReal(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isInteger(x)) {
    colCounts_Integer[hasRows][hasCols](INTEGER(x), nx, 1, asInteger(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isLogical(x)) {
    colCounts_Logical[hasRows][hasCols](LOGICAL(x), nx, 1, asLogical(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  }

  UNPROTECT(1);

  return(ans);
} // count()


/***************************************************************************
 HISTORY:
 2014-11-14 [HB]
  o Created from rowCounts.c.
 **************************************************************************/
