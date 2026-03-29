#pragma execution_character_set("utf-8")
#include"pch.h"
#include"modbusport.h"
#include<string>
#include<thread> 
#include<iostream>
#include"CRC16.h"
#include <iomanip>
#include <sstream>

using namespace std;

HANDLE Initial(const char* PortName, int baud)
{
	HANDLE myport = CreateFile(PortName,//串口名称
		GENERIC_READ | GENERIC_WRITE,//读写模式
		0,//串口共享模式，这里不允许共享，设置为0
		NULL,//串口安全属性，设置为0，表示不可被子程序继承
		OPEN_EXISTING,//创建文件的性质，这里为打开文件且将文件清空
		0,//文件属性和标志，异步通讯为FILE_FLAG_OVERLAPPED，设置为0则为同步通讯
		0);//一个指向模板的句柄，一般为null
		   //该函数失败返回 INVALID_HANDLE_VALUE
	std::cout << PortName << std::endl;
	if (myport == INVALID_HANDLE_VALUE)
	{
		cout << "Failed to open serial port" << endl;
		return myport;
	}
	else {
		cout << "Open serial port successfully" << endl;
	}

	SetupComm(myport, 4096, 4096);//设置缓冲区,输入和输出缓冲区大小都为1024

	COMMTIMEOUTS timeouts;//创建一个超时句柄
	timeouts.ReadIntervalTimeout = 100;//读取两个字符之间的时间间隔
	timeouts.ReadTotalTimeoutConstant = 5000;//读取操作的固定超时
	timeouts.ReadTotalTimeoutMultiplier = 500;//读取操作再读取每个字符时的超时

	timeouts.WriteTotalTimeoutMultiplier = 500;//写操作在写每个字符时的时间间隔
	timeouts.WriteTotalTimeoutConstant = 2000;//写操作的固定超时
	/*总超时=每个字符的超时*字符数+固定超时*/
	SetCommTimeouts(myport, &timeouts);//设置超时

	DCB dcb;//设置一个句柄用来配置串口
	GetCommState(myport, &dcb);//获取设备的配置参数赋给dcp
	dcb.BaudRate = baud;//波特率
	dcb.ByteSize = 8;//数据位，为5~8
	dcb.Parity = NOPARITY;//奇偶校验位，这里为无
	dcb.StopBits = ONESTOPBIT;//停止位，1位停止位
	SetCommState(myport, &dcb);//完成串口配置
	return myport;
}

bool WritePort(HANDLE& myport)
{
	if (myport == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	vector<uint8_t> temp;
	//uint8_t temp[8] = {};
	string str;
	cout << "Please enter telegram:" << endl;
	getline(cin, str);
	string_to_hex(str, temp);
	cout << temp.size() << endl;
	CRC16_Modbus1(temp, temp.size());

	if (WriteFile(myport,
		temp.data(),//指向vector容器元素首地址的指针，注意：不可以用temp代替
		8,
		NULL,
		NULL))
	{
		cout << "Sent successfully" << endl;
		return true;
	}
	else {
		cout << "Send Failure" << endl;
		return false;
	}

}

bool WritePort(HANDLE& myport, string& str)
{
	if (myport == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	vector<uint8_t> temp;
	string_to_hex(str, temp);
	cout << temp.size() << endl;
	CRC16_Modbus1(temp, temp.size());
	if (WriteFile(myport,
		temp.data(),//指向vector容器元素首地址的指针，注意：不可以用temp代替
		8,
		NULL,
		NULL))
	{
		cout << "Sent successfully, the input message is:" << endl;
		for (int i = 0; i < temp.size(); i++)
		{
			std::cout << std::hex << int(temp[i]) << " ";
		}
		std::cout << std::endl;
		return true;
	}
	else {
		cout << "Send Failure" << endl;
		return false;
	}
}

bool ReadPort(HANDLE& myport)
{
	if (myport == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	uint8_t readbuffer[100];
	unsigned long realnum;
	if (ReadFile(myport,
		readbuffer,
		30,
		&realnum,
		NULL) == 1)
	{
		cout << "Telegram response:" << endl;
		print_hex(readbuffer, realnum);
		return true;
	}
	else
	{
		return false;
	}

}

bool ReadPort(HANDLE& myport, uint8_t* buff, int& length)
{
	if (myport == INVALID_HANDLE_VALUE)
	{
		return false;
	}
	uint8_t readbuffer[100];
	unsigned long realnum;
	if (ReadFile(myport,
		readbuffer,
		30,
		&realnum,
		NULL) == 1)
	{
		length = realnum;
		std::cout << "Telegram response:" << std::endl;
		memcpy(buff, readbuffer, realnum);
		print_hex(buff, realnum);
		return true;
	}
	else
	{
		std::cout << "Read failed" << std::endl;
		return false;
	}
}

void hex_to_string(uint8_t* buffer, int length, std::string& str)
{
	for (int i = 0; i < length; i++)
	{
		std::stringstream stream;//创建一个字符流
		stream << std::setfill('0') << std::setw(2) << std::hex << int(buffer[i]);// 将数据以十六进制形式输出，并确保每个字节都用两位表示
		str += stream.str();
	}
	return;
}
