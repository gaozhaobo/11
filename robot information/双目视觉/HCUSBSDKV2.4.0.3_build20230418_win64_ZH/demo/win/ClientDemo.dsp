# Microsoft Developer Studio Project File - Name="ClientDemo" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=ClientDemo - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "ClientDemo.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "ClientDemo.mak" CFG="ClientDemo - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "ClientDemo - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "ClientDemo - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "ClientDemo - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../inCn" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 ../lib/HCUsbSDK.lib /nologo /subsystem:windows /pdb:"../lib/ClientDemo.pdb" /debug /machine:I386 /out:"../lib/ClientDemo.exe"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "ClientDemo - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../inCn" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 HCUsbSDK.lib /nologo /subsystem:windows /pdb:"../lib/ClientDemo.pdb" /debug /machine:I386 /out:"../lib/ClientDemo.exe" /pdbtype:sept /libpath:"../lib"
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "ClientDemo - Win32 Release"
# Name "ClientDemo - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ClientDemo.cpp
# End Source File
# Begin Source File

SOURCE=.\ClientDemo.rc
# End Source File
# Begin Source File

SOURCE=.\ClientDemoDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgActivateCard.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgBeepAndFlickerCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCardParamCfg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCardProtoCfg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateAddAddrInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateInfo.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateMac.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardEncryptCfg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardPack.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardReset.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDetectCard.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgDeviceReg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgExternalDev.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgFingerPrintOper.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgGetHairpinVer.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgICCardNo.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockAdd.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockMinus.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockToReg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1MifarePack.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1ModifySCB.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1PwdVerify.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1ReadBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1RegToBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgM1WriteBlock.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgPSAMSeatCfg.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgRFCReset.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgSetDeviceKey.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgStateSecretPublish.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgStopCardOper.cpp
# End Source File
# Begin Source File

SOURCE=.\DlgUpgrade.cpp
# End Source File
# Begin Source File

SOURCE=.\GlobalCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\SubDlgCertificateInfoInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\SubDlgCpuPsamCardInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\SubDlgDevInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\SubDlgGenInterface.cpp
# End Source File
# Begin Source File

SOURCE=.\SubDlgM1CardInterface.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ClientDemo.h
# End Source File
# Begin Source File

SOURCE=.\ClientDemoDlg.h
# End Source File
# Begin Source File

SOURCE=.\DlgActivateCard.h
# End Source File
# Begin Source File

SOURCE=.\DlgBeepAndFlickerCtrl.h
# End Source File
# Begin Source File

SOURCE=.\DlgCardParamCfg.h
# End Source File
# Begin Source File

SOURCE=.\DlgCardProtoCfg.h
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateAddAddrInfo.h
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateInfo.h
# End Source File
# Begin Source File

SOURCE=.\DlgCertificateMac.h
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardEncryptCfg.h
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardPack.h
# End Source File
# Begin Source File

SOURCE=.\DlgCPUCardReset.h
# End Source File
# Begin Source File

SOURCE=.\DlgDetectCard.h
# End Source File
# Begin Source File

SOURCE=.\DlgDeviceReg.h
# End Source File
# Begin Source File

SOURCE=.\DlgExternalDev.h
# End Source File
# Begin Source File

SOURCE=.\DlgFingerPrintOper.h
# End Source File
# Begin Source File

SOURCE=.\DlgGetHairpinVer.h
# End Source File
# Begin Source File

SOURCE=.\DlgICCardNo.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockAdd.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockMinus.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1BlockToReg.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1MifarePack.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1ModifySCB.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1PwdVerify.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1ReadBlock.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1RegToBlock.h
# End Source File
# Begin Source File

SOURCE=.\DlgM1WriteBlock.h
# End Source File
# Begin Source File

SOURCE=.\DlgPSAMSeatCfg.h
# End Source File
# Begin Source File

SOURCE=.\DlgRFCReset.h
# End Source File
# Begin Source File

SOURCE=.\DlgSetDeviceKey.h
# End Source File
# Begin Source File

SOURCE=.\DlgStateSecretPublish.h
# End Source File
# Begin Source File

SOURCE=.\DlgStopCardOper.h
# End Source File
# Begin Source File

SOURCE=.\DlgUpgrade.h
# End Source File
# Begin Source File

SOURCE=.\GlobalCtrl.h
# End Source File
# Begin Source File

SOURCE=..\inCn\HCUsbSDK.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\SubDlgCertificateInfoInterface.h
# End Source File
# Begin Source File

SOURCE=.\SubDlgCpuPsamCardInterface.h
# End Source File
# Begin Source File

SOURCE=.\SubDlgDevInterface.h
# End Source File
# Begin Source File

SOURCE=.\SubDlgGenInterface.h
# End Source File
# Begin Source File

SOURCE=.\SubDlgM1CardInterface.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\res\ClientDemo.ico
# End Source File
# Begin Source File

SOURCE=.\res\ClientDemo.rc2
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
