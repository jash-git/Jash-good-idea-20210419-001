//---------------------------------------------------------------------------
//Ŀ�ģ�����������Ҽ�����
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
{//Ĭ��CheckBox1״̬
CheckBox1->Checked = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked)
   {//����������Ҽ�����
   ::SwapMouseButton(true);
   StaticText1->Caption = "������Ҽ����ڽ����У�";
   }
else //������Ҽ����ָܻ�Ĭ��
   {
   ::SwapMouseButton(false);
   StaticText1->Caption = "������Ҽ����ڻָ�������";
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{//�뿪����ʱ���ָ�������Ҽ�����״̬
::SwapMouseButton(false);
}
//---------------------------------------------------------------------------
//������ѡ��
void __fastcall TForm1::FileSub101Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,160);
}
//---------------------------------------------------------------------------
//������ѡ��
void __fastcall TForm1::FileSub102Click(TObject *Sender)
{
Color = clBtnFace;
}
//---------------------------------------------------------------------------



