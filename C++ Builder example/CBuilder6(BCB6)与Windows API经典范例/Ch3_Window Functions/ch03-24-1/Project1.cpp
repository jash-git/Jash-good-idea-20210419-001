//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
HANDLE hMutex;
try
   {
   //���Դ򿪴˳������е�Mutexʶ�����
   hMutex = ::OpenMutex( MUTEX_ALL_ACCESS, 0, "MyMutexName" );
   //���ɹ������ʾ���д˳�������ִ���У��A
   //�򽫴˳��򴰿�ȡ�ý������ᵽ��ǰ�漴�ɭ��Y�i
   if( hMutex )
      {//��Ѱ�˳������ƣ�����handle
      HWND hWnd = ::FindWindow(0, "��ֹ�ظ��򿪱�����");
      if( hWnd )
         {//��ʾ�ظ�����Ϣ����
         ShowMessage("�˳����ظ��򿪣�");
         //ȡ����ʾ�������Form1����handle�����ᵽ��ǰ�歱
         HWND TophWnd = ::GetTopWindow(hWnd);
         if( TophWnd ) ::SetForegroundWindow( TophWnd );
         else ::SetForegroundWindow( hWnd );
         }
      return 1;
      }
   //���˳��������е�Mutexʶ���������һ��ʶ�����
   else
      hMutex = ::CreateMutex( 0, 0, "MyMutexName");

   try
     {
     Application->Initialize();
     Application->Title = "��ֹ�ظ��򿪱�����";
     Application->CreateForm(__classid(TForm1), &Form1);
        Application->Run();
     }
   catch (Exception &exception)
     {
     Application->ShowException(&exception);
     }
   }
//�������ʱ���ͷ�Mutexʶ�����
__finally
  {
  ::ReleaseMutex(hMutex);
  }
return 0;
}
//---------------------------------------------------------------------------
