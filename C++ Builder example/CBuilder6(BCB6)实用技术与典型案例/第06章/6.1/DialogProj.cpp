//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("DialogProj.res");
USEFORM("Main.cpp", MainForm);
USEFORM("MessageDlg.cpp", MessageForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TMessageForm), &MessageForm);
         Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
