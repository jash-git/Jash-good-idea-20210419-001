//---------------------------------------------------------------------------
//Ŀ�ģ��ɶ�ʱ����ʱ��������Ļλ�ã���ȡ���������򴰿ڱ����ַ���
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
{//�����������������ϲ�����������½�
FormStyle = fsStayOnTop;
Top = Screen->Height-Height;
Left = Screen->Width-Width;
Timer1->Interval = 100; //0.1�붨ʱ��Ƶ��
}
//---------------------------------------------------------------------------
//�ɶ�ʱ����ʱ��������Ļλ�ã���ȡ�ô��ڴ���
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
::GetCursorPos(&P);//��׽�����Ļλ��
//ȡ�����λ���´���handle
HWND HWnd = ::WindowFromPoint(P);
//��˴����ͳ�"ȡ�ñ����ַ���"��Ϣ
char buffer[100];
SendMessage(HWnd, WM_GETTEXT, (WPARAM)100, (LPARAM)buffer);
//������Form1���ڵ��ַ���������
StaticText2->Caption = buffer;
}
//---------------------------------------------------------------------------
