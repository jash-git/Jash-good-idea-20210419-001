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
//删除Memo1中所有文字
Memo1->Clear();

//取得指定文件的完整路径
char c[MAX_PATH];
char *s = "/Ghostfaq.txt";
//将程序现在目录所在填入此字符数组
::GetCurrentDirectory(MAX_PATH,c);
//将现在目录加上指定文件名
strcat( c, s);

//打开指定文件，并返回检测值
HANDLE hfp = ::CreateFile( c,
                           GENERIC_READ | GENERIC_WRITE,
                           0,
                           0,
                           OPEN_EXISTING,
                           FILE_ATTRIBUTE_NORMAL,
                           0);
//若无法打开指定文件
if (hfp == INVALID_HANDLE_VALUE)
   {
   Memo1->Lines->Add("在此程序相同目录下，未发现Ghostfaq.txt；");
   Memo1->Lines->Add("要测试本程序，请先以记事本制作Ghostfaq.txt。");
   }
//锁住指定文件，不得打开or执行
else if(::LockFile( hfp, (DWORD)100, (DWORD)0, (DWORD)200, (DWORD)0))
   Memo1->Text = "已经锁住目前目录下的Ghostfaq.txt";
else
   Memo1->Text = "无法锁住目前目录下的Ghostfaq.txt";
//小提示！
Memo1->Lines->Add("请放心！关闭本程序时，即解除Ghostfaq.txt的锁定。");
}
//---------------------------------------------------------------------------
