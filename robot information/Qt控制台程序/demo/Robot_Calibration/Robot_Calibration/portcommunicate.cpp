#include "portcommunicate.h"
#include<iostream>

MyPort::MyPort()
{
    //Myport = INVALID_HANDLE_VALUE;//句柄未初始化
}

void MyPort::getparament(const char* str,const int baud)
{
    Portname = str;
    Portbaud = baud;
    return;
}

bool MyPort:: initial_port()
{
    //std::cout<<Portname<<Portbaud<<std::endl;
    Myport = Initial(Portname,Portbaud);
    if(Myport == INVALID_HANDLE_VALUE)
    {
        std::cout<<"Port Initial Fialed !!!"<<std::endl;
        return false;
    }
    return true;
}

bool MyPort::writeport(std::string str)
{
    if(Myport == INVALID_HANDLE_VALUE)
    {
        std::cout<<"The Port has not initialize successfully!!!"<<std::endl;
        return false;
    }
    if(WritePort(Myport,str))
    {
        return true;
    }else{
        std::cout<<"Write Failed!!!"<<std::endl;
        return false;
    }
}

bool MyPort::readport(std::uint8_t* buff,int &length)
{
    if(Myport == INVALID_HANDLE_VALUE)
    {
        std::cout<<"The Port has not initialize successfully!!!"<<std::endl;
        return false;
    }
    if(ReadPort(Myport,buff,length))
    {
        return true;
    }else{
        std::cout<<"Read Failed!!!"<<std::endl;
        return false;
    }

}


bool MyPort::cleanbuff()
{
    if(PurgeComm(Myport, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT))
    {
        return true;
    }else{
        std::cout<<"Clean the buff failed!!!"<<std::endl;
        return false;
    }
}

