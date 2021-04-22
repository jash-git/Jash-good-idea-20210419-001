//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-取得CheckBox的信息值-----------------------------------------------------
#ifndef TVS_CHECKBOXES
#define TVS_CHECKBOXES 0x0100
#endif
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
// 取得原TreeView的类型资料
DWORD dwStyle = ::GetWindowLong(TreeView1->Handle, GWL_STYLE);
// 再加上CheckBox类型的新信息值
dwStyle = dwStyle | TVS_CHECKBOXES;
// 重设回TreeView，让TreeView状态中增加一新状态--CheckBox类型
SetWindowLong(TreeView1->Handle, GWL_STYLE, dwStyle);
}
//---------------------------------------------------------------------------
