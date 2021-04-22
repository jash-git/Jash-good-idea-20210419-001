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
//运用ShowWindow 函数，改变Project1母窗口显现状态
//ShowWindow各状态值在winuser.h中皆有定义，可自行查看
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
int show;//声明变量
//由多选一选项，选取显现状态
switch(RadioGroup1->ItemIndex)
   {
   case 0: show = SW_MAXIMIZE; break;
   case 1: show = SW_MINIMIZE; break;
   case 2: show = SW_RESTORE; break;
   case 3: show = SW_SHOW; break;
   case 4: show = SW_SHOWDEFAULT; break;
   case 5: show = SW_SHOWMAXIMIZED; break;
   case 6: show = SW_SHOWMINIMIZED; break;
   case 7: show = SW_SHOWMINNOACTIVE; break;
   case 8: show = SW_SHOWNA; break;
   case 9: show = SW_SHOWNOACTIVATE; break;
   case 10: show = SW_SHOWNORMAL; break;
   case 11: show = SW_HIDE; break;
   }
//改变Project1母窗口显现状态
::ShowWindow(Application->Handle, show);
}
//---------------------------------------------------------------------------
