//---------------------------------------------------------------------------
//Ŀ�ģ��л����ػ����ֲ�ͬ�߳�ָ��������ʾ״̬��NT�����񻷾���Ϊ����
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
{//�����������ԣ���Ϊ����ֵ
Button1->Default = false;
}
//---------------------------------------------------------------------------
//������ر�ʱ��ȷ�ϻָ���ݹ������������ݷ�ʽͼʾԭò
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//������ť���л����ػ���ʾ�ڿ�ݹ������ϵ�Project1ĸ����
if(Button1->Default)
   ::ShowWindowAsync(Application->Handle, SW_RESTORE);
else
   ::ShowWindowAsync(Application->Handle, SW_HIDE);
//�л�����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
