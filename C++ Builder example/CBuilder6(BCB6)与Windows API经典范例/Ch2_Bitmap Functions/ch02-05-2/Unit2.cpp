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
Image1 = new TImage(this);
Image1->Parent = Form1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete Image1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����BITMAPINFO�ṹ��Ա
BITMAPINFO Bmi;
//������������ڴ�
::ZeroMemory(&Bmi.bmiHeader,sizeof(Bmi.bmiHeader));
Bmi.bmiHeader.biSize=sizeof(Bmi.bmiHeader);
Bmi.bmiHeader.biWidth= 300;
Bmi.bmiHeader.biHeight=-300; //�����Ͻǿ�ʼ����
Bmi.bmiHeader.biPlanes=1;
Bmi.bmiHeader.biBitCount=24; //24λ R,G,B 255*255*255
Bmi.bmiHeader.biCompression=BI_RGB;
BYTE *Pix;
//���ڴ��д���һ��ͼ�ļ�
::CreateDIBSection(0,&Bmi,DIB_RGB_COLORS,(void **)&Pix,0,0);
//ʹĿǰGDI�ػ�
::GdiFlush();

//ֱ���޸��ڴ���λͼ
BYTE *p=Pix;
BYTE r,g,b;
for (int x=0;x<300;x++)
  for (int y=0; y<300;y++)
    {
    r=128.0+127.0*sin(0.1*x);
    g=128.0+127.0*cos(0.1*y);
    b=sqrt(x*x+y*y);//���o����
    *p++=b;
    *p++=g;
    *p++=r;
    }

//��ͼ������Image1��
Image1->Picture->Bitmap->Width=300;
Image1->Picture->Bitmap->Height=300;
HDC hdc = Image1->Picture->Bitmap->Canvas->Handle;
::SetDIBitsToDevice(hdc,
                    30,30, 300,300,
                    60,60, 0,300,
                    Pix,&Bmi,DIB_RGB_COLORS);

//����Image1��Form1λ��
Form1->ClientWidth=300;
Form1->ClientHeight=300;
Image1->Stretch = true;
Image1->Align = alClient;
}
//---------------------------------------------------------------------------

