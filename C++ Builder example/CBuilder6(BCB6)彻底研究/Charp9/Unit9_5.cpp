//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_5.h"
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
     Query1->Close();
     Query1->SQL->Clear();
     Query1->SQL->Add("select CustNo,Company,Addr1 from Customer");


     Query1->SQL->Add("where Company like :Q1 and Addr1 like :Q2");

     
     Query1->ParamByName("Q1")->AsString=Edit1->Text+"%";
     Query1->ParamByName("Q2")->AsString=Edit2->Text+"%";

     if (Query1->Prepared==false) Query1->Prepare();
     Query1->Open();
}
//---------------------------------------------------------------------------
 