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
//������������Ϊ��ӡ�Ի����������handle ID ��ȡ��
Form1->Tag = 0;
//�ж��򿪴�ӡ�Ի������
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��ListBox1��ѡ�δ��ѡ����Ĭ��ֵ
Form1->Tag = 0;
//�ڶ��ε�����ťʱ����ʼ����
//ȡ��ListBox1��ѡ������ֲ���
if(!Button1->Default)
 for(int i=0; i<ListBox1->Items->Count; i++)
   if(ListBox1->Selected[i])
     {
     int y=0;
     AnsiString str = ListBox1->Items->Strings[i];
     AnsiString pstr = ",";
     y = str.Pos(pstr);
     str = str.SubString(1,y-1);
     Form1->Tag = str.ToInt();
     }
//�򿪴�ӡ�Ի���
if(PrinterSetupDialog1->Execute())
  Caption = "����ListBoxѡȡ��ֵ��ʹָ����ʧЧ!";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrinterSetupDialog1Show(TObject *Sender)
{
HWND handle = PrinterSetupDialog1->Handle;
//��һ�ν���Ѱ��ӡ�Ի����ϵĶ���ID
if(Button1->Default)
  {//�Զ��庯�������ݼ������
  GetFontBoxItemsID_Text(handle);
  }
else//�ڶ��κ󼴿���user����ָ��ʧЧ���ܥ\��
  {
  //��ֹ��ӡ�Ի����<ȡ��>��ʧЧ�����඼ִ��
  if(Form1->Tag != 2)
    ::EnableWindow(::GetDlgItem(handle, Form1->Tag), false);
  }
Button1->Default = false;
}
//---------------------------------------------------------------------------
//ȡ�ô�ӡ�Ի��������������handle ID ����ʾ����
void TForm1::GetFontBoxItemsID_Text(HWND handle)
{
//������Ѱ��Χ
for(int a=-3000;a<3000;a++)
  if(::GetDlgItem(handle,a))//����ȡ��handle���ڣ���ͨ��
    {
    char str[256];
    //ȡ�ô�handle�����֣������б�ѡ��ID������ListBox1�г��X
    ::GetDlgItemText(handle,a,str,256);
    ListBox1->Items->Add(AnsiString(a)+","+AnsiString(str));
    }
}
//---------------------------------------------------------------------------


