//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//清空Memo1的文字内容
Memo1->Clear();
RECT r;
//取得Form1内沿范围
::GetClientRect(Handle, &r);
//取得相对于桌面的Form1内沿范围
::MapWindowPoints(Handle, HWND_DESKTOP, reinterpret_cast<LPPOINT>(&r), 2);
//取得Form1外沿范围(相对于桌面)
RECT rWin;
::GetWindowRect(Handle, &rWin);
//相对位置相减，即得内沿与外沿之间距离
int dx = r.left - rWin.left;
int dy = r.top - rWin.top;
Memo1->Lines->Add("Form1的Client区域开始起点：");
Memo1->Lines->Add("X位置为第  "+AnsiString(dx) +"个位图");
Memo1->Lines->Add("Y位置为第 "+AnsiString(dy) +" 个位图");
}
//---------------------------------------------------------------------------
