
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_15.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include "Unit18_13.h"

USEADDITIONALFILES("*.html");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TModify *Modify()
{
  return (TModify*)WebContext()->FindModuleClass(__classid (TModify));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TModify), crOnDemand, caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");
