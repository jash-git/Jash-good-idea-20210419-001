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
//ȡ��Image1�� handle
HBITMAP Hbmp = Image1->Picture->Bitmap->Handle;
//����BITMAP�ṹ��Ա
BITMAP bmp;
//��Image1������BITMAP�ṹ�������
::GetObject(Hbmp, sizeof(BITMAP), &bmp);
//ȡ��ÿ��λͼ��ָ��ɫ��
bmp.bmBits = NULL;
//�ֽ���Ŀ��Ϊ 4 �ı�����ÿ��λͼ�ֽ�*���/4
//bmp.bmWidthBytes = (bmp.bmWidth/4)*4;
bmp.bmBitsPixel = 16; //16λɫ�����λͼ

//����bmp�ṹ����һ��ͼ�ļ�����ȡ��handle
HBITMAP HBitmap = ::CreateBitmapIndirect(&bmp);
//����һ���ض�DC���ݵ��ڴ�DC handle
HDC HMemoryDC = ::CreateCompatibleDC(0);
//��bmp����ѡȡ�������ڴ�DC��
HBITMAP HOldBitmap = ::SelectObject(HMemoryDC, HBitmap);
//��ȡ��Form1��DC handle
HDC hDC = ::GetDC(Form1->Handle);
//���ڴ����ͼ�ļ�������Form1��
::BitBlt(hDC, 10, 40,
         bmp.bmWidth, bmp.bmHeight,
         HMemoryDC,
         0, 0,
         SRCCOPY);

//��һ�ͷš���ԭ����& DC handle
::ReleaseDC(Form1->Handle, hDC);
::SelectObject(HMemoryDC, HOldBitmap);
::DeleteDC(HMemoryDC);
::DeleteObject(HBitmap);

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//����BITMAP�ṹ��Ա
BITMAP bmp;
bmp.bmType = 0;//����Ϊ0
bmp.bmWidth =120;//λͼ���
bmp.bmHeight = 52;//λͼ�߶�
bmp.bmPlanes = 1;//�豸������ӦΪ1
//��λ�������������ʮ��������ֵ��
static BYTE bit[12000];
BYTE b = 0x00;
for(int a=0;a<12000;a++)
   bit[a] = BYTE(b+(a/60));
bmp.bmBits = &bit;//ָ��λͼɫ��
//�ֽ���Ŀ��Ϊ 4 �ı�����ÿ��λͼ�ֽ�*���/4
bmp.bmWidthBytes = (bmp.bmWidth/4)*4;//�ֽڿ��
bmp.bmBitsPixel =16; //16λɫ�����λͼ

//����bmp�ṹ����һ��ͼ�ļ�����ȡ��handle
HBITMAP HBitmap = ::CreateBitmapIndirect(&bmp);
//����һ���ض�DC���ݵ��ڴ�DC handle
HDC HMemoryDC = ::CreateCompatibleDC(0);
//��bmp����ѡȡ�������ڴ�DC��
HBITMAP HOldBitmap = ::SelectObject(HMemoryDC, HBitmap);
//��ȡ��Form1��DC handle
HDC hDC = ::GetDC(Form1->Handle);
//���ڴ����ͼ�ļ�������Form1��
::BitBlt(hDC, 20+bmp.bmWidth, 40,
         bmp.bmWidth, bmp.bmHeight,
         HMemoryDC,
         0, 0,
         SRCCOPY);

//��һ�ͷš���ԭ����& DC handle
::ReleaseDC(Form1->Handle, hDC);
::SelectObject(HMemoryDC, HOldBitmap);
::DeleteDC(HMemoryDC);
::DeleteObject(HBitmap);
}
//---------------------------------------------------------------------------


