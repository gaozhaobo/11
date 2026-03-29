package test;

//import com.sun.javafx.scene.paint.GradientUtils.Point;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.Structure;
import com.sun.jna.ptr.ByteByReference;
import com.sun.jna.win32.StdCallLibrary;
import com.sun.jna.win32.StdCallLibrary.StdCallCallback;

import com.sun.jna.examples.win32.W32API.HWND;

public interface HCUsbSDK extends StdCallLibrary{
	
	HCUsbSDK INSTANCE = (HCUsbSDK) Native.loadLibrary("HCUsbSDK",
            HCUsbSDK.class);
	
	public static final int MAX_MANUFACTURE_LEN = 32;  //鍒堕�犲晢鍚嶇О鏈�澶ч暱搴�
	public static final int MAX_DEVICE_NAME_LEN = 32;  //璁惧鍚嶇О鏈�澶ч暱搴�
	public static final int MAX_SERIAL_NUM_LEN = 48;  //搴忓垪鍙锋渶澶ч暱搴�
	public static final int  MAX_PATH_LEN = 260;
	public static final int MAX_USB_DEV_LEN = 64;  
	public static final int ERR_LEVEL = 1;  
	public static final int DBG_LEVEL = 2;  
	public static final int INF_LEVEL = 3;  
	public static final int MAX_USERNAME_NAME = 32;  //鐢ㄦ埛鍚嶆渶澶ч暱搴�
	public static final int MAX_PASSWORD_LEN = 16;  //瀵嗙爜鏈�澶ч暱搴�
	public static final int INVALID_USER_ID = -1;  //鐧诲綍杩斿洖ID,鐧诲綍澶辫触涓�-1锛屾湁鏁圛D 0-128
	public static final int USB_ERROR_BASE = 0;
	public static final int USB_SUCCESS = (HCUsbSDK.USB_ERROR_BASE + 0);
	public static final int USB_SDK_GET_ACTIVATE_CARD = 0x0104;
	public static final int USB_SDK_GET_CERTIFICATE_INFO = 1000;
	public static final int MAX_USERNAME_LEN = 32;  
	
	
	
	public static final int USB_SET_VIDEO_PARAM = 3004; 
	public static final int USB_SET_SRC_STREAM_TYPE = 3007;
	
	/************************************************************************
	* 定义取流类型
	************************************************************************/
	public static final int USB_STREAM_UNKNOW  =   0;
	public static final int USB_STREAM_PCM     =   1;   // PCM裸码流(DirectShow枚举出的PCM类型为1,保持一致)
	public static final int USB_STREAM_MJPEG   =   101;  // MJPEG裸码流
	public static final int USB_STREAM_YUV     =   102;  // YUV裸码流
	public static final int USB_STREAM_H264    =   103;  // H264裸码流(需相机支持H264裸流输出)

	/************************************************************************
	* 定义预览,码流回调码流类型
	************************************************************************/
	public static final int USB_STREAM_PS_H264  =  201;  // PS封装H264码流
	public static final int USB_STREAM_PS_MJPEG =  202;  // PS封装MJPEG码流
	

	public static class USB_DEVICE_INFO extends Structure
	{
		 public int   dwSize;   //结构体大小
	     public int   dwIndex; // 设备索引 
	     public int   dwVID;   //设备VID
	     public int    dwPID;   //设备PID
	     public byte[]    szManufacturer = new byte[MAX_MANUFACTURE_LEN/*32*/];//制造商（来自描述符）
	     public byte[]    szDeviceName = new byte[MAX_DEVICE_NAME_LEN/*32*/];//设备名称（来自描述符）
	     public byte[]    szSerialNumber = new byte[MAX_SERIAL_NUM_LEN/*48*/];//设备序列号（来自描述符）
	     public byte    byHaveAudio;	// 是否具有音频
	     public byte    iColorType;     // 1.RGB路， 2.IR路
	     public byte[]   szDevicePath = new byte[MAX_PATH_LEN];
	     public byte[]    byRes = new byte[254];
	}
	
    public static class USB_USER_LOGIN_INFO extends Structure
    {
    	public int   dwSize; //结构体大小
    	public int   dwTimeout; //登录超时时间（单位：毫秒）
    	public int   dwDevIndex; //设备下标
    	public int   dwVID;  //设备VID，枚举设备时得到
    	public int   dwPID;  //设备PID，枚举设备时得到
    	public byte[]  szUserName = new byte[MAX_USERNAME_LEN/*32*/]; //用户名，获取激活状态时无需填
    	public byte[]  szPassword = new byte[MAX_PASSWORD_LEN/*16*/]; //密码，获取激活状态时无需填
    	public byte[]  szSerialNumber = new byte[MAX_SERIAL_NUM_LEN/*48*/]; //设备序列号，枚举设备时得到
        public byte  byLoginMode; //0-认证登陆 1-默认账号登陆（不关心用户名密码）（权限不同，部分功能需认证登陆才支持）
        // （尝试采用指定方式登陆）
        public byte[]  byRes = new byte[255];
    }
    
    public static class USB_DEVICE_REG_RES extends Structure
    {
    	public int   dwSize;   //结构体大小
    	public byte[]     szDeviceName = new byte[MAX_DEVICE_NAME_LEN /*32*/]; //设备名称
    	public byte[]     szSerialNumber = new byte[MAX_SERIAL_NUM_LEN /*48*/]; //设备序列号
        public int   dwSoftwareVersion; //软件版本号,高16位是主版本,低16位是次版本
        public short    wYear;
        public byte    byMonth;
        public byte    byDay;
        public byte    byRetryLoginTimes; //剩余可尝试登陆的次数
        public byte[]    byRes1 = new byte[3];             //保留
        public int   dwSurplusLockTime; //剩余时间，单位秒 用户锁定时，此参数有效
        public byte[]    byRes = new byte[256];
    }
    
    public static class USB_CONFIG_INPUT_INFO extends Structure
    {
    	public Pointer lpCondBuffer;        //指向条件缓冲区
        public int  dwCondBufferSize;//条件缓冲区大小
        public Pointer lpInBuffer;          //指向输出缓冲区
        public int  dwInBufferSize;   //输入缓冲区大小
        public byte[]   byRes = new byte[48];
    }
    
    public static class USB_CONFIG_OUTPUT_INFO extends Structure
    {
    	public Pointer lpOutBuffer;      //指向输出缓冲区
    	public int  dwOutBufferSize;  //输出缓冲区大小
        public byte[]   byRes = new byte[56];
    }
    
    public static class USB_PREVIEW_PARAM extends Structure
    {
    	public int  dwSize;
    	public int  dwStreamType;				//码流类型
    	public int  dwChannel;
        public HWND   hWindow;				       //窗口句柄
        public byte   bUseAudio;				   //是否预览音频
        public byte   bYUVCallback;			   //是否开启YUV回调
        public byte[]   byRes = new byte[126];
    }
    
    public static class USB_CAPTURE_PARAM extends Structure
    {
    	public int  dwSize;        // sizeof(USB_CAMERA_CAPTURE_PARAM)
    	public int  dwType;        // 抓图方式：0-内部写文件，1-返回图片数据
    	public Pointer pBuf;         // 数据缓冲区
        public int  dwBufSize;     // 数据缓冲区大小
        public int  dwDataLen;     // 数据缓冲区中有效数据长度(即图片大小)
        public byte[]   szFilePath = new byte[256]; //图片存储路径
        public byte[]   byRes = new byte[32];
    }
    
    public static class USB_VIDEO_PARAM extends Structure
    {
    	public int dwVideoFormat; //视频码流格式
    	public int dwWidth;//分辨率宽
    	public int dwHeight;//分辨率高
    	public int dwFramerate;//帧率
    	public int dwBitrate;//比特率
    	public int dwParamType; //图像参数类型
    	public int dwValue; //图像参数值
    	public byte[]   byRes = new byte[128];//保留字节
    }
    
    public static class USB_SRC_STREAM_CFG extends Structure
    {
    	public int  dwStreamType;	// 原始码流类型(MJPEG/H264/YUV)
    	public byte   bUseAudio;      // 是否使用音频
        public byte[]   byRes = new byte[4];
    }
    
    public static class USB_SUBFACE_PIC extends Structure
    {
    	public int       dwWidth;             // 小图宽度
    	public int       dwHeight;            // 小图高度
    	public Pointer        pSubFacePic;         // 人脸小图
        public int       dwSubFacePicLen;     // 人脸小图大小
        public byte[]   byRes = new byte[16];
    }
    
    public static class USB_FACE_QUALITY extends Structure
    {
    	public float               fEyeDistance;                   // 两眼间距,真实像素值
    	public float               fGrayMean;                      // 灰阶均值，范围0~255
    	public float               fGrayVariance;                  // 灰阶均方差，范围0~128
    	public float               fClearityScore;                 // 清晰度评分，范围0~1
    	public float               fPosePitch;                     // 平面外上下俯仰角，人脸朝上为正，范围-90~90
    	public float               fPoseYaw;                       // 平面外左右偏转角，人脸朝左为正，范围-90~90
    	public float               fPoseRoll;                      // 平面内旋转角，人脸顺时针旋转为正，范围-90~90
    	public float               fPoseConfidence;                // 姿态(pose_pitch、pose_yaw、pose_roll)置信度，范围0~1
    	public float               fFrontalScore;                  // 正面程度评分，范围0~1
    	public float               fVisibleScore;                  // 可见性评分（即不遮挡），范围0~1，0表示完全遮挡，1表示完全不遮挡
    	public float               fFaceScore;                     // 人脸评分，范围0~1
        public byte[]   byRes = new byte[128];
    }
    
    public static class USB_FACE_PARAM extends Structure
    {
        USB_FACE_QUALITY   struFaceQualityList;
        USB_SUBFACE_PIC    struSubFacePic;
        public byte[]   byRes = new byte[16];
    }
    
    public static class USB_MEDIA_DATA extends Structure
    {
    	public int   dwWidth;             // 宽度
    	public int   dwHeight;            // 高度
    	public int   dwFrameRate;         // 帧率
    	public int   dwTimeStamp;         // 时间戳
    	public int   dwFrameNum;          // 帧号
    	public int   dwLen;               // 背景图数据长度
    	public Pointer   pBuffer;            // 背景图缓存
    	public int dwSysTime;          // 系统时间戳
        public byte[]   byRes = new byte[128];         // 保留字节
    }
    
    public static class USB_FD_RESULT_PARAM extends Structure
    {
    	public int        dwFaceTotalNum;             // 人脸总的个数 
        public USB_MEDIA_DATA   struMediaData = new USB_MEDIA_DATA();;
        public USB_FACE_PARAM[]    struFaceParam = new USB_FACE_PARAM[64]; //单个人脸参数
        public byte[]   byRes = new byte[32];
    }
    
    public static interface FDExtenResultCallBack extends StdCallCallback
	{
		public void invoke(long lPort, USB_FD_RESULT_PARAM struFDResultInfo, Pointer pUser);
	}
    
    public static class USB_FACE_DETECT_PARAM extends Structure
    {
        FDExtenResultCallBack fnFDExtenResultCallBack;  // 人脸属性检测结果数据回调
        public Pointer           pUser;
        public byte   bySnapMode;               // 抓图模式  0:自动抓图 1:手动抓图     【预留，不支持】
        public byte[]  byRes = new byte[503];
    }
	
	
	boolean USB_Init();	
	boolean USB_Cleanup();
	int USB_GetLastError();
	
	int USB_GetDeviceCount();
	boolean USB_EnumDevices(int dwCount, Pointer pDevInfoList);
	Pointer USB_GetErrorMsg(int dwErrorCode);
	boolean USB_SetLogToFile(int dwLogLevel, String strLogDir, boolean bAutoDel);  
	int USB_GetSDKVersion();
	int USB_Login(USB_USER_LOGIN_INFO pUsbLoginInfo, USB_DEVICE_REG_RES pDevRegRes);
	boolean USB_Logout(int lUserID);
	boolean USB_GetDeviceConfig(int lUserID, int dwCommand, USB_CONFIG_INPUT_INFO InputInfo, USB_CONFIG_OUTPUT_INFO OutputInfo);
	boolean USB_SetDeviceConfig(int lUserID, int dwCommand, USB_CONFIG_INPUT_INFO InputInfo, USB_CONFIG_OUTPUT_INFO OutputInfo);
	
	int USB_StartPreview(int lUserID, USB_PREVIEW_PARAM pPreviewParam);
	boolean USB_Capture(int lUserID, USB_CAPTURE_PARAM pChapterInfo);
	boolean USB_StopChannel(int lUserID, int lHandle);
	int USB_StartFaceDetect(int lUserID, USB_FACE_DETECT_PARAM pFaceDetectParam);
}

