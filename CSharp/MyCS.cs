using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CliDll;

//C# 的东西我也不懂，就不注释了，全靠百度写的下边的代码，貌似给百度打了广告。。。
//算了，最好培养自己能力，早日用上 Google，用它，逼格高一些
namespace CSharp
{
    public class MyCS
    {
        static Arith arith = new Arith();
        public static void MyCallBack()
        {
            //还是忍不住说一下，C# 和 C++ 有个数据类型对照表，这里用的 byte，对照 C++ 的 unsigned char
            byte[] data = new byte[26];
            int mark = MyCS.arith.GetCliData(data, 26);
            for(int i = 0; i < 26; i++)
            {
                Console.WriteLine(data[i]);
            }
        }

        static void Main(string[] args)
        {
            CliCallBack cliCall = new CliCallBack(MyCallBack);
            MyCS.arith.RegistCall(cliCall);
            MyCS.arith.execute();

            Console.ReadLine();
        }
    }
}

