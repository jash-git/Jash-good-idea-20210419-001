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
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormShow(TObject *Sender)
{
//ͼ��BITMAPINFO�ṹ����&����
BITMAPINFO Bmi;
// ����BITMAPINFO�ṹ�����ݮ�
ZeroMemory(&Bmi.bmiHeader,sizeof(Bmi.bmiHeader));
Bmi.bmiHeader.biSize=sizeof(Bmi.bmiHeader);
Bmi.bmiHeader.biWidth=200;
Bmi.bmiHeader.biHeight=-200; // ͼ��λͼ���϶�������
Bmi.bmiHeader.biPlanes=1;
Bmi.bmiHeader.biBitCount=24; //ɫ��Ϊ24λ(R,G,B��ɫ)
Bmi.bmiHeader.biCompression=BI_RGB;
BYTE *Pix;
//��BITMAPINFO�ṹ����һ24λ����ͼ�ļ�
::CreateDIBSection(0,&Bmi,DIB_RGB_COLORS,(void **)&Pix,0,0);
// ����Ŀǰ�̵߳�GDI���ƹ���
::GdiFlush();

// ֱ����λͼ�������У�����ָ��ͼ��
BYTE *p=Pix;
BYTE r,g,b;
for (int x=0;x<200;x++)
 for (int y=0; y<200;y++)
    {
    r=128.0+127.0*sin(0.1*x);
    g=128.0+127.0*cos(0.1*y);
    b=sqrt(x*x+y*y);
    *p++=b;
    *p++=g;
    *p++=r;
    }

// �����ú�Image1���λͼ�ĳ���
Image1->Picture->Bitmap->Width=200;
Image1->Picture->Bitmap->Height=200;
// ��λͼ��������ͼ����������Image1�����
::SetDIBitsToDevice(Image1->Picture->Bitmap->Canvas->Handle,
                    0,0,
                    200,200,
                    0,0, 0,200,
                    Pix,&Bmi,
                    DIB_RGB_COLORS);

//�������ӡ��Image1���������������form1�ϣ��Ա�۲�APIִ�гɹ�
Image1->Align = alClient;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
