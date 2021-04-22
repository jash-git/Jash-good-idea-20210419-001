//---------------------------------------------------------------------------
#ifndef Unit9_1H
#define Unit9_1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn9;
        TTable *Table1;
        TFloatField *Table1CustNo;
        TStringField *Table1Company;
        TStringField *Table1Addr1;
        TStringField *Table1Phone;
        TStringField *Table1FAX;
        TStringField *Table1Contact;
        TLabel *Label1;
        TDBEdit *DBEdit1;
        TLabel *Label2;
        TDBEdit *DBEdit2;
        TLabel *Label3;
        TDBEdit *DBEdit3;
        TLabel *Label4;
        TDBEdit *DBEdit4;
        TLabel *Label5;
        TDBEdit *DBEdit5;
        TLabel *Label6;
        TDBEdit *DBEdit6;
        TDataSource *DataSource1;
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall BitBtn4Click(TObject *Sender);
        void __fastcall BitBtn5Click(TObject *Sender);
        void __fastcall BitBtn6Click(TObject *Sender);
        void __fastcall BitBtn7Click(TObject *Sender);
        void __fastcall BitBtn8Click(TObject *Sender);
        void __fastcall BitBtn9Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
        void EnterModifyMode();
        void LeaveModifyMode();
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
