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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����Ѱ��Form1����������handle
HWND hWnd = ::FindWindow("TForm1",0);
//��Form1������С������СForm1����Ļ���½�
::CloseWindow(hWnd);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//�����㽻����һ˳λ����Form1������ݹ�������
::CloseWindow(::GetWindow( Handle,GW_HWNDNEXT));
}
//---------------------------------------------------------------------------
