//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
//���Memo1����������
Memo1->Clear();
RECT r;
//ȡ��Form1���ط�Χ
::GetClientRect(Handle, &r);
//ȡ������������Form1���ط�Χ
::MapWindowPoints(Handle, HWND_DESKTOP, reinterpret_cast<LPPOINT>(&r), 2);
//ȡ��Form1���ط�Χ(���������)
RECT rWin;
::GetWindowRect(Handle, &rWin);
//���λ���������������������֮�����
int dx = r.left - rWin.left;
int dy = r.top - rWin.top;
Memo1->Lines->Add("Form1��Client����ʼ��㣺");
Memo1->Lines->Add("Xλ��Ϊ��  "+AnsiString(dx) +"��λͼ");
Memo1->Lines->Add("Yλ��Ϊ�� "+AnsiString(dy) +" ��λͼ");
}
//---------------------------------------------------------------------------
