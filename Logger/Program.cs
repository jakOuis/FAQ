using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Net.Sockets;
using System.Net;

namespace Logger
{
    class Program
    {
        static void Main(string[] args)
        {
            var server = new UdpClient(47381);
            while (true)
            {
                IPEndPoint remote = new IPEndPoint(IPAddress.Any, 0);
                var data = server.Receive(ref remote);
                Console.WriteLine("[{0}] {1}", DateTime.Now.ToShortTimeString(), Encoding.UTF8.GetString(data));
            }
        }
    }
}
