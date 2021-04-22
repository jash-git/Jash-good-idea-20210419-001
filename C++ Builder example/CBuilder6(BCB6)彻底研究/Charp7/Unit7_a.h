//---------------------------------------------------------------------------
#ifndef Unit7_aH
#define Unit7_aH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TLabel *Label1;
    TLabel *Label2;
    TButton *Button2;
    TButton *Button3;
    TButton *Button4;
    TMainMenu *MainMenu1;
    TMenuItem *Help1;
    TMenuItem *Delphi301;
    TMenuItem *N1;
    TMenuItem *N2;
    TMenuItem *N3;
    void __fastcall Delphi301Click(TObject *Sender);
    void __fastcall N1Click(TObject *Sender);
    void __fastcall N2Click(TObject *Sender);
    void __fastcall N3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
