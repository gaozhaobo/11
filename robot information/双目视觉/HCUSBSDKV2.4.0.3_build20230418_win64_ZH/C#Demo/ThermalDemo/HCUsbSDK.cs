using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;

namespace ThermalDemo
{
    class HCUSBSDK
    {

        /************************************************************************
        * 前端命令码定义
        ************************************************************************/
        public const int USB_CAMERA_BASE = 3000;
        public const int USB_GET_VIDEO_CAP = 3001;               // 获取视频能力集
        public const int USB_GET_AUDIO_CAP = 3002;               // 获取音频能力集
        public const int USB_GET_VIDEO_PARAM = 3003;               // 获取视频参数
        public const int USB_SET_VIDEO_PARAM = 3004;                      // 设置视频参数
        public const int USB_SET_AUDIO_PARAM = 3006;               // 设置音频参数
        public const int USB_SET_SRC_STREAM_TYPE = 3007;               // 设置原始码流类型

         /************************************************************************
        * 热成像命令码定义
        ************************************************************************/
        public const int USB_THERMAL_BASE            =     2000;
        public const int USB_GET_SYSTEM_DEVICE_INFO   =  (USB_THERMAL_BASE+11);      //获取设备信息
        public const int USB_SET_SYSTEM_REBOOT   =  (USB_THERMAL_BASE+12);      //设备重启
        public const int USB_SET_SYSTEM_RESET   =  (USB_THERMAL_BASE+13);      //恢复默认
        public const int USB_GET_SYSTEM_HARDWARE_SERVER   =  (USB_THERMAL_BASE+14) ;    //获取硬件服务参数
        public const int USB_SET_SYSTEM_HARDWARE_SERVER   =  (USB_THERMAL_BASE+15);      //设置硬件服务参数
        public const int USB_GET_SYSTEM_LOCALTIME  =   (USB_THERMAL_BASE+16);    //获取系统本地时间
        public const int USB_SET_SYSTEM_LOCALTIME   =  (USB_THERMAL_BASE+17);     //设置系统本地时间
        public const int USB_GET_IMAGE_BRIGHTNESS  =   (USB_THERMAL_BASE+18);   //获取图像亮度参数
        public const int USB_SET_IMAGE_BRIGHTNESS  =   (USB_THERMAL_BASE+19);   //设置图像亮度参数
        public const int USB_GET_IMAGE_CONTRAST   =  (USB_THERMAL_BASE+20);   //获取图像对比度参数
        public const int USB_SET_IMAGE_CONTRAST = (USB_THERMAL_BASE + 21);    //设置图像对比度参数
        public const int USB_GET_IMAGE_VIDEO_ADJUST  =   (USB_THERMAL_BASE+28);      //获取视频调整参数
        public const int USB_SET_IMAGE_VIDEO_ADJUST = (USB_THERMAL_BASE + 29);       //设置视频调整参数       
        public const int USB_GET_BLACK_BODY         =         (USB_THERMAL_BASE+42);             //获取黑体参数
        public const int USB_SET_BLACK_BODY         =         (USB_THERMAL_BASE+43);              //设置黑体参数
        public const int USB_GET_BODYTEMP_COMPENSATION    =   (USB_THERMAL_BASE+44);          //获取体温补偿参数
        public const int USB_SET_BODYTEMP_COMPENSATION = (USB_THERMAL_BASE + 45);           //设置体温补偿参数
        public const int USB_GET_JPEGPIC_WITH_APPENDDATA = (USB_THERMAL_BASE + 46);   //获取热图

        /************************************************************************
        * 定义取流类型
        ************************************************************************/
        public const int USB_STREAM_UNKNOW = 0;
        public const int USB_STREAM_PCM = 1;     // PCM裸码流(DirectShow枚举出的PCM类型为1,保持一致)
        public const int USB_STREAM_MJPEG = 101;   // MJPEG裸码流
        public const int USB_STREAM_YUV = 102;   // YUV裸码流
        public const int USB_STREAM_H264 = 103;   // H264裸码流(需相机支持H264裸流输出)

        /************************************************************************
        * 定义预览,码流回调码流类型
        ************************************************************************/
        public const int USB_STREAM_PS_H264 = 201;  // PS封装H264码流
        public const int USB_STREAM_PS_MJPEG = 202;  // PS封装MJPEG码流
        public const int USB_STREAM_PS_YUY2 = 203;  // PS封装YUV2码流
        public const int USB_STREAM_PS_NV12 = 204;  // PS封装YUV2码流
        public const int MAX_MANUFACTURE_LEN = 32;
        public const int MAX_DEVICE_NAME_LEN = 32;
        public const int MAX_SERIAL_NUM_LEN = 48;////序列号的最大长度
        public const int HPR_MAX_PATH = 260;

        /************************************************************************
        * 错误码等级类型定义
        ************************************************************************/
        public const int ERR_LEVEL = 1;//ListInfo里面的信息类型
        public const int DBG_LEVEL = 2;//ListInfo里面的信息类型
        public const int INF_LEVEL = 3;//ListInfo里面的信息类型

        #region  dllimport

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Init();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_SetLogToFile(int dwLogLevel, string pLogDir, bool bAutoDel);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Cleanup();
        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_Login(IntPtr pUsbLoginInfo, IntPtr pDevRegRes);
        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Logout(int lUserID);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_GetDeviceCount();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_EnumDevices(Int32 dwSize, IntPtr lpDevInfoList);
        //       public static extern int USBCamera_EnumDevice(ref USB_CAMERA_DEVICE_INFO_EXTEN lpDevInfoList, Int32 dwSize);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_SetDeviceConfig(int handle, int dwCommand, IntPtr pConfigInputInfo, IntPtr pConfigOutputInfo);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_GetDeviceConfig(int handleint, int dwCommand, IntPtr pConfigInputInfo, IntPtr pConfigOutputInfo);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Control(int lUserID, int dwCommand, IntPtr pInputInfo);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_StopChannel(int iGraphHandle, int iIndex);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_StartPreview(int handle, ref USB_PREVIEW_PARAM lpPreviewParam);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Capture(int handle, ref USB_CAPTURE_PARAM lpCaptuerParam);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_GetLastError();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern IntPtr USB_GetErrorMsg(int dwErrorCode);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_StartFaceDetect(int handle, USB_FACE_DETECT_PARAM pFaceDetectParam);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_StartStreamCallback(int handle, USB_STREAM_CALLBACK_PARAM pStreamCBParam);

        #endregion


        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CAMERA_DEVICE_INFO_EXTEN
        {
            public Int32 nIndex;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = MAX_PATH, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] cDevPath;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = MAX_PATH, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] cDevName;
            public byte bHaveAudio;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 31, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CAMERA_CONFIG
        {
            public IntPtr pCondBuf;   //[in]，条件数据指针，如表示通道号等
            public uint dwCondSize; //[in]，pCondBuf指向的数据大小
            public IntPtr pInBuf;     //[in]，设置时需要用到，指向结构体的指针
            public uint dwInSize;   //[in], pInBuf指向的数据大小
            public IntPtr pOutBuf;    //[out]，获取时需要用到，指向结构体的指针，内存由上层分配
            public uint dwOutSize;  //[in]，获取时需要用到，表示pOutBuf指向的内存大小，
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 40, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;  //保留
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_PREVIEW_PARAM
        {
            public uint dwSize;
            public uint dwStreamType;				//码流类型
            public uint dwChannel;
            public IntPtr hWindow;				    //窗口句柄
            public byte byUseAudio;				//是否预览音频
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 127, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        public const int MAX_PATH = 260;
        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CAPTURE_PARAM
        {
            public uint dwSize;
            public uint dwType;        // 抓图方式：0-内部写文件，1-返回图片数据;
            public IntPtr pBuf;
            public uint dwBufSize;
            public uint dwDataLen;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_PATH, ArraySubType = UnmanagedType.Struct)]
            public byte[] szFilePath;       // 图片文件存储路径
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 256, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CAMERA_SRC_STREAM_CFG
        {
            public int dwStreamType;	// 原始码流类型
            public bool bUseAudio;       // 是否使用音频
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct MEDIA_RESOLUTION_INFO
        {
            public int dwWidth;
            public int dwHeight;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct RECT
        {
            public int left;
            public int top;
            public int right;
            public int bottom;
        };


        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_MEDIA_DATA
        {
            public int dwWidth;             // 宽度
            public int dwHeight;            // 高度
            public int dwFrameRate;         // 帧率
            public int dwTimeStamp;         // 时间戳
            public int dwFrameNum;          // 帧号
            public int dwLen;               // 背景图数据长度
            public IntPtr pBuffer;            // 背景图缓存
            public int dwSysTime;          // 系统时间戳
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 128, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;         // 保留字节
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_FACE_QUALITY
        {
            public float fEyeDistance;                   // 两眼间距,真实像素值
            public float fGrayMean;                      // 灰阶均值，范围0~255
            public float fGrayVariance;                  // 灰阶均方差，范围0~128
            public float fClearityScore;                 // 清晰度评分，范围0~1
            public float fPosePitch;                     // 平面外上下俯仰角，人脸朝上为正，范围-90~90
            public float fPoseYaw;                       // 平面外左右偏转角，人脸朝左为正，范围-90~90
            public float fPoseRoll;                      // 平面内旋转角，人脸顺时针旋转为正，范围-90~90
            public float fPoseConfidence;                // 姿态(pose_pitch、pose_yaw、pose_roll)置信度，范围0~1
            public float fFrontalScore;                  // 正面程度评分，范围0~1
            public float fVisibleScore;                  // 可见性评分（即不遮挡），范围0~1，0表示完全遮挡，1表示完全不遮挡
            public float fFaceScore;                     // 人脸评分，范围0~1
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 128, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;                     // 保留字节，后续扩展评分项
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_SUBFACE_PIC
        {
            public int dwWidth;             // 小图宽度
            public int dwHeight;            // 小图高度
            public IntPtr pSubFacePic;         // 人脸小图
            public int dwSubFacePicLen;     // 人脸小图大小
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 16, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;           // 保留字节，后续扩展评分项
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_FACE_PARAM
        {
            public USB_FACE_QUALITY struFaceQualityList;
            public USB_SUBFACE_PIC struSubFacePic;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 16, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;         // 保留字节
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_FD_RESULT_PARAM
        {
            public int dwFaceTotalNum;             // 人脸总的个数  
            public USB_MEDIA_DATA struMediaData;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 64, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public USB_FACE_PARAM[] struFaceParam;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 32, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };


        public delegate void FDResultCallBack(long lPort, HCUSBSDK.USB_FD_RESULT_PARAM pstruRes, IntPtr pUser);

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_FACE_DETECT_PARAM
        {
            public FDResultCallBack fnFaceDetectCB;    // 人脸检测结果数据回调
            public IntPtr pUser;
            public byte bySnapMode;               // 抓图模式  0:自动抓图 1:手动抓图     【预留，不支持】
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 503, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_FRAME_INFO
        {
            public int nStamp;       // 时标信息
            public int dwStreamType; // 数据类型
            public int dwWidth;      // 画面宽,如果是音频数据则为音频声道数
            public int dwHeight;     // 画面高,如果是音频数据则为采样位数
            public int dwFrameRate;  // 帧率,编码时产生的图像帧率，如果是音频数据则为采样率
            public int dwFrameType;  // 帧类型,  对应转封装库输出的类型 
            public int dwDataType;   // 数据类型,对应转封装库输出的数据类型
            public int nFrameNum;    // 帧号
            public IntPtr pBuf;        // 数据指针
            public int dwBufSize;    // 数据长度
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 128, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        public delegate void fnStreamCallBack(long handle, USB_FRAME_INFO pFrameInfo, IntPtr pUser);

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_STREAM_CALLBACK_PARAM
        {
            public int dwSize;
            public int dwStreamType; //MJPEG/H264/YUV/PCM
            public fnStreamCallBack funcStreamCallBack;
            public IntPtr pUser;
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 128, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_DEVICE_REG_RES
        {
            public int dwSize;   //结构体大小
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 32, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] szDeviceName; //设备名称
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 48, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] szSerialNumber; //设备序列号
            public int dwSoftwareVersion; //软件版本号,高16位是主版本,低16位是次版本
            public ushort wYear;
            public byte byMonth;
            public byte byDay;
            public byte byRetryLoginTimes; //剩余可尝试登陆的次数
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes1;            //保留
            public int dwSurplusLockTime; //剩余时间，单位秒 用户锁定时，此参数有效
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 256, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };


        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_DEVICE_INFO
        {
            public int dwSize;   //结构体大小
            public int dwIndex; // 设备索引 
            public int dwVID;   //设备VID
            public int dwPID;   //设备PID
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_MANUFACTURE_LEN, ArraySubType = UnmanagedType.I1)]
            public byte[] szManufacturer;               //制造商（来自描述符)
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_DEVICE_NAME_LEN, ArraySubType = UnmanagedType.I1)]
            public byte[] szDeviceName;                 //设备名称（来自描述符）
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_SERIAL_NUM_LEN, ArraySubType = UnmanagedType.I1)]
            public byte[] szSerialNumber;           //设备序列号（来自描述符）
            public byte byHaveAudio;	// 是否具有音频
            public byte iColorType;     // 1.RGB路， 2.IR路
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = HPR_MAX_PATH, ArraySubType = UnmanagedType.I1)]
            public byte[] szDevicePath;
            public byte byDeviceType;  		//设备类型， 4-音频，5-视频
            public int dwBCD;         		//设备软件版本号
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 249, ArraySubType = UnmanagedType.I1)]
            public byte[] byRes;
            public void Init()
            {
                szManufacturer = new byte[MAX_MANUFACTURE_LEN];
                szDeviceName = new byte[MAX_DEVICE_NAME_LEN];
                szSerialNumber = new byte[MAX_SERIAL_NUM_LEN];
                szDevicePath = new byte[HPR_MAX_PATH];
                byRes = new byte[249];
            }
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_USER_LOGIN_INFO
        {
            public int dwSize; //结构体大小
            public int dwTimeout; //登录超时时间（单位：毫秒）
            public int dwDevIndex; //设备下标
            public int dwVID;  //设备VID，枚举设备时得到
            public int dwPID;  //设备PID，枚举设备时得到
           [MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 32)]
            public string szUserName; //用户名，获取激活状态时无需填
           [MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 16)]
           public string szPassword; //密码，获取激活状态时无需填
           [MarshalAsAttribute(UnmanagedType.ByValTStr, SizeConst = 48)]
            public string szSerialNumber; //设备序列号，枚举设备时得到
            public byte byLoginMode; //0-认证登陆 1-默认账号登陆（不关心用户名密码）（权限不同，部分功能需认证登陆才支持）
            // （尝试采用指定方式登陆）
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 255, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CONFIG_INPUT_INFO
        {
            public IntPtr lpCondBuffer;        //指向条件缓冲区
            public int dwCondBufferSize;//条件缓冲区大小
            public IntPtr lpInBuffer;          //指向输出缓冲区
            public int dwInBufferSize;   //输入缓冲区大小
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 48, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_CONFIG_OUTPUT_INFO
        {
            public IntPtr lpOutBuffer;      //指向输出缓冲区
            public int dwOutBufferSize;  //输出缓冲区大小
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 56, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_VIDEO_PARAM
        {
            public int dwVideoFormat; //视频码流格式
            public int dwWidth;//分辨率宽
            public int dwHeight;//分辨率高
            public int dwFramerate;//帧率
            public int dwBitrate;//比特率
            public int dwParamType; //图像参数类型
            public int dwValue; //图像参数值
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 128, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_VIDEO_CAPACITY
        {
            public char nIndex;
            public char nType;					 // 码流类型（USBCamera_H264、USBCamera_MJPEG、USBCamera_RGB24等）
            public int dwWidth;				 // 图像宽度
            public int dwHeight;				 // 图像高度
            public int lListSize;				 // 支持的帧率的个数
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 50, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public long[] lFrameRates;		 // 支持的帧率(50足够大)
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        public struct USB_SRC_STREAM_CFG
        {
            public int dwStreamType;	// 原始码流类型(MJPEG/H264/YUV)
            public byte bUseAudio;      // 是否使用音频
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

       [StructLayoutAttribute(LayoutKind.Sequential)]
        // 条件参数
        public struct USB_COMMON_COND
        {
            public int dwSize;
            public byte  byChannelID;     //通道号
            public byte  bySID;           //场景ID
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

         [StructLayoutAttribute(LayoutKind.Sequential)]
        //视频调整
        public struct USB_IMAGE_VIDEO_ADJUST
        {
            public int  dwSize;
            public byte  byImageFlipStyle;  //镜像模式: 0-关闭 1-中心 2-左右 3-上下
            public byte  byPowerLineFrequencyMode;  //视频制式：1-PAL(50HZ)
            public byte  byCorridor;  //镜头走廊模式(旋转): 0-关闭 1-开启
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 29, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
         //图像亮度调节
        public struct USB_IMAGE_BRIGHTNESS
        {
            public int  dwSize;
            public int  dwBrightness;       //图像亮度0-100
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 28, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

        [StructLayoutAttribute(LayoutKind.Sequential)]
        //图像对比度调节
        public struct USB_IMAGE_CONTRAST
        {
            public int     dwSize;
            public int dwContrast;      //图像对比度0-100
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 28, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };
    
         [StructLayoutAttribute(LayoutKind.Sequential)]
        //抓热图
        public struct USB_JPEGPIC_WITH_APPENDDATA
        {
            public int   dwSize;   //结构体大小
            public int       dwJpegPicLen;//Jpeg图片长度
            public int       dwJpegPicWidth;//图像宽度
            public int       dwJpegPicHeight;//图像高度
            public int       dwP2pDataLen;//全屏测温数据长度
            public byte       byIsFreezedata;//是否数据冻结: 0-否; 1-是
            public byte       byTemperatureDataLength;//测温数据长度（2、4）
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes2;
            public int       dwScale;//放大倍数（测温数据长度为2时返回）
            public int    iOffset;//偏移量（测温数据长度为2时返回）
            public IntPtr  pJpegPic;//热成像图片数据
            public IntPtr  pP2pData;//全屏测温数据
            [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 28, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
            public byte[] byRes;
        };

         [StructLayoutAttribute(LayoutKind.Sequential)]
        //黑体参数配置
    public struct USB_BLACK_BODY
    {
        public int  dwSize;
        public byte   byEnabled;  //使能 0-关闭 1-开启
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] byRes1;
        public int  dwEmissivity; //黑体发射率:0.01 - 1.00, 传输时实际值 * 100换算成整数
        public int  dwDistance;   //距离 0.3-2m, 协议传输时以厘米为单位
        public int  dwTemperature;   //黑体温度 30.0~50.0℃, 传输时实际值*10换算成整数
        public int dwCentrePointX;  //黑体中心点X坐标，归一化值，范围0-1000
        public int  dwCentrePointY;  //黑体中心点Y坐标，归一化值，范围0-1000
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 40, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] byRes;
    };

        [StructLayoutAttribute(LayoutKind.Sequential)]
    //体温补偿参数配置
    public struct USB_BODYTEMP_COMPENSATION
    {
        public int   dwSize;   //结构体大小
        public byte       byEnabled;  //使能 0-关闭 1-开启
        public byte       byType;   //补偿方式:1-手动补偿 2-自动补偿
       [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] byRes1;
        public int iCompensationValue; //补偿温度 [-10.0 10.0]摄氏度, 传输时实际值*10换算成整数
        public int      dwSmartCorrection; //手动校准 -99.0~990.℃, 传输时(实际值+100)*10换算成正整数
        public int      dwEnvironmentalTemperature;    //环境温度 -99.0~99.0℃, 传输时(实际值+100)*10换算成正整数
        public byte       byEnvironmentalTemperatureMode;   //环境温度模式 1-自动模式 2-手动模式
        public byte       byTemperatureCurveSensitivityLevel;//温度曲线灵敏度等级: 1-低 2-中 3-高  
        public byte       byEnvironmentCompensationenabled;//环境补偿使能: 1-关闭  2-开启
        [System.Runtime.InteropServices.MarshalAsAttribute(System.Runtime.InteropServices.UnmanagedType.ByValArray, SizeConst = 45, ArraySubType = System.Runtime.InteropServices.UnmanagedType.I1)]
        public byte[] byRes;
    };
    

    }
}