#pragma once
#ifdef MODBUSDLL_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // 

#include <Windows.h>
#include<string>

DLL_API HANDLE Initial(const char* PortName, int baud);//初始化串口
//参数一：串口名称，参数二：波特率。数据位，奇偶校验位，停止位等按照最常用的设置
//函数返回一个myport句柄，需要一个handle变量接收

DLL_API bool WritePort(HANDLE& myport);

DLL_API bool WritePort(HANDLE& myport, std::string& str);
//写入串口的的重载，将字符串str写入串口

DLL_API bool ReadPort(HANDLE& myport , uint8_t* buff, int& length);
//读出串口的的重载，从串口中读出数据并记录读出的长度

DLL_API bool ReadPort(HANDLE& myport);

DLL_API void hex_to_string(uint8_t* buffer, int length, std::string& str);
//用于将16进制的数据固定成字符串，每个16进制的数的宽度为2，不足的用0补齐
