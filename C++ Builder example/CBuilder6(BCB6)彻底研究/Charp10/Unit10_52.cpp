//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_52.h"
#include "Unit10_51.h"
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
     Form1->Database1->LoginPrompt=false;
     Form1->Database1->Params->Values["USER NAME"]=Edit1->Text;
     Form1->Database1->Params->Values["PASSWORD"]=Edit2->Text;
     try {
       Form1->Database1->Connected=true;
     } catch ( ... ) {
       ShowMessage("连接失败!!可能是用户名和密码有误。");
     }

     Form1->Table1->Active=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{
     Close();
}
//---------------------------------------------------------------------------
