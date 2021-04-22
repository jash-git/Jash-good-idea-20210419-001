//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//运用闲置属性，作为bool运算
Button1->Default = true;
}
//---------------------------------------------------------------------------
//在程序开始时，Image1List即加载系统工具栏的图标
//第一种加载方式
void __fastcall TForm1::FormCreate(TObject *Sender)
{
//建立一临时新工具栏ToolBar对象
HWND HToolBar = ::CreateWindowEx(0, TOOLBARCLASSNAME,
                                 (LPSTR) NULL,
                                 WS_CHILD, 0, 0, 0, 0,
                                 Handle, (HMENU)0,
                                 HInstance, NULL);
//取得与ImageList组件关联
SNDMSG(HToolBar, TB_SETIMAGELIST, 0, (LPARAM)ImageList1->Handle);
//再由系统加载图标到ImageList中，并显示出来
SNDMSG(HToolBar, TB_LOADIMAGES, IDB_STD_LARGE_COLOR,
       (LPARAM)HINST_COMMCTRL);
//完成后，关闭此临时工具栏ToolBar对象
::DestroyWindow(HToolBar);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//执行自定义函数
if(Button1->Default)
   LoadAllIcons(ImageList1, ToolBar1->Handle, eSmallIcons);
else
   LoadAllIcons(ImageList1, ToolBar1->Handle, eLargeIcons);
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

bool TForm1::LoadAllIcons(TImageList * List, HWND Handle, SizeIcon iconsize)
{
//决定成功与否的返回值
bool OK;
//决定图示尺寸
if(iconsize == eSmallIcons)
  {List->Width=16; List->Height=16; }
else
  {List->Width=24; List->Height=24; }
//
//图示大小定义在Commctrl.h中
if(iconsize == eSmallIcons)
  iconsize = (SizeIcon)IDB_STD_SMALL_COLOR;
else
  iconsize = (SizeIcon)IDB_STD_LARGE_COLOR;
//建立一临时新工具栏ToolBar对象
HWND hToolBar =
     ::CreateWindowEx(0, TOOLBARCLASSNAME, (LPSTR) NULL,
                      WS_CHILD,
                      0, 0,
                      0, 0,
                      Handle, (HMENU)0, HInstance, NULL);
if(hToolBar)
  {
  //取得与ImageList组件关联
  SNDMSG(hToolBar, TB_SETIMAGELIST, 0, (LPARAM)List->Handle);
  //再由系统加载图标到ImageList中，并显示出来
  SNDMSG(hToolBar, TB_LOADIMAGES,
         iconsize,(LPARAM)HINST_COMMCTRL);
  //完成后，关闭此临时工具栏ToolBar对象
  ::DestroyWindow(hToolBar);
  //看看有无其他事件需执行
  Application->ProcessMessages();
  OK = true;
  }
else
  OK = false;
//返回成功与否
return OK;
}
//---------------------------------------------------------------------------

