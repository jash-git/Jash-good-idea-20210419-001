//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}

void initFunc()
{
  GUID appGuid;
  ::CLSIDFromString(WideString("{D0020F8E-18DF-41B6-8A2F-DAE39E2B7BC4}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "LoginDemo", "C++Builder WebBroker Application - 'LoginDemo'");
}
#pragma startup initFunc 31

 