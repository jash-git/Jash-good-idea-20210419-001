//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
//����.h�м��� #include <shellapi.h>
//ShellExecuteҲ�ɴ�<�ļ��ܹ�>��ϵͳ�Ի���
::ShellExecute(::GetDesktopWindow(), "find", NULL,
     NULL, NULL, SW_SHOWNORMAL);
::ShellExecute(::GetDesktopWindow(), "explore", NULL,
     NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
