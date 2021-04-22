//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
         //�����˳����ض���Mutex�����Թ�����Ƿ��ظ��򿪴˳���
             HANDLE hMutex = ::CreateMutex(NULL, FALSE, "MyMutexName");
    //�ҵ�����ִ���е���ͬMutex handle
    if ( ::GetLastError() == ERROR_ALREADY_EXISTS )
       {
       //�ض���˳�����⣬�����ظ��ҵ���״������
       Application->Title="Testing";
       HWND FirsthWnd, FirstChildhWnd;
       //�ҵ���ִ�еı�����handle
       FirsthWnd = ::FindWindow("TApplication", "�ظ��򿪴˳������");
       //����С����ݹ������ϣ���������������ǰ��
       if (::IsIconic(FirsthWnd))
           ::ShowWindow(FirsthWnd, SW_SHOWDEFAULT);
       ::SetForegroundWindow(FirsthWnd);
       //ȡ�������ֵ�POP����handle��������ִ�еĴ˳���
       //������POP���ڣ��������ڱ�����ǰ��
       FirstChildhWnd = ::GetLastActivePopup(FirsthWnd);
       if (FirsthWnd != FirstChildhWnd)
           ::BringWindowToTop(FirstChildhWnd);
       }
    else
       {
                 Application->Initialize();
                 Application->Title = "�ظ��򿪴˳������";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
                 //���رճ���ʱ�����ͷ�Mutex����handle
                 ::ReleaseMutex(hMutex);
         }
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
