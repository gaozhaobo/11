// LanguageSelect.cpp : 实现文件
//

#include "stdafx.h"
#include "LanguageSelect.h"
#include "afxdialogex.h"

#include "Language.h"

// CLanguageSelect 对话框
BOOL g_bEnglish; //TRUE-英文Demo FALSE-中文Demo

IMPLEMENT_DYNAMIC(CLanguageSelect, CDialog)

CLanguageSelect::CLanguageSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CLanguageSelect::IDD, pParent)
{

}

CLanguageSelect::~CLanguageSelect()
{
}

void CLanguageSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLanguageSelect, CDialog)
	ON_BN_CLICKED(ID_LANGUAGE_OK, &CLanguageSelect::OnBnClickedLanguageOk)
	ON_BN_CLICKED(IDC_RADIO_CH, &CLanguageSelect::OnBnClickedRadioCh)
	ON_BN_CLICKED(IDC_RADIO_EN, &CLanguageSelect::OnBnClickedRadioEn)
END_MESSAGE_MAP()


// CLanguageSelect 消息处理程序


BOOL CLanguageSelect::OnInitDialog()
{
	CDialog::OnInitDialog();

	if (g_bEnglish)
	{
		((CButton *)GetDlgItem(IDC_RADIO_EN))->SetCheck(TRUE);
		((CButton *)GetDlgItem(IDC_RADIO_CH))->SetCheck(FALSE);
	}
	else
	{
		((CButton *)GetDlgItem(IDC_RADIO_EN))->SetCheck(FALSE);
		((CButton *)GetDlgItem(IDC_RADIO_CH))->SetCheck(TRUE);
	}

	UpdateData(FALSE);

	return TRUE;
}


void CLanguageSelect::OnBnClickedLanguageOk()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);

	CDialog::OnOK();
}


void CLanguageSelect::OnBnClickedRadioCh()
{
	// TODO:  在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_RADIO_CH))->GetCheck())
	{
		g_bEnglish = FALSE;
		OnPaint();
		Invalidate();
	}
}


void CLanguageSelect::OnBnClickedRadioEn()
{
	// TODO:  在此添加控件通知处理程序代码
	if (((CButton *)GetDlgItem(IDC_RADIO_EN))->GetCheck())
	{
		g_bEnglish = TRUE;
#define SWITCH_ENGLISH_US 1;
		OnPaint();
		Invalidate();
	}
}

void CLanguageSelect::OnPaint()
{
	CPaintDC dc(this);
	SET_DLG_LAN(IDD_DIG_SELECT_LANGUAGE);
	SET_CONTROL_LAN(IDD_DIG_SELECT_LANGUAGE, ID_LANGUAGE_OK);
}

