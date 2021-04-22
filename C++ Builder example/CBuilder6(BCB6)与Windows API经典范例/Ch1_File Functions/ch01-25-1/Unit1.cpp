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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1����������
Memo1->Clear();
//��Bitmap��Image1ͼ�ļ����
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

//ȡ��ָ���ļ�������·��
char cdir[MAX_PATH];
char *bfile = "//BIT-8-256.bmp";
//����������Ŀ¼����������ַ�����
::GetCurrentDirectory( MAX_PATH, cdir);
//������Ŀ¼����ָ���ļ���
strcat( cdir, bfile);
//����ͼ�ļ��ṹ
BITMAPFILEHEADER bmfh;
BITMAPINFOHEADER bmih;
//��ָ���ļ�
HANDLE HFile = ::CreateFile(cdir, GENERIC_READ,
                            0, NULL,
                            OPEN_EXISTING,
                            FILE_ATTRIBUTE_NORMAL, NULL);
//
if (HFile != INVALID_HANDLE_VALUE)
   {
   DWORD dwRead;
   //ȡ��ͼ�ļ��ṹ���������
   ::ReadFile(HFile, &bmfh, sizeof(BITMAPFILEHEADER), &dwRead, NULL);
   ::ReadFile(HFile, &bmih, sizeof(BITMAPINFOHEADER), &dwRead, NULL);
   //����һ����ʱ���ã�����ͼ�ļ�16λת��8λʱ�����
   BITMAPINFO bmi;
   //��bmi�ṹ�����ڴ��ʼ���l��
   memset(&bmi, 0, sizeof(BITMAPINFO));
   //BITMAPINFO�ṹ����BITMAPINFOHEADER�ṹ+RGBQUAD�ṹ
   //����BITMAPINFOHEADER�ṹ��Ա��
   bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);//�ṹ��С�p
   bmi.bmiHeader.biWidth = Bitmap->Width;//ͼ�ؿ��
   bmi.bmiHeader.biHeight = Bitmap->Height; //ͼ�ظ߶�
   bmi.bmiHeader.biPlanes = 1;//Ŀ��װ��ƽ��������Ϊ1
   //ת���� 16 λ����
   bmi.bmiHeader.biBitCount = 16; //16λ����
   bmi.bmiHeader = bmih;

//����RGBQUAD�ṹ��Ա
DWORD BitMasks[3];
BitMasks[0] = 0xFFFF;//Blue������
BitMasks[1] = 0xFFFF;//Green������
BitMasks[2] = 0xFFFF;//Red��������
//����õ�RGB�ṹ����RGBQUAD�ṹ
memcpy(bmi.bmiColors, BitMasks, sizeof(BitMasks));
unsigned char *bits;
//��BITMAPINFO�ṹ����һ��DIBͼ�ļ���������handle
//������ָ��DC���ݵ�DC
HDC Hdc = ::CreateCompatibleDC(0);
//��BITMAPINFO�ṹ����һ��DIBͼ�ļ���������handle
HBITMAP HBmp = ::CreateDIBitmap(Hdc, &bmih, CBM_INIT,
                                (BYTE *)sizeof(bmi) + bmi.bmiHeader.biSize,
                                &bmi,
                                DIB_RGB_COLORS);

   //������ָ��DC���ݵ�DC
//   HDC Hdc = ::CreateCompatibleDC(0);
   //�˴����ն���ͼ�ļ��Ľṹ�����ͼ����Form1��Image1��
   HDC hdc = ::GetDC(Image1->Canvas->Handle);
    //ѡ���¶��󣬲�����ԭ�ж�������
//    HBITMAP HOldBmp = ::SelectObject(Hdc, hdc);
if (HBmp)
    {
   //����Image����ͼ������ʱ�豸
   ::BitBlt(hdc, 0, 0,
            bmih.biWidth, bmih.biHeight,//Image1->Width*5, Image1->Height*5,//
            Hdc, 0, 0,
            SRCCOPY);

   Memo1->Lines->Add("�ɹ���ȡͼ�ļ���");
   }
   }
else
   Memo1->Lines->Add("��ȡͼ�ļ�ʧ�ܣ�");
//�ͷ�handle
::CloseHandle(HFile);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ɾ��Memo1����������
Memo1->Clear();
//Ԥ�ȸ�֪�����Ϣ
Memo1->Lines->Add("�����ڳ���ͬһĿ¼������һaaa.txt�ı��ļ���");

char buf[MAX_PATH];
DWORD bytesread;

char dir[MAX_PATH];
char *tfile = "/aaa.txt";
//����������Ŀ¼����������ַ�����
::GetCurrentDirectory( MAX_PATH, dir);
//������Ŀ¼����ָ���ļ���
strcat( dir, tfile);
//���ı��ļ�
HANDLE hFile = ::CreateFile(dir, GENERIC_READ,
                            FILE_SHARE_READ | FILE_SHARE_WRITE,
                            NULL,
                            OPEN_EXISTING,
                            FILE_FLAG_SEQUENTIAL_SCAN, NULL);

//��ȡָ���ļ��ַ����飬������buf��
if(::ReadFile(hFile, buf, sizeof(buf), &bytesread, NULL))
   {
   Memo1->Lines->Add(buf);
   Memo1->Lines->Add("�ɹ���ȡ�ı��ļ���");
   }
else
   Memo1->Lines->Add("��ȡ�ı��ļ�ʧ�ܣ�");
//�ͷ�handle
::CloseHandle(hFile);
}
//---------------------------------------------------------------------------





