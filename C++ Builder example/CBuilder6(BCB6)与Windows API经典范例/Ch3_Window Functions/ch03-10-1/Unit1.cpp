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
//������ť���ͳ�WM_CLOSE��Ϣ��ִ��WMCloseQuery������Ϣ����
SNDMSG(Handle,WM_CLOSE,0,0);
}
//---------------------------------------------------------------------------
//���عرճ�����Ϣ
void __fastcall TForm1::WMCloseQuery(TMessage &Msg)
{
char str[] =
 "�������ǡ���ťֻ�ǹرմ��ڣ���δ�رճ���\nע�⣺Ҫ�� Alt+F4 ������ȫ�رճ���";
if(Msg.Msg == WM_CLOSE )
  {//��ѡȡ"��"��ť�����ر�Form1���ڣ�Project2�����ڦb
  if(Application->MessageBox(str,"",MB_YESNO) == IDYES )
     {
     ::DestroyWindow( this->Handle );
     }
  }
}
//---------------------------------------------------------------------------
