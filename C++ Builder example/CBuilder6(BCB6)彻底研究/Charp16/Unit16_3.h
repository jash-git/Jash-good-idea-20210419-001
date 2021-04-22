//---------------------------------------------------------------------------
#ifndef Unit16_3H
#define Unit16_3H
//---------------------------------------------------------------------------
#include <SysUtils.hpp>
#include <Classes.hpp>
#include <HTTPApp.hpp>
#include <CompProd.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <HTTPProd.hpp>
#include <MConnect.hpp>
#include <MidProd.hpp>
#include <PagItems.hpp>
#include <SConnect.hpp>
#include <XMLBrokr.hpp>
#include <MidItems.hpp>
#include <WebComp.hpp>
//---------------------------------------------------------------------------
class TWebModule1 : public TWebModule
{
__published:	// IDE-managed Components
        TSocketConnection *SocketConnection1;
        TXMLBroker *XMLBroker1;
        TInetXPageProducer *InetXPageProducer1;
        TDataForm *DataForm1;
        TDataGrid *DataGrid1;
        TDataGrid *DataGrid2;
        TDataNavigator *DataNavigator1;
        TDataNavigator *DataNavigator2;
private:	// User declarations
public:		// User declarations
	__fastcall TWebModule1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TWebModule1 *WebModule1;
//---------------------------------------------------------------------------
#endif
