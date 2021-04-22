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
         //建立此程序特定的Mutex对象，以供检测是否重复打开此程序
             HANDLE hMutex = ::CreateMutex(NULL, FALSE, "MyMutexName");
    //找到正在执行中的相同Mutex handle
    if ( ::GetLastError() == ERROR_ALREADY_EXISTS )
       {
       //重定义此程序标题，避免重复找到的状况出现
       Application->Title="Testing";
       HWND FirsthWnd, FirstChildhWnd;
       //找到现执行的本程序handle
       FirsthWnd = ::FindWindow("TApplication", "重复打开此程序测试");
       //若缩小到快捷工具栏上，则显现在桌面最前面
       if (::IsIconic(FirsthWnd))
           ::ShowWindow(FirsthWnd, SW_SHOWDEFAULT);
       ::SetForegroundWindow(FirsthWnd);
       //取得最后出现的POP窗口handle，若非现执行的此程序，
       //而另有POP窗口，则显现在本程序前面
       FirstChildhWnd = ::GetLastActivePopup(FirsthWnd);
       if (FirsthWnd != FirstChildhWnd)
           ::BringWindowToTop(FirstChildhWnd);
       }
    else
       {
                 Application->Initialize();
                 Application->Title = "重复打开此程序测试";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
                 //当关闭程序时，即释放Mutex对象handle
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
