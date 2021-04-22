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
//删除ListBox1所有文字
ListBox1->Clear();
//先将完整路径(AnsiString)转成 char字符串
int leng = FileListBox1->FileName.Length();
char filename[MAX_PATH];
for(int i=0;i<=leng;i++)
    {
    if(i==leng)
       filename[i] = '\0';
    else
       filename[i] = FileListBox1->FileName[i+1];
    }
//显示文件完整路径
ListBox1->Items->Add("文件完整路径:");
ListBox1->Items->Add(AnsiString(filename));
OFSTRUCT ofs;
//取得指定文件handle
HFILE HMyFile = ::OpenFile(filename, &ofs, OF_READ);
//再取得此文件大小
double fsize = (double)::GetFileSize((void *)HMyFile, NULL);

AnsiString strsize;
if ( fsize < 1024)
    {
    strsize = FloatToStrF(fsize, ffNumber, 20, 0);
    ListBox1->Items->Add("文件大小:" + strsize + "个字节组");
    }
else if (fsize < (1024*1024))
    {
    strsize = FloatToStrF((fsize/1024), ffNumber, 20, 0);
    ListBox1->Items->Add("文件大小 " + strsize + " KB");
    }
else
    {
    strsize = FloatToStrF(fsize/(1024*1024),ffNumber, 20,2);
    ListBox1->Items->Add("文件大小 " + strsize + " MB");
    }

}
//---------------------------------------------------------------------------
