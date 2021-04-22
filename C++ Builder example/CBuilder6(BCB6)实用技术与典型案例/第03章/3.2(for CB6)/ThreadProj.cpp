//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("ThreadProj.res");
USEFORM("Main.cpp", MainForm);
USEUNIT("UThread.cpp");
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
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
