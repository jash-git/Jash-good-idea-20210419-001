//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//- 2个取得子窗口的标准callback函数------------------------------------------
bool CALLBACK EnumProc(HWND, LPARAM);
bool CALLBACK EnumChildProc(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//漏斗状光标
Screen->Cursor = crHourGlass;
//在增加数据完毕前，先锁住更新画面
::LockWindowUpdate(Memo1->Handle);
//删除Memo1所有文字
Memo1->Clear();
//逐一搜寻经过所有窗口handle
::EnumWindows(
    reinterpret_cast <WNDENUMPROC> (EnumProc),
    reinterpret_cast <LPARAM> (Memo1)
  );
//重新启动被锁住的窗口更新
::LockWindowUpdate(0);
//光标恢复默认值
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
//设置扫描现在窗口信息，并调用扫描次一层子窗口
bool CALLBACK EnumProc(HWND HWin, LPARAM MemoAddress)
{
//尝试将LPARAM转换成Memo对象型态
TMemo* Memo = reinterpret_cast <TMemo*> (MemoAddress);
//取得窗口信息后，跳到下一行显示
String Line = "\r\n";
//取得现窗口handle的类别名称
char Buffer[128];
if(::GetClassName(HWin, Buffer, sizeof(Buffer)))
    Line += Buffer;
//取得现窗口的标题文字or内含文字
if(::GetWindowText(HWin, Buffer, sizeof(Buffer)))
    Line += (" (" + String(Buffer) + ")");
//由Memo1显示出来
Memo->Lines->Add(Line);
//再搜寻此窗口下的子窗口及对象handle
::EnumChildWindows(
    HWin,
    reinterpret_cast <WNDENUMPROC> (EnumChildProc),
    MemoAddress
    );
//返回真值，告知执行下次handle扫描
return true;
}
//---------------------------------------------------------------------------
//设置此扫描子窗口调用自己，将所有次一层子窗口都扫描过为止
bool CALLBACK EnumChildProc(HWND HWin, LPARAM MemoAddress)
{
//固定地址的变量，控制此子窗口阶层位置
static int Nesting = 0;
++Nesting;
//取得现在此子窗口的类别名称
char NameBuffer[128];
if(::GetClassName(HWin, NameBuffer, sizeof(NameBuffer)))
   {
   TMemo* Memo = reinterpret_cast <TMemo*> (MemoAddress);
   String NextLine;
   for(int i = 0; i < Nesting; ++i)
      NextLine += "-\t";
   NextLine += NameBuffer;
   Memo->Lines->Add(NextLine);
   }
//调用自己，执行再次一层的子窗口扫描，
//直到没有次一层子窗口为止
::EnumChildWindows(
    HWin,
    reinterpret_cast <WNDENUMPROC> (EnumChildProc),
    MemoAddress
    );
//回至现子窗口
--Nesting;
//返回真值，告知执行下次handle扫描
return true;
}
//---------------------------------------------------------------------------

