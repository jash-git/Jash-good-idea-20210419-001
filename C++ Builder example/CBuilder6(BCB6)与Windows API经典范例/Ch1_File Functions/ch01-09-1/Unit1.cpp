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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//设置一字符数组
char c[MAX_PATH];
//将程序现在目录所在填入此字符数组
if(::GetCurrentDirectory(MAX_PATH,c))
    StaticText2->Caption = "程序目前目录是 " + AnsiString(c);
else
    StaticText2->Caption = "取得目前目录失败！";

}
//---------------------------------------------------------------------------
