//---------------------------------------------------------------------------
#ifndef Unit7_bH
#define Unit7_bH
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <SvcMgr.hpp>
#include <vcl.h>
//---------------------------------------------------------------------------
class TService1 : public TService
{
__published:    // IDE-managed Components
        void __fastcall ServiceExecute(TService *Sender);
private:        // User declarations
public:         // User declarations
	__fastcall TService1(TComponent* Owner);
	TServiceController __fastcall GetServiceController(void);

	friend void __stdcall ServiceController(unsigned CtrlCode);
};
//---------------------------------------------------------------------------
extern PACKAGE TService1 *Service1;
//---------------------------------------------------------------------------
#endif
