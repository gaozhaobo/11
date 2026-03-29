package mainWorkSpace;


import com.jfinal.core.Controller;
import com.sun.jna.Pointer;
import java.nio.charset.StandardCharsets;
import java.util.Base64;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.File;

import UsbSDK.HCUsbSDK;
import UsbSDK.Dewlt;

public class Login   extends Controller{
	
	private static HCUsbSDK m_hCUsbSDK = HCUsbSDK.INSTANCE;
	private static int m_iHandle = -1;
	
	//成员变量，方便成员函数使用
	private HCUsbSDK.USB_CERTIFICATE_INFO m_stuCertificate = new HCUsbSDK.USB_CERTIFICATE_INFO();
	//解析人脸的句柄信息
	private static Dewlt m_dewltInstance = null;

	public void index() {
		render("/UI-Resource/Login/Login.html");	//WEB页面展示
		//之前有没有登出的先登出
		if(m_iHandle != -1)
		{
			System.out.println("USB_Logout handle=:" + m_iHandle);
			if(!m_hCUsbSDK.USB_Logout(m_iHandle))
			{
				System.out.println("USB_Logout failed, error:" + m_hCUsbSDK.USB_GetLastError());
			}
			m_iHandle = -1;
		}
		
		m_hCUsbSDK.USB_Init();	//初始化USB SDK
		m_hCUsbSDK.USB_SetLogToFile(3, ".\\", false);		//USB SDK写日志
		SDKgetVersion();		//获取USB版本
		m_dewltInstance = DewltInstance.getInstance();
	}
	
	
	public void SDKgetVersion(){
		int iVersion = m_hCUsbSDK.USB_GetSDKVersion();		
		String v1 = Integer.toString((iVersion>>24) & 0xff);
		String v2 = Integer.toString((iVersion>>16) & 0xff);
		String v3 = Integer.toString((iVersion>>8) & 0xff);
		String v4 = Integer.toString((iVersion) & 0xff);		
		System.out.println("USB_GetSDKVersion succeed, version:" + v1 + "." + v2 + "." + v3 + "." + v4);	
	}
	
	
	//页面登录按钮响应函数
	public void userCheck()
	{
		System.out.println("in userCheck");
		
		int dwVID = getParaToInt("dwVID");
		int dwPID = getParaToInt("dwPID");
		String szSerialNumber = getPara("szSerialNumber");
		String szUserName = getPara("szUserName");
	    String password = getPara("password");
	    
	    HCUsbSDK.USB_DEVICE_REG_RES struDeviceReg = new HCUsbSDK.USB_DEVICE_REG_RES();
		struDeviceReg.dwSize = struDeviceReg.size();
		struDeviceReg.write();
		
		HCUsbSDK.USB_USER_LOGIN_INFO struUserLoginInfo = new HCUsbSDK.USB_USER_LOGIN_INFO();
		struUserLoginInfo.dwSize = struUserLoginInfo.size();
		struUserLoginInfo.dwTimeout = 5000;
	//	struUserLoginInfo.dwDevIndex = 1; 
		struUserLoginInfo.dwVID = dwVID;
		struUserLoginInfo.dwPID = dwPID;	
		System.arraycopy(szSerialNumber.getBytes(), 0, struUserLoginInfo.szSerialNumber, 0, szSerialNumber.length());
		System.arraycopy(szUserName.getBytes(), 0, struUserLoginInfo.szUserName, 0, szUserName.length());
		System.arraycopy(password.getBytes(), 0, struUserLoginInfo.szPassword, 0, password.length());
		
		struUserLoginInfo.write();
		if(m_iHandle != -1)
		{
			System.out.println("USB_Logout handle=:" + m_iHandle);
			if(!m_hCUsbSDK.USB_Logout(m_iHandle))
			{
				System.out.println("USB_Logout failed, error:" + m_hCUsbSDK.USB_GetLastError());
			}
		}
		
		m_iHandle = m_hCUsbSDK.USB_Login(struUserLoginInfo, struDeviceReg);
		System.out.println("iHandle:" + m_iHandle);
		if(m_iHandle < 0){
			setAttr("loginResult",0);
			System.out.println("USB_Login failed, error:" + m_hCUsbSDK.USB_GetLastError());
		}
		else{
			setAttr("loginResult",1);
			System.out.println("USB_Login succeed, lHandle:" + m_iHandle);
		}
	    
		this.renderJson();		    	     
	}
	
	//页面枚举设备响应函数
	public void enumDevice(){
		
		System.out.println(System.getProperty("user.dir"));
		//TODO不退出库会奔溃，暂时先让设备登出规避一下，后续再修改回来
		if(m_iHandle != -1)
		{
			System.out.println("USB_Logout handle=:" + m_iHandle);
			if(!m_hCUsbSDK.USB_Logout(m_iHandle))
			{
				System.out.println("USB_Logout failed, error:" + m_hCUsbSDK.USB_GetLastError());
			}
			m_iHandle = -1;
		}
		
		int iNum = m_hCUsbSDK.USB_GetDeviceCount();
		System.out.println("iNum:" + iNum);
		if(iNum < 1){
			System.out.println("无设备接入");
			setAttr("enumResult",0); //通知前端无设备接入
			
			this.renderJson();
			return ;
		}
		
		//根据获取到的设备数量，申请对应大小的设备信息结构体数组
    	//对结构体数组中的每个成员进行初始化
    	HCUsbSDK.OUT_USB_DEVICE_INFO  struOutDevice = new HCUsbSDK.OUT_USB_DEVICE_INFO();
    	struOutDevice.init(iNum);
    	struOutDevice.write();   
    	Pointer pStruDeviceInfo = struOutDevice.getPointer();
    	if(m_hCUsbSDK.USB_EnumDevices(iNum, pStruDeviceInfo))
    	{
    		struOutDevice.read();
    		String strDevice = "";
    		while((--iNum) >= 0)
    		{
    			String s1, s2, s3, s4, s5, s6;
        		s1 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwIndex);
        		s2 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwVID);
        		s3 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwPID);
        		s4 = new String(struOutDevice.struDeviceArr[iNum].szManufacturer).trim();
        		s5 = new String(struOutDevice.struDeviceArr[iNum].szDeviceName).trim();
        		s6 = new String(struOutDevice.struDeviceArr[iNum].szSerialNumber).trim();
        		strDevice = strDevice + "device:" + s1 + ",dwVID:" +s2 + ",dwPID:" + s3 + ",szManufacturer:" + s4 + ",szDeviceName:" +s5 + ",szSerialNumber:" + s6 + "\n";
        		System.out.println(strDevice);        		
        		
    		}
    		System.out.println("USB_EnumDevices succeed");
    		setAttr("enumResult",1); //枚举成功
    		setAttr("deviceInfo",strDevice); //返回设备信息
    	}
    	else
    	{
    		System.out.println("USB_EnumDevices failed, error:" + m_hCUsbSDK.USB_GetLastError());
    		setAttr("enumResult",2);	//枚举失败
		}
		
				
		this.renderJson();		
	}

	public void activateCard(){
		HCUsbSDK.USB_WAIT_SECOND StruWaitSecond = new HCUsbSDK.USB_WAIT_SECOND();
		StruWaitSecond.dwSize = StruWaitSecond.size();
		StruWaitSecond.byWait = 5;
		
		HCUsbSDK.USB_ACTIVATE_CARD_RES StruActivateRes = new HCUsbSDK.USB_ACTIVATE_CARD_RES();
		StruActivateRes.dwSize = StruActivateRes.size();
		
		HCUsbSDK.USB_CONFIG_INPUT_INFO StruInput = new HCUsbSDK.USB_CONFIG_INPUT_INFO();
		StruInput.dwInBufferSize = StruWaitSecond.size();
		Pointer ptrwaitSecond = StruWaitSecond.getPointer();
		StruWaitSecond.write();
		StruInput.lpInBuffer = ptrwaitSecond;
		
		HCUsbSDK.USB_CONFIG_OUTPUT_INFO StruOutput = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
		StruOutput.dwOutBufferSize = StruActivateRes.size();
		Pointer ptrActivateRes = StruActivateRes.getPointer();
		StruActivateRes.write();
		StruOutput.lpOutBuffer = ptrActivateRes;
		
		if(!m_hCUsbSDK.USB_GetDeviceConfig(m_iHandle, HCUsbSDK.USB_GET_ACTIVATE_CARD, StruInput, StruOutput))
		{
			System.out.println("USB_GET_ACTIVATE_CARD failed, error:" + m_hCUsbSDK.USB_GetLastError());
			setAttr("activeResult",0); //激活卡失败
		}
		else{
			StruActivateRes.read();
			System.out.println("byCardType:" + StruActivateRes.byCardType + ",bySerialLen:" + StruActivateRes.bySerialLen);
			
			System.out.println("USB_GET_ACTIVATE_CARD succeed");	
			
			String SerialNumber = "";
			//返回的bySerial数组需要反序之后，将十六进制转换成十进制就是卡号
			for(int i = 0; i < StruActivateRes.bySerialLen; i++)
			{
				String hex = Integer.toHexString(StruActivateRes.bySerial[StruActivateRes.bySerialLen-i-1] & 0xff); 
				if(hex.length() == 1)
				{
					hex += '0';
				}
				SerialNumber += hex.toUpperCase();
			}
			System.out.println("SerialNumber:0x" + SerialNumber);
			System.out.println("cardNo:" + Long.parseLong(SerialNumber,  16));
			
			setAttr("activeResult",1); //激活卡成功
			setAttr("cardInfo",Long.parseLong(SerialNumber, 16)); //传递卡号
		}
		
		this.renderJson();
		
	}

	//获取身份证信息
	public void getCertificateInfo(){
		
		File file = new File(".\\tmpIDPhoto_$_$.bmp");
		file.delete();
		
		if( -1 == m_iHandle)
		{
			System.out.println("Please login device first!");
			setAttr("getCertificateInfoResult",2);
			this.renderJson();
			return;
		}
		
		HCUsbSDK.USB_CERTIFICATE_INFO struCertificateInfo = new HCUsbSDK.USB_CERTIFICATE_INFO();
		struCertificateInfo.dwSize = struCertificateInfo.size();
		
		HCUsbSDK.USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = new HCUsbSDK.USB_CONFIG_OUTPUT_INFO();
		struConfigOutputInfo.dwOutBufferSize = struCertificateInfo.dwSize;
		Pointer ptrstruCertificateInfo = struCertificateInfo.getPointer();
		struCertificateInfo.write();
		struConfigOutputInfo.lpOutBuffer = ptrstruCertificateInfo;
		
		if(!m_hCUsbSDK.USB_GetDeviceConfig(m_iHandle, HCUsbSDK.USB_GET_CERTIFICATE_INFO, null, struConfigOutputInfo))
		{
			System.out.println("USB_GetDeviceConfig failed, iHandle:" + m_iHandle + " error:" + m_hCUsbSDK.USB_GetLastError());
			setAttr("getCertificateInfoResult",0);
		}
		else
		{
			//读取身份证成功,身份证信息以字符串形式返回到前端
			setAttr("getCertificateInfoResult",1);
	    	struCertificateInfo.read();
	    	m_stuCertificate = struCertificateInfo;
	    	String strCertificateInfo = "姓名:" + getname() + " 性别:" + getSex() + " 名族:" + getNationality()
	    		+ " 出生日期:" + getBirthDate() + " 家庭住址:" + getHomeAddress()
	    		+ " 证件号码:" + getIdNumber() + " 签发机关:" + getIdIssued();
	    	setAttr("certificateInfo",strCertificateInfo);
			System.out.println("getCertificateInfo success:" + strCertificateInfo);
			
			String strPictureData = getPicture();
			if ("" == strPictureData)
			{
				System.out.println("pictureData data:" + strPictureData);
				setAttr("getCertificateInfoResult",0);
			}
			else
			{
				System.out.println("getPicture success, iHandle:" + m_iHandle);
				setAttr("pictureData",strPictureData);
			}
		}
		this.renderJson();
	}
	
	private String getname()
	{
		byte[] name = new byte[30];
    	System.arraycopy(m_stuCertificate.byWordInfo, 0, name, 0, 30);
    	String strName = new String(name, StandardCharsets.UTF_16LE);
    	return strName.trim();
	}

	private String getSex()
	{
		byte[] sex = new byte[2];
    	System.arraycopy(m_stuCertificate.byWordInfo, 30, sex, 0, 2);
    	String strSex = new String(sex, StandardCharsets.UTF_16LE);
    	if(strSex.equals("1"))
    	{
    		strSex = "男";
    	}
    	else
    	{
    		strSex = "女";
    	}
    	return strSex.trim();
	}
	
	private String getNationality()
	{
		byte[] nationality = new byte[4];
    	System.arraycopy(m_stuCertificate.byWordInfo, 32, nationality, 0, 4);
    	String strNationality = new String(nationality, StandardCharsets.UTF_16LE);
    	strNationality = new Nationality().GetNationality(strNationality);
    	return strNationality.trim();
	}
	
	private String getBirthDate()
	{
    	byte[] birthDate = new byte[16];
    	System.arraycopy(m_stuCertificate.byWordInfo, 36, birthDate, 0, 16);
    	String strBirthDate = new String(birthDate, StandardCharsets.UTF_16LE);
    	String yyyy = strBirthDate.substring(0, 4);
    	String mm = strBirthDate.substring(4, 6);
    	String dd = strBirthDate.substring(6, 8);
    	strBirthDate = yyyy + "-" + mm + "-" + dd;
    	return strBirthDate.trim();
	}
	
	private String getHomeAddress()
	{
		byte[] homeAddress = new byte[70];
    	System.arraycopy(m_stuCertificate.byWordInfo, 52, homeAddress, 0, 70);
    	String strHomeAddress = new String(homeAddress, StandardCharsets.UTF_16LE);
    	return strHomeAddress.trim();
	}
	
	private String getIdNumber()
	{
		byte[] idNumber = new byte[36];
    	System.arraycopy(m_stuCertificate.byWordInfo, 122, idNumber, 0, 36);
    	String strIdNumber = new String(idNumber, StandardCharsets.UTF_16LE);
    	return strIdNumber.trim();
	}
	
	private String getIdIssued()
	{
		byte[] idIssued = new byte[30];
    	System.arraycopy(m_stuCertificate.byWordInfo, 158, idIssued, 0, 30);
    	String strIdIssued = new String(idIssued, StandardCharsets.UTF_16LE);
    	return strIdIssued.trim();
	}
	
//	/*************
//	 * 加载图片
//	 */
	@SuppressWarnings("resource")
	private String getPicture()
	{
		
		String strPictureBin = ".\\tmpIDPhoto_$_$.bin";
		File file = new File(strPictureBin);
		try {
			FileOutputStream fos = new FileOutputStream(file);
			fos.write(m_stuCertificate.byPicInfo);
			fos.flush();
			fos.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
		
		//调用dewlt接口解密二进制图片，存成一个.bmp的文件.dewlt.dll是公安部的一个身份证照片解析接口
		if(m_dewltInstance == null)
		{
     		System.out.println("64Bit not support dewlt.dll");  
			return "";
		}
		int num = m_dewltInstance.dewlt(strPictureBin);
		if(num >= 0)
		{
			//读文件
	        try {
	            File f = new File(".\\tmpIDPhoto_$_$.bmp");
	            int length = (int) f.length();
	            byte[] data = new byte[length];
	            new FileInputStream(f).read(data);
	        	String strPictureDataBase64 = Base64.getEncoder().encodeToString(data);
	        	return strPictureDataBase64;        	
	        }
	        catch (Exception e) {
	            e.printStackTrace();
	            return "";
	        }
		}
		return ""; 
	}
}
