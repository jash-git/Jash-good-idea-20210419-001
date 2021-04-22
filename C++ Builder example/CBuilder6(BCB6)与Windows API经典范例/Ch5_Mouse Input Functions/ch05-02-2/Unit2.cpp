//---------------------------------------------------------------------------
//目的：鼠标拖曳刻度组件(TrackBar)箭头，实时显现箭头位置的提示窗口
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
{//调整TrackBar位置、尺寸
TrackBar1->Width = ClientWidth;
TrackBar1->Top = (ClientHeight-TrackBar1->Height)/2;
TrackBar1->Left = 0;
TrackBar1->Max = 50;
//程序开始时，替换成自定义信息处理
OldTrackBarWP = TrackBar1->WindowProc;
TrackBar1->WindowProc = NewTrackBarWP;
//新建一小提示窗口
HintWindow = new THintWindow(this);
//突显TrackBar与小提示窗口
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------
//程序结束时，恢复原有信息处理
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
TrackBar1->WindowProc = OldTrackBarWP;
delete HintWindow;
}
//---------------------------------------------------------------------------
//自定义信息处理
void __fastcall TForm1::NewTrackBarWP(TMessage &Msg)
{//若鼠标单击时，即捕捉住TrackBar
if(Msg.Msg == WM_LBUTTONDOWN)
  {
  ::SetCapture(TrackBar1->Handle);
  }
//若移动鼠标时且单击左键状态，则显现提示窗口
if(Msg.Msg == WM_MOUSEMOVE)
  {
  POINT P;
  ::GetCursorPos(&P);
  if(::GetCapture() == TrackBar1->Handle)
    {
    HintWindow->Invalidate();//更新窗口，引发WM_PAINT信息
    //结合显示在提示窗口的字符串
    AnsiString str = " "+AnsiString(TrackBar1->Position)+" 位置";
    //取得提示窗口的文字结构数据，再重设提示窗口范围
    TEXTMETRIC tm;
    ::GetTextMetrics(::GetDC(HintWindow->Handle), &tm);
    //ws是字符宽度X字符数目(减去最后NULL字符)
    int ws = (int)(tm.tmAveCharWidth*(str.Length()-1));
    //hs是字符高度，看情形是否加上行间距
    int hs = (int)(tm.tmHeight);// + tm.tmExternalLeading);
    RECT R = Rect(P.x, P.y, P.x+ ws, P.y + hs);
    //将提示窗口偏移至鼠标右上方
    ::OffsetRect(&R, 0, -30);
    HintWindow->ActivateHint((TRect)R, str);//显现提示窗口
    }
  }
//若鼠标左键放开时，即释放TrackBar捕捉权与提示窗口
if(Msg.Msg == WM_LBUTTONUP)
  {
  ::ReleaseCapture();
  HintWindow->ReleaseHandle();
  }
//当鼠标拖曳TraskBar移动时，实时重绘提示窗口与位置
if(Msg.Msg == WM_PAINT && ActiveControl == TrackBar1)
  {
  HDC Hdc = ::GetDC(TrackBar1->Handle);
  RECT R = RECT(TrackBar1->ClientRect);
  HBRUSH HOldBrush = ::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));
  ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
  ::SelectObject(Hdc, HOldBrush);
  ::ReleaseDC(TrackBar1->Handle, Hdc);
  }
//其余信息依原方式处理
OldTrackBarWP(Msg);
}
//---------------------------------------------------------------------------

