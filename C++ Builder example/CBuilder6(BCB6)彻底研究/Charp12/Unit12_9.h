//---------------------------------------------------------------------------
#ifndef Unit12_9H
#define Unit12_9H
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
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TCoolBar *CoolBar1;
        TToolBar *ToolBar1;
        TToolButton *ToolButton7;
        TToolButton *ToolButton8;
        TToolButton *ToolButton9;
        TToolButton *ToolButton10;
        TToolButton *ToolButton1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
        TPanel *Panel2;
        TDBGrid *DBGrid1;
        TDCOMConnection *DCOMConnection1;
        TClientDataSet *cdsCustomer;
        TDataSource *dsCustomer;
        TActionList *ActionList1;
        TDataSetInsert *Insert1;
        TDataSetEdit *Edit1;
        TDataSetDelete *Delete1;
        TDataSetCancel *Cancel1;
        TAction *CloseAction;
        TDataSetFirst *First1;
        TDataSetPrior *Prior1;
        TDataSetNext *Next1;
        TDataSetLast *Last1;
        TAction *ApplyUpdate;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall CloseActionExecute(TObject *Sender);
        void __fastcall ApplyUpdateExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
