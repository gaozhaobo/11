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

using AcsDemo_USB.Language;
namespace AcsDemo_USB
{

    public partial class M1PwdVerify : Form
    {
        public int m_UserID = -1;
        public CHCUsbSDK.USB_M1_PWD_VERIFY_INFO m_struM1PwdVerifyInfo = new CHCUsbSDK.USB_M1_PWD_VERIFY_INFO();


        private AcsDemo_USB MainScreen;
        private void M1PwdVerify_Load(object sender, EventArgs e)
        {
            MultiLanguage.LoadLanguage(this);
            MainScreen = (AcsDemo_USB)this.Owner;
        }

        public M1PwdVerify()
        {
            InitializeComponent();
            combM1PwdType.SelectedIndex = 0;
            txtBSCBNoToVerify.Text = "1";
            txtBM1Pwd.Text = "00 00 00 00 00 00";
            
            m_struM1PwdVerifyInfo.Init();
        }

        public void btnVerify_Click(object sender, EventArgs e)
        {
            CHCUsbSDK.USB_CONFIG_INPUT_INFO struInput = new CHCUsbSDK.USB_CONFIG_INPUT_INFO();
            CHCUsbSDK.USB_CONFIG_OUTPUT_INFO struOutput = new CHCUsbSDK.USB_CONFIG_OUTPUT_INFO();
            int dwSize = Marshal.SizeOf(m_struM1PwdVerifyInfo);

            m_struM1PwdVerifyInfo.dwSize = (int)dwSize;
            m_struM1PwdVerifyInfo.byPasswordType = (byte)combM1PwdType.SelectedIndex;
            m_struM1PwdVerifyInfo.bySectionNum = 1;
            for (int i = 0, j=0; i < txtBM1Pwd.Text.Length; i+=3, j++)
            {
                //ASCII码字符转成十六进制
                m_struM1PwdVerifyInfo.byPassword[j] = (byte)(MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBM1Pwd.Text[i])) * 0x10 + MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBM1Pwd.Text[i + 1])));
            }
           
            IntPtr ptrM1PwdVerifyInfo = Marshal.AllocHGlobal(dwSize);
            Marshal.StructureToPtr(m_struM1PwdVerifyInfo, ptrM1PwdVerifyInfo, false);
            struInput.lpInBuffer = ptrM1PwdVerifyInfo;
            struInput.dwInBufferSize = (int)dwSize;
            if (CHCUsbSDK.USB_SetDeviceConfig(m_UserID, CHCUsbSDK.USB_SDK_SET_M1_PWD_VERIFY, ref struInput, ref struOutput))
            {
                MainScreen.WriteLog(CHCUsbSDK.INF_LEVEL, "USB_SDK_SET_M1_PWD_VERIFY successfully");

            }
            else 
            {
                MainScreen.WriteLog(CHCUsbSDK.ERR_LEVEL, "USB_SDK_SET_M1_PWD_VERIFY Failed");
                MainScreen.ShowErrorMsg();
                MessageBox.Show("USB_SDK_SET_M1_PWD_VERIFY Failed", "Error", MessageBoxButtons.OK);
            }
            Marshal.FreeHGlobal(ptrM1PwdVerifyInfo);
        }

    }
}
