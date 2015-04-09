#include "macros.h"

#define METHOD_TYPE_TEMPLATE_H QUOTE_MACROS(CONCAT_MACROS(METHOD,TYPE-template.h))

#ifdef X_TYPE_I
  #define X_TYPE 'i'
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'i'
  #define HAS_ROWS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'i'
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'i'
  #define HAS_ROWS
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H

  void (*rowCounts_Integer[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Integer_noRows_noCols, rowCounts_Integer_noRows_hasCols},
    {rowCounts_Integer_hasRows_noCols, rowCounts_Integer_hasRows_hasCols},
  };
#endif

#ifdef X_TYPE_R
  #define X_TYPE 'r'
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'r'
  #define HAS_ROWS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'r'
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'r'
  #define HAS_ROWS
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H

  void (*rowCounts_Real[2][2])(double *x, R_xlen_t nrow, R_xlen_t ncol, double value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Real_noRows_noCols, rowCounts_Real_noRows_hasCols},
    {rowCounts_Real_hasRows_noCols, rowCounts_Real_hasRows_hasCols},
  };
#endif

#ifdef X_TYPE_L
  #define X_TYPE 'l'
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'l'
  #define HAS_ROWS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'l'
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H
  #define X_TYPE 'l'
  #define HAS_ROWS
  #define HAS_COLS
  #include METHOD_TYPE_TEMPLATE_H

  void (*rowCounts_Logical[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Integer_noRows_noCols, rowCounts_Integer_noRows_hasCols},
    {rowCounts_Integer_hasRows_noCols, rowCounts_Integer_hasRows_hasCols},
  };
#endif


#undef METHOD_TYPE_TEMPLATE_H
