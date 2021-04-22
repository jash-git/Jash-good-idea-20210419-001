//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2a.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//运用闲置属性为递增变量
Tag = 0;
//设置在桌面右下角出现
Top = Screen->Height - Height;
Left = Screen->Width - Width;
}
//---------------------------------------------------------------------------
//接收Project2.exe传送来的自定义信息，并转换成字符串
void __fastcall TForm1::WMTwoWinMsg(TMessage& Msg)
{
AnsiString str = "第 " + AnsiString(++Tag) +
                 " 次从Form1传来-- " + AnsiString(Msg.WParam)+
                 ","+ AnsiString(Msg.LParam);
Memo1->Lines->Add(str);
}
//---------------------------------------------------------------------------
