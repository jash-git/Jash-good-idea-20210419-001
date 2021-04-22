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
{//将闲置属性作为递增变量
Button1->Tag = 0;
}
//---------------------------------------------------------------------------
//单击按钮，则可循环转换工具栏组件(ToolBar1)母窗口
void __fastcall TForm1::Button1Click(TObject *Sender)
{//判断递增变量的循环转换
switch(Button1->Tag%3)
  {
  case 0: ::SetParent(ToolBar1->Handle,Panel1->Handle);break;
  case 1: ::SetParent(ToolBar1->Handle,Panel2->Handle);break;
  case 2: ::SetParent(ToolBar1->Handle,::GetDesktopWindow());break;
  }
//重设工具栏组件位置与尺寸
::SetWindowPos(ToolBar1->Handle,HWND_TOPMOST,
               30, 30,
               ToolBar1->Width/2, ToolBar1->Height/2,
               SWP_SHOWWINDOW
               );
Button1->SetFocus();//仍由按钮取得焦点
++Button1->Tag;//变量递增，以备下次点按按钮
}
//---------------------------------------------------------------------------
//若user同时按住Ctrl键，并用鼠标左键拖曳Panel1，即可拖曳Panel1
void __fastcall TForm1::ToolBar1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Button == mbLeft && Shift.Contains(ssCtrl))
  {//释放原有鼠标捕捉状态，
  //并同时送出鼠标单击位置等同于窗口标题列可拖曳窗口的属性
  ::ReleaseCapture();
  SNDMSG(ToolBar1->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
  }
//若在桌面拖曳ToolBar1时，Button1无法定位而失去单击能力，
//则由鼠标右键单击ToolBar1代替
if(Button == mbRight)
  {
  Button1->Click();
  }
}
//---------------------------------------------------------------------------
