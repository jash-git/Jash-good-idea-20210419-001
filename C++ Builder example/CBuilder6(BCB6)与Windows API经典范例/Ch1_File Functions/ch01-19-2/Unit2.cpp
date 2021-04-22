//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
//删除Memo1中所有文字
Memo1->Clear();
//显示指定目录的完整长路径
Memo1->Lines->Add("以下是完整长路径：");
Memo1->Lines->Add(GetAppNamePath(false));
Memo1->Lines->Add(" ");
//显示指定目录的DOS(8.3)路径
Memo1->Lines->Add("以下是DOS(8.3)路径：");
Memo1->Lines->Add(GetAppNamePath(true));
}
//---------------------------------------------------------------------------
AnsiString TForm1::GetAppNamePath(bool bName)
{
AnsiString dire;
//判断是否在根目录下
if(DirectoryListBox1->Directory.Length() < 4 )
   dire = DirectoryListBox1->Directory;
else
   dire = DirectoryListBox1->Directory + "\\";

char Buffer[MAX_PATH];
AnsiString path = "";
if (bName)
    {
    //路径转换成 8.3 格式
    ::GetShortPathName(dire.c_str(), Buffer, sizeof(Buffer));
    //检测是否为根目录or目录or文件or扩展名
    path = GetThisPath((AnsiString)Buffer,false);
    }
  else
    path = GetThisPath(dire.c_str(), false);
  return path;
}
//---------------------------------------------------------------------------
//判断根目录or目录or文件or扩展名，并返回字符串
AnsiString TForm1::GetThisPath(AnsiString path, bool bFileName)
{
AnsiString result = "";
try
  {
  char drive[MAXDRIVE];
  char dir[MAXDIR];
  char file[MAXFILE];
  char ext[MAXEXT];
  //判断根目录or目录or文件or扩展名，并返回字符串
  int flags = fnsplit(path.c_str(),drive,dir,file,ext);
  if(flags & DRIVE) result += drive;
  if(flags & DIRECTORY) result += dir;
  //判断是否要返回文件or扩展名
  if (bFileName)
     {
     if(flags & FILENAME) result += file;
     if(flags & EXTENSION) result += ext;
     }
  }
catch(...)
  {
  result = "";
  }
return result;
}
