//---------------------------------------------------------------------------
#ifndef Unit21_4H
#define Unit21_4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TChart *Chart1;
    TBarSeries *Series1;
    TButton *Button1;
    TButton *Button2;
    TTable *Table1;
    TIntegerField *Table1EmpNo;
    TStringField *Table1LastName;
    TStringField *Table1FirstName;
    TStringField *Table1PhoneExt;
    TDateTimeField *Table1HireDate;
    TFloatField *Table1Salary;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
