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
//设置PaintBox1位置
PaintBox1->Align = alClient;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//更新PaintBox1画面
PaintBox1->Refresh();
//取得目的图像DC handle
HDC HDestDC = PaintBox1->Canvas->Handle;
//取得来源图像DC handle
HDC HSourceDC = Image1->Canvas->Handle;
//简化程序代码
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;
//设置变形用之变量
int dest_height = Bitmap->Height;
int y_pos1 = 0, y_pos2 = 0;

for (int col = 0; col < Bitmap->Width; col++)
   {
   //先将Image1逐行缩短变形
   ::StretchBlt(HDestDC,           //目的图像
                col, y_pos1,       //X,Y
                1, dest_height,    //宽.高
                HSourceDC,         //来源图像
                col, 0,            //X,Y
                1, Bitmap->Height, //宽.高
                SRCCOPY);
   //再将PaintBox1逐行移动位置
   ::StretchBlt(HDestDC,           //目的图像
                col, 0,            //X,Y
                1, Bitmap->Height, //宽.高
                HDestDC,           //来源图像
                col, y_pos2,       //X,Y
                1, Bitmap->Height, //宽.高
                SRCCOPY);
   //为第一次StretchBlt使用
   //每过 1 行，即调整高度
   if (col % 2 == 0)
      {
      y_pos1++;
      dest_height--;
      }
   //为第二次StretchBlt使用
   //每过 2 行，即移动位置
   if(col%4 == 0)
      y_pos2++;
   }
}
//---------------------------------------------------------------------------

