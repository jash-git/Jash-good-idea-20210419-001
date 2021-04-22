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
//打开【打开】对话框
void __fastcall TForm1::Button1Click(TObject *Sender)
{
OpenDialog1->Execute();
}
//---------------------------------------------------------------------------
//在【打开】对话框显现时，改变特定标题
void __fastcall TForm1::OpenDialog1Show(TObject *Sender)
{
//取得【打开】对话框的handle
HWND hwndD = ::FindWindowEx(NULL,NULL,NULL,"打开");
//重设【打开】对话框的标题文字
::SetWindowText(hwndD,"测试--改变标题--");
//在【打开】对话框中，寻找特定标题文字的对象handle
HWND hw1 = ::FindWindowEx(hwndD,NULL,NULL,"搜索位置(&I):");
//重设此对象标题文字
::SetWindowText(hw1,"搜索_测试1");
HWND hw2 = ::FindWindowEx(hwndD,NULL,NULL,"打开(&O)");
::SetWindowText(hw2,"打开_测试2");
HWND hw3 = ::FindWindowEx(hwndD,NULL,NULL,"取消");
::SetWindowText(hw3,"OK_测试3");
HWND hw4 = ::FindWindowEx(hwndD,NULL,NULL,"文件名称(&N):");
::SetWindowText(hw4,"文件名称_测试4");
HWND hw5 = ::FindWindowEx(hwndD,NULL,NULL,"文件类型(&T):");
::SetWindowText(hw5,"类型_测试5");
}
//---------------------------------------------------------------------------
