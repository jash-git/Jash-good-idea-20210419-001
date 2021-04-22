//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project1.res");
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit1a.cpp", Form1a);//这是新建第二个窗口时，程序自动加入
//在Form1打开前，先显示静态的片头窗口-------------------------------------------
#include "Unit1a.h"
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
try
  {//新建并显示片头窗口
  TForm1a *Splash = new TForm1a(NULL);
  Splash->BorderStyle = bsNone;
  Splash->Show();
  Splash->Refresh();
  //片头窗口倒数计时5秒钟
  int i=5;
  while(i)
     {
     Splash->Panel1->Color = (TColor)RGB(255,i*50,255-i*50);
     Splash->Panel1->Caption = "倒数 "+AnsiString(i--)+" 秒钟";
     Splash->Refresh();
     Sleep(1000);//每次程序停止1秒钟
     }

  Application->ProcessMessages();
  Application->Initialize();
  Application->Title = "我是WinMain函数测试";
  Application->Hint = "我是WinMain函数测试";
  Application->CreateForm(__classid(TForm1), &Form1);
        delete Splash;//在程序显示执行前，删除片头窗口
  Application->Run();
  }
catch (Exception &exception)
  {
  Application->ShowException(&exception);
  }
return 0;
}
//---------------------------------------------------------------------------
