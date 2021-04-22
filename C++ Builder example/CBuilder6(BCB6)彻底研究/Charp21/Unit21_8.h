//---------------------------------------------------------------------------
#ifndef Unit21_8H
#define Unit21_8H
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
    TBarSeries *BarSeries1;
    TPanel *Panel1;
    TBitBtn *BitBtn1;
    TPanel *Panel2;
    TLabel *Label1;
    TMemo *Memo1;
    TBitBtn *BitBtn2;
    TComboBox *ComboBox1;
    TPanel *Panel3;
    TLabel *Label2;
    TDBGrid *DBGrid1;
    TDataSource *DataSource1;
    TQuery *Query1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall BitBtn2Click(TObject *Sender);
    void __fastcall ComboBox1Change(TObject *Sender);
    void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
