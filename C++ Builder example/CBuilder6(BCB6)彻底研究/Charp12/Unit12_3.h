//---------------------------------------------------------------------------
#ifndef Unit12_3H
#define Unit12_3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <MConnect.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TButton *Button1;
        TCheckBox *CheckBox1;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TButton *Button2;
        TButton *Button3;
        TDCOMConnection *DCOMConnection1;
        TClientDataSet *ClientDataSet1;
        TDataSource *DataSource1;
        TActionList *ActionList1;
        TAction *Action1;
        TAction *Action2;
        TClientDataSet *ClientDataSet2;
        TDCOMConnection *DCOMConnection2;
        TDataSource *DataSource2;
        void __fastcall Action1Update(TObject *Sender);
        void __fastcall Action2Update(TObject *Sender);
        void __fastcall Action2Execute(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall CheckBox1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
