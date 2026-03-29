unit ADCNC;

interface

$INCLUDE 'APS168.pas' // POS_DATA_2D, PNT_DATA_2D, POINT_DATA

//Data Struct Define////////////////////////////////////////////////////////////////////////////

type VP_AVL =record
     const radius:DWord;     // radius (pulse), [1,4294967295], 0:disable
     const vmax:DWord;       // maximum velocity (pulse/s), [1,2147483647], 0:disable
end; 


type VP_CONFIG =record
         vmax:DWord;       // maximum velocity (pulse/s), [1,2147483647]
         vmin:DWord;       // minimum velocity (pulse/s), [0,2147483647]
         acc:DWord;        // acceleration rate (pulse/ss), [1,2147483647]
         dec:DWord;        // deceleration rate (pulse/ss), [1,2147483647]
         rvmax:DWord;      // rapid, maximum velocity (pulse/s), [1,2147483647]
         rvmin:DWord;      // rapid, minimum velocity (pulse/s), [0,2147483647]
         racc:DWord;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
         rdec:DWord;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
         dmin:DWord;       // parameter, minimum distance (pulse), [0,4294967295]
         omax:DWord;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
         omin:DWord;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
         opt:DWord;        // extra, option, [0,0xFFFFFFFF]
         vi:DWord;         // extra, initial velocity (pulse/s), [0,2147483647]
         ve:DWord;         // extra, ending velocity (pulse/s), [0,2147483647]
         avr:DWord;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
         avln:DWord;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
     var avlp:VP_AVL;       // extra, arc velocity limiter, array start pointer, 0:disable
end;
      
type VP_CONFIG_EXT=record
         vmax:LongWord;       // maximum velocity (pulse/s), [1,2147483647]
         vmin:LongWord;       // minimum velocity (pulse/s), [0,2147483647]
         acc:LongWord;        // acceleration rate (pulse/ss), [1,2147483647]
         dec:LongWord;        // deceleration rate (pulse/ss), [1,2147483647]
         rvmax:LongWord;      // rapid, maximum velocity (pulse/s), [1,2147483647]
         rvmin:LongWord;      // rapid, minimum velocity (pulse/s), [0,2147483647]
         racc:LongWord;       // rapid, acceleration rate (pulse/ss), [1,2147483647]
         rdec:LongWord;       // rapid, deceleration rate (pulse/ss), [1,2147483647]
         dmin:LongWord;       // parameter, minimum distance (pulse), [0,4294967295]
         omax:LongWord;       // parameter, maximum angular velocity (0.001 degree/s), [0,180000], 0:disable
         omin:LongWord;       // parameter, minimum angular velocity (0.001 degree/s), [0,180000]
         opt:LongWord;        // extra, option, [0,0xFFFFFFFF]
         vi:LongWord;         // extra, initial velocity (pulse/s), [0,2147483647]
         ve:LongWord;         // extra, ending velocity (pulse/s), [0,2147483647]
         avr:LongWord;        // extra, arc volution (vmin) radius (pulse), [1,4294967295], 0:disable
         avln:LongWord;       // extra, arc velocity limiter, array count, [1,2147483647], 0:disable
     var avlp:VP_AVL;         // extra, arc velocity limiter, array start pointer, 0:disable
         sfactor:Double;      // s-curve factor, added in 2013.7.22
end;

VP_OPT_VI      :LongWord = 0x00000001
VP_OPT_VE      :LongWord = 0x00000002
VP_OPT_AVR     :LongWord = 0x00000004
VP_OPT_AVL     :LongWord = 0x00000010
VP_OPT_DBG     :LongWord = 0x80000000
VP_OPT_DBGR    :LongWord = 0x40000000
VP_OPT_DBGW    :LongWord = 0x20000000
__Driver_Magnification_Rate :LongWord = 20


type  VP_CONFIG_SP = record
         size:LongWord;       // [IN ] special configuration, byte count, [0,sizeof(VP_CONFIG_SP)]
         x0:LongInt;         // [IN ] initial position x, [-2147483648,2147483647]
         y0:LongInt;         // [IN ] initial position y, [-2147483648,2147483647]
         nano:LongWord;       // [IN ] cycle time (nano s), [1,4294967295], 0:disable
end;
          
          
function PathOptimize( 
    pointnumber:LongWord;           // [IN ] : position array counter
    var PosArrayI:POS_DATA_2D;      // [IN ] : position array start pointer
    ToleranceError:Double;          // [IN ] : tolerance error
    var reducepointnumber:LongWord; // [OUT] : position array counter after reduction
    var PosArrayR:POS_DATA_2D_RPS;  // [OUT] : position array start pointer after reduction
    var df_tolerr:Double;           // [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
  ):Longint;stdcall;
  
function PathOptimize_F64( 
	  pointnumber:LongWord;   								// [IN ] : position array counter
	  var PosArrayI:POS_DATA_2D_F64;					// [IN ] : position array start pointer
	  ToleranceError:Double;									// [IN ] : tolerance error
	  var reducepointnumber:LongWord;   			// [OUT] : position array counter after reduction
	  var	PosArrayR:POS_DATA_2D_F64_RPS;			// [OUT] : position array start pointer after reduction
	  var df_tolerr:Double; 									// [OUT] : default tolerance error (1/10 of the minimun distance of this pattern) 
	):Longint;stdcall;												// Added in 2013.7.30
	  		
function PathSmooth(
      PosCountI:LongWord;   				// [IN ] position array count, input, [1,4294967295]
      var PosArrayI:POS_DATA_2D;   	// [IN ] position array start pointer, input, [!NULL]
      var Tolerance:LongWord;  			// [IN ] tolerance count, input, [1,4294967295]
      var PosCountO:LongWord;   		// [OUT] position array count, output, [!NULL]
      var PosArrayO:POS_DATA_2D;   	// [OUT] position array start pointer, output, [!NULL]
    ):Longint;stdcall;
    	
function VelocityPlanning(
     var VpConfig:VP_CONFIG;    	// [IN ] velocity planning configuration, [!NULL]
     PosCount:LongWord;    				// [IN ] position array count, [1,4294967295]
     var PosArray:POS_DATA_2D;    // [IN ] position array start pointer, [!NULL]
     var PntArray:PNT_DATA_2D;    // [OUT] point array start pointer, [!NULL]
    ):Longint;stdcall;
    	
function VelocityPlanningEx(
    var VpConfig:VP_CONFIG;    		// [IN ] velocity planning configuration, [!NULL]
    PosCount:LongWord;    				// [IN ] position array count, [1,4294967295]
    var PosArray:POS_DATA_2D;    	// [IN ] position array start pointer, [!NULL]
    var PntArray:PNT_DATA_2D;    	// [OUT] point array start pointer, [!NULL]
    InitialX:LongInt;    					// [IN ] initial position x, [-2147483648,2147483647]
    InitialY:LongInt;    					// [IN ] initial position y, [-2147483648,2147483647]
    ):Longint;stdcall;
    	
function VelocityPlanningSp(
     var VpConfig:VP_CONFIG;    	// [IN ] velocity planning configuration, [!NULL]
     PosCount:LongWord;  				  // [IN ] position array count, [1,4294967295]
     var PosArray:POS_DATA_2D;    // [IN ] position array start pointer, [!NULL]
     var PntArray:PNT_DATA_2D;    // [OUT] point array start pointer, [!NULL]
     var SpConfig:VP_CONFIG_SP;   // [OPT] special configuration, 0:disable
    ):Longint;stdcall;
    	
function VelocityPlanningSp_F64(
      var VpConfig:VP_CONFIG_EXT;    // [IN ] velocity planning configuration, [!NULL]
      PosCount:LongWord;             // [IN ] position array count, [1,4294967295]
      var PosArray:POS_DATA_2D_F64;  // [IN ] position array start pointer, [!NULL]
      var PntArray:PNT_DATA_2D_F64;  // [OUT] point array start pointer, [!NULL]
      var SpConfig:VP_CONFIG_SP;     // [OPT] special configuration, 0:disable
    ):Longint;stdcall;							 // Added in 2013.7.25
    	
function VelocityPlanning_Clean(void):Longint;stdcall;
function VelocityPlanning_IsEmpty(void):Longint;stdcall;
	
function VelocityPlanning_PreAlloc(
    PosCount:LongWord;    // [IN ] total position count, [1,4294967295]
    CfgCount:LongWord;    // [IN ] total configuration count, [1,4294967295]
    ):Longint;stdcall;
    	
function VelocityPlanning_PushBack(
      var VpConfig:VP_CONFIG;      // [IN ] velocity planning configuration, [!NULL]
      PosCount:LongWord;           // [IN ] position array count, [1,4294967295]
      var PosArray:POS_DATA_2D;    // [IN ] position array start pointer, [!NULL]
      IsFinish:LongInt;            // [IN ] flag for trajectory finish, 0:false, x:true
    ):Longint;stdcall;
      	
function VelocityPlanning_PopFront(
      var PntCount:LongWord;       // [OUT] point array count, [0,4294967295]
      var PntArray:PNT_DATA_2D;    // [OUT] point array start pointer, [any], 0:ignore
      var IsFinish:LongInt;        // [OUT] pointer to flag for trajectory finish, 0:false, 1:true
    ):Longint;stdcall;
    	
function VelocityPlanning_Lock(
      Interval:LongWord;                // [IN ] timeout interval in milliseconds, [0,4294967295]
      var const LockName:Byte;  // [IN ] pointer to lock name, [any], 0:anonymous
    ):Longint;stdcall;
      		
function PosData2_FileLoad(
    var const FileName:Byte;    // [IN ] file name
    var PosCount:LongWord;      // [OUT] array count
    var PosArray:POS_DATA_2D;   // [OUT] array start pointer, position data 2d
    ):Longint;stdcall;
    	
    	
function PosData2_FileLoad_F64(
    var	const FileName:Byte;        // [IN ] file name
    var PosCount:LongWord;          // [OUT] array count
    var PosArray:POS_DATA_2D_F64;   // [OUT] array start pointer, position data 2d
    ):Longint;stdcall;	
    	
function PosData2_FileSave(
    var const FileName:Byte;     // [IN ] file name
    PosCount:LongWord;           // [IN ] array count
    var PosArray:POS_DATA_2D;    // [IN ] array start pointer, position data 2d
    ):Longint;stdcall;
    	
    	
function PosData2_FileSave_F64(
      var const FileName:Byte;          // [IN ] file name
      PosCount:LongWord;                // [IN ] array count
      var PosArray:POS_DATA_2D_F64;     // [IN ] array start pointer, position data 2d
    ):Longint;stdcall;									// Added in 2013.7.25
    	
function PosData2_FileSav_LR(
      var const FileName:Byte;          // [IN ] file name
      PosCount:LongWord;                // [IN ] array count
      var PosArray:POS_DATA_2D_RPS;     // [IN ] array start pointer, position data 2d after linear regression
    ):Longint;stdcall;
    	
function PntData2_FileLoad(
      var const FileName:Byte;   // [IN ] file name
      var PntCount:LongWord;     // [OUT] array count
      var PntArray:PNT_DATA_2D;  // [OUT] array start pointer, point data 2d
    ):Longint;stdcall;
      	
      	
function PntData2_FileLoad_F64(
      var const FileName:Byte;         // [IN ] file name
      var PntCount:LongWord;           // [OUT] array count
      var PntArray:PNT_DATA_2D_F64;    // [OUT] array start pointer, point data 2d
    ):Longint;stdcall;	
    	
function PntData2_FileSave(
       var const FileName:Byte;         // [IN ] file name
       PntCount:LongWord;               // [IN ] array count
       var PntArray:PNT_DATA_2D;        // [IN ] array start pointer, point data 2d
    ):Longint;stdcall;
       	
function PntData2_FileSave_F64(
      var const FileName:Byte;         // [IN ] file name
      PntCount:LongWord;               // [IN ] array count
      var PntArray:PNT_DATA_2D_F64;    // [IN ] array start pointer, point data 2d
    ):Longint;stdcall;								 // Added in 2013.7.25

function PntDataX_FileLoad(
      var const FileName:Byte;      // [IN ] file name
      var PntCount:LongWord;        // [OUT] array count
      var PntArray:POINT_DATA;    // [OUT] array start pointer, point data
    ):Longint;stdcall;
    	
function PntDataX_FileSave(
      var const FileName:Byte;      // [IN ] file name
      PntCount:LongWord;            // [IN ] array count
      var PntArray:POINT_DATA;      // [IN ] array start pointer, point data
    ):Longint;stdcall;
    	
    	
function ADCNC_Version(void):Longint;stdcall;
	
	
ERR_CNC_NOERR              :LongWord=     0    // no error
ERR_CNC_INVALID_ARGUMENT   :LongWord= -10001    // invalid argument
ERR_CNC_INVALID_CONFIG     :LongWord= -10002    // invalid config
ERR_CNC_WAIT_FAILED        :LongWord= -10003    // internal resource lock wait failed
ERR_CNC_LOCK_FAILED        :LongWord= -10004    // lock operation is illegal or failed
ERR_CNC_MEMORY_FAILED      :LongWord= -10005    // memory operation is illegal, failed or insufficient
ERR_CNC_FILING_FAILED      :LongWord= -10006    // file operation is illegal or failed
ERR_CNC_REMAINED           :LongWord= -10007    // internal databank still remained data

	
//implementation///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
implementation
	
	
function PathOptimize; external 'ADCNC.dll';
function PathOptimize_F64; external 'ADCNC.dll';
function PathSmooth; external 'ADCNC.dll';
function VelocityPlanning; external 'ADCNC.dll';
function VelocityPlanningEx; external 'ADCNC.dll';
function VelocityPlanningSp; external 'ADCNC.dll';
function VelocityPlanningSp_F64; external 'ADCNC.dll';
function VelocityPlanning_Clean; external 'ADCNC.dll';
function VelocityPlanning_PreAlloc; external 'ADCNC.dll';
function VelocityPlanning_PushBack; external 'ADCNC.dll';
function VelocityPlanning_PopFront; external 'ADCNC.dll';
function VelocityPlanning_Lock; external 'ADCNC.dll';
function PosData2_FileLoad; external 'ADCNC.dll';
function PosData2_FileLoad_F64; external 'ADCNC.dll';
function PosData2_FileSave; external 'ADCNC.dll';
function PosData2_FileSave_F64; external 'ADCNC.dll';
function PosData2_FileSav_LR; external 'ADCNC.dll';
function PntData2_FileLoad; external 'ADCNC.dll';
function PntData2_FileLoad_F64; external 'ADCNC.dll';
function PntData2_FileSave; external 'ADCNC.dll';
function PntData2_FileSave_F64; external 'ADCNC.dll';
function PntDataX_FileLoad; external 'ADCNC.dll';
function PntDataX_FileSave; external 'ADCNC.dll';
function ADCNC_Version; external 'ADCNC.dll';


end.
