// DIODlg.h : header file
//
#include "APS168.h"
#include "APS_Define.h"
#include "ErrorCodeDef.h"
#include "type_def.h"
#pragma once


// CDIODlg dialog
class CDIODlg : public CDialog
{
// Construction
public:
	CDIODlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DIO_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	 

/////// ADLINK PCI-C154+ ////////////
private:
    #define MAXAXIS    (4)
	#define MAXCHANNEL (16)
	#define _NO        (0)
    #define _YES       (1)
	

	//I16 CardId;
	//I32 m_IsInitial; // Is device initialed? (0:No; 1:Yes)   
	I16 Channel;
	
	void m_InterfaceIni();           // User interface initial
	void m_InterfaceCtr();           // Control User interface
	void Function_Result( int Ret ); //Show error code
	void __ReadDo();
	void __ReadDi();
	void __SetDo();
    
	//Button
	CButton *pInitial;
	CButton *pSelect_all;
	CButton *pClear;
	CButton *pCheck[MAXCHANNEL];
	CButton *pSetDo;

	//Edit
	CWnd *pDriver_Ver; 
	CWnd *pPCB_Ver;     
	CWnd *pDSP_Ver;    
	CWnd *pFPGA_Ver;   
	CWnd *pDLL_Ver;
	CWnd *pDo_status[MAXCHANNEL];
	CWnd *pDi_status[MAXCHANNEL];
//////////////////////////////////////////////////

public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
public:
	afx_msg void OnBnClickedinitial();
public:
	afx_msg void OnBnClickedselectall();
public:
	afx_msg void OnBnClickedclear();
public:
	afx_msg void OnBnClickedSetdo();
	afx_msg void OnBnClickedButton1();
};
