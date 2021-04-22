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
FHClipRgn = NULL;
//此Canvas为全域运用
FScreenCanvas = new TCanvas();
//控制是否为鼠标左键单击状态
bDragging = false;
}
//---------------------------------------------------------------------------
//解构函数
__fastcall TForm1::~TForm1()
{
//释放对象handle
::DeleteObject(FHClipRgn);
//释放Canvas
delete FScreenCanvas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//获取全屏幕DC
FScreenCanvas->Handle = ::GetDC(0);
//若有已选取区域handle存在，则删除此对象
if (FHClipRgn) ::DeleteObject(FHClipRgn);
//建立并选取与Image1相同的区块
RECT ClipRect = static_cast<RECT>(Image1->Parent->ClientRect);
//取得相对位置
::OffsetRect(&ClipRect,
             Image1->Parent->ClientOrigin.x,
             Image1->Parent->ClientOrigin.y);
//建立一矩形区域，并返回此区域handle
FHClipRgn = ::CreateRectRgnIndirect(&ClipRect);
//再将此区域选入DC，由全域Canvas主控绘制
::SelectClipRgn(FScreenCanvas->Handle, FHClipRgn);
//重设全域Canvas画笔模式
FScreenCanvas->Pen->Mode = pmNotXor;

//制作一网状图文件，以提供全域Canvas为画笔花纹
//GrayPattern[]是8*8位数组，0x55(16进位)是01010101(2进位)，0xaa是10101010，
//故建立一新网状图文件
const WORD GrayPattern[] = {0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa};
//若建立一新直线状图文件，则如下设置8*8位数组
//const WORD GrayPattern[] = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
HBITMAP GrayBitmap = ::CreateBitmap(8, 8, 1, 1, &GrayPattern);
Graphics::TBitmap *MBitmap = new Graphics::TBitmap();
MBitmap->Handle = GrayBitmap;
//将此画笔花纹指派给全域Canvas
FScreenCanvas->Brush->Bitmap = MBitmap;

//取得Image1可移动范围
::GetWindowRect(Image1->Parent->Handle, &FDragRect);
::OffsetRect(&FDragRect, Image1->Left, Image1->Top);
FDragRect.right = FDragRect.left + Image1->Width;
FDragRect.bottom = FDragRect.top + Image1->Height;

//修正网状区域的出现相对位置
int offint = Height - ClientHeight;
FDragPoint = Point(X, Y-offint);
//确定为鼠标左键单击状态
if(Button == mbLeft)
   bDragging = true;
bFirstDraw = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//当鼠标移动时，不断消去原网状区域
//并在新相对位置绘上新网状区域
if (bDragging)
    {
    //消去原网状区域(XOR)
    if (!bFirstDraw)
        {
        FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                                 FDragRect.right, FDragRect.bottom);
        }
    else
        bFirstDraw = false;
    //在新相对位置绘制新网状区域(XOR)
    ::OffsetRect(&FDragRect, X - FDragPoint.x, Y - FDragPoint.y);
    FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                             FDragRect.right, FDragRect.bottom);
    //更正鼠标拖曳位置
    FDragPoint = Point(X, Y);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Button == mbLeft)
  {
  //消去最后的网状区域(XOR)
  FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                           FDragRect.right, FDragRect.bottom);
  //恢复全域Canvas原有设置
  FScreenCanvas->Pen->Mode = pmCopy;
  FScreenCanvas->Brush->Style = bsSolid;
  //释放全域Canvas DC
  ::ReleaseDC(0, FScreenCanvas);
  //将Image1移动至新位置
  ::OffsetRect(&FDragRect,
               -Image1->Parent->ClientOrigin.x,
               -Image1->Parent->ClientOrigin.y);
  //而Image1维持原有外围
  Image1->BoundsRect = FDragRect;
  }
//确定鼠标左键在放开状态
bDragging = false;
}
//---------------------------------------------------------------------------

