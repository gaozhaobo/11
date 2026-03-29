using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThermalDemo
{
    public partial class ThermalDemo : Form
    {

        private const int INITIALIZED_INDEX = 1;
        private int g_nEnumDevIndex = INITIALIZED_INDEX;
        private HCUSBSDK.USB_DEVICE_INFO[] m_aHidDevInfo;//这个存储着遍历到的设备，列表索引1开始，所以添加
        int m_iHandle = -1;
        int m_iPreviewHandle = -1;
        HCUSBSDK.USB_DEVICE_INFO struDevInfo = new HCUSBSDK.USB_DEVICE_INFO();
        private int SelectedItemsIndex = INITIALIZED_INDEX;//登录设备时选中的索引
        private int IndexOfInfo = INITIALIZED_INDEX;//信息列表更新信息的索引,初始值为1

        public ThermalDemo()
        {
            InitializeComponent();
        }

        private void ThermalDemo_Load(object sender, EventArgs e)
        {
            HCUSBSDK.USB_Init();
            HCUSBSDK.USB_SetLogToFile(3, "C:\\USBSdkLog\\", true);
            
        }

        private void btnEnum_Click(object sender, EventArgs e)
        {
            listViewDeviceInfo.Items.Clear();//不把列表头都清空了，得用item.clear
            g_nEnumDevIndex = INITIALIZED_INDEX;
            int m_iDevNum = HCUSBSDK.USB_GetDeviceCount();
            if (m_iDevNum <= 0)
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GetDeviceCount fail 当前无设备 ！");
                return;
            }
          
            int dwSize = Marshal.SizeOf(struDevInfo);
            IntPtr pDevInfoList = Marshal.AllocHGlobal(dwSize * m_iDevNum);

            m_aHidDevInfo = new HCUSBSDK.USB_DEVICE_INFO[64];
            int iret = HCUSBSDK.USB_EnumDevices(m_iDevNum, pDevInfoList);
            if (iret <= 0)
            {
                Marshal.FreeHGlobal(pDevInfoList);
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SDK_EnumDevice fail 当前无设备 ！");
                return;
            }
            else
            {
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_SDK_EnumDevice succ");
            }            

            for (int i = 0; i < m_iDevNum; i++)
            {
                struDevInfo = (HCUSBSDK.USB_DEVICE_INFO)Marshal.PtrToStructure(pDevInfoList, typeof(HCUSBSDK.USB_DEVICE_INFO));

                if (g_nEnumDevIndex == 64)
                {
                    WriteLog(HCUSBSDK.ERR_LEVEL, "The total number of devices could not be over 64numbers");
                }

                //设备信息展示在列表上
                listViewDeviceInfo.Invoke(new Action(() =>
                {
                    listViewDeviceInfo.Items.Add(new ListViewItem(new string[]
                {
                    (g_nEnumDevIndex).ToString(),
                    struDevInfo.dwVID.ToString(),
                    struDevInfo.dwPID.ToString(),
                    System.Text.Encoding.Default.GetString(struDevInfo.szManufacturer),
                    System.Text.Encoding.Default.GetString(struDevInfo.szDeviceName),
                    System.Text.Encoding.Default.GetString(struDevInfo.szSerialNumber),
                    "no".ToString(),
                    "no".ToString()
                }));
                    m_aHidDevInfo[g_nEnumDevIndex - 1] = struDevInfo;//存储到数组中方便登录获取数据
                    g_nEnumDevIndex++;//更新索引
                }));
                pDevInfoList += Marshal.SizeOf(struDevInfo);
            }
        }

        private void btnLogin_Click(object sender, EventArgs e)
        {
            HCUSBSDK.USB_DEVICE_INFO struUsbDeviceInfo = new HCUSBSDK.USB_DEVICE_INFO();
            struUsbDeviceInfo.dwSize = Marshal.SizeOf(struUsbDeviceInfo);
            struUsbDeviceInfo = struDevInfo;

            HCUSBSDK.USB_USER_LOGIN_INFO m_struCurUsbLoginInfo = new HCUSBSDK.USB_USER_LOGIN_INFO();
            m_struCurUsbLoginInfo.dwSize = Marshal.SizeOf(m_struCurUsbLoginInfo);
            m_struCurUsbLoginInfo.dwTimeout = 5000;
            m_struCurUsbLoginInfo.dwVID = m_aHidDevInfo[SelectedItemsIndex].dwVID; ;
            m_struCurUsbLoginInfo.dwPID = m_aHidDevInfo[SelectedItemsIndex].dwPID;
            m_struCurUsbLoginInfo.szSerialNumber = System.Text.Encoding.Default.GetString(m_aHidDevInfo[SelectedItemsIndex].szSerialNumber);
//             m_struCurUsbLoginInfo.szUserName = szUserName;
//             m_struCurUsbLoginInfo.szPassword = szPassword;

            IntPtr pUsbLoginInfo = Marshal.AllocHGlobal(Marshal.SizeOf(m_struCurUsbLoginInfo));
            Marshal.StructureToPtr(m_struCurUsbLoginInfo, pUsbLoginInfo, false);

            HCUSBSDK.USB_DEVICE_REG_RES struDeviceRegRes = new HCUSBSDK.USB_DEVICE_REG_RES(); ;
            struDeviceRegRes.dwSize = Marshal.SizeOf(struDeviceRegRes);
            IntPtr pDevRegRes = Marshal.AllocHGlobal(struDeviceRegRes.dwSize);

            m_iHandle = HCUSBSDK.USB_Login(pUsbLoginInfo, pDevRegRes);
            if (m_iHandle < 0)
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_Login fail 登录设备失败！");
                ShowErrorMsg();
            }
            else
            {
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_Login Ssucc 登录设备成功！");
                listViewDeviceInfo.SelectedItems[0].SubItems[6].Text = "yes".ToString();
                listViewDeviceInfo.SelectedItems[0].SubItems[7].Text = "yes".ToString();   
            }                  
        }

        private void btnLogout_Click(object sender, EventArgs e)
        {
            if (!HCUSBSDK.USB_Logout(m_iHandle))
            {              
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_Logout fail 注销设备失败！");
                ShowErrorMsg();
                return;
            }
            else
            {
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_Logout succ 注销设备成功！");
                listViewDeviceInfo.SelectedItems[0].SubItems[6].Text = "no".ToString();   
            }
        }

        private void listViewDeviceInfo_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (listViewDeviceInfo.SelectedItems.Count > 0)
            {
                try
                {
                    SelectedItemsIndex = int.Parse(listViewDeviceInfo.FocusedItem.SubItems[0].Text) - 1;
                    btnLogin.Enabled = true;
                    btnLogout.Enabled = true;
                }
                catch (Exception ep)
                {
                    MessageBox.Show(ep.ToString(), "Error", MessageBoxButtons.OK);
                }
            }
            else
            {
                btnLogin.Enabled = false;
                btnLogout.Enabled = false;
            }
        }

        private void btnStart_Click(object sender, EventArgs e)
        {
            bool bRet = false;

            HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfoGet = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
            HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfoGet = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

            //配置相机视频参数 
            HCUSBSDK.USB_VIDEO_CAPACITY[] struVideoParamGet = new HCUSBSDK.USB_VIDEO_CAPACITY[10];
            for (int yy = 0; yy < struVideoParamGet.Length; yy++)
            {
                struVideoParamGet[yy] = new HCUSBSDK.USB_VIDEO_CAPACITY();
                struVideoParamGet[yy].lFrameRates = new long[50];
            }

            IntPtr ptArray = Marshal.AllocHGlobal(Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY)) * 10);
            struConfigOutputInfoGet.lpOutBuffer = ptArray;

            struConfigOutputInfoGet.dwOutBufferSize = Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY)) * 10;
            IntPtr pConfigOutputInfoGet = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfoGet));
            Marshal.StructureToPtr(struConfigOutputInfoGet, pConfigOutputInfoGet, false);
            IntPtr pConfigInputInfoGet = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfoGet));

            bRet = HCUSBSDK.USB_GetDeviceConfig(m_iHandle, HCUSBSDK.USB_GET_VIDEO_CAP, pConfigInputInfoGet, pConfigOutputInfoGet);
            if (!bRet)
            {
                ShowErrorMsg();
            }
            HCUSBSDK.USB_VIDEO_PARAM struVideoParam = new HCUSBSDK.USB_VIDEO_PARAM();
            for (int i = 0; i < 10; ++i)
            {
                struVideoParamGet[i] = (HCUSBSDK.USB_VIDEO_CAPACITY)Marshal.PtrToStructure(struConfigOutputInfoGet.lpOutBuffer + i * Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY)), typeof(HCUSBSDK.USB_VIDEO_CAPACITY));
                if (struVideoParamGet[i].nType == HCUSBSDK.USB_STREAM_MJPEG)
                {
                    struVideoParam.dwVideoFormat = struVideoParamGet[i].nType;
                    struVideoParam.dwFramerate = (int)struVideoParamGet[i].lFrameRates[0];
                    struVideoParam.dwWidth = struVideoParamGet[i].dwWidth;
                    struVideoParam.dwHeight = struVideoParamGet[i].dwHeight;
                }
            }

            HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
            HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struVideoParam));
            Marshal.StructureToPtr(struVideoParam, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struVideoParam);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle, HCUSBSDK.USB_SET_VIDEO_PARAM, pConfigInputInfo, pConfigOutputInfo);
            if (!bRet)
            {
                ShowErrorMsg();
            }
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);

            //配置相机视频参数
            HCUSBSDK.USB_SRC_STREAM_CFG struSrcStreamCfg = new HCUSBSDK.USB_SRC_STREAM_CFG();
            struSrcStreamCfg.dwStreamType = HCUSBSDK.USB_STREAM_MJPEG;
            struSrcStreamCfg.bUseAudio = 0;

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struSrcStreamCfg));
            Marshal.StructureToPtr(struSrcStreamCfg, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struSrcStreamCfg);

            pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle, HCUSBSDK.USB_SET_SRC_STREAM_TYPE, pConfigInputInfo, pConfigOutputInfo);
            if (!bRet)
            {
                ShowErrorMsg();
            }           

            HCUSBSDK.USB_PREVIEW_PARAM lpPreviewParam = new HCUSBSDK.USB_PREVIEW_PARAM();
            lpPreviewParam.dwStreamType = (uint)HCUSBSDK.USB_STREAM_PS_MJPEG;
            lpPreviewParam.byUseAudio = 0;
            lpPreviewParam.dwChannel = 1;
            lpPreviewParam.hWindow = PreviewPanel.Handle;
            lpPreviewParam.dwSize = (uint)Marshal.SizeOf(lpPreviewParam);

            m_iPreviewHandle = HCUSBSDK.USB_StartPreview(m_iHandle, ref lpPreviewParam);
            if (m_iPreviewHandle < 0)
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_StartPreview fail 预览失败！");
                ShowErrorMsg();
            }
            else
            {
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_StartPreview succ!");
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            if (m_iHandle != -1 && m_iPreviewHandle != -1)
            {
                bool bRet = HCUSBSDK.USB_StopChannel(m_iHandle, m_iPreviewHandle);
                if(!bRet)
                {
                    WriteLog(HCUSBSDK.ERR_LEVEL, "USB_StopChannel fail！");
                    ShowErrorMsg();
                    return;
                }
                else
                {
                    WriteLog(HCUSBSDK.INF_LEVEL, "USB_StopChannel succ!");
                }

                PreviewPanel.Refresh();
            }
        }

        /// <summary>
        /// 为了返回显示在日志Info中的level的类型是INF 还是ERR
        /// </summary>
        /// <param name="type"></param>
        /// <returns></returns>
        private string ReturnLevel(int type)//为了返回显示在listviewInfo中的level的类型
        {
            string res = null;
            switch (type)
            {
                case 1:
                    res = "ERR_LEVEL";
                    break;
                case 2:
                    res = "DBG_LEVEL";
                    break;
                case 3:
                    res = "INF_LEVEL";
                    break;
                default:
                    break;
            }
            return res;
        }

        /// <summary>
        /// 实时显示信息到列表日志中
        /// </summary>
        /// <param name="Level"></param>
        /// <param name="ContentofDevice"></param>
        /// <returns></returns>
        public void WriteLog(int Level, string ContentofDevice)//实时显示信息到列表中
        {
            listViewInfo.Items.Add(new ListViewItem(new string[]
                {
                    IndexOfInfo.ToString(),
                    (DateTime.Now).ToString(),
                    ReturnLevel(Level),
                    ContentofDevice
                }));
            ++IndexOfInfo;//更新索引
        }

        public void ShowErrorMsg()
        {
            try
            {
                int Error = HCUSBSDK.USB_GetLastError();
                IntPtr res = HCUSBSDK.USB_GetErrorMsg(Error);
                string sRes = Marshal.PtrToStringAnsi(res);
                WriteLog(HCUSBSDK.ERR_LEVEL, sRes);
            }
            catch
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "Fail To Show USB Error Message in Log Information");
            }
        }

        private void buttonReboot_Click(object sender, EventArgs e)
        {
            if (!HCUSBSDK.USB_Control(m_iHandle, HCUSBSDK.USB_SET_SYSTEM_REBOOT, IntPtr.Zero))
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_SYSTEM_REBOOT fail ！");
                ShowErrorMsg();
            }
            else
            {
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_SYSTEM_REBOOT succ!");
            }
        }

        private void buttonVideoCfg_Click(object sender, EventArgs e)
        {
            VideoCfg videoCfgcb = new VideoCfg();
            videoCfgcb.m_UserID = m_iHandle;
            videoCfgcb.ShowDialog(this);
            videoCfgcb.Dispose();
        }

        private void btnImageCfg_Click(object sender, EventArgs e)
        {
            ImageCfg videoCfgcb = new ImageCfg();
            videoCfgcb.m_UserID = m_iHandle;
            videoCfgcb.ShowDialog(this);
            videoCfgcb.Dispose();
        }

        private void buttonAppendData_Click(object sender, EventArgs e)
        {
            HCUSBSDK.USB_COMMON_COND struCond = new HCUSBSDK.USB_COMMON_COND();
            HCUSBSDK.USB_JPEGPIC_WITH_APPENDDATA struJpegpicWithAppendData = new HCUSBSDK.USB_JPEGPIC_WITH_APPENDDATA();
            HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
            HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            //获取参数
            struJpegpicWithAppendData.pP2pData = Marshal.AllocHGlobal(1024 * 1024); ;
            struJpegpicWithAppendData.dwP2pDataLen = 1024*1024;
            struJpegpicWithAppendData.pJpegPic = Marshal.AllocHGlobal(1024 * 1024); ;
            struJpegpicWithAppendData.dwJpegPicLen = 1024 * 1024; ;
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struJpegpicWithAppendData));
            Marshal.StructureToPtr(struJpegpicWithAppendData, struConfigOutputInfo.lpOutBuffer, false);
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struJpegpicWithAppendData);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_iHandle, HCUSBSDK.USB_GET_JPEGPIC_WITH_APPENDDATA, pConfigInputInfo, pConfigOutputInfo))
            {
                WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_JPEGPIC_WITH_APPENDDATA Fail!");
            }
            else
            {
                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struJpegpicWithAppendData = (HCUSBSDK.USB_JPEGPIC_WITH_APPENDDATA)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_JPEGPIC_WITH_APPENDDATA));

                if (struJpegpicWithAppendData.dwJpegPicLen > 0)
                {
                    DirectoryInfo dirPath = Directory.CreateDirectory("C:\\USBCamera\\ThermalAppData");
                    string CJpegPicName = dirPath.FullName + "appendPic.jpg";

                    if (!File.Exists(CJpegPicName))
                    {
                        FileStream fs = new FileStream(CJpegPicName, FileMode.Create);
                        int iLen = (int)struJpegpicWithAppendData.dwJpegPicLen;
                        byte[] by = new byte[iLen];
                        Marshal.Copy(struJpegpicWithAppendData.pJpegPic, by, 0, iLen);
                        fs.Write(by, 0, iLen);
                        fs.Close();
                    }
                    else
                    {
                        FileStream ps = new FileStream(CJpegPicName, FileMode.Append, FileAccess.Write);
                        int iLen = (int)struJpegpicWithAppendData.dwJpegPicLen;
                        byte[] by = new byte[iLen];
                        Marshal.Copy(struJpegpicWithAppendData.pJpegPic, by, 0, iLen);
                        ps.Write(by, 0, iLen);
                        ps.Close();
                    }
                }
                WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_JPEGPIC_WITH_APPENDDATA Succ!");
            }

            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(struJpegpicWithAppendData.pJpegPic);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);
            Marshal.FreeHGlobal(pConfigOutputInfo);
        }

        private void btnThermomeCfg_Click(object sender, EventArgs e)
        {
            ThermomeCfg videoCfgcb = new ThermomeCfg();
            videoCfgcb.m_UserID = m_iHandle;
            videoCfgcb.ShowDialog(this);
            videoCfgcb.Dispose();
        }
    }
}
