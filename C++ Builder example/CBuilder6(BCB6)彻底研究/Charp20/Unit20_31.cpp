//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit20_32.h"
#include "Unit20_31.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

_di_IHeadLine TForm1::GetHeadLine()
{
  if (!FHeadLine)
  {
    HTTPRIO1->QueryInterface(FHeadLine);
  }
  return FHeadLine;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  if (HeadLine) {
    Memo1->Lines->Text=HeadLine->DelphiNews(0);
    Memo2->Lines->Text=HeadLine->CBuilderNews(0);
    Memo3->Lines->Text=HeadLine->JBuilderNews(0);
    Memo4->Lines->Text=HeadLine->KylixNews(0);
    Memo5->Lines->Text=HeadLine->SOAPNews(0);
    Memo6->Lines->Text=HeadLine->BorConNews(0);
  }
}
//---------------------------------------------------------------------------

