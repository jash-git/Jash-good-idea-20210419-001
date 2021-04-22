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
//Form1handle
HWND hdle = Form1->Handle;
RECT rect = {150,150,400,400};
//<1>分配内存位置给多绪窗口并返回位置handle
HDWP hbwinp = ::BeginDeferWindowPos( 1 );
//<2>更新内存位置给多绪窗口并返回位置handle
HDWP hwinp = ::DeferWindowPos(hbwinp, hdle,
                              HWND_TOPMOST,
                              rect.left, rect.top,
                              rect.right, rect.bottom,
                              SWP_DRAWFRAME | SWP_NOSIZE
                              | SWP_NOACTIVATE
                              );
//<3>在一致的屏幕更新循环中，大小&位置都同步更新完成
::EndDeferWindowPos(hwinp);
//<4>依照微调后的长宽、位置，重新设置窗口
::SetWindowPos(hdle,
               HWND_TOP,
               rect.left, rect.top,
               rect.right-rect.left,
               rect.bottom-rect.top,
               SWP_SHOWWINDOW
               );
}
//---------------------------------------------------------------------------


