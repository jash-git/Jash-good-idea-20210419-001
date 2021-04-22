//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int Col,
      int Row, TRect &Rect, TGridDrawState State)
{
//�����Ϸ�&�󷽱�����״̬
if (State.Contains(gdFixed))
   {
   //���õ�ɫ&��ɫ
   StringGrid1->Canvas->Brush->Color = (TColor)RGB(255,200,230);//clBtnFace;
   StringGrid1->Canvas->Font->Color = clWindowText;
   StringGrid1->Canvas->FillRect(Rect);
   //������άЧ��
   Frame3D(StringGrid1->Canvas, Rect, clBtnHighlight, clBtnShadow, 1);
   }

//���ñ�ѡȡ������״̬
else if (State.Contains(gdSelected))
   {
   //���õ�ɫ&��ɫ
   StringGrid1->Canvas->Brush->Color = (TColor)RGB(210,255,210);
   StringGrid1->Canvas->Font->Color = clHighlightText;
   StringGrid1->Canvas->FillRect(Rect);
   }

//���÷�ѡȡ������״̬
else
   {
   //������StringGrid1֮DC����
   StringGrid1->Canvas->Brush->Color = StringGrid1->Color;
   StringGrid1->Canvas->Font->Color = StringGrid1->Font->Color;
   //��Image1���θ�����StringGrid1��
   ::StretchBlt(StringGrid1->Canvas->Handle,
                Rect.Left,
                Rect.Top,
                Rect.Right - Rect.Left,
                Rect.Bottom - Rect.Top,
                Image1->Picture->Bitmap->Canvas->Handle,
                0, 0,
                Image1->Width, Image1->Height,
                SRCCOPY);
   }
//����StringGrid1�������ݲ����ű���
::SetBkMode(StringGrid1->Canvas->Handle, TRANSPARENT);
//���������ݻ�����ָ������
AnsiString text = StringGrid1->Cells[Col][Row];
RECT R = RECT(Rect);
::DrawText(StringGrid1->Canvas->Handle, text.c_str(),
           text.Length(), &R, DT_LEFT);

}
//---------------------------------------------------------------------------
