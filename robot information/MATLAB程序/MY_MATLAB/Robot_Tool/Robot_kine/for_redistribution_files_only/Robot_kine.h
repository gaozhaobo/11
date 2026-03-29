//
// MATLAB Compiler: 8.0 (R2020a)
// Date: Fri Jan 10 15:33:34 2025
// Arguments:
// "-B""macro_default""-W""cpplib:Robot_kine,all,version=1.0""-T""link:lib""-d""
// D:\MATLAB2020\MY_MATLAB\Robot_Tool\Robot_kine\for_testing""-v""D:\MATLAB2020\
// MY_MATLAB\Robot_Tool\Caculate_Robot2_V_with_Robot1.m""D:\MATLAB2020\MY_MATLAB
// \Robot_Tool\Caculate_Robot2_V_with_Robot1_2.m""D:\MATLAB2020\MY_MATLAB\Robot_
// Tool\Caculate_Robot2_V_with_Robot1_continue.m""D:\MATLAB2020\MY_MATLAB\Robot_
// Tool\Robot_ikine.m""D:\MATLAB2020\MY_MATLAB\Robot_Tool\Robot_ikine_Tool.m""D:
// \MATLAB2020\MY_MATLAB\Robot_Tool\Robot_kine.m""D:\MATLAB2020\MY_MATLAB\Robot_
// Tool\Robot_kine_Tool.m""D:\MATLAB2020\MY_MATLAB\Robot_Tool\Trans_Robot_Camera
// .m"
//

#ifndef Robot_kine_h
#define Robot_kine_h 1

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
#ifndef LIB_Robot_kine_C_API 
#define LIB_Robot_kine_C_API /* No special import/export declaration */
#endif

/* GENERAL LIBRARY FUNCTIONS -- START */

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV Robot_kineInitializeWithHandlers(
       mclOutputHandlerFcn error_handler, 
       mclOutputHandlerFcn print_handler);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV Robot_kineInitialize(void);

extern LIB_Robot_kine_C_API 
void MW_CALL_CONV Robot_kineTerminate(void);

extern LIB_Robot_kine_C_API 
void MW_CALL_CONV Robot_kinePrintStackTrace(void);

/* GENERAL LIBRARY FUNCTIONS -- END */

/* C INTERFACE -- MLX WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- START */

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxCaculate_Robot2_V_with_Robot1(int nlhs, mxArray *plhs[], int nrhs, 
                                                   mxArray *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxCaculate_Robot2_V_with_Robot1_2(int nlhs, mxArray *plhs[], int nrhs, 
                                                     mxArray *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxCaculate_Robot2_V_with_Robot1_continue(int nlhs, mxArray *plhs[], 
                                                            int nrhs, mxArray *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxRobot_ikine(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxRobot_ikine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxRobot_kine(int nlhs, mxArray *plhs[], int nrhs, mxArray *prhs[]);

extern LIB_Robot_kine_C_API 
bool MW_CALL_CONV mlxRobot_kine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                     *prhs[]);

extern LIB_Robot_kine_C_API 
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

#ifdef EXPORTING_Robot_kine
#define PUBLIC_Robot_kine_CPP_API __declspec(dllexport)
#else
#define PUBLIC_Robot_kine_CPP_API __declspec(dllimport)
#endif

#define LIB_Robot_kine_CPP_API PUBLIC_Robot_kine_CPP_API

#else

#if !defined(LIB_Robot_kine_CPP_API)
#if defined(LIB_Robot_kine_C_API)
#define LIB_Robot_kine_CPP_API LIB_Robot_kine_C_API
#else
#define LIB_Robot_kine_CPP_API /* empty! */ 
#endif
#endif

#endif

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Caculate_Robot2_V_with_Robot1(int nargout, mwArray& V_qF, mwArray& V_qL1, const mwArray& q1, const mwArray& q2, const mwArray& tool1, const mwArray& tool2, const mwArray& V1, const mwArray& t_offset);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Caculate_Robot2_V_with_Robot1_2(int nargout, mwArray& V_qF, mwArray& V_qL1, const mwArray& q1, const mwArray& q2, const mwArray& tool1, const mwArray& tool2, const mwArray& V1, const mwArray& T_offset);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Caculate_Robot2_V_with_Robot1_continue(int nargout, mwArray& vec_V_qF, mwArray& vec_V_qL, const mwArray& q1, const mwArray& q2, const mwArray& tool1, const mwArray& tool2, const mwArray& V1, const mwArray& T_offset, const mwArray& single_time, const mwArray& step_nums);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Robot_ikine(int nargout, mwArray& My, const mwArray& Mx, const mwArray& q0, const mwArray& index);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Robot_ikine_Tool(int nargout, mwArray& My, const mwArray& Mx, const mwArray& q0, const mwArray& index, const mwArray& tool);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Robot_kine(int nargout, mwArray& My, const mwArray& Mx, const mwArray& index);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Robot_kine_Tool(int nargout, mwArray& My, const mwArray& Mx, const mwArray& index, const mwArray& Mx2);

extern LIB_Robot_kine_CPP_API void MW_CALL_CONV Trans_Robot_Camera(int nargout, mwArray& Ty, const mwArray& T2, const mwArray& T1);

/* C++ INTERFACE -- WRAPPERS FOR USER-DEFINED MATLAB FUNCTIONS -- END */
#endif

#endif
