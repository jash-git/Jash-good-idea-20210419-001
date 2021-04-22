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
void __fastcall TForm1::StringGrid1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(StringGrid1->EditorMode)
  {
  //取得StringGrid1的handle
  HWND HEdit = FindWindowEx(StringGrid1->Handle, NULL,
                            "TInplaceEdit", NULL);
  //送出信息，返回输入点所在的字符位置，并显示出来
  int pos = LOWORD(SNDMSG(HEdit, EM_GETSEL, NULL, NULL));
  StaticText2->Caption = "现在编辑的位置在第 " + AnsiString(pos) + " 个字";
  }
}
//---------------------------------------------------------------------------
