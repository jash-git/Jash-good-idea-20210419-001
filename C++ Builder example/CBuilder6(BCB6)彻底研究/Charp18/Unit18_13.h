
//---------------------------------------------------------------------------

#ifndef Unit18_13H
#define Unit18_13H
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBAdaptImg.hpp>
#include <DBTables.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>


//---------------------------------------------------------------------------
class TWebDataModule1 : public TWebDataModule
{
__published:	// IDE-managed Components
        TSession *Session1;
        TTable *Table1;
        TDataSetAdapter *DataSetAdapter1;
        TDataSetAdapterField *AdaptSpeciesNo;
        TDataSetAdapterField *AdaptCategory;
        TDataSetAdapterField *AdaptCommon_Name;
        TDataSetAdapterField *AdaptSpeciesName;
        TDataSetAdapterField *AdaptLengthcm;
        TDataSetAdapterField *AdaptLength_In;
        TDataSetAdapterDeleteRowAction *ActionDeleteRow;
        TDataSetAdapterFirstRowAction *ActionFirstRow;
        TDataSetAdapterPrevRowAction *ActionPrevRow;
        TDataSetAdapterNextRowAction *ActionNextRow;
        TDataSetAdapterLastRowAction *ActionLastRow;
        TDataSetAdapterEditRowAction *ActionEditRow;
        TDataSetAdapterBrowseRowAction *ActionBrowseRow;
        TDataSetAdapterNewRowAction *ActionNewRow;
        TDataSetAdapterCancelRowAction *ActionCancel;
        TDataSetAdapterApplyRowAction *ActionApply;
        TDataSetAdapterRefreshRowAction *ActionRefreshRow;
        TDataSetAdapterImageField *AdaptGraphic;
private:	// User declarations
public:		// User declarations
};

TWebDataModule1 *WebDataModule1();

//---------------------------------------------------------------------------
extern PACKAGE TWebDataModule1 *WebDataModule1();
//---------------------------------------------------------------------------
#endif

