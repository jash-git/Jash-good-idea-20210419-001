//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ĭ�϶�ʱ��ֹͣ
Button1->Caption = "ֹͣ";
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------
//�ɰ�ť�����л���ʱ������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
Timer1->Enabled = !Timer1->Enabled;
if(Button1->Caption=="ֹͣ")Button1->Caption ="��ʼ";
else Button1->Caption="ֹͣ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//����ʱ��ִ��ʱ���κγ�������ǰ��ִ�У������Ŵ���ȫ��Ļ
::ShowWindow(::GetForegroundWindow(), SW_MAXIMIZE );
//����ʱ��ִ��ʱ���κγ�������ǰ��ִ�У����ⶼ�ĳ��±���
HWND focusWindow = ::GetForegroundWindow();
if(!::IsWindow(focusWindow)) return;
::SetWindowText( focusWindow,
               " ���Ǹı����Ķ�����"
               );
}
//---------------------------------------------------------------------------

