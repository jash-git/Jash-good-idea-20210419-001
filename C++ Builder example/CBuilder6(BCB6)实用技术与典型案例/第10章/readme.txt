�������������ʱ��Ҫ�Ȱ�װ��IIS��Internet �������������MS Personal Web Server��
�������ʵ���Ĳ��裺

1�����ȣ�����WsServerĿ¼�µĹ����ļ����õ�helloworld.dll��

2����IIS��PWS�н���һ������Ŀ¼����SOAP��Ϊ��ָ��һ������Ŀ¼����E:\ʵ��\��10��\Soap����Ϊ�������Ŀ¼ѡ�ϡ�ִ�С��͡���������ڵ���ʱ���Է���һ�㣩��Ȩ�ޡ�
Ȼ��helloworld.dll����������Ĺ���Ŀ¼�¡�

3����WsClient���̵�ClientMain.cpp�ļ����ҵ����µĴ��룺

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 String str;
 str = GetIMyWS_Hello(true,"http://localhost/Soap/HelloWorld.dll/wsdl/IMyWS_Hello")->GetAString();
 ShowMessage(str);
}

���С�http://localhost/Soap/HelloWorld.dll/wsdl/IMyWS_Hello������Ҫ�û��Լ���ӵġ�Ҳ�������Լ��趨��IIS��PWS��helloworld.dll��·��������ϡ�/wsdl/IMyWS_Hello�����ɡ�

4����󣬱��湤���ļ������пͻ��˳��򼴿ɡ�
