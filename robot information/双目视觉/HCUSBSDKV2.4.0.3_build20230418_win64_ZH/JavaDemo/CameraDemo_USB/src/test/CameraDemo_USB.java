package test;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Panel;
import java.awt.Toolkit;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;

import com.sun.jna.Memory;
import com.sun.jna.Native;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;
import com.sun.jna.examples.win32.W32API.HWND;

//import test.HCUsbSDK.LOG_LEVEL_ENUM;
//import test.HCUsbSDK.USB_SDK_DEVICE_INFO;

import javax.swing.UIManager;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JPasswordField;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JTabbedPane;

public class CameraDemo_USB extends JFrame
{
	static HCUsbSDK hcUsbSDK = HCUsbSDK.INSTANCE;
	private JPanel contentPane;
	private JTextField textField_UserName;
	private JPasswordField passwordField;
	private static JTable DeviceInfo_table;
	private static JTable Info_table;
	private static JLabel label7;
	private static JButton btnTraverse;
	private static JButton btnLoginDevice;
	private static JButton btnLogoutDevice;
	private static JButton btnStartPreview;
	private static JButton btnStopPreview;
	private static JButton btnCapture;
	private final static int INITIALIZED_INDEX = 1;
	private int g_nEnumDevIndex = INITIALIZED_INDEX;
	private Panel panelRealPlay = new Panel();
	private Panel panelPlay;

	public static HCUsbSDK.FDExtenResultCallBack m_FaceDetectExtenResultCallBack = null;  //回调函数
	private static int IndexOfInfo = INITIALIZED_INDEX;  
	private int SelectedIndex = -1; 
	private HCUsbSDK.USB_USER_LOGIN_INFO StruCurUsbLoginInfo = new HCUsbSDK.USB_USER_LOGIN_INFO();
	private HCUsbSDK.USB_DEVICE_REG_RES StruDeviceRegRes = new HCUsbSDK.USB_DEVICE_REG_RES();
	private HCUsbSDK.USB_DEVICE_INFO struDevInfo = new HCUsbSDK.USB_DEVICE_INFO();
	public static int lUserID = -1;
	public static int m_handle = -1;
	private String szLogPath = "C:/UsbSDKlog/";
	private int m_VersionNum = 0;
    public final int WM_DEVICECHANGE = 0x0219;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {														
					hcUsbSDK.USB_Init();					
					CameraDemo_USB frame = new CameraDemo_USB();
					frame.setVisible(true);
				} catch (Exception e) {
					e.printStackTrace();
				}
			}
		});
	}

	/**
	 * Create the frame.
	 */
	public CameraDemo_USB() {						
		InitComponents();
		hcUsbSDK.USB_SetLogToFile(3, szLogPath, false);
		m_VersionNum = hcUsbSDK.USB_GetSDKVersion();
		GetVersion(m_VersionNum);
	}
	
	
	// Init Component 鍒濆鍖栫晫闈�
	private void InitComponents()
	{
		setTitle("CameraDemo_USB");
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();  
		int width = (int)screen.getWidth();
		int height = (int)screen.getHeight();
		setBounds(100, 100, 436, 482);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);		
		
		JLabel lable = new JLabel("版本信息");
		lable.setBounds(10, 10, 54, 15);
		contentPane.add(lable);
		
		label7 = new JLabel("");
		label7.setBounds(20, 35, 118, 15);
		contentPane.add(label7);
		

		panelRealPlay.setForeground(Color.YELLOW);
		panelRealPlay.setBounds(10, 138, 400, 300);
		contentPane.setLayout(null);
		contentPane.add(panelRealPlay);
		panelRealPlay.setLayout(null);

		panelPlay = new Panel();
		panelPlay.setBackground(Color.LIGHT_GRAY);
		panelPlay.setBounds(0, 0, 566, 485);
		panelRealPlay.add(panelPlay);
		
		JButton btnNewButton = new JButton("开始预览");
		btnNewButton.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				StartPreivew(e);
			}
		});
		btnNewButton.setBounds(10, 95, 93, 23);
		contentPane.add(btnNewButton);
		
		JButton button = new JButton("停止预览");
		button.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				StopPreview(e);
			}
		});
		button.setBounds(123, 95, 93, 23);
		contentPane.add(button);
		
		JButton button_1 = new JButton("抓图");
		button_1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Capture(e);
			}
		});
		button_1.setBounds(247, 95, 93, 23);
		contentPane.add(button_1);
	}
	
	/** 
	 * @param lLength
	 * @return Memory
	 */
	public Memory AllocMemory(long lLength) {
		Memory mem = new Memory(lLength);
		mem.clear();
		return mem;
	}
	
	/***********
	 鏄剧ずSDK鐗堟湰鍙�
	 **************/
	public void GetVersion(int dwVersion)
	{
		String s1, s2, s3, s4, Sversion;
		s1 = String.valueOf((0xff000000 & dwVersion) >> 24);
		s2 = String.valueOf((0x00ff0000 & dwVersion) >> 16);
		s3 = String.valueOf((0x0000ff00 & dwVersion) >> 8);
		s4 = String.valueOf(0x000000ff & dwVersion);
		Sversion = "HCUsbSDK V" + s1 + "." + s2 + "." + s3 + "." + s4;
		label7.setText(Sversion);
	}
	
	/***********
	 登录设备
	 **************/
	public void LoginDevice()
	{				
		int nDeviceNum = hcUsbSDK.USB_GetDeviceCount();
        if (nDeviceNum <= 0)
        {
        	System.out.println("当前无设备");
			return;
        }
        
        
        //结构体数组Pointer
        HCUsbSDK.USB_DEVICE_INFO[] struDevInfo = new HCUsbSDK.USB_DEVICE_INFO[nDeviceNum]; 
        HCUsbSDK.USB_DEVICE_INFO struDev = new HCUsbSDK.USB_DEVICE_INFO(); 
        Pointer pDevInfoList = AllocMemory(struDev.size() * nDeviceNum);  
        struDev.dwSize = struDev.size();        
        long offset = 0;
        for(int i=0; i < nDeviceNum; ++i)
        {
        	struDevInfo[i] = struDev;
        	Pointer pJavaMem = struDevInfo[i].getPointer();
        	pDevInfoList.write(offset, pJavaMem.getByteArray(0, struDevInfo[i].size()), 0, struDevInfo[i].size());
        	offset += struDevInfo[i].size();
        }

      
        if (!hcUsbSDK.USB_EnumDevices(nDeviceNum, pDevInfoList))
        {
        	System.out.println("当前无设备");
			return;
        }
        
        //Pointer转结构体数组
        offset = 0;
		for (int i=0; i<nDeviceNum; ++i)
		{
			struDevInfo[i].write();
			Pointer pJavaMem = struDevInfo[i].getPointer();
			pJavaMem.write(0, pDevInfoList.getByteArray(offset, struDevInfo[i].size()), 0, struDevInfo[i].size());
			struDevInfo[i].read();
			offset += struDevInfo[i].size();
		}
        
        
		if(lUserID != -1)
    	{
    		return;
    	}
		
    	StruCurUsbLoginInfo.dwSize = StruCurUsbLoginInfo.size();
    	StruCurUsbLoginInfo.dwTimeout = 5000;  
    	StruCurUsbLoginInfo.dwVID = struDevInfo[0].dwVID;
    	StruCurUsbLoginInfo.dwPID = struDevInfo[0].dwPID;
    	StruCurUsbLoginInfo.szSerialNumber = struDevInfo[0].szSerialNumber;
    	StruDeviceRegRes.dwSize = StruDeviceRegRes.size();
    	lUserID = hcUsbSDK.USB_Login(StruCurUsbLoginInfo, StruDeviceRegRes);
    	if(lUserID == -1)
    	{
    		System.out.println("USB_Login Fail!");
    	}
	}
    

    /*************************
     	娉ㄩ攢璁惧
     **************************/
    public void LogoutDevice(ActionEvent e)
    {
    	if(hcUsbSDK.USB_Logout(lUserID))
    	{
    		lUserID = -1;
    	}
    }
    
    public class FDExtenResultCallBack implements HCUsbSDK.FDExtenResultCallBack
    {
    	public void invoke(long lPort, HCUsbSDK.USB_FD_RESULT_PARAM struFDResultInfo, Pointer pUser)
    	{
    		
    	}
    }
    
    /***************************
     * 婵�娲诲崱
     *****************************/
    public void StartPreivew(ActionEvent e)
    { 
        
    	LoginDevice();
    	    	
    	 //设置设备视频参数
    	HCUsbSDK.USB_VIDEO_PARAM struVideoParam = new HCUsbSDK.USB_VIDEO_PARAM();
    	struVideoParam.dwFramerate = 30;
    	struVideoParam.dwWidth = 640;
        struVideoParam.dwHeight = 480;
        struVideoParam.dwVideoFormat = HCUsbSDK.USB_STREAM_MJPEG;
        
        HCUsbSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
        struConfigInputInfo.dwInBufferSize = struVideoParam.size();
        Pointer ptrInputInfo = struVideoParam.getPointer();      
        struVideoParam.write();
        struConfigInputInfo.lpInBuffer = ptrInputInfo;
        
        HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
        struConfigOutputInfo.dwOutBufferSize = struConfigOutputInfo.size();
        
        if (!hcUsbSDK.USB_SetDeviceConfig(lUserID, HCUsbSDK.USB_SET_VIDEO_PARAM, struConfigInputInfo, struConfigOutputInfo))
        {
        	System.out.println("USB_SET_VIDEO_PARAM Fail!");
        }
        else
        {
        	System.out.println("USB_SET_VIDEO_PARAM Succ!");
        }

        //设置码流参数
        HCUsbSDK.USB_SRC_STREAM_CFG struSrcStreamCfg = new HCUsbSDK.USB_SRC_STREAM_CFG();
        struSrcStreamCfg.dwStreamType = HCUsbSDK.USB_STREAM_MJPEG;
        struSrcStreamCfg.bUseAudio = 0;
        

        struConfigInputInfo.dwInBufferSize = struSrcStreamCfg.size();
        ptrInputInfo = struSrcStreamCfg.getPointer();
        struSrcStreamCfg.write();
        struConfigInputInfo.lpInBuffer = ptrInputInfo;
        
        struConfigOutputInfo.dwOutBufferSize = struConfigOutputInfo.size();
        
        if (!hcUsbSDK.USB_SetDeviceConfig(lUserID, HCUsbSDK.USB_SET_SRC_STREAM_TYPE, struConfigInputInfo, struConfigOutputInfo))
        {
        	System.out.println("USB_SET_SRC_STREAM_TYPE Fail");
        }
        else
        {
        	System.out.println("USB_SET_SRC_STREAM_TYPE Succ!");
        }
        
        //开启预览
        HCUsbSDK.USB_PREVIEW_PARAM struPreviewParam =new HCUsbSDK.USB_PREVIEW_PARAM();
        struPreviewParam.dwSize = struPreviewParam.size();
        HWND hwnd = new HWND(Native.getComponentPointer(panelPlay)); // get preview handle
        struPreviewParam.hWindow = hwnd; // get preview handle
        struPreviewParam.dwStreamType = HCUsbSDK.USB_STREAM_PS_MJPEG;
        struPreviewParam.bUseAudio = 0;
        struPreviewParam.bYUVCallback = 0;
        m_handle = hcUsbSDK.USB_StartPreview(lUserID, struPreviewParam);
        if (m_handle == -1)
        {
        	System.out.println("USB_StartPreview Fail!");
        }
        else
        {
        	System.out.println("USB_StartPreview Succ!");
        }
        
        //开启人脸                     
       HCUsbSDK.USB_FACE_DETECT_PARAM struFDParam = new HCUsbSDK.USB_FACE_DETECT_PARAM();
       m_FaceDetectExtenResultCallBack = new FDExtenResultCallBack(); 
 	   struFDParam.fnFDExtenResultCallBack = m_FaceDetectExtenResultCallBack;
        //启动人脸检测
//        int m_iFDChannel = hcUsbSDK.USB_StartFaceDetect(lUserID, struFDParam);
//        if (m_iFDChannel == -1)
//        {
//        	System.out.println("USB_StartFaceDetect Fail!");
//        }
//        else
//        {
//        	System.out.println("USB_StartFaceDetect Succ!");
//        }
    }
    
    /****************************
     * 韬唤璇佷俊鎭厤缃�  
     *************************/
    public void StopPreview(ActionEvent e)
    {
    	 if (!hcUsbSDK.USB_StopChannel(lUserID, m_handle))
    	 {
    		 System.out.println("USB_StopChannel Fail!");
    	 }
    	 else
         {
         	System.out.println("USB_StopChannel Succ!");
         	panelPlay.repaint();
         }

    }
    
    /****************************
     * 韬唤璇佷俊鎭厤缃�  
     *************************/
    public void Capture(ActionEvent e)
    {
    	HCUsbSDK.USB_CAPTURE_PARAM struCapParam = new HCUsbSDK.USB_CAPTURE_PARAM();
    	struCapParam.dwSize = struCapParam.size(); 	
    	struCapParam.szFilePath = "C:\\test.jpg".getBytes();  
    	struCapParam.dwType = 0;
    	 if (!hcUsbSDK.USB_Capture(lUserID, struCapParam))
    	 {
    		 System.out.println("USB_Capture Fail!");
    	 }
    	 else
    	 {
    		 System.out.println("USB_Capture Succ!");
    	 }
    }

}
