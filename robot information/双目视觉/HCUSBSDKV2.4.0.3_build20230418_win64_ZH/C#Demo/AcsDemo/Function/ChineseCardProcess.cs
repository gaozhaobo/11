using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing;
using System.IO;
using System.Runtime.Serialization.Formatters.Binary;
using System.Runtime.InteropServices;
namespace AcsDemo_USB
{
    /// <summary>
    /// 专门用来处理中国大陆身份证信息的读取与显示
    /// </summary>
    public class ChineseCardProcess
    {
        public CHCUsbSDK.USB_CERTIFICATE_INFO CertificateInfo;
        private int gIndex=1;
        public ChineseCardProcess(ref CHCUsbSDK.USB_CERTIFICATE_INFO PCertificateInfo)
        {
            CertificateInfo = PCertificateInfo;
        }
        public ChineseCardProcess()
        {

        }
        public void ReadCertificateInfo()
        {
            ProcessChineseCardInfo();
        }

        private void ProcessChineseCardInfo()
        {
            CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Clear();
            if (CertificateCard.CertificateCardForm.pictureBoxCertificate.Image!=null)
            {
                CertificateCard.CertificateCardForm.pictureBoxCertificate.Image.Dispose();
                CertificateCard.CertificateCardForm.pictureBoxCertificate.Image = null;
            }
            ReadChineseIDcardName();
            ReadChineseCardSex();
            ReadBirthDate();
            ReadHomeAddress();
            ReadChineseNationality();
            ReadIDnum();
            IDpictureProcess();
        }

        private void ReadChineseIDcardName()
        {
            byte[] ChineseIDName = new byte[30];
            Buffer.BlockCopy(CertificateInfo.byWordInfo, 0, ChineseIDName, 0, 30);
            string SName = Encoding.Unicode.GetString(ChineseIDName);
            string DataName = "姓名";
            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() => 
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                    (gIndex++).ToString(),
                    DataName,
                    SName
                }));
            }));
        }

        private void ReadChineseCardSex()
        {
            byte[] ChineseSex = new byte[2];
           Buffer.BlockCopy(CertificateInfo.byWordInfo, 30, ChineseSex, 0, 2);
            string Sex = "性别";
            string ChineseCardSex = Encoding.Unicode.GetString(ChineseSex);
            if (ChineseCardSex == "1")
            {
                ChineseCardSex = "男";
            }
            else
            {
                ChineseCardSex = "女";
            }

            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() => 
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                    (gIndex++).ToString(),
                    Sex,
                    ChineseCardSex
                }));
            }));
        }

        private void ReadChineseNationality()
        {
            byte[] ByteNationality = new byte[4];
            Buffer.BlockCopy(CertificateInfo.byWordInfo, 32, ByteNationality, 0, 4);
            string SNationality = "民族";
            string nationality = Encoding.Unicode.GetString(ByteNationality);
            nationality = Nationality.GetNationality(ref nationality);
            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() => 
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                   (gIndex++).ToString(),
                   SNationality,
                   nationality
                }));
            }));
        }

        private void ReadBirthDate()
        {
            byte[] Bbirthdate = new byte[16];
            Buffer.BlockCopy(CertificateInfo.byWordInfo, 36, Bbirthdate, 0, 16);
            string Sbirthdate = "出生日期";
            string BirthDate = Encoding.Unicode.GetString(Bbirthdate);
            StandardFormalOfBrithDate(ref BirthDate);

            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() =>
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                   (gIndex++).ToString(),
                   Sbirthdate,
                   BirthDate
                }));
            }));

        }
        private void StandardFormalOfBrithDate(ref string BirthDate)
        {
            string yyyy = BirthDate.Substring(0,4);
            string mm = BirthDate.Substring(4, 2);
            string dd = BirthDate.Substring(6, 2);
            BirthDate = yyyy + "-" + mm + "-" + dd;
        }

        private void ReadHomeAddress()
        {
            byte[] HomeAddress = new byte[70];
            Buffer.BlockCopy(CertificateInfo.byWordInfo, 52, HomeAddress, 0, 70);
            string home = "家庭住址";
            string Address = Encoding.Unicode.GetString(HomeAddress);
            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() =>
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                   (gIndex++).ToString(),
                   home,
                   Address
                }));
            }));
        }

        private void ReadIDnum()
        {
            byte[] IDnumber = new byte[36];
            Buffer.BlockCopy(CertificateInfo.byWordInfo, 122, IDnumber, 0, 36);
            string temp = "身份证号";
            string CertificateNum = Encoding.Unicode.GetString(IDnumber);
            CertificateCard.CertificateCardForm.listViewCertificateCard.BeginInvoke(new Action(() =>
            {
                CertificateCard.CertificateCardForm.listViewCertificateCard.Items.Add(new ListViewItem(new string[] 
                {
                   (gIndex++).ToString(),
                   temp,
                   CertificateNum
                }));
            }));
        }

        private void IDpictureProcess()
        {
            DeleteOldPicture();
            string strExeDir = "C:\\UsbSDKLog";
            string strPictureBin = strExeDir + "\\tmpIDPhoto_$_$.bin";
            try
            {
                using(FileStream fs=new FileStream(strPictureBin,FileMode.Create ,FileAccess.Write))
                {
                    try
                    {
                        fs.Write(CertificateInfo.byPicInfo, 0, CertificateInfo.wPicInfoSize);
                        fs.Flush();
                        fs.Close();
                    }
                    catch(Exception ep)
                    {
                        fs.Close();
                        MessageBox.Show(ep.ToString());
                    }
                }
            }
            catch(Exception ep)
            {
                MessageBox.Show(ep.ToString());
            }
            string strPicture = strExeDir + "\\tmpIDPhoto_$_$.bmp";
            IntPtr StrPath = Marshal.StringToHGlobalAnsi(strPictureBin);
            
            int num = CHCUsbSDK.dewlt(StrPath);
            if(num>=0)
            {
                CertificateCard.CertificateCardForm.pictureBoxCertificate.Image = Image.FromFile(strPicture);
            }
            else
            {
                MessageBox.Show("Fail to acquire the Picture", "Error", MessageBoxButtons.OK);
            }
            Marshal.FreeHGlobal(StrPath);
        }

        private void DeleteOldPicture()
        {
            string PathPic = "C:\\UsbSDKLog" + "\\tmpIDPhoto_$_$.bmp";
            if (System.IO.File.Exists(Path.GetFullPath(PathPic)))
            {
                File.Delete(Path.GetFullPath(PathPic));
            }
        }

    }
}


