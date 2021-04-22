//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit20_21.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}

_di_IQueryCapital TForm1::GetQueryCapital()
{
  if (!FQueryCapital)
  {
    HTTPRIO1->QueryInterface(FQueryCapital);
  }
  return FQueryCapital;
}

//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
  if (QueryCapital) {
    ComboBox1->Items->Text=QueryCapital->QueryCountry();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  if (QueryCapital) {
    Label1->Caption=QueryCapital->QueryCapital(ComboBox1->Items->Strings[ComboBox1->ItemIndex]);
  }
}
//---------------------------------------------------------------------------

