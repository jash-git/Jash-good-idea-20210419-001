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
//自定义函数--建立一ListView窗口，并返回handle
HListView = CreateListView();
// 若成功建立一新ListView窗口，则再进行自定义属性程序
if(HListView)
  {
  // 建立一新对象状态
  NewListViewWP = MakeObjectInstance(ListViewWndProc);
  // 设置新ListView对象属性，并保存原有对象属性，用于程序结束时，回复
  OldListViewWP = (TFarProc)::SetWindowLong(HListView, GWL_WNDPROC, (LONG)NewListViewWP);
  // 设置新ListView子项目属性
  LV_COLUMN lvc;
  lvc.mask = LVCF_WIDTH | LVCF_SUBITEM;
  lvc.cx = 100;
  lvc.iSubItem = 0;
  // 送出信息，改变ListView子项目属性
  SendMessage(HListView, LVM_INSERTCOLUMN, 0, (LPARAM)&lvc);
  lvc.iSubItem = 1;
  SendMessage(HListView, LVM_INSERTCOLUMN, 1, (LPARAM)&lvc);
  }
}
//---------------------------------------------------------------------------
// 程序关闭时，将ListView回复原始设置
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::SetWindowLong(HListView, GWL_WNDPROC, (LONG)OldListViewWP);
FreeObjectInstance(NewListViewWP);
}
//---------------------------------------------------------------------------
// 处理ListView窗口各种信息的函数，可依接收的不同信息，定出不同反应
void __fastcall TForm1::ListViewWndProc(TMessage &Msg)
{
if(Msg.Msg == WM_NOTIFY)
   {
   LPNMHDR lpnmh = (NMHDR *)Msg.LParam;
    // 当信息是鼠标右键单击ListView项目条时，即发出敲击声音
    if (lpnmh->code == NM_RCLICK)
        {
        Beep(10, 10);
        Msg.Result = true;
        return;
        }
    }
// 若非前面指定信息，则依照原来信息方式处理
Msg.Result = CallWindowProc((FARPROC)OldListViewWP, HListView,
                             Msg.Msg, Msg.WParam, Msg.LParam);
}
//---------------------------------------------------------------------------
// 建立一新ListView窗口
HWND TForm1::CreateListView()
{
return CreateWindow(WC_LISTVIEW, "--新的窗口--",
           WS_CAPTION | WS_CHILD | WS_VISIBLE | WS_BORDER | LVS_REPORT,
           10, 10,
           (ClientWidth/3)*2, (ClientHeight/3)*2,
           Handle, NULL, HInstance, NULL);
}
//---------------------------------------------------------------------------

