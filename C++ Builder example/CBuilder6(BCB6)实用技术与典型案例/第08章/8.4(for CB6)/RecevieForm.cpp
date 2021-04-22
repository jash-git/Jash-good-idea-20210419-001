//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "RecevieForm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPOP3Form *POP3Form;
//---------------------------------------------------------------------------
__fastcall TPOP3Form::TPOP3Form(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void TPOP3Form::SetMailCount(int Count)
{
    AnsiString sTemp;
    sTemp.sprintf("����%d���ʼ�",Count);
    EdtMailCount->Text=sTemp;

}
//---------------------------------------------------------------------------

void TPOP3Form::ListMail(int Msg, int Size)
{
    AnsiString sTemp;
    if (Msg < 2)
        ListBoxMail->Clear();
    sTemp.sprintf("��%d�⣺(��%d���ֽ�)",Msg,Size);
    ListBoxMail->Items->Add(sTemp);
}
//---------------------------------------------------------------------------

void __fastcall TPOP3Form::ListBoxMailClick(TObject *Sender)
{
    int iIndex;
    iIndex=ListBoxMail->ItemIndex+1;
    EdtMailName->Text=AnsiString("��")+AnsiString(iIndex)+AnsiString("���ʼ�");
    MainForm->NMPOP31->GetMailMessage(iIndex);
    EdtFrom->Text=MainForm->NMPOP31->MailMessage->From;
    EdtSubject->Text=MainForm->NMPOP31->MailMessage->Subject;
    MemoHead->Lines->Assign(MainForm->NMPOP31->MailMessage->Head);
    MemoContent->Lines->Assign(MainForm->NMPOP31->MailMessage->Body);
    MainForm->NMPOP31->GetSummary(iIndex);
    EdtSize->Text=MainForm->NMPOP31->Summary->Bytes;
    EdtMailID->Text=MainForm->NMPOP31->Summary->MessageId;
    if (MainForm->NMPOP31->MailMessage->Attachments->Text != "")
       MemoAttach->Text=MainForm->NMPOP31->MailMessage->Attachments->Text;
}
//---------------------------------------------------------------------------


