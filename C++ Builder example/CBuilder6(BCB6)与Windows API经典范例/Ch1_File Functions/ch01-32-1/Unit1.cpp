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
//GetDIBSizes 是 BCB Graphics utilities
//取得图文件信息的内存大小与handle
GetDIBSizes(Bitmap->Handle, InfoHeaderSize, ImageSize);
//分配图文件信息需要的空间
const int size = sizeof(BITMAPINFOHEADER) + (256 * sizeof(RGBQUAD));

unsigned char* info_buffer = new unsigned char[size];
unsigned char* bits = new unsigned char[ImageSize];
try
   {
   //BITMAPINFO结构成员包含BITMAPINFOHEADER 与 RGBQUAD 2个成员
   LPBITMAPINFO lpbmi = reinterpret_cast<LPBITMAPINFO>(info_buffer);

   //GetDIB 是 BCB Graphics utilities
   //将DDB图形格式转成DIB图形格式
   if (GetDIB(Bitmap->Handle, Bitmap2->Palette, lpbmi, bits))
      {
      //图文件handle结构
      BITMAPFILEHEADER bmfh;
      //先将内存区块归零
      ::ZeroMemory(&bmfh, sizeof(BITMAPFILEHEADER));
      bmfh.bfType =0x4d42;// "BM" Bitmap标准格式
      bmfh.bfSize = sizeof(BITMAPFILEHEADER) +
                          lpbmi->bmiHeader.biSize +
                          lpbmi->bmiHeader.biSizeImage;
      bmfh.bfReserved1 = 0;// 必须为0
      bmfh.bfReserved2 = 0; // 必须为0
      bmfh.bfOffBits = sizeof(BITMAPFILEHEADER) +
                              lpbmi->bmiHeader.biSize;
      //建立一个新文件
      HANDLE HFile = ::CreateFile(FileName.c_str(),
                                  GENERIC_READ | GENERIC_WRITE,
                                  0, NULL, CREATE_ALWAYS,
                                  FILE_ATTRIBUTE_NORMAL, NULL);
      //若成功，就将预先设置bitmap信息写入此新文件
      if (HFile != INVALID_HANDLE_VALUE)
          {
          DWORD dwWritten;

          lpbmi->bmiHeader.biBitCount = 8;
          lpbmi->bmiHeader.biClrUsed = 256;
          //lpbmi->bmiHeader.biClrImportant = 256;

          //逐一将图文件数据写入文件中，
          //请注意--写入文件数据的顺序
          ::WriteFile(HFile, &bmfh, sizeof(BITMAPFILEHEADER),
                      &dwWritten, NULL);

          ::WriteFile(HFile, &lpbmi->bmiHeader, sizeof(BITMAPINFOHEADER),
                      &dwWritten, NULL);

          ::WriteFile(HFile, bits, lpbmi->bmiHeader.biSizeImage,
                      &dwWritten, NULL);

          ::WriteFile(HFile, &lpbmi->bmiColors,  256 * sizeof(RGBQUAD),
                      &dwWritten, NULL);

          Memo1->Text = "C:\\TEMP\\下建立一新256色图文件(test256colors.bmp)";
          //释放handle
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
