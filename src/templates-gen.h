#include "macros.h"

#define METHOD_TEMPLATE_H QUOTE_MACROS(CONCAT_MACROS(METHOD,TYPE-template.h))
#define ARGUMENTS_LIST X_C_TYPE *x, R_xlen_t nrow, R_xlen_t ncol, X_C_TYPE value, int what, int narm, int hasna, int *ans, int *rows, R_xlen_t nrows, int *cols, R_xlen_t ncols

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

  void (*METHOD_NAME[2][2])(ARGUMENTS_LIST) = {
    {METHOD_NAME_noRows_noCols, METHOD_NAME_noRows_hasCols},
    {METHOD_NAME_hasRows_noCols, METHOD_NAME_hasRows_hasCols},
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

  void (*METHOD_NAME[2][2])(ARGUMENTS_LIST) = {
    {METHOD_NAME_noRows_noCols, METHOD_NAME_noRows_hasCols},
    {METHOD_NAME_hasRows_noCols, METHOD_NAME_hasRows_hasCols},
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

  void (*METHOD_NAME[2][2])(ARGUMENTS_LIST) = {
    {METHOD_NAME_noRows_noCols, METHOD_NAME_noRows_hasCols},
    {METHOD_NAME_hasRows_noCols, METHOD_NAME_hasRows_hasCols},
  };
  #include "templates-types_undef.h"
#endif

#undef METHOD_TEMPLATE_H
