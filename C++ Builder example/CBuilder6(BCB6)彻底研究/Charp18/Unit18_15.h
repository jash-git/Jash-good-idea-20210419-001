
//---------------------------------------------------------------------------

#ifndef Unit18_15H
#define Unit18_15H
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
class TModify : public TWebPageModule
{
__published:	// IDE-managed Components
	TAdapterPageProducer *AdapterPageProducer;
        TAdapterForm *AdapterForm1;
        TAdapterFieldGroup *AdapterFieldGroup1;
        TAdapterCommandGroup *AdapterCommandGroup1;
        TAdapterDisplayField *FldSpeciesNo;
        TAdapterDisplayField *FldCategory;
        TAdapterDisplayField *FldCommon_Name;
        TAdapterDisplayField *FldSpeciesName;
        TAdapterDisplayField *FldLengthcm;
        TAdapterDisplayField *FldLength_In;
private:	// User declarations
public:		// User declarations
};

TModify *Modify();

//---------------------------------------------------------------------------
extern PACKAGE TModify *Modify();
//---------------------------------------------------------------------------
#endif

