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

Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;
Graphics::TBitmap *Bitmap2 = Image1->Picture->Bitmap;
AnsiString FileName = "C:\\temp\\test256colors.bmp";

int InfoHeaderSize, ImageSize;
//GetDIBSizes �� BCB Graphics utilities
//ȡ��ͼ�ļ���Ϣ���ڴ��С��handle
GetDIBSizes(Bitmap->Handle, InfoHeaderSize, ImageSize);
//����ͼ�ļ���Ϣ��Ҫ�Ŀռ�
const int size = sizeof(BITMAPINFOHEADER) + (256 * sizeof(RGBQUAD));

unsigned char* info_buffer = new unsigned char[size];
unsigned char* bits = new unsigned char[ImageSize];
try
   {
   //BITMAPINFO�ṹ��Ա����BITMAPINFOHEADER �� RGBQUAD 2����Ա��
   LPBITMAPINFO lpbmi = reinterpret_cast<LPBITMAPINFO>(info_buffer);

   //GetDIB �� BCB Graphics utilities
   //��DDBͼ�θ�ʽת��DIBͼ�θ�ʽ
   if (GetDIB(Bitmap->Handle, Bitmap2->Palette, lpbmi, bits))
      {
      //ͼ�ļ�handle�ṹ
      BITMAPFILEHEADER bmfh;
      //�Ƚ��ڴ��������
      ::ZeroMemory(&bmfh, sizeof(BITMAPFILEHEADER));
      bmfh.bfType =0x4d42;// "BM" Bitmap��׼��ʽ
      bmfh.bfSize = sizeof(BITMAPFILEHEADER) +
                          lpbmi->bmiHeader.biSize +
                          lpbmi->bmiHeader.biSizeImage;
      bmfh.bfReserved1 = 0;// ����Ϊ0
      bmfh.bfReserved2 = 0; // ����Ϊ0
      bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) +
                              lpbmi->bmiHeader.biSize;
      //����һ�����ļ�
      HANDLE HFile = ::CreateFile(FileName.c_str(),
                                  GENERIC_READ | GENERIC_WRITE,
                                  0, NULL, CREATE_ALWAYS,
                                  FILE_ATTRIBUTE_NORMAL, NULL);
      //���ɹ����ͽ�Ԥ������bitmap��Ϣд������ļ�
      if (HFile != INVALID_HANDLE_VALUE)
          {
          DWORD dwWritten;

          lpbmi->bmiHeader.biBitCount = 8;
          lpbmi->bmiHeader.biClrUsed = 256;
          //lpbmi->bmiHeader.biClrImportant = 256;

          //��һ��ͼ�ļ�����д���ļ��У�
          //��ע��--д���ļ����ݵ�˳��
          ::WriteFile(HFile, &bmfh, sizeof(BITMAPFILEHEADER),
                      &dwWritten, NULL);

          ::WriteFile(HFile, &lpbmi->bmiHeader, sizeof(BITMAPINFOHEADER),
                      &dwWritten, NULL);

          ::WriteFile(HFile, bits, lpbmi->bmiHeader.biSizeImage,
                      &dwWritten, NULL);

          ::WriteFile(HFile, &lpbmi->bmiColors,  256 * sizeof(RGBQUAD),
                      &dwWritten, NULL);

          Memo1->Text = "�bC:\\TEMP\\�½���һ��256ɫͼ�ļ�(test256colors.bmp)";
          //�ͷ�handle
          ::CloseHandle(HFile);

          }
      }
   }
catch (...)
   {
   delete [] info_buffer;
   delete [] bits;
   }
delete [] info_buffer;
delete [] bits;

//delete Bitmap;
//delete Bitmap2;

//
//Image1->Picture->LoadFromFile("C:\\TEMP\\test256colors.bmp");
}
//---------------------------------------------------------------------------
