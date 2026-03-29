//
// MATLAB Compiler: 8.0 (R2020a)
// Date: Fri Jan  3 17:07:36 2025
// Arguments:
// "-B""macro_default""-W""cpplib:Robot_ikine_Tool,all,version=1.0""-T""link:lib
// ""-d""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\test\Robot_ikine_Tool\for_testing""-v""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\Robot_ikine_Tool.m"
//

#ifndef Robot_ikine_Tool_h
#define Robot_ikine_Tool_h 1

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
#ifndef LIB_Robot_ikine_Tool_C_API 
#define LIB_Robot_ikine_Tool_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV Robot_ikine_ToolInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV Robot_ikine_ToolInitialize(void);

extern LIB_Robot_ikine_Tool_C_API 
void MW_CALL_CONV Robot_ikine_ToolTerminate(void);

extern LIB_Robot_ikine_Tool_C_API 
void MW_CALL_CONV Robot_ikine_ToolPrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV mlxRobot_ikine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_Robot_ikine_Tool
#define PUBLIC_Robot_ikine_Tool_CPP_API __declspec(dllexport)
#else
#define PUBLIC_Robot_ikine_Tool_CPP_API __declspec(dllimport)
#endif

#define LIB_Robot_ikine_Tool_CPP_API PUBLIC_Robot_ikine_Tool_CPP_API

#else

#if !defined(LIB_Robot_ikine_Tool_CPP_API)
#if defined(LIB_Robot_ikine_Tool_C_API)
#define LIB_Robot_ikine_Tool_CPP_API LIB_Robot_ikine_Tool_C_API
#else
#define LIB_Robot_ikine_Tool_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_Robot_ikine_Tool_CPP_API void MW_CALL_CONV Robot_ikine_Tool(int nargout, mwArray& My, const mwArray& Mx, const mwArray& q0, const mwArray& index, const mwArray& tool);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
