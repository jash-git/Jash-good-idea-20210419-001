//---------------------------------------------------------------------------
//Ŀ�ģ����뷨����<�������뷨>��ѡȡ������Memo1��ִ�����빦�ܥ\��
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
Memo1->Text = ""; //��ɾ��Memo1������
HKL hkl[10];
//���HKL��ַ�ڴ�
::ZeroMemory(hkl,sizeof(HKL));
//ȡ�����뷨����������뷨handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("�������뷨��" + AnsiString(num) + " ��");
//�j����X�U��J�khandle
while(num)
  {//��win95����ʹ���߳�ִ�д����뷨��
  //��NT����ʹ��ȫϵͳ�����ѵ����߳̽�ִ�д����뷨
  //ȡ����һ���뷨������
  ::ActivateKeyboardLayout((HKL)HKL_NEXT,KLF_REORDER);
  char keyb[KL_NAMELENGTH];
  //ȡ���������뷨����
  ::GetKeyboardLayoutName(keyb);
  //�����뷨handle����RadioGroup1�л�������
  RadioGroup1->Items->Add(AnsiString(keyb));
  Memo1->Lines->Add(AnsiString(keyb));
  num--;
  }
//Ԥ��ѡȡRadioGroup1��һ����
RadioGroup1->ItemIndex = 0;
//��ť������ɣ���ʧЧ
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//����ȡ<�������뷨>��������Ŀ�����л����뷨
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{//ȡ��RadioGroup1��ָ���ַ���
AnsiString skey = RadioGroup1->Items->Strings[RadioGroup1->ItemIndex];
//����ָ�����Ƶ����뷨
::LoadKeyboardLayout( skey.c_str(), KLF_ACTIVATE);
//�����㽻��Memo���Ա��������
Memo1->SetFocus();
}
//---------------------------------------------------------------------------



