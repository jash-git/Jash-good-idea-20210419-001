
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_25.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include "Unit18_24.h"

USEADDITIONALFILES("*.html");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TAfterLogin *AfterLogin()
{
  return (TAfterLogin*)WebContext()->FindModuleClass(__classid (TAfterLogin));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TAfterLogin), crOnDemand, caCache, PageAccess << wpPublished << wpLoginRequired, ".html", "", "", "", "");
