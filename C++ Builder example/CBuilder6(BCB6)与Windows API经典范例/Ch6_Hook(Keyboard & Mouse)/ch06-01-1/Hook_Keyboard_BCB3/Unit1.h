//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
//自定义的键盘信息，与keydll.dll中自定义的键盘信息相互对应
const int WM_KEYHOOK = WM_USER+100;
//---------------------------------------------------------------------------
class TKeyHookForm : public TForm
{
__published:	// IDE-managed Components
    TToolBar *ToolBar1;
    TButton *Button1;
    TButton *Button2;
    TListBox *ListBox1;
    void __fastcall Button1Click(TObject *Sender);
    void __fastcall Button2Click(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
    HINSTANCE inst; //指向键盘hook结构
    int inthook; //递增变量--计算按键次数
public:		// User declarations
//捕捉来自keydll.dll的自定义键盘信息
void __fastcall KeyHook(TMessage &Msg);
BEGIN_MESSAGE_MAP
VCL_MESSAGE_HANDLER(WM_KEYHOOK, TMessage, KeyHook);
END_MESSAGE_MAP(TForm)
    __fastcall TKeyHookForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TKeyHookForm *KeyHookForm;
//---------------------------------------------------------------------------
#endif
