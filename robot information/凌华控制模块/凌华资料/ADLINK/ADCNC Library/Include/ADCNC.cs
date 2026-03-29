using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Runtime.InteropServices;


namespace ADCNC_W32
{
     public sealed class ADLIN_Define 
     {
       public const UInt32 VP_OPT_VI     =(0x00000001);
       public const UInt32 VP_OPT_VE      =(0x00000002);
       public const UInt32 VP_OPT_AVR     =(0x00000004);
       public const UInt32 VP_OPT_AVL     =(0x00000010);
       public const UInt32 VP_OPT_DBG     = (0x80000000);
       public const UInt32 VP_OPT_DBGR    =(0x40000000);
       public const UInt32 VP_OPT_DBGW    =(0x20000000);
       public const UInt32 __Driver_Magnification_Rate = (20);
     }

     public sealed class ADLIN_ErrCode 
     {
         public const Int32 ERR_CNC_NOERR = (0);    // no error
         public const Int32 ERR_CNC_INVALID_ARGUMENT = (-10001);    // invalid argument
         public const Int32 ERR_CNC_INVALID_CONFIG = (-10002);    // invalid config
         public const Int32 ERR_CNC_WAIT_FAILED = (-10003);    // internal resource lock wait failed
         public const Int32 ERR_CNC_LOCK_FAILED = (-10004);    // lock operation is illegal or failed
         public const Int32 ERR_CNC_MEMORY_FAILED = (-10005);    // memory operation is illegal, failed or insufficient
         public const Int32 ERR_CNC_FILING_FAILED = (-10006);    // file operation is illegal or failed
         public const Int32 ERR_CNC_REMAINED = (-10007);    // internal databank still remained data
     }

	 [StructLayout(LayoutKind.Sequential, Pack = 1)]
	 public struct VP_CVL
	 {
				public UInt32 radius;     // radius (pulse), [1,4294967295], 0:disable
				public UInt32 vmax;       // maximum velocity (pulse/s), [1,2147483647], 0:disable
	 }
	 
	 [StructLayout(LayoutKind.Sequential, Pack = 1)]
	 public struct VP_CONFIG
	{
	    public UInt32     vmax;       // maximum velocity (pulse/s), [1,2147483647]
	    public UInt32     vmin;       // minimum velocity (pulse/s), [0,2147483647]
	    public UInt32     acc;        // acceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     dec;        // deceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     rvmax;      // rapid, maximum velocity (pulse/s), [1,2147483647]
	    public UInt32     rvmin;      // rapid, minimum velocity (pulse/s), [0,2147483647]
	    public UInt32     racc;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     rdec;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     dmin;       // parameter, minimum distance (pulse), [0,4294967295]
	    public UInt32     omax;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
	    public UInt32     omin;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
	    public UInt32     opt;        // extra, option, [0,0xFFFFFFFF]
	    public UInt32     vi;         // extra, initial velocity (pulse/s), [0,2147483647]
	    public UInt32     ve;         // extra, ending velocity (pulse/s), [0,2147483647]
	    public UInt32     avr;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
	    public UInt32     avln;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
        public VP_CVL     avlp;       // extra, arc velocity limiter, array start pointer, 0:disable
	}
	
	[StructLayout(LayoutKind.Sequential, Pack = 1)]
	public struct VP_CONFIG_EXT
	{
	    public UInt32     vmax;       // maximum velocity (pulse/s), [1,2147483647]
	    public UInt32     vmin;       // minimum velocity (pulse/s), [0,2147483647]
	    public UInt32     acc;        // acceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     dec;        // deceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     rvmax;      // rapid, maximum velocity (pulse/s), [1,2147483647]
	    public UInt32     rvmin;      // rapid, minimum velocity (pulse/s), [0,2147483647]
	    public UInt32     racc;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     rdec;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
	    public UInt32     dmin;       // parameter, minimum distance (pulse), [0,4294967295]
	    public UInt32     omax;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
	    public UInt32     omin;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
	    public UInt32     opt;        // extra, option, [0,0xFFFFFFFF]
	    public UInt32     vi;         // extra, initial velocity (pulse/s), [0,2147483647]
	    public UInt32     ve;         // extra, ending velocity (pulse/s), [0,2147483647]
	    public UInt32     avr;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
	    public UInt32     avln;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
        public VP_CVL     avlp;       // extra, arc velocity limiter, array start pointer, 0:disable
	    public Double     sfactor;	  // s-curve factor, added in 2013.7.22
	}

  [StructLayout(LayoutKind.Sequential, Pack = 1)]
  public struct VP_CONFIG_SP
	{
	    public UInt32     size;       // [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
	    public Int32        x0;         // [IN ] initial position x, [-2147483648,2147483647]
	    public Int32        y0;         // [IN ] initial position y, [-2147483648,2147483647]
	    public UInt32     nano;       // [IN ] cycle time (nano s), [1,4294967295], 0:disable
	}

    [StructLayout(LayoutKind.Sequential)]
    public struct POS_DATA_2D
    {
        public UInt32 u32_opt;        // option, [0x00000000,0xFFFFFFFF]
        public Int32 i32_x;          // x-axis component (pulse), [-2147483648,2147484647]
        public Int32 i32_y;          // y-axis component (pulse), [-2147483648,2147484647]
        public Int32 i32_theta;      // x-y plane arc move angle (0.000001 degree), [-360000,360000]
    }
    [StructLayout(LayoutKind.Sequential)]
    public struct POS_DATA_2D_RPS
    {
        /* This structure adds another variable to record what point was be saved */
        public UInt32 u32_opt;        // option, [0x00000000, 0xFFFFFFFF]
        public Int32 i32_x;          // x-axis component (pulse), [-2147483648, 2147483647]
        public Int32 i32_y;          // y-axis component (pulse), [-2147483648, 2147483647]
        public Int32 i32_theta;      // x-y plane arc move angle (0.000001 degree), [-360000, 360000]
        public UInt32 crpi;			     // current reading point index
    }

    public struct POS_DATA_2D_F64
    {
        /* This structure extends original point data contents from "I32" to "F64" 
                                           for internal computation. It's important to prevent data overflow. */
        public UInt32 u32_opt;        // option, [0x00000000, 0xFFFFFFFF]
        public Double f64_x;          // x-axis component (pulse), [-9223372036854775808, 9223372036854775807]
        public Double f64_y;          // y-axis component (pulse), [-9223372036854775808, 9223372036854775807]
        public Double f64_theta;      // x-y plane arc move angle (0.000001 degree), [-360000, 360000]
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct POS_DATA_2D_F64_RPS
    {
        /* This structure adds another variable to record what point was be saved */
        public UInt32 u32_opt;        // option, [0x00000000, 0xFFFFFFFF]
        public Double f64_x;          // x-axis component (pulse), [-2147483648, 2147483647]
        public Double f64_y;          // y-axis component (pulse), [-2147483648, 2147483647]
        public Double f64_theta;      // x-y plane arc move angle (0.000001 degree), [-360000, 360000]
        public UInt32 crpi;			      // current reading point index
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct PNT_DATA_2D
    {
        public UInt32 u32_opt;        // option, [0x00000000,0xFFFFFFFF]
        public Int32 i32_x;          // x-axis component (pulse), [-2147483648,2147484647]
        public Int32 i32_y;          // y-axis component (pulse), [-2147483648,2147484647]
        public Int32 i32_theta;      // x-y plane arc move angle (0.000001 degree), [-360000,360000]
        public Int32 i32_acc;        // acceleration rate (pulse/ss), [0,2147484647]
        public Int32 i32_dec;        // deceleration rate (pulse/ss), [0,2147484647]
        public Int32 i32_vi;         // initial velocity (pulse/s), [0,2147484647]
        public Int32 i32_vm;         // maximum velocity (pulse/s), [0,2147484647]
        public Int32 i32_ve;         // ending velocity (pulse/s), [0,2147484647]
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct PNT_DATA_2D_F64
    {
        public UInt32 u32_opt;        // option, [0x00000000,0xFFFFFFFF]
        public Double f64_x;          // x-axis component (pulse), [-2147483648,2147484647]
        public Double f64_y;          // y-axis component (pulse), [-2147483648,2147484647]
        public Double f64_theta;      // x-y plane arc move angle (0.000001 degree), [-360000,360000]
        public Double f64_acc;        // acceleration rate (pulse/ss), [0,2147484647]
        public Double f64_dec;        // deceleration rate (pulse/ss), [0,2147484647]
        public Double f64_vi;         // initial velocity (pulse/s), [0,2147484647]
        public Double f64_vm;         // maximum velocity (pulse/s), [0,2147484647]
        public Double f64_ve;         // ending velocity (pulse/s), [0,2147484647]
        public Double f64_sf;			   // s-factor [0.0 ~ 1.0]
    }

    [StructLayout(LayoutKind.Sequential)]
    public struct POINT_DATA
    {
        public Int32 i32_pos;		// Position data (relative or absolute) (pulse)
        public Int16 i16_accType;	// Acceleration pattern 0: T-curve,  1: S-curve
        public Int16 i16_decType;	// Deceleration pattern 0: T-curve,  1: S-curve
        public Int32 i32_acc;		// Acceleration rate ( pulse / ss )
        public Int32 i32_dec;		// Deceleration rate ( pulse / ss )
        public Int32 i32_initSpeed;	// Start velocity	( pulse / s )
        public Int32 i32_maxSpeed;	// Maximum velocity  ( pulse / s )
        public Int32 i32_endSpeed; 	// End velocity		( pulse / s )
        public Int32 i32_angle;		// Arc move angle    ( degree, -360 ~ 360 )
        public Int32 u32_dwell;		// Dwell times       ( unit: ms )
        public Int32 i32_opt;    	// Option //0xABCD , D:0 absolute, 1:relative
    }

	public class APS168
	{
			[DllImport("ADCNC.dll")]public static extern Int32 
			PathOptimize( 
				  System.UInt32					pointnumber			// [IN ] : position array counter
				, ref POS_DATA_2D			PosArrayI			// [IN ] : position array start pointer
				, System.Double					ToleranceError		// [IN ] : tolerance error
				, ref System.UInt32					reducepointnumber	// [OUT] : position array counter after reduction
				, ref POS_DATA_2D_RPS		PosArrayR			// [OUT] : position array start pointer after reduction
				, ref System.Double					df_tolerr			// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
				);
				
			  [DllImport("ADCNC.dll")]public static extern Int32 
				PathOptimize_F64( 
					   System.UInt32						pointnumber			// [IN ] : position array counter
					, ref POS_DATA_2D_F64			PosArrayI			// [IN ] : position array start pointer
					, System.Double						ToleranceError		// [IN ] : tolerance error
					, ref System.UInt32						reducepointnumber	// [OUT] : position array counter after reduction
					, ref POS_DATA_2D_F64_RPS		PosArrayR			// [OUT] : position array start pointer after reduction
					, ref System.Double						df_tolerr			// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
					);
        
              [DllImport("ADCNC.dll")]public static extern Int32 
              PathSmooth(
                  System.UInt32     PosCountI    // [IN ] position array count, input, [1,4294967295]
                , ref POS_DATA_2D PosArrayI      // [IN ] position array start pointer, input, [!NULL]
                , System.UInt32 Tolerance        // [IN ] tolerance count, input, [1,4294967295]
                , ref System.UInt32 PosCountO    // [OUT] position array count, output, [!NULL] 
                , ref POS_DATA_2D PosArrayO    // [OUT] position array start pointer, output, [!NULL]
                );

              [DllImport("ADCNC.dll")]public static extern Int32 
                VelocityPlanning(
                        ref VP_CONFIG VpConfig    // [IN ] velocity planning configuration, [!NULL]
                        , System.UInt32 PosCount    // [IN ] position array count, [1,4294967295]
                        , ref POS_DATA_2D      PosArray    // [IN ] position array start pointer, [!NULL]
                        , ref PNT_DATA_2D      PntArray    // [OUT] point array start pointer, [!NULL]
                    );

              [DllImport("ADCNC.dll")]public static extern Int32 
                VelocityPlanningEx(
                        ref VP_CONFIG VpConfig    // [IN ] velocity planning configuration, [!NULL]
                        , System.UInt32 PosCount    // [IN ] position array count, [1,4294967295]
                        , ref POS_DATA_2D PosArray    // [IN ] position array start pointer, [!NULL]
                        , ref PNT_DATA_2D PntArray    // [OUT] point array start pointer, [!NULL]
                        , System.UInt32 InitialX    // [IN ] initial position x, [-2147483648,2147483647]
                        , System.UInt32 InitialY    // [IN ] initial position y, [-2147483648,2147483647]
                    );

                [DllImport("ADCNC.dll")]public static extern Int32  
                VelocityPlanningSp(
                ref VP_CONFIG VpConfig    // [IN ] velocity planning configuration, [!NULL]
                , System.UInt32 PosCount    // [IN ] position array count, [1,4294967295]
                , ref POS_DATA_2D PosArray    // [IN ] position array start pointer, [!NULL]
                , ref PNT_DATA_2D PntArray    // [OUT] point array start pointer, [!NULL]
                , ref VP_CONFIG_SP SpConfig    // [OPT] special configuration, 0:disable
                    );

                [DllImport("ADCNC.dll")]public static extern Int32  
                    VelocityPlanningSp_F64(
                    ref VP_CONFIG_EXT VpConfig    // [IN ] velocity planning configuration, [!NULL]
                    , System.UInt32 PosCount    // [IN ] position array count, [1,4294967295]
                    , ref POS_DATA_2D_F64 PosArray    // [IN ] position array start pointer, [!NULL]
                    , ref PNT_DATA_2D_F64  PntArray    // [OUT] point array start pointer, [!NULL]
                    , ref VP_CONFIG_SP SpConfig    // [OPT] special configuration, 0:disable
                        );

                [DllImport("ADCNC.dll")]public static extern Int32 
                    VelocityPlanning_Clean();

                 [DllImport("ADCNC.dll")]public static extern Int32 
                   VelocityPlanning_IsEmpty();

                [DllImport("ADCNC.dll")]public static extern Int32 
                VelocityPlanning_PreAlloc(
                        System.UInt32 PosCount    // [IN ] total position count, [1,4294967295]
                        , System.UInt32 CfgCount    // [IN ] total configuration count, [1,4294967295]
                    );

                 [DllImport("ADCNC.dll")]public static extern Int32  
                    VelocityPlanning_PushBack(
                    ref VP_CONFIG VpConfig    // [IN ] velocity planning configuration, [!NULL]
                    , System.UInt32 PosCount    // [IN ] position array count, [1,4294967295]
                    , ref POS_DATA_2D PosArray    // [IN ] position array start pointer, [!NULL]
                    , System.UInt32 IsFinish    // [IN ] flag for trajectory finish, 0:false, x:true
                        );

                 [DllImport("ADCNC.dll")]public static extern Int32  
                    VelocityPlanning_PopFront(
                    ref System.UInt32 PntCount    // [OUT] point array count, [0,4294967295]
                    , ref PNT_DATA_2D PntArray    // [OUT] point array start pointer, [any], 0:ignore
                    , ref System.UInt32 IsFinish    // [OUT] pointer to flag for trajectory finish, 0:false, 1:true
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32 
                    VelocityPlanning_Lock(
                          System.UInt32               Interval    // [IN ] timeout interval in milliseconds, [0,4294967295]
                        , ref char       LockName    // [IN ] pointer to lock name, [any], 0:anonymous
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32 
                    PosData2_FileLoad(
                    ref char FileName    // [IN ] file name
                    , ref System.UInt32 PosCount    // [OUT] array count
                    , ref POS_DATA_2D PosArray    // [OUT] array start pointer, position data 2d
                        );

                     [DllImport("ADCNC.dll")]public static extern Int32 
                        PosData2_FileLoad_F64(
                        ref char FileName    // [IN ] file name
                        , ref System.UInt32 PosCount    // [OUT] array count
                        , ref POS_DATA_2D_F64 PosArray    // [OUT] array start pointer, position data 2d
                            );


                    [DllImport("ADCNC.dll")]public static extern Int32 
                    PosData2_FileSave(
                    ref char FileName    // [IN ] file name
                    ,System.UInt32 PosCount    // [IN ] array count
                    , ref POS_DATA_2D PosArray    // [IN ] array start pointer, position data 2d
                        );

                     [DllImport("ADCNC.dll")]public static extern Int32 
                        PosData2_FileSave_F64(
                        ref char FileName    // [IN ] file name
                            , System.UInt32					PosCount    // [IN ] array count
                            , ref POS_DATA_2D_F64      PosArray    // [IN ] array start pointer, position data 2d
                            );
            	
                     [DllImport("ADCNC.dll")]public static extern Int32
                    PosData2_FileSav_LR(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PosCount    // [IN ] array count
                    , ref POS_DATA_2D_RPS  PosArray    // [IN ] array start pointer, position data 2d after linear regression
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32
                    PntData2_FileLoad(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PntCount    // [OUT] array count
                    , ref PNT_DATA_2D PntArray    // [OUT] array start pointer, point data 2d
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32
                    PntData2_FileLoad_F64(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PntCount    // [OUT] array count
                    , ref  PNT_DATA_2D_F64 PntArray    // [OUT] array start pointer, point data 2d
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32     
                    PntData2_FileSave(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PntCount    // [IN ] array count
                    , ref PNT_DATA_2D PntArray    // [IN ] array start pointer, point data 2d
                        );

                     [DllImport("ADCNC.dll")]public static extern Int32  
                    PntData2_FileSave_F64(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PntCount    // [IN ] array count
                    , ref PNT_DATA_2D_F64 PntArray    // [IN ] array start pointer, point data 2d
                        );

                     [DllImport("ADCNC.dll")]public static extern Int32 
                    PntDataX_FileLoad(
                    ref char FileName    // [IN ] file name
                    , ref System.UInt32  PntCount    // [OUT] array count
                        , ref POINT_DATA      PntArray    // [OUT] array start pointer, point data
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32 
                    PntDataX_FileSave(
                    ref char FileName    // [IN ] file name
                    , System.UInt32 PntCount    // [IN ] array count
                    , ref POINT_DATA PntArray    // [IN ] array start pointer, point data
                        );

                    [DllImport("ADCNC.dll")]public static extern Int32 
                    ADCNC_Version();
    }
}