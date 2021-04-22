//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit11_6H
#define Unit11_6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <MConnect.hpp>
#include <MidasCon.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TBevel *Bevel1;
        TMemo *SQL;
        TComboBox *DatabaseName;
        TButton *RunButton;
        TDBGrid *DBGrid1;
        TDataSource *DataSource1;
        TClientDataSet *ClientDataSet;
    TLabel *Label2;
    TLabel *Label3;
        TDCOMConnection *DCOMConnection1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall RunButtonClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall DatabaseNameClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
   