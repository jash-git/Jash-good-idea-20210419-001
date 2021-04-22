//---------------------------------------------------------------------------
#include "Unit15_3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
__fastcall TWebModule1::TWebModule1(TComponent* Owner)
	: TWebModule(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TWebModule1::CInfoModuleWebActionItem1Action(
      TObject *Sender, TWebRequest *Request, TWebResponse *Response,
      bool &Handled)
{
  AnsiString temp1,temp2;

  Query1->Close();
  Query1->SQL->Clear();
  Query1->SQL->Add("select * from employee");
  temp1=Request->QueryFields->Values["fd"];		// 索引字段名称
  temp2="'"+Request->QueryFields->Values["vl"]+"%'";	// 查询索引字符串
  Query1->SQL->Add("where "+temp1+" like "+temp2);
  Query1->SQL->Add("order by Salary ");
  Query1->Prepare();
  Query1->Open();
  if (Query1->RecordCount==0) {
   DataSetTableProducer1->Footer->Add("<P>对不起，找不到您刚才输入的数据<P>");
   DataSetTableProducer1->Footer->Add("请你退回去，再输入条件重新查询<P>");
  }
  DataSetTableProducer1->MaxRows=Query1->RecordCount;
  DataSetTableProducer1->Footer->Add("</HTML>");
  Response->Content=DataSetTableProducer1->Content();
}
//---------------------------------------------------------------------------

