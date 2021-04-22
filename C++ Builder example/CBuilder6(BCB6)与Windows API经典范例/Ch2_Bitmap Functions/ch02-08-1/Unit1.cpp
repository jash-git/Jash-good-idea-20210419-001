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
Graphics::TBitmap* Bitmap = Image1->Picture->Bitmap;
//声明RGB色盘数组
RGBQUAD rgbQ[256];
memset(rgbQ, 0, 256);
//取得Image1的色盘，并逐一修改颜色
if (::GetDIBColorTable(Bitmap->Canvas->Handle, 0, 256, rgbQ))
   {
   for (int index = 0; index < 256; index++)
      {
      // floor函数 #include <math>
      //取出色盘中每一RGB加以平均，再提升亮度
      //此方法并非惟一取值方式
      int gray = floor((rgbQ[index].rgbBlue +
                        rgbQ[index].rgbGreen +
                        rgbQ[index].rgbRed)/3*1.05);
      //限制颜色范围
      if(gray <= 0) gray = 0;
      if(gray >= 255) gray = 255;
      //当RGB同为一值时，即显示为灰阶
      rgbQ[index].rgbBlue = (byte)gray;
      rgbQ[index].rgbGreen = (byte)gray;
      rgbQ[index].rgbRed = (byte)gray;
      }
   //将设好之色盘，指派给Image1使用
   ::SetDIBColorTable(Bitmap->Canvas->Handle, 0, 256, rgbQ);
   //重绘Image1
   Image1->Repaint();
   }
}
//---------------------------------------------------------------------------
