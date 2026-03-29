//
// MATLAB Compiler: 8.2 (R2021a)
// Date: Fri Jun 14 15:17:11 2024
// Arguments:
// "-B""macro_default""-W""cpplib:Robot_ikine,all,version=1.0""-T""link:lib""-d"
// "D:\MATLAB2021\MY_MATLAB\Robot_Tool\Robot_ikine\for_testing""-v""D:\MATLAB202
// 1\MY_MATLAB\Robot_Tool\Robot_ikine.m""D:\MATLAB2021\MY_MATLAB\Robot_Tool\Robo
// t_ikine_Tool.m""D:\MATLAB2021\MY_MATLAB\Robot_Tool\Robot_kine.m""D:\MATLAB202
// 1\MY_MATLAB\Robot_Tool\Robot_kine_Tool.m""D:\MATLAB2021\MY_MATLAB\Robot_Tool\
// Trans_Robot_Camera.m"
//

#ifndef Robot_ikine_h
#define Robot_ikine_h 1

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
#ifndef LIB_Robot_ikine_C_API 
#define LIB_Robot_ikine_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV Robot_ikineInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV Robot_ikineInitialize(void);

extern LIB_Robot_ikine_C_API 
void MW_CALL_CONV Robot_ikineTerminate(void);

extern LIB_Robot_ikine_C_API 
void MW_CALL_CONV Robot_ikinePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV mlxRobot_ikine(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV mlxRobot_ikine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV mlxRobot_kine(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV mlxRobot_kine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_Robot_ikine_C_API 
bool MW_CALL_CONV mlxTrans_Robot_Camera(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                        *prhs[]);

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */

#ifdef __cplusplus
}
#endif


/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

#ifdef __cplusplus

/* On Windows, use __declspec to control the exported API */
#if defined(_MSC_VER) || defined(__MINGW64__)

#ifdef EXPORTING_Robot_ikine
#define PUBLIC_Robot_ikine_CPP_API __declspec(dllexport)
#else
#define PUBLIC_Robot_ikine_CPP_API __declspec(dllimport)
#endif

#define LIB_Robot_ikine_CPP_API PUBLIC_Robot_ikine_CPP_API

#else

#if !defined(LIB_Robot_ikine_CPP_API)
#if defined(LIB_Robot_ikine_C_API)
#define LIB_Robot_ikine_CPP_API LIB_Robot_ikine_C_API
#else
#define LIB_Robot_ikine_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_Robot_ikine_CPP_API void MW_CALL_CONV Robot_ikine(int nargout, mwArray& My, const mwArray& Mx, const mwArray& q0, const mwArray& index);

extern LIB_Robot_ikine_CPP_API void MW_CALL_CONV Robot_ikine_Tool(int nargout, mwArray& My, const mwArray& Mx, const mwArray& q0, const mwArray& index, const mwArray& tool);

extern LIB_Robot_ikine_CPP_API void MW_CALL_CONV Robot_kine(int nargout, mwArray& My, const mwArray& Mx, const mwArray& index);

extern LIB_Robot_ikine_CPP_API void MW_CALL_CONV Robot_kine_Tool(int nargout, mwArray& My, const mwArray& Mx, const mwArray& index, const mwArray& Mx2);

extern LIB_Robot_ikine_CPP_API void MW_CALL_CONV Trans_Robot_Camera(int nargout, mwArray& Ty, const mwArray& T2, const mwArray& T1);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
