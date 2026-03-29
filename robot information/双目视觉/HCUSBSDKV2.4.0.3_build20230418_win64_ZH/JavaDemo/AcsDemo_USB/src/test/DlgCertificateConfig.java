package test;

import java.awt.Color;
import java.awt.Font;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.TitledBorder;
import javax.swing.table.DefaultTableModel;

import com.sun.jna.Pointer;
import com.sun.org.apache.bcel.internal.classfile.Field;
//import com.sun.prism.Image;

import javax.swing.JTable;
import javax.swing.UIManager;
import javax.swing.JScrollPane;
import javax.swing.JLabel;
import java.awt.event.ActionListener;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.UnsupportedEncodingException;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.awt.event.ActionEvent;

public class DlgCertificateConfig extends JDialog
{
	static HCUsbSDK hcUsbSDK = HCUsbSDK.INSTANCE;
	static Dewlt dewltInstance = null;
	public static JTable Info_table;
	public JLabel photo_label;
	public HCUsbSDK.USB_CERTIFICATE_INFO Certificate = new HCUsbSDK.USB_CERTIFICATE_INFO();
	
	public DlgCertificateConfig(String LanEnvironment) 
	{
		dewltInstance = DewltInstance.getInstance();
		setResizable(false);
		InitCompoent(LanEnvironment);
	}

	/*********************
	 * 初始化界面
	 */
	public void InitCompoent(String LanEnvironment)
	{
		JButton btnGet = null;
		setSize(698, 289);
		getContentPane().setLayout(null);
		
		JPanel Info_panel = new JPanel();
		Info_panel.setLayout(null);
		Info_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		Info_panel.setBounds(10, 10, 530, 234);
		getContentPane().add(Info_panel);
		
		JScrollPane Info_scrollPane = new JScrollPane();
		Info_scrollPane.setBounds(10, 20, 510, 200);
		Info_panel.add(Info_scrollPane);
		
		Info_table = new JTable();
		Info_table.setFont(new Font("宋体", Font.PLAIN, 14));
		Info_table.setModel(this.initialTableModel3(LanEnvironment));
		Info_table.getColumnModel().getColumn(0).setPreferredWidth(10);
		Info_table.getColumnModel().getColumn(1).setPreferredWidth(30);
		Info_table.getColumnModel().getColumn(2).setPreferredWidth(300);
		Info_scrollPane.setViewportView(Info_table);
		
		
		JPanel photo_panel = new JPanel();
		photo_panel.setLayout(null);
		photo_panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		
		
		photo_label = new JLabel("");
		photo_label.setBounds(10, 20, 117, 154);
		photo_panel.add(photo_label);

		if(LanEnvironment.contains("en"))
		{
			setTitle("obtain card info");
			
			Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "basic info",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));

		
			photo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "image",
					TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
			photo_panel.setBounds(550, 10, 131, 177);
			getContentPane().add(photo_panel);
			
			btnGet = new JButton("obtain");
			btnGet.addActionListener(new ActionListener() {
				public void actionPerformed(ActionEvent e) {
					btnGet(e);
				}
			});
			btnGet.setBounds(574, 205, 93, 23);
			getContentPane().add(btnGet);
			return ;
		}

		btnGet = new JButton("获取");
		btnGet.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnGet(e);
			}
		});
		btnGet.setBounds(574, 205, 93, 23);
		getContentPane().add(btnGet);
		
		
		setTitle("获取身份证信息");
		Info_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "基本信息",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		photo_panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "图片",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		photo_panel.setBounds(550, 10, 131, 177);
		getContentPane().add(photo_panel);
		btnGet = new JButton("获取");
		return ;
	}
	
	/**********************
	 * 初始化JTable表格
	 */
	public DefaultTableModel initialTableModel3(String LanEnvironment)
	{
		 String tabeTile[] = null;
		 if(LanEnvironment.contains("en"))
		 {
			 tabeTile = new String[]{"serial no", "head", "content"};
			 DefaultTableModel deviceTableModel = new DefaultTableModel(tabeTile, 0);
			 return deviceTableModel;
		 }
		 tabeTile = new String[]{"序号", "数据项名称", "信息"};
	     DefaultTableModel deviceTableModel = new DefaultTableModel(tabeTile, 0);
	     return deviceTableModel;
	}
	
	/*************
	 * 获得JTable句柄
	 */
	 public DefaultTableModel getTableModel3()
	 {
		 return ((DefaultTableModel)Info_table.getModel());
	 }
	
	 
	public String byteArrayToString(byte[] bytes) {
		if (null == bytes || bytes.length == 0) {
				return "";
		}
		int iLengthOfBytes = 0;
		for(byte st:bytes){
			if(st != 0){
				iLengthOfBytes++;
			}else
				break;
		}
		String strContent = "";
		try {
				strContent = new String(bytes, 0, iLengthOfBytes, "UTF-8");
		} catch (UnsupportedEncodingException e) {
				e.printStackTrace();
		}
		return strContent;
	} 
	 
	/**********************
	 * 获取
	 */
	public void btnGet(ActionEvent arg0)
	{
		HCUsbSDK.USB_CERTIFICATE_INFO struCertificateInfo = new HCUsbSDK.USB_CERTIFICATE_INFO();
		struCertificateInfo.dwSize = struCertificateInfo.size();
		
		HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
		struConfigOutputInfo.dwOutBufferSize = struCertificateInfo.dwSize;
		Pointer ptrstruCertificateInfo = struCertificateInfo.getPointer();
		struCertificateInfo.write();
		struConfigOutputInfo.lpOutBuffer = ptrstruCertificateInfo;
		
		if(hcUsbSDK.USB_GetDeviceConfig(AcsDemo_USB.GetSelectUserID(), HCUsbSDK.USB_GET_CERTIFICATE_INFO, null, struConfigOutputInfo))
		{
			AcsDemo_USB.WriteLog(HCUsbSDK.INF_LEVEL, "SUCCESS: USB_SDK_GetDeviceConfig() Command = USB_SDK_GET_CERTIFICATE_INFO");
			
			//先清空表格
			DefaultTableModel tableModel = (DefaultTableModel)Info_table.getModel();
	    	tableModel.setRowCount(0);  //先清空列表
	    	
	    	struCertificateInfo.read();
	    	Certificate = struCertificateInfo;
	    	
	    	getname();
	    	getSex();
	    	getNationality();
	    	getBirthDate();
	    	getHomeAddress();
	    	getIdNumber();
	    	getIdIssued();
	    	getPicture();
		}
		else
		{
			//增加错误信息处理
			int dwError = hcUsbSDK.USB_GetLastError();
			Pointer pErrorMsg = hcUsbSDK.USB_GetErrorMsg(dwError);
			byte[] byMsg = new byte[100];
			pErrorMsg.read(0, byMsg, 0, byMsg.length);
			String strMsg = byteArrayToString(byMsg);
			AcsDemo_USB.WriteLog(HCUsbSDK.INF_LEVEL, strMsg);
		}
	}

	private void getname()
	{
		byte[] name = new byte[30];
    	System.arraycopy(Certificate.byWordInfo, 0, name, 0, 30);
    	String strName = new String(name, StandardCharsets.UTF_16LE);
    	String[] Info = {"1", "姓名", strName.trim()};
		this.getTableModel3().addRow(Info);
	}

	private void getSex()
	{
		byte[] sex = new byte[2];
    	System.arraycopy(Certificate.byWordInfo, 30, sex, 0, 2);
    	String strSex = new String(sex, StandardCharsets.UTF_16LE);
    	if(strSex.equals("1"))
    	{
    		strSex = "男";
    	}
    	else
    	{
    		strSex = "女";
    	}
    	String[] Info = {"2", "性别", strSex.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	private void getNationality()
	{
		byte[] nationality = new byte[4];
    	System.arraycopy(Certificate.byWordInfo, 32, nationality, 0, 4);
    	String strNationality = new String(nationality, StandardCharsets.UTF_16LE);
    	strNationality = new Nationality().GetNationality(strNationality);
    	String[] Info = {"3", "民族", strNationality.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	private void getBirthDate()
	{
    	byte[] birthDate = new byte[16];
    	System.arraycopy(Certificate.byWordInfo, 36, birthDate, 0, 16);
    	String strBirthDate = new String(birthDate, StandardCharsets.UTF_16LE);
    	String yyyy = strBirthDate.substring(0, 4);
    	String mm = strBirthDate.substring(4, 6);
    	String dd = strBirthDate.substring(6, 8);
    	strBirthDate = yyyy + "-" + mm + "-" + dd;
    	String[] Info = {"4", "出生日期", strBirthDate.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	private void getHomeAddress()
	{
		byte[] homeAddress = new byte[70];
    	System.arraycopy(Certificate.byWordInfo, 52, homeAddress, 0, 70);
    	String strHomeAddress = new String(homeAddress, StandardCharsets.UTF_16LE);
    	String[] Info = {"5", "住址", strHomeAddress.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	private void getIdNumber()
	{
		byte[] idNumber = new byte[36];
    	System.arraycopy(Certificate.byWordInfo, 122, idNumber, 0, 36);
    	String strIdNumber = new String(idNumber, StandardCharsets.UTF_16LE);
    	String[] Info = {"6", "身份证号码", strIdNumber.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	private void getIdIssued()
	{
		byte[] idIssued = new byte[30];
    	System.arraycopy(Certificate.byWordInfo, 158, idIssued, 0, 30);
    	String strIdIssued = new String(idIssued, StandardCharsets.UTF_16LE);
		String[] Info = {"7", "签发机关", strIdIssued.trim()};
		this.getTableModel3().addRow(Info);
	}
	
	/*************
	 * 加载图片
	 */
	private void getPicture()
	{
		//先生成.bin文件，再调用接口将.bin转成.bmp文件
		String strExeDir = AcsDemo_USB.szLogPath;
		String strPictureBin = strExeDir + "\\tmpIDPhoto_$_$.bin";
		File file = new File(strPictureBin);
		try {
			FileOutputStream fos = new FileOutputStream(file);
			fos.write(Certificate.byPicInfo);
			fos.flush();
			fos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		if(dewltInstance == null)
		{
			String strMsg = "64bit not support to convert picture by dewlt.dll!!";
			AcsDemo_USB.WriteLog(HCUsbSDK.INF_LEVEL, strMsg);
			return;
		}
		int num = dewltInstance.dewlt(strPictureBin);  //调用该接口将.bin文件转换成.bmp文件
		if(num >= 0)
		{
			PicConver bmpTojpg = new PicConver();
			ImageIcon image = new ImageIcon(strExeDir + "\\tmpIDPhoto_$_$.jpg");
			photo_label.setIcon(image);
		}
	}
}
