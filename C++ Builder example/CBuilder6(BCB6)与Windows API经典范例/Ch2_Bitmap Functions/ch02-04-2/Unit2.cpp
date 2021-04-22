//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//����Unit2_2.h ��ͷ��-------------------------------------------------------
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
//����Newform������Newform��������
//����Newform���������ж���
Newform->ShowModal();
//��ʱ����ʵ���ѱ��Newform������ͼ
RECT mRect;
//��Form1��Χ������NewForm�У���ΪNewForm���ݲο�
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
