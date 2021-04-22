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
//将Image1图像指派给bm，bm为Image1代理人
bm = new Graphics::TBitmap;
bm->Width = Image1->Picture->Bitmap->Width;
bm->Height = Image1->Picture->Bitmap->Height;
bm->Assign(Image1->Picture->Bitmap);
Image1->Hide();
//运用闲置属性，作为bool运用
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
RECT r;
HDC hdc;
//单击按钮，切换bm图像可拼贴的面积
if(Button1->Default)
  {//将bm图像拼贴到全屏幕范围
  RECT r1 = {0,0,Screen->Width,Screen->Height};
  r =r1;
  hdc = ::GetDC(0);
  }
else//将bm图像拼贴到Form1范围
  {
  ::GetClientRect(Handle, &r);
  hdc = Canvas->Handle;
  }
//逐一将bm拼贴到指定范围中
for(int i=0; i<r.bottom; i += bm->Height)
  for(int j=0; j<r.right; j+= bm->Width )
    {
    ::BitBlt(hdc,j,i, bm->Width, bm->Height,
             bm->Canvas->Handle, 0, 0, SRCCOPY);
    }
}
//---------------------------------------------------------------------------
//程序结束时，删除bm--Image1代理人
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete bm;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//单击按钮时，即切换拼贴范围
Button1->Default = !Button1->Default;
//送出绘制信息，即引发OnPaint事件
SNDMSG(Handle,WM_PAINT,0,0);
//避免绘制全屏幕时，连本程序也一并覆盖，指定鼠标位置
//将鼠标移到Form1的左上角系统选单位置
POINT p = { 5, -5};
p = ClientToScreen(p);
::SetCursorPos(p.x,p.y);
//仿真单击鼠标左键一次，打开Form1的系统菜单
::mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
::mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
}
//---------------------------------------------------------------------------


