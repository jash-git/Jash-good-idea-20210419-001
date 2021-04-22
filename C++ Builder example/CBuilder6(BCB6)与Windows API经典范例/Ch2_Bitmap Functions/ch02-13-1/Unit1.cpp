//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//在Form1建构式中
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), is_dragging_(false),
   Bitmap_(new Graphics::TBitmap()), ScreenCanvas_(new TCanvas())
{
//制造一单色位图交错图像，并备用
Bitmap_->Width = 8;
Bitmap_->Height = 8;
Bitmap_->PixelFormat = pf24bit;
//先删除Bitmap_图样
::PatBlt(Bitmap_->Canvas->Handle, 0, 0, 8, 8, WHITENESS);
//恶瓜ユ岿瓜
for (int y = 0; y < 8; y += 2)
   {
   RGBTRIPLE *rgbT = static_cast<RGBTRIPLE*>( Bitmap_->ScanLine[y]);
   for (int x = (y % 2 ? 0 : 1); x < 8; x += 2)
      {
      rgbT[x].rgbtBlue = 0;
      rgbT[x].rgbtGreen = 0;
      rgbT[x].rgbtRed = 0;
      }
   }
//重新确认Image1 & Panel1间之位置
Image1->AutoSize = true;
Panel1->Width = Image1->Width + 16;
Panel1->Height = Image1->Height + 16;
Image1->Top = 8;
Image1->Left = 8;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (Button == mbLeft)
   {
   //测试在内存中有否新图文件
   assert(ScreenCanvas_.get() != NULL);
   assert(Bitmap_.get() != NULL);
   //将Panel1范围转换为RECT结构
   RECT ClipRect =
        static_cast<RECT>( Panel1->Parent->ClientRect );
   //并且将实际偏移量指派给此RECT结构
   ::OffsetRect(&ClipRect,
                Panel1->Parent->ClientOrigin.x,
                Panel1->Parent->ClientOrigin.y
                );
   //创造此RECT区域并返回handle
   HRGN HClipRgn = ::CreateRectRgnIndirect(&ClipRect);
   if (HClipRgn)
      {
      try
        {
        //取得屏幕DC handle
        ScreenCanvas_->Handle = ::GetDC(NULL);
        //将Bitmap_内容指向ScreenCanvas
        ScreenCanvas_->Brush->Bitmap = Bitmap_.get();
        //从DC中选取得矩形区域
        ::SelectClipRgn(ScreenCanvas_->Handle, HClipRgn);
        }
      catch (...)
        {
        //若否，则释放DC & 删除矩形区域对象
        ::ReleaseDC(NULL, ScreenCanvas_->Handle);
        ::DeleteObject(HClipRgn);
        }
      ::DeleteObject(HClipRgn);
      //打开可拖曳矩形区域对象的开关
      is_dragging_ = true;
      //取得此矩形区域对象起始点
      PMouse_ = Point(X, Y);
      //此矩形区域对象长宽相同于Panel1长宽
      ::GetWindowRect(Panel1->Handle, &DragRect_);
      //自定义函数，将此矩形区域对象绘制成网状边框状态
      RenderTrackingRect(ScreenCanvas_->Handle, DragRect_);
      }
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if (is_dragging_)
  {
  //取得相对位置
  const int dX = X - PMouse_.x;
  const int dY = Y - PMouse_.y;

  const HDC HScreenDC = ScreenCanvas_->Handle;
  //自定义函数，将此矩形区域对象绘制成网状边框状态
  RenderTrackingRect(HScreenDC, DragRect_);
  //将此矩形区域对象偏移至新相对位置
  ::OffsetRect(&DragRect_, dX, dY);
  //自定义函数，将此矩形区域对象绘制成网状边框状态
  RenderTrackingRect(HScreenDC, DragRect_);
  //控制此矩形区域对象位置
  PMouse_ = Point(X, Y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (is_dragging_)
   {
   //关闭可拖曳矩形区域对象的开关
   is_dragging_ = false;
   //释放选取之矩形对象 & HDC
   ::SelectClipRgn(ScreenCanvas_->Handle, NULL);
   ::ReleaseDC(NULL, ScreenCanvas_->Handle);
   ScreenCanvas_->Handle = NULL;
   //将此矩形区域对象偏移至新相对位置
   ::OffsetRect(&DragRect_,
                -Panel1->Parent->ClientOrigin.x,
                -Panel1->Parent->ClientOrigin.y
                );
   //再确定Panel1外缘范围
   Panel1->BoundsRect = DragRect_;
   }
}
//---------------------------------------------------------------------------
//自定义函数，将此矩形区域对象绘制成网状边框状态
void TForm1::RenderTrackingRect(IN HDC HDestDC, IN RECT& RRender)
{
//配合Panel1到Image1边框距离
const int line_width = 8;
const int width = RRender.right - RRender.left;
const int height = RRender.bottom - RRender.top;
const DWORD dwROP3 = PATINVERT;

//将上方矩形区域填入位图交错图案
::PatBlt(HDestDC,
         RRender.left, RRender.top,
         width, line_width,
         dwROP3);
//将下方矩形区域填入位图交错图案
::PatBlt(HDestDC,
         RRender.left, RRender.bottom - line_width,
         width, line_width,
         dwROP3);
//将左方矩形区域填入位图交错图案
::PatBlt(HDestDC,
         RRender.left, RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);
//将右方矩形区域填入位图交错图案
::PatBlt(HDestDC,
         RRender.right - line_width, RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);

//将中间直立矩形区域填入位图交错图案
::PatBlt(HDestDC,
         (RRender.left + RRender.right-8)/2,
         RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);
//将中间横向矩形区域填入位图交错图案
::PatBlt(HDestDC,
         RRender.left + 8,
         (RRender.top + RRender.bottom -8)/2,
         width - 16, line_width,
         dwROP3);
}
//---------------------------------------------------------------------------

