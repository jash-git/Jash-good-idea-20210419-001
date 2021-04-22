//---------------------------------------------------------------------------
#ifndef Unit15_1H
#define Unit15_1H
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
        TDataSetTableProducer *DataSetTableProducer1;
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