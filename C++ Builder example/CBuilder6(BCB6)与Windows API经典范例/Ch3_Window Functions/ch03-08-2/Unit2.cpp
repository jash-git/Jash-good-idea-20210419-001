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
//新按钮的默认标题与按钮文字
str = "YES! 我是独立且彩色的按钮！";
//默认新按钮尺寸、位置
RECT btR = {0, 0, 100, 100};
//建立一个多行文字、可移动、彩色文字、彩色背景的按钮窗口
HStatic = ::CreateWindow("BUTTON", str.c_str(),
                         WS_CAPTION | WS_VISIBLE | WS_CHILD
                         | SS_CENTER | WS_SIZEBOX
                         | BS_MULTILINE | BS_OWNERDRAW,
                         btR.left, btR.top,
                         btR.right - btR.left, btR.bottom - btR.top,
                         Handle, NULL, HInstance, NULL);
}
//---------------------------------------------------------------------------
//新按钮需重绘时，即送出此信息
void __fastcall TForm1::WMDrawItem(TMessage &Msg)
{
//<1>基本信息取得与整理
//由LParam信息指向按钮LPDRAWITEMSTRUCT结构
LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT *)Msg.LParam;
//若非新按钮，就依照默认信息处理
if (lpdis->hwndItem != HStatic)
   {
   TForm::Dispatch(&Msg);
   return;
   }
//从DRAWITEMSTRUCT结构取得有用信息
HDC Hdc = lpdis->hDC;
RECT R = lpdis->rcItem;
//取得按钮是否在鼠标单击选取状态
unsigned int uState = lpdis->itemState;
//设置按钮为浮起状态
unsigned int uDrawSytle = DFCS_BUTTONPUSH;
//按钮文字的偏移量
int text_offset = 0;
//若按钮在鼠标单击选取状态，则边沿呈现凹陷光影与
//文字偏移量向右下方加3位图
if (uState & ODS_SELECTED)
  {
  uDrawSytle = uDrawSytle | DFCS_PUSHED;
  text_offset+=3;
  }
//<2>先绘制按钮背景与边框
//将对象绘制出指定型态与状态
::DrawFrameControl(Hdc, &R, DFC_BUTTON, uDrawSytle);
//按钮背景的范围
RECT r = {R.left+3,R.top+3,
          R.right-3,R.bottom-3};
//建立一新彩色画笔，填满按钮背景
HBRUSH hbr = ::CreateSolidBrush(RGB(200,0,200));
::FillRect(Hdc, &r, hbr);
//<3>再绘制按钮文字
//先设置字体背景为透明状态
unsigned int iOldMode = ::SetBkMode(Hdc, TRANSPARENT);
//确定偏移量
::OffsetRect(&r, text_offset, text_offset);
//设置文字色彩
::SetTextColor( Hdc, RGB(180,230,255));
//::SetBkColor( Hdc, ColorToRGB(clBlue));
//在按钮上绘出文字
::DrawText(Hdc, str.c_str(),
           str.Length(),
           &r,
           DT_CENTER | DT_VCENTER | DT_WORDBREAK);
//恢复原有背景
::SetBkMode(Hdc, iOldMode);
Msg.Result = true;
}
//---------------------------------------------------------------------------
