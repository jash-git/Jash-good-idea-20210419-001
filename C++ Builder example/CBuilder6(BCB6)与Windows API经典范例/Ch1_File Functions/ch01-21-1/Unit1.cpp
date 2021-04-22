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
//删除Memo1所有文字
Memo1->Clear();

char TempPath[MAX_PATH+1] ;
//取得系统默认的缓冲目录
if((int)::GetTempPath(MAX_PATH, TempPath))
   Memo1->Lines->Add("系统缓冲目录：" + AnsiString(TempPath));
//若无默认缓冲目录，则新建缓冲目录
else if (!::CreateDirectory("C:\\TEMP", NULL))
   Memo1->Lines->Add("新建系统缓冲目录(C:\TEMP\)失败！");
}
//---------------------------------------------------------------------------
 