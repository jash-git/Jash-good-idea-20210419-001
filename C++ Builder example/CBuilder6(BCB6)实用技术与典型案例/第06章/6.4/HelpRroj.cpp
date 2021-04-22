//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("HelpRroj.res");
USEFORM("Main.cpp", MainForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->HelpFile = "D:\\YCL\\exemple\\6.4\\Myhelp.hlp";
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
