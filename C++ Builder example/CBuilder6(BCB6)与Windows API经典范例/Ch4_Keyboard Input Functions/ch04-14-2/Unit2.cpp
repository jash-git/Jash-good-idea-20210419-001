//---------------------------------------------------------------------------
//Ŀ�ģ������ѡѡ������Ŀ����ִ��ѡ������
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//VK_MENU����Alt������ʹ����ѡ��������
::keybd_event(VK_MENU, (BYTE)::MapVirtualKey(VK_MENU,0),0,0);
//��Alt����F�����ɴ���<�ļ�>ѡ��
::keybd_event('F', (BYTE)::MapVirtualKey('F',0),0,0);
//�ٽ�F���ĳ�V�����ɴ���<�ı���ɫ>ѡ��
::keybd_event('V', (BYTE)::MapVirtualKey('V',0),0,0);
//�ﵽӦ�й��ܺ󣬷����ͷŰ���
::keybd_event('V', (BYTE)::MapVirtualKey('V',0),KEYEVENTF_KEYUP,0);
::keybd_event('F', (BYTE)::MapVirtualKey('F',0),KEYEVENTF_KEYUP,0);
::keybd_event(VK_MENU, (BYTE)::MapVirtualKey(VK_MENU,0),KEYEVENTF_KEYUP,0);
}
//---------------------------------------------------------------------------
//Alt + F��������<������Ϊ����ɫ>ѡ������
void __fastcall TForm1::File1Click(TObject *Sender)
{
Color = (TColor)RGB(190,255,125);
Caption = "��ϸ��������һ���ӱ���Ϊ����ɫ�����";
}
//---------------------------------------------------------------------------
//Alt + V��������<������Ϊ����ɫ>ѡ��ܯ�
void __fastcall TForm1::FileSub104Click(TObject *Sender)
{
Color = (TColor)RGB(128,128,255);
}
//---------------------------------------------------------------------------



