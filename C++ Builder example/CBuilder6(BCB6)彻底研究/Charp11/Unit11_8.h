//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1998 Borland International Inc.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit11_8H
#define Unit11_8H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <MConnect.hpp>
#include <MidasCon.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TBevel *Bevel1;
    TDBGrid *DBGrid1;
    TEdit *StartDate;
    TEdit *EndDate;
    TDBImage *DBImage1;
    TDBMemo *DBMemo1;
    TButton *ShowEvents;
    TDataSource *DataSource1;
    TClientDataSet *Events;
    TLabel *Label5;
        TDCOMConnection *DCOMConnection1;
    void __fastcall FormCreate(TObject *Sender);
    
    void __fastcall ShowEventsClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
