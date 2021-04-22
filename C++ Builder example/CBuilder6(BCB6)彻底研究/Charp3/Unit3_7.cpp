//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_7.h"
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

void __fastcall TForm3::Image1DragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{
    if (dynamic_cast<TFileListBox *> (Source)!=0) {
        DeleteFile(FileListBox1->FileName.c_str());
        FileListBox1->Update();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Image1DragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
    if (dynamic_cast<TFileListBox *> (Source))
      	Accept = True;
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCreate(TObject *Sender)
{
    DriveComboBox1->DirList= DirectoryListBox1;
    DirectoryListBox1->FileList= FileListBox1;
    FilterComboBox1->FileList= FileListBox1;
}
//---------------------------------------------------------------------------

