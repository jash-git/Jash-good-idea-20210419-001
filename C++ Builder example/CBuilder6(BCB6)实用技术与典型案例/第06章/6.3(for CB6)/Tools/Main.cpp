//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include <Registry.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
char  OSPath[50];
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
    try
    {
        GetWindowsDirectory(OSPath,50);
        m_strOSPath=AnsiString(OSPath);

    }
    catch(...)
    {
        //int ErroCode=GetLastError();
    }
}
//---------------------------------------------------------------------------
void TMainForm::WriteReg(void)
{
     TRegistry *Registry = new TRegistry;
     try
     {
        Registry->RootKey = HKEY_LOCAL_MACHINE;
        if(Registry->OpenKey("SOFTWARE\\API²âÊÔ³ÌÐò",false))
        {
            if(CheckBox1->Checked)
                Registry->WriteInteger("NextHide",1);
            else
                Registry->WriteInteger("NextHide",0);
            m_iSpyTime=EdtInterval->Text.ToInt();
            Registry->WriteInteger("SpyTime",m_iSpyTime);

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
       if(Registry->OpenKey("SOFTWARE\\API²âÊÔ³ÌÐò",false))
       {
            m_bNextHide=Registry->ReadInteger("NextHide");
            m_strHistoryFile=Registry->ReadString("HistoryFilePath");
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
       // Registry=NULL;
    }
}
//---------------------------------------------------------------------------

void TMainForm::LoadHistoryInfo(void)
{
    if(FileExists(m_strHistoryFile))
        ListBoxCptureInfo->Items->LoadFromFile(m_strHistoryFile);
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormCreate(TObject *Sender)
{
    ReadReg();
    LoadHistoryInfo();
    CheckBox1->Checked=m_bNextHide;
    EdtInterval->Text=m_iSpyTime;
    ReadHwnd();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormClose(TObject *Sender, TCloseAction &Action)
{
    WriteReg();
    SaveHistoryFile();
        
}
//---------------------------------------------------------------------------

void TMainForm::SaveHistoryFile(void)
{
    ListBoxCptureInfo->Items->SaveToFile(m_strHistoryFile);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    ListBoxCptureInfo->Items->Clear();
}
//---------------------------------------------------------------------------

void TMainForm::ReadHwnd(void)
{
    if(!m_strOSPath.IsEmpty())
   {
        AnsiString strHWNDFile=ExtractFileDir(m_strOSPath);
        strHWNDFile+=AnsiString("ApiTestWHND.ini");
        TIniFile*  File;
        File=new TIniFile(strHWNDFile);
        m_APITestHwnd=(HWND)File->ReadInteger("Form","HWND",0);
        EdtHwn->Text=AnsiString((int)m_APITestHwnd);
        delete File;
   }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Button2Click(TObject *Sender)
{

    if(m_APITestHwnd)
        SendMessage(m_APITestHwnd,WM_CLOSE,NULL,NULL);
}
//---------------------------------------------------------------------------

