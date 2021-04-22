#include <vcl.h>
#pragma hdrstop

#include "INTEREXPRESSSERIMPL.H"
#include "Unit16_1.h"

#if !defined(__PRAGMA_SMART_INIT_DEFINED)
#define __PRAGMA_SMART_INIT_DEFINED
#pragma package(smart_init)
#endif

#pragma resource "*.dfm"


/////////////////////////////////////////////////////////////////////////////
// Global instance of TInterExpressSerImpl 
/////////////////////////////////////////////////////////////////////////////
TInterExpressSer *InterExpressSer;


/////////////////////////////////////////////////////////////////////////////
// TInterExpressSer::TInterExpressSer
/////////////////////////////////////////////////////////////////////////////
__fastcall TInterExpressSer::TInterExpressSer(TComponent* Owner) : TCRemoteDataModule(Owner)
{
}

STDMETHODIMP TInterExpressSerImpl::QueryEmployee(BSTR DEPT_NO,
  BSTR FULL_NAME, VARIANT* ret)
{
  int i;
  InterExpressSer->qQueryEmployee->Close();
  InterExpressSer->qQueryEmployee->ParamByName("DEPT_NO")->AsString=(AnsiString)DEPT_NO+"%";
  InterExpressSer->qQueryEmployee->ParamByName("FULL_NAME")->AsString=(AnsiString)FULL_NAME+"%";
  InterExpressSer->qQueryEmployee->Open();
  InterExpressSer->qQueryEmployee->First();
  i=0;
  while (!InterExpressSer->qQueryEmployee->Eof) {
    InterExpressSer->qQueryEmployee->Next();
    i++;
  }
  InterExpressSer->qtpQueryEmployee->MaxRows=i;
  *ret=Variant(InterExpressSer->qtpQueryEmployee->Content());
}

STDMETHODIMP TInterExpressSerImpl::PostCountry(BSTR INPUT, VARIANT* ret)
{
   TStringList *TempList = new TStringList; // declare the list
   try{
     TempList->Text=(AnsiString)INPUT;
     InterExpressSer->qUpdate->Close();
     InterExpressSer->qUpdate->Params->Clear();
     InterExpressSer->qUpdate->SQL->Clear();
     InterExpressSer->qUpdate->SQL->Add("INSERT INTO COUNTRY(COUNTRY,CURRENCY) ");
     InterExpressSer->qUpdate->SQL->Add("VALUES(:COUNTRY,:CURRENCY)");
     InterExpressSer->qUpdate->ParamByName("COUNTRY")->Value=TempList->Values["COUNTRY"];
     InterExpressSer->qUpdate->ParamByName("CURRENCY")->Value=TempList->Values["CURRENCY"];
     try {
       InterExpressSer->qUpdate->ExecSQL();
       *ret = Variant("寫入成功");
     }
     catch (Exception &exception)
     {
       *ret = Variant("寫入失敗");
     }
   }
   __finally{
    delete TempList;
   }
}


STDMETHODIMP TInterExpressSerImpl::QueryCountry(VARIANT* ret)
{
    InterExpressSer->qCountry->Close();
    InterExpressSer->qCountry->Open();
    InterExpressSer->qtpCountry->MaxRows=InterExpressSer->qCountry->RecordCount;
    *ret=Variant(InterExpressSer->qtpCountry->Content());
}


