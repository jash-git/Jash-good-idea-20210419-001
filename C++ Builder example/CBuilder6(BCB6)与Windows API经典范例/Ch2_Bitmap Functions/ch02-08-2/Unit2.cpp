//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//将Image1备份，新图文件为来源图文件
bakImg = new TImage(Form1);
bakImg->Parent = Form1;
bakImg->Picture = Image1->Picture;
bakImg->Hide();
//显示ScrollBar1移动位置
Form1->Caption = "ScrollBar1位置在 255";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete bakImg;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
//当ScrollBar1移动时，即更新Image1，以便
Image1->Picture = bakImg->Picture;
//显示ScrollBar1移动位置
Form1->Caption = "ScrollBar1位置在"+ AnsiString(ScrollBar1->Position);
//色盘数组声明 
RGBQUAD OldPalette[256];
RGBQUAD NewPalette[256];
//先取得Image1色盘
::GetDIBColorTable(Image1->Canvas->Handle, 0, 256, OldPalette);
//再重设新Image1色盘
for (int i = 0 ; i < 256 ; i++)
    {
     NewPalette[i].rgbBlue = (unsigned short) (ScrollBar1->Position *
                                       OldPalette[i].rgbBlue / 255);
     NewPalette[i].rgbGreen = (unsigned short) (ScrollBar1->Position *
                                      OldPalette[i].rgbGreen / 255);
     NewPalette[i].rgbRed = (unsigned short) (ScrollBar1->Position *
                                        OldPalette[i].rgbRed / 255);
    }
//将新色盘指派给Image1
::SetDIBColorTable(Image1->Canvas->Handle, 0, 256, NewPalette);
//更新Image1
Image1->Invalidate();
ScrollBar1->SetFocus();
}
//---------------------------------------------------------------------------

