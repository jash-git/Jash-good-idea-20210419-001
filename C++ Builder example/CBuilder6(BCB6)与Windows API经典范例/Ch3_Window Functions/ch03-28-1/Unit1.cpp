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
//ȷ���˴�������ǰ�������ö�ʱ��Ƶ��
FormStyle = fsStayOnTop;
Timer1->Interval = 200;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
char text[256];
//ȡ���������λ��
::GetCursorPos(&P);
//ȡ���������λ�õĴ���handle
HWND HWnd = ::WindowFromPoint(P);
//�ɴ���handleȡ�ñ����ַ���
::GetWindowText(HWnd, text, 256);
//��ʾ��Memo1�ϤW
Memo1->Text = "�������λ�õı����ǣ�" + AnsiString(text);
}
//---------------------------------------------------------------------------
