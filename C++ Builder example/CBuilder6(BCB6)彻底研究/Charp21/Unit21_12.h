//---------------------------------------------------------------------------
#ifndef Unit21_12H
#define Unit21_12H
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
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TQuickRep *QuickRep1;
    TQRBand *QRBand1;
    TQRLabel *QRLabel1;
    TQRSysData *QRSysData1;
    TQRLabel *QRLabel2;
    TQRBand *QRBand2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRBand *QRBand3;
    TQRDBText *QRDBText1;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText4;
    TQRDBText *QRDBText5;
    TQRBand *QRBand4;
    TQRLabel *QRLabel8;
    TQRSysData *QRSysData2;
    TTable *Table1;
    TFloatField *Table1CustNo;
    TStringField *Table1Company;
    TStringField *Table1Addr1;
    TStringField *Table1Addr2;
    TStringField *Table1City;
    TStringField *Table1State;
    TStringField *Table1Zip;
    TStringField *Table1Country;
    TStringField *Table1Phone;
    TStringField *Table1FAX;
    TFloatField *Table1TaxRate;
    TStringField *Table1Contact;
    TDateTimeField *Table1LastInvoiceDate;
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
