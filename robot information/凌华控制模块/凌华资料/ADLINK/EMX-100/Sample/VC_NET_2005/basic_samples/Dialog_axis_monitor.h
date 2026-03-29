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
#define DLG_RDY     (8)
#define MAX_MIO_CHECK   (9) // ***

// Motion status
#define DLG_MDN       (0)
#define DLG_EMGS      (1)
#define DLG_ALMS      (2)
#define DLG_PELS      (3)
#define DLG_MELS      (4)
#define DLG_SPELS     (5)
#define DLG_SMELS     (6)
#define DLG_HMES      (7)
#define DLG_ORGS      (8)
#define DLG_EZS       (9)
#define MAX_MSTS_CHECK  (10) // ****

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
	void updateDate(int data);

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
	int repeatResult;

public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton2();
public:
	afx_msg void OnBnClickedButton3();
public:
	afx_msg void OnBnClickedCheck17();
};

