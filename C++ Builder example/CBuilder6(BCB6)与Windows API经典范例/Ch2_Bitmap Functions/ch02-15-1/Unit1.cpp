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
//ScrollBar1北
ScrollBar1->Max = 255;
//将Image1复制成一新图像，
//此图像设为来源图像
Sourmap = new Graphics::TBitmap();
Sourmap->Width = Image1->Picture->Bitmap->Width;
Sourmap->Height = Image1->Picture->Bitmap->Height;
Sourmap->Assign(Image1->Picture->Bitmap);
Sourmap->PixelFormat = pf24bit;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete Sourmap;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//创造一8位(256色)DIB暂时图像
Graphics::TBitmap* Tmpmap = new Graphics::TBitmap();
Tmpmap->Width = Sourmap->Width;
Tmpmap->Height = Sourmap->Height;
Tmpmap->HandleType = bmDIB;
Tmpmap->PixelFormat = pf8bit;
//设置此暂时图像的256色色盘
RGBQUAD rgbQ[256];
for (int index = 0; index < 256; index++)
   {
   rgbQ[index].rgbRed = static_cast<unsigned char>(index);
   rgbQ[index].rgbBlue = static_cast<unsigned char>(index);
   rgbQ[index].rgbGreen = static_cast<unsigned char>(255-index);
   rgbQ[index].rgbReserved = 0;
   }
//将256色盘指派给此暂时图像
::SetDIBColorTable(Tmpmap->Canvas->Handle,
                   ScrollBar1->Position,
                   256, rgbQ);

//先由来源图像复制图像至256色暂时图像中
//即依照色盘顺序对换色彩
::BitBlt(Tmpmap->Canvas->Handle, 0, 0,
         Sourmap->Width,
         Sourmap->Height,
         Sourmap->Canvas->Handle,
         0, 0,
         SRCCOPY);
//将完成256色转换的暂时图像指派给Image1
Image1->Picture->Bitmap->Assign(Tmpmap);
//更新Image1图像
Image1->Refresh();
delete Tmpmap;
}
//---------------------------------------------------------------------------
//在Form1标题显示256色盘的起始颜色
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
Caption = "256色盘数组中,起始颜色在第" +
          AnsiString(ScrollBar1->Position) +
          " 数组位置";
}
//---------------------------------------------------------------------------

