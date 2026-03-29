#include"pch.h"
#include"CRC16.h"
#include<string>
#include<iostream>
#include <sstream>

unsigned short CRC16_Modbus1(vector<uint8_t>& temp, int iDatalen)
{
    unsigned short crc = 0xFFFF;
    for (int j = 0; j < iDatalen; j++)
    {
        crc = crc ^ temp[j];
        for (int i = 0; i < 8; i++)
        {
            if ((crc & 0x0001) > 0)
            {
                crc = crc >> 1;
                crc = crc ^ 0xa001;
            }
            else
                crc = crc >> 1;
        }
    }
    temp.push_back(crc & 0x00ff);
    temp.push_back(crc >> 8);

    return crc;
}

void string_to_hex(const string &str , vector<uint8_t> &temp)//数据转换成16进制数据
{
    uint8_t data[20];
    string str_temp;
    for (int i = 0; i < str.length(); i += 2)
    {
        str_temp = str.substr(i, 2);//字符串裁剪
        sscanf_s(str_temp.c_str(), "%hhx", &data[i / 2]);//将字符类型转换成16进制
        temp.push_back(data[i / 2]);
    }
    /*for (int i = 0; i < str.size()/2; i++)
    {
        unsigned short num = std::stoi(str.substr(i, 2), 0, 16);
        temp.push_back(num);
    }*/
    return ;
}

void print_hex(const uint8_t* readbuffer, unsigned long length)
{
    for (unsigned int i = 0; i < length; i++)
    {
        printf("%02X ", int(readbuffer[i]));
    }
    cout << endl;
}

