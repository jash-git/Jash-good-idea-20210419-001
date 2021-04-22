//---------------------------------------------------------------------------
#ifndef Unit2aH
#define Unit2aH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//与Project2.exe设置相同的自定义信息-------------------------------------------
static const UINT WM_TWOWINMSG = WM_APP + 0x750;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TStaticText *StaticText1;
private:	// User declarations
public:		// User declarations
    //捕捉Project2.exe传送来的自定义信息
    void __fastcall WMTwoWinMsg(TMessage& Msg);
BEGIN_MESSAGE_MAP
MESSAGE_HANDLER(WM_TWOWINMSG, TMessage, WMTwoWinMsg)
END_MESSAGE_MAP(TForm)
    __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
