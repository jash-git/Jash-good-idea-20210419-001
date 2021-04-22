//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_4.h"
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
     AnsiString temp;

     temp="";
     Query1->Close();
     Query1->SQL->Clear();
     Query1->SQL->Add("Select * From Customer");
     temp=ComboBox1->Text;
     Query1->SQL->Add("Where "+temp+" Like '"+Edit1->Text+"%'");
     if (!Query1->Prepared) Query1->Prepare();
     Query1->Open();
}
//---------------------------------------------------------------------------
 