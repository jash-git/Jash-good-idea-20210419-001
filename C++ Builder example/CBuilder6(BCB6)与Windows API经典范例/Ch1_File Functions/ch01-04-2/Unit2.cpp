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
//删除所有项目
ListBox1->Clear();
//默认检测COM端口的返回值
HANDLE h = INVALID_HANDLE_VALUE;
//逐一进行COM 端口检测
for(int i=1;i<=32;i++)
   {
   AnsiString comname = "\\\\.\\COM" + String(i);
   //打开COM端口，并返回检测值
   h = ::CreateFile( comname.c_str(),
                     GENERIC_READ | GENERIC_WRITE,
                     0,
                     0,
                     OPEN_EXISTING,
                     FILE_ATTRIBUTE_NORMAL,
                     0);
   //若无法打开指定COM 端口
   if (h == INVALID_HANDLE_VALUE)
      {
      //取得错误信息
      DWORD err = ::GetLastError();
      //若 err 为 2 ，即此COM端口尚未安装
      if (err!=2)
         {
         ListBox1->Items->Add("COM" + AnsiString(i) +
                              " 尚未使用，错误信息为 (" +
                              AnsiString((int)err) + ")");
         }
      }
   else
      {
      ListBox1->Items->Add("COM" + AnsiString(i) + " 正在使用中！");
      }
   //释放handle
   ::CloseHandle(h);
   }

}
//---------------------------------------------------------------------------
