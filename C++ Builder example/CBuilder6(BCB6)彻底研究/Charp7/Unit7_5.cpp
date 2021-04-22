//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit7_5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
extern "C" __declspec(dllimport) int __stdcall PCopyFile(char *sour, char*targ);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
   FileListBox1->DragMode=dmAutomatic;    
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DirectoryListBox2DragOver(TObject *Sender,
      TObject *Source, int X, int Y, TDragState State, bool &Accept)
{
   Accept = Source->ClassNameIs("TFileListBox");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DirectoryListBox2DragDrop(TObject *Sender,
      TObject *Source, int X, int Y)
{
   AnsiString FromF,ToF;

   FromF=FileListBox1->FileName;
   ToF=DirectoryListBox2->Directory+"\\"+FileListBox1->FileEdit->Text;
   PCopyFile(FromF.c_str(),ToF.c_str());
   ShowMessage("已完成複製動作！");
}
//---------------------------------------------------------------------------




