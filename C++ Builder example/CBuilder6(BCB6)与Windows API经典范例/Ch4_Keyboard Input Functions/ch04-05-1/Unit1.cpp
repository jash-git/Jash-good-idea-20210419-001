//---------------------------------------------------------------------------
//Ŀ�ģ�ȡ�������߳����뷨��α����ɨ�����໥ת��
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
{//��Form1��Tag��Ϊ��������
Tag = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��ɾ��Memo1����������
Memo1->Text = "";
while(Tag<400)
   {//MapVirtualKeyEx�ڶ����������α����ɨ�����໥ת���Ļ���
   //GetKeyboardLayout(0)ȡ�������߳����뷨��handle
   int g = ::MapVirtualKeyEx(Tag++, 0, ::GetKeyboardLayout(0));
   if(g)//��ת���ɹ������г�
      Memo1->Lines->Add("α��_" + AnsiString(Tag) +
                        " <-> ɨ����_"+AnsiString(g));
   }
Tag = 0;//��Form1��Tag����
}
//---------------------------------------------------------------------------



