//---------------------------------------------------------------------------
//Ŀ�ģ����ü�����ϼ��������������ָ��λ�ã������浥��������ִ�й��ܯ�
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�� VK_W ����� W ��ֵ------------------------------------------------------
#define VK_W 0x57
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//ɾ��Memo1������
Memo1->Text = "";
//��Memo1���½�150������
char a[26];
for(int x=65;x<91;x++)
    a[x-65] = char(x);
for(int i=1; i<151; i++)
    Memo1->Lines->Add("�� "+AnsiString(i)+" ��_ "+AnsiString(a));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
//����ϼ������Ctrl+W ���ǵ���״̬
//��ɽ�����ع��ܸı�
if(::GetKeyState(VK_CONTROL) && ::GetKeyState(VK_W))
  {
  //���������Memo1�����½�ScrollBarλ��
  POINT p = { Memo1->Left+Memo1->Width-10, Memo1->Top+Memo1->Height-10};
  p = ClientToScreen(p);
  ::SetCursorPos(p.x,p.y);
  //���浥��������һ��
  ::mouse_event( MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0 );
  ::mouse_event( MOUSEEVENTF_LEFTUP, 0, 0, 0, 0 );
  }
}
//---------------------------------------------------------------------------
