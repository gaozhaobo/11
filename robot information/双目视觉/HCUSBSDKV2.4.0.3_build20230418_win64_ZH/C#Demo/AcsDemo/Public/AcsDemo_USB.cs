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

using AcsDemo_USB.Language;
using System.Threading;
using System.Globalization;
namespace AcsDemo_USB
{
    public partial class AcsDemo_USB : Form
    {
        public AcsDemo_USB()
        {
            InitializeComponent();
            bool res= CHCUsbSDK.USB_Init();//USB initialize
            IntPtr ptrLogPath = Marshal.StringToHGlobalAnsi(szLogPath);//写日志
            CHCUsbSDK.USB_SetLogToFile(3,ptrLogPath,false);//这里用枚举参数不匹配，直接写了3,
            Marshal.FreeHGlobal(ptrLogPath);
            m_VersionNum = CHCUsbSDK.USB_GetSDKVersion();
            ShowStringVersion(ref m_VersionNum);
            btnLoginDevice.Enabled = false;
            btnLogOutDevice.Enabled = false;
            //comboBoxLanguage.SelectedIndex = 0;
            //MultiLanguage.SetDefaultLanguage(comboBoxLanguage.Text);
            //foreach (Form form in Application.OpenForms)
            //{
            //    MultiLanguage.LoadLanguage(form);
            //}
            //if (comboBoxLanguage.Text == "English")
            //{
            //    Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
            //}
            //else if (comboBoxLanguage.Text == "Chinese")
            //{
            //    Thread.CurrentThread.CurrentUICulture = new CultureInfo("zh-CN");
            //}
        }

        private const int INITIALIZED_INDEX = 1;
        private uint m_VersionNum = 0;
        private string szLogPath = "C:/UsbSDKLog/";
        private int g_nEnumDevIndex = INITIALIZED_INDEX;
        private CHCUsbSDK.USB_DEVICE_INFO[] m_aHidDevInfo;//这个存储着遍历到的设备，列表索引1开始，所以添加
        public static CHCUsbSDK.EnumDeviceCallBack m_OnEnumDeviceCallBack = null;//遍历设备的回调
        private int IndexOfInfo = INITIALIZED_INDEX;//信息列表更新信息的索引,初始值为1
        private int SelectedItemsIndex=INITIALIZED_INDEX;//登录设备时选中的索引
        private CHCUsbSDK.USB_USER_LOGIN_INFO StruCurUsbLoginInfo=new CHCUsbSDK.USB_USER_LOGIN_INFO();
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
        /// 点击遍历设备
        /// </summary>
        /// <param name="sender"></param>
        /// <param name="e"></param>
        private void btnTraverse_Click(object sender, EventArgs e)//遍历设备
        {
            TraverseDevice();
        }

        private void TraverseDevice()
        {
            m_aHidDevInfo = new CHCUsbSDK.USB_DEVICE_INFO[CHCUsbSDK.MAX_USB_DEV_LEN];
            g_nEnumDevIndex = 1;
            listViewDeviceInfo.Items.Clear();                   //不把列表头都清空了，得用item.clear
            bool bExceedFlag = false;
            int dwCount = CHCUsbSDK.USB_GetDeviceCount();
            CHCUsbSDK.USB_DEVICE_INFO struDeviceInfo =  new CHCUsbSDK.USB_DEVICE_INFO();
            struDeviceInfo.Init();
            IntPtr pDeviceInfo = Marshal.AllocHGlobal(dwCount * Marshal.SizeOf(struDeviceInfo));
            //清空内存空间
            for (int i = 0; i < dwCount * Marshal.SizeOf(struDeviceInfo); i++)
            {
                Marshal.WriteByte(pDeviceInfo, i, 0);
            }
            IntPtr pTempDeviceInfo = IntPtr.Zero;

            if (CHCUsbSDK.USB_EnumDevices(dwCount, pDeviceInfo))                    //枚举设备
            {
                WriteLog(CHCUsbSDK.INF_LEVEL, "SUCCESS USB_SDK_EnumDevice()");
                pTempDeviceInfo = pDeviceInfo;
                while (--dwCount >= 0)
                {
                    struDeviceInfo = new CHCUsbSDK.USB_DEVICE_INFO();
                    struDeviceInfo = (CHCUsbSDK.USB_DEVICE_INFO)Marshal.PtrToStructure(pTempDeviceInfo, typeof(CHCUsbSDK.USB_DEVICE_INFO));
                    if (g_nEnumDevIndex == 64)
                    {
                        bExceedFlag = true;
                        break;
                    }
                    listViewDeviceInfo.Invoke(new Action(() =>
                    {
                        listViewDeviceInfo.Items.Add(new ListViewItem(new string[]
                        {
                            (g_nEnumDevIndex).ToString(),
                            struDeviceInfo.dwVID.ToString(),
                            struDeviceInfo.dwPID.ToString(),
                            System.Text.Encoding.Default.GetString(struDeviceInfo.szManufacturer),
                            System.Text.Encoding.Default.GetString(struDeviceInfo.szDeviceName),
                            System.Text.Encoding.Default.GetString(struDeviceInfo.szSerialNumber)
                        }));
                        m_aHidDevInfo[g_nEnumDevIndex - 1] = struDeviceInfo;        //存储到数组中方便登录获取数据
                        g_nEnumDevIndex++;                                          //更新索引
                    }));
                    pTempDeviceInfo += Marshal.SizeOf(struDeviceInfo);
                }
                if (bExceedFlag)
                {
                    MessageBox.Show("The total number of devices could not be over 64numbers", "Error", MessageBoxButtons.OK);
                }
            }
            else
            {
                WriteLog(CHCUsbSDK.ERR_LEVEL, "FAILED USB _SDK_EnumDevice()");
                ShowErrorMsg();
            }
            //释放内存
            if (pDeviceInfo != IntPtr.Zero)
            {
                Marshal.FreeHGlobal(pDeviceInfo);
                pDeviceInfo = IntPtr.Zero;
                pTempDeviceInfo = IntPtr.Zero;
            }
        }
        /// <summary>
        /// 转换USB_SDK_GetErrorMsg的结果成字符串显示到日志表格中
        /// </summary>
        public void ShowErrorMsg()
        {
            IntPtr res = IntPtr.Zero;
            try
            {
                uint Error = CHCUsbSDK.USB_GetLastError();
                res = CHCUsbSDK.USB_GetErrorMsg(Error);
                string sRes = Marshal.PtrToStringAnsi(res);
                WriteLog(CHCUsbSDK.ERR_LEVEL, sRes);
                res = IntPtr.Zero;
            }
            catch
            {
                res = IntPtr.Zero;
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
            StruCurUsbLoginInfo.init();

            StruCurUsbLoginInfo.dwSize         =    (int)Marshal.SizeOf(StruCurUsbLoginInfo);
            StruCurUsbLoginInfo.dwTimeout      =    5000;//登录超时时间是5秒
            StruCurUsbLoginInfo.dwVID          =    m_aHidDevInfo[SelectedItemsIndex].dwVID;
            StruCurUsbLoginInfo.dwPID          =    m_aHidDevInfo[SelectedItemsIndex].dwPID;

            System.Array.Copy(m_aHidDevInfo[SelectedItemsIndex].szSerialNumber, StruCurUsbLoginInfo.szSerialNumber, 
                m_aHidDevInfo[SelectedItemsIndex].szSerialNumber.Length);

            byte[] TempUserArr  = System.Text.Encoding.Default.GetBytes(textBoxUserName.Text.ToString());
            System.Array.Copy(TempUserArr, StruCurUsbLoginInfo.szUserName, TempUserArr.Length);

            byte[] TempszPassword = System.Text.Encoding.Default.GetBytes(textBoxPassWord.Text.ToString());
            System.Array.Copy(TempszPassword, StruCurUsbLoginInfo.szPassword, TempszPassword.Length);


            CHCUsbSDK.USB_DEVICE_REG_RES StruDeviceRegRes = new CHCUsbSDK.USB_DEVICE_REG_RES();
            StruDeviceRegRes.init();
            StruDeviceRegRes.dwSize = (int)Marshal.SizeOf(StruDeviceRegRes);
           
            int UserIDTemp = UserID;
            
            UserID = CHCUsbSDK.USB_Login(ref StruCurUsbLoginInfo, ref StruDeviceRegRes);
            if(UserID==CHCUsbSDK.INVALID_USER_ID)
            {
                ShowErrorMsg();
                UserID = UserIDTemp;//为了解决重复登录时的问题，但是这次只考虑了只能登录一个设备，两个设备同时能登录的话，ID会覆盖得继续解决ID的问题
            }
            else
            {
                string SuccesfulLoginInfo = "The device whose serial number is " + System.Text.Encoding.Default.GetString(StruCurUsbLoginInfo.szSerialNumber) + "login in successfully";
                WriteLog(CHCUsbSDK.INF_LEVEL, SuccesfulLoginInfo);
            }
        }

        private void btnLogOutDevice_Click(object sender, EventArgs e)
        {
            if (CHCUsbSDK.USB_Logout(UserID))
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
            activateCard.Owner = this;

            activateCard.ShowDialog(this);
            activateCard.Dispose();
        }

        private void btnCertificateConfig_Click(object sender, EventArgs e)
        {
            CertificateCard certificateCard = new CertificateCard();
            certificateCard.m_UserID = UserID;
            certificateCard.ShowDialog(this);
            certificateCard.Dispose();
        }

        public const int WM_DEVICECHANGE = 0x0219;
        protected override void WndProc(ref Message m)
        {
            if (m.Msg == WM_DEVICECHANGE)
            {
                TraverseDevice();
            }
            base.WndProc(ref m);
        }

        private void btnM1PwdVerify_Click(object sender, EventArgs e)
        {
            M1PwdVerify m1pwdverify = new M1PwdVerify();
            m1pwdverify.m_UserID = UserID;
            m1pwdverify.ShowDialog(this);
            m1pwdverify.Dispose();
        }

        private void btnM1ModifySCB_Click(object sender, EventArgs e)
        {
            M1ModifySCB m1modifyscb = new M1ModifySCB();
            m1modifyscb.m_UserID = UserID;
            m1modifyscb.ShowDialog(this);
            m1modifyscb.Dispose();
        }

        public byte ASCIIByteToHexByte(byte byData)
        {
            byte byTemp = 0;
            if (byData >= 'A' && byData <= 'F')
            {
                byTemp = (byte)(byData - 55);
            }
            if (byData >= 'a' && byData <= 'f')
            {
                byTemp = (byte)(byData - 55 - 32);
            }
            if (byData >= '0' && byData <= '9')
            {
                byTemp = (byte)(byData - 48);
            }

            return byTemp;
        }

        private string ConvertHexToTen(string str)
        {
            double result = 0;
            Dictionary<char, int> dict = new Dictionary<char, int>{
            {'0',0},{'1',1},{'2',2},{'3',3},{'4',4},{'5',5}
            ,{'6',6},{'7',7},{'8',8},{'9',9},{'A',10},{'B',11}
            ,{'C',12},{'D',13},{'E',14},{'F',15}
            };
            for (int i = 0; i < str.Length;i++ )
            {
                result = result * 16 + dict[str[i]];
            }
            return result.ToString();
        }

        private void btnGetCardNo_Click(object sender, EventArgs e)
        {
            if(!ActivateCard.bIsActivated)
            {
                MessageBox.Show("Please activate card first!");
                return;
            }
            string cardNo = ActivateCard.szCardNo;
            string[] sArray = cardNo.Split('-');
            cardNo = string.Empty;
            for (int i = sArray.Length - 1; i >= 0; --i) cardNo = sArray[i] + cardNo;
            int loc = 0;
            while (cardNo[loc] == '0') loc++;
            cardNo = cardNo.Substring(loc);
            cardNo = ConvertHexToTen(cardNo);
            MessageBox.Show("cardNo: " + cardNo);
        }

        private void comboBoxLanguage_SelectedIndexChanged(object sender, EventArgs e)
        {
            if (comboBoxLanguage.Text != null)
            {
                MultiLanguage.SetDefaultLanguage(comboBoxLanguage.Text);
                foreach (Form form in Application.OpenForms)
                {
                    MultiLanguage.LoadLanguage(form);
                }

                if (comboBoxLanguage.Text == "English")
                {
                    Thread.CurrentThread.CurrentUICulture = new CultureInfo("en-US");
                }
                else if (comboBoxLanguage.Text == "Chinese")
                {
                    Thread.CurrentThread.CurrentUICulture = new CultureInfo("zh-CN");
                }
            }
        }

    }
}
