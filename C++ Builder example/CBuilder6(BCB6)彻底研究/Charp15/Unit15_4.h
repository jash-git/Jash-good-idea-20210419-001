//---------------------------------------------------------------------------
// Borland C++Builder
// Copyright (c) 1987, 1999 Inprise Corp.  All Rights Reserved.
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
#ifndef Unit15_4H
#define Unit15_4H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBWeb.hpp>
#include <SysInit.hpp>
#include <System.hpp>
#include <Controls.hpp>
#include <Dialogs.hpp>
#include <DSProd.hpp>
#include <Forms.hpp>
#include <Graphics.hpp>
#include <JPeg.hpp>
#include <Messages.hpp>
#include <Windows.hpp>
#include <DB.hpp>
#include <DBBdeWeb.hpp>
#include <HTTPProd.hpp>

//---------------------------------------------------------------------------
class TCInfoModule : public TWebModule
{
__published:	// IDE-managed Components
        TTable *Customer;
        TDataSource *CustSource;
        TQuery *Query1;
        TPageProducer *CustomerList;
        TQueryTableProducer *CustomerOrders;
        TFloatField *CustomerCustNo;
        TStringField *CustomerCompany;
        void __fastcall CustomerListHTMLTag(TObject *Sender, TTag Tag,
          const AnsiString TagString, TStrings *TagParams,
          AnsiString &ReplaceText);
        void __fastcall CustomerInfoModuleCustomerlistAction(
          TObject *Sender, TWebRequest *Request, TWebResponse *Response,
          bool &Handled);
        void __fastcall CustomerInfoModuleQueryActionAction(
          TObject *Sender, TWebRequest *Request, TWebResponse *Response,
          bool &Handled);
        void __fastcall CustInfoModCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCInfoModule(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCInfoModule *CInfoModule;
//---------------------------------------------------------------------------
#endif
