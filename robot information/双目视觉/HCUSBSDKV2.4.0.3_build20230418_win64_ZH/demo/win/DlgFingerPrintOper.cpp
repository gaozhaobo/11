// DlgFingerPrintOper.cpp : implementation file
//

#include "stdafx.h"
#include "clientdemo.h"
#include "DlgFingerPrintOper.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgFingerPrintOper dialog
int HIK_WriteBmp(char *fileName, unsigned char *imageData, int width, int height);

CDlgFingerPrintOper::CDlgFingerPrintOper(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFingerPrintOper::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgFingerPrintOper)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_lUserID=-1;
    m_byFPCompareTimeout=0;
    m_byFPTemplateQuality=0;
    m_byWait=10;
    m_byQulity=0;
}


void CDlgFingerPrintOper::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgFingerPrintOper)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
    DDX_Control(pDX,IDC_COMBO_PRINT_OPER,m_comboFPCompareType);
    DDX_Control(pDX,IDC_COMBO_CAPTURE_TYPE,m_comboFPCaptureType);
    DDX_Text(pDX,IDC_EDIT_TIMEOUT,m_byFPCompareTimeout);
    DDX_Control(pDX,IDC_COMBO_MATCH_LEVEL,m_comboFPCompareMatchLevel);
    DDX_Control(pDX,IDC_COMBO_COMPARE_RS,m_comboResult);
    DDX_Text(pDX,IDC_EDIT_FP_QUALITY,m_byFPTemplateQuality);
    DDX_Text(pDX,IDC_EDIT_WAIT,m_byWait);
    DDX_Control(pDX,IDC_COMBO_FPTYPE,m_FPType);
    DDX_Control(pDX,IDC_COMBO_RESULT,m_comboCaptureResult);
    DDX_Text(pDX,IDC_EDIT_FP_TEMP_QUALITY,m_byQulity);
    DDX_Text(pDX,IDC_EDIT_FRINT_INFO,m_csFPBuffer);
}


BEGIN_MESSAGE_MAP(CDlgFingerPrintOper, CDialog)
	//{{AFX_MSG_MAP(CDlgFingerPrintOper)
	ON_BN_CLICKED(IDC_BTN_SET, OnBtnSet)
	ON_BN_CLICKED(IDC_BTN_GET, OnBtnGet)
	ON_BN_CLICKED(IDC_BTN_CAPTURE, OnBtnCapture)
	//}}AFX_MSG_MAP
    ON_WM_PAINT()
END_MESSAGE_MAP()

BOOL CDlgFingerPrintOper::OnInitDialog()
{
    CDialog::OnInitDialog();

    if (g_bEnglish)
    {
        m_comboFPCompareType.InsertString(0, _T("No"));
        m_comboFPCompareType.InsertString(1, _T("Device"));
        m_comboFPCompareType.InsertString(2, _T("Platform"));
    }
    else
    {
        m_comboFPCompareType.InsertString(0, _T("不比对"));
        m_comboFPCompareType.InsertString(1, _T("设备内部对比"));
        m_comboFPCompareType.InsertString(2, _T("平台对比"));
    }

    if (g_bEnglish)
    {
        m_comboFPCaptureType.InsertString(0, _T("Template"));
        m_comboFPCaptureType.InsertString(1, _T("Picture"));
    }
    else
    {
        m_comboFPCaptureType.InsertString(0, _T("模板"));
        m_comboFPCaptureType.InsertString(1, _T("图片"));
    }

    if (g_bEnglish)
    {
        m_comboResult.InsertString(0, _T("Successful"));
        m_comboResult.InsertString(1, _T("Failed"));
        m_comboResult.InsertString(2, _T("Timeout"));
        m_comboResult.InsertString(3, _T("Poor fingerprint image quality"));
        m_comboResult.InsertString(4, _T("The 1:1 comparison between the two failed"));
        m_comboResult.InsertString(5, _T("Emptying failed"));
        m_comboResult.InsertString(6, _T("Failed to generate fingerprint feature"));
    }
    else
    {
        m_comboResult.InsertString(0, _T("比对成功"));
        m_comboResult.InsertString(1, _T("比对失败"));
        m_comboResult.InsertString(2, _T("比对超时"));
        m_comboResult.InsertString(3, _T("指纹图像质量差"));
        m_comboResult.InsertString(4, _T("两者1:1对比失败"));
        m_comboResult.InsertString(5, _T("清空失败"));
        m_comboResult.InsertString(6, _T("生成指纹特征失败"));
    }

    if (g_bEnglish)
    {
        m_FPType.InsertString(0, _T("Template"));
        m_FPType.InsertString(1, _T("Picture"));
    }
    else
    {
        m_FPType.InsertString(0, _T("模板"));
        m_FPType.InsertString(1, _T("图片"));
    }

    if (g_bEnglish)
    {
        m_comboCaptureResult.InsertString(0, _T("Successful"));
        m_comboCaptureResult.InsertString(1, _T("Failed"));
        m_comboCaptureResult.InsertString(2, _T("Timeout"));
        m_comboCaptureResult.InsertString(3, _T("Poor fingerprint image quality"));
    }
    else
    {
        m_comboCaptureResult.InsertString(0, _T("比对成功"));
        m_comboCaptureResult.InsertString(1, _T("比对失败"));
        m_comboCaptureResult.InsertString(2, _T("比对超时"));
        m_comboCaptureResult.InsertString(3, _T("指纹图像质量差"));
    }

    UpdateData(FALSE);
    return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CDlgFingerPrintOper message handlers

void CDlgFingerPrintOper::OnBtnSet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_FINGER_PRINT_OPER_PARAM struFingerOper = {0};
    struFingerOper.dwSize = sizeof(struFingerOper);
    struFingerOper.byFPCompareType = m_comboFPCompareType.GetCurSel();
    struFingerOper.byFPCaptureType=m_comboFPCaptureType.GetCurSel()+1;
    struFingerOper.byFPCompareTimeout=m_byFPCompareTimeout;
    struFingerOper.byFPCompareMatchLevel=m_comboFPCompareMatchLevel.GetCurSel()+1;
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struFingerOper);
    struInput.lpInBuffer = &struFingerOper;
    
    if (USB_SetDeviceConfig(m_lUserID, USB_SET_FINGER_PRINT_OPER_PARAM, &struInput, NULL))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_SetDeviceConfig()  Command = USB_SET_FINGER_PRINT_OPER_PARAM");
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_SetDeviceConfig()  Command = USB_SET_FINGER_PRINT_OPER_PARAM");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
}

void CDlgFingerPrintOper::OnBtnGet() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);
    
    USB_FINGER_PRINT_CONTRAST_RESULT struFingerResult = {0};
    struFingerResult.dwSize = sizeof(struFingerResult);
    
    USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
    
    struConfigOutputInfo.dwOutBufferSize = sizeof(struFingerResult);
    struConfigOutputInfo.lpOutBuffer = &struFingerResult;
    
    if (USB_GetDeviceConfig(m_lUserID, USB_GET_FINGER_PRINT_CONTRAST_RESULT, NULL, &struConfigOutputInfo))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command =USB_GET_FINGER_PRINT_CONTRAST_RESULT");
        
        m_comboResult.SetCurSel(struFingerResult.byResult-1);
        m_byFPTemplateQuality = struFingerResult.byFPTemplateQuality;
        UpdateData(FALSE);
    }
    else
    {
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_GET_FINGER_PRINT_CONTRAST_RESULT");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
    }
    
    return;
}

void CDlgFingerPrintOper::OnBtnCapture() 
{
	// TODO: Add your control notification handler code here
    UpdateData(TRUE);

    if (m_byWait < 10 || m_byWait > 60)
    {
#ifdef SWITCH_ENGLISH_US
        MessageBox("Operate Wait Time (from 10s to 60s, default 60s)");
#else
        MessageBox("操作等待时间（范围10s-60s，不设置时默认为60s）");
#endif
        return;
    }
	
    USB_FINGER_PRINT_COND struCond = {0};
    struCond.dwSize = sizeof(USB_FINGER_PRINT_COND);
    struCond.byWait = m_byWait;
    struCond.byFPType = m_FPType.GetCurSel() + 1;

	char* pFPBuffer=new char[MAX_FINGER_PRINT];
	memset(pFPBuffer,0,MAX_FINGER_PRINT);
    USB_FINGER_PRINT struFingerCapture = {0};
    struFingerCapture.dwSize = sizeof(USB_FINGER_PRINT);
    struFingerCapture.pFPBuffer = pFPBuffer;
	struFingerCapture.dwFPBufferSize =MAX_FINGER_PRINT;
    
    USB_CONFIG_INPUT_INFO struInput = {0};
    struInput.dwInBufferSize = sizeof(struCond);
    struInput.lpInBuffer = &struCond;
    
    USB_CONFIG_OUTPUT_INFO struOutput = {0};
    struOutput.dwOutBufferSize = sizeof(struFingerCapture);
    struOutput.lpOutBuffer = &struFingerCapture;

    if (USB_GetDeviceConfig(m_lUserID, USB_CAPTURE_FINGER_PRINT, &struInput, &struOutput))
    {
        LOGIN_INFO->WriteLog(INF_LEVEL, "SUCCESS USB_GetDeviceConfig()  Command = USB_CAPTURE_FINGER_PRINT");
        m_FPType.SetCurSel(struFingerCapture.byFPType-1);
		if (struFingerCapture.byFPType==1)
		{
			m_byQulity=struFingerCapture.byFPTemplateQuality;
		}
		m_comboCaptureResult.SetCurSel(struFingerCapture.byResult-1);
		if(struFingerCapture.byFPType==2&&struFingerCapture.byResult==1)
		{
            HIK_WriteBmp("fp.bmp", (unsigned char *)pFPBuffer, 256, 360);

            //定义变量存储图片信息
            BYTE *pBmpData;             //图像数据
            BITMAPFILEHEADER bmpHeader; //文件头
            BITMAPINFOHEADER bmpInfo;   //信息头
            CFile bmpFile;              //记录打开文件
            
            //以只读的方式打开文件 读取bmp图片各部分 bmp文件头 信息 数据
            if(!bmpFile.Open("fp.bmp", CFile::modeRead|CFile::typeBinary)) 
                return;
            if (bmpFile.Read(&bmpHeader,sizeof(BITMAPFILEHEADER)) != sizeof(BITMAPFILEHEADER))
                return;
            if (bmpFile.Read(&bmpInfo,sizeof(BITMAPINFOHEADER)) != sizeof(BITMAPINFOHEADER))
                return;
            //为图像数据申请空间
            DWORD dataBytes = bmpHeader.bfSize - bmpHeader.bfOffBits;
            pBmpData = (BYTE*)new char[dataBytes];
            bmpFile.Read(pBmpData,dataBytes);
            bmpFile.Close();

            typedef struct tagBITMAPINFO_X
            {
                BITMAPINFOHEADER  bmiHeader;
                RGBQUAD           bmiColors[256];
            } BITMAPINFO_X;
            BITMAPINFO_X pBmpInfoEx;  
            memcpy(&pBmpInfoEx.bmiHeader,&bmpInfo,sizeof(BITMAPINFOHEADER));
            //构造灰度图的调色版（此处为重点）
            for(int i=0;i<256;i++)
            {
                pBmpInfoEx.bmiColors[i].rgbBlue=i;
                pBmpInfoEx.bmiColors[i].rgbGreen=i;
                pBmpInfoEx.bmiColors[i].rgbRed=i;
                pBmpInfoEx.bmiColors[i].rgbReserved=0;
            }
            
            //显示图像
            CWnd *pWnd=GetDlgItem(IDC_EDIT_FRINT_INFO); //获得pictrue控件窗口的句柄
            //CRect rect;
            //pWnd->GetClientRect(&rect); //获得pictrue控件所在的矩形区域
            CDC *pDC=pWnd->GetDC(); //获得pictrue控件的DC
            pDC->SetStretchBltMode(HALFTONE);
            StretchDIBits(pDC->GetSafeHdc(),0,0,256,360,0,0,
				256,360,pBmpData,(BITMAPINFO*)(&pBmpInfoEx),DIB_RGB_COLORS,SRCCOPY);
		}
		if (pFPBuffer!=NULL)
		{
            delete []pFPBuffer;
			pFPBuffer=NULL;
		}
		UpdateData(FALSE);
    }
    else
    {
        CString csInfo;
        LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED USB_GetDeviceConfig()  Command = USB_CAPTURE_FINGER_PRINT");
        DWORD dwError = USB_GetLastError();
        LOGIN_INFO->WriteLog(INF_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
		if (pFPBuffer!=NULL)
		{
            delete []pFPBuffer;
			pFPBuffer=NULL;
		}		
    }
}

/***************************************************************************************************
* 功  能：
*           保存BMP位图图像
* 参  数：
*           fileName    - I     图像文件名
*           imageData   - I     图像原始数据，第一个像素为图像左上角第一个像素
*           height	    - I     图像高度
*           width       - I     图像宽度
* 返回值：
*            0 —— 保存成功
*           -1 —— 保存失败
*           -9 —— 参数为NULL
***************************************************************************************************/
int HIK_WriteBmp(char *fileName, unsigned char *imageData, int width, int height)
{
	FILE *fp;
	int i, k;
	int flag;
	int linebytes;
	unsigned char *p;
	unsigned char tempbuffer[54]={
		0x42, 0x4d,				// 文件头BM
		0x00, 0x00, 0x00, 0x00,	// 文件大小
		0x00, 0x00,				// 保留1
		0x00, 0x00,				// 保留2
		0x36, 0x04, 0x00, 0x00,	// 位图数据偏移

		0x28, 0x00, 0x00, 0x00,	// 信息头大小
		0x00, 0x00, 0x00, 0x00,	// 图像宽度
		0x00, 0x00, 0x00, 0x00,	// 图像高度
		0x01, 0x00,				// 视图数
		0x08, 0x00,				// 位深
		0x00, 0x00, 0x00, 0x00,	// 压缩方式
		0x00, 0x00, 0x00, 0x00,	// 图像大小
		0x00, 0x00, 0x00, 0x00,	// 水平分辨率
		0x00, 0x00, 0x00, 0x00,	// 垂直分辨率
		0x00, 0x00, 0x00, 0x00,	// 颜色数
		0x00, 0x00, 0x00, 0x00	// 重要颜色数
	};

	if (fileName == NULL || imageData == NULL)
	{
		return (-9);
	}

	if (width <= 0 || width >= 1024 || height <= 0 || height >= 1024)
	{
		return (-9);
	}

	fp = fopen(fileName, "wb");

	if (fp == NULL)
	{
		return (-1);
	}

	// 每行字节数
	linebytes = (width + 3) / 4 * 4;

	// 文件大小
	k = linebytes * height + 1078;
	tempbuffer[2] = k & 0xff;
	k >>= 8;
	tempbuffer[3] = k & 0xff;
	k >>= 8;
	tempbuffer[4] = k & 0xff;
	k >>= 8;
	tempbuffer[5] = k & 0xff;

	// 图像宽度
	k = width;
	tempbuffer[18] = k & 0xff;
	k >>= 8;
	tempbuffer[19] = k & 0xff;
	k >>= 8;
	tempbuffer[20] = k & 0xff;
	k >>= 8;
	tempbuffer[21] = k & 0xff;

	// 图像高度
	k = height;
	tempbuffer[22] = k & 0xff;
	k >>= 8;
	tempbuffer[23] = k & 0xff;
	k >>= 8;
	tempbuffer[24] = k & 0xff;
	k >>= 8;
	tempbuffer[25] = k & 0xff;

	// 写文件头和信息头
	fwrite(tempbuffer, 1, 54, fp);

	// 写调色板
	for (i = 0; i < 256; i++)
	{
		fputc(i, fp);
		fputc(i, fp);
		fputc(i, fp);
		fputc(0, fp);
	}

	// 写位图数据

	if (linebytes == width)
	{
		flag = 0;
	}
	else
	{
		flag = 1;
	}

	p = imageData + (height-1) * width;
	if (flag)
	{
		for (i = 0; i < height; i++)
		{
			fwrite(p, 1, width, fp);

			for (k = 0; k < linebytes-width; k++)
			{
				fputc(0, fp);
			}

			p -= width;
		}
	}
	else
	{
		for (i = 0; i < height; i++)
		{
			fwrite(p, 1, width, fp);

			p -= width;
		}
	}

	fclose(fp);

	return (0);
}


void CDlgFingerPrintOper::OnPaint()
{
    CPaintDC dc(this); // device context for painting
    // TODO:  在此处添加消息处理程序代码
    // 不为绘图消息调用 CDialog::OnPaint()
    SET_DLG_LAN(IDD_DLG_FINGER_PRINT);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC1);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC2);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC3);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC4);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC5);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC6);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC7);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC8);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC9);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC10);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC11);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC12);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC13);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_STATIC14);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_BTN_SET);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_BTN_GET);
    SET_CONTROL_LAN(IDD_DLG_FINGER_PRINT, IDC_BTN_CAPTURE);
}
