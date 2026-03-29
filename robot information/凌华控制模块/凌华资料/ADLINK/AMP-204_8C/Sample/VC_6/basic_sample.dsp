# Microsoft Developer Studio Project File - Name="basic_sample" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=basic_sample - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "basic_sample.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "basic_sample.mak" CFG="basic_sample - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "basic_sample - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "basic_sample - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "basic_sample - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "../../../APS Library/Include" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "NDEBUG"
# ADD RSC /l 0x404 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 APS168.lib /nologo /subsystem:windows /machine:I386 /libpath:"../../../APS Library"

!ELSEIF  "$(CFG)" == "basic_sample - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "../../../APS Library/Include" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x404 /d "_DEBUG"
# ADD RSC /l 0x404 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 APS168.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept /libpath:"../../../APS Library"

!ENDIF 

# Begin Target

# Name "basic_sample - Win32 Release"
# Name "basic_sample - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\Axis_Monitor.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_sample.cpp
# End Source File
# Begin Source File

SOURCE=.\basic_sample.rc
# End Source File
# Begin Source File

SOURCE=.\basic_sampleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CmpTrig.cpp
# End Source File
# Begin Source File

SOURCE=.\Get_Version.cpp
# End Source File
# Begin Source File

SOURCE=.\Motion.c
# End Source File
# Begin Source File

SOURCE=.\PWM_VAO.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE="..\..\..\APS Library\Include\APS168.h"
# End Source File
# Begin Source File

SOURCE="..\..\..\APS Library\Include\APS_Define.h"
# End Source File
# Begin Source File

SOURCE=.\Axis_Monitor.h
# End Source File
# Begin Source File

SOURCE=.\basic_sample.h
# End Source File
# Begin Source File

SOURCE=.\basic_sampleDlg.h
# End Source File
# Begin Source File

SOURCE=.\CmpTrig.h
# End Source File
# Begin Source File

SOURCE="..\..\..\APS Library\Include\ErrorCodeDef.h"
# End Source File
# Begin Source File

SOURCE=.\Get_Version.h
# End Source File
# Begin Source File

SOURCE=.\Motion.h
# End Source File
# Begin Source File

SOURCE=.\PWM_VAO.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE="..\..\..\APS Library\Include\type_def.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\basic_sample.ico
# End Source File
# Begin Source File

SOURCE=.\res\basic_sample.rc2
# End Source File
# Begin Source File

SOURCE=.\basic_samples.ico
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
