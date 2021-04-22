//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_7.h"
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

void __fastcall TForm1::DBLookupComboBox1Click(TObject *Sender)
{

     Query1->Close();
     Query1->SQL->Clear();
     Query1->SQL->Add("Select * from Orders");
     Query1->SQL->Add("where CustNo=:CustNo");
     
     Query1->ParamByName("CustNo")->AsInteger=Table1CustNo->AsInteger;
     if (Query1->Prepared==false) Query1->Prepare();
     Query1->Open();
}
//---------------------------------------------------------------------------
 