//---------------------------------------------------------------------------
//Ŀ�ģ����������ָ������״̬���˷���������Win9*
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
{//������������Ϊboolֵ
Button1->Default = false;
//Ĭ��CheckBox1Ϊδѡȡ״̬
CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
Memo1->Text = "";//���Memo1��������
//ȡ�����ڼ���״̬
::GetKeyboardState((PBYTE)key);
//��Ԫ����--�жϼ����ض�����ֵ�������ֳ���
str=((bool)key[VK_NUMLOCK])?"Num Lockִ����":"Num Lock�ر���";
Memo1->Lines->Add(str);
str=((bool)key[VK_CAPITAL])?"Caps Lockִ����":"Caps Lock�ر���";
Memo1->Lines->Add(str);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�ı� NUMLOCK�������ֵ
//key[VK_NUMLOCK]����Num Lock��
key[VK_NUMLOCK] = (BYTE)Button1->Default;
//�������ڼ���״̬
::SetKeyboardState((PBYTE)key);
//��ָ������״̬���޸�Memo1�ַ���
str=((bool)key[VK_NUMLOCK])?"Num Lockִ����":"Num Lock�ر���";
Memo1->Lines->Strings[0] = str;
//�л����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
//�ı� Caps Lock�������ֵ
key[VK_CAPITAL] = CheckBox1->Checked ? (BYTE) 1 : (BYTE) 0;
//��ָ������״̬���޸�Memo1�ַ���
str=((bool)key[VK_CAPITAL])?"Caps Lockִ����":"Caps Lock�ر���";
Memo1->Lines->Strings[1] = str;
//�������ڼ���״̬
::SetKeyboardState((PBYTE)key);
}
//---------------------------------------------------------------------------


