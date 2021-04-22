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
//清空Memo1上文字
Memo1->Clear();
AnsiString showstr;
//由WINDOWPLACEMENT结构成员，取得指定窗口配置信息
WINDOWPLACEMENT Wpl;
Wpl.length = sizeof(WINDOWPLACEMENT);
::GetWindowPlacement(Handle, &Wpl);
//以下依照取得之窗口配置结构成员，由Memo1显示
//Wpl.flags结构成员
if(Wpl.flags == WPF_RESTORETOMAXIMIZED)
   showstr = "回复成原先最大化状态";
else if(Wpl.flags == WPF_SETMINPOSITION)
   showstr = "指定最小化的位置";
else if(Wpl.flags == (WPF_RESTORETOMAXIMIZED & WPF_SETMINPOSITION))
   showstr = "兼具恢复成原先最大化状态与指定最小化的位置";
Memo1->Lines->Add(showstr);
//Wpl.showCmd结构成员
switch(Wpl.showCmd)
    {
    case SW_HIDE :
       showstr = "这个窗口在隐藏状态"; break;
    case SW_MINIMIZE :
       showstr = "这个窗口在缩到快捷工具栏中"; break;
    case SW_RESTORE :
       showstr = "这个窗口是恢复在桌面时的状态"; break;
    case SW_SHOW :
       showstr = "这个窗口在显示状态"; break;
    case SW_SHOWMAXIMIZED :
       showstr = "这个窗口在最大化状态"; break;
    case SW_SHOWMINIMIZED :
       showstr = "这个窗口在显示成图标状态"; break;
    case SW_SHOWMINNOACTIVE :
       showstr = "这个窗口在显示图标状态"; break;
    case SW_SHOWNA :
       showstr = "这个窗口在维持目前状态"; break;
    case SW_SHOWNOACTIVATE :
       showstr = "这个窗口在显示上次状态"; break;
    case SW_SHOWNORMAL :
       showstr = "这个窗口在启动状态"; break;
    default :
       showstr = "这个窗口是不明状态"; break;
    }
Memo1->Lines->Add(showstr);
//Wpl.ptMinPosition结构成员
showstr = "最小化时位置在X= " + AnsiString(Wpl.ptMinPosition.x) +
          AnsiString(Wpl.ptMinPosition.y);
Memo1->Lines->Add(showstr);
//Wpl.ptMaxPosition结构成员
showstr = "最大化时位置在X=  " + AnsiString(Wpl.ptMaxPosition.x) +
          AnsiString(Wpl.ptMaxPosition.y);
Memo1->Lines->Add(showstr);
//Wpl.rcNormalPosition结构成员
RECT r = Wpl.rcNormalPosition;
showstr = "窗口在桌面上时，左边在" + AnsiString(r.left) +
          "，上边在" + AnsiString(r.top) +
          "，右边在 " + AnsiString(r.right) +
          "，底边在" + AnsiString(r.bottom);
Memo1->Lines->Add(showstr);
}
//---------------------------------------------------------------------------
