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
//������ҷʱ��״̬
FDragging = false;
//Ĭ��ImageList1ͼ����ֵ�λ��
DrawP = Point(ClientWidth/2, ClientHeight/3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//��Form1���л�������ImageList1�ĵ�һ��ͼ��
ImageList1->Draw(Canvas, DrawP.x, DrawP.y, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//�������ImageList1ͼ��Χ�ڣ��������
if (X > DrawP.x && X < DrawP.x + ImageList1->Width &&
     Y > DrawP.y && Y < DrawP.y + ImageList1->Height)
   {
   ClickP = ClientToScreen(Point(X, Y));
   //��ʱ��ס���ڸ��¶���
   ::LockWindowUpdate(::GetDesktopWindow());
   //������ҷImageList1ͼ��
   ImageList1->SetDragImage(0, X-DrawP.x, Y-DrawP.y);
   //��ʼ��ҷImageList1ͼ��
   ImageList1->BeginDrag(::GetDesktopWindow(),
                         ClickP.x, ClickP.y);
   //����OnMouseMove�¼�
   FDragging = true;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
if(FDragging)
  {
  //�����ͼ����Ե��ƶ�
  TPoint P = ClientToScreen(Point(X, Y));
  ImageList1->DragMove(P.x, P.y);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
if(FDragging)
  {
  //�ſ�������ʱ����������ҷ����������´���
  ImageList1->EndDrag();
  ::LockWindowUpdate(NULL);

  //�ٸ����������ƶ�����λ�ã�
  //��ָ�ɸ��´���ҷʱ�Ŀ�ʼλ��
  TPoint P = ClientToScreen(Point(X, Y));
  DrawP.x = DrawP.x + (P.x - ClickP.x);
  DrawP.y = DrawP.y + (P.y - ClickP.y);
  Refresh();
  FDragging = false;
  }
}
//---------------------------------------------------------------------------

