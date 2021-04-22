//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit7_f.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString st;
int AttrByte;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
  st=Edit1->Text;
  AttrByte=FileGetAttr(st);
 

  if ((AttrByte & faReadOnly)==faReadOnly) {
    CheckBox1->Checked=True;
  } else {
    CheckBox1->Checked=False;
  }

  if ((AttrByte & faHidden)==faHidden) {
    CheckBox2->Checked=True;
  } else {
    CheckBox2->Checked=False;
  }

  if ((AttrByte & faSysFile)==faSysFile) {
    CheckBox3->Checked=True;
  } else {
    CheckBox3->Checked=False;
  }

  if ((AttrByte & faArchive)==faArchive) {
    CheckBox4->Checked=True;
  } else {
    CheckBox4->Checked=False;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
  AttrByte=0;
  if (CheckBox1->Checked) AttrByte=(AttrByte | faReadOnly);

  if (CheckBox2->Checked) AttrByte=(AttrByte | faHidden);

  if (CheckBox3->Checked) AttrByte=(AttrByte | faSysFile);

  if (CheckBox4->Checked) AttrByte=(AttrByte | faArchive);

  FileSetAttr( st, AttrByte );
  
  ShowMessage("文件属性修改完成 !!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
  Close();        
}
//---------------------------------------------------------------------------

