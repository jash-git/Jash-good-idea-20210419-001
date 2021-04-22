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
//参数声明
char longfilename[MAX_PATH];
char shortfilename[MAX_PATH];
TSearchRec SearchRecord;
AnsiString sfn,sfd;
//判断是否在根目录下
if(DirectoryListBox1->Directory.Length() < 4 )
   {
   sfn = String(DriveComboBox1->Drive) +":\\*.*";
   sfd = String(DriveComboBox1->Drive) +":\\";
   }
else
   {
   sfn = DirectoryListBox1->Directory + "\\*.*";
   sfd = DirectoryListBox1->Directory + "\\" ;
   }
//删除ListBox1中所有文字
ListBox1->Clear();
//开始寻找第一个符合条件的文件
if (::FindFirst(sfn.c_str(), faAnyFile, SearchRecord) == 0)
     {
     strcpy(longfilename, sfd.c_str());
     strcat(longfilename, SearchRecord.Name.c_str());
     //转换成 8.3 格式
     ::GetShortPathName(longfilename, shortfilename, MAX_PATH);
     //显示在ListBox1上
     ListBox1->Items->Add(ExtractFileName(shortfilename));
     //开始寻找下一个文件的循环
     while (::FindNext(SearchRecord) == 0)
          {
          strcpy(longfilename,  sfd.c_str());
          strcat(longfilename, SearchRecord.Name.c_str());
          //转换成 8.3 格式
          ::GetShortPathName(longfilename, shortfilename, MAX_PATH);
          //显示在ListBox1上
          ListBox1->Items->Add(ExtractFileName(shortfilename));
          }
     }
}
//---------------------------------------------------------------------------
