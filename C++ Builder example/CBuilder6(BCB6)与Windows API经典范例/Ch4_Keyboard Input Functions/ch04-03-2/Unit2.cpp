//---------------------------------------------------------------------------
//在左边RichEdit1中，将tabs跳格(Ctrl+I 组合键)原有功能，改成能键入红色斜体字体功能
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//将 VK_I 定义成 I 键值------------------------------------------------------
#define VK_I 0x49
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit1KeyPress(TObject *Sender, char &Key)
{
//当组合键相等于跳格(tab)时与 I 键是单击状态，则可进行相关功能改变
if(Key == VK_TAB && (::GetAsyncKeyState(VK_I) < 0))
  {
  Key = 0;
  RichEdit1->SelAttributes->Style =
       RichEdit1->SelAttributes->Style << fsBold << fsItalic;
  RichEdit1->SelAttributes->Color = clRed;
  }
}
//---------------------------------------------------------------------------



