#include "Cli.h"
#include "Cpp/Cpp.h"

//CLI 不支持直接声明对象，因为这里是托管平台，而 MyArith 为非托管类
MyArith *myArith;

CliDll::Arith::Arith()
{
    //非托管使用 new
    myArith = new MyArith();
}


CliDll::Arith::~Arith()
{
    myArith->~MyArith();
}


//在此函数里，函数参数为 C# 的托管数组，函数内申请一块非托管内存，交由 C++ 进行赋值，再赋值给 C# 的托管数组
int CliDll::Arith::GetCliData(array<unsigned char>^ ch, int len)
{
    //申请一块非托管内存
    unsigned char* src = new unsigned char[len];
    if (src == nullptr)
    {
        return -1;
    }

    //非托管内存交由 C++ 赋值
    int mark = myArith->GetCppData(src, len);
    if (mark)
    {
        return -2;
    }

    //获取 C# 层托管内存的原生指针，用以赋值
    pin_ptr<unsigned char> cssrc = &ch[0];
    unsigned char* clisrc = src;
    for (int i = 0; i < len; i++)
    {
        *(cssrc++) = *(clisrc++);
    }

    //申请的非托管的内存块，需要手动释放
    delete[] src;

    return 0;

}


//传入参数为 C# 的静态函数
int CliDll::Arith::RegistCall(CliCallBack^ pFun)
{
    //C# 的函数转 C++ 的函数指针，转换成原生指针
    CppCallBack cliCall = (CppCallBack)Marshal::GetFunctionPointerForDelegate(pFun).ToPointer();

    //注册 C++ 提供的回调函数
    myArith->RegistCall(cliCall);
    return 0;
}


//执行函数
void CliDll::Arith::execute()
{
    myArith->execute();
}

