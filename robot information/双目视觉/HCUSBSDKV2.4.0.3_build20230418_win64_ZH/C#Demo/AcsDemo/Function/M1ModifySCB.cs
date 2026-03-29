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
    public partial class M1ModifySCB : Form
    {

        public int m_UserID = -1;
        public CHCUsbSDK.USB_M1_MODIFY_SCB m_struM1ModifySCB = new CHCUsbSDK.USB_M1_MODIFY_SCB();

        private AcsDemo_USB MainScreen;
        private void M1ModifySCB_Load(object sender, EventArgs e)
        {
            MultiLanguage.LoadLanguage(this);
            MainScreen = (AcsDemo_USB)this.Owner;
        }

        public M1ModifySCB()
        {
            InitializeComponent();
            txtBSCBNo.Text = "1";
            txtBPwdA.Text = "00 00 00 00 00";
            txtBCtlBlock.Text = "00 00 00 00";
            txtBPwdB.Text = "00 00 00 00 00";
            m_struM1ModifySCB.Init();
        }


        private void btnModify_Click(object sender, EventArgs e)
        {
            CHCUsbSDK.USB_CONFIG_INPUT_INFO struInput = new CHCUsbSDK.USB_CONFIG_INPUT_INFO();
            CHCUsbSDK.USB_CONFIG_OUTPUT_INFO struOutput = new CHCUsbSDK.USB_CONFIG_OUTPUT_INFO();
            int dwSize = Marshal.SizeOf(m_struM1ModifySCB);

            m_struM1ModifySCB.dwSize = (int)dwSize;

            m_struM1ModifySCB.bySectionNum = 1; //扇区号
            
            //卡密码A
            for (int i=0, j=0; i < txtBPwdA.Text.Length; i+=3, j++)
            {
                //ASCII码字符转成十六进制
                m_struM1ModifySCB.byPasswordA[j] = (byte)(MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBPwdA.Text[i])) * 0x10 + MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBPwdA.Text[i+1])));
            }
            
            //控制位
            for (int i=0, j=0; i < txtBCtlBlock.Text.Length; i += 3, j++)
            {
                //ASCII码字符转成十六进制
                m_struM1ModifySCB.byCtrlBits[j] = (byte)(MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBCtlBlock.Text[i])) * 0x10 + MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBCtlBlock.Text[i + 1])));
            }

            //卡密码B
            for (int i = 0, j = 0; i < txtBPwdB.Text.Length; i += 3, j++)
            {
                //ASCII码字符转成十六进制
                m_struM1ModifySCB.byPasswordB[j] = (byte)(MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBPwdB.Text[i])) * 0x10 + MainScreen.ASCIIByteToHexByte(Convert.ToByte(txtBPwdB.Text[i + 1])));
            }

            IntPtr ptrM1ModifySCB = Marshal.AllocHGlobal(dwSize);
            Marshal.StructureToPtr(m_struM1ModifySCB, ptrM1ModifySCB, false);
            struInput.lpInBuffer = ptrM1ModifySCB;
            struInput.dwInBufferSize = (int)dwSize;
            if (CHCUsbSDK.USB_SetDeviceConfig(m_UserID, CHCUsbSDK.USB_SDK_SET_M1_MODIFY_SCB, ref struInput, ref struOutput))
            {
                MainScreen.WriteLog(CHCUsbSDK.INF_LEVEL, "USB_SDK_SET_M1_MODIFY_SCB  successfully");

            }
            else
            {
                MainScreen.WriteLog(CHCUsbSDK.ERR_LEVEL, "USB_SDK_SET_M1_MODIFY_SCB  Failed");
                MainScreen.ShowErrorMsg();
                MessageBox.Show("USB_SDK_SET_M1_MODIFY_SCB  Failed", "Error", MessageBoxButtons.OK);
            }
            Marshal.FreeHGlobal(ptrM1ModifySCB);
        }

    }
}
