//---------------------------------------------------------------------------
//目的：单击按钮，将所有缩小化子窗口以拼图方式重新排列于母窗口左下角
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
//在程序显现时，建立4个不同位置的缩小状态子窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{//动态建立四个子窗口
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Panel1;
   form->Name = "form_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   form->Show();
   form->WindowState = wsMinimized;
   //移动缩小状态子窗口的位置
   ::MoveWindow(form->Handle,i*40,i*60,
                form->Width, form->Height,
                false);
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{//将所有缩小化子窗口以拼图方式重新排列
if(::ArrangeIconicWindows(Panel1->Handle))
   ShowMessage("成功重新排列缩小化窗口");
}
//---------------------------------------------------------------------------

