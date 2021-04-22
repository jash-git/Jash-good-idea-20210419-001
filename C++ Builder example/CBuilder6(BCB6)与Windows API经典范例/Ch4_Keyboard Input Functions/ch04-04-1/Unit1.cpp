//---------------------------------------------------------------------------
//目的：若鼠标移动时传入的窗口handle相异于键盘焦点，焦点即跳至form窗口上
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
{//让Panel1美观，突显子窗口
Panel1->Color = (TColor)RGB(255,255,200);
}
//---------------------------------------------------------------------------
//在程序显现时，创造4个不同位置的缩小状态子窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{//动态创造出四个子窗口
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Panel1;
   form->Name = "FORM_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Top = i*60; form->Left = i*40;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   form->Show();
   //子窗口通用的OnMouseMove事件
   form->OnMouseMove = AllFormMouseMove;
   }
}
//---------------------------------------------------------------------------
//在程序关闭时，关闭4个子窗口
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
//通用的OnMouseMove事件
void __fastcall TForm1::AllFormMouseMove(TObject *Sender, TShiftState Shift,
    int X, int Y)
{
//转换信息成窗口型态
TForm *form = dynamic_cast<TForm *>(Sender);
//若传入的窗口handle相异于键盘焦点，焦点即跳至form窗口上
if(::GetFocus() != (HWND)form->Handle)
   {
   ::SetFocus(form->Handle);//设置form为焦点
   ::BringWindowToTop(form->Handle);//将窗口带至最前面
   Caption = "现在"+form->Caption+" 取得焦点";
   }
}
//---------------------------------------------------------------------------

