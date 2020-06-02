#pragma once


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Collections::Generic;
using namespace System::Collections;
using namespace std;

#pragma managed
namespace CliDll {

	public delegate void CliCallBack();

	public ref class Arith
	{
	public:
		Arith();
		~Arith();

		int GetCliData(array<unsigned char>^ ch, int len);
		int RegistCall(CliCallBack^ pFun);
		void execute();
	};
}
