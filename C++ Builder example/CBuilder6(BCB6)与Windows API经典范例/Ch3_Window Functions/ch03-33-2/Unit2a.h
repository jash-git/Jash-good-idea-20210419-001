//---------------------------------------------------------------------------
#ifndef Unit2aH
#define Unit2aH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//��Project2.exe������ͬ���Զ�����Ϣ-------------------------------------------
static const UINT WM_TWOWINMSG = WM_APP + 0x750;
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
    TMemo *Memo1;
    TStaticText *StaticText1;
private:	// User declarations
public:		// User declarations
    //��׽Project2.exe���������Զ�����Ϣ
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
