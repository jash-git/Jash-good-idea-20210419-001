//---------------------------------------------------------------------------
#ifndef Unit9_9H
#define Unit9_9H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TDBLookupComboBox *DBLookupComboBox1;
        TStoredProc *StoredProc1;
        TTable *Table1;
        TStringField *Table1DEPT_NO;
        TStringField *Table1DEPARTMENT;
        TStringField *Table1HEAD_DEPT;
        TSmallintField *Table1MNGR_NO;
        TFloatField *Table1BUDGET;
        TStringField *Table1LOCATION;
        TStringField *Table1PHONE_NO;
        TDataSource *DataSource1;
        TDatabase *Database1;
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
