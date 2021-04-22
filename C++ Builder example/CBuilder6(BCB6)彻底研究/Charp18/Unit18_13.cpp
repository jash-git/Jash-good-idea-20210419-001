
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_13.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TWebDataModule1 *WebDataModule1()
{
  return (TWebDataModule1*)WebContext()->FindModuleClass(__classid (TWebDataModule1));
}

static TWebDataModuleInit WebInit(__classid(TWebDataModule1), crOnDemand, caCache);
