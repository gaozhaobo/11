//
// MATLAB Compiler: 8.0 (R2020a)
// Date: Mon Jan  6 19:36:48 2025
// Arguments:
// "-B""macro_default""-W""cpplib:Caculate_Robot2_V_with_Robot1,all,version=1.0"
// "-T""link:lib""-d""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\Double_arms\Caculate_Robot2_V_with_Robot1\for_testi
// ng""-v""D:\MATLAB 2020\MY_MATLAB\Robot_Tool\Caculate_Robot2_V_with_Robot1.m"
//

#ifndef Caculate_Robot2_V_with_Robot1_h
#define Caculate_Robot2_V_with_Robot1_h 1

#if defined(__cplusplus) && !defined(mclmcrrt_h) && defined(__linux__)
#  pragma implementation "mclmcrrt.h"
#endif
#include "mclmcrrt.h"
#include "mclcppclass.h"
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_Caculate_Robot2_V_with_Robot1_C_API 
#define LIB_Caculate_Robot2_V_with_Robot1_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV Caculate_Robot2_V_with_Robot1InitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV Caculate_Robot2_V_with_Robot1Initialize(void);

extern LIB_Caculate_Robot2_V_with_Robot1_C_API 
void MW_CALL_CONV Caculate_Robot2_V_with_Robot1Terminate(void);

extern LIB_Caculate_Robot2_V_with_Robot1_C_API 
void MW_CALL_CONV Caculate_Robot2_V_with_Robot1PrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV mlxCaculate_Robot2_V_with_Robot1(int nlhs, mxArray *plhs[], int nrhs, 
                                                   mxArray *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_Caculate_Robot2_V_with_Robot1
#define PUBLIC_Caculate_Robot2_V_with_Robot1_CPP_API __declspec(dllexport)
#else
#define PUBLIC_Caculate_Robot2_V_with_Robot1_CPP_API __declspec(dllimport)
#endif

#define LIB_Caculate_Robot2_V_with_Robot1_CPP_API PUBLIC_Caculate_Robot2_V_with_Robot1_CPP_API

#else

#if !defined(LIB_Caculate_Robot2_V_with_Robot1_CPP_API)
#if defined(LIB_Caculate_Robot2_V_with_Robot1_C_API)
#define LIB_Caculate_Robot2_V_with_Robot1_CPP_API LIB_Caculate_Robot2_V_with_Robot1_C_API
#else
#define LIB_Caculate_Robot2_V_with_Robot1_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_Caculate_Robot2_V_with_Robot1_CPP_API void MW_CALL_CONV Caculate_Robot2_V_with_Robot1(int nargout, mwArray& V_qF, mwArray& V_qL1, const mwArray& q1, const mwArray& q2, const mwArray& tool1, const mwArray& tool2, const mwArray& V1, const mwArray& t_offset);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
