//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#pragma link "WebReq.obj"
#pragma link "ComAppHlpr.obj"
#pragma link "webinit.obj"
//---------------------------------------------------------------------------
USEFORM("Unit18_11.cpp", Form1);
USEFORM("Unit18_12.cpp", Home); /* TWebAppPageModule: File Type */
USEFORM("Unit18_13.cpp", WebDataModule1); /* TWebDataModule: File Type */
USEFORM("Unit18_14.cpp", Grid); /* TWebPageModule: File Type */
USEFORM("Unit18_15.cpp", Modify); /* TWebPageModule: File Type */
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

