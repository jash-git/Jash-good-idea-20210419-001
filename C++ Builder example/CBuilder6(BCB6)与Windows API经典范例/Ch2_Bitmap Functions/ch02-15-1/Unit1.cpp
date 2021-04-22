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
//ScrollBar1����
ScrollBar1->Max = 255;
//��Image1���Ƴ�һ��ͼ�񣬡A
//��ͼ����Ϊ��Դͼ��
Sourmap = new Graphics::TBitmap();
Sourmap->Width = Image1->Picture->Bitmap->Width;
Sourmap->Height = Image1->Picture->Bitmap->Height;
Sourmap->Assign(Image1->Picture->Bitmap);
Sourmap->PixelFormat = pf24bit;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete Sourmap;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����һ8λ(256ɫ)DIB��ʱͼ��
Graphics::TBitmap* Tmpmap = new Graphics::TBitmap();
Tmpmap->Width = Sourmap->Width;
Tmpmap->Height = Sourmap->Height;
Tmpmap->HandleType = bmDIB;
Tmpmap->PixelFormat = pf8bit;
//���ô���ʱͼ���256ɫɫ��
RGBQUAD rgbQ[256];
for (int index = 0; index < 256; index++)
   {
   rgbQ[index].rgbRed = static_cast<unsigned char>(index);
   rgbQ[index].rgbBlue = static_cast<unsigned char>(index);
   rgbQ[index].rgbGreen = static_cast<unsigned char>(255-index);
   rgbQ[index].rgbReserved = 0;
   }
//��256ɫ��ָ�ɸ�����ʱͼ��
::SetDIBColorTable(Tmpmap->Canvas->Handle,
                   ScrollBar1->Position,
                   256, rgbQ);

//������Դͼ����ͼ����256ɫ��ʱͼ����
//������ɫ��˳��Ի�ɫ��
::BitBlt(Tmpmap->Canvas->Handle, 0, 0,
         Sourmap->Width,
         Sourmap->Height,
         Sourmap->Canvas->Handle,
         0, 0,
         SRCCOPY);
//�����256ɫת������ʱͼ��ָ�ɸ�Image1
Image1->Picture->Bitmap->Assign(Tmpmap);
//����Image1ͼ��
Image1->Refresh();
delete Tmpmap;
}
//---------------------------------------------------------------------------
//��Form1������ʾ256ɫ�̵���ʼ��ɫ
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
Caption = "256ɫ��������,��ʼ��ɫ�ڵ�" +
          AnsiString(ScrollBar1->Position) +
          " ����λ��";
}
//---------------------------------------------------------------------------

