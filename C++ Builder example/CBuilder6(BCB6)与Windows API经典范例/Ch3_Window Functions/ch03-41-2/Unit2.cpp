//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//将闲置属性作为布尔值运算
Button1->Default = true;
}
//---------------------------------------------------------------------------
//在Win32 Help中，搜索Edit Control Styles字符串，即可取得完整的字符串组件类型标志
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得Edit1的原有类型数据
DWORD dwStyle = ::GetWindowLong(Edit1->Handle, GWL_STYLE);
//由按钮属性来切换Edit单行字符串组件的特有功能
if(Button1->Default)
  {dwStyle &= ~ES_UPPERCASE;
  dwStyle |= ES_NUMBER;
  StaticText1->Caption = "Edit1解除<字母都转为大写>与新建<限制输入数字>";
  }
else
  {dwStyle &= ~ES_NUMBER;
  dwStyle |= ES_UPPERCASE;
  StaticText1->Caption = "Edit1解除<限制输入数字>与新建<字母都转为大写>";
  }
//将修改的类型数据，重设Edit1类型
::SetWindowLong(Edit1->Handle, GWL_STYLE, dwStyle);
Edit1->SetFocus();
//切换布尔值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
