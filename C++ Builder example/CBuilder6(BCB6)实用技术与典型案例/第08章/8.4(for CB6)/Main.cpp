//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "RecevieForm.h"
#include "SendForm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnSMTPConnectClick(TObject *Sender)
{
  /* for(int i=0;i<ComponentCount;i++)
   {
     TControl *Temp;
     if (Temp=dynamic_cast<TControl *>(Components[i]))
         Temp->Cursor=crHourGlass;
   } */
   this->Cursor=crHourGlass;
   NMSMTP1->Host=EdtSMTPServer->Text;
   NMSMTP1->Port=EdtSMTPPort->Text.ToInt();
   NMSMTP1->UserID=EdtSMTPUser->Text ;
   NMSMTP1->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMSMTP1Connect(TObject *Sender)
{
  /* for(int i=0;i<ComponentCount;i++)
   {
     TControl *Temp;
     if (Temp=dynamic_cast<TControl *>(Components[i]))
         Temp->Cursor=crDefault;
    }   */
    this->Cursor=crDefault;
    AnsiString sTemp;
    sTemp.sprintf("与SMTP服务器%s连接成功!",EdtSMTPServer->Text);
    StatusBar1->Panels->Items[0]->Text=sTemp;
    SMTPForm->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnPop3ConnectClick(TObject *Sender)
{
   /* for(int i=0;i<ComponentCount;i++)
    {
      TControl *Temp;
      if (Temp=dynamic_cast<TControl *>(Components[i]))
         Temp->Cursor=crHourGlass;
    } */
    this->Cursor=crHourGlass;
    NMPOP31->AttachFilePath = ".";
    NMPOP31->DeleteOnRead = false;
    NMPOP31->ReportLevel = Status_Basic;
    NMPOP31->TimeOut = 20000;
    NMPOP31->Host=EdtPop3Server->Text;
    NMPOP31->Port=EdtPop3Port->Text.ToInt();
    NMPOP31->Password=EdtPop3Password->Text;
    NMPOP31->UserID=EdtPop3User->Text;
    NMPOP31->Connect();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMPOP31Connect(TObject *Sender)
{
   /* for(int i=0;i<ComponentCount;i++)
    {
      TControl *Temp;
      if (Temp=dynamic_cast<TControl *>(Components[i]))
         Temp->Cursor=crDefault;
    } */
    this->Cursor=crDefault;
    AnsiString sTemp;
    sTemp.sprintf("与POP3服务器%s连接成功!",EdtSMTPServer->Text);
    StatusBar1->Panels->Items[1]->Text=sTemp;
    POP3Form->SetMailCount(NMPOP31->MailCount);
    NMPOP31->List();
    BtnReciveMailClick(this);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnPop3DisConnectClick(TObject *Sender)
{
    if(NMPOP31->Connected)
        NMPOP31->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnReciveMailClick(TObject *Sender)
{
    POP3Form->ShowModal();       
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMPOP31Disconnect(TObject *Sender)
{
    AnsiString sTemp;
    sTemp.sprintf("与POP3服务器%s断开连接!",EdtSMTPServer->Text);
    StatusBar1->Panels->Items[1]->Text=sTemp;
   
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMPOP31List(int Msg, int Size)
{
    POP3Form->ListMail(Msg,Size);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnSMTPDisCloseClick(TObject *Sender)
{
    if(NMSMTP1->Connected)
       NMSMTP1->Disconnect();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMPOP31RetrieveStart(TObject *Sender)
{
   this->Cursor= crHourGlass;    
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMPOP31RetrieveEnd(TObject *Sender)
{
     this->Cursor= crDefault;     
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::NMSMTP1Disconnect(TObject *Sender)
{
    AnsiString sTemp;
    sTemp.sprintf("与SMTP服务器%s断开连接!",EdtSMTPServer->Text);
    StatusBar1->Panels->Items[0]->Text=sTemp;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnCloseClick(TObject *Sender)
{
    Close();    
}
//---------------------------------------------------------------------------

