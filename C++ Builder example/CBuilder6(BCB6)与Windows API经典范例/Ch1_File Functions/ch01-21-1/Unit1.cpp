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
//ɾ��Memo1�������֦r
Memo1->Clear();

char TempPath[MAX_PATH+1] ;
//ȡ��ϵͳĬ�ϵĻ���Ŀ¼
if((int)::GetTempPath(MAX_PATH, TempPath))
   Memo1->Lines->Add("ϵͳ����Ŀ¼��" + AnsiString(TempPath));
//����Ĭ�ϻ���Ŀ¼�����½�����Ŀ¼
else if (!::CreateDirectory("C:\\TEMP", NULL))
   Memo1->Lines->Add("�½�ϵͳ����Ŀ¼(C:\TEMP\)ʧ�ܣ�");
}
//---------------------------------------------------------------------------
 