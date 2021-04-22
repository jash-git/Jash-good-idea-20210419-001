//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit2a.h"
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
//建立第二个窗口，以供检测
void __fastcall TForm1::FormShow(TObject *Sender)
{
form = new TForm(this);
form->Caption = "我是第二个窗口！";
form->Width = 250; form->Height = 100;
form->Top = Top+Height; form->Left = Left+30;
form->Color = (TColor)RGB(255,210,110);
form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete form;
}
//---------------------------------------------------------------------------
//将焦点转移到第二个窗口上，并显现自定义字符串
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//取得次一窗口handle，并转移焦点
HWND hwnd = ::GetNextWindow(Handle,GW_HWNDNEXT);
::SetFocus(hwnd);
//在新取得焦点窗口上，绘制自定义字符串
RECT r = {30,30,250,250};
::DrawText(::GetDC(hwnd),"我得到焦点！",12,&r,DT_SINGLELINE);
}
//---------------------------------------------------------------------------

