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
//在Win95下无作用
void __fastcall TForm1::Button1Click(TObject *Sender)
{
AnsiString S;
AnsiString Filename = FileListBox1->FileName;
DWORD BType;

if(::GetBinaryType(Filename.c_str(), &BType))
   {
   switch(BType)
     {
     case SCS_32BIT_BINARY:
        S = "Win32 executable";break;
     case SCS_DOS_BINARY:
        S = "DOS executable";break;
     case SCS_WOW_BINARY:
        S = "Win16 executable";break;
     case SCS_PIF_BINARY:
        S = "PIF file";break;
     case SCS_POSIX_BINARY:
        S = "POSIX executable";break;
     case SCS_OS216_BINARY:
        S = "OS/2 16 bit executable";break;
     default :
        S = "unknown executable";
     }
   }
else
   S = "File is not an executable";
StaticText1->Caption = S;
}
//---------------------------------------------------------------------------

