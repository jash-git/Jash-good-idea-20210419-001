//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4_1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::O1Click(TObject *Sender)
{
  Label1->Font->Color=clRed;
  Label1->Caption="��ѡ�����ļ����½�";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::O2Click(TObject *Sender)
{
  Label1->Font->Color=clBlue;
  Label1->Caption="��ѡ�����ļ��Ĵ�";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N13Click(TObject *Sender)
{
  Label1->Font->Color=clGreen;
  Label1->Caption="��ѡ�����ļ������Ϊ";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N12Click(TObject *Sender)
{
  Label1->Font->Color=clGreen;
  Label1->Caption="��ѡ���Ǳ���ı���";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N3Click(TObject *Sender)
{
  Label1->Font->Color=clBlack;
  Label1->Caption="��ѡ���Ǳ�������Ϊ";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::P1Click(TObject *Sender)
{
  Label1->Font->Color=clYellow;
  Label1->Caption="��ѡ���Ǵ�ӡ";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::E2Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::N14Click(TObject *Sender)
{
  Panel1->Font->Size++;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N15Click(TObject *Sender)
{
  Panel1->Font->Size--;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N17Click(TObject *Sender)
{
  Panel1->Font->Color=clRed;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N18Click(TObject *Sender)
{
  Panel1->Font->Color=clBlue;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N20Click(TObject *Sender)
{
  Panel1->Alignment=taCenter;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N21Click(TObject *Sender)
{
  Panel1->Alignment=taLeftJustify;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::N22Click(TObject *Sender)
{
  Panel1->Alignment=taRightJustify;

}
//---------------------------------------------------------------------------

















