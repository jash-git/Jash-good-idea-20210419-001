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
//默认按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
//预先关闭计时器
Timer1->Enabled = false;
Timer1->Interval = 100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//启动监视C:\temp目录中的文件异动
hChange = ::FindFirstChangeNotification("C:\\temp",
                                        true,//包括子目录
                                        FILE_NOTIFY_CHANGE_FILE_NAME);
//若此目录不存在
if (hChange == INVALID_HANDLE_VALUE)
   {
   ListBox1->Items->Add("C:\temp目录不存在or无法打开！");
   //送出关闭信息，结束程序
   Application->Terminate();
   }
else
   {
   //切换按钮状态
   Button1->Enabled = false;
   Button2->Enabled = true;
   //记录启动时间
   struct time st;
   gettime(&st);
   ListBox1->Items->Add("启动监视C:\\temp目录文件异动: " +
                        AnsiString(st.ti_hour) + "_" +
                        AnsiString(st.ti_min) + "_" +
                        AnsiString(st.ti_sec)
                        );

   //启动计时器时，计算文件异动值先归零
   counter = 0;
   //启动计时器
   Timer1->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//释放目录handle
::FindCloseChangeNotification(hChange);
//切换按钮状态
Button1->Enabled = true;
Button2->Enabled = false;
//默认计时器状态
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//若此线程有所改变时，传回信息
DWORD rc = ::WaitForSingleObject(hChange, 0);
//
if (rc == WAIT_OBJECT_0)
   {
   ListBox1->Items->Add( "共有 " + AnsiString(++counter) + " 次文件建立or更改or删除");
   //删除现在通知并等待下一更改通知
   ::FindNextChangeNotification(hChange);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//预防未释放目录handle
::FindCloseChangeNotification(hChange);
}
//---------------------------------------------------------------------------
 