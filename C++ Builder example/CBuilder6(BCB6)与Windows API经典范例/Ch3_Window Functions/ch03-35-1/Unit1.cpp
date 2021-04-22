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
{//默认Form1为母窗口
FormStyle = fsMDIForm;
}
//---------------------------------------------------------------------------
//在程序显示时，建立4个子窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Form1;
   form->FormStyle = fsMDIChild;
   form->Name = "Child_" + AnsiString(i);
   form->Width = 150; form->Height = 50;
   form->Top = i*50; form->Left = i*15;
   }
}
//---------------------------------------------------------------------------
//运用按钮切换隐藏或显示4个子窗口
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0;i<4;i++)
   {
   AnsiString name = "Child_" + AnsiString(i);
   HWND hwnd = ::FindWindow(NULL, name.c_str());
   ::DestroyWindow(hwnd);
   }
}
//---------------------------------------------------------------------------
//先取得Form1下的第一个子窗口
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char cls[256];
//先取得Form1下的第一个子窗口
HWND hwnd = ::GetWindow(Handle, GW_CHILD);
//持续找寻子窗口，进行显示或隐藏功能
do{ //取得子窗口类型名称，判断是否进行
  ::GetClassName(hwnd, cls, 255);
  if (! strcmp(cls, "MDIClient"))
   {//三元运算，判断子窗口是否为可视状态
   ::ShowWindow(hwnd, ::IsWindowVisible(hwnd) ? SW_HIDE : SW_SHOW);
   (Caption=="隐藏子窗口")?(Caption="显示子窗口"):(Caption="隐藏子窗口");
   }
   //再取得下一子窗口handle，进行判断
   hwnd = ::GetWindow(hwnd, GW_HWNDNEXT);
   } while(hwnd);
}
//---------------------------------------------------------------------------

