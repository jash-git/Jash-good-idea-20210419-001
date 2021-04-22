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
{//除第一次单击任一按钮外，即阻止保存原<开始>按钮图像
Button1->Default = true;
}
//---------------------------------------------------------------------------
//当程序关闭时，还原快捷工具栏下的<开始>按钮图标
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
SNDMSG(HButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)HOldBitmap);
::EnableWindow(HButton, true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//自定义函数返回<开始>按钮handle
HButton = DesktopHandle("Shell_TrayWnd");
//令<开始>按钮生效
::EnableWindow(HButton, true);
//送出重设图标信息，并返回原图标图像
HBITMAP tempBmp = (HBITMAP)SNDMSG(HButton, BM_SETIMAGE,
                            IMAGE_BITMAP,
                            (LPARAM)Image1->Picture->Bitmap->Handle);
//第一次按钮后，即停止传送<开始>图像
if(Button1->Default) HOldBitmap = tempBmp;
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//自定义函数返回<开始>按钮handle
HButton = DesktopHandle("Shell_TrayWnd");
//将<开始>按钮失效
::EnableWindow(HButton, false);
//送出重设图标信息，并返回原图标图像
HBITMAP tempBmp = (HBITMAP)SNDMSG(HButton, BM_SETIMAGE,
                             IMAGE_BITMAP,
                             (LPARAM)Image2->Picture->Bitmap->Handle);
//第一次按钮后，即停止传送<开始>图像
if(Button1->Default) HOldBitmap = tempBmp;
Button1->Default = false;
}
//---------------------------------------------------------------------------
//自定义函数--返回<开始>按钮handle
HWND TForm1::DesktopHandle(char *str)
{
char buffer[MAX_PATH];
//取得快捷工具栏的handle
HWND HTray = ::FindWindow(str, NULL);
//取得快捷工具栏下的子窗口handle
HWND HChild = ::GetWindow(HTray, GW_CHILD);
//逐一找寻到<开始>按钮对象handle
while(HChild)
   {
   ::GetClassName(HChild, buffer, sizeof(buffer));
   if (strcmp(buffer, "Button") == 0) break;
   //若否，则取得下一子窗口handle
   HChild = ::GetWindow(HChild, GW_HWNDNEXT);
   }
//返回<开始>按钮对象handle
return HChild;
}
//---------------------------------------------------------------------------


