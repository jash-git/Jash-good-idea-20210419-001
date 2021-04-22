//---------------------------------------------------------------------------
#ifndef Unit11_2H
#define Unit11_2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBActns.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <MConnect.hpp>
#include <ToolWin.hpp>
#include <StdActns.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton7;
        TToolButton *ToolButton6;
        TPanel *Panel2;
        TDBGrid *DBGrid1;
        TDCOMConnection *DCOMConnection1;
        TClientDataSet *cdsCustomer;
        TDataSource *DataSource1;
        TActionList *ActionList1;
        TDataSetInsert *DataSetInsert1;
        TDataSetEdit *DataSetEdit1;
        TDataSetDelete *DataSetDelete1;
        TDataSetCancel *DataSetCancel1;
        TDataSetRefresh *DataSetRefresh1;
        TAction *Post;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall PostExecute(TObject *Sender);
        void __fastcall ToolButton6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
