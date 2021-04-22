//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("MailProj.res");
USEFORM("Main.cpp", MainForm);
USEFORM("RecevieForm.cpp", POP3Form);
USEFORM("SendForm.cpp", SMTPForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TMainForm), &MainForm);
         Application->CreateForm(__classid(TPOP3Form), &POP3Form);
         Application->CreateForm(__classid(TSMTPForm), &SMTPForm);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
