//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "webinit.obj"
//---------------------------------------------------------------------------
USEFORM("Unit18_21.cpp", Form1);
USEFORM("Unit18_22.cpp", Home); /* TWebAppPageModule: File Type */
USEFORM("Unit18_23.cpp", Login); /* TWebPageModule: File Type */
USEFORM("Unit18_24.cpp", WebDataModule4); /* TWebDataModule: File Type */
USEFORM("Unit18_25.cpp", AfterLogin); /* TWebPageModule: File Type */
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

