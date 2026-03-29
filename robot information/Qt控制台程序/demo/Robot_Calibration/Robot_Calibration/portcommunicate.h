#ifndef PORTCOMMUNICATE_H
#define PORTCOMMUNICATE_H
#include<modbusport.h>


/*该类直接调用动态库，这里仅仅做一个简单的二次封装*/
class MyPort
{
public:
    MyPort();

    HANDLE Myport;//串口的句柄

    bool initial_port();//初始化串口，在此之前要获得其串口名称和波特率，其余配置选项已经在内部固定

    bool writeport(std::string str);//向串口写入数据，二次封装发送报文
    //参数为要向串口发送的报文（字符串格式）

    bool readport(std::uint8_t* buff,int &length);//向串口发送数据，二次封装接受报文
    //参数为接收的报文指针

    bool cleanbuff();//清空串口的缓冲区，最好每次读写结束后清空一下防止缓冲区溢出

    void getparament(const char* str, const int baud);//获取串口名称以及波特率


    const char* Portname = nullptr;//串口名称
    int Portbaud = 0;//波特率

};

#endif // PORTCOMMUNICATE_H
