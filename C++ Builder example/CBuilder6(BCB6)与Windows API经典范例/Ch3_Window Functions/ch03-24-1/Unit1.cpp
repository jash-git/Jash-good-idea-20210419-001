//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//再次确定将本程序提到最前面
Application->OnActivate = AppActivate;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AppActivate(TObject *Sender)
{
Application->BringToFront();
}
// ---------------------------------------------------------------------------
