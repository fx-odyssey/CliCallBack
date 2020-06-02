#include "Cpp.h"


MyArith::MyArith(){}


MyArith::~MyArith(){}


int MyArith::GetCppData(unsigned char ch[], int len)
{
    //在这里对预期的内存块进行复制，在 CLI 层，二次赋值给 C#
    unsigned char* p = ch;
    for (int i = 0; i < len; i++)
    {
        *(p++) = i % 26 + 65;
    }
    return 0;
}


//注册回调函数
int MyArith::RegistCall(CppCallBack pFun)
{
    if (pFun != nullptr)
    {
        cppCall = pFun;
        return 0;
    }
    else
    {
        return -1;
    }
}


//执行函数，演示的
void MyArith::execute()
{
    cppCall();
}
