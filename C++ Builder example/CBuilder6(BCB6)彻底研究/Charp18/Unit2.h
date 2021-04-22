
//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
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
#include <WebSess.hpp>
#include <WebUsers.hpp>

//---------------------------------------------------------------------------
class THome : public TWebAppPageModule
{
__published:	// IDE-managed Components
	TPageProducer *PageProducer;
	TWebAppComponents *WebAppComponents;
	TApplicationAdapter *ApplicationAdapter;
	TEndUserSessionAdapter *EndUserSessionAdapter;
	TPageDispatcher *PageDispatcher;
	TAdapterDispatcher *AdapterDispatcher;
	TSessionsService *SessionsService;
	TWebUserList *WebUserList;
private:	// User declarations
public:		// User declarations
};

THome *Home();

//---------------------------------------------------------------------------
extern PACKAGE THome *Home();
//---------------------------------------------------------------------------
#endif

