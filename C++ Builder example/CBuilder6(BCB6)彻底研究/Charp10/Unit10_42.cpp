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
        MessageBox(0, "你刚才输入的客户代码已经存在，请重新输入！", "警告" ,MB_OK);
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
        MessageBox(0, "你必须先删除关联到的订单数据，才能删除客户数据！"
                , "警告" ,MB_OK);
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
           MessageBox(0, "员工编号字段一定要输入，请再重新输入一遍！", "警告" ,MB_OK);
           return;
        case eKeyViol :
           MessageBox(0, "你刚才输入的员工编号已经存在，请重新输入！",
           "警告" ,MB_OK);
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
      MessageBox(0, "此产品编号并不存在", "警告" ,MB_OK);
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
         if (MessageBox(0, "确定要删除这笔订单?", "确认",
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

