//---------------------------------------------------------------------------
#ifndef Project12_6H
#define Project12_6H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <Provider.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TPanel *Panel2;
        TLabel *Label12;
        TLabel *Label13;
        TLabel *Label14;
        TPanel *Panel1;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit4;
        TDBEdit *DBEdit5;
        TDBEdit *DBEdit6;
        TDBEdit *DBEdit7;
        TDBEdit *DBEdit9;
        TDBEdit *DBEdit10;
        TDBEdit *DBEdit11;
        TDBGrid *DBGrid1;
        TDBNavigator *DBNavigator1;
        TDBEdit *DBEdit2;
        TDBNavigator *DBNavigator2;
        TDBEdit *DBEdit3;
        TDBEdit *DBTextShipMethod;
        TDataSource *CustDataSource;
        TQuery *CustQuery;
        TFloatField *CustQueryCustNo;
        TStringField *CustQueryCompany;
        TStringField *CustQueryAddr1;
        TStringField *CustQueryAddr2;
        TStringField *CustQueryCity;
        TStringField *CustQueryState;
        TStringField *CustQueryZip;
        TStringField *CustQueryCountry;
        TStringField *CustQueryPhone;
        TStringField *CustQueryFAX;
        TFloatField *CustQueryTaxRate;
        TStringField *CustQueryContact;
        TDateTimeField *CustQueryLastInvoiceDate;
        TQuery *OrderQuery;
        TClientDataSet *CustOrders;
        TFloatField *CustOrdersCustNo;
        TStringField *CustOrdersCompany;
        TStringField *CustOrdersAddr1;
        TStringField *CustOrdersAddr2;
        TStringField *CustOrdersCity;
        TStringField *CustOrdersState;
        TStringField *CustOrdersZip;
        TStringField *CustOrdersCountry;
        TStringField *CustOrdersPhone;
        TStringField *CustOrdersFAX;
        TFloatField *CustOrdersTaxRate;
        TStringField *CustOrdersContact;
        TDateTimeField *CustOrdersLastInvoiceDate;
        TDataSetField *CustOrdersOrderQuery;
        TDataSource *CustOrdersDataSource;
        TDataSource *OrderDSDataSource;
        TClientDataSet *OrderDS;
        TFloatField *OrderDSOrderNo;
        TStringField *OrderDSShipVIA;
        TCurrencyField *OrderDSItemsTotal;
        TDateTimeField *OrderDSSaleDate;
        TDateTimeField *OrderDSShipDate;
        TStringField *OrderDSPaymentMethod;
        TFloatField *OrderDSTaxRate;
        TAggregateField *OrderDSTotalPerCustomer;
        TAggregateField *OrderDSOrderTotalPerShipMethod;
        TDataSetProvider *DataSetProvider1;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
