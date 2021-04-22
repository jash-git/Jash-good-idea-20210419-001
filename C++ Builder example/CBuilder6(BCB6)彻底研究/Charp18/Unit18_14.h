
//---------------------------------------------------------------------------

#ifndef Unit18_14H
#define Unit18_14H
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <HTTPProd.hpp>
#include <CompProd.hpp>
#include <HTTPApp.hpp>
#include <MidItems.hpp>
#include <PagItems.hpp>
#include <SiteProd.hpp>
#include <WebComp.hpp>
#include <WebForm.hpp>

//---------------------------------------------------------------------------
class TGrid : public TWebPageModule
{
__published:	// IDE-managed Components
	TAdapterPageProducer *AdapterPageProducer;
        TAdapterForm *AdapterForm1;
        TAdapterGrid *AdapterGrid1;
        TAdapterDisplayColumn *ColSpeciesNo;
        TAdapterDisplayColumn *ColCategory;
        TAdapterDisplayColumn *ColCommon_Name;
        TAdapterDisplayColumn *ColSpeciesName;
        TAdapterDisplayColumn *ColLengthcm;
        TAdapterDisplayColumn *ColLength_In;
        TAdapterDisplayColumn *ColGraphic;
        TAdapterCommandColumn *AdapterCommandColumn1;
        TAdapterActionButton *CmdEditRow;
private:	// User declarations
public:		// User declarations
};

TGrid *Grid();

//---------------------------------------------------------------------------
extern PACKAGE TGrid *Grid();
//---------------------------------------------------------------------------
#endif

