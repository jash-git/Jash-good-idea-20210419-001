//----------------------------------------------------------------------------
//Borland C++Builder
//Copyright (c) 1987, 1997 Borland International Inc. All Rights Reserved.
//----------------------------------------------------------------------------
//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit10_41.h"
#include "Unit10_42.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TFmMain *FmMain;
//---------------------------------------------------------------------------
__fastcall TFmMain::TFmMain(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFmMain::GridOrdersEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->OrdersSource;
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridCustomersEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->CustomerSource;
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridItemsEnter(TObject *Sender)
{
	DBNavigator1->DataSource = DM->ItemsSource;  
}
//---------------------------------------------------------------------
void __fastcall TFmMain::GridCustomersExit(TObject *Sender)
{
	if (DM->Customer->State == dsEdit || DM->Customer->State == dsInsert)
    {
    	DM->Customer->Post();
    }
}
//---------------------------------------------------------------------
void __fastcall TFmMain::Button1Click(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

