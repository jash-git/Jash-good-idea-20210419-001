//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
//��Form1����ʽ��
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner), is_dragging_(false),
   Bitmap_(new Graphics::TBitmap()), ScreenCanvas_(new TCanvas())
{
//����һ��ɫλͼ����ͼ�񣬲�����
Bitmap_->Width = 8;
Bitmap_->Height = 8;
Bitmap_->PixelFormat = pf24bit;
//��ɾ��Bitmap_ͼ��
::PatBlt(Bitmap_->Canvas->Handle, 0, 0, 8, 8, WHITENESS);
//�A��J�ϯ�����Ϯ�
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
//����ȷ��Image1 & Panel1��֮λ��
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
   //�������ڴ����з���ͼ�ļ�
   assert(ScreenCanvas_.get() != NULL);
   assert(Bitmap_.get() != NULL);
   //��Panel1��Χת��ΪRECT�ṹ
   RECT ClipRect =
        static_cast<RECT>( Panel1->Parent->ClientRect );
   //���ҽ�ʵ��ƫ����ָ�ɸ���RECT�ṹ
   ::OffsetRect(&ClipRect,
                Panel1->Parent->ClientOrigin.x,
                Panel1->Parent->ClientOrigin.y
                );
   //�����RECT���򲢷���handle
   HRGN HClipRgn = ::CreateRectRgnIndirect(&ClipRect);
   if (HClipRgn)
      {
      try
        {
        //ȡ����ĻDC handle
        ScreenCanvas_->Handle = ::GetDC(NULL);
        //��Bitmap_����ָ��ScreenCanvas
        ScreenCanvas_->Brush->Bitmap = Bitmap_.get();
        //��DC��ѡȡ�þ�������
        ::SelectClipRgn(ScreenCanvas_->Handle, HClipRgn);
        }
      catch (...)
        {
        //�������ͷ�DC & ɾ�������������
        ::ReleaseDC(NULL, ScreenCanvas_->Handle);
        ::DeleteObject(HClipRgn);
        }
      ::DeleteObject(HClipRgn);
      //�򿪿���ҷ�����������Ŀ���
      is_dragging_ = true;
      //ȡ�ô˾������������ʼ��
      PMouse_ = Point(X, Y);
      //�˾���������󳤿���ͬ��Panel1����
      ::GetWindowRect(Panel1->Handle, &DragRect_);
      //�Զ��庯�������˾������������Ƴ���״�߿�״̬
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
  //ȡ�����λ��
  const int dX = X - PMouse_.x;
  const int dY = Y - PMouse_.y;

  const HDC HScreenDC = ScreenCanvas_->Handle;
  //�Զ��庯�������˾������������Ƴ���״�߿�״̬
  RenderTrackingRect(HScreenDC, DragRect_);
  //���˾����������ƫ���������λ��
  ::OffsetRect(&DragRect_, dX, dY);
  //�Զ��庯�������˾������������Ƴ���״�߿�״̬
  RenderTrackingRect(HScreenDC, DragRect_);
  //���ƴ˾����������λ��
  PMouse_ = Point(X, Y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if (is_dragging_)
   {
   //�رտ���ҷ�����������Ŀ���
   is_dragging_ = false;
   //�ͷ�ѡȡ֮���ζ��� & HDC
   ::SelectClipRgn(ScreenCanvas_->Handle, NULL);
   ::ReleaseDC(NULL, ScreenCanvas_->Handle);
   ScreenCanvas_->Handle = NULL;
   //���˾����������ƫ���������λ��
   ::OffsetRect(&DragRect_,
                -Panel1->Parent->ClientOrigin.x,
                -Panel1->Parent->ClientOrigin.y
                );
   //��ȷ��Panel1��Ե��Χ
   Panel1->BoundsRect = DragRect_;
   }
}
//---------------------------------------------------------------------------
//�Զ��庯�������˾������������Ƴ���״�߿�״̬
void TForm1::RenderTrackingRect(IN HDC HDestDC, IN RECT& RRender)
{
//���Panel1��Image1�߿����
const int line_width = 8;
const int width = RRender.right - RRender.left;
const int height = RRender.bottom - RRender.top;
const DWORD dwROP3 = PATINVERT;

//���Ϸ�������������λͼ����ͼ��
::PatBlt(HDestDC,
         RRender.left, RRender.top,
         width, line_width,
         dwROP3);
//���·�������������λͼ����ͼ��
::PatBlt(HDestDC,
         RRender.left, RRender.bottom - line_width,
         width, line_width,
         dwROP3);
//���󷽾�����������λͼ����ͼ��
::PatBlt(HDestDC,
         RRender.left, RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);
//���ҷ�������������λͼ����ͼ��
::PatBlt(HDestDC,
         RRender.right - line_width, RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);

//���м�ֱ��������������λͼ����ͼ��
::PatBlt(HDestDC,
         (RRender.left + RRender.right-8)/2,
         RRender.top + line_width,
         line_width, height - (2 * line_width),
         dwROP3);
//���м���������������λͼ����ͼ��
::PatBlt(HDestDC,
         RRender.left + 8,
         (RRender.top + RRender.bottom -8)/2,
         width - 16, line_width,
         dwROP3);
}
//---------------------------------------------------------------------------

