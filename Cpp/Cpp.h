#pragma once

//C++11标准用法，替代原有的 typedef 用法
using CppCallBack = void (__stdcall*)();

class __declspec(dllexport) MyArith
{
public:
    MyArith();
    ~MyArith();

    //C#先在自己的托管平台上申请内存，传到 CLI 层，与非托管的 C++ 数据进行交互赋值
    int GetCppData(unsigned char ch[], int len);

    //注册回调函数的接口
    int RegistCall(CppCallBack pFun);

    //执行函数
    void execute();

private:
    CppCallBack cppCall;
};

