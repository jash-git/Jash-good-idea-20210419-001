//---------------------------------------------------------------------------
#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit6_3.h"
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

void __fastcall TForm1::FormActivate(TObject *Sender)
{
  WIN32_FIND_DATA f;
  HANDLE h;
  char buf[255];
  TListItem *p;

  if (RadioButton1->Checked) ListView1->ViewStyle=vsSmallIcon;
  if (RadioButton2->Checked) ListView1->ViewStyle=vsIcon;
  if (RadioButton3->Checked) ListView1->ViewStyle=vsList;
  if (RadioButton4->Checked) ListView1->ViewStyle=vsReport;
  ListView1->Items->Clear();
  sprintf(buf,"%s%s", DirectoryListBox1->Directory.c_str(), "\\*.*");
  h=FindFirstFile(buf, &f);
  if (h != INVALID_HANDLE_VALUE) {
    p=ListView1->Items->Add();
    p->Caption=f.cFileName;
    sprintf(buf,"%d", f.nFileSizeLow);
    p->SubItems->Add(buf);
    while (FindNextFile(h,&f)) {
      p=ListView1->Items->Add();
      p->Caption=f.cFileName;
      sprintf(buf,"%d", f.nFileSizeLow);
      p->SubItems->Add(buf);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  ListView1->SmallImages=ImageList1;
  ListView1->LargeImages=ImageList2;
}
//---------------------------------------------------------------------------

