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
{//��Form1��handleָ�ɸ��״�ѭ��
hWnd = Handle;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//���Memo1�ַ���
Memo1->Text = "";
for(int i=1;i<16;i++)
  {
  //ȡ����һ˳λ�Ĵ���handle
  hWnd = ::GetNextWindow(hWnd,GW_HWNDNEXT);
  char str[256];
  //ȡ�ô��ڱ����ַ���
  ::GetWindowText(hWnd, str,
                  ::GetWindowTextLength(hWnd)+1);
  Memo1->Lines->Add("ȡ�õ�" + AnsiString(i) +
                    "˳λ�Ĵ��ڱ����ַ�����" + AnsiString(str));
  }
}
//---------------------------------------------------------------------------
