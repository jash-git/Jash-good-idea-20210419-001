//---------------------------------------------------------------------------
//Ŀ�ģ������������ݣ���������Ϣת���ɰ������Ƴ���
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
//��׽����������Ϣ
void __fastcall TForm1::WMKeydown(TMessage &Msg)
{
char KeyName[255];
//����Ϣ�İ�������ת�ɰ������Ƴ���
if(::GetKeyNameText(Msg.LParam, KeyName, sizeof(KeyName)))
  Panel4->Caption = "��׽��  "+AnsiString(KeyName)+"  ��������";
else
  Panel4->Caption = "�˷���Ч������Ϣ";
}
//---------------------------------------------------------------------------
//����Ϊ�����¼�--OnKeyDown��OnKeyPress����
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//��⵽���ܼ�״̬
if(Shift.Contains(ssShift))
 Panel2->Caption = "��ס Shift ��";
if(Shift.Contains(ssAlt))
 Panel2->Caption = "��ס Alt ��";
if(Shift.Contains(ssCtrl))
 Panel2->Caption = "��ס Ctrl ��";
//��ʾ��������
Panel1->Caption = "�������룺"+AnsiString(IntToHex((int)Key,2));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
Panel3->Caption = "���ַ�����ʵ�ʳ���Ϊ��"+AnsiString(Key);
}
//---------------------------------------------------------------------------


