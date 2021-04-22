//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_4.h"
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

void __fastcall TForm2::Button1Click(TObject *Sender)
{
  ListBox1->Items->Add(Edit1->Text);
  Edit1->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
  int i;

  for(i=0;i<ListBox1->Items->Count;i++) {
    if (ListBox1->Selected[i]==True) {
      Memo1->Lines->Add("你选了第"+IntToStr(i+1)+"项!");
      ComboBox1->Items->Add(ListBox1->Items->Strings[i]);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
  Edit1->Text="";
  ComboBox1->Text="";
  ListBox1->Items->Clear();
  ComboBox1->Items->Clear();
  Memo1->Lines->Clear();
}
//---------------------------------------------------------------------------

