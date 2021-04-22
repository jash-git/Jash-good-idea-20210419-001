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
//默认在C:\Temp\下建立新文件
AnsiString fileName="C:\\Temp\\test.txt";
DWORD BytesWritten;
//建立一新文件，并返回此新文件handle
HANDLE HFile=::CreateFile(fileName.c_str(),GENERIC_WRITE,
                          FILE_SHARE_READ,NULL,
                          CREATE_ALWAYS,
                          FILE_ATTRIBUTE_NORMAL | FILE_FLAG_WRITE_THROUGH,
                          NULL);
//若返回新文件handle，则进行输入文字
if(HFile!=INVALID_HANDLE_VALUE)
    {
    //将字符输入字符数组中
    char text[4096] = "";
    int leng = 25, a = 0;
    while(leng<4096)
       {
       AnsiString str = "这是第 " + AnsiString(++a) + "个字符串。\n";
       strcat(text,str.c_str());
       leng += str.Length();
       }
    //将text字符数组输入到指定文件中
    if(::WriteFile(HFile,text,sizeof(text),&BytesWritten,NULL) ||
       sizeof( text) == BytesWritten)
          Memo1->Lines->Add("成功将"+AnsiString(a)+" 个字符串输入到指定文件中。");
       else
          Memo1->Lines->Add("字符串无法输入到文件中。");
    }
else
    Memo1->Lines->Add("无法建立一新文本文件！");

//释放handle
::CloseHandle(HFile);
}
//---------------------------------------------------------------------------
