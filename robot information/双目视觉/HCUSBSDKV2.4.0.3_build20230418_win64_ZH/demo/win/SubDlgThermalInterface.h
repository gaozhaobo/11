#pragma once
#include "resource.h"
#include "afxwin.h"
//#include "ClientDemoDlg.h"

// SubDlgThermalInterface 对话框

class SubDlgThermalInterface : public CDialog
{
	//DECLARE_DYNAMIC(SubDlgThermalInterface)

public:
	SubDlgThermalInterface(CWnd* pParent = NULL);   // 标准构造函数
	//virtual ~SubDlgThermalInterface();

// 对话框数据
	enum { IDD = IDD_SUBDLG_THERMAL_INTERFACE };

    LONG m_lUserID;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    LONG m_lCurChannel;
    CString m_csFileName;
    CString m_csFilePath;
    HWND m_hVideoWnd;

	DECLARE_MESSAGE_MAP()
public:
    CComboBox m_cbConfig;
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedButtonConfig();
    afx_msg void OnBnClickedButtonSelect();
    virtual void OnOK();
    virtual void OnCancel();
    CStatic m_PreviewWindow;
    afx_msg void OnBnClickedButtonStartPreview();
    void SetOsd();
    afx_msg void OnBnClickedButtonStopPreview();
    static void CALLBACK OnEventCallBack(int handle, long lEvent, long nParam1, long nParam2, void *pUser);
    CComboBox m_combDecodeType;
    int m_iCallBackChannel;
    int m_iStreamType;
    afx_msg void OnPaint();
    afx_msg void OnBnClickedButtonConfigState();
};
