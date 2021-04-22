//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit10_41H
#define Unit10_41H
//---------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Menus.hpp>
#include <vcl\DBCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\DBGrids.hpp>
#include <vcl\Grids.hpp>
//---------------------------------------------------------------------------
class TFmMain : public TForm
{
__published:	// IDE-managed Components 
        TDBNavigator *DBNavigator1;
        TLabel *Label1;
        TDBGrid *GridCustomers;
        TDBGrid *GridOrders;
        TLabel *Label3;
        TLabel *Label4;
        TDBGrid *GridItems;
	TButton *Button1;
    void __fastcall GridOrdersEnter(TObject *Sender);
    void __fastcall GridCustomersEnter(TObject *Sender);
    void __fastcall GridItemsEnter(TObject *Sender);
    void __fastcall GridCustomersExit(TObject *Sender);
    
	
	void __fastcall Button1Click(TObject *Sender);
        
private:	// User declarations
public:		// User declarations
        virtual __fastcall TFmMain(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern TFmMain *FmMain;
//---------------------------------------------------------------------------
#endif
