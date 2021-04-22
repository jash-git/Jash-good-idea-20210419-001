
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit18_14.h"
#include <WebInit.h>
#include <WebReq.hpp>
#include <WebCntxt.hpp>
#include <WebFact.hpp>
#include "Unit18_13.h"

USEADDITIONALFILES("*.html");
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TGrid *Grid()
{
  return (TGrid*)WebContext()->FindModuleClass(__classid (TGrid));
}

static TWebPageAccess PageAccess;
static TWebPageInit WebInit(__classid(TGrid), crOnDemand, caCache, PageAccess << wpPublished /* << wpLoginRequired */, ".html", "", "", "", "");
