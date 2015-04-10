#include "macros.h"

#define METHOD_TEMPLATE_H QUOTE_MACROS(CONCAT_MACROS(METHOD,TYPE-template.h))

#ifdef X_TYPE_I
  #define X_TYPE 'i'
  #define HAS_ROWS
  #include METHOD_TEMPLATE_H // 10
  #define HAS_COLS
  #include METHOD_TEMPLATE_H // 11
  #undef HAS_ROWS
  #include METHOD_TEMPLATE_H // 01
  #undef HAS_COLS
  #include METHOD_TEMPLATE_H // 00

  void (*METHOD_NAME[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Integer_noRows_noCols, rowCounts_Integer_noRows_hasCols},
    {rowCounts_Integer_hasRows_noCols, rowCounts_Integer_hasRows_hasCols},
  };
  #include "templates-types_undef.h"
#endif

#ifdef X_TYPE_R
  #define X_TYPE 'r'
  #define HAS_ROWS
  #include METHOD_TEMPLATE_H // 10
  #define HAS_COLS
  #include METHOD_TEMPLATE_H // 11
  #undef HAS_ROWS
  #include METHOD_TEMPLATE_H // 01
  #undef HAS_COLS
  #include METHOD_TEMPLATE_H // 00

  void (*METHOD_NAME[2][2])(double *x, R_xlen_t nrow, R_xlen_t ncol, double value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Real_noRows_noCols, rowCounts_Real_noRows_hasCols},
    {rowCounts_Real_hasRows_noCols, rowCounts_Real_hasRows_hasCols},
  };
  #include "templates-types_undef.h"
#endif

#ifdef X_TYPE_L
  #define X_TYPE 'l'
  #define HAS_ROWS
  #include METHOD_TEMPLATE_H // 10
  #define HAS_COLS
  #include METHOD_TEMPLATE_H // 11
  #undef HAS_ROWS
  #include METHOD_TEMPLATE_H // 01
  #undef HAS_COLS
  #include METHOD_TEMPLATE_H // 00

  void (*METHOD_NAME[2][2])(int *x, R_xlen_t nrow, R_xlen_t ncol, int value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols) = {
    {rowCounts_Logical_noRows_noCols, rowCounts_Logical_noRows_hasCols},
    {rowCounts_Logical_hasRows_noCols, rowCounts_Logical_hasRows_hasCols},
  };
  #include "templates-types_undef.h"
#endif

#undef METHOD_TEMPLATE_H
