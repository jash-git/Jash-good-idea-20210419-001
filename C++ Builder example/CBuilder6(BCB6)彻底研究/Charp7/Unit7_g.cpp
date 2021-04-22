//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7_g.h"
#include <comobj.hpp>
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
    Variant V;
    AnsiString str;
    int i;

    V=CreateOleObject("Word.Basic");


    V.Exec(Procedure("AppShow"));
    V.Exec(Procedure("FileNew") << "Normal");


    Query1->SQL->Add("Select company, contact, phone from customer");
    Query1->Open();
    while (!Query1->Eof) {
      str="";

      for (i=0;i<(Query1->FieldCount-1);i++)
        str=str+Query1->Fields->Fields[i]->AsString+"  "+13;


      V.Exec(Procedure("Insert") << str);

      Query1->Next();
    }
    Query1->Close();


    V.Exec(Procedure("FileSaveAs") << Edit1->Text);


    V.Exec(Procedure("AppClose"));

    Button1->Caption="±£´æÍê±Ï!!";
}
//---------------------------------------------------------------------------

