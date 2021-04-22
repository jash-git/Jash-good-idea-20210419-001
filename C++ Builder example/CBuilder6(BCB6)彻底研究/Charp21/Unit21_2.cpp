//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include <vcl\printers.hpp>
#include "Unit21_2.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString Fname;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (OpenDialog1->Execute()) {
    	Fname=OpenDialog1->FileName;
        Label1->Caption="׼����ӡ "+Fname;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    AnsiString PageNum;
    int Ctr,i,PHeight,LineSpace,x;

    Printer()->BeginDoc();   // ����һ���µ�ӡ����
    x=0;             	     // ��ӡ�� x ����
    Ctr=1;                   // �����ӡ�����ı���
    PHeight=Printer()->PageHeight;
    LineSpace=PHeight / 60;
    PageNum=IntToStr(Printer()->PageNumber);
    Label1->Caption="��������ӡ��"+PageNum+"ҳ����.....";
    Memo1->Lines->LoadFromFile(Fname);  // ��ȡ��ӡ���ı��ļ�
	for(i=0; i<(Memo1->Lines->Count); i++) {  // ���ı��ļ�һ��һ�д�ӡ����
    	Printer()->Canvas->TextOut(0,x,Memo1->Lines->Strings[i]);
		x+=LineSpace;
        Ctr++;
        if (Ctr > 59) {		// �������60�о���ҳ
        	Printer()->NewPage();  // �ͳ���ҳ���
			x=0;
            Ctr=0;
            PageNum=IntToStr(Printer()->PageNumber);
		    Label1->Caption="��������ӡ��"+PageNum+"ҳ����.....";
        }
    }
    Printer()->EndDoc();
    Label1->Caption="��ӡ��ɣ�һ��ӡ��"+PageNum+"ҳ��";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

