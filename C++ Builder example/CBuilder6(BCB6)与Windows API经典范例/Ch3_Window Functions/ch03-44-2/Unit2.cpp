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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char str[256];
//ȡ��ϵͳʹ�����Դ���ID�����ɴ�IDȡ�ö����ַ���
::VerLanguageName(::GetSystemDefaultLangID(), str, 256);
//��ȡ�����ַ�������Form1�����ַ�����
::SetWindowText(Handle,str);
}
//---------------------------------------------------------------------------
