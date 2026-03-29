#pragma once
#include<vector>
#include<string>
using namespace std;

//unsigned short CRC16_Modbus1(unsigned char* pcData, int iDatalen);
unsigned short CRC16_Modbus1(vector<uint8_t>& temp, int iDatalen);

void string_to_hex(const string& str, std::vector<uint8_t>& temp);

//将字符串数据转换成16进制数据，参数一：带转换的字符串，参数二：转换后16进制的数组
void print_hex(const uint8_t* readbuffer, unsigned long length);
//打印输出16进制数据，参数一：存放16进制数据的数组，参数二：数组长度

