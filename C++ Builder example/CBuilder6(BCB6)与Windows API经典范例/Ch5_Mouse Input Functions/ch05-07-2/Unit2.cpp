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
//预先将现在双击间隔时间保存
Tag = ::GetDoubleClickTime();
//显示现在双击间隔时间
StaticText2->Caption = "鼠标双击间隔为" + AnsiString(Tag)+ " 毫秒";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//若关闭此程序时，恢复双击原有速度
::SetDoubleClickTime(Tag);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDblClick(TObject *Sender)
{
//将双击间隔时间逐渐减少
int gtime = ::GetDoubleClickTime() - 20;
//重设双击间隔时间
::SetDoubleClickTime(gtime);
StaticText2->Caption = "鼠标双击间隔为" + AnsiString(gtime)+ " 毫秒";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
//冻结时间至越过鼠标引发双击事件的时间
//区隔OnClick事件与OnDblClick事件
::Sleep(::GetDoubleClickTime()+1);

StaticText2->Caption = "你的双击动作慢了喔！再快一点！";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//恢复双击原有速度
::SetDoubleClickTime(Tag);
StaticText2->Caption = "鼠标双击间隔为" + AnsiString(Tag)+ " 毫秒";
}
//---------------------------------------------------------------------------
