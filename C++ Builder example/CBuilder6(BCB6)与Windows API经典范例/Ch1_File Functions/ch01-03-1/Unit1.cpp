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
// 若已经输入新路径名称
if(Edit1->Text !="")
   {
   AnsiString dir = DirectoryListBox1->Directory;
   //分辨是否在根目录下
   if(dir.Length()>4)
      dir = dir + "\\" + Edit1->Text;
   else
      dir = dir + Edit1->Text;
   // 在程序中显示新目录的完整路径
   StaticText1->Caption = "新建目录路径：" + dir;
   //若新建目录失败
   if(!::CreateDirectory(dir.c_str(), NULL))
      ShowMessage("新建目录失败！");
   //若新建目录成功，则更新显示
   DirectoryListBox1->Update();
   }
else
   ShowMessage("空白无效！请输入有效目录名称。");
}
//---------------------------------------------------------------------------

