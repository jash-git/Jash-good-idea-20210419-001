//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_12.h"
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
Close();        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
Edit1->Text="";
Edit2->Text="";	
        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button3Click(TObject *Sender)
{
Edit1->Text="取消輸入";
Edit2->Text="取消輸入";
Close();
        
}
//---------------------------------------------------------------------------

