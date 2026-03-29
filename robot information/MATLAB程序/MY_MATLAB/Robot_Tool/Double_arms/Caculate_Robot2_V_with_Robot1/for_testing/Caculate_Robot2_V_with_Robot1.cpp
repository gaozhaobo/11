//
// MATLAB Compiler: 8.0 (R2020a)
// Date: Mon Jan  6 19:36:48 2025
// Arguments:
// "-B""macro_default""-W""cpplib:Caculate_Robot2_V_with_Robot1,all,version=1.0"
// "-T""link:lib""-d""D:\MATLAB
// 2020\MY_MATLAB\Robot_Tool\Double_arms\Caculate_Robot2_V_with_Robot1\for_testi
// ng""-v""D:\MATLAB 2020\MY_MATLAB\Robot_Tool\Caculate_Robot2_V_with_Robot1.m"
//

#define EXPORTING_Caculate_Robot2_V_with_Robot1 1
#include "Caculate_Robot2_V_with_Robot1.h"

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
#ifndef LIB_Caculate_Robot2_V_with_Robot1_C_API
#define LIB_Caculate_Robot2_V_with_Robot1_C_API /* No special import/export declaration */
#endif

LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV Caculate_Robot2_V_with_Robot1InitializeWithHandlers(
    mclOutputHandlerFcn error_handler,
    mclOutputHandlerFcn print_handler)
{
    int bResult = 0;
    if (_mcr_inst)
        return true;
    if (!mclmcrInitialize())
        return false;
    if (!GetModuleFileName(GetModuleHandle("Caculate_Robot2_V_with_Robot1"), path_to_dll, _MAX_PATH))
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

LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV Caculate_Robot2_V_with_Robot1Initialize(void)
{
    return Caculate_Robot2_V_with_Robot1InitializeWithHandlers(mclDefaultErrorHandler, 
                                                             mclDefaultPrintHandler);
}

LIB_Caculate_Robot2_V_with_Robot1_C_API 
void MW_CALL_CONV Caculate_Robot2_V_with_Robot1Terminate(void)
{
    if (_mcr_inst)
        mclTerminateInstance(&_mcr_inst);
}

LIB_Caculate_Robot2_V_with_Robot1_C_API 
void MW_CALL_CONV Caculate_Robot2_V_with_Robot1PrintStackTrace(void) 
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


LIB_Caculate_Robot2_V_with_Robot1_C_API 
bool MW_CALL_CONV mlxCaculate_Robot2_V_with_Robot1(int nlhs, mxArray *plhs[], int nrhs, 
                                                   mxArray *prhs[])
{
    return mclFeval(_mcr_inst, "Caculate_Robot2_V_with_Robot1", nlhs, plhs, nrhs, prhs);
}

LIB_Caculate_Robot2_V_with_Robot1_CPP_API 
void MW_CALL_CONV Caculate_Robot2_V_with_Robot1(int nargout, mwArray& V_qF, mwArray& 
                                                V_qL1, const mwArray& q1, const mwArray& 
                                                q2, const mwArray& tool1, const mwArray& 
                                                tool2, const mwArray& V1, const mwArray& 
                                                t_offset)
{
    mclcppMlfFeval(_mcr_inst, "Caculate_Robot2_V_with_Robot1", nargout, 2, 6, &V_qF, &V_qL1, &q1, &q2, &tool1, &tool2, &V1, &t_offset);
}

