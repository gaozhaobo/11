using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;
using System.Runtime.InteropServices.ComTypes;
namespace AcsDemo_USB
{
   public class CHCUsbSDK
    {
        #region HCUsbSDK.dll macro definition

        #region common use
        public const int MAX_MANUFACTURE_LEN=32;
        public const int MAX_DEVICE_NAME_LEN=32;
        public const int MAX_SERIAL_NUM_LEN=48;////序列号的最大长度
        public const int MAX_USB_DEV_LEN = 64;
        public const int ERR_LEVEL = 1;//ListInfo里面的信息类型
        public const int DBG_LEVEL = 2;//ListInfo里面的信息类型
        public const int INF_LEVEL = 3;//ListInfo里面的信息类型
        public const int MAX_USERNAME_LEN = 32;//用户名的最大长度
        public const int MAX_PASSWORD_LEN = 16;//最大的密码长度
        public const int INVALID_USER_ID = -1;
        public const int USB_ERROR_BASE = 0;
        public const int USB_SUCCESS = (CHCUsbSDK.USB_ERROR_BASE + 0);
        public const uint USB_GET_ACTIVATE_CARD     = 1004;
        public const uint USB_GET_CERTIFICATE_INFO  = 1020;
        public const int HPR_MAX_PATH = 260;
        #endregion

        #region
        public const int USB_SDK_SET_BEEP_AND_FLICKER = 1000;     //控制蜂鸣器及显示灯
        public const int USB_SDK_SET_CARD_PROTO = 1003;           //设置操作卡协议类型
        public const int USB_SDK_SET_M1_PWD_VERIFY  = 1006;       //(M1卡) 验证扇区密码
        public const int USB_SDK_SET_M1_WRITE_BLOCK = 1008;       //(M1卡) 写卡指定块数据
        public const int USB_SDK_SET_M1_MODIFY_SCB = 1009;        //(M1卡) 修改指定扇区控制块
        public const int USB_SDK_SET_M1_BLOCK_ADD_VALUE = 1010;   //(M1卡) 块加值
        public const int USB_SDK_SET_M1_BLOCK_MINUS_VALUE = 1011; //(M1卡) 块减值
        public const int USB_SDK_SET_M1_MIFARE_PACK = 1014;       //(M1卡) Mifare数据包透传
        public const int USB_SDK_SET_CARD_PARAM = 1016;           //(M1卡) 设置卡参数
        public const int USB_SDK_SET_CPU_CARD_PACK = 1018;        //(M1卡) CPU卡数据包透传
        #endregion


        public enum LOG_LEVEL_ENUM
        {
            ENUM_ERROR_LEVEL= 1,
            ENUM_DEBUG_LEVEL = 2,
            ENUM_INFO_LEVEL = 3
        }
        #endregion

        #region structure definition

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
        public struct  USB_USER_LOGIN_INFO
        {
            public int      dwSize;                    //结构体大小
            public int      dwTimeout;                 //登录超时时间（单位：毫秒）
            public int      dwDevIndex;                //设备下标
            public int      dwVID;                     //设备VID，枚举设备时得到
            public int      dwPID;                     //设备PID，枚举设备时得到

            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MAX_USERNAME_LEN, ArraySubType = UnmanagedType.I1)]              //用户名32
            public byte[]   szUserName;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MAX_PASSWORD_LEN, ArraySubType = UnmanagedType.I1)]             //密码16
            public byte[]   szPassword;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = MAX_SERIAL_NUM_LEN, ArraySubType = UnmanagedType.I1)]        //序列号的最大长度48
            public byte[]   szSerialNumber;
           
            
            public byte     byLoginMode;                 //0-认证登陆 1-默认账号登陆（不关心用户名密码）（权限不同，部分功能需认证登陆才支持）
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.I1)]
            public byte[]   byRes2;                    //保留的字段
            public int      dwFd;                      //设备描述符fd (android下没有root权限登录时使用)
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 248, ArraySubType = UnmanagedType.I1)]
            public byte[]   byRes;                    //保留的字段

            public void init()
            {
                szUserName      = new byte[MAX_USERNAME_LEN];
                szPassword      = new byte[MAX_PASSWORD_LEN];
                szSerialNumber  = new byte[MAX_SERIAL_NUM_LEN];
                byRes2          = new byte[3];
                byRes           = new byte[248];
            }
        }

       [StructLayoutAttribute(LayoutKind.Sequential)]
       public struct  USB_DEVICE_REG_RES
       {
           public int           dwSize;                     //结构体大小
           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_DEVICE_NAME_LEN, ArraySubType = UnmanagedType.I1)]
           public byte[]        szDeviceName;
           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = MAX_SERIAL_NUM_LEN, ArraySubType = UnmanagedType.I1)]
           public byte[]        szSerialNumber;
           public int           dwSoftwareVersion;      //软件版本号,高16位是主版本,低16位是次版本
           public ushort        wYear;
           public byte          byMonth;
           public byte          byDay;
           public byte          byRetryLoginTimes;      //剩余可尝试登陆的次数

           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.I1)]
           public byte[] byRes1;
           public byte bySurplusLockTime;          //剩余时间，单位秒 用户锁定时，此参数有效

           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 256, ArraySubType = UnmanagedType.I1)]
           public byte[] byRes;

           public void init()
           {
               szDeviceName     = new byte[MAX_DEVICE_NAME_LEN];
               szSerialNumber   = new byte[MAX_SERIAL_NUM_LEN];
               byRes1 = new byte[3];
               byRes = new byte[256];
           }

       }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_M1_PWD_VERIFY_INFO    //卡扇区带密码验证结构体
        {
            public int      dwSize;
            public byte     byPasswordType;
            public byte     bySectionNum;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 2, ArraySubType = UnmanagedType.I1)]
            public byte[]     byRes1;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = UnmanagedType.I1)]
            public byte[]     byPassword;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 18, ArraySubType = UnmanagedType.I1)]
            public byte[]     byRes;
            public void Init()
            {
                byRes1 = new byte[2];
                byPassword = new byte[6];
                byRes = new byte[18];
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_M1_BLOCK_WRITE_DATA   //写卡指定块数据
        {
            public int      dwSize;
            public short    wAddr;
            public byte     byDataLen;
            public byte     byRes1;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 16, ArraySubType = UnmanagedType.I1)]
            public byte[]   byData;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 8, ArraySubType = UnmanagedType.I1)]
            public byte[]   byRes;
            public void Init()
            {
                byData = new byte[16];
                byRes = new byte[8];
            }
        }

       [StructLayout(LayoutKind.Sequential)]
        public struct USB_M1_MODIFY_SCB   //(M1卡) 修改指定扇区控制块
       {
            public int     dwSize;
            public byte     bySectionNum;
            [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = UnmanagedType.I1)]
            public byte[]   byPasswordA;
            public byte     byRes1;
           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 4, ArraySubType = UnmanagedType.I1)]
            public byte[]   byCtrlBits;
           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 6, ArraySubType = UnmanagedType.I1)]
            public byte[]   byPasswordB;
           [MarshalAsAttribute(UnmanagedType.ByValArray, SizeConst = 10, ArraySubType = UnmanagedType.I1)]
            public byte[]   byRes;
           public void Init()
           {
               byPasswordA = new byte[6];
               byCtrlBits = new byte[4];
               byPasswordB = new byte[6];
               byRes = new byte[10];
           }
       }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_ACTIVATE_CARD_RES
        {
            public int dwSize;
            public byte byCardType;// 卡类型（0-TypeA m1卡，1-TypeA cpu卡,2-TypeB,3-125kHz Id卡）
            public byte bySerialLen; //卡物理序列号字节长度
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 10, ArraySubType = UnmanagedType.I1)]
            public byte[] bySerial;//卡物理序列号
            public byte bySelectVerifyLen;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 3, ArraySubType = UnmanagedType.I1)]
            public byte[] bySelectVerify;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 12, ArraySubType = UnmanagedType.I1)]
            public byte[] byRes;

            public void Init()
            {
                bySerial = new byte[10];
                bySelectVerify = new byte[3];
                byRes = new byte[12];
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_WAIT_SECOND
        {
            public int dwSize;//结构体的大小
            public byte byWait;//1Byte操作等待时间（0-一直执行直到有卡响应，其他对应1S单位）
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 27, ArraySubType = UnmanagedType.I1)]
            public byte[] byRes;

            public void Init()
            {
                byRes = new byte[27];
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_CONFIG_INPUT_INFO
        {
            public IntPtr lpCondBuffer;//指向条件缓冲区
            public int dwCondBufferSize;//条件缓冲区大小
            public IntPtr lpInBuffer;//指向输出缓冲区
            public int dwInBufferSize;//输入缓冲区大小
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 48, ArraySubType = UnmanagedType.I1)]
            public byte[] byRes;

            public void Init()
            {
                byRes = new byte[48];
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_CONFIG_OUTPUT_INFO
        {
            public IntPtr   lpOutBuffer;//指向输出缓冲区
            public int      dwOutBufferSize;//输出缓冲区大小
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 56, ArraySubType = UnmanagedType.I1)]
            public byte[]   byRes;          // 56个字节
            public void Init()
            {
                byRes = new byte[56];
            }
        }

        [StructLayout(LayoutKind.Sequential)]
        public struct USB_CERTIFICATE_INFO
        {
            public int dwSize; //结构体大小
            public ushort wWordInfoSize; //文字信息长度
            public ushort wPicInfoSize; //相片信息长度
            public ushort wFingerPrintInfoSize; //指纹信息长度
            public byte byCertificateType; //证件类型：0-身份证，1-中国绿卡
            public byte byRes2;
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 256, ArraySubType = UnmanagedType.I1)]
            public byte[] byWordInfo;//文字信息
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 1024, ArraySubType = UnmanagedType.I1)]
            public byte[] byPicInfo;//相片信息
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 1024, ArraySubType = UnmanagedType.I1)]
            public byte[] byFingerPrintInfo;//指纹信息
            [MarshalAs(UnmanagedType.ByValArray, SizeConst = 40, ArraySubType = UnmanagedType.I1)]
            public byte[] byRes;

            public void Init()
            {
                byWordInfo = new byte[256];
                byPicInfo = new byte[1024];
                byFingerPrintInfo = new byte[1024];
                byRes = new byte[40];
            }
        }

        #endregion

        #region HCUsbSDK.dll function definition
        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Init();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Cleanup();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern uint USB_GetLastError();

        public delegate void EnumDeviceCallBack(ref CHCUsbSDK.USB_DEVICE_INFO pDevceInfo, IntPtr pUser);
       
        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_EnumDevices(int dwCount, IntPtr pDevInfoList);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_GetDeviceCount();


        [DllImport(@"HCUSBSDK.dll")]
        public static extern IntPtr USB_GetErrorMsg(uint dwErrorCode);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_SetLogToFile(uint dwLogLevel, IntPtr strLogDir, bool bAutoDel);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern uint USB_GetSDKVersion();

        [DllImport(@"HCUSBSDK.dll")]
        public static extern int USB_Login(ref CHCUsbSDK.USB_USER_LOGIN_INFO pUsbLoginInfo, ref CHCUsbSDK.USB_DEVICE_REG_RES pDevRegRes);

        [DllImport(@"HCUSBSDK.dll")]
        public static extern bool USB_Logout(int lUserID);

        [DllImportAttribute(@"HCUSBSDK.dll")]
        public static extern bool USB_GetDeviceConfig(int lUserID, uint dwCommand, ref CHCUsbSDK.USB_CONFIG_INPUT_INFO pInputInfo, ref CHCUsbSDK.USB_CONFIG_OUTPUT_INFO pOutputInfo);

        [DllImportAttribute(@"HCUSBSDK.dll")]
        public static extern bool USB_SetDeviceConfig(int lUserID, uint dwCommand, ref CHCUsbSDK.USB_CONFIG_INPUT_INFO pInputInfo, ref CHCUsbSDK.USB_CONFIG_OUTPUT_INFO pOutputInfo);

        [DllImport(@"Dewlt.dll")]
        public static extern int dewlt(IntPtr strPictureBin);
        #endregion

    }
}
