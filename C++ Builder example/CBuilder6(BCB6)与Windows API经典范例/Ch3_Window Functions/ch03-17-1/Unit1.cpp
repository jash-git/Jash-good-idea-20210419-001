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
//�򿪡��򿪡��Ի���
void __fastcall TForm1::Button1Click(TObject *Sender)
{
OpenDialog1->Execute();
}
//---------------------------------------------------------------------------
//�ڡ��򿪡��Ի�������ʱ���ı��ض�����
void __fastcall TForm1::OpenDialog1Show(TObject *Sender)
{
//ȡ�á��򿪡��Ի����handle
HWND hwndD = ::FindWindowEx(NULL,NULL,NULL,"��");
//���衾�򿪡��Ի���ı������֦r
::SetWindowText(hwndD,"����--�ı����--");
//�ڡ��򿪡��Ի����У�Ѱ���ض��������ֵĶ���handle
HWND hw1 = ::FindWindowEx(hwndD,NULL,NULL,"����λ��(&I):");
//����˶����������
::SetWindowText(hw1,"����_����1");
HWND hw2 = ::FindWindowEx(hwndD,NULL,NULL,"��(&O)");
::SetWindowText(hw2,"��_����2");
HWND hw3 = ::FindWindowEx(hwndD,NULL,NULL,"ȡ��");
::SetWindowText(hw3,"OK_����3");
HWND hw4 = ::FindWindowEx(hwndD,NULL,NULL,"�ļ�����(&N):");
::SetWindowText(hw4,"�ļ�����_����4");
HWND hw5 = ::FindWindowEx(hwndD,NULL,NULL,"�ļ�����(&T):");
::SetWindowText(hw5,"����_����5");
}
//---------------------------------------------------------------------------
