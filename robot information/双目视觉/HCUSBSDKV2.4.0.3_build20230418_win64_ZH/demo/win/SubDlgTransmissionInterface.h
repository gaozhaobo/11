#pragma once
#include "resource.h"
#include "afxwin.h"
#include <map>
#include <vector>

#define MAX_NAME_LENGTH     16
#define MAX_PATH_LENGTH     64
#define MAX_PROPERTY_NUM    10
#define IDC_BASE            10000
#define IDC_EDIT_BEGIN      (IDC_BASE + 1)
#define IDC_EDIT_END        (IDC_BASE + MAX_PROPERTY_NUM)
#define IDC_STATIC_BEGIN    (IDC_EDIT_END + 1)
#define IDC_STATIC_END      (IDC_EDIT_END + MAX_PROPERTY_NUM)

static std::map<int, vector<std::string> > PROPERTY_MAP =
{
    { USB_GET_VCA_SWITCH, { "ChannelID", "DetectEnabled", "IdentifyEnabled", "", "", "", "", "", "", "" } },
    { USB_SET_VCA_SWITCH, { "ChannelID", "DetectEnabled", "IdentifyEnabled", "", "", "", "", "", "", "" } },
    { USB_GET_VCA_SNAPSHOT, { "ChannelID", "SnapshotMode", "CaptureInterval", "Path", "", "", "", "", "", "" } },
    { USB_GET_VCA_FACE_THRESHOLD, { "ChannelID", "ThresholdValue", "", "", "", "", "", "", "", "" } },
    { USB_SET_VCA_FACE_THRESHOLD, { "ChannelID", "ThresholdValue", "", "", "", "", "", "", "", "" } },
    { USB_GET_VCA_FACE_ATTRIBUTES, { "ChannelID", "Enabled", "FaceExpression", "Age", "Gender", "Glass", "", "", "", "" } },
    { USB_SET_VCA_FACE_ATTRIBUTES, { "ChannelID", "Enabled", "FaceExpression", "Age", "Gender", "Glass", "", "", "", "" } },
    { USB_GET_VCA_FACE_DETECT_RULE, { "ChannelID", "Sensitivity", "ObjGenerateRate", "RegionX", "RegionY", "RegionWidth", "RegionHeight", "", "", "" } },
    { USB_SET_VCA_FACE_DETECT_RULE, { "ChannelID", "Sensitivity", "ObjGenerateRate", "RegionX", "RegionY", "RegionWidth", "RegionHeight", "", "", "" } },
    { USB_GET_VCA_FACE_QUALITY, { "ChannelID", "LeftAngle", "RightAngle", "UpAngle", "DownAngle", "PupilDistance", "Score", "ShelterType", "", "" } },
    { USB_SET_VCA_FACE_QUALITY, { "ChannelID", "LeftAngle", "RightAngle", "UpAngle", "DownAngle", "PupilDistance", "Score", "ShelterType", "", "" } },
    { USB_SET_VCA_PIC_DOWNLOAD, { "Id", "Type", "PicWidth", "PicHeight", "PicSize", "Name", "Post", "Path", "", "" } },
    { USB_GET_VCA_FACE_BASE_DATA_CFG, { "Id", "OperateType", "Name", "Post", "", "", "", "", "", "" } },
    { USB_SET_VCA_FACE_BASE_DATA_CFG, { "Id", "OperateType", "Name", "Post", "", "", "", "", "", "" } },
    { USB_GET_VCA_ELECTRONICSIGNAGE_CFG, { "ChannelID", "Enabled", "FontColor", "FontType", "", "", "", "", "", "" } },
    { USB_SET_VCA_ELECTRONICSIGNAGE_CFG, { "ChannelID", "Enabled", "FontColor", "FontType", "", "", "", "", "", "" } },
    { USB_GET_VCA_FACE_DETECT, { "ChannelID", "DetFaceNum", "RegionX", "RegionY", "RegionWidth", "RegionHeight", "", "", "", "" } },
    { USB_SET_VCA_FACE_DETECT, { "ChannelID", "DetFaceNum", "RegionX", "RegionY", "RegionWidth", "RegionHeight", "", "", "", "" } },
    { USB_GET_VCA_FACE_CONTRAST, { "ChannelID", "Id", "FPID", "Name", "Post", "", "", "", "", "" } },
    { USB_SET_VCA_FACE_CONTRAST, { "ChannelID", "Id", "FPID", "Name", "Post", "", "", "", "", "" } }
};


// SubDlgTransmissionInterface 对话框

class SubDlgTransmissionInterface : public CDialog
{
    DECLARE_DYNAMIC(SubDlgTransmissionInterface)

public:
    SubDlgTransmissionInterface(CWnd* pParent = NULL);   // 标准构造函数
    virtual ~SubDlgTransmissionInterface();

    // 对话框数据
    enum { IDD = IDD_SUBDLG_TRANSMISSION_INTERFACE };

protected:
    virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
    void OnPaint();
    DECLARE_MESSAGE_MAP()
public:
    virtual BOOL OnInitDialog();
    afx_msg void OnBnClickedOk();
    afx_msg void OnCbnSelchangeComboCommand();

private:
    void CreateControl(vector<string> captionList);
    void GetByteFromEdit(int index, BYTE& target);
    void GetDwordFromEdit(int index, DWORD& target);
    void GetByteArrayFromEdit(int index, BYTE* target, int len);

    void SetByteToEdit(int index, BYTE value);
    void SetDwordToEdit(int index, DWORD value);
    void SetByteArrayToEdit(int index, BYTE* value);

public:
    LONG m_lUserID;

private:
    CComboBox m_cbCommand;
    CStatic m_cStatic[MAX_PROPERTY_NUM];          //属性
    CEdit m_cEdit[MAX_PROPERTY_NUM];              //文本框
    CString m_csFilePath; //导入文件路径

public:
    afx_msg void OnBnClickedBtnSelectFile();

};
