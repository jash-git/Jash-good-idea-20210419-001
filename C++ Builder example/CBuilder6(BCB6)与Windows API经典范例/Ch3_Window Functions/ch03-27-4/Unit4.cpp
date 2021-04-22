//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
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
//再次确认片头窗口图像加载的路径
char sysDir[MAX_PATH +1];
//取得系统的目录路径，并加以修改
::GetSystemDirectory(sysDir, sizeof(sysDir));
AnsiString dir = AnsiString(sysDir);
dir = dir.SubString(1, dir.Length()-6)+"Setup.bmp";
StaticText1->Caption = dir;
}
//---------------------------------------------------------------------------

