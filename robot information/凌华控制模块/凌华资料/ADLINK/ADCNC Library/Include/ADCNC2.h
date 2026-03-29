#ifndef   _ADCNC2_H_
#define   _ADCNC2_H_

/*
** necessary including
*/
#include "type_def.h"



/* Configuration for Velocity Planning */
typedef struct _VP_PARAM_CONFIG
{
    U32     vmax;       // maximum velocity (pulse/s)
    U32     acc;        // maximum acceleration (pulse/s^2)
    U32     rvmax;      // rapid, maximum velocity (pulse/s)
    U32     racc;       // rapid, maximum acceleration (pulse/s^2)
	U32     corner;     // corner velocity setting
	U32     dt;         // cycle time (unit: nano second)
	U32     opt;        // reserved
	F64		sfactor;	// s-curve factor
}
VP_PARAM_CONFIG, *PVP_PARAM_CONFIG;



/* Function Prototype */
#ifdef __cplusplus
extern "C" {
#endif

I32 __stdcall
ADCNC_Velocity_Planning(
      VP_PARAM_CONFIG*		VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32					PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D_F64*      PosArray    // [IN ] position array start pointer, [!NULL]
    , PNT_DATA_2D_F64*      PntArray    // [OUT] point array start pointer, [!NULL]
    );



I32 __stdcall 
ADCNC_Path_Optimize( 
	  U32						pointnumber			// [IN ] : position array counter
	, POS_DATA_2D_F64*			PosArrayIn			// [IN ] : position array start pointer
	, F64						ToleranceError		// [IN ] : tolerance error
	, U32*						reducepointnumber	// [OUT] : position array counter after reduction
	, POS_DATA_2D_F64*          PosArrayOut			// [OUT] : position array start pointer after reduction
	, F64*						df_tolerr			// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
	);



I32 __stdcall
PosData2_FileLoad_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32*					PosCount    // [OUT] array count
    , POS_DATA_2D_F64*      PosArray    // [OUT] array start pointer, position data 2d
    );


I32 __stdcall
PosData2_FileSave_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32					PosCount    // [IN ] array count
    , POS_DATA_2D_F64*      PosArray    // [IN ] array start pointer, position data 2d
    );


I32 __stdcall
PntData2_FileLoad_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32*					PntCount    // [OUT] array count
    , PNT_DATA_2D_F64*      PntArray    // [OUT] array start pointer, point data 2d
    );	


I32 __stdcall
PntData2_FileSave_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32					PntCount    // [IN ] array count
    , PNT_DATA_2D_F64*      PntArray    // [IN ] array start pointer, point data 2d
    );	


I32 __stdcall
ADCNC_Version(void);

#ifdef __cplusplus
}
#endif


/* Error Code */
#define  ERR_CNC_NOERR              (     0)    // no error
#define  ERR_CNC_INVALID_ARGUMENT   (-10001)    // invalid argument
#define  ERR_CNC_INVALID_CONFIG     (-10002)    // invalid config
#define  ERR_CNC_FILING_FAILED      (-10006)    // file operation is illegal or failed


#endif