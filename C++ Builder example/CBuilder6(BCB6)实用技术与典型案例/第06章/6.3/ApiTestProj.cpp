//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("ApiTestProj.res");
USEFORM("Main.cpp", MainForm);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{

    HANDLE hInstanceMutex = ::CreateMutex(NULL,TRUE, "ApiTestProj");
    if(GetLastError() == ERROR_ALREADY_EXISTS)
    {
        ShowMessage("Has Open a App");
        if(hInstanceMutex)
            CloseHandle(hInstanceMutex);

        return 0;
    }
    DWORD dwExStyle = GetWindowLong(Application->Handle, GWL_EXSTYLE);
    dwExStyle |= WS_EX_TOOLWINDOW;
    SetWindowLong(Application->Handle, GWL_EXSTYLE, dwExStyle);
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TMainForm), &MainForm);
         //Application->ShowMainForm = false;
         //ShowWindow(Application->Handle, SW_HIDE);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    ReleaseMutex(hInstanceMutex);
    CloseHandle(hInstanceMutex);
    return 0;
}
//---------------------------------------------------------------------------
