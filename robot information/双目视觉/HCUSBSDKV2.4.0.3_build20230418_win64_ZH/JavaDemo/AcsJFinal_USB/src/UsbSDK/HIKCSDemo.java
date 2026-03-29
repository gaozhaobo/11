package UsbSDK;

import com.sun.jna.Pointer;

public class HIKCSDemo {
	
	static HCUsbSDK hCUsbSDK = HCUsbSDK.INSTANCE;
	static int iHandle = -1;
	
	
	
	public static void main(String[] args) throws InterruptedException{
		HIKCSDemo csdemo = new HIKCSDemo();		
		hCUsbSDK.USB_Init();
		hCUsbSDK.USB_SetLogToFile(3, ".\\", false);
		System.out.println(System.getProperty("user.dir"));
		csdemo.getVersion(); //获取版本
		
		csdemo.EnumDevices();	//枚举设备
		csdemo.Login();
		csdemo.ActivateCard();
		
		
		while(true);
		
	}
	
	
	public void getVersion(){
		int iVersion = hCUsbSDK.USB_GetSDKVersion();
		
		String v1 = Integer.toString((iVersion>>24) & 0xff);
		String v2 = Integer.toString((iVersion>>16) & 0xff);
		String v3 = Integer.toString((iVersion>>8) & 0xff);
		String v4 = Integer.toString((iVersion) & 0xff);		
		System.out.println("USB_GetSDKVersion succeed, version:" + v1 + "." + v2 + "." + v3 + "." + v4);		
	}
	
	public void EnumDevices(){
		int iNum = hCUsbSDK.USB_GetDeviceCount();
		System.out.println("iNum:" + iNum);
		if(iNum < 1){
			System.out.println("无设备接入");
			return ;
		}
		
		//根据获取到的设备数量，申请对应大小的设备信息结构体数组
    	//对结构体数组中的每个成员进行初始化
    	HCUsbSDK.OUT_USB_DEVICE_INFO  struOutDevice = new HCUsbSDK.OUT_USB_DEVICE_INFO();
    	struOutDevice.init(iNum);
    	struOutDevice.write();

    	Pointer pStruDeviceInfo = struOutDevice.getPointer();
    	if(hCUsbSDK.USB_EnumDevices(iNum, pStruDeviceInfo))
    	{
    		struOutDevice.read();
    		while((--iNum) >= 0)
    		{
    			String s1, s2, s3, s4, s5, s6;
        		s1 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwIndex);
        		s2 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwVID);
        		s3 = String.valueOf(struOutDevice.struDeviceArr[iNum].dwPID);
        		s4 = new String(struOutDevice.struDeviceArr[iNum].szManufacturer).trim();
        		s5 = new String(struOutDevice.struDeviceArr[iNum].szDeviceName).trim();
        		s6 = new String(struOutDevice.struDeviceArr[iNum].szSerialNumber).trim();
        		System.out.println("device:" + s1 + ",dwVID:" +s2 + ",dwPID:" + s3 + ",szManufacturer:" + s4 + ",szDeviceName:" +s5 + ",szSerialNumber:" + s6);
    		}
    		System.out.println("USB_EnumDevices succeed");
    	}
    	else
    	{
    		System.out.println("USB_EnumDevices failed, error:" + hCUsbSDK.USB_GetLastError());
		}
	}
	
	public void Login(){
		HCUsbSDK.USB_DEVICE_REG_RES struDeviceReg = new HCUsbSDK.USB_DEVICE_REG_RES();
		struDeviceReg.dwSize = struDeviceReg.size();
		struDeviceReg.write();
		
		HCUsbSDK.USB_USER_LOGIN_INFO struUserLoginInfo = new HCUsbSDK.USB_USER_LOGIN_INFO();
		struUserLoginInfo.dwSize = struUserLoginInfo.size();
		struUserLoginInfo.dwTimeout = 5000;
		struUserLoginInfo.dwDevIndex = 1; 
		struUserLoginInfo.dwVID = 1155;
		struUserLoginInfo.dwPID = 22352;	
		System.arraycopy("813717552".getBytes(), 0, struUserLoginInfo.szSerialNumber, 0, "813717552".length());
		System.arraycopy("admin".getBytes(), 0, struUserLoginInfo.szUserName, 0, "admin".length());
		System.arraycopy("12345".getBytes(), 0, struUserLoginInfo.szPassword, 0, "12345".length());
		
		struUserLoginInfo.write();
		
		iHandle = hCUsbSDK.USB_Login(struUserLoginInfo, struDeviceReg);
		System.out.println("iHandle:" + iHandle);
		if(iHandle < 0){
			System.out.println("USB_Login failed, error:" + hCUsbSDK.USB_GetLastError());
		}
		else{
			System.out.println("USB_Login succeed, lHandle:" + iHandle);
		}
	}
	
	
	public void ActivateCard(){
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
		
		if(!hCUsbSDK.USB_GetDeviceConfig(iHandle, HCUsbSDK.USB_GET_ACTIVATE_CARD, StruInput, StruOutput))
		{
			System.out.println("USB_GET_ACTIVATE_CARD failed, error:" + hCUsbSDK.USB_GetLastError());
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
			
		}
		
	}
	
//class 结束	
}
