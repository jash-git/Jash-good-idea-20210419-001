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
//��handle�Ǵ�����̬����ִ�е�Ȧ
while(::IsWindow(hWnd))
  {
  //ȡ����һ˳λ�Ĵ���handle
  hWnd = ::GetNextWindow(hWnd,GW_HWNDNEXT);
  //����ȡ�ñ����ַ�������ͨ��
  if(::GetWindowTextLength(hWnd))
    {
    char str[256];
    //ȡ�ô��ڱ����ַ���
    ::GetWindowText(hWnd, str,
                    ::GetWindowTextLength(hWnd)+1);
    //�жϴ˴��ڵ��ַ�����
    if(::IsWindowUnicode(hWnd))
       Memo1->Lines->Add(AnsiString(str) + "_��Unicode�ַ�����");
    else
       Memo1->Lines->Add(AnsiString(str) + "_��ANSI-ASCII�ַ�����");
    }
  }
}
//---------------------------------------------------------------------------
