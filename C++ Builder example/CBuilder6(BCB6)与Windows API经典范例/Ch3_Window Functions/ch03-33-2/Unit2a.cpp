//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2a.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//������������Ϊ��������
Tag = 0;
//�������������½ǳ���
Top = Screen->Height - Height;
Left = Screen->Width - Width;
}
//---------------------------------------------------------------------------
//����Project2.exe���������Զ�����Ϣ����ת�����ַ���
void __fastcall TForm1::WMTwoWinMsg(TMessage& Msg)
{
AnsiString str = "�� " + AnsiString(++Tag) +
                 " �δ�Form1����-- " + AnsiString(Msg.WParam)+
                 ","+ AnsiString(Msg.LParam);
Memo1->Lines->Add(str);
}
//---------------------------------------------------------------------------
