在运行这个程序时，要先安装有IIS（Internet 服务管理器）或MS Personal Web Server。
运行这个实例的步骤：

1、首先，编译WsServer目录下的工程文件，得到helloworld.dll。

2、在IIS或PWS中建立一个虚拟目录，如SOAP，为其指定一个工作目录，如E:\实例\第10章\Soap，并为这个虚拟目录选上“执行”和“浏览”（在调试时可以方便一点）的权限。
然后将helloworld.dll拷贝到上面的工作目录下。

3、打开WsClient工程的ClientMain.cpp文件，找到如下的代码：

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 String str;
 str = GetIMyWS_Hello(true,"http://localhost/Soap/HelloWorld.dll/wsdl/IMyWS_Hello")->GetAString();
 ShowMessage(str);
}

其中“http://localhost/Soap/HelloWorld.dll/wsdl/IMyWS_Hello”是需要用户自己添加的。也就是在自己设定的IIS或PWS中helloworld.dll的路径后面加上“/wsdl/IMyWS_Hello”即可。

4、最后，保存工程文件，运行客户端程序即可。
