package test;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.FlowLayout;
import java.awt.Font;

import javax.swing.JButton;
import javax.swing.JComponent;
import javax.swing.JDialog;
import javax.swing.JPanel;
import javax.swing.border.EmptyBorder;
import javax.swing.border.TitledBorder;

import org.omg.CORBA.PRIVATE_MEMBER;

import com.sun.jna.NativeLong;
import com.sun.jna.Pointer;

//import jdk.internal.dynalink.beans.StaticClass;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.UIManager;
import javax.swing.JTextPane;
import java.awt.event.ActionListener;
import java.awt.event.ActionEvent;

public class DialogActivateCard extends JDialog 
{
	static HCUsbSDK hcUsbSDK = HCUsbSDK.INSTANCE;
	private JTextField textField_WaitTime;
	private JTextField textField_CardProtocol;
	private JTextField textField_SerialLen;
	private JTextField textField_Serial;
	private JTextField textField_VerifyLen;
	private JTextField textField_SelVerify;
	private String aCardProto[] = new String[] {"0-TypeA M1卡", "1-TypeA CPU卡", "2-TypeB", "3-125KHz ID卡"};
	
	public DialogActivateCard() 
	{
		setResizable(false);
		InitCompoent();
	
	}
	
	/************
	 * 初始化界面
	 */
	public void InitCompoent()
	{
		setTitle("激活");
		setSize(520, 312);
		getContentPane().setLayout(null);
		
		JLabel label = new JLabel("操作等待时间：");
		label.setBounds(10, 10, 100, 15);
		getContentPane().add(label);
		
		textField_WaitTime = new JTextField();
		textField_WaitTime.setText("5");
		textField_WaitTime.setBounds(123, 7, 66, 21);
		getContentPane().add(textField_WaitTime);
		textField_WaitTime.setColumns(10);
		
		JLabel label_1 = new JLabel("秒");
		label_1.setBounds(199, 10, 54, 15);
		getContentPane().add(label_1);
		
		JButton btnActivate = new JButton("激活");
		btnActivate.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				btnActivate(e);
			}
		});
		btnActivate.setBounds(347, 6, 93, 23);
		getContentPane().add(btnActivate);
		
		JPanel panel = new JPanel();
		panel.setLayout(null);
		panel.setFont(new Font("Times New Roman", Font.PLAIN, 12));
		panel.setBorder(new TitledBorder(UIManager.getBorder("TitledBorder.border"), "设备应答",
				TitledBorder.LEADING, TitledBorder.TOP, null, new Color(0, 0, 0)));
		panel.setBounds(10, 51, 484, 212);
		getContentPane().add(panel);
		
		JLabel label_2 = new JLabel("卡协议类型：");
		label_2.setBounds(10, 27, 86, 15);
		panel.add(label_2);
		
		JLabel label_3 = new JLabel("序列号长度：");
		label_3.setBounds(10, 63, 86, 15);
		panel.add(label_3);
		
		JLabel label_4 = new JLabel("序列号：");
		label_4.setBounds(10, 98, 54, 15);
		panel.add(label_4);
		
		JLabel label_5 = new JLabel("选择确认长度：");
		label_5.setBounds(10, 134, 115, 15);
		panel.add(label_5);
		
		JLabel label_6 = new JLabel("选择确认：");
		label_6.setBounds(10, 170, 86, 15);
		panel.add(label_6);
		
		textField_CardProtocol = new JTextField();
		textField_CardProtocol.setBounds(135, 24, 169, 21);
		panel.add(textField_CardProtocol);
		textField_CardProtocol.setColumns(10);
		
		textField_SerialLen = new JTextField();
		textField_SerialLen.setBounds(135, 60, 169, 21);
		panel.add(textField_SerialLen);
		textField_SerialLen.setColumns(10);
		
		textField_Serial = new JTextField();
		textField_Serial.setBounds(135, 95, 169, 21);
		panel.add(textField_Serial);
		textField_Serial.setColumns(10);
		
		textField_VerifyLen = new JTextField();
		textField_VerifyLen.setBounds(135, 131, 169, 21);
		panel.add(textField_VerifyLen);
		textField_VerifyLen.setColumns(10);
		
		textField_SelVerify = new JTextField();
		textField_SelVerify.setBounds(135, 167, 169, 21);
		panel.add(textField_SelVerify);
		textField_SelVerify.setColumns(10);
	}
	
	/**************************
	 * 激活
	 */
	public void btnActivate(ActionEvent e)
	{
		int waitTime = Integer.valueOf(textField_WaitTime.getText()).intValue();
		if(waitTime < 0 || waitTime > 255)
		{
			AcsDemo_USB.WriteLog(HCUsbSDK.ERR_LEVEL, "操作等待时间范围为[0, 255], 0表示一直执行，直到有卡响应");
			return;
		}
		HCUsbSDK.USB_WAIT_SECOND StruWaitSecond = new HCUsbSDK.USB_WAIT_SECOND();
		StruWaitSecond.dwSize = StruWaitSecond.size();
		StruWaitSecond.byWait = (byte)waitTime;
		
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
		
		if(hcUsbSDK.USB_GetDeviceConfig(AcsDemo_USB.GetSelectUserID(), HCUsbSDK.USB_GET_ACTIVATE_CARD, StruInput, StruOutput))
		{
			AcsDemo_USB.WriteLog(HCUsbSDK.INF_LEVEL, "SUCCESS: USB_SDK_GetDeviceConfig()  Command = USB_SDK_GET_ACTIVATE_CARD");
			StruActivateRes.read();
			textField_CardProtocol.setText(aCardProto[StruActivateRes.byCardType]);  //卡类型
			textField_SerialLen.setText(String.valueOf(StruActivateRes.bySerialLen));  //序列号长度
			
			//序列号,字节转16进制
			String SerialNumber = "";
			for(int i = 0; i < StruActivateRes.bySerialLen; i++)
			{
				/*String hex = Integer.toHexString(StruActivateRes.bySerial[i] & 0xff); 
				if(hex.length() == 1)
				{
					hex += '0';
				}
				if(i < (StruActivateRes.bySerialLen - 1))
				{
					SerialNumber += (hex.toUpperCase() + "-");
				}
				else
				{
					SerialNumber += hex.toUpperCase();
				}*/
				int iSerial= StruActivateRes.bySerial[i]&0xff;
				String StrOneByte = String.format("%02x", iSerial);
				SerialNumber = StrOneByte + SerialNumber;
			}
			textField_Serial.setText(SerialNumber);
			
			textField_VerifyLen.setText(String.valueOf(StruActivateRes.bySelectVerifyLen));  //选择确认长度
			
			//选择确认
			String selVerity = "";
			for(int i = 0; i < 3; i++)
			{
				String hex = Integer.toHexString(StruActivateRes.bySelectVerify[i] & 0xff); 
				if(hex.length() == 1)
				{
					hex += '0';
				}
				if(i < 2)
				{
					selVerity += (hex.toUpperCase() + "-");
				}
				else
				{
					selVerity += hex.toUpperCase();
				}
			}
			textField_SelVerify.setText(selVerity);
		}
		else
		{
			int error = hcUsbSDK.USB_GetLastError();
			AcsDemo_USB.WriteLog(HCUsbSDK.ERR_LEVEL, "activate card failed, error no:" + error);
		}
	}
}
