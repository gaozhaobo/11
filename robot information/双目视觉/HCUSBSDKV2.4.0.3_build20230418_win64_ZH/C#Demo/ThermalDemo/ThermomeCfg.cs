using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace ThermalDemo
{
    public partial class ThermomeCfg : Form
    {
        public int m_UserID = -1;
        HCUSBSDK.USB_COMMON_COND struCond = new HCUSBSDK.USB_COMMON_COND();
        HCUSBSDK.USB_BLACK_BODY struBlackBody = new HCUSBSDK.USB_BLACK_BODY();
        HCUSBSDK.USB_BODYTEMP_COMPENSATION struBodytempCompensation = new HCUSBSDK.USB_BODYTEMP_COMPENSATION();

        HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
        HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

        private ThermalDemo MainScreen;
        public ThermomeCfg()
        {
            InitializeComponent();
        }

        private void ThermomeCfg_Load(object sender, EventArgs e)
        {
            MainScreen = (ThermalDemo)this.Owner;
        }

        private void buttonGet_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            //获取参数
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struBlackBody));
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struBlackBody);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_UserID, HCUSBSDK.USB_GET_BLACK_BODY, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_BLACK_BODY Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_BLACK_BODY Succ");

                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struBlackBody = (HCUSBSDK.USB_BLACK_BODY)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_BLACK_BODY));

                if (1 == struBlackBody.byEnabled)
                {
                    checkBoxBlack.Checked = true;
                }
                textBoxEmissivity.Text = struBlackBody.dwEmissivity.ToString();
                textBoxDistance.Text = struBlackBody.dwDistance.ToString();
                txtTemperature.Text = struBlackBody.dwTemperature.ToString();
                textCentrePointX.Text = struBlackBody.dwCentrePointX.ToString();
                textCentrePointY.Text = struBlackBody.dwCentrePointY.ToString();
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);

            Update();
        }

        private void buttonSet_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            if( checkBoxBlack.Checked)
            {
                struBlackBody.byEnabled = 1;
            }
            struBlackBody.dwTemperature = int.Parse(txtTemperature.Text);
            struBlackBody.dwEmissivity = int.Parse(textBoxEmissivity.Text);
            struBlackBody.dwDistance = int.Parse(textBoxDistance.Text);
            struBlackBody.dwCentrePointX = int.Parse(textCentrePointX.Text);
            struBlackBody.dwCentrePointY = int.Parse(textCentrePointY.Text);

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struBlackBody));
            Marshal.StructureToPtr(struBlackBody, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struBlackBody);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (!HCUSBSDK.USB_SetDeviceConfig(m_UserID, HCUSBSDK.USB_SET_BLACK_BODY, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_BLACK_BODY Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_BLACK_BODY Succ");
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);
        }

        private void btnget_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            //获取参数
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struBodytempCompensation));
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struBodytempCompensation);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_UserID, HCUSBSDK.USB_GET_BODYTEMP_COMPENSATION, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_BODYTEMP_COMPENSATION Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_BODYTEMP_COMPENSATION Succ");

                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struBodytempCompensation = (HCUSBSDK.USB_BODYTEMP_COMPENSATION)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_BODYTEMP_COMPENSATION));

                if (1 == struBodytempCompensation.byEnabled)
                {
                    checkBoxComPensation.Checked = true;
                }

                comboBoxType.SelectedIndex = struBodytempCompensation.byType - 1;
                comboBoxCurveSensitivityLevel.SelectedIndex = struBodytempCompensation.byTemperatureCurveSensitivityLevel - 1;
                comboBoxTemperatureMode.SelectedIndex = struBodytempCompensation.byEnvironmentalTemperatureMode - 1;

                textCompensationValue.Text = struBodytempCompensation.iCompensationValue.ToString();
                textEnvironmentalTemperature.Text = struBodytempCompensation.dwEnvironmentalTemperature.ToString();
            }
           
            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);

            Update();
        }

        private void btnset_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            if (checkBoxComPensation.Checked)
            {
                struBodytempCompensation.byEnabled = 1;
            }
            struBodytempCompensation.dwEnvironmentalTemperature = int.Parse(textEnvironmentalTemperature.Text);
            struBodytempCompensation.iCompensationValue = int.Parse(textCompensationValue.Text);
            struBodytempCompensation.byType = (byte)(comboBoxType.SelectedIndex + 1);
            struBodytempCompensation.byEnvironmentalTemperatureMode = (byte)(comboBoxTemperatureMode.SelectedIndex + 1);
            struBodytempCompensation.byTemperatureCurveSensitivityLevel = (byte)(comboBoxCurveSensitivityLevel.SelectedIndex + 1);

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struBodytempCompensation));
            Marshal.StructureToPtr(struBodytempCompensation, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struBodytempCompensation);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (!HCUSBSDK.USB_SetDeviceConfig(m_UserID, HCUSBSDK.USB_SET_BODYTEMP_COMPENSATION, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_BODYTEMP_COMPENSATION Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_BODYTEMP_COMPENSATION Succ");
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);
        }
    }
}
