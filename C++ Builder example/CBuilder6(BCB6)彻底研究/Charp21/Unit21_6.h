//---------------------------------------------------------------------------
#ifndef Unit21_6H
#define Unit21_6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <Db.hpp>
#include <DBChart.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Series.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <DB.hpp>
#include <DbChart.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TDBChart *DBChart1;
    TPieSeries *PieSeries1;
    TPanel *Panel2;
    TDBGrid *DBGrid1;
    TRadioGroup *RadioGroup1;
    TBitBtn *BitBtn1;
    TTable *Table1;
    TStringField *Table1NAME;
    TSmallintField *Table1SIZE;
    TSmallintField *Table1WEIGHT;
    TDataSource *DataSource1;
    void __fastcall RadioGroup1Click(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
