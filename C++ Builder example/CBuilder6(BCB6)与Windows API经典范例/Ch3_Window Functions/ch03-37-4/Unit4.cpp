//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
const int ABE_FLOAT = -1;
const int WM_MYAPPBAR = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//<1>先整理Form1及子对象状态
BorderStyle = bsSizeToolWin;//Form1先设为可随意调整尺寸
//去除Form1的标题栏
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_CAPTION;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
Caption = "自定义的快捷工具栏";
//按住时，即可任意拖拽Form1至屏幕任一边沿
StaticText1->OnMouseDown = Form1->OnMouseDown;

//<2>将Form1改成一个自定义的快捷工具栏
//填入APPBARDATA结构，送出信息
abd.cbSize = sizeof(APPBARDATA);
abd.hWnd = Handle;
abd.uCallbackMessage = WM_MYAPPBAR;//自定义信息
abd.lParam = 0;
::SHAppBarMessage(ABM_NEW, &abd);//改造成快捷工具栏

//<3>先放在桌面下边沿，并影响其它程序向上推移
abd.uEdge = ABE_BOTTOM;//维持SetAppBarPos函数参数一致性
//自定义函数--决定自定义快捷工具栏位置
SetAppBarPos(abd.uEdge, BoundsRect);
::SetWindowPos(Handle, HWND_TOPMOST, 0, Screen->Height-50,
               Screen->Width, 50, SWP_DRAWFRAME);
}
//---------------------------------------------------------------------------
//按住时，即可任意拖曳Form1至屏幕任一边沿
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
::ReleaseCapture();
SNDMSG(Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//关闭程序时，移除自定义的快捷工具列
::SHAppBarMessage(ABM_REMOVE, &abd);
}
//---------------------------------------------------------------------------
//在拖拽结束时，即由此函数判断在桌面的新位置，并自动推移其它程序
void __fastcall TForm1::SetAppBarPos(int flag, TRect R)
{
//若窗口在浮动状态下，则加上标题栏并停止程序代码执行而返回
  DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
if(flag == ABE_FLOAT)
  {//新建Form1的标题栏
  dwStyle |= WS_CAPTION;
  ::SetWindowLong(Handle, GWL_STYLE, dwStyle);
  return;
  }
else//去除Form1的标题栏
  {
  dwStyle &= ~WS_CAPTION;
  ::SetWindowLong(Handle, GWL_STYLE, dwStyle);
  }
//先处理传入变量与标志
int iHeight = 0, iWidth = 0;
abd.rc = R;
abd.uEdge = flag;
//若窗口贴近屏幕右边沿或左边沿时，则定出高度与宽度
if(flag == ABE_LEFT || flag == ABE_RIGHT)
  {
  iWidth = abd.rc.right - abd.rc.left;
  abd.rc.top = 0;
  abd.rc.bottom = ::GetSystemMetrics(SM_CYSCREEN);
  }
else//若窗口贴近屏幕上边沿或下边沿时，则定出高度与宽度
  {
  iHeight = abd.rc.bottom - abd.rc.top;
  abd.rc.left = 0;
  abd.rc.right = ::GetSystemMetrics(SM_CXSCREEN);
  }
//送出信息，向系统再次确认位置与尺寸
::SHAppBarMessage(ABM_QUERYPOS, &abd);
//取得边沿状态而确定位置
switch(flag)
  {
  case ABE_LEFT:
      abd.rc.right = abd.rc.left + iWidth; break;
  case ABE_RIGHT:
      abd.rc.left = abd.rc.right - iWidth; break;
  case ABE_TOP:
      abd.rc.bottom = abd.rc.top + iHeight; break;
  case ABE_BOTTOM:
      abd.rc.top = abd.rc.bottom - iHeight; break;
  }
//通知系统，确定最后位置及范围
::SHAppBarMessage(ABM_SETPOS, &abd);
//并移动至确定位置与尺寸
::MoveWindow(abd.hWnd, abd.rc.left, abd.rc.top,
             abd.rc.right - abd.rc.left,
             abd.rc.bottom - abd.rc.top, true);
}
//---------------------------------------------------------------------------
//重载Form1信息函数，捕捉窗口的基本信息与自定义信息
void __fastcall TForm1::WndProc(TMessage &Msg)
{
switch(Msg.Msg)
  {//若捕捉到自定义信息，则逐一分辨执行
  case WM_MYAPPBAR:
    switch(Msg.LParam)
      {
      case ABN_FULLSCREENAPP:
           {
           if(Msg.WParam)
             ::SetWindowPos(Handle, HWND_BOTTOM, 0, 0, 0, 0,
                            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
           else
             ::SetWindowPos(Handle, HWND_TOPMOST, 0, 0, 0, 0,
                            SWP_NOMOVE | SWP_NOSIZE | SWP_NOACTIVATE);
           break;
           }
      case ABN_STATECHANGE: break;
      case ABN_POSCHANGED: break;
      }
  case WM_ACTIVATE://当Form1可执行时，也送出新工具栏窗口可执行状态
       ::SHAppBarMessage(ABM_ACTIVATE, &abd);
       TForm::Dispatch(&Msg);
       break;
  case WM_WINDOWPOSCHANGED://当Form1位置改变时，也送出新工具栏窗口相同信息
       TForm::Dispatch(&Msg);
       ::SHAppBarMessage(ABM_WINDOWPOSCHANGED, &abd);
       break;
  //当Form1停止移动或调整大小时，即执行自定义函数--决定自定义快捷工具栏位置
  case WM_EXITSIZEMOVE:
       TForm::Dispatch(&Msg);
       SetAppBarPos(abd.uEdge, abd.rc);
       break;
  //当Form1移动中，实时
  case WM_MOVING: AppBarMoving(Msg); break;
  default: TForm::Dispatch(&Msg);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AppBarMoving(TMessage &Msg)
{//由信息取出新工具栏窗口的实时动态框围
LPRECT DragRect = (RECT *)Msg.LParam;
//将RECT结构与布尔值存于一固定地址
static RECT BackupRect = Rect(0, 0, 0, 0);
static bool boolFirstTime = true;
//先界定新工具列窗口最后在屏幕的位置与范围
RECT DesktopRect = Rect(0, 0, Screen->Width, Screen->Height);
RECT LeftRect = Rect(DesktopRect.left, DesktopRect.top,
                     DesktopRect.left + 50, DesktopRect.bottom);
RECT RightRect = Rect(DesktopRect.right - 50, DesktopRect.top,
                      DesktopRect.right, DesktopRect.bottom);
RECT TopRect = Rect(DesktopRect.left, DesktopRect.top,
                    DesktopRect.right, DesktopRect.top + 50);
RECT BottomRect = Rect(DesktopRect.left, DesktopRect.bottom - 50,
                       DesktopRect.right, DesktopRect.bottom);
//取得屏幕上鼠标位置
POINT P;
::GetCursorPos(&P);
//再依照鼠标位置，判断新工具栏窗口应该在何处出现
if(::PtInRect(&LeftRect, P))//鼠标在左边范围
  {
  if(boolFirstTime)
    {//实时将现在范围存入，以供在拖曳浮动状态中的相对位置
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = LeftRect;
  abd.rc = LeftRect;
  abd.uEdge = ABE_LEFT;
  }
else if(::PtInRect(&TopRect, P))//鼠标在上边范围
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = TopRect;
  abd.rc = TopRect;
  abd.uEdge = ABE_TOP;
  }
else if(::PtInRect(&RightRect, P))//鼠标在右边范围
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = RightRect;
  abd.rc = RightRect;
  abd.uEdge = ABE_RIGHT;
  }
else if(::PtInRect(&BottomRect, P))//鼠标在底边范围
  {
  if(boolFirstTime)
    {
    ::CopyRect(&BackupRect, DragRect);
    boolFirstTime = false;
    }
  *DragRect = BottomRect;
  abd.rc = BottomRect;
  abd.uEdge = ABE_BOTTOM;
  }
else //鼠标在中间范围，则处于浮动状态
  {
  abd.uEdge = ABE_FLOAT;
  if(!::IsRectEmpty(&BackupRect) && boolFirstTime == false)
    {
    POINT P;
    ::GetCursorPos(&P);
    RECT TempRect = Rect(P.x, P.y,
                         P.x + BackupRect.right - BackupRect.left,
                         P.y + BackupRect.bottom - BackupRect.top);

    *DragRect = TempRect;
    boolFirstTime = true;
    }
  }
Msg.Result = true;
}
//---------------------------------------------------------------------------

