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
{//������������Ϊ��������
Button1->Tag = 0;
}
//---------------------------------------------------------------------------
//������ť�����ѭ��ת�����������(ToolBar1)ĸ����
void __fastcall TForm1::Button1Click(TObject *Sender)
{//�жϵ���������ѭ��ת��
switch(Button1->Tag%3)
  {
  case 0: ::SetParent(ToolBar1->Handle,Panel1->Handle);break;
  case 1: ::SetParent(ToolBar1->Handle,Panel2->Handle);break;
  case 2: ::SetParent(ToolBar1->Handle,::GetDesktopWindow());break;
  }
//���蹤�������λ����ߴ�
::SetWindowPos(ToolBar1->Handle,HWND_TOPMOST,
               30, 30,
               ToolBar1->Width/2, ToolBar1->Height/2,
               SWP_SHOWWINDOW
               );
Button1->SetFocus();//���ɰ�ťȡ�ý���
++Button1->Tag;//�����������Ա��´ε㰴��ť
}
//---------------------------------------------------------------------------
//��userͬʱ��סCtrl����������������ҷPanel1��������ҷPanel1
void __fastcall TForm1::ToolBar1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Button == mbLeft && Shift.Contains(ssCtrl))
  {//�ͷ�ԭ����겶׽״̬��
  //��ͬʱ�ͳ���굥��λ�õ�ͬ�ڴ��ڱ����п���ҷ���ڵ�����
  ::ReleaseCapture();
  SNDMSG(ToolBar1->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
  }
//����������ҷToolBar1ʱ��Button1�޷���λ��ʧȥ�������������U��O�A
//��������Ҽ�����ToolBar1����
if(Button == mbRight)
  {
  Button1->Click();
  }
}
//---------------------------------------------------------------------------
