//---------------------------------------------------------------------------
//的：捕捉鼠标各种状态，按住窗口的背景区域，相同于按住标题栏，可拖曳移动
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
void __fastcall TForm1::WMNCHitTest(TMessage &Msg)
{
//取得现在信息结果
LRESULT DefResult = ::DefWindowProc( Handle, Msg.Msg,
                                     Msg.WParam, Msg.LParam);
//当鼠标左键在窗口背景按住不放，如同按住标题栏，可拖曳移动Form1
if(::GetAsyncKeyState(VK_LBUTTON) < 0
    && (DefResult == HTCLIENT))
    {//按住窗口背景时，如同按住标题列
    Msg.Result = HTCAPTION;
    Color = (TColor)RGB(255,170,210);//粉红色
    }
else//若否，则信息照旧
    {
    Msg.Result = DefResult;
    Color = (TColor)RGB(200,255,150);//淡绿色
    }
}
//---------------------------------------------------------------------------


