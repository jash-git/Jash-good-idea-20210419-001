
//---------------------------------------------------------------------------

#ifndef Unit18_25H
#define Unit18_25H
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <CompProd.hpp>
#include <HTTPApp.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <MidItems.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TAfterLogin : public TWebPageModule
{
__published:	// IDE-managed Components
	TAdapterPageProducer *AdapterPageProducer;
        TAdapterForm *AdapterForm1;
        TAdapterGrid *AdapterGrid1;
private:	// User declarations
public:		// User declarations
};

TAfterLogin *AfterLogin();

//---------------------------------------------------------------------------
extern PACKAGE TAfterLogin *AfterLogin();
//---------------------------------------------------------------------------
#endif

