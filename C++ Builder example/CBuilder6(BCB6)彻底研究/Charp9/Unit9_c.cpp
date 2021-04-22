//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit9_c.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
Graphics::TBitmap *pic1,*pic2,*pic3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

  pic1=new Graphics::TBitmap;
  pic2=new Graphics::TBitmap;
  pic3=new Graphics::TBitmap;
  pic1->LoadFromFile("Bitmap1.bmp");
  pic2->LoadFromFile("Bitmap2.bmp");
  pic3->LoadFromFile("Bitmap3.bmp");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1DblClick(TObject *Sender)
{
  if (DBGrid1->SelectedField->FieldName != "Preferred") return;


  DBGrid1->DataSource->DataSet->Edit();


  if(DBGrid1->SelectedField->DisplayText=="True") {
    DBGrid1->SelectedField->AsString="False";
  } else {
    DBGrid1->SelectedField->AsString="True";
  }


  DBGrid1->DataSource->DataSet->Post();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::DBGrid1DrawColumnCell(TObject *Sender,
      const TRect &Rect, int DataCol, TColumn *Column,
      TGridDrawState State)
{
  int x,y;


  if (Column->FieldName != "Preferred") return;


  DBGrid1->Canvas->StretchDraw(Rect, pic3);
  x=(Rect.Right-Rect.Left-pic1->Width)/2;
  y=(Rect.Bottom-Rect.Top-pic1->Height)/2;


  if (Column->Field->DisplayText=="True") {
    DBGrid1->Canvas->Draw(Rect.Left+x, Rect.Top+y, pic1);
  } else {
    DBGrid1->Canvas->Draw(Rect.Left+x, Rect.Top+y, pic2);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  delete pic1;
  delete pic2;
  delete pic3;
}
//---------------------------------------------------------------------------
