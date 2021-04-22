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
//������ת���ֵĽǶȷ�Χ
ScrollBar1->Max = 360;
ScrollBar1->Min = 0;
ScrollBar1->Position = 0;
//������ת���ֱ�����͸����
CheckBox1->Checked = false;
//������ת���ֵĳߴ硢���ͦr��
Canvas->Font->Size = 24;
Canvas->Font->Name = "Arial";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ScrollBar1Change(TObject *Sender)
{
//�򻯺�����������Ӿ����Ӷ�
int pos = ScrollBar1->Position;
//�л���ת����ɫ���뱳��ɫ��
if(CheckBox1->Checked)
  {
  Canvas->Font->Color = (TColor)RGB(pos-255,240-pos,pos/2);
  Canvas->Brush->Style = bsClear;
  }
else
  {
  Canvas->Font->Color = (TColor)RGB(pos-255,255-pos,pos/3);
  Canvas->Brush->Color = (TColor)RGB(pos-255,pos/2,240-pos);
  Canvas->Brush->Style = bsSolid;
  }
//ɾ��Form1�ϲ���ͼ��
Refresh();
//ȡ��Form1�������ݣ�����������������
LOGFONT f;
::GetObject(Canvas->Font->Handle, sizeof (LOGFONT), &f);
f.lfEscapement = ScrollBar1->Position*10;
f.lfOrientation = ScrollBar1->Position*10;
f.lfOutPrecision = OUT_TT_ONLY_PRECIS;
Canvas->Font->Handle = ::CreateFontIndirect (&f);
//ȡ��Form1��Χ�ߴ�
RECT r;
::GetClientRect(Handle,&r);
//����ת���ֻ��Ƶ�Form1��
Canvas->TextOut(r.right/5*2, r.bottom/5*2, Edit1->Text.c_str());
}
//---------------------------------------------------------------------------


