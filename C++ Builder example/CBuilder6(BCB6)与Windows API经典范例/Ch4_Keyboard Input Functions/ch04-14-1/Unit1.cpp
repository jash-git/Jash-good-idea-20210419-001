//---------------------------------------------------------------------------
//目的：仿真键盘输入组合键，将桌面上所有打开程序切换最小化或还原
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
{//调用快捷工具栏的window系统选单
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//调用快捷工具栏的window系统选单
//在快捷工具栏空白处，右键点按，出现的系统选单
::keybd_event( VK_LWIN, (BYTE)::MapVirtualKey( VK_LWIN, 0), 0, 0 );

if(Button1->Default)//单击 Shift 键
  ::keybd_event( VK_SHIFT, (BYTE)::MapVirtualKey( VK_SHIFT, 0), 0, 0 );
//单击 M 键
::keybd_event( 'M', (BYTE)::MapVirtualKey( 'M', 0), 0, 0 );
::keybd_event( 'M', (BYTE)::MapVirtualKey( 'M', 0), KEYEVENTF_KEYUP, 0 );

if(Button1->Default)//解除单击 Shift 键
   ::keybd_event( VK_SHIFT, (BYTE)::MapVirtualKey( VK_SHIFT, 0), KEYEVENTF_KEYUP, 0 );
//解除调用快捷工具栏的window系统选单
::keybd_event( VK_LWIN, (BYTE)::MapVirtualKey( VK_LWIN, 0), KEYEVENTF_KEYUP, 0 );
//使按钮重复单击时，切换功能
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
