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
    public partial class ActivateCard : Form
    {
       

        private int WaitSecond = 0;
        public int m_UserID = 0;
        private static AcsDemo_USB MainScreen;
        private readonly string[] aCardProto = new string[] { "0-TypeA M1卡", "1-TypeA CPU卡", "2-TypeB", "3-125KHz ID卡" };

        public static bool bIsActivated = false;
        public static string szCardNo = string.Empty;

        public ActivateCard()
        {
            InitializeComponent();
            szCardNo = string.Empty;
            bIsActivated = false;
        }


        private void ActivateCard_Load(object sender, EventArgs e)
        {
            MultiLanguage.LoadLanguage(this);
            MainScreen = (AcsDemo_USB)this.Owner;
        }

        private void CheckValidityOfWaitSecond()
        {
            try
            {
                int.TryParse(labWaitSecond.Text.ToString(), out WaitSecond);
                if (WaitSecond < 0 || WaitSecond > 255)
                {
                    string MentionInfo = "The range of waitSecond is between 0 and 254, 0 represents the device would be always waiting response of device";
                    MainScreen.WriteLog(CHCUsbSDK.ERR_LEVEL, MentionInfo);
                    MessageBox.Show(MentionInfo);
                }
            }
            catch (Exception ep)
            {
                MainScreen.WriteLog(CHCUsbSDK.ERR_LEVEL, ep.ToString());
                MessageBox.Show(ep.ToString(), "ERROR", MessageBoxButtons.OK);
            }
        }

        private void btnActivate_Click(object sender, EventArgs e)
        {
            CheckValidityOfWaitSecond();
            CHCUsbSDK.USB_WAIT_SECOND StruWaitSecond = new CHCUsbSDK.USB_WAIT_SECOND();
            StruWaitSecond.dwSize = (int)Marshal.SizeOf(StruWaitSecond);
            StruWaitSecond.byWait = Convert.ToByte(labWaitSecond.Text.ToString());

            CHCUsbSDK.USB_CONFIG_INPUT_INFO StruInput = new CHCUsbSDK.USB_CONFIG_INPUT_INFO();
            StruInput.dwInBufferSize = StruWaitSecond.dwSize;
            //StruInput.lpCondBuffer = IntPtr.Zero;
            IntPtr ptrWaitSecond = Marshal.AllocHGlobal((int)StruWaitSecond.dwSize);
            Marshal.StructureToPtr(StruWaitSecond, ptrWaitSecond, false);
            StruInput.lpInBuffer = ptrWaitSecond;//输入缓冲区指针

            CHCUsbSDK.USB_ACTIVATE_CARD_RES StruActivateRes = new CHCUsbSDK.USB_ACTIVATE_CARD_RES();
            StruActivateRes.dwSize = (int)Marshal.SizeOf(StruActivateRes); 

            CHCUsbSDK.USB_CONFIG_OUTPUT_INFO StruOutput = new CHCUsbSDK.USB_CONFIG_OUTPUT_INFO();
            StruOutput.dwOutBufferSize = StruActivateRes.dwSize;
            IntPtr ptrStruActivateRes = Marshal.AllocHGlobal((int)StruActivateRes.dwSize);
            Marshal.StructureToPtr(StruActivateRes, ptrStruActivateRes, false);
            StruOutput.lpOutBuffer = ptrStruActivateRes;

            if (CHCUsbSDK.USB_GetDeviceConfig(m_UserID, CHCUsbSDK.USB_GET_ACTIVATE_CARD, ref StruInput, ref StruOutput))
            {
                bIsActivated = true;
                MainScreen.WriteLog(CHCUsbSDK.INF_LEVEL, "USB_GetDeviceConfig successfully");
                StruActivateRes = (CHCUsbSDK.USB_ACTIVATE_CARD_RES)Marshal.PtrToStructure(StruOutput.lpOutBuffer, typeof(CHCUsbSDK.USB_ACTIVATE_CARD_RES));
                textBoxCardProtocol.Text = aCardProto[StruActivateRes.byCardType];
                textBoxSerialLength.Text = StruActivateRes.bySerialLen.ToString();

                int SerialLength;
                int.TryParse(StruActivateRes.bySerialLen.ToString(),out SerialLength);
                string SerialNumber = null;
                for(int i=0;i<SerialLength;++i)
                {
                    SerialNumber = BitConverter.ToString(StruActivateRes.bySerial)+"  ";
                }
                textBoxSerialNumber.Text=SerialNumber;
                Array.Reverse(StruActivateRes.bySerial);
                SerialNumber = BitConverter.ToString(StruActivateRes.bySerial);
                Array.Reverse(StruActivateRes.bySerial);
                szCardNo = SerialNumber;

                textBoxSelected_Verify_Length.Text = StruActivateRes.bySelectVerifyLen.ToString();
                textBoxSelect_Verify.Text = BitConverter.ToString(StruActivateRes.bySelectVerify) + "  ";
                Marshal.FreeHGlobal(ptrStruActivateRes);
                Marshal.FreeHGlobal(ptrWaitSecond);
            }
            else
            {
                Marshal.FreeHGlobal(ptrStruActivateRes);
                Marshal.FreeHGlobal(ptrWaitSecond);
                MainScreen.WriteLog(CHCUsbSDK.ERR_LEVEL, "Fail to activate Card");
                MainScreen.ShowErrorMsg();
                MessageBox.Show("Fail to activate Card", "Error", MessageBoxButtons.OK);
            }
        }
    }
}
