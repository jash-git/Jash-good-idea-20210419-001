//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5_23.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
    // 釋放子視窗 Form3 所佔的記憶空間
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
    // 關閉子視窗 Form3
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::N7Click(TObject *Sender)
{
  Close();      
}
//---------------------------------------------------------------------------

