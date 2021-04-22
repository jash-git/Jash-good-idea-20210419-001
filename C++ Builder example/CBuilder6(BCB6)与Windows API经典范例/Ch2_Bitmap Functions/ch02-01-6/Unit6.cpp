//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��CheckBox1����
CheckBox1->Checked = false;

//�����Զ���Ⱦ�С�ڵ����ͼ�ļ�
//������һ��ͼ�ļ���20x20λͼ�Ĺ̶�����
gridBitmap = new Graphics::TBitmap();
gridBitmap->Width = 20;
gridBitmap->Height = 20;
gridBitmap->Canvas->Brush->Color = (TColor)RGB(220,255,220);
gridBitmap->Canvas->Pen->Color = (TColor)RGB(0,170,90);
gridBitmap->Canvas->FillRect(gridBitmap->Canvas->ClipRect);
//����ͼ�ļ����沼���Ⱦ�С��
const int spacing = 10;
for (y = 0; y < 20; y = y + spacing)
    {
    for (x = 0; x < 20; x = x + spacing)
        {
        gridBitmap->Canvas->Ellipse(x, y, x + 2, y + 2);
        }
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::~TForm1()
{
//��������ʱ���ͷ���ͼ�ļ�
delete gridBitmap;
}
//---------------------------------------------------------------------------
//��ÿ���ػ�Form1ʱ���㽫��ͼ�ļ��Ⱦ�浽Form1�ϣ��A
//��������Form1����
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//ȡ��Form1����
const int width = ClientWidth;
const int height = ClientHeight;
//
if(CheckBox1->Checked)
  {
  //����ͼ�ļ��������Ƶ�Form1������
  HDC HdcDest = Canvas->Handle;
  HDC HdcSource = gridBitmap->Canvas->Handle;
  for (y = 0; y < height; y = y + 20)
     {
     for (x = 0; x < width; x = x + 20)
        {
        ::BitBlt(HdcDest, x, y, 20, 20,
                 HdcSource, 0, 0,
                 SRCCOPY);
        }
     }
  }
else
  {
  //���ڴ�������һ��ͼ�ļ�
  //�bUnit6.h���[�J #include <memory>
  std::auto_ptr<Graphics::TBitmap> BackGr(new Graphics::TBitmap());
  BackGr->Width = ClientWidth;
  BackGr->Height = ClientHeight;
  //������ͼ�ļ�����
  BackGr->Canvas->Brush->Color = (TColor)RGB(255,230,255);
  BackGr->Canvas->Brush->Style = bsDiagCross;
  BackGr->Canvas->FillRect(BackGr->Canvas->ClipRect);
  //����ͼ�ļ����Ƶ�Form1������
  ::BitBlt(Canvas->Handle, 0, 0,
           BackGr->Width, BackGr->Height,
           BackGr->Canvas->Handle, 0, 0,
           SRCINVERT);
  }
}
//---------------------------------------------------------------------------
//���㰴CheckBoxʱ���ػ�Form1����
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
Form1->Refresh();
Form1->OnPaint;
}
//---------------------------------------------------------------------------

