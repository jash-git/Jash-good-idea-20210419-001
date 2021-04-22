//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��Bitmap����Image1��
//����׫дʱ�������Ķ�����
Bitmap = Image1->Picture->Bitmap;
//����Image1
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
//��������Ϣ������ȥ
TForm::Dispatch(&Msg);
//ȡ��ϵͳ�б���߶�
int CaptionHeight = ::GetSystemMetrics(SM_CYCAPTION);
//ȡ��Form1��DC handle
HDC HWindowDC = ::GetWindowDC(Handle);
//��ͼ������Form1���ⳤ������+��ɫ������Form1�����ϤW
::StretchBlt(HWindowDC,
             4, 2,
             Width-62, CaptionHeight+2,
             Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width, Bitmap->Height,
             NOTSRCCOPY);
//��ͼ������Form1��Χ�������λ�����Form1������
::StretchBlt(Canvas->Handle,
             0, 0,
             ClientWidth,
             ClientHeight-StaticText1->Height,
             Bitmap->Canvas->Handle,
             0, 0,
             Bitmap->Width,
             Bitmap->Height,
             SRCCOPY);
//ûʹ����Ϣ��Resultֵ
Msg.Result = 0;
//�ͷ�ϵͳDC��handle
::ReleaseDC(Handle, HWindowDC);
}
//---------------------------------------------------------------------------

