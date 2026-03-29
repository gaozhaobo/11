#pragma once


// CDialog_axis_monitor dialog




// Motion I/O
#define DLG_ALM     (0)
#define DLG_PEL     (1)
#define DLG_MEL     (2)
#define DLG_ORG     (3)
#define DLG_EMG     (4)
#define DLG_EZ      (5)
#define DLG_INP     (6)
#define DLG_SVON    (7)
#define MAX_MIO_CHECK   (8) // ***

// Motion status
// Motion I/O
#define DLG_CSTP     (0)
#define DLG_VM       (1)
#define DLG_ACC      (2)
#define DLG_DEC      (3)
#define DLG_DIR      (4)
#define DLG_MDN      (5)
#define DLG_HMV      (6)
#define DLG_WAIT     (7)
#define DLG_PTB      (8)
#define DLG_JOG      (9)
#define DLG_ASTP     (10)
#define DLG_BLD      (11)
#define DLG_PRED     (12)
#define DLG_POSTD    (13)
#define DLG_GER      (14)
#define MAX_MSTS_CHECK  (15) // ****

class CDialog_axis_monitor : public CDialog
{
	DECLARE_DYNAMIC(CDialog_axis_monitor)

public:
	CDialog_axis_monitor(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDialog_axis_monitor();

// Dialog Data
	enum { IDD = IDD_DLG_AXIS_MONITOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:

public:
	virtual BOOL OnInitDialog();

	int v_card_id;
	int v_start_axis_id;
	int v_total_axes;
	int v_selected_axis_id;
	CComboBox *pCombo_select_axis;

	CButton *v_pCheck_motion_io[MAX_MIO_CHECK];
	CButton *v_pCheck_motion_status[MAX_MSTS_CHECK];
	int v_motion_io_bit_map[MAX_MIO_CHECK];
	int v_motion_status_bit_map[MAX_MSTS_CHECK];

	// CDialog_axis_monitor **v_pParentPoint;
public:
	afx_msg void OnCbnSelchangeCombo1();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);

protected:
	virtual void PostNcDestroy();
	virtual void OnCancel();

public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedButton3();
};

