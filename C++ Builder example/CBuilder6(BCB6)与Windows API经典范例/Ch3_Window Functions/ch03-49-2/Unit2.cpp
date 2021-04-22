//---------------------------------------------------------------------------
//目的：由定时器定时检测鼠标屏幕位置，而选取子窗口
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
{//默认组件各项属性
CheckBox1->Checked = false;
CheckBox1->Caption = "已关闭鼠标滑动选取子窗口";
CheckBox1->Width = 170; //设置足够宽度
Timer1->Interval = 100; //定时器频率
Timer1->Enabled = false; //先关闭定时器
}
//---------------------------------------------------------------------------
//在程序显示时，建立4个子窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Form1;
   form->FormStyle = fsMDIChild;
   form->Name = "form_" + AnsiString(i);
   form->Width = 120; form->Height = 60;
   form->Top = i*50; form->Left = i*30;
   form->Color = (TColor)RGB(255,i*50,255-i*50);
   }
}
//---------------------------------------------------------------------------
//在程序关闭时，关闭4个子窗口
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
//控制定时器开关，并修改状态说明字符串
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
Timer1->Enabled = !Timer1->Enabled;
if (Timer1->Enabled)  CheckBox1->Caption ="已启动鼠标滑动选取子窗口";
else                  CheckBox1->Caption ="已关闭鼠标滑动选取子窗口";
}
//---------------------------------------------------------------------------
//由定时器定时检测鼠标屏幕位置，而选取子窗口
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
::GetCursorPos(&P);//取得鼠标屏幕位置
//取得鼠标位置下窗口handle
HWND HWindow = ::WindowFromPoint(P);
//将焦点设给此窗口
if (HWindow) ::SetFocus(HWindow);
}
//---------------------------------------------------------------------------

