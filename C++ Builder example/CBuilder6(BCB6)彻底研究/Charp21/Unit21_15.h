//---------------------------------------------------------------------------
#ifndef Unit21_15H
#define Unit21_15H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
#include <quickrpt.hpp>
#include <QuickRpt.hpp>
#include <DB.hpp>
#include <QRCtrls.hpp>
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQuery *Query1;
    TFloatField *Query1CustNo;
    TStringField *Query1Company;
    TStringField *Query1Addr1;
    TStringField *Query1Addr2;
    TStringField *Query1City;
    TStringField *Query1State;
    TStringField *Query1Zip;
    TStringField *Query1Country;
    TStringField *Query1Phone;
    TStringField *Query1FAX;
    TFloatField *Query1TaxRate;
    TStringField *Query1Contact;
    TDateTimeField *Query1LastInvoiceDate;
    TFloatField *Query1OrderNo;
    TFloatField *Query1CustNo_1;
    TDateTimeField *Query1SaleDate;
    TDateTimeField *Query1ShipDate;
    TIntegerField *Query1EmpNo;
    TStringField *Query1ShipToContact;
    TStringField *Query1ShipToAddr1;
    TStringField *Query1ShipToAddr2;
    TStringField *Query1ShipToCity;
    TStringField *Query1ShipToState;
    TStringField *Query1ShipToZip;
    TStringField *Query1ShipToCountry;
    TStringField *Query1ShipToPhone;
    TStringField *Query1ShipVIA;
    TStringField *Query1PO;
    TStringField *Query1Terms;
    TStringField *Query1PaymentMethod;
    TCurrencyField *Query1ItemsTotal;
    TFloatField *Query1TaxRate_1;
    TCurrencyField *Query1Freight;
    TCurrencyField *Query1AmountPaid;
    TFloatField *Query1OrderNo_1;
    TFloatField *Query1ItemNo;
    TFloatField *Query1PartNo;
    TIntegerField *Query1Qty;
    TFloatField *Query1Discount;
    TFloatField *Query1PartNo_1;
    TFloatField *Query1VendorNo;
    TStringField *Query1Description;
    TFloatField *Query1OnHand;
    TFloatField *Query1OnOrder;
    TCurrencyField *Query1Cost;
    TCurrencyField *Query1ListPrice;
    TQRGroup *QRGroup1;
    TQRDBText *QRDBText1;
    TQRLabel *QRLabel6;
    TQRGroup *QRGroup2;
    TQRExpr *QRExpr1;
    TQRExpr *QRExpr2;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRBand *DetailBand1;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText4;
    TQRDBText *QRDBText5;
    TQRBand *QRBand1;
    TQRExpr *QRExpr3;
    TQRLabel *QRLabel4;
    TQRBand *QRBand2;
    TQRExpr *QRExpr4;
    TQRLabel *QRLabel5;
    TQRChildBand *ChildBand1;
private:	// User declarations
public:		// User declarations
    __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
