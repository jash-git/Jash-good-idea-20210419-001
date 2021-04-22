//---------------------------------------------------------------------------
#ifndef uCgi3H
#define uCgi3H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DB.hpp>
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
    TQuery *Query1;
    TFloatField *Query1CustNo;
    TStringField *Query1Company;
    TStringField *Query1Contact;
    TStringField *Query1Phone;
    void __fastcall FormCreate(TObject *Sender);
    
private:	// User declarations
public:		// User declarations
    __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
