#pragma once


using namespace System;

//用到外部非托管均需要使用此内容
using namespace System::Runtime::InteropServices;

using namespace System::Collections::Generic;
using namespace System::Collections;
using namespace std;

#pragma managed
namespace CliDll {

	//C# 端的静态函数对应 C++ 的回调函数，需要以 CLI 的代理函数作为中转
	public delegate void CliCallBack();

	public ref class Arith
	{
	public:
		Arith();
		~Arith();

		//传入参数为 C# 端申请的托管内存，对其进行赋值
		int GetCliData(array<unsigned char>^ ch, int len);

		//注册回调函数
		int RegistCall(CliCallBack^ pFun);

		//执行函数
		void execute();
	};
}
