//
// MATLAB Compiler: 8.0 (R2020a)
// Date: Fri Jan  3 17:07:36 2025
// Arguments:
// "-B""macro_default""-W""cpplib:Robot_ikine_Tool,all,version=1.0""-T""link:lib
// ""-d""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\test\Robot_ikine_Tool\for_testing""-v""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\Robot_ikine_Tool.m"
//

#define EXPORTING_Robot_ikine_Tool 1
#include "Robot_ikine_Tool.h"

static HMCRINSTANCE _mcr_inst = NULL; /* don't use nullptr; this may be either C or C++ */

#if defined( _MSC_VER) || defined(__LCC__) || defined(__MINGW64__)
#ifdef __LCC__
#undef EXTERN_C
#endif
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif
#define NOMINMAX
#include <windows.h>
#undef interface

static char path_to_dll[_MAX_PATH];

BOOL WINAPI DllMain(HINSTANCE hInstance, DWORD dwReason, void *pv)
{
    if (dwReason == DLL_PROCESS_ATTACH)
    {
        if (GetModuleFileName(hInstance, path_to_dll, _MAX_PATH) == 0)
            return FALSE;
    }
    else if (dwReason == DLL_PROCESS_DETACH)
    {
    }
    return TRUE;
}
#endif
#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

static int mclDefaultPrintHandler(const char *s)
{
    return mclWrite(1 /* stdout */, s, sizeof(char)*strlen(s));
}

#ifdef __cplusplus
} /* End extern C block */
#endif

#ifdef __cplusplus
extern "C" { // sbcheck:ok:extern_c
#endif

static int mclDefaultErrorHandler(const char *s)
{
    int written = 0;
    size_t len = 0;
    len = strlen(s);
    written = mclWrite(2 /* stderr */, s, sizeof(char)*len);
    if (len > 0 && s[ len-1 ] != '\n')
        written += mclWrite(2 /* stderr */, "\n", sizeof(char));
    return written;
}

#ifdef __cplusplus
} /* End extern C block */
#endif

/* This symbol is defined in shared libraries. Define it here
 * (to nothing) in case this isn't a shared library. 
 */
#ifndef LIB_Robot_ikine_Tool_C_API
#define LIB_Robot_ikine_Tool_C_API /* No special import/export declaration */
#endif

LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV Robot_ikine_ToolInitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("Robot_ikine_Tool"), path_to_dll, _MAX_PATH))
        return false;
    {
        mclCtfStream ctfStream = 
            mclGetEmbeddedCtfStream(path_to_dll);
        if (ctfStream) {
            bResult = mclInitializeComponentInstanceEmbedded(&_mcr_inst,
                                                             error_handler, 
                                                             print_handler,
                                                             ctfStream);
            mclDestroyStream(ctfStream);
        } else {
            bResult = 0;
        }
    }  
    if (!bResult)
    return false;
    return true;
}

LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV Robot_ikine_ToolInitialize(void)
{
    return Robot_ikine_ToolInitializeWithHandlers(mclDefaultErrorHandler, 
                                                mclDefaultPrintHandler);
}

LIB_Robot_ikine_Tool_C_API 
void MW_CALL_CONV Robot_ikine_ToolTerminate(void)
{
    if (_mcr_inst)
        mclTerminateInstance(&_mcr_inst);
}

LIB_Robot_ikine_Tool_C_API 
void MW_CALL_CONV Robot_ikine_ToolPrintStackTrace(void) 
{
    char** stackTrace;
    int stackDepth = mclGetStackTrace(&stackTrace);
    int i;
    for(i=0; i<stackDepth; i++)
    {
        mclWrite(2 /* stderr */, stackTrace[i], sizeof(char)*strlen(stackTrace[i]));
        mclWrite(2 /* stderr */, "\n", sizeof(char)*strlen("\n"));
    }
    mclFreeStackTrace(&stackTrace, stackDepth);
}


LIB_Robot_ikine_Tool_C_API 
bool MW_CALL_CONV mlxRobot_ikine_Tool(int nlhs, mxArray *plhs[], int nrhs, mxArray 
                                      *prhs[])
{
    return mclFeval(_mcr_inst, "Robot_ikine_Tool", nlhs, plhs, nrhs, prhs);
}

LIB_Robot_ikine_Tool_CPP_API 
void MW_CALL_CONV Robot_ikine_Tool(int nargout, mwArray& My, const mwArray& Mx, const 
                                   mwArray& q0, const mwArray& index, const mwArray& tool)
{
    mclcppMlfFeval(_mcr_inst, "Robot_ikine_Tool", nargout, 1, 4, &My, &Mx, &q0, &index, &tool);
}

