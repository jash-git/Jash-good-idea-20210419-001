//---------------------------------------------------------------------------
#include <WebBroker.hpp>
#include <ApacheApp.hpp>
#pragma hdrstop

USEFORM("Unit15_6.cpp", WebModule1); /* TWebModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "ApacheApp.obj"
#pragma link "webbroker.obj"

//---------------------------------------------------------------------------
extern "C"
{
  Httpd::module __declspec(dllexport) hello_module;
}

//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
      strcpy(ContentType, "hello-handler");
      strcpy(ModuleName, "mod_hello");
      Apacheapp::set_module(&hello_module);

                 Application->Initialize();
                 Application->CreateForm(__classid(TWebModule1), &WebModule1);
                 Application->Run();
    }
  }
  catch (Exception &exception)
  {
  }
  return 1;
}
//---------------------------------------------------------------------------
#undef Application
//---------------------------------------------------------------------------

