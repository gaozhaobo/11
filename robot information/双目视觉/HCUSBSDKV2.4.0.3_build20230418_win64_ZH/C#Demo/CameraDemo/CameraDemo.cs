using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Runtime.InteropServices;
using System.Threading;

namespace CameraDemo
{
    public partial class CameraDemo : Form
    {

        public const int MAX_PATH = 260;

        int m_iFDChannel1 = -1;
        int m_iFDChannel2 = -1;
        int m_iHandle1 = -1;
        int m_iHandle2 = -1;
        int m_iPreviewHandle1 = -1;
        int m_iPreviewHandle2 = -1;
        private static HCUSBSDK.FDResultCallBack m_FDDataCB = new HCUSBSDK.FDResultCallBack(MsgCallback);

        public CameraDemo()
        {
            InitializeComponent();
        }

        public const int DEV_START_INDEX = 0;
        private void CameraDemo_Load(object sender, EventArgs e)
        {
            HCUSBSDK.USB_Init();
            HCUSBSDK.USB_SetLogToFile(3, "C:\\USBSdkLog\\", true);

            InitUIConfig();
        }

        public static void MsgCallback(int lPort, IntPtr pstruRes, IntPtr pUser)
         {
             //MessageBox.Show("MsgCallbac!");
             HCUSBSDK.USB_FD_RESULT_PARAM struFDResultInfo = new HCUSBSDK.USB_FD_RESULT_PARAM();
             struFDResultInfo = (HCUSBSDK.USB_FD_RESULT_PARAM)Marshal.PtrToStructure(pstruRes, typeof(HCUSBSDK.USB_FD_RESULT_PARAM));
             
             System.DateTime currentTime = new System.DateTime();
             currentTime = System.DateTime.Now;
             string strDate = currentTime.ToString("yyyyMMddhhmmss");

             if (struFDResultInfo.dwFaceTotalNum > 0)      //保存人脸识别背景大图
             {
                 DirectoryInfo dirPath = Directory.CreateDirectory("C:\\USBCameraPicture\\RGB_" + struFDResultInfo.struMediaData.dwWidth + "_" + struFDResultInfo.struMediaData.dwHeight);
                 string CJpegPicName = dirPath.FullName + "\\[" + strDate + "]" + ".nv12";

                 if (!File.Exists(CJpegPicName))
                 {
                     FileStream fs = new FileStream(CJpegPicName, FileMode.Create, FileAccess.Write);
                     int iLen = struFDResultInfo.struMediaData.dwLen;
                     byte[] by = new byte[iLen];
                     Marshal.Copy(struFDResultInfo.struMediaData.pBuffer, by, 0, iLen);
                     fs.Write(by, 0, iLen);
                     fs.Close();
                 }
             }

             for (int i = 0; i < struFDResultInfo.dwFaceTotalNum; i++)
             {
                 DirectoryInfo dirPath = Directory.CreateDirectory("C:\\USBCameraPicture\\SubPic_" + struFDResultInfo.struFaceParam[i].struSubFacePic.dwWidth + "_" + struFDResultInfo.struFaceParam[i].struSubFacePic.dwHeight);
                 string CJpegPicName = dirPath.FullName + "\\[" + strDate + "]" + ".nv12";

                 if (struFDResultInfo.struFaceParam[i].struFaceQualityList.fFaceScore > 0.5)  //设置人脸图片评分阈值，挑选较优人脸图保存子图
                 {
                     if (!File.Exists(CJpegPicName))
                     {
                         FileStream fs = new FileStream(CJpegPicName, FileMode.Create);
                         int iLen = struFDResultInfo.struFaceParam[i].struSubFacePic.dwSubFacePicLen;
                         byte[] by = new byte[iLen];
                         Marshal.Copy(struFDResultInfo.struFaceParam[i].struSubFacePic.pSubFacePic, by, 0, iLen);
                         fs.Write(by, 0, iLen);
                         fs.Close();
                     }
                 }
             }

         }

        private void InitUIConfig()
        {
            int nDeviceNum = HCUSBSDK.USB_GetDeviceCount();
            if (nDeviceNum <= 0)
            {
                MessageBox.Show("当前无设备！");
                return;
            }

            //结构体数组转IntPtr
            HCUSBSDK.USB_DEVICE_INFO[] struDevInfo = new HCUSBSDK.USB_DEVICE_INFO[nDeviceNum];
            int dwSize = Marshal.SizeOf(struDevInfo[0]);
            IntPtr pDevInfoList = Marshal.AllocHGlobal(dwSize * nDeviceNum);

            long longPtr = pDevInfoList.ToInt64();
            for (int i = 0; i < struDevInfo.Length; i++)
            {
                IntPtr pDevInfo = new IntPtr(longPtr);
                Marshal.StructureToPtr(struDevInfo[i], pDevInfo, false);
                longPtr += Marshal.SizeOf(typeof(HCUSBSDK.USB_DEVICE_INFO));
            }

            if (!HCUSBSDK.USB_EnumDevices(nDeviceNum, pDevInfoList))
            {
                Marshal.FreeHGlobal(pDevInfoList);
                MessageBox.Show("USB_EnumDevices fail！");
                return;
            }
            if (nDeviceNum == 0)
            {
                Marshal.FreeHGlobal(pDevInfoList);
                MessageBox.Show("当前无设备！");
                return;
            }
            for (int i = 0; i < nDeviceNum; i++)
            {
                //IntPtr转结构体数组
                pDevInfoList += i * Marshal.SizeOf(typeof(HCUSBSDK.USB_DEVICE_INFO));
                struDevInfo[i] = (HCUSBSDK.USB_DEVICE_INFO)Marshal.PtrToStructure(pDevInfoList, typeof(HCUSBSDK.USB_DEVICE_INFO));
            }           

            if (nDeviceNum >1)
            {
                textDevice1Name.Text = System.Text.Encoding.Default.GetString(struDevInfo[0].szDeviceName);
                textDevice2Name.Text = System.Text.Encoding.Default.GetString(struDevInfo[1].szDeviceName);
            }
            else
            {
                textDevice1Name.Text = System.Text.Encoding.Default.GetString(struDevInfo[0].szDeviceName);
            }

                   
            if (textDevice1Name.Text != "")
            {
                //获取相机视频能力参数 
                HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
                HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

                IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
                Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);
                IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

                //结构体数组转IntPtr
                HCUSBSDK.USB_VIDEO_CAPACITY[] struVideoCap = new HCUSBSDK.USB_VIDEO_CAPACITY[100];

                IntPtr pOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struVideoCap[0]) * 100);
                longPtr = pOutBuffer.ToInt64();
                for (int i = 0; i < struVideoCap.Length; i++)
                {
                    IntPtr pStruVideoCap = new IntPtr(longPtr);
                    Marshal.StructureToPtr(struVideoCap[i], pStruVideoCap, false);
                    longPtr += Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY));
                }

                struConfigOutputInfo.lpOutBuffer = pOutBuffer;
                struConfigOutputInfo.dwOutBufferSize = 4;
                Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

                

                //登录参数
                HCUSBSDK.USB_DEVICE_INFO struUsbDeviceInfo = new HCUSBSDK.USB_DEVICE_INFO();
                struUsbDeviceInfo.dwSize = Marshal.SizeOf(struUsbDeviceInfo);
                struUsbDeviceInfo = struDevInfo[0];

                HCUSBSDK.USB_USER_LOGIN_INFO m_struCurUsbLoginInfo = new HCUSBSDK.USB_USER_LOGIN_INFO();
                m_struCurUsbLoginInfo.dwSize = Marshal.SizeOf(m_struCurUsbLoginInfo);
                m_struCurUsbLoginInfo.dwTimeout = 5000;
                m_struCurUsbLoginInfo.dwVID = struUsbDeviceInfo.dwVID;
                m_struCurUsbLoginInfo.dwPID = struUsbDeviceInfo.dwPID;
                m_struCurUsbLoginInfo.szSerialNumber = System.Text.Encoding.Default.GetString(struUsbDeviceInfo.szSerialNumber);

                IntPtr pUsbLoginInfo = Marshal.AllocHGlobal(m_struCurUsbLoginInfo.dwSize);
                Marshal.StructureToPtr(m_struCurUsbLoginInfo, pUsbLoginInfo, false);

                HCUSBSDK.USB_DEVICE_REG_RES struDeviceRegRes = new HCUSBSDK.USB_DEVICE_REG_RES(); ;
                struDeviceRegRes.dwSize = Marshal.SizeOf(struDeviceRegRes);
                IntPtr pDevRegRes = Marshal.AllocHGlobal(struDeviceRegRes.dwSize);

                m_iHandle1 = HCUSBSDK.USB_Login(pUsbLoginInfo, pDevRegRes);
                if (m_iHandle1 < 0)
                {
                    MessageBox.Show("打开设备1失败");
                    Marshal.FreeHGlobal(pConfigInputInfo);
                    Marshal.FreeHGlobal(pConfigOutputInfo);
                    Marshal.FreeHGlobal(pOutBuffer);
                    Marshal.FreeHGlobal(pUsbLoginInfo);
                    Marshal.FreeHGlobal(pDevRegRes);
                    Marshal.FreeHGlobal(pDevInfoList);
                    return;
                }

                bool bRet = HCUSBSDK.USB_GetDeviceConfig(m_iHandle1, HCUSBSDK.USB_GET_VIDEO_CAP, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();
                }
                else
                {
                    struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                    for (int i = 0; i < 100; i++)
                    {
                        //IntPtr转结构体数组
                        struConfigOutputInfo.lpOutBuffer += i * 416;/*Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY))*/;
                        struVideoCap[i] = (HCUSBSDK.USB_VIDEO_CAPACITY)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_VIDEO_CAPACITY));

                        if (0 == struVideoCap[i].nType && 0 == struVideoCap[i].dwWidth && 0 == struVideoCap[i].dwHeight)
                        {
                            comboBoxVideo1Param.SelectedIndex = 0;
                            break;
                        }

                        string videoInfo = "";
                        if (101 == struVideoCap[i].nType)
                        {
                            videoInfo = "[MJPEG][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        else if (102 == struVideoCap[i].nType)
                        {
                            videoInfo = "[YUV][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        else if (103 == struVideoCap[i].nType)
                        {
                            videoInfo = "[H264][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        comboBoxVideo1Param.Items.Add(videoInfo);
                    }
                    
                }

                Marshal.FreeHGlobal(pConfigInputInfo);
                Marshal.FreeHGlobal(pConfigOutputInfo);
                Marshal.FreeHGlobal(pOutBuffer);
                Marshal.FreeHGlobal(pUsbLoginInfo);
                Marshal.FreeHGlobal(pDevRegRes);                
            }

            if (textDevice2Name.Text != "")
            {
                //获取相机视频能力参数 
                HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
                HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

                IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
                Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);
                IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

                //结构体数组转IntPtr
                HCUSBSDK.USB_VIDEO_CAPACITY[] struVideoCap = new HCUSBSDK.USB_VIDEO_CAPACITY[100];

                IntPtr pOutBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struVideoCap[0]) * 100);
                longPtr = pOutBuffer.ToInt64();
                for (int i = 0; i < struVideoCap.Length; i++)
                {
                    IntPtr pStruVideoCap = new IntPtr(longPtr);
                    Marshal.StructureToPtr(struVideoCap[i], pStruVideoCap, false);
                    longPtr += Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY));
                }

                struConfigOutputInfo.lpOutBuffer = pOutBuffer;
                struConfigOutputInfo.dwOutBufferSize = 4;
                Marshal.StructureToPtr(struConfigOutputInfo, pConfigOutputInfo, false);

                //登录参数
                HCUSBSDK.USB_DEVICE_INFO struUsbDeviceInfo = new HCUSBSDK.USB_DEVICE_INFO();
                struUsbDeviceInfo.dwSize = Marshal.SizeOf(struUsbDeviceInfo);
                struUsbDeviceInfo = struDevInfo[1];

                HCUSBSDK.USB_USER_LOGIN_INFO m_struCurUsbLoginInfo = new HCUSBSDK.USB_USER_LOGIN_INFO();
                m_struCurUsbLoginInfo.dwSize = Marshal.SizeOf(m_struCurUsbLoginInfo);
                m_struCurUsbLoginInfo.dwTimeout = 5000;
                m_struCurUsbLoginInfo.dwVID = struUsbDeviceInfo.dwVID;
                m_struCurUsbLoginInfo.dwPID = struUsbDeviceInfo.dwPID;
                m_struCurUsbLoginInfo.szSerialNumber = System.Text.Encoding.Default.GetString(struUsbDeviceInfo.szSerialNumber);

                IntPtr pUsbLoginInfo = Marshal.AllocHGlobal(m_struCurUsbLoginInfo.dwSize);
                Marshal.StructureToPtr(m_struCurUsbLoginInfo, pUsbLoginInfo, false);

                HCUSBSDK.USB_DEVICE_REG_RES struDeviceRegRes = new HCUSBSDK.USB_DEVICE_REG_RES(); ;
                struDeviceRegRes.dwSize = Marshal.SizeOf(struDeviceRegRes);
                IntPtr pDevRegRes = Marshal.AllocHGlobal(struDeviceRegRes.dwSize);

                m_iHandle2 = HCUSBSDK.USB_Login(pUsbLoginInfo, pDevRegRes);
                if (m_iHandle2 < 0)
                {
                    MessageBox.Show("打开设备2失败");
                    Marshal.FreeHGlobal(pConfigInputInfo);
                    Marshal.FreeHGlobal(pConfigOutputInfo);
                    Marshal.FreeHGlobal(pOutBuffer);
                    Marshal.FreeHGlobal(pUsbLoginInfo);
                    Marshal.FreeHGlobal(pDevRegRes);
                    Marshal.FreeHGlobal(pDevInfoList);
                    return;
                }

                bool bRet = HCUSBSDK.USB_GetDeviceConfig(m_iHandle2, HCUSBSDK.USB_GET_VIDEO_CAP, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();

                }
                else
                {
                    struConfigOutputInfo = (HCUSBSDK.USB_CONFIG_OUTPUT_INFO)Marshal.PtrToStructure(pConfigOutputInfo, typeof(HCUSBSDK.USB_CONFIG_OUTPUT_INFO));
                    for (int i = 0; i < 100; i++)
                    {
                        //IntPtr转结构体数组
                        struConfigOutputInfo.lpOutBuffer += i * 416;/*Marshal.SizeOf(typeof(HCUSBSDK.USB_VIDEO_CAPACITY))*/;
                        struVideoCap[i] = (HCUSBSDK.USB_VIDEO_CAPACITY)Marshal.PtrToStructure(struConfigOutputInfo.lpOutBuffer, typeof(HCUSBSDK.USB_VIDEO_CAPACITY));

                        if (0 == struVideoCap[i].nType && 0 == struVideoCap[i].dwWidth && 0 == struVideoCap[i].dwHeight)
                        {
                            comboBoxVideo2Param.SelectedIndex = 0;
                            break;
                        }

                        string videoInfo = "";
                        if (101 == struVideoCap[i].nType)
                        {
                            videoInfo = "[MJPEG][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        else if (102 == struVideoCap[i].nType)
                        {
                            videoInfo = "[YUV][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        else if (103 == struVideoCap[i].nType)
                        {
                            videoInfo = "[H264][" + struVideoCap[i].dwWidth + "w*" + struVideoCap[i].dwHeight + "h][" + struVideoCap[i].lFrameRates[0] + "]fps";
                        }
                        comboBoxVideo2Param.Items.Add(videoInfo);
                    }
                }

                Marshal.FreeHGlobal(pConfigInputInfo);
                Marshal.FreeHGlobal(pConfigOutputInfo);
                Marshal.FreeHGlobal(pOutBuffer);
                Marshal.FreeHGlobal(pUsbLoginInfo);
                Marshal.FreeHGlobal(pDevRegRes);
            }
        }

        private void btnEnumDevice_Click(object sender, EventArgs e)
        {

            //配置视频参数
            bool bRet = false;

            HCUSBSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUSBSDK.USB_CONFIG_INPUT_INFO();
            HCUSBSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUSBSDK.USB_CONFIG_OUTPUT_INFO();

            //配置相机视频参数 
            HCUSBSDK.USB_VIDEO_PARAM struVideoParam = new HCUSBSDK.USB_VIDEO_PARAM();
            struVideoParam.dwVideoFormat = HCUSBSDK.USB_STREAM_MJPEG;
            struVideoParam.dwFramerate = 30;
            struVideoParam.dwWidth = 640;
            struVideoParam.dwHeight = 480;

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struVideoParam));
            Marshal.StructureToPtr(struVideoParam, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struVideoParam);

            IntPtr pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            IntPtr pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if(checkBoxEnable1.Checked)
            {
                bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle1, HCUSBSDK.USB_SET_VIDEO_PARAM, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();
                }
            }
            if (checkBoxEnable2.Checked)
            {
                 bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle2, HCUSBSDK.USB_SET_VIDEO_PARAM, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();
                }
            }
           
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);

            //配置相机视频参数
            HCUSBSDK.USB_SRC_STREAM_CFG struSrcStreamCfg = new HCUSBSDK.USB_SRC_STREAM_CFG();
            struSrcStreamCfg.dwStreamType = HCUSBSDK.USB_STREAM_MJPEG;
            struSrcStreamCfg.bUseAudio = 0;

            struConfigInputInfo.lpInBuffer = Marshal.AllocHGlobal(Marshal.SizeOf(struSrcStreamCfg));
            Marshal.StructureToPtr(struSrcStreamCfg, struConfigInputInfo.lpInBuffer, false);
            struConfigInputInfo.dwInBufferSize = Marshal.SizeOf(struSrcStreamCfg);

            pConfigInputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigInputInfo));
            Marshal.StructureToPtr(struConfigInputInfo, pConfigInputInfo, false);

            pConfigOutputInfo = Marshal.AllocHGlobal(Marshal.SizeOf(struConfigOutputInfo));

            if (checkBoxEnable1.Checked)
            {
                bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle1, HCUSBSDK.USB_SET_SRC_STREAM_TYPE, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();
                }
            }
            if (checkBoxEnable2.Checked)
            {
                bRet = HCUSBSDK.USB_SetDeviceConfig(m_iHandle1, HCUSBSDK.USB_SET_SRC_STREAM_TYPE, pConfigInputInfo, pConfigOutputInfo);
                if (!bRet)
                {
                    long iErr = HCUSBSDK.USB_GetLastError();
                }
            }
           
            Marshal.FreeHGlobal(pConfigInputInfo);
            Marshal.FreeHGlobal(pConfigOutputInfo);
            Marshal.FreeHGlobal(struConfigInputInfo.lpInBuffer);

            //开启预览
            if (checkBoxEnable1.Checked)
            {
                HCUSBSDK.USB_PREVIEW_PARAM lpPreviewParam = new HCUSBSDK.USB_PREVIEW_PARAM();
                lpPreviewParam.dwStreamType = (uint)HCUSBSDK.USB_STREAM_PS_MJPEG;
                lpPreviewParam.byUseAudio = 0;
                lpPreviewParam.dwChannel = 1;
                lpPreviewParam.hWindow = PreviewPanel1.Handle;
                lpPreviewParam.dwSize = (uint)Marshal.SizeOf(lpPreviewParam);

                m_iPreviewHandle1 = HCUSBSDK.USB_StartPreview(m_iHandle1, ref lpPreviewParam);
                if (m_iPreviewHandle1 < 0)
                {
                    MessageBox.Show("预览失败");
                }

                if (checkBoxEnableFD.Checked)
                {
                    HCUSBSDK.USB_FACE_DETECT_PARAM struFDParam = new HCUSBSDK.USB_FACE_DETECT_PARAM();
                    struFDParam.Init();
                    if (struFDParam.fnFaceDetectCB == null)
                    {
                        struFDParam.fnFaceDetectCB = m_FDDataCB;
                    }

                    struFDParam.bySnapMode = 0;
                    IntPtr p = new IntPtr(11);
                    struFDParam.pUser = p;
                    IntPtr pFaceDetectParam = Marshal.AllocHGlobal(Marshal.SizeOf(struFDParam));
                    Marshal.StructureToPtr(struFDParam, pFaceDetectParam, false);

                    //启动人脸检测
                    m_iFDChannel1 = HCUSBSDK.USB_StartFaceDetect(m_iHandle1, pFaceDetectParam);
                    if (m_iFDChannel1 < 0)
                    {
                        MessageBox.Show("启动人脸识别失败");
                    }
                }

            }
            if (checkBoxEnable2.Checked)
            {
                HCUSBSDK.USB_PREVIEW_PARAM lpPreviewParam = new HCUSBSDK.USB_PREVIEW_PARAM();
                lpPreviewParam.dwStreamType = (uint)HCUSBSDK.USB_STREAM_PS_MJPEG;
                lpPreviewParam.byUseAudio = 0;
                lpPreviewParam.dwChannel = 1;
                lpPreviewParam.hWindow = PreviewPanel2.Handle;
                lpPreviewParam.dwSize = (uint)Marshal.SizeOf(lpPreviewParam);

                m_iPreviewHandle2 = HCUSBSDK.USB_StartPreview(m_iHandle2, ref lpPreviewParam);
                if (m_iPreviewHandle2 < 0)
                {
                    MessageBox.Show("预览失败");
                }

                if (checkBoxEnableFD.Checked)
                {
                    HCUSBSDK.USB_FACE_DETECT_PARAM struFDParam = new HCUSBSDK.USB_FACE_DETECT_PARAM();
                    struFDParam.Init();
                    if (struFDParam.fnFaceDetectCB == null)
                    {
                        struFDParam.fnFaceDetectCB = m_FDDataCB;
                    }

                    struFDParam.bySnapMode = 0;
                    IntPtr p = new IntPtr(10);
                    struFDParam.pUser = p;
                    IntPtr pFaceDetectParam = Marshal.AllocHGlobal(Marshal.SizeOf(struFDParam));
                    Marshal.StructureToPtr(struFDParam, pFaceDetectParam, false);

                    //启动人脸检测
                    m_iFDChannel2 = HCUSBSDK.USB_StartFaceDetect(m_iHandle2, pFaceDetectParam);
                    if (m_iFDChannel2 < 0)
                    {
                        MessageBox.Show("启动人脸识别失败");
                    }
                }
            }

        }

        private void Snap_Click(object sender, EventArgs e)
        {
            HCUSBSDK.USB_CAPTURE_PARAM lpCaptuerParam = new HCUSBSDK.USB_CAPTURE_PARAM();                       
            if (checkBoxEnable1.Checked)
            {
                string str = "C:\\test1.jpg";
                lpCaptuerParam.szFilePath = System.Text.Encoding.Default.GetBytes(str.Trim().PadRight(260, '\0').ToCharArray());
                lpCaptuerParam.pBuf = Marshal.AllocHGlobal(10 * 1024 * 1024);

                if (!HCUSBSDK.USB_Capture(m_iHandle1, ref lpCaptuerParam))
                {
                    MessageBox.Show("Dev1 抓图失败！");
                }
                else
                {
                    MessageBox.Show("Dev1 抓图成功！");
                }
            }
            if (checkBoxEnable2.Checked)
            {
                string str = "C:\\test2.jpg";
                lpCaptuerParam.szFilePath = System.Text.Encoding.Default.GetBytes(str.Trim().PadRight(260, '\0').ToCharArray());
                lpCaptuerParam.pBuf = Marshal.AllocHGlobal(10 * 1024 * 1024);

                if (!HCUSBSDK.USB_Capture(m_iHandle2, ref lpCaptuerParam))
                {
                    MessageBox.Show("Dev2 抓图失败！");
                }
                else
                {
                    MessageBox.Show("Dev2 抓图成功！");
                }
            }
            
        }

        private void checkBoxEnableFD_CheckedChanged(object sender, EventArgs e)
        {
            //MessageBox.Show("C# Demo暂不支持,待更新！");
            //if (-1 != m_iPreviewHandle2 || -1 != m_iPreviewHandle2)
            //{
            //    MessageBox.Show("请先启动人脸识别，再开启预览！");
            //}
        }

        private void btStopPreview_Click(object sender, EventArgs e)
        {
            if (m_iFDChannel1 >= 0 && m_iHandle1 >= 0)
            {
                HCUSBSDK.USB_StopChannel(m_iHandle1, m_iFDChannel1);
                HCUSBSDK.USB_StopChannel(m_iHandle2, m_iFDChannel1);
                m_iFDChannel1 = -1;
            }
            if (m_iFDChannel2 >= 0 && m_iHandle2 >= 0)
            {
                HCUSBSDK.USB_StopChannel(m_iHandle2, m_iFDChannel2);
                HCUSBSDK.USB_StopChannel(m_iHandle2, m_iFDChannel2);
                m_iFDChannel2 = -1;
            }

            if (m_iHandle1 >= 0 && m_iPreviewHandle1 >= 0)
            {
                HCUSBSDK.USB_StopChannel(m_iHandle1, m_iPreviewHandle1);
                m_iPreviewHandle1 = -1;
                PreviewPanel1.Refresh();
            }

            if (m_iHandle2 >= 0 && m_iPreviewHandle2 >= 0)
            {
                HCUSBSDK.USB_StopChannel(m_iHandle2, m_iPreviewHandle2);
                m_iPreviewHandle2 = -1;
                PreviewPanel2.Refresh();
            }
        }
    }
}