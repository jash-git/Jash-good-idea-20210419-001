//---------------------------------------------------------------------------
//Ŀ�ģ��������������ϼ��������������д򿪳����л���С����ԭ
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
{//���ÿ�ݹ�������windowϵͳѡ��
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//���ÿ�ݹ�������windowϵͳѡ��
//�ڿ�ݹ������հ״����Ҽ��㰴�����ֵ�ϵͳѡ��
::keybd_event( VK_LWIN, (BYTE)::MapVirtualKey( VK_LWIN, 0), 0, 0 );

if(Button1->Default)//���� Shift ��
  ::keybd_event( VK_SHIFT, (BYTE)::MapVirtualKey( VK_SHIFT, 0), 0, 0 );
//���� M ��
::keybd_event( 'M', (BYTE)::MapVirtualKey( 'M', 0), 0, 0 );
::keybd_event( 'M', (BYTE)::MapVirtualKey( 'M', 0), KEYEVENTF_KEYUP, 0 );

if(Button1->Default)//������� Shift ��
   ::keybd_event( VK_SHIFT, (BYTE)::MapVirtualKey( VK_SHIFT, 0), KEYEVENTF_KEYUP, 0 );
//������ÿ�ݹ�������windowϵͳѡ��
::keybd_event( VK_LWIN, (BYTE)::MapVirtualKey( VK_LWIN, 0), KEYEVENTF_KEYUP, 0 );
//ʹ��ť�ظ�����ʱ���л�����
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
