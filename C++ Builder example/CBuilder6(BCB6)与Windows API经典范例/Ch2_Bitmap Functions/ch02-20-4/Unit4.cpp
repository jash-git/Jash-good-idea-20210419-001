//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//������Image1
Image1->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormResize(TObject *Sender)
{
//��Form1����Χ��ΪʧЧ��Χ��
//������WM_ERASEBKGND��Ϣ���������ػ�
::InvalidateRect(Handle, NULL, true);
}
//---------------------------------------------------------------------------
//WM_ERASEBKGND��Ϣ
void __fastcall TForm1::WMEraseBkgnd(TMessage &Msg)
{
//��ͼ������Form1�������λ���
::StretchBlt(Canvas->Handle,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Image1->Canvas->Handle, 0, 0,
             Image1->Width,
             Image1->Height, SRCCOPY);
Msg.Result = 0;
}
