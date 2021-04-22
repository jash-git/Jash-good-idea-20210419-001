//---------------------------------------------------------------------------
#ifndef Unit5H
#define Unit5H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TImage *Image1;
    TStaticText *StaticText1;
    void __fastcall FormResize(TObject *Sender);
private:	// User declarations
    Graphics::TBitmap *Bitmap; 
public:		// User declarations
    void __fastcall WMEraseBkgnd(TMessage &Msg);

BEGIN_MESSAGE_MAP
    MESSAGE_HANDLER(WM_ERASEBKGND, TMessage, WMEraseBkgnd)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
