//---------------------------------------------------------------------------
//目的：按住Image1拖曳时，实际是捕捉到Image1下的动态Panel1对象
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
//默认在鼠标OnClick单击中途，先执行其他事件，
//再进行OnClick原本行程
CheckBox1->Checked = true;
//若真，在CheckBox1->Checked为真，则进行双击事件
CheckBox2->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDblClick(TObject *Sender)
{
//若真，在CheckBox1->Checked为真，则进行双击事件
if(CheckBox2->Checked == true)
   {
   //若Form1的OnClick事件失效，
   //则进行这里的程序代码
   Color = clRed;
   Canvas->TextOut(40, 40, "绕道至鼠标双击事件！");
   //再绕回OnClick执行后面程序代码
   CheckBox2->Checked = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
//先为淡蓝色
Color = (TColor)RGB(170,225,255);
//冻结时间至越过鼠标引发双击事件的时间
//避免触发OnDblClick事件
::Sleep(::GetDoubleClickTime()+1);
//中断现在程序执行，以先进行其他事件的响应
//再进行后面功能
if(CheckBox1->Checked)
   Application->ProcessMessages();

if(CheckBox2->Checked == false)
   {
   Color = (TColor)RGB(200,255,160);
   Canvas->TextOut(50, 50, "避开了鼠标双击事件！" + AnsiString(::GetDoubleClickTime()));
   }

}
//---------------------------------------------------------------------------


