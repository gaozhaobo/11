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

import test.HCUsbSDK.USB_PREVIEW_PARAM;

//import test.HCUsbSDK.LOG_LEVEL_ENUM;
//import test.HCUsbSDK.USB_SDK_DEVICE_INFO;

import javax.swing.UIManager;
import javax.swing.JTextField;
import javax.swing.JLabel;
import javax.swing.JComboBox;
import javax.swing.JPasswordField;
import javax.swing.JTable;
import javax.swing.JScrollPane;
import javax.imageio.ImageIO;
import javax.swing.JButton;
import java.awt.event.ActionListener;
import java.util.Date;
import java.text.SimpleDateFormat;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.image.BufferedImage;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;

import javax.swing.JTabbedPane;

public class ThermalDemo_USB extends JFrame
{
	static HCUsbSDK hcUsbSDK = HCUsbSDK.INSTANCE;
	private JPanel contentPane;
	private JTextField textField_UserName;
	private JPasswordField passwordField;
	private static JTable DeviceInfo_table;
	private static JTable Info_table;
	private static JLabel label7;
	private static JTextField textField_emissivity;
	private static JTextField textField_temperature; 
	private static JTextField textField_Enable; 
	private static JTextField textField_Distance;
	private static JTextField textField_PointX;
	private static JTextField textField_PointY;
	private static JScrollPane DeviceInfo_scrollPane;
	private static JButton btnTraverse;
	private static JButton btnLoginDevice;
	private static JButton btnLogoutDevice;
	private static JButton btnStartPreview;
	private static JButton btnStopPreview;
	private static JButton btnAPPENDDATA;
	private static JButton btnGet;
	private static JButton btnSet;
	private final static int INITIALIZED_INDEX = 1;
	private int g_nEnumDevIndex = INITIALIZED_INDEX;
	private Panel panelRealPlay = new Panel();
	private Panel panelPlay;
	private static int IndexOfInfo = INITIALIZED_INDEX;  
	private int SelectedIndex = -1; 
	private HCUsbSDK.USB_USER_LOGIN_INFO StruCurUsbLoginInfo = new HCUsbSDK.USB_USER_LOGIN_INFO();
	private HCUsbSDK.USB_DEVICE_REG_RES StruDeviceRegRes = new HCUsbSDK.USB_DEVICE_REG_RES();
	private HCUsbSDK.USB_BLACK_BODY struBlackBody = new HCUsbSDK.USB_BLACK_BODY();
	
	
	private HCUsbSDK.USB_DEVICE_INFO[] struDevList; 
	private int nDeviceNum = 0;
	public static int m_lUserID[] = null;
	public static int m_lCurChannel = -1;
	private int m_iPriviewUserID = -1;//码流对应的设备index;
	private String szLogPath = "C:/UsbSDKlog/";
	private int m_VersionNum = 0;
    public final int WM_DEVICECHANGE = 0x0219;
    
    String s1, s2, s3, s4, s5, s6, s7, s8;
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					hcUsbSDK.USB_Init();
					ThermalDemo_USB frame = new ThermalDemo_USB();
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
	public ThermalDemo_USB() {
		InitComponents();
		btnLoginDevice.setEnabled(false);
		btnLogoutDevice.setEnabled(false);
		hcUsbSDK.USB_SetLogToFile(3, szLogPath, false);
		m_VersionNum = hcUsbSDK.USB_GetSDKVersion();
		GetVersion(m_VersionNum);
	}
	
	
	// Init Component 鍒濆鍖栫晫闈�
	private void InitComponents()
	{
		setTitle("ThermalDemo_USB");
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();  
		int width = (int)screen.getWidth();
		int height = (int)screen.getHeight();
		setBounds(width/3, height/5, 780, 666);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		JPanel VerInfo_panel = new JPanel();
		VerInfo_panel.setLayout(null);
		VerInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		VerInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "版本信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		VerInfo_panel.setBounds(10, 10, 192, 60);
		getContentPane().add(VerInfo_panel);
		
		JLabel label = new JLabel("SDK版本");
		label.setBounds(10, 25, 72, 15); 
		VerInfo_panel.add(label);
		
		JLabel label1 = new JLabel("HCUsbSDK V");
		label1.setBounds(68, 25, 90, 15);
		VerInfo_panel.add(label1);
				
		label7 = new JLabel("");
		label7.setBounds(142, 25, 54, 15);
		VerInfo_panel.add(label7);
			
		btnTraverse = new JButton("枚举设备");
		btnTraverse.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TraverseDevice(e);
			}
		});
		btnTraverse.setBounds(320, 32, 93, 23);
		contentPane.add(btnTraverse);
		
		btnLoginDevice = new JButton("登录设备");
		btnLoginDevice.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDevice(e);
			}
		});
		btnLoginDevice.setBounds(480, 32, 93, 23);
		contentPane.add(btnLoginDevice);
		
		btnLogoutDevice = new JButton("注销");
		btnLogoutDevice.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LogoutDevice(e);
			}
		});
		btnLogoutDevice.setBounds(640, 32, 93, 23);
		contentPane.add(btnLogoutDevice);
		
		JPanel Login_panel = new JPanel();
		Login_panel.setLayout(null);
		Login_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		Login_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "设备操作",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		Login_panel.setBounds(280, 10, 489, 60);
		getContentPane().add(Login_panel);
		
							
		JPanel DeviceInfo_panel = new JPanel();
		DeviceInfo_panel.setLayout(null);
		DeviceInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		DeviceInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "设备列表",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		DeviceInfo_panel.setBounds(10, 75, 760, 158);
		getContentPane().add(DeviceInfo_panel);
		
		
		DeviceInfo_scrollPane = new JScrollPane();
		DeviceInfo_scrollPane.setBounds(10, 27, 738, 121);
		DeviceInfo_panel.add(DeviceInfo_scrollPane);
		
		DeviceInfo_table = new JTable();
		DeviceInfo_table.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				GetIndex(e);
			}
		});
		DeviceInfo_table.setModel(this.initialTableModel());
		DeviceInfo_table.getColumnModel().getColumn(0).setPreferredWidth(20);
		DeviceInfo_table.getColumnModel().getColumn(1).setPreferredWidth(30);
		DeviceInfo_table.getColumnModel().getColumn(2).setPreferredWidth(30);
		DeviceInfo_table.getColumnModel().getColumn(3).setPreferredWidth(50);
		DeviceInfo_table.getColumnModel().getColumn(4).setPreferredWidth(180);
		DeviceInfo_scrollPane.setViewportView(DeviceInfo_table);
		
		
		//预览界面及按钮
		btnStartPreview = new JButton("开始预览");
		btnStartPreview.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				StartPreivew(e);
			}
		});
		btnStartPreview.setBounds(10, 260, 120, 23);
		contentPane.add(btnStartPreview);
		
		btnStopPreview = new JButton("停止预览");
		btnStopPreview.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				StopPreview(e);
			}
		});
		btnStopPreview.setBounds(10, 310, 120, 23);
		contentPane.add(btnStopPreview);
			
		btnAPPENDDATA = new JButton("获取热图");
		btnAPPENDDATA.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				GetAppendDdta(e);
			}
		});
		btnAPPENDDATA.setBounds(10, 360, 120, 23);
		contentPane.add(btnAPPENDDATA);
		
		panelRealPlay.setForeground(Color.YELLOW);
		panelRealPlay.setBounds(10, 138, 400, 300);
		contentPane.setLayout(null);
		contentPane.add(panelRealPlay);
		panelRealPlay.setLayout(null);
		
		panelPlay = new Panel();
		panelPlay.setBackground(Color.LIGHT_GRAY);
		panelPlay.setBounds(150, 0, 566, 485);
		panelRealPlay.add(panelPlay);
		
		//配置模块
		JPanel Config_panel = new JPanel();
		Config_panel.setLayout(null);
		Config_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		Config_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "测温黑体参数配置",
		TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		Config_panel.setBounds(429, 239, 339, 180);
		getContentPane().add(Config_panel);
		
		JLabel lenable= new JLabel("使能:");
		lenable.setBounds(30, 30, 50, 20); 
		Config_panel.add(lenable);
		
		textField_Enable = new JTextField("");
		textField_Enable.setBounds(85, 30, 54, 20);
		Config_panel.add(textField_Enable);
		
		JLabel lEmissivity = new JLabel("黑体发射率:");
		lEmissivity.setBounds(30, 65, 72, 20); 
		Config_panel.add(lEmissivity);
		
		textField_emissivity = new JTextField("");
		textField_emissivity.setBounds(105, 65, 54, 20);
		Config_panel.add(textField_emissivity);
		
		JLabel lTemperature = new JLabel("黑体温度:");
		lTemperature.setBounds(30, 100, 72, 20); 
		Config_panel.add(lTemperature);
		
		textField_temperature = new JTextField("");
		textField_temperature.setBounds(95, 100, 54, 20);
		Config_panel.add(textField_temperature);
		
		JLabel lDistance= new JLabel("距离:");
		lDistance.setBounds(199, 30, 50, 20); 
		Config_panel.add(lDistance);
		
		textField_Distance = new JTextField("");
		textField_Distance.setBounds(238, 30, 64, 20);
		Config_panel.add(textField_Distance);
		
		JLabel lPointX= new JLabel("坐标X:");
		lPointX.setBounds(199, 65, 50, 20); 
		Config_panel.add(lPointX);
		
		textField_PointX = new JTextField("");
		textField_PointX.setBounds(238, 65, 64, 20);
		Config_panel.add(textField_PointX);
		
		JLabel lPointY= new JLabel("坐标Y:");
		lPointY.setBounds(199, 100, 50, 20); 
		Config_panel.add(lPointY);
		
		textField_PointY = new JTextField("");
		textField_PointY.setBounds(238, 100, 64, 20);
		Config_panel.add(textField_PointY);
		
		
		btnGet = new JButton("获取");
		btnGet.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				GetBlackCfg(e);
			}
		});
		btnGet.setBounds(50, 138, 80, 23);
		Config_panel.add(btnGet);
		
		btnSet = new JButton("设置");
		btnSet.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				SetBlackCfg(e);
			}
		});
		btnSet.setBounds(180, 138, 80, 23);
		Config_panel.add(btnSet);
		
		
		
		//日志模块
		JPanel Info_panel = new JPanel();
		Info_panel.setLayout(null);
		Info_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "日志信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		Info_panel.setBounds(10, 420, 754, 208);
		getContentPane().add(Info_panel);
		
		JScrollPane Info_scrollPane = new JScrollPane();
		Info_scrollPane.setBounds(10, 20, 734, 178);
		Info_panel.add(Info_scrollPane);
		
		Info_table = new JTable();
		Info_table.setModel(this.initialTableModel2());
		Info_table.getColumnModel().getColumn(0).setPreferredWidth(50);
		Info_table.getColumnModel().getColumn(1).setPreferredWidth(120);
		Info_table.getColumnModel().getColumn(3).setPreferredWidth(350);
		Info_scrollPane.setViewportView(Info_table);
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
		Sversion = s1 + "." + s2 + "." + s3 + "." + s4;
		label7.setText(Sversion);
		WriteLog(HCUsbSDK.INF_LEVEL, "获取SDK版本号为：" + Sversion);  //鍐欐棩蹇�
	}
	
	/*****************
	 鍒濆鍖朖Table
	 **************************/
    public DefaultTableModel initialTableModel()
    {
        String tabeTile[];
        tabeTile = new String[]{"Index", "VID", "PID", "制造商", "设备名称", "设备序列号", "已登录", "已激活"};
        DefaultTableModel deviceTableModel = new DefaultTableModel(tabeTile, 0);
        return deviceTableModel;
    }
    
    public DefaultTableModel initialTableModel2()
    {
        String tabeTile[];
        tabeTile = new String[]{"Index", "Time", "Level", "Info"};
        DefaultTableModel deviceTableModel = new DefaultTableModel(tabeTile, 0);
        return deviceTableModel;
    }
    
    /****************************
     鑾峰緱 (DefaultTableModel)JTable.getModel()
     **************************/
    public static DefaultTableModel getTableModel()
    {
    	return ((DefaultTableModel)DeviceInfo_table.getModel());
    }
    
    public static DefaultTableModel getTableModel2()
    {
    	return ((DefaultTableModel)Info_table.getModel());
    }
    
    /********************
                      鎸夐敭鍝嶅簲鍑芥暟--閬嶅巻璁惧
     *******************/
    private void TraverseDevice(ActionEvent arg0)
    {
    	//先注销设备,再重新遍历
	    for(int i=0;i< nDeviceNum ;i ++)
	    {
	    	if(m_lUserID[i] >= 0)
	    	{
	    		hcUsbSDK.USB_Logout(m_lUserID[i]);
	    		m_lUserID[i] = -1;
	    	}
	    }
    	g_nEnumDevIndex = 0; 
    	DefaultTableModel tableModel = (DefaultTableModel) DeviceInfo_table.getModel();
    	tableModel.setRowCount(0);  											//先清空列表
    	int dwCount = hcUsbSDK.USB_GetDeviceCount();
       	if(dwCount <= 0)
    	{
    		WriteLog(HCUsbSDK.INF_LEVEL, "No device!");
    		return;
    	}
    	nDeviceNum = dwCount;
    	//根据获取到的设备数量，申请对应大小的设备信息结构体数组
    	struDevList = new HCUsbSDK.USB_DEVICE_INFO[dwCount];  //数组用来存放设备
    	m_lUserID = new int[dwCount];
    	HCUsbSDK.OUT_USB_DEVICE_INFO  struOutDevice = new HCUsbSDK.OUT_USB_DEVICE_INFO();
    	struOutDevice.init(dwCount);
    	Pointer pStruDeviceInfo = struOutDevice.getPointer();
    	struOutDevice.write();
    	if(hcUsbSDK.USB_EnumDevices(dwCount, pStruDeviceInfo))
    	{
    		struOutDevice.read();
    		while((--dwCount) >= 0)
    		{
        		s1 = String.valueOf(struOutDevice.struDeviceArr[g_nEnumDevIndex].dwIndex);
        		s2 = String.valueOf(struOutDevice.struDeviceArr[g_nEnumDevIndex].dwVID);
        		s3 = String.valueOf(struOutDevice.struDeviceArr[g_nEnumDevIndex].dwPID);
        		s4 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szManufacturer);
        		s5 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szDeviceName);
        		s6 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szSerialNumber);
        		s7 = new String("no");
        		s8 = new String("no");
        		String[] log = {s1, s2, s3, s4.trim(), s5.trim(), s6.trim(), s7.trim(), s8.trim()};  	//.trim()去掉String右侧的空格
        		ThermalDemo_USB.getTableModel().addRow(log);  						//将数据写到表中
        		struDevList[g_nEnumDevIndex] = struOutDevice.struDeviceArr[g_nEnumDevIndex];  			//存储到数组中方便登录获取数据，数组从0开始
        		m_lUserID[struOutDevice.struDeviceArr[g_nEnumDevIndex].dwIndex -1] = -1;
        		g_nEnumDevIndex++;
    		}
    		WriteLog(HCUsbSDK.INF_LEVEL, "SUCCESS USB_SDK_EnumDevice()");
    	}
    	else
    	{
			WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_EnumDevice()");
		}	
    }
    
    /***********************
                  鑾峰彇褰撳墠榧犳爣鐐瑰嚮鐨凧Table琛屽彿
     ************************/
    public void GetIndex(MouseEvent e)
    {
    	int index = DeviceInfo_table.getSelectedRow();  
    	SelectedIndex = index;
    	btnLoginDevice.setEnabled(true);
		btnLogoutDevice.setEnabled(true);
    }
    
    /***********************
                     鎸夐敭鍝嶅簲浜嬩欢--鐧诲綍璁惧
     *************************/
    public void LoginDevice(ActionEvent arg0)
    {
    	if(m_lUserID[struDevList[SelectedIndex].dwIndex -1] >= 0)
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_Login");
    		return;
    	}
    	StruCurUsbLoginInfo.dwSize = StruCurUsbLoginInfo.size();
    	StruCurUsbLoginInfo.dwTimeout = 5000;  
    	StruCurUsbLoginInfo.dwVID = struDevList[SelectedIndex].dwVID;
    	StruCurUsbLoginInfo.dwPID = struDevList[SelectedIndex].dwPID;
    	StruCurUsbLoginInfo.szSerialNumber = struDevList[SelectedIndex].szSerialNumber;
    	StruDeviceRegRes.dwSize = StruDeviceRegRes.size();
    	m_lUserID[struDevList[SelectedIndex].dwIndex -1] = hcUsbSDK.USB_Login(StruCurUsbLoginInfo, StruDeviceRegRes);
    	if(m_lUserID[struDevList[SelectedIndex].dwIndex -1] < 0)
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_Login");
    	}
    	else
    	{
        	DefaultTableModel tableModel = (DefaultTableModel) DeviceInfo_table.getModel();
        	tableModel.setRowCount(0);  											//先清空列表
    	    String s1, s2, s3, s4, s5, s6, s7, s8;
    	    for(int i=0;i< nDeviceNum ;i ++)
    	    {
    	    	if( struDevList[i].dwIndex == struDevList[SelectedIndex].dwIndex)
    	    	{
    	    		s7 = new String("yes");
    				s8 = new String("yes");
    	    	}
    	    	else
    	    	{
    	    		if(m_lUserID[struDevList[i].dwIndex - 1] >=  0)
    	    		{
        	    		s7 = new String("yes");
        				s8 = new String("yes");
    	    		}
    	    		else if (m_lUserID[struDevList[i].dwIndex -1] == -1)
    	    		{
        	    		s7 = new String("no");
        				s8 = new String("no");
    	    		}
    	    		else
    	    		{
        	    		s7 = new String("no");
        				s8 = new String("yes");
    	    		}
    	    	}
    	    	
        		s1 = String.valueOf(struDevList[i].dwIndex);
        		s2 = String.valueOf(struDevList[i].dwVID);
        		s3 = String.valueOf(struDevList[i].dwPID);
        		s4 = new String(struDevList[i].szManufacturer);
        		s5 = new String(struDevList[i].szDeviceName);
        		s6 = new String(struDevList[i].szSerialNumber);
    			String[] log = {s1, s2, s3, s4.trim(), s5.trim(), s6.trim(), s7.trim(), s8.trim()};  //.trim()鍘绘帀String鍙充晶鐨勭┖鏍�
    			ThermalDemo_USB.getTableModel().addRow(log);  //灏嗘暟鎹啓鍒拌〃涓�
    					
        		String src = new String(StruCurUsbLoginInfo.szSerialNumber);
        		String SuccesfulLoginInfo = "SUCCESS USB_Login:" + src;
        		WriteLog(HCUsbSDK.INF_LEVEL, SuccesfulLoginInfo);
    	    }
    	}
    }
    
    /*************************
     	娉ㄩ攢璁惧
     **************************/
    public void LogoutDevice(ActionEvent e)
    {
    	if(hcUsbSDK.USB_Logout(m_lUserID[struDevList[SelectedIndex].dwIndex -1]))
    	{
        	DefaultTableModel tableModel = (DefaultTableModel) DeviceInfo_table.getModel();
        	tableModel.setRowCount(0);
    	    String s1, s2, s3, s4, s5, s6, s7, s8;
    	    for(int i=0;i< nDeviceNum ;i ++)
    	    {
    	    	if( struDevList[i].dwIndex == struDevList[SelectedIndex].dwIndex)
    	    	{
    	    		s7 = new String("no");
    				s8 = new String("yes");
    				m_lUserID[struDevList[SelectedIndex].dwIndex -1] = -2;//之前登录过又登出的情况，-1是从来都没登录过的情况
    	    	}
    	    	else
    	    	{
    	    		if(m_lUserID[struDevList[i].dwIndex - 1] >= 0)
    	    		{
        	    		s7 = new String("yes");
        				s8 = new String("yes");
    	    		}
    	    		else if (m_lUserID[struDevList[i].dwIndex -1] == -1)
    	    		{
        	    		s7 = new String("no");
        				s8 = new String("no");
    	    		}
    	    		else
    	    		{
        	    		s7 = new String("no");
        				s8 = new String("yes");
    	    		}
    	    	}
    	    	
        		s1 = String.valueOf(struDevList[i].dwIndex);
        		s2 = String.valueOf(struDevList[i].dwVID);
        		s3 = String.valueOf(struDevList[i].dwPID);
        		s4 = new String(struDevList[i].szManufacturer);
        		s5 = new String(struDevList[i].szDeviceName);
        		s6 = new String(struDevList[i].szSerialNumber);
    			String[] log = {s1, s2, s3, s4.trim(), s5.trim(), s6.trim(), s7.trim(), s8.trim()};  //.trim()鍘绘帀String鍙充晶鐨勭┖鏍�
    			ThermalDemo_USB.getTableModel().addRow(log);  //灏嗘暟鎹啓鍒拌〃涓�
    					
        		String src = new String(StruCurUsbLoginInfo.szSerialNumber);
        		String SuccesfulLoginInfo = "SUCCESS USB_Logout:" + src;
        		WriteLog(HCUsbSDK.INF_LEVEL, SuccesfulLoginInfo);
    	    }
    	}
    	else
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_Logout()");
		}
    }
    
    public void GetBlackCfg(ActionEvent e)
    {
    	HCUsbSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
    	HCUsbSDK.USB_COMMON_COND struCond = new HCUsbSDK.USB_COMMON_COND();
    	 //条件参数
        struCond.byChannelID = 1;   
        struConfigInputInfo.dwCondBufferSize = struCond.size();
        Pointer ptrCondInfo = struCond.getPointer();
        struCond.write();
        struConfigInputInfo.lpCondBuffer = ptrCondInfo;
        
        struConfigInputInfo.dwInBufferSize = struConfigInputInfo.size();
        Pointer ptrInputInfo = struConfigInputInfo.getPointer();
        struConfigInputInfo.write();
        struConfigInputInfo.lpInBuffer = ptrInputInfo;
        
        HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
        struConfigOutputInfo.dwOutBufferSize = struBlackBody.size();
        Pointer ptrOutputInfo = struBlackBody.getPointer();
        struBlackBody.write();
        struConfigOutputInfo.lpOutBuffer = ptrOutputInfo;
        
        if (!hcUsbSDK.USB_SetDeviceConfig(m_lUserID[struDevList[SelectedIndex].dwIndex -1], HCUsbSDK.USB_GET_BLACK_BODY, struConfigInputInfo, struConfigOutputInfo))
        {
        	WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_GET_BLACK_BODY");
        }
        else
        {
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_GET_BLACK_BODY");
        	struBlackBody.read();
        	if(1 == struBlackBody.byEnabled)
        	{
        		textField_Enable.setText("yes"); 
        	}
        	else
        	{
        		textField_Enable.setText("no");  //鍗＄被鍨�
        	}
        	textField_emissivity.setText(String.valueOf(struBlackBody.dwEmissivity)); 
        	textField_temperature.setText(String.valueOf(struBlackBody.dwTemperature)); 
        	textField_Distance.setText(String.valueOf(struBlackBody.dwDistance));
        	textField_PointX.setText(String.valueOf(struBlackBody.dwCentrePointX));
        	textField_PointY.setText(String.valueOf(struBlackBody.dwCentrePointY));
        }
        
    }
    
    
    public void SetBlackCfg(ActionEvent e)
    {
    	HCUsbSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
    	HCUsbSDK.USB_COMMON_COND struCond = new HCUsbSDK.USB_COMMON_COND();
    	 //条件参数
        struCond.byChannelID = 1;   
        struConfigInputInfo.dwCondBufferSize = struCond.size();
        Pointer ptrCondInfo = struCond.getPointer();
        struCond.write();
        struConfigInputInfo.lpCondBuffer = ptrCondInfo;
               

        if(textField_Enable.getText(). equals("yes"))
        {
        	struBlackBody.byEnabled = 1;
        }
        struBlackBody.dwEmissivity = Integer.parseInt(textField_emissivity.getText());
        struBlackBody.dwTemperature = Integer.parseInt(textField_temperature.getText());
        struBlackBody.dwDistance = Integer.parseInt(textField_Distance.getText());
        struBlackBody.dwCentrePointX = Integer.parseInt(textField_PointX.getText());
        struBlackBody.dwCentrePointY = Integer.parseInt(textField_PointY.getText());
        
        struConfigInputInfo.dwInBufferSize = struBlackBody.size();
        Pointer ptrInputInfo = struBlackBody.getPointer();
        struBlackBody.write();
        struConfigInputInfo.lpInBuffer = ptrInputInfo;
        
        HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
        struConfigOutputInfo.dwOutBufferSize = struConfigOutputInfo.size();
        
        if (!hcUsbSDK.USB_SetDeviceConfig(m_lUserID[struDevList[SelectedIndex].dwIndex -1], HCUsbSDK.USB_SET_BLACK_BODY, struConfigInputInfo, struConfigOutputInfo))
        {
        	WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SET_BLACK_BODY");
        }
        else
        {
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_SET_BLACK_BODY");
        }
    }
    
    /***************************
     * 婵�娲诲崱
     *****************************/
    public void StartPreivew(ActionEvent e)
    {   
    	if(m_lCurChannel != -1)//如果有正在播放的流先停掉
    	{
    		hcUsbSDK.USB_StopChannel(m_iPriviewUserID, m_lCurChannel);
    		m_iPriviewUserID = -1;
    	}
    	 //设置设备视频参数
    	HCUsbSDK.USB_VIDEO_PARAM struVideoParam = new HCUsbSDK.USB_VIDEO_PARAM();
    	struVideoParam.dwFramerate = 30;
    	struVideoParam.dwWidth = 240;
        struVideoParam.dwHeight = 320;
        struVideoParam.dwVideoFormat = HCUsbSDK.USB_STREAM_MJPEG;
        
        HCUsbSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
        struConfigInputInfo.dwInBufferSize = struVideoParam.size();
        Pointer ptrInputInfo = struVideoParam.getPointer();
        struVideoParam.write();
        struConfigInputInfo.lpInBuffer = ptrInputInfo;
        
        HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
        struConfigOutputInfo.dwOutBufferSize = struConfigOutputInfo.size();
        
        if (!hcUsbSDK.USB_SetDeviceConfig(m_lUserID[struDevList[SelectedIndex].dwIndex -1], HCUsbSDK.USB_SET_VIDEO_PARAM, struConfigInputInfo, struConfigOutputInfo))
        {
        	WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SET_VIDEO_PARAM");
        }
        else
        {
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_SET_VIDEO_PARAM");
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
        
        if (!hcUsbSDK.USB_SetDeviceConfig(m_lUserID[struDevList[SelectedIndex].dwIndex -1], HCUsbSDK.USB_SET_SRC_STREAM_TYPE, struConfigInputInfo, struConfigOutputInfo))
        {
        	WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SET_SRC_STREAM_TYPE");
        }
        else
        {
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_SET_SRC_STREAM_TYPE");
        }
        
        //开启预览
        HCUsbSDK.USB_PREVIEW_PARAM struPreviewParam =new HCUsbSDK.USB_PREVIEW_PARAM();
        struPreviewParam.dwSize = struPreviewParam.size();
        struPreviewParam.hWindow = new HWND(Native.getComponentPointer(panelPlay)); // get preview handle
        struPreviewParam.dwStreamType = HCUsbSDK.USB_STREAM_PS_MJPEG;
        struPreviewParam.bUseAudio = 0;
        int userid = m_lUserID[struDevList[SelectedIndex].dwIndex -1];
        m_lCurChannel = hcUsbSDK.USB_StartPreview(userid, struPreviewParam);
        if (m_lCurChannel == -1)
        {
        	WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_StartPreview");
        }
        else
        {
        	m_iPriviewUserID = userid;
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_StartPreview");
        }

        
    }
    
    /****************************
     * 韬唤璇佷俊鎭厤缃�
     *************************/
    public void StopPreview(ActionEvent e)
    {
    	 if (!hcUsbSDK.USB_StopChannel(m_lUserID[struDevList[SelectedIndex].dwIndex -1], m_lCurChannel))
    	 {
    		 WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_StopChannel");
    	 }
    	 else
    	 {		 
    		 WriteLog(HCUsbSDK.INF_LEVEL, "SUCC USB_StopChannel");
    		 m_iPriviewUserID = -1;
    		 panelPlay.repaint();
    	 }

    }
    
    /****************************
     * 韬唤璇佷俊鎭厤缃�
     *************************/
    public void GetAppendDdta(ActionEvent e)
    {

    	HCUsbSDK.USB_COMMON_COND struCond = new HCUsbSDK.USB_COMMON_COND();
    	HCUsbSDK.USB_CONFIG_INPUT_INFO struConfigInputInfo = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
    	//条件参数
       struCond.byChannelID = 1;         
       Pointer ptrCondInfo = struCond.getPointer();
       struCond.write();
       struConfigInputInfo.lpCondBuffer = ptrCondInfo;
       struConfigInputInfo.dwCondBufferSize = struCond.size();
       
       struConfigInputInfo.dwInBufferSize = struConfigInputInfo.size();
         
    	//设置设备视频参数
    	HCUsbSDK.USB_JPEGPIC_WITH_APPENDDATA struJpegpicWithAppendData = new HCUsbSDK.USB_JPEGPIC_WITH_APPENDDATA();
    	struJpegpicWithAppendData.pP2pData = new Memory(1024*1024);
        struJpegpicWithAppendData.dwP2pDataLen = 1024 * 1024 ;
        struJpegpicWithAppendData.pJpegPic = new Memory(1024*1024);
        struJpegpicWithAppendData.dwJpegPicLen = 1024 * 1024 ;
             
        HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
        Pointer ptrOutputInfo = struJpegpicWithAppendData.getPointer();
        struJpegpicWithAppendData.write();
        struConfigOutputInfo.lpOutBuffer = ptrOutputInfo;       
        struConfigOutputInfo.dwOutBufferSize = struJpegpicWithAppendData.size();
        
        
    	if (!hcUsbSDK.USB_GetDeviceConfig(m_lUserID[struDevList[SelectedIndex].dwIndex -1], HCUsbSDK.USB_GET_JPEGPIC_WITH_APPENDDATA, struConfigInputInfo, struConfigOutputInfo))
        {
            WriteLog(HCUsbSDK.INF_LEVEL, "FAILED  USB_GET_JPEGPIC_WITH_APPENDDATA");
        }
        else
        {
        	WriteLog(HCUsbSDK.INF_LEVEL, "SUCC  USB_GET_JPEGPIC_WITH_APPENDDATA");
        	
        	struJpegpicWithAppendData.read();

        	if(struJpegpicWithAppendData.pJpegPic == null || struJpegpicWithAppendData.dwJpegPicLen == 0)
        	{
        		return;
        	}
    		try
    		{
    			File PicFile = new File("C:\\AppendData.jpg");
    			if(!PicFile.exists())
    				PicFile.createNewFile();
    			OutputStream os = new FileOutputStream("C:\\AppendData.jpg");
    			if(os == null)
    			{
    				 WriteLog(HCUsbSDK.INF_LEVEL, "Write AppendData Error");
    				 return;
    			}
    			os.write(struJpegpicWithAppendData.pJpegPic.getByteArray(0, struJpegpicWithAppendData.dwJpegPicLen), 0, struJpegpicWithAppendData.dwJpegPicLen);
    			os.flush();
    			os.close();
    		}catch(IOException ex)
    		{
    			System.out.println("IO Exception!");

    		}
        }
    }
    
    /******************************
    鍦ㄦ渶涓嬫柟淇℃伅琛ㄤ腑鍐欐棩蹇�
    *********************/
    public static void WriteLog(int Level, String Content)
    {
    	String s1, s2, s3, s4;
    	s1 = String.valueOf(IndexOfInfo);
    	SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");
    	s2 = df.format(new Date());
    	s3 = ReturnLevel(Level);
    	s4 = Content;
    	String[] log = {s1, s2, s3, s4};
		ThermalDemo_USB.getTableModel2().addRow(log);  
    	IndexOfInfo++;
    }
    
    public static String ReturnLevel(int type)
    {
    	String res = null;
    	switch(type)
    	{
    	case 1:
    		res = "ERR_LEVEL";
    		break;
    	case 2:
    		res = "DBG_LEVEL";
    		break;
    	case 3:
    		res = "INF_LEVEL";
    		break;
    	default:
    		break;
    	}
    	return res;
    }
}
