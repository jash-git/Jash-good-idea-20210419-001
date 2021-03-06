//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup1Click(TObject *Sender)
{
  switch (RadioGroup1->ItemIndex) {
    case 0:Label1->Font->Color=clBlue; break;
    case 1:Label1->Font->Color=clRed;  break;
  }
  Label1->Caption="我的性別是"+RadioGroup1->Items->Strings[RadioGroup1->ItemIndex];
  // RadioGroup1->Items->Strings[i] 取出RadioGroup第i個選項的字串內容
  // RadioGroup1->ItemIndex 是存放使用者點選RadioGroup的第幾項資料
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup2Click(TObject *Sender)
{
  Label2->Caption="我的工作部門是"+RadioGroup2->Items->Strings[RadioGroup2->ItemIndex];        
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  Label3->Font->Color=clYellow;
  Label3->Caption="你的嗜好是  ";
  if (CheckBox1->Checked==true) Label3->Caption=Label3->Caption+CheckBox1->Caption+"  ";
  if (CheckBox2->Checked==true) Label3->Caption=Label3->Caption+CheckBox2->Caption+"  ";
  if (CheckBox3->Checked==true) Label3->Caption=Label3->Caption+CheckBox3->Caption+"  ";
  if (CheckBox4->Checked==true) Label3->Caption=Label3->Caption+CheckBox4->Caption+"  ";
  if (CheckBox5->Checked==true) Label3->Caption=Label3->Caption+CheckBox5->Caption+"  ";
  if (CheckBox6->Checked==true) Label3->Caption=Label3->Caption+CheckBox6->Caption+"  ";
  if (CheckBox7->Checked==true) Label3->Caption=Label3->Caption+Edit1->Text;
  // CheckBox->Checked 是用來判斷此項CheckBox是否有被選到
}
//---------------------------------------------------------------------------
void __fastcall TForm2::CheckBox7Click(TObject *Sender)
{
  if (CheckBox7->Checked==true) Edit1->Enabled=True;
     else Edit1->Enabled=False;
  Edit1->SetFocus();
}
//---------------------------------------------------------------------------
