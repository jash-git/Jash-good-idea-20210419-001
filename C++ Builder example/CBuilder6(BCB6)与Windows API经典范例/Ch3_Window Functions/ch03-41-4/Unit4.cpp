//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//动态新建一个POP菜单，用来显示鼠标在Panel1范围中位置
popMenu = new TPopupMenu(this);
pop1 = new TMenuItem(this);
popMenu->Items->Add(pop1);
pop1->Caption = "这是Panel1范围中";
//将闲置属性作为布尔值运算
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{//取得Panel1的原有类型数据
LONG ExStyle = ::GetWindowLong(Panel1->Handle, GWL_EXSTYLE);
//将Panel1设为透明状态
::SetWindowLong(Panel1->Handle, GWL_EXSTYLE,
                ExStyle | WS_EX_TRANSPARENT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete pop1;
delete popMenu;
}
//---------------------------------------------------------------------------
//当鼠标点取Panel1而按键跳起时，删除POP菜单上的显示字符串
void __fastcall TForm1::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
pop1->Caption = "";
}
//---------------------------------------------------------------------------
//当鼠标点取Panel1而按键单击时，检测鼠标位置并显示在POP选单上
void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Button == mbLeft)
   popMenu->Popup(X+Left+Panel1->Left,Y+Top+Panel1->Top+25);
pop1->Caption = "这是Panel1范围的X:"+AnsiString(X)+",Y:"+AnsiString(Y);
}
//---------------------------------------------------------------------------
//在Win32 Help中，搜寻Button Styles字符串，即可取得完整的按钮型态旗标
void __fastcall TForm1::Button1Click(TObject *Sender)
{//取得Button1的原有类型数据
DWORD dwStyle = ::GetWindowLong(Button1->Handle, GWL_STYLE);
//由按钮属性来切换按钮标题左上右下边切齐状态
if(Button1->Default)
  {dwStyle &= ~BS_LEFT & ~BS_TOP;
  dwStyle |= BS_RIGHT | BS_BOTTOM;
  Button1->Caption = "右下侧标题";}
else
  {dwStyle &= ~BS_RIGHT & ~BS_BOTTOM;
  dwStyle |= BS_LEFT | BS_TOP;
  Button1->Caption ="左上侧标题";}
//将修改的类型数据，重设Button1类型
::SetWindowLong(Button1->Handle, GWL_STYLE, dwStyle);
Button1->Refresh();//重绘Button1
//切换布尔值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

