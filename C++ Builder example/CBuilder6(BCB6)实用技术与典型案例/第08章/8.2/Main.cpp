//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "SHDocVw_OCX"
#pragma resource "*.dfm"
TForm1 *Form1;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
     ProgressBar=new  TProgressBar(StatusBar1);
     ProgressBar->Top=5;
     ProgressBar->Left=210;
     ProgressBar->Height=StatusBar1->Height-10;
     ProgressBar->Width=150;
     ProgressBar->Parent=StatusBar1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BtnGotoClick(TObject *Sender)
{
    BOOL bExist=false;
    if(!CmbURL->Text.IsEmpty())
    {
        TVariant url(CmbURL->Text);
       CppWebBrowser1->Navigate2(&url);
        for(int i=0;i<CmbURL->Items->Count;i++)
        {
           if(CmbURL->Items->Strings[i]==CmbURL->Text)
              bExist=true;
        }
        if(!bExist)
            CmbURL->Items->Add(CmbURL->Text);
     }    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CmbURLKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
    if(Key==VK_RETURN)
        BtnGotoClick(this);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnBackClick(TObject *Sender)
{
    CppWebBrowser1->GoBack();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnForwardClick(TObject *Sender)
{
    CppWebBrowser1->GoForward();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnHomeClick(TObject *Sender)
{
     CppWebBrowser1->GoHome();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::BtnStopClick(TObject *Sender)
{
    CppWebBrowser1->Stop();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton5Click(TObject *Sender)
{
    CppWebBrowser1->Refresh();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CppWebBrowser1DownloadComplete(TObject *Sender)
{
   CmbURL->Text=CppWebBrowser1->LocationURL;
   StatusBar1->Panels->Items[0]->Text=AnsiString("连接完成:")+CmbURL->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CppWebBrowser1DownloadBegin(TObject *Sender)
{
   StatusBar1->Panels->Items[0]->Text=AnsiString("开始连接:")+CmbURL->Text;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::CppWebBrowser1ProgressChange(TObject *Sender,
      long Progress, long ProgressMax)
{
   ProgressBar->Max=ProgressMax;
   ProgressBar->Position=Progress;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
   delete ProgressBar;
}
//---------------------------------------------------------------------------

