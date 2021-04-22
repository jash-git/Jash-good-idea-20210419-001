//---------------------------------------------------------------------------
#ifndef Unit12_6H
#define Unit12_6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
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
        TDBGrid *DBGrid1;
        TDCOMConnection *DCOMConnection1;
        TClientDataSet *ClientDataSet1;
        TDataSource *DataSource1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall DCOMConnection1Login(TObject *Sender,
          AnsiString Username, AnsiString Password);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
