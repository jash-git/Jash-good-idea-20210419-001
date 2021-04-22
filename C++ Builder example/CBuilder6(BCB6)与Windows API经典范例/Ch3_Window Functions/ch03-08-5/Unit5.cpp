//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//按钮默认值
Button1->Enabled = true;
//运用Form1的Tag属性为记数器
Tag = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//固定选单位置尺寸
RECT R = {30, 40, 150, 80};
//建立一新下拉式滚动条菜单--自定义函数
HComboBox = CreateComboBox(Handle, 0, &R, CBS_DROPDOWNLIST);
//新建菜单选项
if(HComboBox)
  {
  for(int a=1;a<11;a++)
     {
     AnsiString str = "第 " + AnsiString(a) + " 选项";
     SNDMSG(HComboBox, CB_ADDSTRING, 0,
           reinterpret_cast<LPARAM>(str.c_str()));
     }
  //送出信息，返回选项高度
  const int item_height = SNDMSG(HComboBox, CB_GETITEMHEIGHT, 0, 0);
  const int list_height = item_height * 10;
  //重设下拉的选项总长度
  ::SetWindowPos(HComboBox, NULL, 0, 0, 150, 40 + list_height,
                 SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
    }
//只允许建立一个滚动条菜单
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//建立一新滚动条菜单
HWND TForm1::CreateComboBox(HWND HParent, int nID, RECT *r,
    unsigned int uiStyle)
{
return ::CreateWindow ("COMBOBOX", "",
                       WS_CHILD | WS_VISIBLE | uiStyle,
                       r->left, r->top,
                       r->right - r->left,
                       r->bottom - r->top,
                       HParent, reinterpret_cast<HMENU>(nID),
                       HInstance, NULL);
}
//---------------------------------------------------------------------------
//此新滚动条选单的信息处理
void __fastcall TForm1::NewComboBoxClick(TMessage &Msg)
{
//若handle是滚动条单击与滚动条菜单改变选取的信息
//CBN_SELCHANGE信息可由Combo Box Messages查询到
if (reinterpret_cast<HWND>(Msg.LParam) == HComboBox &&
    HIWORD(Msg.WParam) == CBN_SELCHANGE)
   {
   char str[256];
   ::GetWindowText(HComboBox,str,256);
   StaticText2->Caption = "现在选择<" + AnsiString(str) +
                           ">这个选项,共选" +
                           AnsiString(Tag++) + "次";
   }
//其余信息依照原设置执行
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------

