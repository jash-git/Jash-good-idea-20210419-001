//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//ComboBox转换成自定义信息
OldComboBoxWP = ComboBox1->WindowProc;
ComboBox1->WindowProc = NewComboBoxWP;
//控制ComboBox1右边向下箭头的凹陷与浮起状态
FPushed = false;
}
//---------------------------------------------------------------------------
//当程序结束时，回复原有信息状态
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
ComboBox1->WindowProc = OldComboBoxWP;
}
//---------------------------------------------------------------------------
//自定义ComboBox信息
void __fastcall TForm1::NewComboBoxWP(TMessage &Msg)
{
//当鼠标左键点击ComboBox1右边向下箭头，即引发重绘动作，
//FPushed为真时，即绘制成凹陷状态
if(Msg.Msg == WM_LBUTTONDOWN) FPushed = true;
//FPushed为伪时，即绘制成浮起状态
if(Msg.Msg == WM_LBUTTONUP || Msg.Msg == CM_MOUSELEAVE)
  {
  FPushed = false;
  ComboBox1->Invalidate();//引发重绘动作(WM_PAINT)
  }
if(Msg.Msg == WM_PAINT)
  {//
  PAINTSTRUCT ps;
  HDC Hdc = ::BeginPaint(ComboBox1->Handle, &ps);
  DrawComboBox(Hdc, FPushed);//自定义函数
  //
  EndPaint(ComboBox1->Handle, &ps);
  Msg.Result = 0;
  return;
  }
//其它ComboBox1信息依原方式处理
OldComboBoxWP(Msg);
}
//---------------------------------------------------------------------------
//绘制ComboBox1--自定义信息
void TForm1::DrawComboBox(HDC Hdc, bool Pushed)
{
//取得ComboBox1范围尺寸
RECT R;
::GetClientRect(ComboBox1->Handle, &R);
//选取<去除画笔>性质至ComboBox1的DC中
::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));

//开始绘制新ComboBox1外框边
LOGBRUSH lb;
lb.lbColor = RGB(255,220,140);
::SelectObject(Hdc, ::CreateBrushIndirect(&lb));
::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
//将绘制框围各边同时缩入2个位图
::InflateRect(&R, -2, -2);
lb.lbColor = RGB(160,220,255);
::SelectObject(Hdc, ::CreateBrushIndirect(&lb));
//::SelectObject(Hdc, ::GetStockObject(BLACK_PEN));
::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);

//取得右边向下箭头的宽度，并重设其框围
int btnWidth = ::GetSystemMetrics(SM_CXVSCROLL);
RECT BtnRect = {R.right-btnWidth+2, R.top+2,
                R.right-2, R.bottom-2};

//判断与设置右边向下箭头的凹陷与浮起状态
unsigned int style = DFCS_SCROLLCOMBOBOX;
if (Pushed) style = style | DFCS_PUSHED;
else style = style | DFCS_FLAT;
//保持右边向下箭头可运作
if (!ComboBox1->Enabled) style = style | DFCS_INACTIVE;

//依照前述设置，绘制右边向下箭头框围
::DrawFrameControl(Hdc, &BtnRect, DFC_SCROLL, style);
}
//---------------------------------------------------------------------------

