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
//运用Button1的闲置属性，作为bool运用
Button1->Default = true;
///建立一新的简单窗口，提供位置给AVI文件播放
HAnimation =
     ::CreateWindow(ANIMATE_CLASS, NULL,
                    WS_CHILD | WS_VISIBLE | ACS_TRANSPARENT,
                    30,
                    (Panel1->Height-Animate1->Height)/2,
                    0, 0,
                    Panel1->Handle, NULL,
                    HInstance, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//重复单击按钮，可打开播放AVI文件或关闭AVI文件
if(Button1->Default)
   {
   //打开AVI文件--宏
   Animate_Open(HAnimation, "E:\\BCB--API\\0013 Window Functions\\Filecopy.avi");
   //播放AVI文件--宏
   Animate_Play(HAnimation, 0, -1, 15);
   }
else//关闭打开AVI文件--宏
   Animate_Close(HAnimation);

Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------


