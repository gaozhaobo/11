// DlgFileTransfer.cpp : 实现文件
//

#include "stdafx.h"
#include "DlgFileTransfer.h"
#include "afxdialogex.h"


// CDlgFileTransfer 对话框

IMPLEMENT_DYNAMIC(CDlgFileTransfer, CDialog)

CDlgFileTransfer::CDlgFileTransfer(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgFileTransfer::IDD, pParent)
    , m_szEncryptFilePath(_T(""))
    , m_szUploadFilePath(_T(""))
{

}

CDlgFileTransfer::~CDlgFileTransfer()
{
}

void CDlgFileTransfer::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Text(pDX, IDC_EDIT_ENCRYPT_FILE_PATH, m_szEncryptFilePath);
    DDX_Text(pDX, IDC_EDIT_UPLOAD_FILE_PATH, m_szUploadFilePath);
}


BEGIN_MESSAGE_MAP(CDlgFileTransfer, CDialog)
    ON_BN_CLICKED(IDC_BTN_SELECT_ENCRYPT_FILE, &CDlgFileTransfer::OnBnClickedBtnSelectEncryptFile)
    ON_BN_CLICKED(IDC_BTN_SELECT_UPLOAD_FILE, &CDlgFileTransfer::OnBnClickedBtnSelectUploadFile)
    ON_BN_CLICKED(IDC_BTN_FILE_TRANSFER_START, &CDlgFileTransfer::OnBnClickedBtnFileTransferStart)
END_MESSAGE_MAP()

BOOL CDlgFileTransfer::OnInitDialog()
{
    GetDlgItem(IDC_EDIT_UPLOAD_REMOTE_FILE_PATH)->SetWindowText("/data/test.txt");
    GetDlgItem(IDC_EDIT_DOWNLOAD_REMOTE_FILE_PATH)->SetWindowText("/data/test.txt");
    GetDlgItem(IDC_EDIT_DOWNLOAD_FILE_PATH)->SetWindowText("C:\\USBSDKLog\\test.txt");
    return TRUE;
}
// CDlgFileTransfer 消息处理程序


void CDlgFileTransfer::OnBnClickedBtnSelectEncryptFile()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);

    BOOL isOpen = TRUE;	    //是否打开(否则为保存)
    CString defaultDir = _T("C:\\");    //默认打开的文件路径
    //CString filter = _T("文件 (*.txt; *.dat; *.bin; *.dav; *.log)|*.txt;*.dat;*.bin;*.dav;*.log||");  //文件过虑的类型

    CFileDialog openFileDlg(isOpen, defaultDir, m_szEncryptFilePath, OFN_HIDEREADONLY | OFN_READONLY, NULL, NULL);
    //openFileDlg.GetOFN().lpstrInitialDir = _T("");

    INT_PTR result = openFileDlg.DoModal();
    if (result == IDOK)
    {
        m_szEncryptFilePath = openFileDlg.GetPathName();
        UpdateData(FALSE);
    }
}


void CDlgFileTransfer::OnBnClickedBtnSelectUploadFile()
{
    // TODO:  在此添加控件通知处理程序代码
    UpdateData(TRUE);

    BOOL isOpen = TRUE;	    //是否打开(否则为保存)
    CString defaultDir = _T("C:\\");    //默认打开的文件路径
    //CString filter = _T("文件 (*.txt; *.dat; *.bin; *.dav; *.log)|*.txt;*.dat;*.bin;*.dav;*.log||");  //文件过虑的类型

    CFileDialog openFileDlg(isOpen, defaultDir, m_szUploadFilePath, OFN_HIDEREADONLY | OFN_READONLY, NULL, NULL);
    //openFileDlg.GetOFN().lpstrInitialDir = _T("");

    INT_PTR result = openFileDlg.DoModal();
    if (result == IDOK)
    {
        m_szUploadFilePath = openFileDlg.GetPathName();
        UpdateData(FALSE);
    }
}


void CDlgFileTransfer::OnBnClickedBtnFileTransferStart()
{
    // TODO:  在此添加控件通知处理程序代码
    USB_FILE_TRANSFER_INFO struFileTransferInfo = { 0 };
    USB_FILE_TRANSFER_PROGRESS_INFO struProgressInfo = { 0 };

    //判断选择的是哪个功能
    if (((CButton *)GetDlgItem(IDC_RADIO_ENCRYPT))->GetCheck()) //加密
    {
        memcpy(struFileTransferInfo.byLocalFileName, m_szEncryptFilePath.GetBuffer(m_szEncryptFilePath.GetLength()), m_szEncryptFilePath.GetLength());

        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_START, &struFileTransferInfo, &struProgressInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_DEVICE_ENCRYPTION");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            while (true)
            {
                if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_PROGRESS, NULL, &struProgressInfo))
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_DEVICE_ENCRYPTION_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //状态判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "Dev Encrypt failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //传输中，打印进度
                LOGIN_INFO->WriteLog(INF_LEVEL, "Dev Encrypt Progress[%d]", struProgressInfo.byProgress);
                Sleep(1000);

                //完成判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
                {
                    break;
                }
            }

            //关闭加密
            if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_DEVICE_ENCRYPTION_STOP, NULL, NULL))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_DEVICE_ENCRYPTION_STOP");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
        }
    }
    else if (((CButton *)GetDlgItem(IDC_RADIO_UPLOAD))->GetCheck())//导入
    {
        memcpy(struFileTransferInfo.byLocalFileName, m_szUploadFilePath.GetBuffer(m_szUploadFilePath.GetLength()), m_szUploadFilePath.GetLength()); //本地文件路径

        CString strRemoteFileName;
        GetDlgItem(IDC_EDIT_UPLOAD_REMOTE_FILE_PATH)->GetWindowText(strRemoteFileName);
        //memcpy(struFileTransferInfo.byRemoteFileName, "/data/test.txt", strlen("/data/test.txt"));//写死
        memcpy(struFileTransferInfo.byRemoteFileName, strRemoteFileName.GetBuffer(strRemoteFileName.GetLength()), strRemoteFileName.GetLength()); // 设备文件路径

        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_START, &struFileTransferInfo, &struProgressInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_UPLOAD_START");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            while (true)
            {
                if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_PROGRESS, NULL, &struProgressInfo))
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_FILE_UPLOAD_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //状态判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "Upload failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //传输中，打印进度
                LOGIN_INFO->WriteLog(INF_LEVEL, "Upload Progress[%d]", struProgressInfo.byProgress);
                Sleep(1000);

                //完成判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
                {
                    break;
                }
            }

            //关闭加密
            if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_UPLOAD_STOP, NULL, NULL))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_UPLOAD_STOP");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
        }
    }
    else if (((CButton *)GetDlgItem(IDC_RADIO_DOWNLOAD))->GetCheck())//导出
    {
        //memcpy(struFileTransferInfo.byLocalFileName, "C:\\USBSDKLog\\test.txt", strlen("C:\\USBSDKLog\\test.txt")); //写死
        //memcpy(struFileTransferInfo.byRemoteFileName, "/data/test.txt", strlen("/data/test.txt")); //写死

        CString strRemoteFileName;
        GetDlgItem(IDC_EDIT_DOWNLOAD_REMOTE_FILE_PATH)->GetWindowText(strRemoteFileName);
        memcpy(struFileTransferInfo.byRemoteFileName, strRemoteFileName.GetBuffer(strRemoteFileName.GetLength()), strRemoteFileName.GetLength()); // 设备文件路径

        CString strLocalFileName;
        GetDlgItem(IDC_EDIT_DOWNLOAD_FILE_PATH)->GetWindowText(strLocalFileName);
        memcpy(struFileTransferInfo.byLocalFileName, strLocalFileName.GetBuffer(strLocalFileName.GetLength()), strLocalFileName.GetLength()); // 本地文件路径

        if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_START, &struFileTransferInfo, &struProgressInfo))
        {
            LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_DOWNLOAD_START");
            DWORD dwError = USB_GetLastError();
            LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
        }
        else
        {
            while (true)
            {
                if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_PROGRESS, NULL, &struProgressInfo))
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "USB_TRANS_FILE_DOWNLOAD_PROGRESS  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //状态判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_FAIL)
                {
                    DWORD dwError = USB_GetLastError();
                    LOGIN_INFO->WriteLog(ERR_LEVEL, "Download failed  ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
                    break;
                }

                //传输中，打印进度
                LOGIN_INFO->WriteLog(INF_LEVEL, "Download Progress[%d]", struProgressInfo.byProgress);
                Sleep(1000);

                //完成判断
                if (struProgressInfo.byState == USB_FILE_TRANSFER_SUCC || struProgressInfo.byProgress == 100)
                {
                    break;
                }
            }

            //关闭加密
            if (!USB_FileTransfer_V20(m_lUserID, USB_TRANS_FILE_DOWNLOAD_STOP, NULL, NULL))
            {
                LOGIN_INFO->WriteLog(ERR_LEVEL, "FAILED  USB_TRANS_FILE_DOWNLOAD_STOP");
                DWORD dwError = USB_GetLastError();
                LOGIN_INFO->WriteLog(ERR_LEVEL, "ErrorCode = [%d], ErrorMsg = [%s]", dwError, USB_GetErrorMsg(dwError));
            }
        }
    }
    else
    {
        AfxMessageBox(_T("未选择功能"));
    }
}
