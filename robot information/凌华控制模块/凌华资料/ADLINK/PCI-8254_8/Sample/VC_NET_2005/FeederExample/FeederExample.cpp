// FeederExample.cpp : Defines the entry point for the console application.
//

#include "windows.h"
#include "APS168.h"
#include "ErrorCodeDef.h"
#include "ADCNC.h"
#include <stdlib.h>	//system
#include <stdio.h>	//printf


// Functions prototype
PNT_DATA_2D* __LoadTableFromFile( I32 *Cnt );
POS_DATA_2D* LoadPosFromFile( I32 *Cnt );

#define		_YES	(1)
#define		_NO		(0)

//#define		_GET_SMOOTH_FINAL_CNT_METHOD_1	
#define	_GET_SMOOTH_FINAL_CNT_METHOD_2

#define _DEBUG_LOG

int main()
{
	I32 ret;				// Return code.
	I32 boardID_InBits = 0; // Return board ID in bit format.
	I32 mode		   = 0;	// Initail mode
	I32 cardId		   = 0;	// Device ID
	I32 groupId        = 0;	// Feeder group ID [0,1]
	// I32 groupId      = 1; //Feeder group ID [0,1]

	I32 isSmooth	   = _YES;	// Path smooth or not
	POS_DATA_2D* pPos  = NULL;  // Pointer of POS_DATA_2D
	PNT_DATA_2D* pPnt  = NULL;	// Pointer of PNT_DATA_2D
	I32 cnt            = 0;		// Size of array

	I32 m_dim	= 2;	// Dimension of axes
	I32 m_axisX = 0;
	I32 m_axisY = 1;

	I32 tmp[2]  = 
	{ m_axisX,		// First point table axis, (Control axis)
	  m_axisY	};	// Second axis, (Slave axis)

	// Initial Card.
	ret = APS_initial( &boardID_InBits, mode );
	
	if( ret != ERR_NoError )
	{
		printf( "APS initial failed.\n" );
		goto RELEASE;
	}

	//Load configure setting from XML file.
	/*ret = APS_load_param_from_file( "param.xml" );
	if( ret != ERR_NoError )
	{
		printf( "Load parameters from XML failed.\n" );
		goto RELEASE;
	}*/


	// Set axes servo ON
	APS_set_servo_on( m_axisX, 1 );
	APS_set_servo_on( m_axisY, 1 );

	Sleep(10);
	// Check axes servo ON

	// Check motion status is normal
	

	//*********** Load point data (2D) from file. *****************
	pPos = LoadPosFromFile( &cnt );

	




	if( pPos == NULL )
	{
		printf( "Load point from file failed.\n" );
		goto RELEASE;
	}

	//*********** Path smooth operation ***************************
	if( isSmooth == _YES )
	{
		I32  err		= 0;
		U32  final		= 0;
		U32  tolerance	= 50;
		POS_DATA_2D*  q = 0;

#ifdef _GET_SMOOTH_FINAL_CNT_METHOD_1
		// Get final counts
		err = PathSmooth(
				  cnt         // [IN ] position array count, input, [1,0xFFFFFFFF]
				, pPos          // [IN ] position array start pointer, input, [!NULL]
				, tolerance     // [IN ] tolerance count input, [1,0xFFFFFFFF]
				, &final        // [OUT] position array count, output, [0,0xFFFFFFFF]
				, 0             // [OUT] position array start pointer, output
				);

		if( err != 0 ) 
		{ 
			printf( "PathSmooth() return error: %d.\n", err );
			goto RELEASE; 
		}
#elif defined( _GET_SMOOTH_FINAL_CNT_METHOD_2 )
		//This method is more efficient
		final = 2 * cnt; //This value may be large than actual value.
#endif

		q = (POS_DATA_2D*) calloc(final, sizeof(POS_DATA_2D));

		err = PathSmooth(
				  cnt         // [IN ] position array count, input, [1,0xFFFFFFFF]
				, pPos        // [IN ] position array start pointer, input, [!NULL]
				, tolerance   // [IN ] tolerance count input, [1,0xFFFFFFFF]
				, &final      // [OUT] position array count, output, [0,0xFFFFFFFF]
				, q           // [OUT] position array start pointer, output
				);

		if( err != 0 ) 
		{ 
			free( q );
			q = NULL;
			printf( "PathSmooth() return error: %d.\n", err );
			goto RELEASE; 
		}

#ifdef _DEBUG_LOG
// Safe file for debug used
{
	static const wchar_t  __fileo[] = L"pos1_ps.txt";
    ret = PosData2_FileSave(
			  __fileo  // [IN ] file name
			, final      // [IN ] point array count
			, q     // [IN ] point start pointer
			);

    if( ret ) 
	{ 
		printf( "PosData2_FileSave() return error: %d.\n", ret );
		goto RELEASE;  
	}
}
#endif

		// Let "pPts" point to new array
		free( pPos );
		pPos = q;
		
		cnt = final;
	}

	//*********** Velocity planning operation *******************
    VP_CONFIG     cfg;
	memset( &cfg, 0, sizeof(VP_CONFIG) );

    cfg.vmax =  10000;  // maximum velocity (pulse/s), [1,0xFFFFFFFF]
    cfg.vmin =   2000;  // minimum velocity (pulse/s), [0,0xFFFFFFFF]
    cfg.acc  =  20000;  // acceleration rate (pulse/ss), [1,0xFFFFFFFF]
    cfg.dmin =      0;  // parameter, minimum distance (pulse), [0,0xFFFFFFFF]
    cfg.dec  =  20000;  // deceleration rate (pulse/ss), [1,0xFFFFFFFF]
	cfg.racc = 200000;
	cfg.rdec = 200000;
//    cfg.omax = 175000;  // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
//    cfg.omin =  30000;  // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    cfg.opt  =      0;  // extra parameter, option, [0,0xFFFFFFFF]


	pPnt = (PNT_DATA_2D*)calloc( cnt, sizeof(PNT_DATA_2D) );
	
	if ( 0 == pPnt ) 
	{
		printf( "Memory alloc failed." );
		goto RELEASE; 
    }

    ret = VelocityPlanning(
			  &cfg   // [IN ] velocity planning configuration, [!NULL]
			, cnt    // [IN ] position array count, [1,0xFFFFFFFF]
			, pPos   // [IN ] position array start pointer, [!NULL]
			, pPnt   // [OUT] point array start pointer, [!NULL]
			);

    if( ret != 0 ) 
	{ 
		printf( "VelocityPlanning() return error: %d.\n", ret );
		goto RELEASE;  
	}

#ifdef _DEBUG_LOG
	// Safe file for debug used
{
	static const wchar_t  __fileo[] = L"pnt1_vp.txt";
    ret = PntData2_FileSave(
			  __fileo  // [IN ] file name
			, cnt      // [IN ] point array count
			, pPnt     // [IN ] point start pointer
			);

    if( ret ) 
	{ 
		printf( "PntData2_FileSave() return error: %d.\n", ret );
		goto RELEASE;  
	}
}
#endif


	//********** Set feeder group *************************
		
	ret = APS_set_feeder_group( groupId, m_dim, tmp );
	if( ret != ERR_NoError )
	{
		printf( "Set feeder group failed.\n" );
		goto RELEASE;
	}

	//*********** Load point table to feeder *******************
	//*********** Set Last flag ********************************
	ret = APS_set_feeder_point_2D( groupId, pPnt, cnt, 1 );

	if( ret != ERR_NoError )
	{
		printf( "APS_set_feeder_points failed. Ret:%d \n", ret );
		goto RELEASE;
	}

	//*********** Start feeder and point table move *************
	ret = APS_start_feeder_move( groupId );
	if( ret != ERR_NoError )
	{
		printf( "APS_start_feeder_move failed. Ret:%d \n", ret );
		goto RELEASE;
	}

	//********* Check process is finish *************************
	I32 runIdx;
	I32 fedIdx;
	I32 msts;
	do 
	{
		ret = APS_get_feeder_running_index( groupId, &runIdx);
		if( ret != ERR_NoError ) break;
		ret = APS_get_feeder_feed_index( groupId, &fedIdx);
		if( ret != ERR_NoError ) break;
		
		msts = APS_motion_status( tmp[0] );
		
		system("cls");
		printf( "RunIndex:%d  FeedIndex:%d \n", runIdx, fedIdx );
		printf( "Axis %d MSTS: 0x%08x \n", tmp[0], msts );
		Sleep(300);
		fedIdx--; 
		
		if( msts & 0x10000 )
		{
			printf( "Abnormal stop!. \n" );
			break;
		}
	}while( runIdx != fedIdx && ( msts & 0x3800 ) );

	printf( "Point table move finish!. \n" );

RELEASE:

	if( pPos != NULL )
	{
		free( pPos );
		pPos = NULL;
	}
	
	if( pPnt != NULL )
	{
		free( pPnt );
		pPnt = NULL;
	}

	//***** Release feeder gorup ********************************
	ret = APS_free_feeder_group( groupId );
	if( ret != ERR_NoError )
	{
		printf( "APS_free_feeder_group() failed. Ret:%d \n", ret );
	}

	//****** Close devices ***************************************
	APS_close();

	system( "pause" );
	return 0;
}


PNT_DATA_2D* __LoadTableFromFile( I32 *Cnt )
{
	static const wchar_t  __filei[] = L"pnt1.txt";
	I32		err;
	U32		cnt = 0;

	*Cnt = 0;

    err =
    PntData2_FileLoad(
      __filei   // [IN ] file name
    , &cnt      // [OUT] position table array count
    , 0         // [OUT] position table array start pointer
    );

    if ( 0 == cnt ) 
	{
        printf( "File open failed.\n" );
        return NULL;
    }

    PNT_DATA_2D* const  p = (PNT_DATA_2D*) calloc(cnt, sizeof(PNT_DATA_2D));

    if ( 0 == p ) 
	{
        printf( "Memory alloc failed." );
        return NULL;
    }

    err =
    PntData2_FileLoad(
      __filei   // [IN ] file name
    , &cnt      // [OUT] position table array count
    , p         // [OUT] position table array start pointer
    );

	*Cnt = cnt;

	return p;
}


POS_DATA_2D* LoadPosFromFile( I32 *Cnt )
{
    static const wchar_t  __filei[] = L"pos1.txt";
    I32           err = 0;		// Return code
    U32           cnt = 0;		// position data count
    POS_DATA_2D*  p   = NULL;	// position array


    err = PosData2_FileLoad(
			  __filei   // [IN ] file name
			, &cnt      // [OUT] position table array count
			, 0         // [OUT] position table array start pointer
			);
    
	if( err != 0   || 
		0   == cnt   ) 
	{
		printf( "File open failed.\n" );
		return NULL;
	}

    p = (POS_DATA_2D*) calloc( cnt, sizeof(POS_DATA_2D) );

    if ( 0 == p ) 
	{
        printf( "Memory alloc failed." );
        return NULL;
    }

    err = PosData2_FileLoad(
			  __filei   // [IN ] file name
			, &cnt      // [OUT] position table array count
			, p         // [OUT] position table array start pointer
			);

    if( err ) 
	{ 
		printf( "File open failed.\n" );
		return NULL;
	}

	*Cnt = cnt;
	return p;



}