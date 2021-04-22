//---------------------------------------------------------------------------
//目的：所有子窗口以拼图方式或依序排列方式重组于母窗口指定范围中
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
//在程序显示时，创造4个子窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = this;
   form->Name = "Child_" + AnsiString(i);
   form->Width = 150; form->Height = 40;
   form->Top = i*40+ToolBar1->Height; form->Left = i*15;
   form->Color = (TColor)RGB(255,i*50,255-i*50);
   form->Show();
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
{
//取得Form1中间区域范围
RECT sr = {0,ToolBar1->Height,
           ClientWidth,
           ClientHeight-StaticText1->Height};
//以拼图方式重组子窗口
if(Button1->Default)
   ::TileWindows(Handle,
                 MDITILE_VERTICAL,//排除具有横向滚动条的子窗口
                 &sr,
                 NULL,//若为NULL，则为所有子窗口数目
                 NULL //若为NULL，则指向所有子窗口handle数组
                 );
else//以标题列依序排列方式重组子窗口
   ::CascadeWindows(Handle,
                    MDITILE_SKIPDISABLED,//填入此惟一旗标
                    &sr,
                    NULL,//若为NULL，则为所有子窗口数目
                    NULL //若为NULL，则指向所有子窗口handle数组
                    );
//切换布尔值
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

