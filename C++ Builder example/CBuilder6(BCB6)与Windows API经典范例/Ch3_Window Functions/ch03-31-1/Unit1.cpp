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
//���Memo1����
Memo1->Text = "";
//����������Ĭ��
int b=0, c=0;
AnsiString str = "";
char ch[256];
//��һ����Form1�µ��Ӷ�����������������
for(int i=0;i<ComponentCount;i++)
  {//�Ƚ����ָ��ת��Ϊͨ�ô�������
  TWinControl* cp = (TWinControl *)Components[i];
  //���˶����Ǿ��д������Ե��Ӷ���
  if(::IsChild(Handle,(HWND)cp->Handle))
    {//ȡ�ô��Ӵ�����������
    ::GetClassName((HWND)cp->Handle, ch, 256);
    str = str + AnsiString(ch) + ",";
    b++;
    }
  else
    c++;
  }
Memo1->Lines->Add("Form1���ڹ�  " + AnsiString(b) +
                  "���Ӵ��ڶ���," + AnsiString(c) + "���޴��ڶ���");
Memo1->Lines->Add("ӵ�д��ڵĶ�������Ϊ--" + str);
}
//---------------------------------------------------------------------------
