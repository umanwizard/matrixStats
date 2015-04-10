#include <Rinternals.h>
#include "macros.h"


#undef X_C_TYPE
#undef X_IN_C
#undef X_ISNAN
#undef X_ISNA
#undef X_ABS
#undef X_PSORT
#undef X_QSORT_I

#undef Y_C_TYPE
#undef Y_IN_C
#undef Y_ISNAN
#undef Y_ISNA
#undef Y_ABS
#undef Y_PSORT
#undef Y_QSORT_I

#undef ANS_SXP
#undef ANS_NA
#undef ANS_ISNAN
#undef ANS_ISNA
#undef ANS_C_TYPE
#undef ANS_IN_C


/*
 Data type macros for argument 'x'
 */
#if X_TYPE == 'i'
  #define X_C_TYPE int
  #define X_IN_C INTEGER
  #define X_ISNAN(x) (x == NA_INTEGER)
  #define X_ISNA(x) (x == NA_INTEGER)
  #define X_ABS(x) abs(x)
  #define X_PSORT iPsort
  #define X_QSORT_I R_qsort_int_I
#elif X_TYPE == 'r'
  #define X_C_TYPE double
  #define X_IN_C REAL
  #define X_ISNAN(x) ISNAN(x) /* NA or NaN */
  #define X_ISNA(x) ISNA(x) /* NA only */
  #define X_ABS(x) fabs(x)
  #define X_PSORT rPsort
  #define X_QSORT_I R_qsort_I
#elif X_TYPE == 'l'
  #define X_C_TYPE int
  #define X_IN_C LOGICAL
  #define X_ISNAN(x) (x == NA_LOGICAL)
#else
  #error "INTERNAL ERROR: Failed to set C macro X_C_TYPE etc.: Unknown X_TYPE"
#endif


/*
 Data type macros for argument 'y'
 */
#ifdef Y_TYPE
  #if Y_TYPE == 'i'
    #define Y_C_TYPE int
    #define Y_IN_C INTEGER
    #define Y_ISNAN(x) (x == NA_INTEGER)
    #define Y_ISNA(x) (x == NA_INTEGER)
    #define Y_ABS(x) abs(x)
    #define Y_PSORT iPsort
    #define Y_QSORT_I R_qsort_int_I
  #elif Y_TYPE == 'r'
    #define Y_C_TYPE double
    #define Y_IN_C REAL
    #define Y_ISNAN(x) ISNAN(x) /* NA or NaN */
    #define Y_ISNA(x) ISNA(x) /* NA only */
    #define Y_ABS(x) fabs(x)
    #define Y_PSORT rPsort
    #define Y_QSORT_I R_qsort_I
  #elif Y_TYPE == 'l'
    #define Y_C_TYPE int
    #define Y_IN_C LOGICAL
    #define Y_ISNAN(x) (x == NA_LOGICAL)
  #else
    #error "INTERNAL ERROR: Failed to set C macro Y_C_TYPE etc.: Unknown Y_TYPE"
  #endif
//#else
//  #define Y_TYPE '.'
#endif



/*
 Data type macros for result ('ans')
 */
#ifndef ANS_TYPE
  /* Default to same as 'x' */
  #define ANS_TYPE X_TYPE
#endif


#if ANS_TYPE == 'i'
  #define ANS_SXP INTSXP
  #define ANS_NA NA_INTEGER
  #define ANS_ISNAN(x) (x == NA_INTEGER)
  #define ANS_ISNA(x) (x == NA_INTEGER)
  #define ANS_C_TYPE int
  #define ANS_IN_C INTEGER
#elif ANS_TYPE == 'r'
  #define ANS_SXP REALSXP
  #define ANS_NA NA_REAL
  #define ANS_ISNAN(x) ISNAN(x) /* NA or NaN */
  #define ANS_ISNA(x) ISNA(x) /* NA only */
  #define ANS_C_TYPE double
  #define ANS_IN_C REAL
#elif ANS_TYPE == 'l'
  #define ANS_SXP LGLSXP
  #define ANS_NA NA_LOGICAL
  #define ANS_ISNAN(x) (x == NA_LOGICAL)
  #define ANS_C_TYPE int
  #define ANS_IN_C LOGICAL
#else
  #error "INTERNAL ERROR: Failed to set C macro ANS_C_TYPE: Unknown ANS_TYPE"
#endif


/*
 Method name based on 'x' (and 'y') types
 */
#ifndef METHOD_NAME
  #if X_TYPE == 'i'
    #if Y_TYPE == 'i'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Integer_Integer)
    #elif Y_TYPE == 'r'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Integer_Real)
    #elif Y_TYPE == 'l'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Integer_Logical)
    #else
      #define METHOD_NAME CONCAT_MACROS(METHOD, Integer)
    #endif
  #elif X_TYPE == 'r'
    #if Y_TYPE == 'i'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Real_Integer)
    #elif Y_TYPE == 'r'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Real_Real)
    #elif Y_TYPE == 'l'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Real_Logical)
    #else
      #define METHOD_NAME CONCAT_MACROS(METHOD, Real)
    #endif
  #elif X_TYPE == 'l'
    #if Y_TYPE == 'i'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Logical_Integer)
    #elif Y_TYPE == 'r'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Logical_Real)
    #elif Y_TYPE == 'l'
      #define METHOD_NAME CONCAT_MACROS(METHOD, Logical_Logical)
    #else
      #define METHOD_NAME CONCAT_MACROS(METHOD, Logical)
    #endif
  #else
    #error "INTERNAL ERROR: Failed to set C macro METHOD_NAME: Unknown X_TYPE"
  #endif
#endif


#undef NUM_OF_ROWS
#undef ROW_INDEX_II
#undef METHOD_NAME_ROW

#undef NUM_OF_COLS
#undef COL_INDEX_JJ
#undef METHOD_NAME_ROW_COL

#ifdef HAS_ROWS
  #define NUM_OF_ROWS nrows
  #define ROW_INDEX_II (rows[ii]-1)
  #define METHOD_NAME_ROW CONCAT_MACROS(METHOD_NAME, hasRows)
#else
  #define NUM_OF_ROWS nrow
  #define ROW_INDEX_II ii
  #define METHOD_NAME_ROW CONCAT_MACROS(METHOD_NAME, noRows)
#endif

#ifdef HAS_COLS
  #define NUM_OF_COLS ncols
  #define COL_INDEX_JJ (cols[jj]-1)
  #define METHOD_NAME_ROW_COL CONCAT_MACROS(METHOD_NAME_ROW, hasCols)
#else
  #define NUM_OF_COLS ncol
  #define COL_INDEX_JJ jj
  #define METHOD_NAME_ROW_COL CONCAT_MACROS(METHOD_NAME_ROW, noCols)
#endif
