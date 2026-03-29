#include <stdlib.h> // system, calloc, free
#include <stdio.h>  // printf
#include <memory.h> // memset

#include "ADCNC.h"

static 
I32 __PathOptimize_VelocityPlanning_Test(void)
{
    static const char     __title[] = "__PathOptimize_VelocityPlanning_F64_Test";
    static const wchar_t  __filei[] = L".\\pnt1_vp_1_high.txt";
	static const wchar_t  __filer[] = L".\\pnt1_vp_1_high_reduced.txt";
    static const wchar_t  __fileo[] = L".\\pnt1_vp_1_high_result.txt";

	static const I32  InitialX = 0;
    static const I32  InitialY = 0;

	I32						err;
	U32						cnt, final, i;
    const char*				msg;
	VP_CONFIG_EXT			cfg;
    VP_CONFIG_SP			sp;
	POS_DATA_2D*			p;
	POS_DATA_2D_F64_RPS*	r;
	POS_DATA_2D_F64*		pf;
	POS_DATA_2D_F64*		pfr;
	PNT_DATA_2D_F64*		q;

	F64 ToleranceError = 10.0, 
		df_tolerror;


	/* Read file to check how many data points in CAM file (no parse data) */
	cnt = 0;
    msg = 0;
	
	err = PosData2_FileLoad( __filei, &cnt, 0 );
	if ( err ) { msg = "PosData2_FileLoad, 1"; goto _QUIT_; }

    if ( 0 == cnt ) {  err = -1;  msg = "cnt=0, file is empty or mismatch format";  goto _QUIT_;  }

	// Allocate memory to p
	p = (POS_DATA_2D*) calloc(cnt, sizeof(POS_DATA_2D));

	if ( 0 == p ) {  err = -2;  msg = "p=0, calloc fail";  goto _QUIT_;  }

	/* Read file again to parse data content (command, x, y, and theta) */
	err = PosData2_FileLoad( __filei, &cnt, p );
    if ( err ) { msg = "PosData2_FileLoad, 2"; goto _ERR_1_; }


	/* Transform from I32 to F64 numerical data structure */
	pf = (POS_DATA_2D_F64*) calloc(cnt, sizeof(POS_DATA_2D_F64));
	for ( i=0; i<cnt; i++ )  {
		pf[i].u32_opt = p[i].u32_opt;
		pf[i].f64_x	= p[i].i32_x;	pf[i].f64_y	= p[i].i32_y;	pf[i].f64_theta = p[i].i32_theta;
	}
	/**********************************
	*  Part 1:						  *
	*     Execute path optimization	  *
	**********************************/
	err = PathOptimize_F64(  cnt,  pf,  ToleranceError,  &final,  0,  &df_tolerror  );
	if ( err ) { msg = "PathPotimize fail"; goto _ERR_2_; }

	// Allocate memory to r
	r = (POS_DATA_2D_F64_RPS*) calloc(final, sizeof(POS_DATA_2D_F64_RPS));

	if ( 0 == r ) {
        err = -3;
        msg = "q=0, calloc fail";
       goto _ERR_2_;
    }

	err = PathOptimize_F64(  cnt,  pf,  ToleranceError,  &final,  r,  &df_tolerror  );
	if ( err ) { msg = "PathPotimize fail"; goto _ERR_2_; }



	/**********************************
	*  Part 2:						  *
	*     Execute Velocity Planning	  *
	**********************************/
    cfg.vmax  =  800000; // maximum velocity (pulse/s), [1,4294967295]
    cfg.vmin  =   4000	* __Driver_Magnification_Rate; // minimum velocity (pulse/s), [0,4294967295]
    cfg.acc   =  5000000; // acceleration rate (pulse/ss), [1,4294967295]
    cfg.dec   =  5000000; // deceleration rate (pulse/ss), [1,4294967295]
    cfg.rvmax =  10000000; // rapid, maximum velocity (pulse/s), [1,4294967295]
    cfg.rvmin =  4000	* __Driver_Magnification_Rate; // rapid, minimum velocity (pulse/s), [0,4294967295]
    cfg.racc  =  20000000; // rapid, acceleration rate (pulse/ss), [1,4294967295]
    cfg.rdec  =  20000000; // rapid, deceleration rate (pulse/ss), [1,4294967295]
    cfg.dmin  =      0; // parameter, minimum distance (pulse), [0,4294967295]
    cfg.omax  = 0; // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
    cfg.omin  =  0; // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
    cfg.opt   =      0; // extra, option, [0,0xFFFFFFFF]
	cfg.sfactor = 0.3;

//	cfg.opt |= VP_OPT_DBG;      // enable debug

    memset(&sp, 0, sizeof(sp));
    sp.size = sizeof(sp);   // [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
    sp.x0   = InitialX;     // [IN ] initial position x, [-2147483648,2147483647]
    sp.y0   = InitialY;     // [IN ] initial position y, [-2147483648,2147483647]
	sp.nano = 0;

	// Allocate memory to pfr
	pfr = (POS_DATA_2D_F64*) calloc(final, sizeof(POS_DATA_2D_F64));
	for ( i=0; i < final; i++ )  {
		pfr[i].u32_opt	= r[i].u32_opt;
		pfr[i].f64_x = r[i].f64_x;	pfr[i].f64_y = r[i].f64_y;	pfr[i].f64_theta = r[i].f64_theta;
	}

	// Allocate memory to q
    q = (PNT_DATA_2D_F64*) calloc(final, sizeof(PNT_DATA_2D_F64));

	err = VelocityPlanningSp_F64( &cfg,  final, 
								  pfr,  q, 
								  &sp 
								  );
    if ( err ) { msg = "VelocityPlanningEx"; goto _ERR_3_; }



	// Output the results
    err =
    PntData2_FileSave_F64(
      __fileo           // [IN ] file name
    , final             // [IN ] point array count
    , q                 // [IN ] point start pointer
    );
    if ( err ) { msg = "PntData2_FileSave"; goto _ERR_3_; }


// Release memory to operating system
_ERR_3_:
	free(pfr);
    free(q);
_ERR_2_:
    free(r);
_ERR_1_:
    free(p);
_QUIT_:
    if ( err ) {
        printf("[ERROR] %s, err=%d, %s\n", __title, err, msg);
    }
	return err;
}

int __cdecl
main(int argc, char* argv[])
{
 	__PathOptimize_VelocityPlanning_Test();

	system("PAUSE");
	return 0;
}