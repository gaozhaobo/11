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
    public partial class VideoCfg : Form
    {
        public int m_UserID = -1;
        HCUSBSDK.USB_COMMON_COND struCond = new HCUSBSDK.USB_COMMON_COND();
        HCUSBSDK.USB_IMAGE_VIDEO_ADJUST struImageVideoAdjuse = new HCUSBSDK.USB_IMAGE_VIDEO_ADJUST();
        HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
        HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

        private ThermalDemo MainScreen;

        public VideoCfg()
        {
            InitializeComponent();
        }

        private void VideoCfg_Load(object sender, EventArgs e)
        {
            MainScreen = (ThermalDemo)this.Owner;
        }

        private void btnGet_Click(object sender, EventArgs e)
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
            struConfigOutputInfo.lpOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageVideoAdjuse));
            struConfigOutputInfo.dwOutBufferSize = Marshal.SizeOf(struImageVideoAdjuse);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));
            Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

            if (!HCUSBSDK.USB_GetDeviceConfig(m_UserID, HCUSBSDK.USB_GET_IMAGE_VIDEO_ADJUST, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_GET_IMAGE_VIDEO_ADJUST Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_GET_IMAGE_VIDEO_ADJUST Succ");

                struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                struImageVideoAdjuse = (HCUSBSDK.USB_IMAGE_VIDEO_ADJUST)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_IMAGE_VIDEO_ADJUST));

                comboBoxImageFlipStyle.SelectedIndex = (int)struImageVideoAdjuse.byImageFlipStyle;

                if (1 == struImageVideoAdjuse.byPowerLineFrequencyMode)
                {
                    textBoxPowerLineFrequencyMode.Text = "PAL".ToString();
                }
                comboBoxCorridor.SelectedIndex = (int)struImageVideoAdjuse.byCorridor;
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigOutputInfo.lpOutBuffer);
        }

        private void btnSet_Click(object sender, EventArgs e)
        {
            //条件参数
            struCond.byChannelID = 1;
            struConfigInputInfo.lpCondBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struCond));
            Marshal.StructureToPtr(struCond, struConfigInputInfo.lpCondBuffer, false);
            struConfigInputInfo.dwCondBufferSize = Marshal.SizeOf(struCond);

            //入参
            struImageVideoAdjuse.byCorridor = (byte)comboBoxImageFlipStyle.SelectedIndex;
            struImageVideoAdjuse.byImageFlipStyle = (byte)comboBoxCorridor.SelectedIndex;
            struImageVideoAdjuse.byPowerLineFrequencyMode = 1;

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struImageVideoAdjuse));
            Marshal.StructureToPtr(struImageVideoAdjuse, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struImageVideoAdjuse);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (!HCUSBSDK.USB_SetDeviceConfig(m_UserID, HCUSBSDK.USB_SET_IMAGE_VIDEO_ADJUST, pConfigInputInfo, pConfigOutputInfo))
            {
                MainScreen.WriteLog(HCUSBSDK.ERR_LEVEL, "USB_SET_IMAGE_VIDEO_ADJUST Fail");
            }
            else
            {
                MainScreen.WriteLog(HCUSBSDK.INF_LEVEL, "USB_SET_IMAGE_VIDEO_ADJUST Succ");
            }

            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpCondBuffer);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);

        }

    }
}
