using System;
using System.Drawing;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;
using System.Data;
using System.Runtime.InteropServices;
using APS168_W32;
using APS_Define_W32;

namespace ADCNC2_W32
{
    //ADLINK Struct++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
    [StructLayout(LayoutKind.Sequential)]
    public struct VP_PARAM_CONFIG
    {
        public  UInt32     vmax;       // maximum velocity (pulse/s)
        public  UInt32     acc;        // maximum acceleration (pulse/s^2)
        public  UInt32     rvmax;      // rapid, maximum velocity (pulse/s)
        public  UInt32     racc;       // rapid, maximum acceleration (pulse/s^2)
	    public  UInt32     corner;     // corner velocity setting
	    public  UInt32     dt;         // cycle time (unit: nano second)
	    public  UInt32     opt;        // reserved
	    public  Double		sfactor;	// s-curve factor
    }



    public class ADCNC2
	{
        [DllImport("ADCNC.dll")]
        public static extern Int32 ADCNC_Velocity_Planning(ref VP_PARAM_CONFIG VpConfig, System.UInt32 PosCount, IntPtr PosArray, IntPtr PntArray);
        [DllImport("ADCNC.dll")]
        public static extern Int32 ADCNC_Path_Optimize(System.UInt32 pointnumber, IntPtr PosArrayIn, System.Double ToleranceError, ref System.UInt32 reducepointnumber, IntPtr PosArrayOut, ref System.Double df_tolerr);
        [DllImport("ADCNC.dll")]
        public static extern Int32 PosData2_FileLoad_F64([MarshalAsAttribute(UnmanagedType.LPWStr)]string FileName, ref UInt32 PosCount, IntPtr  PosArray);
        [DllImport("ADCNC.dll")]
        public static extern Int32 PosData2_FileSave_F64([MarshalAsAttribute(UnmanagedType.LPWStr)]string FileName, System.UInt32 PosCount, IntPtr PosArray);
        [DllImport("ADCNC.dll")]
        public static extern Int32 PntData2_FileLoad_F64([MarshalAsAttribute(UnmanagedType.LPWStr)]string FileName, ref System.UInt32 PntCount, ref POS_DATA_2D_F64 PntArray);
        [DllImport("ADCNC.dll")]
        public static extern Int32 PntData2_FileSave_F64([MarshalAsAttribute(UnmanagedType.LPWStr)]string FileName, System.UInt32 PntCount, IntPtr PntArray);
        [DllImport("ADCNC.dll")]  
        public static extern Int32 ADCNC_Version();
    }
       
    
}
