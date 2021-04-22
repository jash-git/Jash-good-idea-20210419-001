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
//需在.h中加入 #include <shellapi.h>
//ShellExecute也可打开<文件总管>等系统对话框
::ShellExecute(::GetDesktopWindow(), "find", NULL,
     NULL, NULL, SW_SHOWNORMAL);
::ShellExecute(::GetDesktopWindow(), "explore", NULL,
     NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------
