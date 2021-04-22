//---------------------------------------------------------------------------
//目的：列出伪码与扫描码相互转换后的清单结果
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
{//将闲置属性作为递增变量
Tag = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{//先删除Memo1中所有文字
Memo1->Text = "";
while(Tag<400)
   {//MapVirtualKeyEx第二项参数决定伪码与扫描码相互转换的机制
   //GetKeyboardLayout(0)取得现在线程输入法的handle
   int g = ::MapVirtualKeyEx(Tag++, 0, ::GetKeyboardLayout(0));
   //可转换成功，则列出16进位的扫描码
   if(g)
      Memo1->Lines->Add("伪码_" + AnsiString(Tag) +
                        "<-> 扫描码_"+AnsiString(IntToHex(g,2)));
   }
//将Form1的Tag归零
Tag = 0;
}
//---------------------------------------------------------------------------


