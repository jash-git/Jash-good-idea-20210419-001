//---------------------------------------------------------------------------
#ifndef Unit15_2H
#define Unit15_2H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBWeb.hpp>
#include <DB.hpp>
#include <DBBdeWeb.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        TQueryTableProducer *CustomerOrders;
        TTable *Table1;
        TIntegerField *Table1EmpNo;
        TStringField *Table1LastName;
        TStringField *Table1FirstName;
        TStringField *Table1PhoneExt;
        TDateTimeField *Table1HireDate;
        TFloatField *Table1Salary;
        void __fastcall CInfoModuleWebActionItem1Action(TObject *Sender,
          TWebRequest *Request, TWebResponse *Response, bool &Handled);
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
