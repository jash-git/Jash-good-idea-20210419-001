//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ClientMain.h"
#include "IMyWS_Hello.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
 String str;
 str = GetIMyWS_Hello(true)->GetAString();
 ShowMessage(str);    
}
//---------------------------------------------------------------------------
