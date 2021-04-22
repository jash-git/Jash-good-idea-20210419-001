
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_24.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TWebDataModule4 *WebDataModule4()
{
  return (TWebDataModule4*)WebContext()->FindModuleClass(__classid (TWebDataModule4));
}

static TWebDataModuleInit WebInit(__classid(TWebDataModule4), crOnDemand, caCache);
