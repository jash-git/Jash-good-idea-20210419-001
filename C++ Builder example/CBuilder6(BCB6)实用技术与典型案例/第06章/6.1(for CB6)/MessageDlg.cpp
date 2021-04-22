//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "MessageDlg.h"
#include "Main.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMessageForm *MessageForm;
//---------------------------------------------------------------------------
__fastcall TMessageForm::TMessageForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TMessageForm::BtnCloseClick(TObject *Sender)
{
      Close();
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::BtnLeftClick(TObject *Sender)
{
    SendMessage(MainForm->Handle,WM_MYMESSAGE,LEFTBUTTON,0);
}
//---------------------------------------------------------------------------
void __fastcall TMessageForm::BtnRightClick(TObject *Sender)
{
    SendMessage(MainForm->Handle,WM_MYMESSAGE,RIGHTBUTTON,0);
}
//---------------------------------------------------------------------------
