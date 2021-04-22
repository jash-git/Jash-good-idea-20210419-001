//---------------------------------------------------------------------------
//目的：仿真点选选单中项目，并执行选单功能
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
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//VK_MENU即是Alt键，可使现有选单起作用
::keybd_event(VK_MENU, (BYTE)::MapVirtualKey(VK_MENU,0),0,0);
//若Alt加上F键，可触动<文件>选单
::keybd_event('F', (BYTE)::MapVirtualKey('F',0),0,0);
//再将F键改成V键，可触动<改变颜色>选项
::keybd_event('V', (BYTE)::MapVirtualKey('V',0),0,0);
//达到应有功能后，反序释放按键
::keybd_event('V', (BYTE)::MapVirtualKey('V',0),KEYEVENTF_KEYUP,0);
::keybd_event('F', (BYTE)::MapVirtualKey('F',0),KEYEVENTF_KEYUP,0);
::keybd_event(VK_MENU, (BYTE)::MapVirtualKey(VK_MENU,0),KEYEVENTF_KEYUP,0);
}
//---------------------------------------------------------------------------
//Alt + F键，触动<背景成为淡绿色>选单功能
void __fastcall TForm1::File1Click(TObject *Sender)
{
Color = (TColor)RGB(190,255,125);
Caption = "仔细看，出现一下子背景为淡绿色的情况";
}
//---------------------------------------------------------------------------
//Alt + V键，触动<背景成为淡蓝色>选项功能
void __fastcall TForm1::FileSub104Click(TObject *Sender)
{
Color = (TColor)RGB(128,128,255);
}
//---------------------------------------------------------------------------



