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
   //尝试打开此程序特有的Mutex识别对象
   hMutex = ::OpenMutex( MUTEX_ALL_ACCESS, 0, "MyMutexName" );
   //若成功，则表示已有此程序正在执行中，
   //则将此程序窗口取得焦点与提到最前面即可
   if( hMutex )
      {//找寻此程序名称，返回handle
      HWND hWnd = ::FindWindow(0, "防止重复打开本程序");
      if( hWnd )
         {//显示重复打开信息窗口
         ShowMessage("此程序重复打开！");
         //取得显示在桌面的Form1窗口handle，并提到最前面
         HWND TophWnd = ::GetTopWindow(hWnd);
         if( TophWnd ) ::SetForegroundWindow( TophWnd );
         else ::SetForegroundWindow( hWnd );
         }
      return 1;
      }
   //若此程序无特有的Mutex识别对象，则建立一新识别对象
   else
      hMutex = ::CreateMutex( 0, 0, "MyMutexName");

   try
     {
     Application->Initialize();
     Application->Title = "防止重复打开本程序";
     Application->CreateForm(__classid(TForm1), &Form1);
        Application->Run();
     }
   catch (Exception &exception)
     {
     Application->ShowException(&exception);
     }
   }
//程序结束时，释放Mutex识别对象
__finally
  {
  ::ReleaseMutex(hMutex);
  }
return 0;
}
//---------------------------------------------------------------------------
