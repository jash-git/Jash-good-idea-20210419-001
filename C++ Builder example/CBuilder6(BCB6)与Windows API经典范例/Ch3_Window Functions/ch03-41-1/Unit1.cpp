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
{//������������Ϊ����ֵ����
Button1->Default = true;
Button2->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ��CheckBox1��ԭ����������
DWORD dwStyle = ::GetWindowLong(CheckBox1->Handle, GWL_STYLE);
//��Ԫ������--�ɰ�ť�������л����水ť������������
(Button1->Default)?(dwStyle |= BS_PUSHLIKE):(dwStyle &= ~BS_PUSHLIKE);
//���޸ĵ��������ݣ�����CheckBox1����
::SetWindowLong(CheckBox1->Handle, GWL_STYLE, dwStyle);
CheckBox1->Refresh();//�ػ�CheckBox1
//�л�����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//��RadioGroup1�е��Ӷ�����һ������ʾ������
for(int i=0; i<RadioGroup1->ControlCount; ++i)
   {//���Ӷ���ת��Ϊͨ�ô��ڶ���
   TWinControl* Btnlike = static_cast<TWinControl*>
                              (RadioGroup1->Controls[i]);
   //ȡ��RadioGroup1�Ӷ����ԭ����������
   DWORD dwStyle = ::GetWindowLong(Btnlike->Handle, GWL_STYLE);
   //��Ԫ������--�ɰ�ť�������л����水ť������������
   (Button2->Default)?(dwStyle |= BS_PUSHLIKE):(dwStyle &= ~BS_PUSHLIKE);
   //���޸ĵ��������ݣ�����RadioGroup1�Ӷ�������
   ::SetWindowLong(Btnlike->Handle, GWL_STYLE, dwStyle);
   }
RadioGroup1->Refresh();//�ػ�RadioGroup1
//�л�����ֵ
Button2->Default = !Button2->Default;
}
//---------------------------------------------------------------------------

