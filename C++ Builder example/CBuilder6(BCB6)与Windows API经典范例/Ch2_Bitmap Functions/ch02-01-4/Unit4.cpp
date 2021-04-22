//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
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
void __fastcall TForm1::FormCreate(TObject *Sender)
{
MyBitmap = new Graphics::TBitmap();
MyBitmap = Image1->Picture->Bitmap;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
MyBitmap->PixelFormat=pf24bit;
colorData= new COLORREF[MyBitmap->Width*MyBitmap->Height];
MyBitmap->Canvas->Pen->Color = (TColor)RGB(125,255,125);//
DrawGrid(2, 2);

}
//---------------------------------------------------------------------------
void TForm1::DrawGrid(int GridWidth, int GridHeight)
{
for (int row=0;row<MyBitmap->Height;row+=GridHeight)
   {
   BYTE* scanPtr=(BYTE*)MyBitmap->ScanLine[row];
   for (int col=0;col<MyBitmap->Width;col+=GridWidth)
      {
      BYTE* tempPtr=scanPtr+col*3;
      int dataIndex=row*MyBitmap->Width+col;

      tempPtr[0]=GetRValue(colorData[dataIndex]);
      tempPtr[1]=GetGValue(colorData[dataIndex]);
      tempPtr[2]=GetBValue(colorData[dataIndex]);
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//释放所有图文件
for(int i=0;i<ComponentCount;i++)
  {if (Components[i]->ClassNameIs("TBitmap"))
      delete Components[i];
  }
}
//---------------------------------------------------------------------------

