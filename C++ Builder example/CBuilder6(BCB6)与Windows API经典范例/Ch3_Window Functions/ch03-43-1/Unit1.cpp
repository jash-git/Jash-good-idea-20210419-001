//---------------------------------------------------------------------------
//目的：单击按钮，切换无标题窗口位置与大小
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
{//修改Form1的类型，去除标题列
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_DLGFRAME;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
//运用闲置属性，作为布尔值切换
Tag = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int x, y, w, h;
//运用三元运算，切换窗口位置与尺寸的变量
(Tag)?
(w=200,h=200,x=0,y=0,Tag=false):
(w=200,h=150,x=Screen->Width-200,y=Screen->Height-150,Tag=true);
//设置窗口位置与尺寸
::SetWindowPos(Handle,HWND_TOPMOST,
               x, y, w, h,
               SWP_SHOWWINDOW);
}
//---------------------------------------------------------------------------
//关闭窗口
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


