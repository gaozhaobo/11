#include "mainwindow.h"

#include <QApplication>

#include<iostream>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    MainWindow w(1);//第一个参数完全没用，就是避免和默认构造函数混淆

    w.show();

    std::cout<<"程序开始"<<std::endl;

    return a.exec();
}
