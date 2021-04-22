//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit10_32.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDM *DM;
//---------------------------------------------------------------------------
__fastcall TDM::TDM(TComponent* Owner)
        : TDataModule(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TDM::Query1UpdateRecord(TDataSet *DataSet,
      TUpdateKind UpdateKind, TUpdateAction &UpdateAction)
{
   DM->Query1->UpdateObject=UpdateEmployee;
   UpdateEmployee->SetParams(UpdateKind);
   UpdateEmployee->ExecSQL(UpdateKind);

   DM->Query1->UpdateObject=UpdateDepartment;
   UpdateDepartment->SetParams(UpdateKind);
   UpdateDepartment->ExecSQL(UpdateKind);

   UpdateAction=uaApplied;
}
//---------------------------------------------------------------------------
