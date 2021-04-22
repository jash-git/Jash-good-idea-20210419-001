//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit9_8.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  Query1->Close();
  Query1->SQL->Clear();
  Query1->Params->Clear();
  Query1->SQL->Add("SELECT * FROM COUNTRY ");
  Query1->SQL->Add("ORDER BY COUNTRY ");
  Query1->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn4Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
  try
  {
    Query1->Close();
    Query1->SQL->Clear();
    Query1->Params->Clear();
    Query1->SQL->Add("INSERT INTO COUNTRY (COUNTRY, CURRENCY) ");
    Query1->SQL->Add("VALUES (:COUNTRY, :CURRENCY) ");
    Query1->ParamByName("COUNTRY")->AsString=Edit1->Text;
    Query1->ParamByName("CURRENCY")->AsString=Edit2->Text;
    Query1->ExecSQL();
    FormCreate(Sender);
    MessageDlg("写入成功！",mtInformation,TMsgDlgButtons() << mbOK,0);
  } catch (...) {
    MessageDlg("写入失败！",mtError,TMsgDlgButtons() << mbOK,0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn2Click(TObject *Sender)
{
  try
  {
    Query1->Close();
    Query1->SQL->Clear();
    Query1->Params->Clear();
    Query1->SQL->Add("UPDATE COUNTRY SET CURRENCY=:CURRENCY ");
    Query1->SQL->Add("WHERE COUNTRY=:COUNTRY ");
    Query1->ParamByName("COUNTRY")->AsString=Edit1->Text;
    Query1->ParamByName("CURRENCY")->AsString=Edit2->Text;
    Query1->ExecSQL();
    FormCreate(Sender);
    MessageDlg("写入成功！",mtInformation,TMsgDlgButtons() << mbOK,0);
  } catch (...) {
    MessageDlg("写入失败！",mtError,TMsgDlgButtons() << mbOK,0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::BitBtn3Click(TObject *Sender)
{
  if (MessageDlg("确定要删除？",mtConfirmation,TMsgDlgButtons() << mbYes << mbNo,0)==mrYes)
  {
    try
    {
      Query1->Close();
      Query1->SQL->Clear();
      Query1->Params->Clear();
      Query1->SQL->Add("DELETE FROM COUNTRY ");
      Query1->SQL->Add("WHERE COUNTRY=:COUNTRY ");
      Query1->ParamByName("COUNTRY")->AsString=Edit1->Text;
      Query1->ExecSQL();
      FormCreate(Sender);
      MessageDlg("写入成功！",mtInformation,TMsgDlgButtons() << mbOK,0);
    } catch (...) {
      MessageDlg("写入失败！",mtError,TMsgDlgButtons() << mbOK,0);
    }
  }
}
//---------------------------------------------------------------------------

