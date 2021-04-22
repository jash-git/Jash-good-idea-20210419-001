//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//含入Unit2_2.h 标头档-------------------------------------------------------
#include "Unit2_2.h"
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
//显现Newform，启动Newform建构函数
//进行Newform建构函数中动作
Newform->ShowModal();
//此时桌面实际已变成Newform背景底图
RECT mRect;
//将Form1范围复制至NewForm中，作为NewForm依据参考
Newform->GetRect(&mRect);
Sleep(100);
GetMouseClickArea(&mRect);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::GetMouseClickArea(LPRECT rect)
{
Graphics::TBitmap *Bitmap = Image1->Picture->Bitmap;

HDC HScreenDC = ::GetDC(0);
Bitmap->Handle =
     ::CreateCompatibleBitmap(HScreenDC,
                              rect->right - rect->left,
                              rect->bottom - rect->top);

int result = ::GetDeviceCaps(HScreenDC, RASTERCAPS);
if (result & RC_PALETTE)
    {
    int palette_size = ::GetDeviceCaps(HScreenDC, SIZEPALETTE);
    if (palette_size == 256)
        {
        int size = sizeof(LOGPALETTE) + 256 * sizeof(PALETTEENTRY);
        LPLOGPALETTE lplogpal =
                (LPLOGPALETTE) new unsigned char[size];
        lplogpal->palVersion = 0x300;
        lplogpal->palNumEntries = 256;
        ::GetSystemPaletteEntries(HScreenDC, 0, 256,
                                  lplogpal->palPalEntry);
        Bitmap->Palette = ::CreatePalette(lplogpal);
        delete [] lplogpal;
        }
    }

::BitBlt(Bitmap->Canvas->Handle, 0, 0,
         Bitmap->Width, Bitmap->Height,
         HScreenDC, rect->left, rect->top,
         SRCCOPY);

::ReleaseDC(0, HScreenDC);
}
//---------------------------------------------------------------------------
