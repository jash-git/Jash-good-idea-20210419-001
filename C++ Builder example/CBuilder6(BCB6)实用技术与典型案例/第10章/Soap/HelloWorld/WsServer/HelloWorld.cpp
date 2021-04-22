//---------------------------------------------------------------------------
#include <ActiveX.hpp>
#include <ComObj.hpp>
#include <WebBroker.hpp>
#include <ISAPIApp.hpp>
#include <ISAPIThreadPool.hpp>
#include <Isapi2.hpp>
#pragma hdrstop

USEFORM("HelloWorld_ServerMain.cpp", WebModule1); /* TWebModule: File Type */
//---------------------------------------------------------------------------
#define Application Webbroker::Application

#pragma link "isapiapp.obj"
#pragma link "isapithreadpool.obj"
#pragma link "webbroker.obj"
#pragma link "ReqMulti.obj"
#pragma link "WebSnap.lib"
#pragma link "WebDSnap.lib"
//---------------------------------------------------------------------------
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
  try
  {
    if (reason == DLL_PROCESS_ATTACH) {
      CoInitFlags = COINIT_MULTITHREADED;
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
extern "C"
{
  BOOL __declspec(dllexport) WINAPI GetExtensionVersion(Isapi2::THSE_VERSION_INFO &Ver)
  {
    return Isapithreadpool::GetExtensionVersion(Ver);
  }
  //---------------------------------------------------------------------------
  unsigned __declspec(dllexport) WINAPI HttpExtensionProc(Isapi2::TEXTENSION_CONTROL_BLOCK &ECB)
  {
    return Isapithreadpool::HttpExtensionProc(ECB);
  }
  //---------------------------------------------------------------------------
  BOOL __declspec(dllexport) WINAPI TerminateExtension(int dwFlags)
  {
    return Isapithreadpool::TerminateExtension(dwFlags);
  }
}
//---------------------------------------------------------------------------
#undef Application
//---------------------------------------------------------------------------
