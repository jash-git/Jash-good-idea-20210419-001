//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//先取得窗口风格性质
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
//去除窗口的标题栏性质
dwStyle &= ~WS_CAPTION;
//再将无标题栏的风格重新设回窗口
::SetWindowLong(Handle, GWL_STYLE, dwStyle);

RECT r;
//取得指定窗口范围、位置
::GetClientRect(Handle, &r);
//建立两个椭圆形位置与范围
HRGN hRgn1 = ::CreateEllipticRgn(2, 2, r.right/6*2, r.bottom/6*2);
HRGN hRgn2 = ::CreateEllipticRgn(r.right/6*4, 2, r.right, r.bottom/6*2);
//再结合此两个椭圆形位置与范围
::CombineRgn(hRgn1,hRgn1,hRgn2,RGN_OR);
//另建立一个椭圆形位置与范围
HRGN hRgn3 = ::CreateEllipticRgn(r.right/6, r.bottom/6, r.right/6*5, r.bottom);
//再结合此两个椭圆形位置与范围
::CombineRgn(hRgn1,hRgn1,hRgn3,RGN_OR);
//设回指定窗口的显示范围
::SetWindowRgn(Handle, hRgn1, TRUE);
::SetProp(Handle, "region", hRgn1);
//将窗口设为橙色
Color = (TColor)RGB(255,200,140);
//并将关闭窗口的按钮位置居中
Button1->Left = (Width-Button1->Width)/2;
Button1->Top = (Height-Button1->Height)/2;
}
//---------------------------------------------------------------------------
//按住橙色区域，即可移动Form1
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//释放鼠标的捕捉，并送出按住窗口移动，如同按住标题栏移动窗口的信息
::ReleaseCapture();
SNDMSG(Handle, WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
}
//---------------------------------------------------------------------------
//取代关闭窗口的功能
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

