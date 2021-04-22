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
//确定Form1为一般类型
FormStyle = fsNormal;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//动态建立5个彩色背景的窗口
for(int i=0;i<5;i++)
    {
    TForm *form = new TForm(Form1);
    form->Parent = Form1;
    form->FormStyle = fsNormal;
    form->Name = "form" + AnsiString(i+1);
    form->Width = 150; form->Height = 40;
    form->Top = ToolBar1->Height + 40*i;
    form->Left = 40*i;
    form->Color = (TColor)RGB(255-i*50,i*50,255);
    //若在新窗口上移动鼠标，引发Form1的OnMouseMove事件
    form->OnMouseMove = FormMouseMove;
    form->Show();
    //form2,form4设为失效状态
    if(i%2) form->Enabled = false;
    }
//若在其他组件上移动鼠标，引发Form1的OnMouseMove事件
StaticText1->OnMouseMove = FormMouseMove;
ToolBar1->OnMouseMove = FormMouseMove;
Button1->OnMouseMove = FormMouseMove;
Button2->OnMouseMove = FormMouseMove;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
char name[6];
//删除程序开始时建立的5个彩色窗口
for(int num=0;num<ComponentCount;num++)
   {
   sprintf(name,"form%i",(num+1));//#include <stdio.h>
   for(int i=0;i<ComponentCount;i++)
     if(Components[i]->Name == name)
       {
       delete (TForm *)Components[i];
       }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//取得鼠标位置
POINT pd;
GetCursorPos(&pd);
pd = ScreenToClient(pd);
char name[256], text[256];
//排除失效对象，由鼠标位置而取得Form1上对象handle
HWND h = ::ChildWindowFromPointEx(Handle, pd, CWP_SKIPDISABLED);
//由对象handle取得对象相关信息
::GetClassName(h,name,256);
::GetWindowText(h,text,256);
//实时显示对象信息
StaticText2->Caption = "类：" + AnsiString(name) +
                       ",内含文字："+AnsiString(text);
}
//---------------------------------------------------------------------------


