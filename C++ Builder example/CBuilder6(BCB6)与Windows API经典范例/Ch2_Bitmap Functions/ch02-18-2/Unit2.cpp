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
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//�ظ�����֮���λͼ
int GridSpace = 8;
//����һ��ͼ����Ϊƴ����Դ
Grid = new Graphics::TBitmap;
Grid->Width = ClientWidth;
Grid->Height = ClientHeight;
Grid->Canvas->Brush->Color = (TColor)RGB(140,140,255);
Grid->Canvas->FillRect( Grid->Canvas->ClipRect );
//λͼ����ı�ɫ��
for ( int y = 0 ; y < Grid->Height ; y += GridSpace )
  for ( int x = 0 ; x < Grid->Width ; x += GridSpace )
     {
     ::SetPixel( Grid->Canvas->Handle , x+1, y+1, RGB(0,50,0));
     ::SetPixel( Grid->Canvas->Handle , x, y, RGB(220,255,220));
     }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//�ͷ�ͼ��
delete Grid;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//����Ҫ�ػ�Form1ʱ������Gridͼ����Form1��
Canvas->CopyRect( Canvas->ClipRect, Grid->Canvas, Canvas->ClipRect );
}
//---------------------------------------------------------------------------

