using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using CliDll;

namespace CSharp
{
    public partial class MyCS
    {
        static Arith arith = new Arith();
        public static void MyCallBack()
        {
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

