/***************************************************************************
 Public methods:
 SEXP rowCounts(SEXP x, SEXP value, SEXP naRm, SEXP hasNA)

 Copyright Henrik Bengtsson, 2014
 **************************************************************************/
#include <Rdefines.h>
#include "types.h"
#include "utils.h"


#define METHOD rowCounts

#define X_TYPE 'i'
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'i'
#define HAS_ROWS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'i'
#define HAS_COLS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'i'
#define HAS_ROWS
#define HAS_COLS
#include "rowCounts_TYPE-template.h"

void (*rowCounts_Integer[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
  {rowCounts_Integer_noRows_noCols, rowCounts_Integer_noRows_hasCols},
  {rowCounts_Integer_hasRows_noCols, rowCounts_Integer_hasRows_hasCols},
};


#define X_TYPE 'r'
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'r'
#define HAS_ROWS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'r'
#define HAS_COLS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'r'
#define HAS_ROWS
#define HAS_COLS
#include "rowCounts_TYPE-template.h"

void (*rowCounts_Real[2][2])(double *x, R_xlen_t nrow, R_xlen_t ncol, double value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
  {rowCounts_Real_noRows_noCols, rowCounts_Real_noRows_hasCols},
  {rowCounts_Real_hasRows_noCols, rowCounts_Real_hasRows_hasCols},
};


#define X_TYPE 'l'
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'l'
#define HAS_ROWS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'l'
#define HAS_COLS
#include "rowCounts_TYPE-template.h"
#define X_TYPE 'l'
#define HAS_ROWS
#define HAS_COLS
#include "rowCounts_TYPE-template.h"

void (*rowCounts_Logical[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
  {rowCounts_Integer_noRows_noCols, rowCounts_Integer_noRows_hasCols},
  {rowCounts_Integer_hasRows_noCols, rowCounts_Integer_hasRows_hasCols},
};

#undef METHOD


SEXP rowCounts(SEXP x, SEXP dim, SEXP value, SEXP what, SEXP naRm, SEXP hasNA, SEXP rows, SEXP cols) {
  SEXP ans;
  int narm, hasna, what2;
  R_xlen_t nrow, ncol;

  /* Argument 'x' & 'dim': */
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

  if (!isNull(rows) && xlength(rows)) {
    crows = validateIndices(rows, nrow, &nrows);
    hasRows = 1;
  }
  if (!isNull(cols) && xlength(cols)) {
    ccols = validateIndices(cols, ncol, &ncols);
    hasCols = 1;
  }

  /* Argument 'what': */
  what2 = asInteger(what);

  /* Argument 'naRm': */
  narm = asLogicalNoNA(naRm, "na.rm");

  /* Argument 'hasNA': */
  hasna = asLogicalNoNA(hasNA, "hasNA");

  /* R allocate a double vector of length 'nrow' */
  PROTECT(ans = allocVector(INTSXP, nrows));

  /* Double matrices are more common to use. */
  if (isReal(x)) {
    rowCounts_Real[hasRows][hasCols](REAL(x), nrow, ncol, asReal(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isInteger(x)) {
    rowCounts_Integer[hasRows][hasCols](INTEGER(x), nrow, ncol, asInteger(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  } else if (isLogical(x)) {
    rowCounts_Logical[hasRows][hasCols](LOGICAL(x), nrow, ncol, asLogical(value), what2, narm, hasna, INTEGER(ans), crows, nrows, ccols, ncols);
  }

  UNPROTECT(1);

  return(ans);
} // rowCounts()


/***************************************************************************
 HISTORY:
 2014-06-02 [HB]
  o Created.
 **************************************************************************/
