//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//������������Ϊ����ֵ����
Button1->Default = true;
}
//---------------------------------------------------------------------------
//��Win32 Help�У�����Edit Control Styles�ַ���������ȡ���������ַ���������ͱ�־
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ��Edit1��ԭ����������
DWORD dwStyle = ::GetWindowLong(Edit1->Handle, GWL_STYLE);
//�ɰ�ť�������л�Edit�����ַ�����������й��ܯ�
if(Button1->Default)
  {dwStyle &= ~ES_UPPERCASE;
  dwStyle |= ES_NUMBER;
  StaticText1->Caption = "Edit1���<��ĸ��תΪ��д>���½�<������������>";
  }
else
  {dwStyle &= ~ES_NUMBER;
  dwStyle |= ES_UPPERCASE;
  StaticText1->Caption = "Edit1���<������������>���½�<��ĸ��תΪ��д>";
  }
//���޸ĵ��������ݣ�����Edit1����
::SetWindowLong(Edit1->Handle, GWL_STYLE, dwStyle);
Edit1->SetFocus();
//�л�����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
