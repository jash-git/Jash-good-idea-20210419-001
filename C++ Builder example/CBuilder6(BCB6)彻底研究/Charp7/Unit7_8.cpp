//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7_8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
extern "C" __declspec(dllimport) void __fastcall CustomerForm(char *st);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{

  void (*CustomerForm)(char *);


  HINSTANCE hInst=LoadLibrary("pDelphiDLL.dll");


  (FARPROC &)CustomerForm=GetProcAddress(hInst,"CustomerForm");


  CustomerForm(Edit1->Text.c_str());


  FreeLibrary(hInst);
}
//---------------------------------------------------------------------------
