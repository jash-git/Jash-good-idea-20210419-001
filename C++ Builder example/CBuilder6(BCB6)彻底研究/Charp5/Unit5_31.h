//---------------------------------------------------------------------------
#ifndef Unit5_31H
#define Unit5_31H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TDatabase *Database1;
        TTable *Table1;
        TDataSource *DataSource1;
        TTable *Table2;
        TDataSource *DataSource2;
        TMainMenu *MainMenu1;
        TMenuItem *F1;
        TMenuItem *O1;
        TMenuItem *O2;
        TMenuItem *S2;
        TMenuItem *N12;
        TMenuItem *N13;
        TMenuItem *N1;
        TMenuItem *N3;
        TMenuItem *P1;
        TMenuItem *N2;
        TMenuItem *E2;
        TMenuItem *E1;
        TMenuItem *U1;
        TMenuItem *N4;
        TMenuItem *C1;
        TMenuItem *C2;
        TMenuItem *P2;
        TMenuItem *L1;
        TMenuItem *N5;
        TMenuItem *N6;
        TMenuItem *N7;
        TMenuItem *H1;
        TMenuItem *N10;
        TMenuItem *N11;
        TMenuItem *A2;
        void __fastcall A2Click(TObject *Sender);
        void __fastcall Logo1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
