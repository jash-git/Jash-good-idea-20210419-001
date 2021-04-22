//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <dir.h>
#include <Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#pragma resource"SpyCursor.res"

TMainForm *MainForm;
char WindowTitle[80];
char OSPath[50];
const crSpyCursor=5;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    bStartCapture=false;
    StatusBar1->SimpleText=AnsiString("您现在没有任何操作!");
    m_strCaptureWindow=new TStringList;
    Screen->Cursors[crSpyCursor]=LoadCursor( HInstance,"SPY");
    m_strOSPath="C:\\";
    m_iSpyTime=2000;
    try
    {
        GetWindowsDirectory(OSPath,50);
        m_strOSPath=AnsiString(OSPath);
        
    }
    catch(...)
    {
        ShowMessage(GetLastError());
    }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MenuHideClick(TObject *Sender)
{
    ShowWindow(MainForm->Handle,SW_HIDE);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    if(Button==mbRight)
    {
        SetWindowPos(MainForm->Handle,HWND_BOTTOM,50,50,100,100,SWP_NOSIZE);
        SetCapture(MainForm->Handle);
        bStartCapture=true;
        Screen->Cursor=(TCursor)crSpyCursor;
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{

     if(bStartCapture)
     {

        POINT MousePos;
        HWND hwndSubject;

        StatusBar1->SimpleText=AnsiString("您现在正在捕捉窗体");
        MousePos.x=(long)X;
        MousePos.y=(long)Y;
        hwndSubject=WindowFromPoint(MousePos);
        if(hwndSubject)
        {
            if(GetWindowThreadProcessId(hwndSubject,NULL)!=GetCurrentThreadId())
            {
                RECT WindowRect;
                WINDOWINFO CaptureWindowInfo;
                GetWindowText(hwndSubject,WindowTitle,80);
                m_strWindowTitle=AnsiString(WindowTitle);
                LabelHasCapture->Caption=AnsiString("您捕捉的窗口是:  ")+m_strWindowTitle;
                GetWindowInfo(hwndSubject,&CaptureWindowInfo);
                WindowRect=CaptureWindowInfo.rcWindow;
                Label3->Caption=AnsiString("窗口宽度:")+AnsiString(WindowRect.right-WindowRect.left);
                Label4->Caption=AnsiString("窗口高度:")+AnsiString(WindowRect.bottom-WindowRect.top);
                WindowRect=CaptureWindowInfo.rcClient;
                Label5->Caption=AnsiString("客户区宽度:")+AnsiString(WindowRect.right-WindowRect.left);
                Label6->Caption=AnsiString("客户区高度:")+AnsiString(WindowRect.bottom-WindowRect.top);
             }
         }

     }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CreateParams(TCreateParams &Params)
{
    TForm::CreateParams(Params);         // call base class first
        Params.ExStyle |= WS_EX_CLIENTEDGE;  // then add the style
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    SaveCaptureWindow();
    WriteReg();
    delete m_strCaptureWindow;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormMouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    StatusBar1->SimpleText=AnsiString("您现在没有任何操作!");
    if(bStartCapture)
    {
        if(!m_strWindowTitle.IsEmpty())
        {
            m_strCaptureWindow->Add(m_strWindowTitle);
            ListBoxCapture->Items->Assign(m_strCaptureWindow);
        }
        bStartCapture=false;
        Screen->Cursor=crArrow;
    }
}
//---------------------------------------------------------------------------

void TMainForm::SaveCaptureWindow(void)
{
    if(ListBoxCapture->Items->Count>0)
    {
        AnsiString strHistoryFile=ChangeFileExt( Application->ExeName, ".INI");
        ListBoxCapture->Items->SaveToFile(strHistoryFile);
    }
    else
        MessageDlg(" 您没有捕捉任何窗口", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

}
//---------------------------------------------------------------------------

void TMainForm::LoadHistoryInfo(void)
{
    AnsiString strHistoryFile=ChangeFileExt( Application->ExeName, ".INI");
    if(FileExists(strHistoryFile))
    {
        m_strCaptureWindow->LoadFromFile(strHistoryFile);
        ListBoxCapture->Items->Assign(m_strCaptureWindow);
    }
    else
        MessageDlg(" 您以前没有捕捉任何窗口", mtConfirmation, TMsgDlgButtons() << mbOK, 0);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormCreate(TObject *Sender)
{
     LoadHistoryInfo();
     ReadReg();
     CheckBoxHide->Checked=bNextHide;
   //  Timer1->Interval=m_iSpyTime;
     Timer1->Interval=2000;
     if(bNextHide)
     {
        Application->ShowMainForm = false;
        ShowWindow(Application->Handle, SW_HIDE);
        Timer1->Enabled=true;
     }
     RecordHwnd();
}
//---------------------------------------------------------------------------
void TMainForm::WriteReg(void)
{
     TRegistry *Registry = new TRegistry;
     try
     {
        Registry->RootKey = HKEY_LOCAL_MACHINE;
        if(Registry->OpenKey("SOFTWARE\\API测试程序",true))
        {
            AnsiString strHistoryFile=ChangeFileExt( Application->ExeName, ".INI");
            if(CheckBoxHide->Checked)
                Registry->WriteInteger("NextHide",1);
            else
                Registry->WriteInteger("NextHide",0);
            Registry->WriteInteger("SpyTime",m_iSpyTime);
            Registry->WriteString("HistoryFilePath",strHistoryFile.c_str());

        }
     }
    __finally
    {
        delete Registry;
        Registry=NULL;
    }
    if(Registry)
    {
        delete Registry;
        Registry=NULL;
    }
}
//---------------------------------------------------------------------------
void TMainForm::ReadReg(void)
{
    TRegistry *Registry = new TRegistry;
    try
    {
       Registry->RootKey = HKEY_LOCAL_MACHINE;
       if(Registry->OpenKey("SOFTWARE\\API测试程序",false))
       {
            bNextHide=Registry->ReadInteger("NextHide");
            m_iSpyTime=Registry->ReadInteger("SpyTime");

       }
    }
    __finally
    {
        delete Registry;
        Registry=NULL;
    }
    if(Registry)
    {
        delete Registry;

    }
}
//---------------------------------------------------------------------------
void TMainForm::DiasableCaptureWindow(void)
{
    
    if(ListBoxCapture->Items->Count>0)
    {
       char* CaptureWindow;
       HWND  WindowHandle;
       for(int i=0;i<ListBoxCapture->Items->Count;i++)
       {
            AnsiString Str=ListBoxCapture->Items->Strings[i];
            CaptureWindow=Str.c_str();
            WindowHandle=FindWindow(NULL,CaptureWindow);
            if(WindowHandle)
            {
               PostMessage(WindowHandle,WM_CLOSE,NULL,NULL);
            }
       }
    }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Timer1Timer(TObject *Sender)
{
   DiasableCaptureWindow();
}
//---------------------------------------------------------------------------

void TMainForm::RecordHwnd(void)
{
   if(!m_strOSPath.IsEmpty())
   {
        AnsiString strHWNDFile=ExtractFileDir(m_strOSPath);
        strHWNDFile+=AnsiString("ApiTestWHND.ini");
        TIniFile*  File;
        File=new TIniFile(strHWNDFile);
        File->WriteInteger("Form","HWND",(int)this->Handle);
        delete File;
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnClearSelectClick(TObject *Sender)
{
    ListBoxCapture->Items->Clear();
}
//---------------------------------------------------------------------------

