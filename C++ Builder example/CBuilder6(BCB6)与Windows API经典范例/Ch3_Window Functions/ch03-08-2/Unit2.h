//---------------------------------------------------------------------------
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TStaticText *StaticText1;
    
private:	// User declarations
    HWND HStatic;
    AnsiString str;
public:		// User declarations

    void __fastcall WMDrawItem(TMessage &Msg);
BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_DRAWITEM, TMessage, WMDrawItem)
END_MESSAGE_MAP(TForm)

    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
 