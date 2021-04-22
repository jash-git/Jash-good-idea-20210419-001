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
//自定义函数，将现有磁盘卷标显示在ListBox1上
ShowDrive();
//将Form1的Tag属性作为 bool 使用
//判断是否选取ListBox1中项目
Tag = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//逐一搜索被选取的磁盘项目
for (int i = 0; i < ListBox1->Items->Count; i++)
  if (ListBox1->Selected[i])
    {
    AnsiString str = ListBox1->Items->Strings[i].SubString(1,3);
    //重设被选定的磁盘卷标
    if(::SetVolumeLabel(str.c_str(),Edit1->Text.c_str()))
         {
         ShowMessage("已经将 " + str + " 磁盘卷标\n改成"+Edit1->Text);
         //自定义函数，将现有磁盘卷标显示在ListBox1上
         ShowDrive();
         }
    else
         ShowMessage("无法更改 " + str + "磁盘卷标，\n请修改根目录位置");
    //若有选取ListBox1中项目
    Tag = false;
    }
//若没选取ListBox1中项目，则出现提示信息
if(Tag)
   ShowMessage("请先选择ListBox1中的磁盘，再单击按钮更改磁盘卷标！");
Tag = true;
}
//---------------------------------------------------------------------------
//自定义函数，将现有磁盘卷标显示在ListBox1上
void TForm1::ShowDrive()
{
//删除ListBox1所有文字
ListBox1->Clear();
//取得现在运行的逻辑磁盘
DWORD Drives = ::GetLogicalDrives();
for(int x = 0; x < 32; ++x)
    if(Drives & (1 << x))
       {
       String dr(char('A' + x));
       dr += ":\\";

       String Volume;
       Volume.SetLength(256);
       //取得根目录标题文字
       if(::GetVolumeInformation(dr.c_str(),
                                 Volume.c_str(),
                                 Volume.Length(),
                                 0,0, 0, 0, 0))
          {
          dr += " " + Volume;
          }
      //将结果显示在ListBox1上
      ListBox1->Items->Add(dr);
      }
}
//---------------------------------------------------------------------------


