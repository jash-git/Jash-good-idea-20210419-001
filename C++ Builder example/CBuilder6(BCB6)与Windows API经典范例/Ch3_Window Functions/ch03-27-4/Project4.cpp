//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project4.res");
USEFORM("Unit4.cpp", Form1);
//���޸ĵ���Ϣ����-------------------------------------------------------------
LONG APIENTRY WndProc(HWND HWnd,UINT Msg,WPARAM WParam,LPARAM LParam)
{
return DefWindowProc(HWnd, Msg, WParam, LParam);
}
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
//������WNDCLASS�ṹ������һ�������ͫ�
WNDCLASS SplashClass;
SplashClass.style = CS_HREDRAW | CS_VREDRAW;
SplashClass.lpfnWndProc = (WNDPROC)WndProc;//��Ϣ����䶯
SplashClass.cbClsExtra = 0;
SplashClass.cbWndExtra = 0;
SplashClass.hInstance = HInstance;
SplashClass.hIcon = NULL;
SplashClass.hCursor = NULL;
SplashClass.hbrBackground = (HBRUSH)(BLACK_BRUSH);
SplashClass.lpszMenuName = "splash";
SplashClass.lpszClassName = "splash";
//���޷���¼���´������ͣ���ֹͣ����
if(!::RegisterClass(&SplashClass)) return false;
//Ԥ��Ƭͷ����
const int width = Screen->Width/2;
const int height = Screen->Height/2;
//��ȡ�����淶Χ
RECT R;
::GetWindowRect(::GetDesktopWindow(), &R);
//���´������ͣ�����һ�´���
HWND SplashHandle = ::CreateWindow("splash", NULL, WS_POPUP,
                                   (R.right - width) / 2,
                                   (R.bottom - height) / 2,
                                   width, height, NULL, NULL,
                                   HInstance, NULL);
//���޷�����һ�´��ڣ���ִֹͣ�г���
if (!SplashHandle) return false;
//����Ƭͷ������Ϊ��ǰ��λ��
::SetWindowPos(SplashHandle, HWND_TOPMOST, 0, 0, 0, 0,
               SWP_NOMOVE | SWP_NOSIZE);
//��ʼ��ʾ���´���
::ShowWindow(SplashHandle, SW_SHOW);
//���´��´���
::UpdateWindow(SplashHandle);
//�ٽ�ָ��ͼ����ʾ�ڴ���Ƭͷ�����ϤW
Graphics::TBitmap *Bitmap = new Graphics::TBitmap();
//ȡ�����ڴ���ϵͳĿ¼�µ�Windowͼ��Ϊʾ��
char sysDir[MAX_PATH +1];
::GetSystemDirectory(sysDir, sizeof(sysDir));
AnsiString setupbmp = AnsiString(sysDir);
setupbmp = setupbmp.SubString(1, setupbmp.Length()-6)+"Setup.bmp";
Bitmap->LoadFromFile(setupbmp.c_str());
//��ͼ����дЩ�֣��r�I
Bitmap->Canvas->Font->Name = "����";
Bitmap->Canvas->Font->Size = 40;
Bitmap->Canvas->TextOut(30,20,"����WinAPI����Ƭͷ!!!");
//��ͼ����������Ƶ�Ƭͷ���ڱ����ϤW
HDC Hdc = ::GetDC(SplashHandle);
::StretchBlt(Hdc, 0, 0, width, height,
             Bitmap->Canvas->Handle,
             0, 0, Bitmap->Width, Bitmap->Height, SRCCOPY);
//�ͷ�Ƭͷ����DC��ɾ��ͼ��
::ReleaseDC(SplashHandle, Hdc);
delete Bitmap;
//ֹͣ3���ӣ�����Ƭͷͼ��
::Sleep(3000);
//��ʼ����Form1
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
