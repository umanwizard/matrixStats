#include "types.h"
#include "templates-types.h"

#if OP == '+'
  #define METHOD_NAME_T CONCAT_MACROS(METHOD_NAME, Add)
  #define FUN CONCAT_MACROS(FUN, METHOD_NAME_T)
  static R_INLINE double FUN(X_C_TYPE x, Y_C_TYPE y, int narm) {
      if (narm) {
        if (X_ISNAN(x)) {
          return (double)y;
        } else if (Y_ISNAN(y)) {
          return (double)x;
        } else {
          return (double)x + (double)y;
        }
      } else {
        return (double)x + (double)y;
      }
  }
#elif OP == '-'
  #define METHOD_NAME_T CONCAT_MACROS(METHOD_NAME, Sub)
  #define FUN CONCAT_MACROS(FUN, METHOD_NAME_T)
  static R_INLINE double FUN(X_C_TYPE x, Y_C_TYPE y, int narm) {
    return (double)x - (double)y;
  }
#elif OP == '*'
  #define METHOD_NAME_T CONCAT_MACROS(METHOD_NAME, Mul)
  #define FUN CONCAT_MACROS(FUN, METHOD_NAME_T)
  static R_INLINE double FUN(X_C_TYPE x, Y_C_TYPE y, int narm) {
      if (narm) {
        if (X_ISNAN(x)) {
          return (double)y;
        } else if (Y_ISNAN(y)) {
          return (double)x;
        } else {
          return (double)x * (double)y;
        }
      } else {
        return (double)x * (double)y;
      }
  }
#elif OP == '/'
  #define METHOD_NAME_T CONCAT_MACROS(METHOD_NAME, Div)
  #define FUN CONCAT_MACROS(FUN, METHOD_NAME_T)
  static R_INLINE double FUN(X_C_TYPE x, Y_C_TYPE y, int narm) {
    return (double)x / (double)y;
  }
#else
  #error "INTERNAL ERROR: Failed to set C inline function FUN(x, y, narm): Unknown OP"
#endif

void METHOD_NAME_T(X_C_TYPE *x, R_xlen_t nx, 
                   Y_C_TYPE *y, R_xlen_t ny, R_xlen_t step,
                   int narm, int hasna, 
                   ANS_C_TYPE *ans, R_xlen_t n) {
  double value;
  R_xlen_t kk, xi, yi;

  xi = 0;
  yi = 0;

  if (step >= 2) {
    for (kk=0; kk < n; kk++) {
      value = FUN(x[xi], y[yi], narm);
  
      /*      Rprintf("x[%d]=%g, y[%d]=%g & step=%d => ans[%d]=%g\n", xi, (double)x[xi],  yi, (double)y[yi], step, kk, value); */
      ans[kk] = (ANS_C_TYPE) value;
  
      /* Next x and y values */
      xi++;
      if (xi >= nx) xi = 0;
      yi = xi / step;
      yi %= ny;
    } /* for (kk ...) */
  } else {
    for (kk=0; kk < n; kk++) {
      value = FUN(x[xi], y[yi], narm);
  
      /*      Rprintf("x[%d]=%g, y[%d]=%g & step=%d => ans[%d]=%g\n", xi, (double)x[xi],  yi, (double)y[yi], step, kk, value); */
      ans[kk] = (ANS_C_TYPE) value;
  
      /* Next x and y values */
      xi++;
      if (xi >= nx) xi = 0;
      yi++;
      if (yi >= ny) yi = 0;
    } /* for (kk ...) */
  }
}

#undef FUN
#undef METHOD_NAME_T

/* Undo template macros */
#include "templates-types_undef.h"
