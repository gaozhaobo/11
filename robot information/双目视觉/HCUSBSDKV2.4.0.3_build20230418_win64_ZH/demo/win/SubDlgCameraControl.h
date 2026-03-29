#pragma once
#include "resource.h"
#include "afxwin.h"

#define IDC_BASE			10000
#define IDC_EDIT_BEGIN		(IDC_BASE + 1)
#define IDC_EDIT_END		(IDC_BASE + 20)
#define IDC_BT_CHECK_BEGIN	(IDC_EDIT_END + 1)
#define IDC_BT_CHECK_END	(IDC_EDIT_END + 19)
#define IDC_SLIDER_BEGIN	(IDC_BT_CHECK_END + 1)
#define IDC_SLIDER_END		(IDC_BT_CHECK_END + 20)
#define IDC_STATIC_BEGIN	(IDC_SLIDER_END + 1)
#define IDC_STATIC_END		(IDC_SLIDER_END + 20)

static char* PROPERTY_LIST_CN[20] =
{
	"亮度",
	"对比度",
	"色调",
	"饱和度",
	"清晰度",
	"伽玛",
	"启用颜色",
	"白平衡",
	"逆光对比",
	"增益",
	"电力线频率",
	"全景",
	"倾斜",
	"滚动",
	"缩放",
	"曝光",
	"光圈",
	"焦点",
	"低亮度补偿",
	"音量"
};

static char* PROPERTY_LIST_EN[20] =
{
	"Bright",
	"Contrast",
	"Hue",
	"Saturat",
	"Sharp",
	"Gamma",
	"CE",
	"WB",
	"BC",
	"Gain",
	"PLF",
	"Pan",
	"Tilt",
	"Roll",
	"Zoom",
	"Exposure",
	"Iris",
	"Focus",
	"LBC",
	"Volume"
};

static UINT SET_COMMAND_INDEX_LIST[20] =
{
	USB_SET_VIDEO_BRIGHTNESS,
	USB_SET_VIDEO_CONTRAST,
	USB_SET_VIDEO_HUE,
	USB_SET_VIDEO_SATURATION,
	USB_SET_VIDEO_SHARPNESS,
	USB_SET_VIDEO_GAMMA,
	USB_SET_VIDEO_COLORENABLE,
	USB_SET_VIDEO_WHITEBALANCE,
	USB_SET_VIDEO_BACKLIGHTCOMPENSATION,
	USB_SET_VIDEO_GAIN,
	USB_SET_VIDEO_POWERLINEFREQUENCY,
	USB_SET_VIDEO_PAN,
	USB_SET_VIDEO_TILT,
	USB_SET_VIDEO_ROLL,
	USB_SET_VIDEO_ZOOM,
	USB_SET_VIDEO_EXPOSURE,
	USB_SET_VIDEO_IRIS,
	USB_SET_VIDEO_FOCUS,
	USB_SET_VIDEO_LOWBRIGHTNESSCOMPENSATION,
	USB_SET_VIDEO_VOLUME
};

static UINT GET_COMMAND_INDEX_LIST[20] =
{
	USB_GET_VIDEO_BRIGHTNESS,
	USB_GET_VIDEO_CONTRAST,
	USB_GET_VIDEO_HUE,
	USB_GET_VIDEO_SATURATION,
	USB_GET_VIDEO_SHARPNESS,
	USB_GET_VIDEO_GAMMA,
	USB_GET_VIDEO_COLORENABLE,
	USB_GET_VIDEO_WHITEBALANCE,
	USB_GET_VIDEO_BACKLIGHTCOMPENSATION,
	USB_GET_VIDEO_GAIN,
	USB_GET_VIDEO_POWERLINEFREQUENCY,
	USB_GET_VIDEO_PAN,
	USB_GET_VIDEO_TILT,
	USB_GET_VIDEO_ROLL,
	USB_GET_VIDEO_ZOOM,
	USB_GET_VIDEO_EXPOSURE,
	USB_GET_VIDEO_IRIS,
	USB_GET_VIDEO_FOCUS,
	USB_GET_VIDEO_LOWBRIGHTNESSCOMPENSATION,
	USB_GET_VIDEO_VOLUME
};

// CSubDlgCameraControl 对话框

class CSubDlgCameraControl : public CDialog
{
	DECLARE_DYNAMIC(CSubDlgCameraControl)

public:
	CSubDlgCameraControl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CSubDlgCameraControl();

// 对话框数据
	enum { IDD = IDD_SUBDLG_CAMERA_CONTROL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
    afx_msg void OnPaint();
	LONG m_lCurChannel;
	HWND m_hVideoWnd;
	CStatic m_PreviewWindow;
	CStatic m_cStatic[IDC_STATIC_END - IDC_STATIC_BEGIN + 1];		//属性
	CButton m_cButton[IDC_BT_CHECK_END - IDC_BT_CHECK_BEGIN + 1];	//复选框
	CEdit m_cEdit[IDC_EDIT_END - IDC_EDIT_BEGIN + 1];				//文本框
	CSliderCtrl m_cSlider[IDC_SLIDER_END - IDC_SLIDER_BEGIN + 1];	//滑动条
public:
	LONG m_lUserID;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButtonGetVideoCap();
	afx_msg void OnBnClickedButtonSetDefaultCap();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnBnClickedBtStartPreview();
	afx_msg void OnBnClickedBtStopPreview();
	afx_msg void OnBnCheckClicked(UINT nID);

private:
	void SetSliderState(UINT index, int min, int max, UINT nCheckEnable = 0);
	void SetSliderPos(UINT index, int pos);
	int GetProperty(long *pValue, UINT nCommand);
	int SetProperty(int nValue, UINT nCommand, UINT nFlag = 2);
	int GetPropertyCap(USB_VIDEO_PROPERTY_CAP *pVideoPropertyCap);
};
