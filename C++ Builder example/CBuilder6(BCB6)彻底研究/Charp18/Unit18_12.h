
//---------------------------------------------------------------------------

#ifndef Unit18_12H
#define Unit18_12H
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <ReqMulti.hpp>
#include <HTTPApp.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <WebDisp.hpp>

//---------------------------------------------------------------------------
class THome : public TWebAppPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
	TWebAppComponents *WebAppComponents;
	TApplicationAdapter *ApplicationAdapter;
	TPageDispatcher *PageDispatcher;
	TAdapterDispatcher *AdapterDispatcher;
private:	// User declarations
public:		// User declarations
};

THome *Home();

//---------------------------------------------------------------------------
extern PACKAGE THome *Home();
//---------------------------------------------------------------------------
#endif

