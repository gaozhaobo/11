#pragma once
#include "resource.h"
#include "afxwin.h"

// SubDlgCameraInterface 对话框

class SubDlgCameraInterface : public CDialog
{
	//DECLARE_DYNAMIC(SubDlgCameraInterface)

public:
	SubDlgCameraInterface(CWnd* pParent = NULL);   // 标准构造函数
	//virtual ~SubDlgCameraInterface();

// 对话框数据
	enum { IDD = IDD_SUBDLG_CAMERA_INTERFACE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
    virtual void OnOK();
    virtual void OnCancel();
    afx_msg void OnPaint();
public:
    INT32 m_handle;
    HWND m_hVideoWnd;
    INT32 m_iPreviewChannel;
    INT32 m_iFDChannel;
    INT32 m_iCallBackChannel;
    INT32 m_iRecordChannel;
    INT32 m_dwRotateAngle;  //当前预览画面旋转角度

    INT32 m_dwFrameRate;
    INT32 m_dwWidth;
    INT32 m_dwHeight;
    INT32 m_dwSrcStreamType;
    BOOL m_bSetOSD;

    CComboBox m_cmbVideoType;
    CComboBox m_cmbAudioType;

    CComboBox m_cmbFDSnapMode;

    CComboBox m_cmbCallBackType;
    CComboBox m_cmbPreviewType;
    CComboBox m_cmbRecordType;

    CButton m_btnPreviewAudio;

    CStatic m_PreviewWindow;
    USB_VIDEO_CAPACITY m_CamVideoCap[100];
    USB_AUDIO_PARAM    m_CamAudioCap[100];
    INT32 m_nVideoCapCount;
    INT32 m_nAudioCapCount;

    virtual BOOL OnInitDialog();
    void UpdateAudio(BOOL bHaveAudio);
    BOOL GetAudioFormat(USB_AUDIO_PARAM* pWF);
    BOOL GetVideoFormat(INT32 &dwSrcStreamType, INT32 &dwFrameRate, INT32 &dwWidth, INT32 &dwHeight);
    void OnCbnSelchangeCamVideo();
    void OnCbnSelchangeCamAudio();
    void GetCamVideoCap();
    void GetCamAudioCap();
    void SetOsd(BOOL bOpen);
    void __stdcall FaceDetectExtenResultCallBackLoacl(long lPort, LPUSB_FD_RESULT_PARAM FDParamInfo, void* pUser);
    void __stdcall OnEventCallBack(int handle, long lEvent, long nParam1, long nParam2, void *pUser);
    void __stdcall StreamCallBackLocal(INT32 handle, USB_FRAME_INFO *pFrameInfo, void* pUser);

    afx_msg void OnBnClickedBtnStartPreview();
    afx_msg void OnBnClickedBtnStartFacedetect();
    afx_msg void OnBnClickedBtnStartRecord();
    afx_msg void OnBnClickedBtnStartStreamcallback();
    afx_msg void OnBnClickedBtnEnumCap();
    afx_msg void OnBnClickedBtnSetConfig();
    afx_msg void OnBnClickedBtnSetRotateAngle();
    afx_msg void OnBnClickedBtnSnapshot();
    afx_msg void OnBnClickedBtnStopPreview();
    afx_msg void OnBnClickedBtnStopRecord();
    afx_msg void OnBnClickedBtnStopFacedetect();
    afx_msg void OnBnClickedBtnStopStreamcallback();
    afx_msg void OnBnClickedBtnEventcallback();

private:
	LONG m_lPlayPort;
public:
    afx_msg void OnBnClickedButton1();
};

static void __stdcall FaceDetectExtenResultCallBack(long lPort, LPUSB_FD_RESULT_PARAM FDParamInfo, void* pUser);
static void __stdcall StreamCallBack(long handle, USB_FRAME_INFO *pFrameInfo, void* pUser);
static void __stdcall EventCallBack(long handle, long lEvent, long nParam1, long nParam2, void *pUser);

