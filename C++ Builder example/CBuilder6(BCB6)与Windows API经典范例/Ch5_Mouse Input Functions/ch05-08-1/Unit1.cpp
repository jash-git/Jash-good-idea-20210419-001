//---------------------------------------------------------------------------
//目的：交换鼠标左右键功能
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
{//默认CheckBox1状态
CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked)
   {//交换鼠标左右键功能
   ::SwapMouseButton(true);
   StaticText1->Caption = "鼠标左右键现在交换中！";
   }
else //鼠标左右键功能恢复默认
   {
   ::SwapMouseButton(false);
   StaticText1->Caption = "鼠标左右键现在恢复正常！";
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{//离开程序时，恢复鼠标左右键正常状态
::SwapMouseButton(false);
}
//---------------------------------------------------------------------------
//测试用选项
void __fastcall TForm1::FileSub101Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,160);
}
//---------------------------------------------------------------------------
//测试用选项
void __fastcall TForm1::FileSub102Click(TObject *Sender)
{
Color = clBtnFace;
}
//---------------------------------------------------------------------------



