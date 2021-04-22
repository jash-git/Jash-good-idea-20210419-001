
//---------------------------------------------------------------------------

#ifndef Unit18_24H
#define Unit18_24H
//---------------------------------------------------------------------------
#include <WebInit.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <WebModu.hpp>
#include <DB.hpp>
#include <DBAdapt.hpp>
#include <DBTables.hpp>
#include <WebAdapt.hpp>
#include <WebComp.hpp>


//---------------------------------------------------------------------------
class TWebDataModule4 : public TWebDataModule
{
__published:	// IDE-managed Components
        TSession *Session1;
        TTable *Table1;
        TDataSetAdapter *DataSetAdapter1;
        TDataSetAdapterField *AdaptEmpNo;
        TDataSetAdapterField *AdaptLastName;
        TDataSetAdapterField *AdaptFirstName;
        TDataSetAdapterField *AdaptPhoneExt;
        TDataSetAdapterField *AdaptHireDate;
        TDataSetAdapterField *AdaptSalary;
private:	// User declarations
public:		// User declarations
};

TWebDataModule4 *WebDataModule4();

//---------------------------------------------------------------------------
extern PACKAGE TWebDataModule4 *WebDataModule4();
//---------------------------------------------------------------------------
#endif

