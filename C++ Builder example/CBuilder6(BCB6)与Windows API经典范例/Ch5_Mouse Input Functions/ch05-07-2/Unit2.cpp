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
{
//Ԥ�Ƚ�����˫�����ʱ�䱣��
Tag = ::GetDoubleClickTime();
//��ʾ����˫�����ʱ��
StaticText2->Caption = "���˫�����Ϊ" + AnsiString(Tag)+ " ����";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//���رմ˳���ʱ���ָ�˫��ԭ���ٶ�
::SetDoubleClickTime(Tag);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDblClick(TObject *Sender)
{
//��˫�����ʱ���𽥼���
int gtime = ::GetDoubleClickTime() - 20;
//����˫�����ʱ��
::SetDoubleClickTime(gtime);
StaticText2->Caption = "���˫�����Ϊ" + AnsiString(gtime)+ " ����";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
//����ʱ����Խ���������˫���¼���ʱ��
//����OnClick�¼���OnDblClick�¼�
::Sleep(::GetDoubleClickTime()+1);

StaticText2->Caption = "���˫����������ร��ٿ�һ�㣡";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�ָ�˫��ԭ���ٶ�
::SetDoubleClickTime(Tag);
StaticText2->Caption = "���˫�����Ϊ" + AnsiString(Tag)+ " ����";
}
//---------------------------------------------------------------------------
