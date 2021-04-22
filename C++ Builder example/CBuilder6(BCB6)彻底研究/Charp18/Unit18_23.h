
//---------------------------------------------------------------------------

#ifndef Unit18_23H
#define Unit18_23H
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
#include <WebAdapt.hpp>
#include <WebComp.hpp>
#include <MidItems.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TLogin : public TWebPageModule
{
__published:	// IDE-managed Components
	TAdapterPageProducer *AdapterPageProducer;
        TLoginFormAdapter *LoginFormAdapter1;
        TAdapterForm *AdapterForm1;
        TAdapterFieldGroup *AdapterFieldGroup1;
        TAdapterCommandGroup *AdapterCommandGroup1;
private:	// User declarations
public:		// User declarations
};

TLogin *Login();

//---------------------------------------------------------------------------
extern PACKAGE TLogin *Login();
//---------------------------------------------------------------------------
#endif

