
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_12.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>

USEADDITIONALFILES("*.html");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

THome *Home()
{
  return (THome*)WebContext()->FindModuleClass(__classid (THome));
}

static TWebPageAccess PageAccess;
static TWebAppPageInit WebInit(__classid(THome), caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");
