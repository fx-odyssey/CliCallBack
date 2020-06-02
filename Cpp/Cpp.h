#pragma once

using CppCallBack = void (__stdcall*)();

class __declspec(dllexport) MyArith
{
public:
    MyArith();
    ~MyArith();

    int GetCppData(unsigned char ch[], int len);
    int RegistCall(CppCallBack pFun);
    void execute();

private:
    CppCallBack cppCall;
};

