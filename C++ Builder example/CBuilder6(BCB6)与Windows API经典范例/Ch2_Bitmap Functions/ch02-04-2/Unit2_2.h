//---------------------------------------------------------------------------
#ifndef Unit2_2H
#define Unit2_2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TNewform : public TForm
{
__published:	// IDE-managed Components
private:	// User declarations

public:		// User declarations
    RECT R;
    void __fastcall WndProc(TMessage &Msg);
    void __fastcall GetRect(LPRECT lpRect);

    __fastcall TNewform(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TNewform *Newform;
//---------------------------------------------------------------------------
#endif
