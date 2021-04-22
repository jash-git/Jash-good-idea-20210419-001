//---------------------------------------------------------------------------
//目的：赋予所有Edit组件相同事件，判断及接收由 ListBox1 拖曳来的文字数据
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
{//将所有TEdit组件设置相同拖曳事件
for(int i=0; i < ComponentCount; i++)
   if(Components[i]->ClassNameIs("TEdit"))
      {
      TEdit *Edit = (TEdit *)Components[i];
      Edit->OnDragDrop = AllDragDrop;
      Edit->OnDragOver = AllDragOver;
      }
}
//---------------------------------------------------------------------------
//检测鼠标所在的ListBox项目文字是否在拖曳中
void __fastcall TForm1::ListBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (::DragDetect(ListBox1->Handle, Point(X, Y)))
     ListBox1->BeginDrag(false);
}
//---------------------------------------------------------------------------
//Edit共同的OnDragOver事件
void __fastcall TForm1::AllDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{//确定由ListBox1拖曳来的数据
Accept = (bool)dynamic_cast<TListBox *>(Source);
}
//---------------------------------------------------------------------------
//Edit共同的OnDragDrop事件
void __fastcall TForm1::AllDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{//接收由ListBox1拖曳来的数据
TEdit *edit = dynamic_cast<TEdit *>(Sender);
if (edit)
    {
    edit->Text = ListBox1->Items->Strings[ListBox1->ItemIndex];
    int i = ListBox1->ItemIndex;
    edit->Color = (TColor)RGB(i*60,255,255-i*30);
    }
}
//---------------------------------------------------------------------------
