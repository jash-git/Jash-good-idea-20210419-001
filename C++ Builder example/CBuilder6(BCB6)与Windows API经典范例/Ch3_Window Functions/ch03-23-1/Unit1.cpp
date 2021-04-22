//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//原<打开>对话框的说明文字代码-------------------------------------------
#define IDLOOKIN 1091
#define IDFILENAME 1090
#define IDFILETYPE 1089
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//打开原<打开>对话框类型
void __fastcall TForm1::Button1Click(TObject *Sender)
{
OpenDlg = new TOpenDialog(this);
//将自定义OnShow函数指派给OpenDlg
OpenDlg->OnShow = AllOpenDlgShow;
OpenDlg->Title = "改变了的打开对话框";
OpenDlg->Execute();
delete OpenDlg;
}
//---------------------------------------------------------------------------
//自定义OnShow函数，改变说明文字
void __fastcall TForm1::AllOpenDlgShow(TObject *Sender)
{
//取得按钮的母窗口，再重设指定对象的标题文字
HWND hd = ::GetParent(OpenDlg->Handle);
::SetDlgItemText( hd, IDOK, "选择这个？");
::SetDlgItemText( hd, IDCANCEL, "不作改变！");
//送出改变对象文字的信息
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDLOOKIN, (LPARAM)"我的搜索区>");
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDFILENAME, (LPARAM)"我的文件名称>");
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDFILETYPE, (LPARAM)"我的文件类型>");
}
//---------------------------------------------------------------------------
//重载<打开>对话框，并打开显示
void __fastcall TForm1::Button2Click(TObject *Sender)
{
TMySelectDlg *msd = new TMySelectDlg(this);
msd->Execute();
delete msd;
}
//---------------------------------------------------------------------------
//重载<打开旧文件>对话框的信息处理函数
void __fastcall TMySelectDlg :: WndProc(Messages::TMessage &Msg)
{
//信息依照原方式处理
TOpenDialog::WndProc(Msg);
//取得按钮的母窗口，再重设此对象的标题文字
::SetDlgItemText(::GetParent(Handle), IDOK, "&Select?");
::SetDlgItemText(::GetParent(Handle), IDCANCEL, "&Cancel!");
}
//---------------------------------------------------------------------------

