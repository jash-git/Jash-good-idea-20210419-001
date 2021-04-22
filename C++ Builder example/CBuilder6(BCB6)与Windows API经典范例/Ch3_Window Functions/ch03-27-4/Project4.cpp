//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project4.res");
USEFORM("Unit4.cpp", Form1);
//无修改的信息处理-------------------------------------------------------------
LONG APIENTRY WndProc(HWND HWnd,UINT Msg,WPARAM WParam,LPARAM LParam)
{
return DefWindowProc(HWnd, Msg, WParam, LParam);
}
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
//先设置WNDCLASS结构，设置一窗口类型
WNDCLASS SplashClass;
SplashClass.style = CS_HREDRAW | CS_VREDRAW;
SplashClass.lpfnWndProc = (WNDPROC)WndProc;//信息不予变动
SplashClass.cbClsExtra = 0;
SplashClass.cbWndExtra = 0;
SplashClass.hInstance = HInstance;
SplashClass.hIcon = NULL;
SplashClass.hCursor = NULL;
SplashClass.hbrBackground = (HBRUSH)(BLACK_BRUSH);
SplashClass.lpszMenuName = "splash";
SplashClass.lpszClassName = "splash";
//若无法登录此新窗口类型，则停止程序
if(!::RegisterClass(&SplashClass)) return false;
//预定片头长宽
const int width = Screen->Width/2;
const int height = Screen->Height/2;
//再取得桌面范围
RECT R;
::GetWindowRect(::GetDesktopWindow(), &R);
//依新窗口类型，建立一新窗口
HWND SplashHandle = ::CreateWindow("splash", NULL, WS_POPUP,
                                   (R.right - width) / 2,
                                   (R.bottom - height) / 2,
                                   width, height, NULL, NULL,
                                   HInstance, NULL);
//若无法建立一新窗口，则停止执行程序
if (!SplashHandle) return false;
//将此片头窗口设为最前面位置
::SetWindowPos(SplashHandle, HWND_TOPMOST, 0, 0, 0, 0,
               SWP_NOMOVE | SWP_NOSIZE);
//开始显示此新窗口
::ShowWindow(SplashHandle, SW_SHOW);
//更新此新窗口
::UpdateWindow(SplashHandle);
//再将指定图像显示在此新片头窗口上
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
//取得现在窗口系统目录下的Window图像为示范
char sysDir[MAX_PATH +1];
::GetSystemDirectory(sysDir, sizeof(sysDir));
AnsiString setupbmp = AnsiString(sysDir);
setupbmp = setupbmp.SubString(1, setupbmp.Length()-6)+"Setup.bmp";
Bitmap->LoadFromFile(setupbmp.c_str());
//在图像上写些字！
Bitmap->Canvas->Font->Name = "宋体";
Bitmap->Canvas->Font->Size = 40;
Bitmap->Canvas->TextOut(30,20,"这是WinAPI测试片头!!!");
//将图像缩放与绘制到片头窗口背景上
HDC Hdc = ::GetDC(SplashHandle);
::StretchBlt(Hdc, 0, 0, width, height,
             Bitmap->Canvas->Handle,
             0, 0, Bitmap->Width, Bitmap->Height, SRCCOPY);
//释放片头窗口DC与删除图像
::ReleaseDC(SplashHandle, Hdc);
delete Bitmap;
//停止3秒钟，欣赏片头图像
::Sleep(3000);
//开始进入Form1
try
    {
    Application->Initialize();
    Application->CreateForm(__classid(TForm1), &Form1);
        ::DestroyWindow(SplashHandle);
    Application->Run();
    }
catch (Exception &exception)
    {
    Application->ShowException(&exception);
    }
return 0;
}
//---------------------------------------------------------------------------
