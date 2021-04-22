//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
Button1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
char buffer[MAX_PATH];
//取得快捷工具栏的 handle
HWND HTray = ::FindWindow("Shell_TrayWnd", NULL);
//再取得快捷工具栏下子选项的 handle
HWND HChild = ::GetWindow(HTray, GW_CHILD);
//因<开始>子选项是以按钮型态出现，故搜索按钮对象即可
while (HChild)
   {
   ::GetClassName(HChild, buffer, sizeof(buffer));
   if (strcmp(buffer, "Button") == 0) break;
   //子选项若非按钮状态，则返回下一子选项handle
   HChild = ::GetWindow(HChild, GW_HWNDNEXT);
   }
HButton = HChild;
//将<开始>按钮失效
::EnableWindow(HButton, false);
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//离开程序时，将<开始>按钮生效
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::EnableWindow(HButton, true);
}
//---------------------------------------------------------------------------
