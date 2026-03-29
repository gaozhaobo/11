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
using System.IO;

using AcsDemo_USB.Language;
namespace AcsDemo_USB
{
    public partial class CertificateCard : Form
     {
        public CertificateCard()
        {
            InitializeComponent();
            CertificateCardForm = this;
        }
        public int m_UserID = 0;
        private AcsDemo_USB MainScreen;
        private ChineseCardProcess ProcessChineseCard = new ChineseCardProcess();
        private void CertificateCard_Load(object sender, EventArgs e)
        {
            MultiLanguage.LoadLanguage(this);
            MainScreen = (AcsDemo_USB)this.Owner;
        }

        public static CertificateCard CertificateCardForm = null;

        private void btnAcquire_Click(object sender, EventArgs e)
        {
            CHCUsbSDK.USB_CERTIFICATE_INFO struCertificateInfo = new CHCUsbSDK.USB_CERTIFICATE_INFO();
            struCertificateInfo.dwSize = (int)Marshal.SizeOf(struCertificateInfo);

            CHCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new CHCUsbSDK.USB_CONFIG_OUTPUT_INFO();
            struConfigOutputInfo.dwOutBufferSize = struCertificateInfo.dwSize;
            IntPtr ptrstruCertificateInfo = Marshal.AllocHGlobal((int)struCertificateInfo.dwSize);
            Marshal.StructureToPtr(struCertificateInfo, ptrstruCertificateInfo, false);
            struConfigOutputInfo.lpOutBuffer = ptrstruCertificateInfo;

            CHCUsbSDK.USB_CONFIG_INPUT_INFO strConfigInputConfig = new CHCUsbSDK.USB_CONFIG_INPUT_INFO();
            if (CHCUsbSDK.USB_GetDeviceConfig(m_UserID, CHCUsbSDK.USB_GET_CERTIFICATE_INFO, ref strConfigInputConfig, ref struConfigOutputInfo))
            {
                struCertificateInfo=(CHCUsbSDK.USB_CERTIFICATE_INFO)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer,typeof (CHCUsbSDK.USB_CERTIFICATE_INFO));
                ProcessChineseCard.CertificateInfo = struCertificateInfo;
                ProcessChineseCard.ReadCertificateInfo();
            }
            else
            {
                uint dwError = CHCUsbSDK.USB_GetLastError();
                IntPtr ptrMsg = CHCUsbSDK.USB_GetErrorMsg(dwError);
                String ErrMsg = Marshal.PtrToStringAnsi(ptrMsg);
                MessageBox.Show("Fail to Read CardInfo", "ERROR", MessageBoxButtons.OK);
            }
            if (ptrstruCertificateInfo != IntPtr.Zero)
            {
                Marshal.FreeHGlobal(ptrstruCertificateInfo);
            }
        }

        private void CertificateCard_FormClosed(object sender, FormClosedEventArgs e)
        {
            CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Clear();
            if (CertificateCard.CertificateCardForm.pictureBoxCertificate.Image != null)
            {
                CertificateCard.CertificateCardForm.pictureBoxCertificate.Image.Dispose();
                CertificateCard.CertificateCardForm.pictureBoxCertificate.Image = null;
            }
        }

     }
}
