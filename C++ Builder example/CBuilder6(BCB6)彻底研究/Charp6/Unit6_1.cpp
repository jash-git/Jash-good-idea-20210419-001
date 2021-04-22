//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit6_1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
Graphics::TBitmap *pic;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button1Click(TObject *Sender)
{

  if (OpenDialog1->Execute()) {
    pic->LoadFromFile(OpenDialog1->FileName);
    ImageList1->Height=pic->Height;
    ImageList1->Width=pic->Width;
    ImageList1->Add(pic, NULL);
    ListBox1->Items->Add(Edit1->Text);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Button2Click(TObject *Sender)
{

  ImageList1->Delete(ListBox1->ItemIndex);
  ListBox1->Items->Delete(ListBox1->ItemIndex);
  Image1->Picture->Assign(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{

  ImageList1->Clear();
  ListBox1->Items->Clear();
  Image1->Picture->Assign(NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
  pic=new Graphics::TBitmap;

}
//---------------------------------------------------------------------------
void __fastcall TForm2::ListBox1Click(TObject *Sender)
{

  ImageList1->GetBitmap(ListBox1->ItemIndex, pic);


  Image1->Picture->Assign(pic);


  Image1->Width=pic->Width;
  Image1->Height=pic->Height;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
  pic->Free();

}
//---------------------------------------------------------------------------

