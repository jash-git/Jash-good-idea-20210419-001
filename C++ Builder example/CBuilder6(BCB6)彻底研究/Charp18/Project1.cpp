//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "webinit.obj"
//---------------------------------------------------------------------------
USEFORM("Unit1.cpp", Form1);
USEFORM("Unit2.cpp", Home); /* TWebAppPageModule: File Type */
USEFORM("Unit3.cpp", Login); /* TWebPageModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
  try
  {
    Application->Initialize();
    Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
  }
  catch (Exception &exception)
  {
    Sysutils::ShowException(&exception, System::ExceptAddr());
  }
  return 0;
}
//---------------------------------------------------------------------------

