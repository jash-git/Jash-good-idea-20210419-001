//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//取得子窗口的callback函数---------------------------------------------------
bool CALLBACK EnumWindowsProc (HWND hWnd, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除TreeView1所有树状结构
TreeView1->Items->Clear();
//逐一搜寻经过所有窗口handle
::EnumWindows((WNDENUMPROC)EnumWindowsProc, NULL);
//展开TreeView1树状结构
TreeView1->FullExpand();
}
//---------------------------------------------------------------------------
//设置此扫描子窗口调用自己，将所有次一层子窗口都扫描过为止
bool CALLBACK EnumWindowsProc (HWND hWnd, LPARAM lParam)
{
//没有新handle时，则跳离
if (hWnd==NULL) return false;
//窗口正在运行中，则继续
if (!::IsWindowVisible(hWnd)) return true;
//取得现在窗口的类别名称与内含文字(标题)
char winTitle[128]; char winClass[128];
::GetClassName(hWnd, winClass, sizeof(winClass));
::GetWindowText(hWnd, winTitle, sizeof(winTitle));
//将取得文字传到TreeView1中
TTreeNode *ParentNode;
if (strlen(winTitle) > 0)
  ParentNode = Form1->TreeView1->Items->Add( Form1->TreeView1->Selected,
                                             "标题："+(AnsiString)winTitle);
else
  ParentNode = Form1->TreeView1->Items->Add( Form1->TreeView1->Selected,
                                             "标题：无");

Form1->TreeView1->Items->AddChild(ParentNode, "类："+(AnsiString)winClass);
//返回真值，告知执行下次handle扫描
return true;
}
//---------------------------------------------------------------------------

