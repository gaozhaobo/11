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
    public partial class ImageCfg : Form
    {
        public int m_UserID = -1;
        HCUSBSDK.USB_COMMON_COND struCond = new HCUSBSDK.USB_COMMON_COND();
        HCUSBSDK.USB_IMAGE_BRIGHTNESS struImageBrightness = new HCUSBSDK.USB_IMAGE_BRIGHTNESS();
        HCUSBSDK.USB_IMAGE_CONTRAST struImageContrast = new HCUSBSDK.USB_IMAGE_CONTRAST();

        HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
        HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

        private ThermalDemo MainScreen;
        public ImageCfg()
        {
            InitializeComponent();
        }
        private void ImageCfg_Load(object sender, EventArgs e)
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
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageBrightness));
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struImageBrightness);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_UserID, HCUSBSDK.USB_GET_IMAGE_BRIGHTNESS, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_IMAGE_BRIGHTNESS Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_IMAGE_BRIGHTNESS Succ");

                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struImageBrightness = (HCUSBSDK.USB_IMAGE_BRIGHTNESS)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_IMAGE_BRIGHTNESS));
                txtBrightness.Text = struImageBrightness.dwBrightness.ToString();
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);

        }

        private void buttonSet_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            struImageBrightness.dwBrightness = int.Parse(txtBrightness.Text);
            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageBrightness));
            Marshal.StructureToPtr(struImageBrightness, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struImageBrightness);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (!HCUSBSDK.USB_SetDeviceConfig(m_UserID, HCUSBSDK.USB_SET_IMAGE_BRIGHTNESS, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_IMAGE_BRIGHTNESS Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_IMAGE_BRIGHTNESS Succ");
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
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageContrast));
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struImageContrast);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_UserID, HCUSBSDK.USB_GET_IMAGE_CONTRAST, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_IMAGE_CONTRAST Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_IMAGE_CONTRAST Succ");
                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struImageContrast = (HCUSBSDK.USB_IMAGE_CONTRAST)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_IMAGE_CONTRAST));
                textBoxContrast.Text = struImageContrast.dwContrast.ToString();
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);
        }

        private void btnset_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            struImageContrast.dwContrast = int.Parse(textBoxContrast.Text);
            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageContrast));
            Marshal.StructureToPtr(struImageContrast, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struImageContrast);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (!HCUSBSDK.USB_SetDeviceConfig(m_UserID, HCUSBSDK.USB_SET_IMAGE_CONTRAST, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_IMAGE_CONTRAST Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_IMAGE_CONTRAST Succ");
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);
        }
    }
}
