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
//清空Memo1文字
Memo1->Text = "";
//变量声明与默认
int b=0, c=0;
AnsiString str = "";
char ch[256];
//逐一测试Form1下的子对象性质与类型名称
for(int i=0;i<ComponentCount;i++)
  {//先将组件指针转换为通用窗口类型
  TWinControl* cp = (TWinControl *)Components[i];
  //若此对象是具有窗口属性的子对象
  if(::IsChild(Handle,(HWND)cp->Handle))
    {//取得此子窗口类型名称
    ::GetClassName((HWND)cp->Handle, ch, 256);
    str = str + AnsiString(ch) + ",";
    b++;
    }
  else
    c++;
  }
Memo1->Lines->Add("Form1窗口共  " + AnsiString(b) +
                  "个子窗口对象," + AnsiString(c) + "个无窗口对象");
Memo1->Lines->Add("拥有窗口的对象类型为--" + str);
}
//---------------------------------------------------------------------------
