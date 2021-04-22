#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit10_42.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::CustomerPostError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eKeyViol)
     {
        MessageBox(0, "��ղ�����Ŀͻ������Ѿ����ڣ����������룡", "����" ,MB_OK);
        return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eDetailsExist)
     {
        MessageBox(0, "�������ɾ���������Ķ������ݣ�����ɾ���ͻ����ݣ�"
                , "����" ,MB_OK);
        return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerCustNoChange(TField *Sender)
{
   Orders->DisableControls();
   Items->DisableControls();
}
//---------------------------------------------------------------------
void __fastcall TDM::CustomerAfterPost(TDataSet *DataSet)
{
   DM->Orders->Refresh();
   DM->Items->Refresh();
   DM->Orders->EnableControls();
   DM->Items->EnableControls();
}
//---------------------------------------------------------------------
void __fastcall TDM::OrdersPostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action)
{
  int iDBIError;

  if (dynamic_cast<EDBEngineError*>(E) != 0)
  {
     iDBIError = dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode;

     switch (iDBIError)
     {
        case eRequiredFieldMissing :
           MessageBox(0, "Ա������ֶ�һ��Ҫ���룬������������һ�飡", "����" ,MB_OK);
           return;
        case eKeyViol :
           MessageBox(0, "��ղ������Ա������Ѿ����ڣ����������룡",
           "����" ,MB_OK);
           return;
     }
  }
}
//---------------------------------------------------------------------
void __fastcall TDM::ItemsPostError(TDataSet *DataSet, EDatabaseError *E,
      TDataAction &Action)
{
   if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eForeignKey)
   {
      MessageBox(0, "�˲�Ʒ��Ų�������", "����" ,MB_OK);
      return;
   }
}
//---------------------------------------------------------------------
void __fastcall TDM::OrdersDeleteError(TDataSet *DataSet,
      EDatabaseError *E, TDataAction &Action)
{
   if (dynamic_cast<EDBEngineError*>(E) != 0)
   {
      if (dynamic_cast<EDBEngineError*>(E)->Errors[0]->ErrorCode == eDetailsExist)
      {
         if (MessageBox(0, "ȷ��Ҫɾ����ʶ���?", "ȷ��",
            MB_YESNO) == IDYES)
         {
            while (Items->RecordCount > 0)
            {
               Items->Delete();
            }
            Action = daRetry;
         }
         else
         {
            return;
         }
      }
   }
}
//---------------------------------------------------------------------

