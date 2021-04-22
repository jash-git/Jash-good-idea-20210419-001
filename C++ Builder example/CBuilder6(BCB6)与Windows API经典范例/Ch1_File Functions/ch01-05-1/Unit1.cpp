//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
for(int i=0; i<FileListBox1->Items->Count; i++)
   {
   //逐一处理被选取的文件
   if( FileListBox1->Selected[i] )
      {
      //取得完整路径&名称
      AnsiString FName = FileListBox1->Directory + "\\" + FileListBox1->Items->Strings[i];
      //删除此文件
      ::DeleteFile(FName.c_str());
      }
   }
//将文件表更新
FileListBox1->Update();
}
//---------------------------------------------------------------------------


