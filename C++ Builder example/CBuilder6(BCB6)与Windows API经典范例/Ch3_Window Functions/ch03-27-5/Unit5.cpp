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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//Form1������ɵ���ɫ
Color = (TColor)RGB(230,140,255);
//�Զ��庯��--�ƶ���굽�ض�λ��
CursorPos(Handle);
}
//---------------------------------------------------------------------------
void TForm1::CursorPos(HWND hwnd)
{
RECT r;
//ȡ�ð�ť��Χ����
::GetWindowRect(::GetWindow(hwnd,GW_CHILD), &r);
//�ƶ���굽�ض�λ��
::SetCursorPos(r.left+4,(r.bottom+r.top)/2);
}
//---------------------------------------------------------------------------
