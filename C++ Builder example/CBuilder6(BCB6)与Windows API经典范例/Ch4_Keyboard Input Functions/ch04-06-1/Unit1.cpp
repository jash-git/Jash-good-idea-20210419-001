//---------------------------------------------------------------------------
//Ŀ�ģ�ȡ�����뷨�������г����뷨����
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
//��HKL��ַ�ڴ�������ͬ��ֵ
::FillMemory(hkl,sizeof(hkl),0);
//ȡ�����뷨����������뷨handle
int num = ::GetKeyboardLayoutList(255, hkl);
Memo1->Lines->Add("�������뷨�� " + AnsiString(num) + " ��");
//�Y�n��ܿ�J�k�W�١A�h�����b�{���X���ΦC�|(switch)�覡�B�z
//ѭ��ȡ�������뷨handle
while(num>-1)
  {
  long k = (long)hkl[num--];
  if((int)k != 0) //�����뷨handle����Memo1��
    Memo1->Lines->Add("��"+AnsiString(num+2) +
                      "�����뷨Handle��ֵΪ"+IntToHex((int)k,8));
  }
}
//---------------------------------------------------------------------------


