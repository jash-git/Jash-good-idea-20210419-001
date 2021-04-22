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
//图像BITMAPINFO结构声明&设置
BITMAPINFOHEADER bmih = {
  sizeof(BITMAPINFOHEADER), //结构大小
  Image1->Width, //位图宽度
  Image1->Height, //位图高度
  1, // 色层数目
  24, //每一位图的位数目
  BI_RGB, //是否为压缩图文件
  0, //总字节，若无压缩(BI_RGB)，则可设为 0
  0, //X轴最佳输出分辨率
  0, //Y轴最佳输出分辨率
  0, //使用颜色数目(RGBQUAD数组数目)，若为0，则使用最大颜色数目
  0 //主要使用颜色数目
  };
//若图文件在8位(256色)以上，设置此色彩结构则无作用
RGBQUAD rgb0 = {0,0,0,0};
//整合至结构中
BITMAPINFO bmi;
bmi.bmiHeader = bmih;
bmi.bmiColors[0] = rgb0; //无色盘

//计算每列为多少字节
int RowSize = ((((Image1->Width + 1) * 3) / 4) * 4);
//再计算图文件全部字节，并返回指针
BYTE *Bits = new BYTE[RowSize * Image1->Height];
//再来逐一用随机数填入每一位图的RGB值
BYTE *BitsPtr;
for (int y=0; y<Image1->Height; y++)
  {
  //每一列起始位图的位置
  BitsPtr = Bits + (RowSize * y);
  for (int x=0; x<Image1->Width; x++)
    {//每一位图为3字节构成，如 0x00B9蓝FF绿DC红
    //故可推移位置
    *BitsPtr++ = (BYTE)((x>255)?255:x);//蓝色
    *BitsPtr++ = (BYTE)random(255); //绿色
    *BitsPtr++ = (BYTE)255; //红色
    }//random(int num)惠 #include <stdlib.h>
  }
//重设Image1大小
Image1->Picture->Bitmap->Width = Image1->Width;
Image1->Picture->Bitmap->Height = Image1->Height;
HBITMAP hbmp = Image1->Picture->Bitmap->Handle;
HDC hdc = Image1->Canvas->Handle;
//设置DIB图像数据
::SetDIBits (hdc, //装置设备的handle
             hbmp, //图像handle
             30, //扫描起始列
             Image1->Height-60, //扫描列数
             Bits, //字节总数
             &bmi, //BITMAPINFO结构
             DIB_RGB_COLORS //色彩类别旗标
             );
//释放位数组
delete[] Bits;
//重绘Image1
Image1->Repaint();
Image1->Stretch = true;
}
//---------------------------------------------------------------------------

