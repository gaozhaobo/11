using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
namespace AcsDemo_USB
{
    public partial class AcsDemo_USB : Form
    {
        public AcsDemo_USB()
        {
            InitializeComponent();
            bool res= CHCUsbSDK.USB_SDK_Init();//USB initialize
            IntPtr ptrLogPath = Marshal.StringToHGlobalAnsi(szLogPath);//写日志
            CHCUsbSDK.USB_SDK_SetLogToFile(3,ptrLogPath,false);//这里用枚举参数不匹配，直接写了3,
            Marshal.FreeHGlobal(ptrLogPath);
            m_VersionNum = CHCUsbSDK.USB_SDK_GetSDKVersion();
            ShowStringVersion(ref m_VersionNum);
            btnLoginDevice.Enabled = false;
            btnLogOutDevice.Enabled = false;
        }

        private const int INITIALIZED_INDEX = 1;
        private uint m_VersionNum = 0;
        private string szLogPath = "C:/UsbSDKLog/";
        private int g_nEnumDevIndex = INITIALIZED_INDEX;
        private CHCUsbSDK.USB_SDK_DEVICE_INFO[] m_aHidDevInfo;//这个存储着遍历到的设备，列表索引1开始，所以添加
        public static CHCUsbSDK.EnumDeviceCallBack m_OnEnumDeviceCallBack = null;//遍历设备的回调
        private int IndexOfInfo = INITIALIZED_INDEX;//信息列表更新信息的索引,初始值为1
        private int SelectedItemsIndex=INITIALIZED_INDEX;//登录设备时选中的索引
        private CHCUsbSDK.USB_SDK_USER_LOGIN_INFO StruCurUsbLoginInfo=new CHCUsbSDK.USB_SDK_USER_LOGIN_INFO();
        private int UserID = -1;
        /// <summary>
        /// 显示在版本编号
        /// </summary>
        /// <param name="dwVersion"></param>
        private void ShowStringVersion(ref uint dwVersion)
        {
            string Sversion = string.Format("{0}.{1}.{2}.{3}", (0xff000000 & dwVersion)>>24,(0x00ff0000 & dwVersion)>>16,
                (0x0000ff00 & dwVersion) >> 8, (0x000000ff & dwVersion));
            label4.Text = Sversion;
            WriteLog(CHCUsbSDK.INF_LEVEL, "获取SDK版本" + Sversion);
        }

        /// <summary>
        /// 为了返回显示在日志Info中的level的类型是INF 还是ERR
        /// </summary>
        /// <param name="type"></param>
        /// <returns></returns>
        private string ReturnLevel(int type)//为了返回显示在listviewInfo中的level的类型
        {
            string res=null;
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
        public void WriteLog(int Level,string ContentofDevice)//实时显示信息到列表中
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

        /// <summary>
        /// 回调函数用于在空间框中显示遍历到的设备的信息
        /// </summary>
        /// <param name="pDevceInfo"></param>
        /// <param name="pUser"></param>
        /// <returns></returns>
        public void OnEnumDeviceCallBack(ref CHCUsbSDK.USB_SDK_DEVICE_INFO pDevceInfo, IntPtr pUser)//枚举设备的回调函数
        {
            CHCUsbSDK.USB_SDK_DEVICE_INFO CopyDeviceInfo = new CHCUsbSDK.USB_SDK_DEVICE_INFO();
            CopyDeviceInfo = pDevceInfo;
            CopyDeviceInfo.dwSize = (uint)Marshal.SizeOf(CopyDeviceInfo);//结构体本身的大小
            if(g_nEnumDevIndex==64)
            {
                MessageBox.Show("The total number of devices could not be over 64numbers", "Error", MessageBoxButtons.OK);
            }
            listViewDeviceInfo.BeginInvoke(new Action(() =>
            {
                listViewDeviceInfo.Items.Add(new ListViewItem(new string[]
                {
                    (g_nEnumDevIndex).ToString(),
                    CopyDeviceInfo.dwVID.ToString(),
                    CopyDeviceInfo.dwPID.ToString(),
                    CopyDeviceInfo.szManufacturer,
                    CopyDeviceInfo.szDeviceName,
                    CopyDeviceInfo.szSerialNumber
                }));
                m_aHidDevInfo[g_nEnumDevIndex - 1] = CopyDeviceInfo;//存储到数组中方便登录获取数据
                g_nEnumDevIndex++;//更新索引
            }));
        }

        /// <summary>
        /// 点击遍历设备
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnTraverse_Click(object sender, EventArgs e)//遍历设备
        {
            //m_nHidDevNum = 0;
            m_aHidDevInfo= new CHCUsbSDK.USB_SDK_DEVICE_INFO[CHCUsbSDK.MAX_USB_DEV_LEN];
            g_nEnumDevIndex = 1;
            listViewDeviceInfo.Items.Clear();//不把列表头都清空了，得用item.clear
            m_OnEnumDeviceCallBack = new CHCUsbSDK.EnumDeviceCallBack(OnEnumDeviceCallBack);
            if(CHCUsbSDK.USB_SDK_EnumDevice(m_OnEnumDeviceCallBack,IntPtr.Zero))//枚举设备
            {
                WriteLog(CHCUsbSDK.INF_LEVEL, "SUCCESS USB_SDK_EnumDevice()");
            }
            else
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "FAILED USB _SDK_EnumDevice()");
                ShowErrorMsg();
            }
        }

        /// <summary>
        /// 转换USB_SDK_GetErrorMsg的结果成字符串显示到日志表格中
        /// </summary>
        private void ShowErrorMsg()
        {
            try
            {
                uint Error = CHCUsbSDK.USB_SDK_GetLastError();
                IntPtr res = CHCUsbSDK.USB_SDK_GetErrorMsg(Error);
                string sRes = Marshal.PtrToStringAnsi(res);
                WriteLog(CHCUsbSDK.ERR_LEVEL, sRes);
            }
            catch
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "Fail To Show USB Error Message in Log Information");
            }
        }

        private void listViewDeviceInfo_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listViewDeviceInfo.SelectedItems.Count>0)
            {
                try
                {
                    SelectedItemsIndex = int.Parse(listViewDeviceInfo.FocusedItem.SubItems[0].Text)-1;
                    btnLoginDevice.Enabled = true;
                    btnLogOutDevice.Enabled = true;
                }
                catch(Exception ep)
                {
                    WriteLog(1, ep.ToString());
                    MessageBox.Show(ep.ToString(), "Error", MessageBoxButtons.OK);
                }
            }
            else
            {
                btnLoginDevice.Enabled = false;
                btnLogOutDevice.Enabled = false;
            }
        }

        /// <summary>
        /// 判断登录设备的相关信息是否是有效的
        /// </summary>
        /// <returns></returns>
        private Boolean JudgeValidOfLoginInfo()
        {
            if (textBoxUserName.TextLength>32)
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "The length of username could not be over 32 numbers");
                MessageBox.Show("The length of username could not be over 32 numbers", "Attention", MessageBoxButtons.OK);
                return false;
            }
            if (textBoxPassWord.TextLength > 16)
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "The length of password could not be over 16 numbers");
                MessageBox.Show("The length of password could not be over 16 numbers", "Attention", MessageBoxButtons.OK);
                return false;
            }
            if(listViewDeviceInfo.SelectedItems.Count<=0)
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "Please select a device firstly");
                MessageBox.Show("Please select a device firstly", "Attention", MessageBoxButtons.OK);
                return false;
            }
            return true;
        }

        private void btnLoginDevice_Click(object sender, EventArgs e)
        {
            if (!JudgeValidOfLoginInfo())
            {
                return;
            }
            StruCurUsbLoginInfo.dwSize = (uint)Marshal.SizeOf(StruCurUsbLoginInfo);
            StruCurUsbLoginInfo.dwTimeout = 5000;//登录超时时间是5秒
            StruCurUsbLoginInfo.dwVID=m_aHidDevInfo[SelectedItemsIndex].dwVID;
            StruCurUsbLoginInfo.dwPID = m_aHidDevInfo[SelectedItemsIndex].dwPID;
            StruCurUsbLoginInfo.szSerialNumber = m_aHidDevInfo[SelectedItemsIndex].szSerialNumber;
            StruCurUsbLoginInfo.szUserName = textBoxUserName.Text.ToString();
            StruCurUsbLoginInfo.szPassword = textBoxPassWord.Text.ToString();
            CHCUsbSDK.USB_SDK_DEVICE_REG_RES StruDeviceRegRes = new CHCUsbSDK.USB_SDK_DEVICE_REG_RES();
            StruDeviceRegRes.dwSize = (uint)Marshal.SizeOf(StruDeviceRegRes);
            int UserIDTemp = UserID;
            UserID = CHCUsbSDK.USB_SDK_Login(ref StruCurUsbLoginInfo, ref StruDeviceRegRes);
            if(UserID==CHCUsbSDK.INVALID_USER_ID)
            {
                ShowErrorMsg();
                UserID = UserIDTemp;//为了解决重复登录时的问题，但是这次只考虑了只能登录一个设备，两个设备同时能登录的话，ID会覆盖得继续解决ID的问题
            }
            else
            {
                string SuccesfulLoginInfo = "The device whose serial number is " + StruCurUsbLoginInfo.szSerialNumber + "login in successfully";
                WriteLog(CHCUsbSDK.INF_LEVEL, SuccesfulLoginInfo);
            }

        }

        private void btnLogOutDevice_Click(object sender, EventArgs e)
        {
            if (CHCUsbSDK.USB_SDK_Logout(UserID))
            {
                WriteLog(CHCUsbSDK.INF_LEVEL, "SUCCESS USB_SDK_Logout()");
                btnActivateCard.Enabled = true;
            }
            else
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_Logout()");
                ShowErrorMsg();
            }
        }

        private void btnActivateCard_Click(object sender, EventArgs e)
        {
            ActivateCard activateCard = new ActivateCard();
            activateCard.m_UserID = UserID;
            //activateCard.Owner = this;
            activateCard.ShowDialog(this);
            activateCard.Dispose();
        }
    }
}
