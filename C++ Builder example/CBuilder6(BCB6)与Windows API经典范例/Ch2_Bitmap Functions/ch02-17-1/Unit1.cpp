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
//图像BITMAPINFO结构声明&设置
BITMAPINFO Bmi;
// 清理BITMAPINFO结构内数据
ZeroMemory(&Bmi.bmiHeader,sizeof(Bmi.bmiHeader));
Bmi.bmiHeader.biSize=sizeof(Bmi.bmiHeader);
Bmi.bmiHeader.biWidth=200;
Bmi.bmiHeader.biHeight=-200; // 图像位图由上而下排列
Bmi.bmiHeader.biPlanes=1;
Bmi.bmiHeader.biBitCount=24; //色彩为24位(R,G,B三色)
Bmi.bmiHeader.biCompression=BI_RGB;
BYTE *Pix;
//以BITMAPINFO结构创造一24位的新图文件
::CreateDIBSection(0,&Bmi,DIB_RGB_COLORS,(void **)&Pix,0,0);
// 更新目前线程的GDI绘制功能
::GdiFlush();

// 直接在位图缓冲区中，绘制指定图样
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

// 先设置好Image1组件位图的长宽
Image1->Picture->Bitmap->Width=200;
Image1->Picture->Bitmap->Height=200;
// 将位图缓冲区的图样，显现在Image1组件上
::SetDIBitsToDevice(Image1->Picture->Bitmap->Canvas->Handle,
                    0,0,
                    200,200,
                    0,0, 0,200,
                    Pix,&Bmi,
                    DIB_RGB_COLORS);

//将完成贴印的Image1组件，扩张至整个form1上，以便观察API执行成果
Image1->Align = alClient;
Image1->Stretch = true;
}
//---------------------------------------------------------------------------
