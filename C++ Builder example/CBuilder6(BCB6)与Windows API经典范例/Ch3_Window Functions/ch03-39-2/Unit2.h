//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
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
    TStaticText *StaticText1;
    TPopupMenu *PopupMenu1;
    TMenuItem *pop011;
    TMenuItem *pop021;
    TMenuItem *pop031;
    void __fastcall FormClick(TObject *Sender);    
    void __fastcall pop011Click(TObject *Sender);
    void __fastcall pop021Click(TObject *Sender);
    void __fastcall pop031Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
