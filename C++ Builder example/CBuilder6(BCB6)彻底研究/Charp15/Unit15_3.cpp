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
  temp1=Request->QueryFields->Values["fd"];		// �����ֶ�����
  temp2="'"+Request->QueryFields->Values["vl"]+"%'";	// ��ѯ�����ַ���
  Query1->SQL->Add("where "+temp1+" like "+temp2);
  Query1->SQL->Add("order by Salary ");
  Query1->Prepare();
  Query1->Open();
  if (Query1->RecordCount==0) {
   DataSetTableProducer1->Footer->Add("<P>�Բ����Ҳ������ղ����������<P>");
   DataSetTableProducer1->Footer->Add("�����˻�ȥ���������������²�ѯ<P>");
  }
  DataSetTableProducer1->MaxRows=Query1->RecordCount;
  DataSetTableProducer1->Footer->Add("</HTML>");
  Response->Content=DataSetTableProducer1->Content();
}
//---------------------------------------------------------------------------

