'****************************************************************************/
'*  Copyright (c) 2014, ADLink Technology Inc.  All rights reserved.        */
'*                                                                          */
'*  File Name   :   ADCNC2.vb                                               */
'*  Purpose     :   Basic function Sample  for ADCNC C# 2012                */
'*  Date        :   2014/10/27                                              */
'*  Programmer  :   Johnny Tseng	                                        */
'****************************************************************************/
Option Strict Off
Option Explicit On
Imports System.Runtime.InteropServices
Module ADNCN2

    '  Copyright  Lib "ADCNC.dll" (C) 1995-2009 Adlink Technology INC.
    '  All rights reserved.

    Structure VP_PARAM_CONFIG
        Dim u32_vmax As UInteger    ' maximum velocity (pulse/s)
        Dim u32_acc As UInteger       ' maximum acceleration (pulse/s^2)
        Dim u32_rvmax As UInteger   ' rapid, maximum velocity (pulse/s)
        Dim u32_racc As UInteger      ' rapid, maximum acceleration (pulse/s^2)
        Dim u32_corner As UInteger   ' corner velocity setting
        Dim u32_dt As UInteger         ' cycle time (unit: nano second)
        Dim u32_opt As UInteger      ' reserved
        Dim f64_sfactor As Double     ' s-curve factor
    End Structure
    Declare Function ADCNC_Velocity_Planning Lib "ADCNC.dll" (ByRef VpConfig As VP_PARAM_CONFIG, ByVal PosCount As UInt32, ByVal PosArray As IntPtr, ByVal PntArray As IntPtr) As Int32
    Declare Function ADCNC_Path_Optimize Lib "ADCNC.dll" (ByVal pointnumber As UInt32, ByVal PosArrayIn As IntPtr, ByVal ToleranceError As Double, ByRef reducepointnumber As UInt32, ByVal PosArrayOut As IntPtr, ByRef df_tolerr As Double) As Int32
    Declare Function PosData2_FileLoad_F64 Lib "ADCNC.dll" (<MarshalAsAttribute(UnmanagedType.LPWStr)> ByVal FileName As String, ByRef PosCount As UInt32, ByVal PosArray As IntPtr) As Int32
    Declare Function PosData2_FileSave_F64 Lib "ADCNC.dll" (<MarshalAsAttribute(UnmanagedType.LPWStr)> ByVal FileName As String, ByVal PosCount As UInt32, ByVal PosArray As IntPtr) As Int32
    Declare Function PntData2_FileLoad_F64 Lib "ADCNC.dll" (<MarshalAsAttribute(UnmanagedType.LPWStr)> ByVal FileName As String, ByRef PntCount As UInt32, ByVal PntArray As IntPtr) As Int32
    Declare Function PntData2_FileSave_F64 Lib "ADCNC.dll" (<MarshalAsAttribute(UnmanagedType.LPWStr)> ByVal FileName As String, ByVal PntCount As UInt32, ByVal PntArray As IntPtr) As Int32
    Declare Function ADCNC_Version Lib "ADCNC.dll" () As Int32

End Module
