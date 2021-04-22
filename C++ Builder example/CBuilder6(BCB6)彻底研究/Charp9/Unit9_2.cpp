//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_2.h"
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
  bool FindSuccess;
  TLocateOptions SearchOptions;

  SearchOptions << loPartialKey;
  FindSuccess = False;
  switch(RadioGroup1->ItemIndex) {
    case 0:         // Locate查询方式
      FindSuccess = Table1->Locate("CustNo", Edit1->Text,
                    SearchOptions);
      break;
    case 1:         // GotoKey查询方式
      Table1->Close();
      Table1->IndexFieldNames="CustNo";
      Table1->Open();
      Table1->SetKey();
      Table1->FieldByName("CustNo")->AsString=Edit1->Text;
      FindSuccess = Table1->GotoKey();
      break;
    case 2:       // FindKey查询方式
      Table1->Close();
      Table1->IndexFieldNames="CustNo";
      Table1->Open();
      FindSuccess = Table1->FindKey(new TVarRec(Edit1->Text), 0);
      break;
    case 3:       // Filter查询方式
      Table1->Close();
      Table1->Filtered = True;
      Table1->Open();
      break;
  };
  if (FindSuccess) {
    DBGrid1->SetFocus();
    ShowMessage("找到了 !");
  } else ShowMessage("对不起,找不到 !!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Table1FilterRecord(TDataSet *DataSet, bool &Accept)
{
  // Filter查询条件判断式
  if (CompareStr(Table1->FieldByName("CustNo")->AsString,Edit1->Text)==0)
    Accept=True;
  else
    Accept=False;
}
//---------------------------------------------------------------------------

