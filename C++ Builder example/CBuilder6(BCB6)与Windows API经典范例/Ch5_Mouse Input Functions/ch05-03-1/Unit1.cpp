//---------------------------------------------------------------------------
//Ŀ�ģ������Form1��˫��ʱ�����˫�����ʱ�䣬����ʹʱ������
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
{//Ԥ�Ƚ�����˫�����ʱ�䱣��
Tag = ::GetDoubleClickTime();
//��ʾ����˫�����ʱ��
StaticText2->Caption = "���˫�����Ϊ  " + AnsiString(Tag)+ " ����";
}
//---------------------------------------------------------------------------
//���رմ˳���ʱ���ָ�˫��ԭ���ٶ�
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
::SetDoubleClickTime(Tag);
}
//---------------------------------------------------------------------------
//��ϵͳ�ж����Ϊ˫���¼�ʱ
void __fastcall TForm1::FormDblClick(TObject *Sender)
{//��˫�����ʱ���𽥼���
int gtime = ::GetDoubleClickTime() - 20;
//����˫�����ʱ��
::SetDoubleClickTime(gtime);
//��ʾ���˫��ʱ������ı���ɫ��
StaticText2->Caption = "���˫�����Ϊ" + AnsiString(gtime)+ " ����";
Color=(Button1->Default)?(TColor)RGB(128,255,200):(TColor)RGB(255,200,128);
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
//��ϵͳ�ж����Ϊ�����¼�ʱ
void __fastcall TForm1::FormClick(TObject *Sender)
{//����ʱ����Խ���������˫���¼���ʱ��
//����OnClick�¼���OnDblClick�¼�
::Sleep(::GetDoubleClickTime()+1);
//��ʾ���˫��ʱ������ı���ɫ��
StaticText2->Caption = "���˫���������ˣ��ٿ�һ�㣡";
Color = clBtnFace;
}
//---------------------------------------------------------------------------
//�ָ�˫��ԭ���ٶ�
void __fastcall TForm1::Button1Click(TObject *Sender)
{
::SetDoubleClickTime(Tag);
StaticText2->Caption = "���˫�����Ϊ " + AnsiString(Tag)+ " ����";
}
//---------------------------------------------------------------------------
