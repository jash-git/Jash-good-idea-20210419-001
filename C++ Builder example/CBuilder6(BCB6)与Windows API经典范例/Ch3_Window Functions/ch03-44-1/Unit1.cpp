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
Tag = 1;//������������Ϊѭ������
Timer1->Interval = 500; //�����ӷ�Ӧһ��
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
AnsiString hint;
//��Ԫ����--�л������ַ���
(Tag%2)?(hint=Edit1->Text,Tag=2):(hint=Edit2->Text,Tag=1);
//��Ѱ��ͨ����ʾ����handle
HWND hWnd = ::FindWindow("THintWindow",NULL);
if(hWnd)
  {//����ڴ�����ͣ��ʱ��������ֵ���ʾ�ַ���
  ::SetWindowText(hWnd, hint.c_str());
  SendMessage(hWnd,WM_SETTEXT,0,256);//�ͳ������ַ�����Ϣ
  //�ͳ������ַ�����Ϣ��CM_TEXTCHANGED������Controls.hpp��
  SendMessage(hWnd,CM_TEXTCHANGED,0,0);
  }
}
//---------------------------------------------------------------------------
