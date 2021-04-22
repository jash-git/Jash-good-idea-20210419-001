//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
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
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    TLabel *label;
public:		// User declarations
    //捕捉Crtl+F5快捷键送出的自定义信息
    void __fastcall WMHotKey(TMessage &Msg);

BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_HOTKEY, TMessage, WMHotKey)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
