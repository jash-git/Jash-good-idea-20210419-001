
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>

USEADDITIONALFILES("*.html");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TLogin *Login()
{
  return (TLogin*)WebContext()->FindModuleClass(__classid (TLogin));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TLogin), crOnDemand, caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");
 