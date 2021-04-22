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
{//将闲置属性作为布尔值运算
Button1->Default = true;
Button2->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得CheckBox1的原有类型数据
DWORD dwStyle = ::GetWindowLong(CheckBox1->Handle, GWL_STYLE);
//三元运算子--由按钮属性来切换仿真按钮浮起陷下类型
(Button1->Default)?(dwStyle |= BS_PUSHLIKE):(dwStyle &= ~BS_PUSHLIKE);
//将修改的类型数据，重设CheckBox1类型
::SetWindowLong(CheckBox1->Handle, GWL_STYLE, dwStyle);
CheckBox1->Refresh();//重绘CheckBox1
//切换布尔值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//将RadioGroup1中的子对象，逐一重设显示的类型
for(int i=0; i<RadioGroup1->ControlCount; ++i)
   {//将子对象转型为通用窗口对象
   TWinControl* Btnlike = static_cast<TWinControl*>
                              (RadioGroup1->Controls[i]);
   //取得RadioGroup1子对象的原有类型数据
   DWORD dwStyle = ::GetWindowLong(Btnlike->Handle, GWL_STYLE);
   //三元运算子--由按钮属性来切换仿真按钮浮起陷下类型
   (Button2->Default)?(dwStyle |= BS_PUSHLIKE):(dwStyle &= ~BS_PUSHLIKE);
   //将修改的类型数据，重设RadioGroup1子对象类型
   ::SetWindowLong(Btnlike->Handle, GWL_STYLE, dwStyle);
   }
RadioGroup1->Refresh();//重绘RadioGroup1
//切换布尔值
Button2->Default = !Button2->Default;
}
//---------------------------------------------------------------------------

