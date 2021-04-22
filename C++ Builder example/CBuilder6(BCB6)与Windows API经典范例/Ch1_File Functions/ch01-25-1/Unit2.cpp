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
   AnsiString FileName="C:\\aaa01.txt";
   char TheText[50]="This is some test text";
   HANDLE TheFile;
   DWORD BytesWritten;

   TheFile=CreateFile(FileName.c_str(),
                      GENERIC_WRITE,FILE_SHARE_READ,
                      NULL,
                      CREATE_ALWAYS,
                      FILE_ATTRIBUTE_NORMAL,
                      NULL);
   if(TheFile==INVALID_HANDLE_VALUE)
   {
      ShowMessage("无法建立新文件");
      return;
   }
   if(!WriteFile(TheFile,TheText,sizeof(TheText),&BytesWritten,NULL) ||
      sizeof(TheText)!=BytesWritten)
   {
      ShowMessage("文件无法写入新资料");
   }
   CloseHandle(TheFile);

}
//---------------------------------------------------------------------------
