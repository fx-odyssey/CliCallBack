#include "Cli.h"
#include "Cpp/Cpp.h"

MyArith *myArith;

CliDll::Arith::Arith()
{
    myArith = new MyArith();
}


CliDll::Arith::~Arith()
{
    myArith->~MyArith();
}


int CliDll::Arith::GetCliData(array<unsigned char>^ ch, int len)
{
    unsigned char* src = new unsigned char[len];
    if (src == nullptr)
    {
        return -1;
    }

    int mark = myArith->GetCppData(src, len);
    if (mark)
    {
        return -2;
    }

    unsigned char* clisrc = src;
    pin_ptr<unsigned char> cssrc = &ch[0];
    for (int i = 0; i < len; i++)
    {
        *(cssrc++) = *(clisrc++);
    }
    delete[] src;

    return 0;

}


int CliDll::Arith::RegistCall(CliCallBack^ pFun)
{
    CppCallBack cliCall = (CppCallBack)Marshal::GetFunctionPointerForDelegate(pFun).ToPointer();
    myArith->RegistCall(cliCall);
    return 0;
}


void CliDll::Arith::execute()
{
    myArith->execute();
}

