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
//运用Button1的Default属性，作为bool运用
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1中所有文字
Memo1->Text = " ";
//被更动的RECT
RECT r = {0,0,1,1};
//设置2种不同的整数长宽
RECT r1 = {0,0,300,300};
RECT r2 = {0,0,200,200};
//若真，则r=r1；假，则r=r2
(Button1->Default)?r = r1:r = r2;
//再精确地调整窗口外框长宽
//加入标题、边框、菜单宽度
//dwStyle参数，在CreateWindow函数处详细列出
::AdjustWindowRect(&r,
                   WS_CAPTION|WS_BORDER,
                   true);//加入菜单宽高
//依照微调后的长宽、位置，重新设置窗口
::SetWindowPos(Handle,
               HWND_TOP,
               0,
               0,
               r.right-r.left,
               r.bottom-r.top,
               SWP_NOMOVE
               );
//显示微调后的实际长宽、位置
Memo1->Lines->Add("微调后的实际长宽、位置：");
Memo1->Lines->Add("上 "+AnsiString(r.top)+",左 "+AnsiString(r.left)+
              ",右 "+AnsiString(r.right)+",底 "+AnsiString(r.bottom));
Memo1->Lines->Add("原设置的实际长宽、位置：");
if(Button1->Default)
     Memo1->Lines->Add("上 "+AnsiString(r1.top)+",左 "+AnsiString(r1.left)+
                  ",右 "+AnsiString(r1.right)+",底 "+AnsiString(r1.bottom));
else
 Memo1->Lines->Add("上 "+AnsiString(r2.top)+",左 "+AnsiString(r2.left)+
              ",右 "+AnsiString(r2.right)+",底 "+AnsiString(r2.bottom));


//切换2种尺寸
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
