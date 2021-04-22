//---------------------------------------------------------------------------
//目的：将指定窗口下的子窗口重新设置为同一大小及位置
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
//确定Form1为一般型态
FormStyle = fsNormal;
}
//---------------------------------------------------------------------------
//动态建立5个彩色背景的窗口
void __fastcall TForm1::FormShow(TObject *Sender)
{
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
    form->Show();
    }
}
//---------------------------------------------------------------------------
//删除程序开始时建立的5个彩色窗口
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//声明HWND数组
HWND *pHwnd = new HWND[5];
//设置RECT结构
RECT r = {40,40,250,150};
try
   {
   char name[5];
   //寻找指定名称的子窗口
   for(int num=0;num<5;num++)
   {
   sprintf(name,"form%i",num+1);//#include <stdio.h>
   //取得子窗口handle数组
   for(int i=0;i<ComponentCount;i++)
     if(Components[i]->Name == name)
       {
       //将TComponent转成TForm型态
       TForm *form = (TForm *)Components[i];
       pHwnd[num] = form->Handle;
       }
   }
   //将子窗口数组重新设置为同一大小&位置
   ::CascadeWindows(Handle, MDITILE_SKIPDISABLED,
                    &r, 5, pHwnd);
   }
catch (...)
   {
   delete [] pHwnd;
   }
delete [] pHwnd;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//取得桌面上所有程序数目
const int count = Screen->FormCount;
RECT r = {Screen->Width/5,Screen->Height/5,
          Screen->Width/5*4,Screen->Height/5*4};
//将桌面上所有程序皆重新设置为同一大小&位置
::CascadeWindows(NULL, MDITILE_SKIPDISABLED, &r, count, NULL);
}
//---------------------------------------------------------------------------



