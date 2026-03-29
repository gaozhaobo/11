// ADCNC.h: Adlink CNC Library
////////////////////////////////////////////////////////////////////////////////

#ifndef   _AD_CNC_H_
#define   _AD_CNC_H_   ADLINK Technology Inc.

/*
** necessary including
*/
#include "type_def.h"   // POS_DATA_2D, PNT_DATA_2D, POINT_DATA

// array element, arc velocity limiter
//
typedef struct _VP_AVL
{
    U32     radius;     // radius (pulse), [1,4294967295], 0:disable
    U32     vmax;       // maximum velocity (pulse/s), [1,2147483647], 0:disable
}
VP_AVL, *PVP_AVL;

typedef  const VP_AVL   VP_CVL, *PVP_CVL;

// configuration, velocity planning
//
typedef struct _VP_CONFIG
{
    U32     vmax;       // maximum velocity (pulse/s), [1,2147483647]
    U32     vmin;       // minimum velocity (pulse/s), [0,2147483647]
    U32     acc;        // acceleration rate (pulse/ss), [1,2147483647]
    U32     dec;        // deceleration rate (pulse/ss), [1,2147483647]
    U32     rvmax;      // rapid, maximum velocity (pulse/s), [1,2147483647]
    U32     rvmin;      // rapid, minimum velocity (pulse/s), [0,2147483647]
    U32     racc;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
    U32     rdec;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
    U32     dmin;       // parameter, minimum distance (pulse), [0,4294967295]
    U32     omax;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
    U32     omin;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    U32     opt;        // extra, option, [0,0xFFFFFFFF]
    U32     vi;         // extra, initial velocity (pulse/s), [0,2147483647]
    U32     ve;         // extra, ending velocity (pulse/s), [0,2147483647]
    U32     avr;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
    U32     avln;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
    VP_CVL* avlp;       // extra, arc velocity limiter, array start pointer, 0:disable
}
VP_CONFIG, *PVP_CONFIG;

typedef struct _VP_CONFIG_EXT
{
    U32     vmax;       // maximum velocity (pulse/s), [1,2147483647]
    U32     vmin;       // minimum velocity (pulse/s), [0,2147483647]
    U32     acc;        // acceleration rate (pulse/ss), [1,2147483647]
    U32     dec;        // deceleration rate (pulse/ss), [1,2147483647]
    U32     rvmax;      // rapid, maximum velocity (pulse/s), [1,2147483647]
    U32     rvmin;      // rapid, minimum velocity (pulse/s), [0,2147483647]
    U32     racc;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
    U32     rdec;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
    U32     dmin;       // parameter, minimum distance (pulse), [0,4294967295]
    U32     omax;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
    U32     omin;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    U32     opt;        // extra, option, [0,0xFFFFFFFF]
    U32     vi;         // extra, initial velocity (pulse/s), [0,2147483647]
    U32     ve;         // extra, ending velocity (pulse/s), [0,2147483647]
    U32     avr;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
    U32     avln;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
    VP_CVL* avlp;       // extra, arc velocity limiter, array start pointer, 0:disable

	F64		sfactor;	// s-curve factor, added in 2013.7.22
}
VP_CONFIG_EXT, *PVP_CONFIG_EXT;
// option
//
#define  VP_OPT_VI      (0x00000001)
#define  VP_OPT_VE      (0x00000002)
#define  VP_OPT_AVR     (0x00000004)
#define  VP_OPT_AVL     (0x00000010)
#define  VP_OPT_DBG     (0x80000000)
#define  VP_OPT_DBGR    (0x40000000)
#define  VP_OPT_DBGW    (0x20000000)
#define  __Driver_Magnification_Rate		20

// special configuration, velocity planning
//
typedef struct _VP_CONFIG_SP
{
    U32     size;       // [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
    I32     x0;         // [IN ] initial position x, [-2147483648,2147483647]
    I32     y0;         // [IN ] initial position y, [-2147483648,2147483647]
    U32     nano;       // [IN ] cycle time (nano s), [1,4294967295], 0:disable
}
VP_CONFIG_SP, *PVP_CONFIG_SP;

/*
** function prototype
*/
#ifdef __cplusplus
extern "C" {
#endif

I32 __stdcall 
PathOptimize( 
	  U32					pointnumber			// [IN ] : position array counter
	, POS_DATA_2D*			PosArrayI			// [IN ] : position array start pointer
	, F64					ToleranceError		// [IN ] : tolerance error
	, U32*					reducepointnumber	// [OUT] : position array counter after reduction
	, POS_DATA_2D_RPS*		PosArrayR			// [OUT] : position array start pointer after reduction
	, F64*					df_tolerr			// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
	);

I32 __stdcall 
PathOptimize_F64( 
	  U32						pointnumber			// [IN ] : position array counter
	, POS_DATA_2D_F64*			PosArrayI			// [IN ] : position array start pointer
	, F64						ToleranceError		// [IN ] : tolerance error
	, U32*						reducepointnumber	// [OUT] : position array counter after reduction
	, POS_DATA_2D_F64_RPS*		PosArrayR			// [OUT] : position array start pointer after reduction
	, F64*						df_tolerr			// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
	);												// Added in 2013.7.30

I32 __stdcall
PathSmooth(
      U32               PosCountI   // [IN ] position array count, input, [1,4294967295]
    , POS_DATA_2D*      PosArrayI   // [IN ] position array start pointer, input, [!NULL]
    , U32               Tolerance   // [IN ] tolerance count, input, [1,4294967295]
    , U32*              PosCountO   // [OUT] position array count, output, [!NULL]
    , POS_DATA_2D*      PosArrayO   // [OUT] position array start pointer, output, [!NULL]
    );

// standalone trajectory (single configuration)
//
I32 __stdcall
VelocityPlanning(
      VP_CONFIG*        VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32               PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D*      PosArray    // [IN ] position array start pointer, [!NULL]
    , PNT_DATA_2D*      PntArray    // [OUT] point array start pointer, [!NULL]
    );

I32 __stdcall
VelocityPlanningEx(
      VP_CONFIG*        VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32               PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D*      PosArray    // [IN ] position array start pointer, [!NULL]
    , PNT_DATA_2D*      PntArray    // [OUT] point array start pointer, [!NULL]
    , I32               InitialX    // [IN ] initial position x, [-2147483648,2147483647]
    , I32               InitialY    // [IN ] initial position y, [-2147483648,2147483647]
    );

I32 __stdcall
VelocityPlanningSp(
      VP_CONFIG*        VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32               PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D*      PosArray    // [IN ] position array start pointer, [!NULL]
    , PNT_DATA_2D*      PntArray    // [OUT] point array start pointer, [!NULL]
    , VP_CONFIG_SP*     SpConfig    // [OPT] special configuration, 0:disable
    );


I32 __stdcall
VelocityPlanningSp_F64(
      VP_CONFIG_EXT*			VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32					PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D_F64*      PosArray    // [IN ] position array start pointer, [!NULL]
    , PNT_DATA_2D_F64*      PntArray    // [OUT] point array start pointer, [!NULL]
    , VP_CONFIG_SP*			SpConfig    // [OPT] special configuration, 0:disable
    );									// Added in 2013.7.25

// parted trajectory (several configurations)
//
I32 __stdcall
VelocityPlanning_Clean(void);

I32 __stdcall
VelocityPlanning_IsEmpty(void);

I32 __stdcall
VelocityPlanning_PreAlloc(
      U32               PosCount    // [IN ] total position count, [1,4294967295]
    , U32               CfgCount    // [IN ] total configuration count, [1,4294967295]
    );

I32 __stdcall
VelocityPlanning_PushBack(
      VP_CONFIG*        VpConfig    // [IN ] velocity planning configuration, [!NULL]
    , U32               PosCount    // [IN ] position array count, [1,4294967295]
    , POS_DATA_2D*      PosArray    // [IN ] position array start pointer, [!NULL]
    , I32               IsFinish    // [IN ] flag for trajectory finish, 0:false, x:true
    );

I32 __stdcall
VelocityPlanning_PopFront(
      U32*              PntCount    // [OUT] point array count, [0,4294967295]
    , PNT_DATA_2D*      PntArray    // [OUT] point array start pointer, [any], 0:ignore
    , I32*              IsFinish    // [OUT] pointer to flag for trajectory finish, 0:false, 1:true
    );

I32 __stdcall
VelocityPlanning_Lock(
      U32               Interval    // [IN ] timeout interval in milliseconds, [0,4294967295]
    , const char*       LockName    // [IN ] pointer to lock name, [any], 0:anonymous
    );

// filing
//
I32 __stdcall
PosData2_FileLoad(
      const wchar_t*    FileName    // [IN ] file name
    , U32*              PosCount    // [OUT] array count
    , POS_DATA_2D*      PosArray    // [OUT] array start pointer, position data 2d
    );

I32 __stdcall
PosData2_FileLoad_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32*					PosCount    // [OUT] array count
    , POS_DATA_2D_F64*      PosArray    // [OUT] array start pointer, position data 2d
    );									// Added in 2013.7.25

I32 __stdcall
PosData2_FileSave(
      const wchar_t*    FileName    // [IN ] file name
    , U32               PosCount    // [IN ] array count
    , POS_DATA_2D*      PosArray    // [IN ] array start pointer, position data 2d
    );

I32 __stdcall
PosData2_FileSave_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32					PosCount    // [IN ] array count
    , POS_DATA_2D_F64*      PosArray    // [IN ] array start pointer, position data 2d
    );									// Added in 2013.7.25

I32 __stdcall
PosData2_FileSav_LR(
      const wchar_t*		FileName    // [IN ] file name
    , U32					PosCount    // [IN ] array count
    , POS_DATA_2D_RPS*      PosArray    // [IN ] array start pointer, position data 2d after linear regression
    );

I32 __stdcall
PntData2_FileLoad(
      const wchar_t*    FileName    // [IN ] file name
    , U32*              PntCount    // [OUT] array count
    , PNT_DATA_2D*      PntArray    // [OUT] array start pointer, point data 2d
    );

I32 __stdcall
PntData2_FileLoad_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32*					PntCount    // [OUT] array count
    , PNT_DATA_2D_F64*      PntArray    // [OUT] array start pointer, point data 2d
    );									// Added in 2013.7.25

I32 __stdcall
PntData2_FileSave(
      const wchar_t*    FileName    // [IN ] file name
    , U32               PntCount    // [IN ] array count
    , PNT_DATA_2D*      PntArray    // [IN ] array start pointer, point data 2d
    );

I32 __stdcall
PntData2_FileSave_F64(
      const wchar_t*		FileName    // [IN ] file name
    , U32					PntCount    // [IN ] array count
    , PNT_DATA_2D_F64*      PntArray    // [IN ] array start pointer, point data 2d
    );									// Added in 2013.7.25

I32 __stdcall
PntDataX_FileLoad(
      const wchar_t*    FileName    // [IN ] file name
    , U32*              PntCount    // [OUT] array count
    , POINT_DATA*       PntArray    // [OUT] array start pointer, point data
    );

I32 __stdcall
PntDataX_FileSave(
      const wchar_t*    FileName    // [IN ] file name
    , U32               PntCount    // [IN ] array count
    , POINT_DATA*       PntArray    // [IN ] array start pointer, point data
    );

// miscellaneous
//
I32 __stdcall
ADCNC_Version(void);

#ifdef __cplusplus
}
#endif

// error number
//
#define  ERR_CNC_NOERR              (     0)    // no error
#define  ERR_CNC_INVALID_ARGUMENT   (-10001)    // invalid argument
#define  ERR_CNC_INVALID_CONFIG     (-10002)    // invalid config
#define  ERR_CNC_WAIT_FAILED        (-10003)    // internal resource lock wait failed
#define  ERR_CNC_LOCK_FAILED        (-10004)    // lock operation is illegal or failed
#define  ERR_CNC_MEMORY_FAILED      (-10005)    // memory operation is illegal, failed or insufficient
#define  ERR_CNC_FILING_FAILED      (-10006)    // file operation is illegal or failed
#define  ERR_CNC_REMAINED           (-10007)    // internal databank still remained data


#endif // _AD_CNC_H_
