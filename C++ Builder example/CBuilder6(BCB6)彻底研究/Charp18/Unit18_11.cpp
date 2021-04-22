//---------------------------------------------------------------------------
#define NO_WIN32_LEAN_AND_MEAN
#include <vcl.h>
#pragma hdrstop
#include "Unit18_11.h"
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
  ::CLSIDFromString(WideString("{38439535-611D-4CFC-AA14-1DC0B1B0A50E}").c_bstr(), &appGuid);
  InitCOMAppFactory(appGuid, "WebSnapDemo1", "C++Builder WebBroker Application - 'WebSnapDemo1'");
}
#pragma startup initFunc 31

