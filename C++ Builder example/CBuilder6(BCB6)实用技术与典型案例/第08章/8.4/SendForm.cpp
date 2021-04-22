//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SendForm.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TSMTPForm *SMTPForm;
//---------------------------------------------------------------------------
__fastcall TSMTPForm::TSMTPForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TSMTPForm::BtnSendClick(TObject *Sender)
{
    if(MainForm->NMSMTP1->Connected)
    {
       MainForm->NMSMTP1->SubType=mtPlain;
       switch(RadioGroup1->ItemIndex)
       {
            case 0:
               MainForm->NMSMTP1->EncodeType=uuMime;
               break;
            case 1:
               MainForm->NMSMTP1->EncodeType=uuCode;
               break;
       }
       MainForm->NMSMTP1->PostMessage->FromAddress=MainForm->EdtFromAddress->Text;
       MainForm->NMSMTP1->PostMessage->FromName=MainForm->EdtSMTPUser->Text;
       MainForm->NMSMTP1->PostMessage->Subject=EdtSubject->Text ;
       MainForm->NMSMTP1->PostMessage->ToAddress->Add(EdtToAddress->Text);
       MainForm->NMSMTP1->PostMessage->ToCarbonCopy->Add(EdtCarbonCopy->Text);
       MainForm->NMSMTP1->PostMessage->ToBlindCarbonCopy->Add(EdtBlindCopy->Text);
       MainForm->NMSMTP1->PostMessage->Attachments->AddStrings(ListBoxAttach->Items);
       MainForm->NMSMTP1->PostMessage->Body->Assign( MemoContent->Lines);
       MainForm->NMSMTP1->SendMail();
  }     
}
//---------------------------------------------------------------------------
void __fastcall TSMTPForm::BtnAddAttachClick(TObject *Sender)
{
    if(OpenDialog1->Execute())
        ListBoxAttach->Items->Add(OpenDialog1->FileName);
}
//---------------------------------------------------------------------------
void __fastcall TSMTPForm::BtnDeleteAttachClick(TObject *Sender)
{
    ListBoxAttach->Items->Delete(ListBoxAttach->ItemIndex);
}
//---------------------------------------------------------------------------
