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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//在打开窗口中寻找<连接到对话框>，
//若有，则返回其handle
HWND handle = NULL;
handle = ::FindWindow( NULL, "联机到");
//确定【连接到】对话框已打开，则提到最前面显示
if(::IsWindow(handle))
   {
   ::ShowWindow( handle, SW_SHOWMINIMIZED);
   ::ShowWindow( handle, SW_SHOWNORMAL);
   Caption = "【连接到】对话框已打开并显示！";
   }
else
   Caption = "【连接到】对话框并未打开并显示！";
}
//---------------------------------------------------------------------------
