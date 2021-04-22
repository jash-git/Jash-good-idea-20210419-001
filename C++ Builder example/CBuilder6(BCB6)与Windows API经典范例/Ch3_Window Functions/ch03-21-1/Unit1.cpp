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
}
//---------------------------------------------------------------------------
//建立一POP子窗口，以供检测
void __fastcall TForm1::FormShow(TObject *Sender)
{
form = new TForm(this);
form->Caption = "我是POP子窗口！";
form->Width = 250; form->Height = 100;
form->Top = Top+Height; form->Left = Left+30;
form->Color = (TColor)RGB(255,210,110);
form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete form;
}
//---------------------------------------------------------------------------




