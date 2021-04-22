//---------------------------------------------------------------------------
#ifndef Unit4H
#define Unit4H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
#include <shellapi.h>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TStaticText *StaticText1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
    
    
private:	// User declarations
    APPBARDATA abd;
public:		// User declarations
    void __fastcall SetAppBarPos(int flag, TRect R);
    void __fastcall WndProc(TMessage &Msg);
    void __fastcall AppBarMoving(TMessage &Msg);
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
