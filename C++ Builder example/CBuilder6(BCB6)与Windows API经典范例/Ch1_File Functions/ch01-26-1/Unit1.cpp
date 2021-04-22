//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
// 宏定义----------------------------------------------------------------------
#define max(a, b)  (((a) > (b)) ? (a) : (b))
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//目录组件，也可在各组件的 Properties 中直接设置
/*
  DirectoryListBox1->FileList = FileListBox1;
  DriveComboBox1->DirList = DirectoryListBox1;
*/
//默认程序开始时的目录
DriveComboBox1->Drive = 'C';
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得选取的目录路径
char* dir = DirectoryListBox1->GetItemPath(DirectoryListBox1->ItemIndex).c_str();
//预先指定删除后的前一目录位置，max为自定义宏
int nextdir = max(DirectoryListBox1->ItemIndex - 1, 0);
//删除指定目录
if (::RemoveDirectory(dir))
   {
   if(MessageDlg("您要删除这个指定目录？", mtConfirmation,
                 TMsgDlgButtons() << mbYes << mbNo,
                 0) == mrYes)
        {
         DirectoryListBox1->Update();
         //取得删除后的前一目录位置
         DirectoryListBox1->ItemIndex = nextdir;
         //打开删除后的前一目录
         DirectoryListBox1->OpenCurrent();
        }
   }
else
    ShowMessage("删除这个指定目录前，\n请先删除内含文件！");

}
//---------------------------------------------------------------------------
