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
//Ĭ��CheckBox1��αֵ
CheckBox1->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1������
Memo1->Clear();
//��ȡ���ֳ�������һ����handle
char name[100];
HWND hWnd = ::GetTopWindow(NULL);
HWND hwndNext = ::GetNextWindow(hWnd, GW_HWNDNEXT);
//�г�������ִ���еĴ���
if(CheckBox1->Checked)//CheckBox1ѡȡ״̬
  {
  while(hwndNext)
   {//������ִ�������������ȡ�ô��ڱ����ַ���
   if((::IsWindowVisible(hwndNext)) &&
      (!::GetWindow(hwndNext, GW_OWNER)))
      {
      ::GetWindowText(hwndNext, (LPTSTR)name, sizeof(name));
      if(name[0] != '\0')//���б����ַ����������Memo1��
        Memo1->Lines->Add(name);
      }
   //���ҵ���һ����
   hwndNext = ::GetNextWindow(hwndNext, GW_HWNDNEXT);
   }
  }
else //�г������г��봰��
  {
  while(hwndNext)
   {//�����ھ߶����г̣���ȡ�ô��ڱ����ַ���
   if(!::GetWindow(hwndNext, GW_OWNER))
     {
     GetWindowText(hwndNext, (LPTSTR)name, sizeof(name));
     if(name[0] != '\0')
       Memo1->Lines->Add(name);
     }
   //�A���ҵ���һ����
   hwndNext = ::GetNextWindow(hwndNext, GW_HWNDNEXT);
   }
  }
}
//---------------------------------------------------------------------------
