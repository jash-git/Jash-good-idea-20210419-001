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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����һ�ַ�����
char c[MAX_PATH];
//����������Ŀ¼����������ַ�����
if(::GetCurrentDirectory(MAX_PATH,c))
    StaticText2->Caption = "����ĿǰĿ¼�� " + AnsiString(c);
else
    StaticText2->Caption = "ȡ��ĿǰĿ¼ʧ�ܣ�";

}
//---------------------------------------------------------------------------
