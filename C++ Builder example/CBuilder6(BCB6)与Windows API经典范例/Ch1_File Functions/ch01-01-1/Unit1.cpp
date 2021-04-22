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
//Ĭ�ϰ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1���������֦r
Memo1->Text = "";
//�ж����ڳ����Ƿ�ΪANSI�ַ���or OEM�ַ���
//�����жϹ��ܶ� 8 λ������豸��Ϊ����
if(AreFileApisANSI())
   {
   Memo1->Lines->Add("���ڳ����� ANSI �ַ�����");
   Memo1->Lines->Add("Ϊ WIN32 ����ʹ�á�");
   Memo1->Lines->Add("������Button2��ť����ת�� OEM �ַ�����");
   Memo1->Lines->Add("����ֱ���� 8 �ֽ���������豸ʹ�á�");
   Button2->Enabled = true;
   Button3->Enabled = false;
   }
else
   {
   Memo1->Lines->Add("������ OEM �ַ�����");
   Memo1->Lines->Add("����ֱ���� 8 �ֽ�������豸ʹ�á�");
   Memo1->Lines->Add("������Button3��ť����ת�� ANSI �ַ�����");
   Memo1->Lines->Add("Ϊ WIN32 ����ʹ�á�");
   Button2->Enabled = false;
   Button3->Enabled = true;
   }
Memo1->Lines->Add("���϶���Ӱ�����к������صĽ��");
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//�� ANSI ��� OEM
SetFileApisToOEM();
Memo1->Text = "�� ANSI �ַ���ת�� OEM �ַ���";
//���谴ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//��OEM ��� ANSI
SetFileApisToANSI();
Memo1->Text = "�� OEM �ַ���ת�� ANSI �ַ���";
//���谴ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
Button3->Enabled = false;
}
//---------------------------------------------------------------------------

