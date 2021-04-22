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
//��CanvasΪȫ������
FScreenCanvas = new TCanvas();
//�����Ƿ�Ϊ����������״̬
bDragging = false;
}
//---------------------------------------------------------------------------
//�⹹����
__fastcall TForm1::~TForm1()
{
//�ͷŶ���handle
::DeleteObject(FHClipRgn);
//�ͷ�Canvas
delete FScreenCanvas;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//��ȡȫ��ĻDC
FScreenCanvas->Handle = ::GetDC(0);
//������ѡȡ����handle���ڣ���ɾ���˶���
if (FHClipRgn) ::DeleteObject(FHClipRgn);
//������ѡȡ��Image1��ͬ������
RECT ClipRect = static_cast<RECT>(Image1->Parent->ClientRect);
//ȡ�����λ��
::OffsetRect(&ClipRect,
             Image1->Parent->ClientOrigin.x,
             Image1->Parent->ClientOrigin.y);
//����һ�������򣬲����ش�����handle
FHClipRgn = ::CreateRectRgnIndirect(&ClipRect);
//�ٽ�������ѡ��DC����ȫ��Canvas���ػ���
::SelectClipRgn(FScreenCanvas->Handle, FHClipRgn);
//����ȫ��Canvas����ģʽ
FScreenCanvas->Pen->Mode = pmNotXor;

//����һ��״ͼ�ļ������ṩȫ��CanvasΪ���ʻ��ƪ᯾
//GrayPattern[]��8*8λ���飬0x55(16��λ)��01010101(2��λ)��0xaa��10101010��
//�ʽ���һ����״ͼ�ļ�
const WORD GrayPattern[] = {0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa, 0x55, 0xaa};
//������һ��ֱ��״ͼ�ļ�������������8*8λ����C
//const WORD GrayPattern[] = {0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55};
HBITMAP GrayBitmap = ::CreateBitmap(8, 8, 1, 1, &GrayPattern);
Graphics::TBitmap *MBitmap = new Graphics::TBitmap();
MBitmap->Handle = GrayBitmap;
//���˻��ʻ���ָ�ɸ�ȫ��Canvas
FScreenCanvas->Brush->Bitmap = MBitmap;

//ȡ��Image1���ƶ���Χ
::GetWindowRect(Image1->Parent->Handle, &FDragRect);
::OffsetRect(&FDragRect, Image1->Left, Image1->Top);
FDragRect.right = FDragRect.left + Image1->Width;
FDragRect.bottom = FDragRect.top + Image1->Height;

//������״����ĳ������λ��
int offint = Height - ClientHeight;
FDragPoint = Point(X, Y-offint);
//ȷ��Ϊ����������״̬
if(Button == mbLeft)
   bDragging = true;
bFirstDraw = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//������ƶ�ʱ��������ȥԭ��״����
//���������λ�û�������״����
if (bDragging)
    {
    //��ȥԭ��״����(XOR)
    if (!bFirstDraw)
        {
        FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                                 FDragRect.right, FDragRect.bottom);
        }
    else
        bFirstDraw = false;
    //�������λ�û�������״����(XOR)
    ::OffsetRect(&FDragRect, X - FDragPoint.x, Y - FDragPoint.y);
    FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                             FDragRect.right, FDragRect.bottom);
    //���������ҷλ��
    FDragPoint = Point(X, Y);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(Button == mbLeft)
  {
  //��ȥ������״����(XOR)
  FScreenCanvas->Rectangle(FDragRect.left, FDragRect.top,
                           FDragRect.right, FDragRect.bottom);
  //�ָ�ȫ��Canvasԭ������
  FScreenCanvas->Pen->Mode = pmCopy;
  FScreenCanvas->Brush->Style = bsSolid;
  //�ͷ�ȫ��Canvas DC
  ::ReleaseDC(0, FScreenCanvas);
  //��Image1�ƶ�����λ��
  ::OffsetRect(&FDragRect,
               -Image1->Parent->ClientOrigin.x,
               -Image1->Parent->ClientOrigin.y);
  //��Image1ά��ԭ����Χ
  Image1->BoundsRect = FDragRect;
  }
//ȷ���������ڷſ�״̬
bDragging = false;
}
//---------------------------------------------------------------------------

