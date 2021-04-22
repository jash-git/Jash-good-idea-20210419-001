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
//��ȡ�ô��ڷ������
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
//ȥ�����ڵı���������
dwStyle &= ~WS_CAPTION;
//�ٽ��ޱ������ķ��������ش���
::SetWindowLong(Handle, GWL_STYLE, dwStyle);

RECT r;
//ȡ��ָ�����ڷ�Χ��λ��
::GetClientRect(Handle, &r);
//����������Բ��λ���뷶Χ
HRGN hRgn1 = ::CreateEllipticRgn(2, 2, r.right/6*2, r.bottom/6*2);
HRGN hRgn2 = ::CreateEllipticRgn(r.right/6*4, 2, r.right, r.bottom/6*2);
//�ٽ�ϴ�������Բ��λ���뷶Χ
::CombineRgn(hRgn1,hRgn1,hRgn2,RGN_OR);
//����һ����Բ��λ���뷶Χ
HRGN hRgn3 = ::CreateEllipticRgn(r.right/6, r.bottom/6, r.right/6*5, r.bottom);
//�ٽ�ϴ�������Բ��λ���뷶Χ
::CombineRgn(hRgn1,hRgn1,hRgn3,RGN_OR);
//���ָ�����ڵ���ʾ��Χ
::SetWindowRgn(Handle, hRgn1, TRUE);
::SetProp(Handle, "region", hRgn1);
//��������Ϊ��ɫ
Color = (TColor)RGB(255,200,140);
//�����رմ��ڵİ�ťλ�þ���
Button1->Left = (Width-Button1->Width)/2;
Button1->Top = (Height-Button1->Height)/2;
}
//---------------------------------------------------------------------------
//��ס��ɫ���򣬼����ƶ�Form1
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//�ͷ����Ĳ�׽�����ͳ���ס�����ƶ�����ͬ��ס�������ƶ����ڵ���Ϣ
::ReleaseCapture();
SNDMSG(Handle, WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
}
//---------------------------------------------------------------------------
//ȡ���رմ��ڵĹ��ܯ�
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------

