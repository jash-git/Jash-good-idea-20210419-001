//---------------------------------------------------------------------------
//Ŀ�ģ�ȡ�����뷨�������г����뷨���ƭ�
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
Memo1->Text = ""; //��ɾ��Memo1�����֦r
HKL hkl[10];
//���HKL��ַ�ڴ�
::ZeroMemory(hkl,sizeof(HKL));
//ȡ�����뷨����������뷨handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("�������뷨��" + AnsiString(num) + " ��");
//ѭ��ȡ�������뷨handle
while(num)
  {//ʹ��һ˳������뷨��Ч��
  ::ActivateKeyboardLayout((HKL)HKL_NEXT,KLF_REORDER);
  char keyb[KL_NAMELENGTH];
  //ȡ������ִ�������뷨����
  ::GetKeyboardLayoutName(keyb);
  //�����뷨handle����Memo1��
  Memo1->Lines->Add("��"+AnsiString(num) +
                    "�����뷨Handle��ֵΪ"+AnsiString(keyb));
  num--;
  }
}
//---------------------------------------------------------------------------



