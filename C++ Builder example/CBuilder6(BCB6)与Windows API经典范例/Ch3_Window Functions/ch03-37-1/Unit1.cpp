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
{//先关闭定时器，用按钮控制开关
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//切换定时器开关
Timer1->Enabled = !Timer1->Enabled;
(Timer1->Enabled)?(Caption = "窗口画面向下移动中")
                    :(Caption = "停止窗口画面移动");

}
//---------------------------------------------------------------------------
//Form1在桌面位置不变，画面却向下移动
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
::MoveWindow(Handle, Left, Top++, Width, Height, false);
}
//---------------------------------------------------------------------------

