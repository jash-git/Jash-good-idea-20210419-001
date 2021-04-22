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
void __fastcall TForm1::FormPaint(TObject *Sender)
{
//ȡ��Form1�����ɼ���Χ
const int width = ClientWidth;
const int height = ClientHeight - StaticText1->Height;
//Ĭ��256ɫ��ɫ�̣�ָ�ɸ���ͼ�ļ�
RGBQUAD setcolor[256];
for(int i=0; i<256; i++)
   {
   setcolor[i].rgbBlue = (byte)i;
   setcolor[i].rgbGreen = (byte)(255-i);
   setcolor[i].rgbRed = (byte)i;
   setcolor[i].rgbReserved = 0;
   }
//����һ��ɫ��ָ������ɫ����ΪbrushĬ��ɫ��
setcolor[0].rgbBlue = (byte) 255;
setcolor[0].rgbGreen = (byte)255;
setcolor[0].rgbRed = (byte) 255;
setcolor[0].rgbReserved = 0;

//��һ���� BITMAPINFO �ṹ
BITMAPINFO BitmapInfo;
::ZeroMemory(&BitmapInfo, sizeof(BITMAPINFO));

BitmapInfo.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
BitmapInfo.bmiHeader.biWidth = width;
BitmapInfo.bmiHeader.biHeight = -height;//�����Ͻǻ���
BitmapInfo.bmiHeader.biPlanes = 1;
BitmapInfo.bmiHeader.biBitCount = 8;//8 λ 256ɫ
BitmapInfo.bmiHeader.biCompression = BI_RGB;//δѹ��״̬
//����256ɫ��ɫ��
BitmapInfo.bmiColors[256] = setcolor[256];
//ָ���DIBλ
BYTE *Data;
//����һDIBSectionͼ��
HBITMAP HBitmap =
    ::CreateDIBSection(0, &BitmapInfo, DIB_RGB_COLORS,
                       (void **)&Data, NULL, NULL);
if (HBitmap)
    {
    //����ÿ��������ֽ�
    int BytesPerLine =
         BitmapInfo.bmiHeader.biWidth * BitmapInfo.bmiHeader.biBitCount / 8;
    //bitmap�Ǵ����Ͻ�����
    for (int y = 0; y < height; y++)
        {
        int row = BytesPerLine * y;
        for (int x = 0; x < BytesPerLine; x++)
            {
            int bit = y;
            if(bit > 255) bit = 255-y;
            *(Data + x + row) = (BYTE) bit;
            }
        }

    //����һ��Form1���ݵ��ڴ�DC
    HDC Hdc = ::CreateCompatibleDC(Canvas->Handle);
    //�ٽ���DIBSectionѡ���DC��
    HBITMAP HOldBitmap = ::SelectObject(Hdc, HBitmap);

    //�����ڴ����ٻ���һ����
    ::Rectangle(Hdc,
                40, 40,
                width-40, height-40);
    //�N�O����ϧ�ø�s��Form1�W
    ::BitBlt(Canvas->Handle,
             0, 0, width, height,
             Hdc, 0, 0,
             SRCCOPY);

    //���ڴ�ͼ�λ�����Form1��
    ::SelectObject(Hdc, HOldBitmap);
    ::DeleteObject(HBitmap);
    }
}
//---------------------------------------------------------------------------
//��ԭ&�ͷ�HDC
void __fastcall TForm1::FormResize(TObject *Sender)
{
Repaint();    
}
//---------------------------------------------------------------------------

