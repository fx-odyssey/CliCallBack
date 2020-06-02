#include "Cpp.h"


MyArith::MyArith(){}


MyArith::~MyArith(){}


int MyArith::GetCppData(unsigned char ch[], int len)
{
    unsigned char* p = ch;
    for (int i = 0; i < len; i++)
    {
        *(p++) = i % 26 + 65;
    }
    return 0;
}


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


void MyArith::execute()
{
    cppCall();
}
