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
    // ����l���� Form3 �Ҧ����O�ЪŶ�
    Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::N6Click(TObject *Sender)
{
    // �����l���� Form3
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm3::N7Click(TObject *Sender)
{
  Close();      
}
//---------------------------------------------------------------------------

