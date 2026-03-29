#pragma once
#ifdef Python_EXPORTS
#define DLL_API __declspec(dllexport)
#else
#define DLL_API __declspec(dllimport)
#endif // 

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <Python.h>

#define Single_thread_call 1
#define Double_thread_call 2

extern const char* Function1 ;//单线程调用，单张图片预测
extern const char* Function2 ;//双线程调用，两张图像进行预测
extern const char* Testfunc ;//测试的时候用，其余不用

class DLL_API PythonModel {
public:
	PythonModel() :Flag_isInitial(false), Mode_Flag(Single_thread_call){

	}

	PythonModel(const PythonModel& other);//构造函数重载，用于初始化对象

	bool InitialPyhton(const wchar_t* str = L"D://Anaconda//envs//TF2_HLH", const char* str2 = "./");
	//初始化环境,并设置Python文件路径
	//参数1：为设置Python的运行环境，默认环境路径为"D://Anaconda//envs//TF2_HLH"，注意：这里要输入一个宽字符串，否则将按照默认路径
	//参数2：为Python文件搜索路径，默认为当前目录,这里建议将python工程项目拷贝到当前目录，进而避免出现Py项目中的部分路径和当前路径不一致的情况

	bool Setfunction(const char* pyname = "callpython", const char* function_name = Function1);
	//这里设置所需调用的函数对象,参数1：调用python的文件名，参数2：调用的函数名，将结果保存在pFunc

	bool trans_img2func(cv::Mat& imagesrc, cv::Mat& imagedct);

	bool trans_img2func(cv::Mat& imagesrc1, cv::Mat& imagesrc2, cv::Mat& imagedct1, cv::Mat& imagedct2);
	//向函数传递图像，用于模型预测功能
	//参数1.,2：输入模型的图像，参数3,4：模型返回的图像

	bool ImportImg2Model(cv::Mat &imagesrc, cv::Mat &imagedct,const char* pyname = "callpython", const char* function_name = "test_one_image");
	//向深度学习模型导图一张图片
	//参数1：输入模型的图像，参数2：模型返回的图像
	//参数3：调用python的文件名
	//参数4：调用的函数名
	//补充说明：该函数测试时用，由于会反复加载py环境，运行会很慢，在正式调用时不推荐使用该接口

	bool Clean();

	bool isinitial();//判断是否执行了初始化

private:
	bool Flag_isInitial;//判断环境是否被初始化的标志
	int Mode_Flag;//模式设置标识,1：单线程检测单个图像。2：双线程检测两张图像
	PyObject* pModule;//这里保存Py文件
	PyObject* pFunc;//这里保存所需调用的函数对象，如果调用的是同一函数，则不必重复设置该值

};



