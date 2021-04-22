//---------------------------------------------------------------------------
//境奻﹜迠狟Keyboard hookㄛ甜堍蚚赻隅砱陓洘換菰Hook杅擂
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TKeyHookForm *KeyHookForm;
//---------------------------------------------------------------------------
__fastcall TKeyHookForm::TKeyHookForm(TComponent* Owner)
    : TForm(Owner)
{
inthook = 0;//計算按鍵次數變數歸零
//將KeyHookForm維持在視窗最上面
FormStyle = fsStayOnTop;
//掛上&卸下Hook的按鈕狀態
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//掛上Hook鏈，並設置定時器從共享記憶體中取回鍵盤訊息
void __fastcall TKeyHookForm::Button1Click(TObject *Sender)
{
//計算按鍵次數變數歸零
inthook = 0;
//在keydll.dll中，SetHook函式是執行注射Hook行程至訊息鏈中
//先宣告有一SetHook函式
void (*SetHook)();
//載入同一目錄下的指定連接檔--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中SetHook函式位址
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//執行指向dll中的SetHook函式
SetHook();
//掛上&卸下Hook的按鈕狀態
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//卸下Hook鏈，解除自訂的hook
void __fastcall TKeyHookForm::Button2Click(TObject *Sender)
{
//在keydll.dll中，RemoveHook函式是執行從訊息鏈中卸下Hook行程
//宣告RemoveHook函式
void (*RemoveHook)();
//載入同一目錄下的指定連接檔--keydll.dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中RemoveHook函式位址
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//執行指向dll中的RemoveHook函式
RemoveHook();
//釋放dll
::FreeLibrary(inst);
//掛上&卸下Hook的按鈕狀態
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//預防使用者結束Hook時，未卸下Hook鏈
void __fastcall TKeyHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
//在keydll.dll中，RemoveHook函式是執行從訊息鏈中卸下Hook行程
//先宣告RemoveHook函式
void (*RemoveHook)();
//載入dll
inst = ::LoadLibrary("keydll.dll");
//取得dll中RemoveHook函式位址
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//執行指向dll中的RemoveHook函式
RemoveHook();
//釋放dll
::FreeLibrary(inst);
}
//---------------------------------------------------------------------------
//取得攔截自鍵盤中的自訂訊息
void __fastcall TKeyHookForm::KeyHook(TMessage &Msg)
{
//取得自訂訊息中的按鍵名稱
char keytext[80];
::GetKeyNameText(Msg.LParam, keytext, 80);
//取得自訂訊息中的按鍵狀態(檢測用..意義不大...)
AnsiString keystate;
keystate = ::GetKeyState((int)Msg.WParam);
keystate = (keystate == "1")?"偌狟":"腹れ";//C++腔��啋堍呾

//由ListBox元件顯示攔截成果
ListBox1->Items->Insert(0,
                        "菴 "+AnsiString(++inthook) + "偌瑩__" +
                        AnsiString(keytext)+ " ˙袨怓>>" + keystate
                        );
}
//---------------------------------------------------------------------------

