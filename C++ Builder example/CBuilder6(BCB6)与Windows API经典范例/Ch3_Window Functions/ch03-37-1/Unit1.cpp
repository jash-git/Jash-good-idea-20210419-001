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
{//�ȹرն�ʱ�����ð�ť���ƿ���
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�л���ʱ������
Timer1->Enabled = !Timer1->Enabled;
(Timer1->Enabled)?(Caption = "���ڻ��������ƶ���")
                    :(Caption = "ֹͣ���ڻ����ƶ�");

}
//---------------------------------------------------------------------------
//Form1������λ�ò��䣬����ȴ�����ƶ�
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
::MoveWindow(Handle, Left, Top++, Width, Height, false);
}
//---------------------------------------------------------------------------

