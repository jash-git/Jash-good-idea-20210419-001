//---------------------------------------------------------------------------
#ifndef Unit9_aH
#define Unit9_aH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
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
        TDBLookupComboBox *DBLookupComboBox1;
        TTable *Table1;
        TSmallintField *Table1EMP_NO;
        TStringField *Table1FIRST_NAME;
        TStringField *Table1LAST_NAME;
        TStringField *Table1PHONE_EXT;
        TDateTimeField *Table1HIRE_DATE;
        TStringField *Table1DEPT_NO;
        TStringField *Table1JOB_CODE;
        TSmallintField *Table1JOB_GRADE;
        TStringField *Table1JOB_COUNTRY;
        TFloatField *Table1SALARY;
        TStringField *Table1FULL_NAME;
        TQuery *Query1;
        TDatabase *Database1;
        TDataSource *DataSource1;
        TDataSource *DataSource2;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall DBLookupComboBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
