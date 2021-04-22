//---------------------------------------------------------------------------
//目的：按下Ctrl+Tab 键，即可依次调用子窗口取得焦点，并显示到最前面
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//默认快捷键信息常数值---------------------------------------------------------
const int ID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//让Form1美观，突显子窗口
Color = (TColor)RGB(255,255,200);
//Form1的Tag属性，用来切换子窗口的变量
Tag = 1;
//将Form1型态变成可拥有子窗口的母窗口
FormStyle = fsMDIForm;
//给这个线程登录快捷键
//按下Ctrl+Tab 键，即可调用子窗口取得焦点，并显示到最前面
::RegisterHotKey(Handle, ID, MOD_CONTROL, VK_TAB);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//动态建立出四个子窗口
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Form1;
   form->FormStyle = fsMDIChild;
   form->Name = "form_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//释放此线程登录的快捷键
::UnregisterHotKey(Handle, ID);
}
//---------------------------------------------------------------------------
//捕捉自定义快捷键信息
void __fastcall TForm1::HotKeys(TMessage &Msg)
{
//将信息分流到其他处理函数
TForm::Dispatch(&Msg);
//寻找指定名称的子窗口
char name[6];
Form1->Tag++;
int num = Form1->Tag%4;
sprintf(name,"form_%i",num);//#include <stdio.h>
//若此子窗口在后面，即提到最前面
for(int i=0;i<Form1->ComponentCount;i++)
  if(Components[i]->Name == name)
    {
    //将TComponent转成TForm型态
    TForm *form = (TForm *)Components[i];
    ::BringWindowToTop(form->Handle);
    //若此程序是缩小化状态，则恢复原来状态
    if (::IsIconic(form->Handle))
       ::ShowWindow(form->Handle, SW_RESTORE);
    }
}
//---------------------------------------------------------------------------


