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
//����Button1��ť��������Timer
Timer1->Enabled = false;
//�������뷨���Ƶ���ʱ�嵥
list = new TStringList();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��ɾ��Memo1������
Memo1->Text = "";
//���뷨��������
s = 0;
pass = 0;
//��Ĭ��ָ�����뷨��ָ�����飬��30��ָ��λ��
HKL hkl[30];

//ȡ�����뷨����
s = ::GetKeyboardLayoutList(255, hkl);

Memo1->Lines->Add("�������뷨�� " + AnsiString(s) + " ��");
//�����뷨��������Timer1��ִ�д���
pass = s;
//����Timer1��ȡ���������뷨
//��ɺ󣬼��ر�Timer1
Timer1->Enabled = true;
}
//---------------------------------------------------------------------------
//����Timer�Ķ�ʱ���ܣ��޴μ�����뷨����
//������switch�оٳ�
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
if(pass > 0)
   {
   //�л�����һ�����뷨<Ctrl + Shift>
   //���� Ctrl ��
   ::keybd_event(VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL,0),0,0);
   //�ٵ��� Shift ��
   ::keybd_event(VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT,0),0,0);
   //�л����뷨�󣬷����ͷŰ���
   ::keybd_event(VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT,0),KEYEVENTF_KEYUP,0);
   ::keybd_event(VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL,0),KEYEVENTF_KEYUP,0);

   //ȡ���������뷨�����ƴ���
   char keyb[KL_NAMELENGTH];
   ::GetKeyboardLayoutName(keyb);
   //�����뷨���Ƽ���RadioGroup1�л������ʱ�嵥��
   RadioGroup1->Items->Add(AnsiString(keyb));
   list->Add(AnsiString(keyb));
   //���뷨������ʾ��Memo1��
   Memo1->Lines->Add(keyb);
   Button1->Enabled = false;
   }
else
   Timer1->Enabled = false;

pass--;
}
//---------------------------------------------------------------------------
//����ȡ��������Ŀ�����л����뷨
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
//ȡ��StringList��ָ���ַ���
AnsiString skey = list->Strings[RadioGroup1->ItemIndex];

//����ָ�����Ƶ����뷨
::LoadKeyboardLayout( skey.c_str(), KLF_ACTIVATE);

//�����㽻��Memo���Ա��������
Memo1->SetFocus();
}
//---------------------------------------------------------------------------
//�ͷ�StringListռס���ڴ�
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete list;
}
//---------------------------------------------------------------------------


