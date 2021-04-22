//---------------------------------------------------------------------------
#ifndef Unit9_3H
#define Unit9_3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TDBGrid *DBGrid1;
        TEdit *Edit1;
        TButton *Button1;
        TTable *Table1;
        TFloatField *Table1CustNo;
        TStringField *Table1Company;
        TStringField *Table1Addr1;
        TDataSource *DataSource1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Table1FilterRecord(TDataSet *DataSet,
      bool &Accept);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
