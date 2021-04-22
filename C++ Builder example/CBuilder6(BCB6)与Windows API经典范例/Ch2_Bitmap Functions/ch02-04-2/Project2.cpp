//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
USERES("Project2.res");
USEFORM("Unit2.cpp", Form1);
USEFORM("Unit2_2.cpp", Newform);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
        Application->Initialize();
        Application->CreateForm(__classid(TForm1), &Form1);
        Application->CreateForm(__classid(TNewform), &Newform);
        Application->Run();
    }
    catch (Exception &exception)
    {
        Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
