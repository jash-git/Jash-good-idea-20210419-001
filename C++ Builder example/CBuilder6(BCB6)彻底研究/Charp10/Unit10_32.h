//---------------------------------------------------------------------------
#ifndef Unit10_32H
#define Unit10_32H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TDM : public TDataModule
{
__published:	// IDE-managed Components
        TDatabase *Database1;
        TQuery *Query1;
        TUpdateSQL *UpdateEmployee;
        TUpdateSQL *UpdateDepartment;
        void __fastcall Query1UpdateRecord(TDataSet *DataSet,
      TUpdateKind UpdateKind, TUpdateAction &UpdateAction);
private:	// User declarations
public:		// User declarations
        __fastcall TDM(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TDM *DM;
//---------------------------------------------------------------------------
#endif
