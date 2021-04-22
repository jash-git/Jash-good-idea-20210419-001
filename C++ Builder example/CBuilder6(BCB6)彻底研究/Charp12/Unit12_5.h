//---------------------------------------------------------------------------
#ifndef Unit12_5H
#define Unit12_5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBClient.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include <Mask.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label4;
        TLabel *Label5;
        TPanel *Panel1;
        TLabel *Label2;
        TLabel *Label3;
        TDBEdit *DBEdit1;
        TDBEdit *DBEdit2;
        TButton *Button1;
        TListBox *ListBox1;
        TPanel *Panel2;
        TDBGrid *DBGrid1;
        TRadioButton *RadioButton1;
        TClientDataSet *cdsUser;
        TStringField *cdsUserUSERNAME;
        TStringField *cdsUserPASSWORD;
        TDataSource *DataSource1;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall RadioButton1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
