package test;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
import java.awt.Font;
import java.awt.Toolkit;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;

import com.sun.jna.Memory;
import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;

import test.HCUsbSDK.LOG_LEVEL_ENUM;
import test.HCUsbSDK.USB_DEVICE_INFO;

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
import java.util.Locale;
import java.util.Vector;
import java.text.SimpleDateFormat;
import java.awt.event.ActionEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.JTabbedPane;

public class AcsDemo_USB extends JFrame
{
	static HCUsbSDK hcUsbSDK = HCUsbSDK.INSTANCE;
	private JPanel contentPane;
	private JTextField textField_UserName;
	private JPasswordField passwordField;
	private static JTable DeviceInfo_table;
	private static JTable Info_table;
	private static JLabel label7;
	private final static int INITIALIZED_INDEX = 1;
	private HCUsbSDK.USB_DEVICE_INFO[] m_aHidDevInfo;  			//数组存储遍历到的设备，列表索引1开始
	private int g_nEnumDevIndex = INITIALIZED_INDEX;
	private static int IndexOfInfo = INITIALIZED_INDEX;  		//信息JTable更新信息的索引，从1开始
	private static int SelectedIndex = -1;  							//在设备列表中，当前鼠标选择行，初始没选中设为-1
	private HCUsbSDK.USB_USER_LOGIN_INFO StruCurUsbLoginInfo = new HCUsbSDK.USB_USER_LOGIN_INFO();
	private HCUsbSDK.USB_DEVICE_REG_RES StruDeviceRegRes = new HCUsbSDK.USB_DEVICE_REG_RES();
	public static int m_lUserID[] = null;
	private int nDeviceNum = 0;
	public static String szLogPath = "";
	private int m_VersionNum = 0;
    public final int WM_DEVICECHANGE = 0x0219;
    public static String LanEnvironment = "";
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {
			public void run() {
				try {
					hcUsbSDK.USB_Init();
					AcsDemo_USB frame = new AcsDemo_USB();
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
	public AcsDemo_USB() {
		//判断当前系统的语言环境
		Locale locale = Locale.getDefault();
		LanEnvironment = locale.getLanguage();
		//获取当前进程的路径
		szLogPath = System.getProperty("user.dir");
		szLogPath += "\\UsbSDKLog";
		InitComponents();
		btnLoginDevice.setEnabled(false);
		btnLogoutDevice.setEnabled(false);
		hcUsbSDK.USB_SetLogToFile(3, szLogPath, false);
		m_VersionNum = hcUsbSDK.USB_GetSDKVersion();
		GetVersion(m_VersionNum);
	}
	
	
	//将界面控件改成全局，用于更改界面的语言
	private static JPanel 	VerInfo_panel = null;
	private static JLabel 	label  = null;
	private static JLabel 	label2 = null;
	private static JPanel 	Login_panel = null;
	private static JLabel 	label4 = null;
	private static JLabel 	label5 = null;
	private static JPanel 	DeviceInfo_panel = null;
	private static JButton 	btnTraverse= null;
	private static JButton 	btnLoginDevice= null;
	private static JButton 	btnLogoutDevice= null;
	private static JButton 	btnActivateCard= null;
	private static JButton 	btnCertificateConfig= null;
	private static JPanel 	Tab_panel = null;
	private static JPanel 	p1 = null;
	private static JPanel 	p2 = null;
	private static JPanel 	Info_panel = null;
	private static DefaultTableModel deviceTableModel = null;
	private static JScrollPane DeviceInfo_scrollPane = null;
	
	private static JTabbedPane Tab = null;
	
	// Init Component 初始化界面
	private void InitComponents()
	{
		setTitle("AcsDemo_USB");
		setResizable(false);
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dimension screen = Toolkit.getDefaultToolkit().getScreenSize();  //获得屏幕分辨率，把界面显示在屏幕中间
		int width = (int)screen.getWidth();
		int height = (int)screen.getHeight();
		setBounds(width/3, height/5, 780, 666);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		setContentPane(contentPane);
		contentPane.setLayout(null);
		
		VerInfo_panel = new JPanel();
		VerInfo_panel.setLayout(null);
		VerInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		
		Login_panel = new JPanel();
		Login_panel.setLayout(null);
		Login_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		
		DeviceInfo_panel = new JPanel();
		DeviceInfo_panel.setLayout(null);
		DeviceInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		//设置滚动条，将表格加入到滚动条中
		DeviceInfo_scrollPane = new JScrollPane();
		DeviceInfo_scrollPane.setBounds(10, 27, 569, 121);
		
		Tab_panel = new JPanel();
		Tab_panel.setLayout(null);
		Tab_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		Tab = new JTabbedPane(JTabbedPane.TOP);
		Tab.setBounds(10, 21, 734, 127);
		
		Info_panel = new JPanel();
		Info_panel.setLayout(null);
		Info_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		if(LanEnvironment.contains("en"))
		{
			VerInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "version info",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
			VerInfo_panel.setBounds(10, 10, 359, 80);
			getContentPane().add(VerInfo_panel);
			
			label = new JLabel("build：");
			label.setBounds(10, 25, 46, 15);
			VerInfo_panel.add(label);
			
			JLabel label1 = new JLabel("2018.11.12");
			label1.setBounds(106, 25, 76, 15);
			VerInfo_panel.add(label1);
			
			label2 = new JLabel("sdk ver：");
			label2.setBounds(10, 50, 69, 15);
			VerInfo_panel.add(label2);
			
			JLabel label3 = new JLabel("HCUsbSDK");
			label3.setBounds(106, 50, 64, 15);
			VerInfo_panel.add(label3);
			
			label7 = new JLabel("");
			label7.setBounds(189, 50, 54, 15);
			VerInfo_panel.add(label7);
			
			
			Login_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "login info",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
			Login_panel.setBounds(379, 10, 385, 80);
			getContentPane().add(Login_panel);
			
			label4 = new JLabel("name：");
			label4.setBounds(10, 25, 54, 15);
			Login_panel.add(label4);
			
			label5 = new JLabel("passwd：");
			label5.setBounds(213, 25, 60, 15);
			Login_panel.add(label5);
			
			textField_UserName = new JTextField();
			textField_UserName.setText("admin");
			textField_UserName.setBounds(99, 22, 83, 21);
			Login_panel.add(textField_UserName);
			textField_UserName.setColumns(10);
			
			passwordField = new JPasswordField();
			passwordField.setText("12345");
			passwordField.setBounds(275, 22, 83, 21);
			Login_panel.add(passwordField);
	
			JPanel DeviceInfo_panel = new JPanel();
			DeviceInfo_panel.setLayout(null);
			DeviceInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
			DeviceInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "device info",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
			DeviceInfo_panel.setBounds(10, 100, 754, 158);
			getContentPane().add(DeviceInfo_panel);
			
			//设置滚动条，将表格加入到滚动条中
			JScrollPane DeviceInfo_scrollPane = new JScrollPane();
			DeviceInfo_scrollPane.setBounds(10, 27, 569, 121);
			DeviceInfo_panel.add(DeviceInfo_scrollPane);
			
			DeviceInfo_table = new JTable();
			DeviceInfo_table.addMouseListener(new MouseAdapter() {
				@Override
				public void mouseClicked(MouseEvent e) {
					GetIndex(e);
				}
			});
			DeviceInfo_table.setModel(this.initialTableModel(LanEnvironment));
			DeviceInfo_table.getColumnModel().getColumn(0).setPreferredWidth(20);
			DeviceInfo_table.getColumnModel().getColumn(1).setPreferredWidth(30);
			DeviceInfo_table.getColumnModel().getColumn(2).setPreferredWidth(30);
			DeviceInfo_table.getColumnModel().getColumn(3).setPreferredWidth(50);
			DeviceInfo_table.getColumnModel().getColumn(4).setPreferredWidth(180);
			DeviceInfo_scrollPane.setViewportView(DeviceInfo_table);

			
			btnTraverse = new JButton("search");
			btnTraverse.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					TraverseDevice(e);
				}
			});
			btnTraverse.setBounds(617, 45, 93, 23);
			DeviceInfo_panel.add(btnTraverse);
			
			btnLoginDevice = new JButton("login");
			btnLoginDevice.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					LoginDevice(e);
				}
			});
			btnLoginDevice.setBounds(617, 80, 93, 23);
			DeviceInfo_panel.add(btnLoginDevice);
			
			btnLogoutDevice = new JButton("logout");
			btnLogoutDevice.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					LogoutDevice(e);
				}
			});
			btnLogoutDevice.setBounds(617, 113, 93, 23);
			DeviceInfo_panel.add(btnLogoutDevice);
			

			Tab_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "Interface",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
			Tab_panel.setBounds(10, 262, 754, 158);
			getContentPane().add(Tab_panel);
			
			
			Tab_panel.add(Tab);
			 p1 = new JPanel();
			 p2 = new JPanel();
				
			 
			Tab.add(p1, "device interface");
			p1.setLayout(null);
			btnActivateCard = new JButton("activate");
			btnActivateCard.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					ActivateCard(e);
				}
			});
			btnActivateCard.setBounds(10, 10, 85, 23);
			p1.add(btnActivateCard);
			
			Tab.add(p2, "card interface");
			p2.setLayout(null);
			btnCertificateConfig = new JButton("config ID card");
			btnCertificateConfig.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					CertificateConfig(e);
				}
			});
			btnCertificateConfig.setBounds(20, 10, 128, 23);
			p2.add(btnCertificateConfig);
			
	
			Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "information",
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
			return ;
		}
		
		VerInfo_panel = new JPanel();
		VerInfo_panel.setLayout(null);
		VerInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		VerInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "版本信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		VerInfo_panel.setBounds(10, 10, 359, 80);
		getContentPane().add(VerInfo_panel);
		
		label = new JLabel("构建：");
		label.setBounds(10, 25, 46, 15);
		VerInfo_panel.add(label);
		
		JLabel label1 = new JLabel("2018.11.12");
		label1.setBounds(106, 25, 76, 15);
		VerInfo_panel.add(label1);
		
		label2 = new JLabel("SDK版本：");
		label2.setBounds(10, 50, 69, 15);
		VerInfo_panel.add(label2);
		
		JLabel label3 = new JLabel("HCUsbSDK");
		label3.setBounds(106, 50, 64, 15);
		VerInfo_panel.add(label3);
		
		label7 = new JLabel("");
		label7.setBounds(189, 50, 54, 15);
		VerInfo_panel.add(label7);
		
		
		Login_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "登录信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		Login_panel.setBounds(379, 10, 385, 80);
		getContentPane().add(Login_panel);
		
		label4 = new JLabel("用户名：");
		label4.setBounds(10, 25, 54, 15);
		Login_panel.add(label4);
		
		label5 = new JLabel("密码：");
		label5.setBounds(213, 25, 60, 15);
		Login_panel.add(label5);
		

		
		textField_UserName = new JTextField();
		textField_UserName.setText("admin");
		textField_UserName.setBounds(99, 22, 83, 21);
		Login_panel.add(textField_UserName);
		textField_UserName.setColumns(10);
		
		passwordField = new JPasswordField();
		passwordField.setText("12345");
		passwordField.setBounds(275, 22, 83, 21);
		Login_panel.add(passwordField);
		
		
	
		JPanel DeviceInfo_panel = new JPanel();
		DeviceInfo_panel.setLayout(null);
		DeviceInfo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		DeviceInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "设备信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		DeviceInfo_panel.setBounds(10, 100, 754, 158);
		getContentPane().add(DeviceInfo_panel);
		
		//设置滚动条，将表格加入到滚动条中
		JScrollPane DeviceInfo_scrollPane = new JScrollPane();
		DeviceInfo_scrollPane.setBounds(10, 27, 569, 121);
		DeviceInfo_panel.add(DeviceInfo_scrollPane);
		
		DeviceInfo_table = new JTable();
		DeviceInfo_table.addMouseListener(new MouseAdapter() {
			@Override
			public void mouseClicked(MouseEvent e) {
				GetIndex(e);
			}
		});
		DeviceInfo_table.setModel(this.initialTableModel(LanEnvironment));
		DeviceInfo_table.getColumnModel().getColumn(0).setPreferredWidth(20);
		DeviceInfo_table.getColumnModel().getColumn(1).setPreferredWidth(30);
		DeviceInfo_table.getColumnModel().getColumn(2).setPreferredWidth(30);
		DeviceInfo_table.getColumnModel().getColumn(3).setPreferredWidth(50);
		DeviceInfo_table.getColumnModel().getColumn(4).setPreferredWidth(180);
		DeviceInfo_scrollPane.setViewportView(DeviceInfo_table);
		
		btnTraverse = new JButton("遍历设备");
		btnTraverse.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				TraverseDevice(e);
			}
		});
		btnTraverse.setBounds(617, 45, 93, 23);
		DeviceInfo_panel.add(btnTraverse);
		
		btnLoginDevice = new JButton("登录设备");
		btnLoginDevice.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LoginDevice(e);
			}
		});
		btnLoginDevice.setBounds(617, 80, 93, 23);
		DeviceInfo_panel.add(btnLoginDevice);
		
		btnLogoutDevice = new JButton("注销设备");
		btnLogoutDevice.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				LogoutDevice(e);
			}
		});
		btnLogoutDevice.setBounds(617, 113, 93, 23);
		DeviceInfo_panel.add(btnLogoutDevice);
		

		Tab_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "接口",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		Tab_panel.setBounds(10, 262, 754, 158);
		getContentPane().add(Tab_panel);
		
		Tab_panel.add(Tab);
		 p1 = new JPanel();
		 p2 = new JPanel();
		
		Tab.add(p1, "设备接口");
		p1.setLayout(null);
		btnActivateCard = new JButton("激活卡");
		btnActivateCard.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				ActivateCard(e);
			}
		});
		btnActivateCard.setBounds(10, 10, 85, 23);
		p1.add(btnActivateCard);
		
		Tab.add(p2, "身份证信息接口");
		p2.setLayout(null);
		btnCertificateConfig = new JButton("身份证信息配置");
		btnCertificateConfig.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				CertificateConfig(e);
			}
		});
		btnCertificateConfig.setBounds(20, 10, 128, 23);
		p2.add(btnCertificateConfig);
		
		Info_panel = new JPanel();
		Info_panel.setLayout(null);
		Info_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "信息",
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
		return ;
	}
	
	/***********
	 显示SDK版本号
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
		WriteLog(HCUsbSDK.INF_LEVEL, "Get SDK Version" + Sversion);  //写日志
	}
	
	/*****************
	 初始化JTable
	 **************************/
    public DefaultTableModel initialTableModel(String LanEnviron)
    {
    	String tabeTile[];
    	if(LanEnviron.contains("en"))
    	{
    	   	tabeTile = new String[]{"Index", "VID", "PID", "Manufacturer", "Device name", "device serial no"};
    	    deviceTableModel = new DefaultTableModel(tabeTile, 0);
            return deviceTableModel;
    	}
        tabeTile = new String[]{"Index", "VID", "PID", "制造商", "设备名称", "设备序列号"};
        deviceTableModel = new DefaultTableModel(tabeTile, 0);
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
     获得 (DefaultTableModel)JTable.getModel()
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
      按键响应函数--遍历设备
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
    	m_aHidDevInfo = new HCUsbSDK.USB_DEVICE_INFO[HCUsbSDK.MAX_USB_DEV_LEN];  //数组用来存放设备
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
    	m_lUserID = new int[dwCount];
    	//根据获取到的设备数量，申请对应大小的设备信息结构体数组
    	HCUsbSDK.USB_DEVICE_INFO struDeviceInfo = new HCUsbSDK.USB_DEVICE_INFO();
    	HCUsbSDK.USB_DEVICE_INFO [] struDeviceInfoArr = new HCUsbSDK.USB_DEVICE_INFO[dwCount];
    	//对结构体数组中的每个成员进行初始化
    	for(int i = 0; i < dwCount; i++)
    	{
    		struDeviceInfoArr[i] = new HCUsbSDK.USB_DEVICE_INFO();
    	}
    	int size = struDeviceInfo.size();
    	HCUsbSDK.OUT_USB_DEVICE_INFO  struOutDevice = new HCUsbSDK.OUT_USB_DEVICE_INFO();
    	struOutDevice.init(dwCount);
    	//Pointer pStruDeviceInfo = AllocMemory(size * dwCount);	
    	Pointer pStruDeviceInfo = struOutDevice.getPointer();
    	if(hcUsbSDK.USB_EnumDevices(dwCount, pStruDeviceInfo))
    	{
    		struOutDevice.read();
    		while((--dwCount) >= 0)
    		{
    			String s1, s2, s3, s4, s5, s6;
        		s1 = String.valueOf(g_nEnumDevIndex);
        		s2 = String.valueOf(struOutDevice.struDeviceArr[g_nEnumDevIndex].dwVID);
        		s3 = String.valueOf(struOutDevice.struDeviceArr[g_nEnumDevIndex].dwPID);
        		s4 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szManufacturer);
        		s5 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szDeviceName);
        		s6 = new String(struOutDevice.struDeviceArr[g_nEnumDevIndex].szSerialNumber);
        		String[] log = {s1, s2, s3, s4.trim(), s5.trim(), s6.trim()};  	//.trim()去掉String右侧的空格
        		AcsDemo_USB.getTableModel().addRow(log);  						//将数据写到表中
        		m_aHidDevInfo[g_nEnumDevIndex] = struOutDevice.struDeviceArr[g_nEnumDevIndex];  			//存储到数组中方便登录获取数据，数组从0开始
        		m_lUserID[g_nEnumDevIndex] = -1;
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
     获取当前鼠标点击的JTable行号
     ************************/
    public void GetIndex(MouseEvent e)
    {
    	int index = DeviceInfo_table.getSelectedRow();  //当前选中的行号，是从0开始，而不是1
    	SelectedIndex = index;
    	btnLoginDevice.setEnabled(true);
		btnLogoutDevice.setEnabled(true);
    }
    
    public static int GetSelectUserID()
    {
    	if(SelectedIndex < 0)
    	{
    		return -1;
    	}
    	return m_lUserID[SelectedIndex];
    }
    
    /***********************
    	根据界面选择的语言，更换界面的语言信息
    ************************/
   public void ChangeLanguage(int index)
   {
	 String tabeTile[] = null;
	 //表明选择了中文
   	 if(index == 0)
   	 {
   		VerInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "版本信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		label.setText("构建:");
   		label2.setText("SDK 版本:");
   		Login_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "登录信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		label4.setText("用户名: ");
   		label5.setText("密码: ");

   		DeviceInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "设备信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		btnTraverse.setText("遍历设备");
   		btnLoginDevice.setText("登录设备");
   		btnLogoutDevice.setText("注销设备");
   		btnActivateCard.setText("激活卡");
   		btnCertificateConfig.setText("身份证信息配置");
   		Tab_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "接口",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		Tab.add(p1, "设备接口");
   		Tab.add(p2, "身份证信息接口");
   		Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		//更新设备信息表头的内容
   		tabeTile =  new String[]{"Index", "VID", "PID", "制造商", "设备名称", "设备序列号"};
   	 }
   	 if(index == 1)
   	 {
   		VerInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "version info",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		label.setText("build:");
   		label2.setText("SDK version:");
   		label2.setBounds(10, 50, 85, 15);
		
   		Login_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "login info",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		label4.setText("name: ");
   		label5.setText("passwd: ");
   		label5.setBounds(213, 25, 60, 15);
   		DeviceInfo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "device info",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		btnTraverse.setText("search");
   		btnLoginDevice.setText("login");
   		btnLogoutDevice.setText("logout");
   		btnActivateCard.setText("activate");
   		btnCertificateConfig.setText("config ID card");
   		Tab_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "interface",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		Tab.add(p1, "device interface");
   		Tab.add(p2, "card interface");
   		Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "information",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
   		//更新设备信息表头的内容
   		tabeTile = new String[]{"Index", "VID", "PID", "Manufacturer", "Dev name", "device serial no"};
   	 }
   	 
   	 //表单中数据不能丢失
	  Object[] RowData = new Object[6];
	  int RowCount = deviceTableModel.getRowCount();
	  if(RowCount >= 1)
	  {
		 for(int i = 0; i < deviceTableModel.getColumnCount(); i++)
	   	 {
	   		RowData[i] = deviceTableModel.getValueAt(0, i);
	   	 }
		 deviceTableModel = new DefaultTableModel(tabeTile, deviceTableModel.getRowCount()-1);
		 deviceTableModel.insertRow(0, RowData);	
	   }else
	   {
		 deviceTableModel = new DefaultTableModel(tabeTile, 0);
	   }
   	   DeviceInfo_table.setModel(deviceTableModel);
   	   DeviceInfo_table.getColumnModel().getColumn(0).setPreferredWidth(20);
	   DeviceInfo_table.getColumnModel().getColumn(1).setPreferredWidth(30);
	   DeviceInfo_table.getColumnModel().getColumn(2).setPreferredWidth(30);
       DeviceInfo_table.getColumnModel().getColumn(3).setPreferredWidth(50);
	   DeviceInfo_table.getColumnModel().getColumn(4).setPreferredWidth(180);
	   DeviceInfo_scrollPane.setViewportView(DeviceInfo_table);
   }
    
    
    /***********************
     	按键响应事件--登录设备
     *************************/
    public void LoginDevice(ActionEvent arg0)
    {
    	if(m_lUserID[SelectedIndex] != -1)
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_Login, under logined, please don't relogin");
    		return;
    	}
    	if(textField_UserName.getText().length() > 32)
    	{
    		//messagebox();
    		return;
    	}
    	if(passwordField.getText().length() > 16)
    	{
    		//messagebox();
    		return;
    	}
    	StruCurUsbLoginInfo.dwSize = StruCurUsbLoginInfo.size();
    	StruCurUsbLoginInfo.dwTimeout = 5000;  //登录超时时间5秒
    	StruCurUsbLoginInfo.dwVID = m_aHidDevInfo[SelectedIndex].dwVID;
    	StruCurUsbLoginInfo.dwPID = m_aHidDevInfo[SelectedIndex].dwPID;
    	StruCurUsbLoginInfo.szSerialNumber = m_aHidDevInfo[SelectedIndex].szSerialNumber;
    	StruCurUsbLoginInfo.szUserName = textField_UserName.getText().getBytes();
    	StruCurUsbLoginInfo.szPassword = passwordField.getText().getBytes();	
    	StruDeviceRegRes.dwSize = StruDeviceRegRes.size();
    	//修改返回值类型
    	int userID = hcUsbSDK.USB_Login(StruCurUsbLoginInfo, StruDeviceRegRes);
    	if(userID == -1)
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_Login");
    	}
    	else
    	{
    		m_lUserID[SelectedIndex] = userID;
    		String src = new String(StruCurUsbLoginInfo.szSerialNumber);
    		String SuccesfulLoginInfo = "SUCCESS USB_SDK_Login:" + src;
    		WriteLog(HCUsbSDK.INF_LEVEL, SuccesfulLoginInfo);
    	}
    }
    
    /*************************
     	注销设备
     **************************/
    public void LogoutDevice(ActionEvent e)
    {
    	if(hcUsbSDK.USB_Logout(m_lUserID[SelectedIndex]))
    	{
    		m_lUserID[SelectedIndex] = -1;
    		WriteLog(HCUsbSDK.INF_LEVEL, "SUCCESS USB_SDK_Logout()");
    	}
    	else
    	{
    		WriteLog(HCUsbSDK.ERR_LEVEL, "FAILED USB_SDK_Logout()");
		}
    }
    
    /***************************
     * 激活卡
     *****************************/
    public void ActivateCard(ActionEvent e)
    {
    	DlgActivateCard dlg = new DlgActivateCard(LanEnvironment);
    	dlg.setLocation(AcsDemo_USB.this.getX() + AcsDemo_USB.this.getWidth()/4, 
    			AcsDemo_USB.this.getY() + AcsDemo_USB.this.getHeight()/4);
    	dlg.setModal(true);
    	dlg.setVisible(true);
    	dlg.dispose();
    }
    
    /****************************
     * 身份证信息配置
     *************************/
    public void CertificateConfig(ActionEvent e)
    {
    	DlgCertificateConfig dlg = new DlgCertificateConfig(LanEnvironment);
    	dlg.setLocation(AcsDemo_USB.this.getX() + AcsDemo_USB.this.getWidth()/4, 
    			AcsDemo_USB.this.getY() + AcsDemo_USB.this.getHeight()/4);
    	dlg.setModal(true);
    	dlg.setVisible(true);
    	dlg.dispose();
    }
    
    /******************************
    在最下方信息表中写日志
    *********************/
    public static void WriteLog(int Level, String Content)
    {
    	String s1, s2, s3, s4;
    	s1 = String.valueOf(IndexOfInfo);
    	SimpleDateFormat df = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss");//设置日期格式
    	s2 = df.format(new Date());
    	s3 = ReturnLevel(Level);
    	s4 = Content;
    	String[] log = {s1, s2, s3, s4};
		AcsDemo_USB.getTableModel2().addRow(log);  //将数据写到表中
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
