//---------------------------------------------------------------------------
//目的：解析按键内容，将按键信息转换成按键名称呈现
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
//捕捉按键输入信息
void __fastcall TForm1::WMKeydown(TMessage &Msg)
{
char KeyName[255];
//将信息的按键内容转成按键名称呈现
if(::GetKeyNameText(Msg.LParam, KeyName, sizeof(KeyName)))
  Panel4->Caption = "捕捉到  "+AnsiString(KeyName)+"  按键名称";
else
  Panel4->Caption = "此非有效按键信息";
}
//---------------------------------------------------------------------------
//以下为键盘事件--OnKeyDown、OnKeyPress函数
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//检测到功能键状态
if(Shift.Contains(ssShift))
 Panel2->Caption = "按住 Shift 键";
if(Shift.Contains(ssAlt))
 Panel2->Caption = "按住 Alt 键";
if(Shift.Contains(ssCtrl))
 Panel2->Caption = "按住 Ctrl 键";
//显示按键代码
Panel1->Caption = "按键代码："+AnsiString(IntToHex((int)Key,2));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
Panel3->Caption = "在字符串中实际呈现为："+AnsiString(Key);
}
//---------------------------------------------------------------------------


