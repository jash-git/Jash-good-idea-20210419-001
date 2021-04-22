//---------------------------------------------------------------------------
#ifndef Unit21_7H
#define Unit21_7H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Chart.hpp>
#include <Db.hpp>
#include <DBChart.hpp>
#include <DBCtrls.hpp>
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
    TAreaSeries *AreaSeries1;
    TDBGrid *DBGrid1;
    TPanel *Panel2;
    TDBNavigator *DBNavigator1;
    TBitBtn *BitBtn1;
    TDBGrid *DBGrid2;
    TDataSource *DataSource1;
    TTable *Table1;
    TFloatField *Table1CustNo;
    TStringField *Table1Company;
    TStringField *Table1City;
    TStringField *Table1Country;
    TStringField *Table1Phone;
    TStringField *Table1Addr1;
    TTable *Table2;
    TFloatField *Table2OrderNo;
    TFloatField *Table2CustNo;
    TDateTimeField *Table2SaleDate;
    TCurrencyField *Table2AmountPaid;
    TStringField *Table2PaymentMethod;
    TDateTimeField *Table2ShipDate;
    TDataSource *DataSource2;void __fastcall BitBtn1Click(TObject *Sender);
    void __fastcall DataSource1DataChange(TObject *Sender, TField *Field);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
