//---------------------------------------------------------------------------
#include "Unit7_b.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TService1 *Service1;
//---------------------------------------------------------------------------
__fastcall TService1::TService1(TComponent* Owner)
	: TService(Owner)
{
}

TServiceController __fastcall TService1::GetServiceController(void)
{
	return (TServiceController) ServiceController;
}

void __stdcall ServiceController(unsigned CtrlCode)
{
	Service1->Controller(CtrlCode);
}
//---------------------------------------------------------------------------

void __fastcall TService1::ServiceExecute(TService *Sender)
{
  while (!Terminated) {
    Sleep(1000);
    Beep(1000,1000);
    ServiceThread->ProcessRequests(False);
  }        
}
//---------------------------------------------------------------------------
 