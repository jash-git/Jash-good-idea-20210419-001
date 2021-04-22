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
//��Image1���ݣ���ͼ�ļ�Ϊ��Դͼ�ļ�
bakImg = new TImage(Form1);
bakImg->Parent = Form1;
bakImg->Picture = Image1->Picture;
bakImg->Hide();
//��ʾScrollBar1�ƶ�λ��
Form1->Caption = "ScrollBar1λ���� 255";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete bakImg;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
//��ScrollBar1�ƶ�ʱ��������Image1���Ա�
Image1->Picture = bakImg->Picture;
//��ʾScrollBar1�ƶ�λ��
Form1->Caption = "ScrollBar1λ����"+ AnsiString(ScrollBar1->Position);
//ɫ���������� �ŧi
RGBQUAD OldPalette[256];
RGBQUAD NewPalette[256];
//��ȡ��Image1ɫ��
::GetDIBColorTable(Image1->Canvas->Handle, 0, 256, OldPalette);
//��������Image1ɫ��
for (int i = 0 ; i < 256 ; i++)
    {
     NewPalette[i].rgbBlue = (unsigned short) (ScrollBar1->Position *
                                       OldPalette[i].rgbBlue / 255);
     NewPalette[i].rgbGreen = (unsigned short) (ScrollBar1->Position *
                                      OldPalette[i].rgbGreen / 255);
     NewPalette[i].rgbRed = (unsigned short) (ScrollBar1->Position *
                                        OldPalette[i].rgbRed / 255);
    }
//����ɫ��ָ�ɸ�Image1
::SetDIBColorTable(Image1->Canvas->Handle, 0, 256, NewPalette);
//����Image1
Image1->Invalidate();
ScrollBar1->SetFocus();
}
//---------------------------------------------------------------------------

