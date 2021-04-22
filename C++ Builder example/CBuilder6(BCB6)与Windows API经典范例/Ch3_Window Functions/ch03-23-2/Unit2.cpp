//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//<打开旧文件>对话框的信息函数与结构函数---------------------------------------
UINT APIENTRY OFNHookProc(HWND, UINT, WPARAM, LPARAM);
bool ShowOpenDialog(HWND, char *FileName, char *Title,
                    char *InitialDir, char *Filter);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//打开<打开>对话框
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char FileName[MAX_PATH];
if (ShowOpenDialog(Handle,
                   FileName,
                   "标准API【打开】对话框",
                   "C:\\Program Files",
                   "Text Files (*.txt)\0*.txt\0"
                   "Zip Files (*.zip)\0*.zip\0"
                   "All Files (*.*)\0*.*\0"))
    {
    ::MessageBox(Handle, FileName, "选择文件是：", MB_OK);
    }
}
//<打开旧文件>对话框的信息函数-------------------------------------------------
UINT APIENTRY OFNHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam, LPARAM lParam)
{
//
HWND HOpenDialogBox = ::GetParent(hdlg);
//当<打开>对话框取得初始化信息时，
//即送出改变特定对象标题文字
if (uiMsg == WM_INITDIALOG)
    {
    SNDMSG(HOpenDialogBox, CDM_SETCONTROLTEXT,
           IDOK, (LPARAM)"SUBMIT!");
    }
return 0L;
}
//<打开旧文件>对话框的结构设置函数---------------------------------------------
bool ShowOpenDialog(HWND HWndOwner, char *FileName, char *Title,
    char *InitialDir, char *Filter)
{
//声明OPENFILENAME结构
OPENFILENAME ofn;
//先整理结构位置内容
ZeroMemory(&ofn, sizeof(OPENFILENAME));
char szFile[MAX_PATH];
ZeroMemory(szFile, MAX_PATH);
//开始设置OPENFILENAME结构成员
ofn.lStructSize = sizeof(OPENFILENAME);
ofn.hwndOwner = HWndOwner;
ofn.lpstrFile = szFile;
ofn.nMaxFile = MAX_PATH;
ofn.lpstrFilter = Filter;
ofn.nFilterIndex = 0;
ofn.lpstrTitle = Title;
ofn.lpstrInitialDir = InitialDir;
//此对话框具有新窗口风格、多重选取文件与自定义信息内容
ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST | OFN_ENABLEHOOK;
//自定义信息内容
ofn.lpfnHook = OFNHookProc;
//填完结构成员后，指派给"打开"对话框，并显示对话框
if (::GetOpenFileName(&ofn))
    {//若有选取到文件，则返回文件名称与真值
    strcpy(FileName, ofn.lpstrFile);
    return true;
    }
//否则返回伪值   
return false;
}
//---------------------------------------------------------------------------

