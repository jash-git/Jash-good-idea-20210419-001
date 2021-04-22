//---------------------------------------------------------------------------
//目的：2个多字符串对象，可相互拖曳至对方栏中成新建项目文字
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
//将所有TListBox组件设置相同事件
for(int i=0; i < ComponentCount; i++)
   if(Components[i]->ClassNameIs("TListBox"))
      {
      TListBox *ListBox = (TListBox *)Components[i];
      ListBox->OnMouseDown = AllMouseDown;
      ListBox->OnDragDrop = AllDragDrop;
      ListBox->OnDragOver = AllDragOver;
      }
}
//---------------------------------------------------------------------------
//ListBox共同的OnMouseDown事件
void __fastcall TForm1::AllMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//将Sender试着转换成TListBox对象
TListBox *LBox = dynamic_cast<TListBox *>(Sender);
if(LBox)//若确定鼠标单击位置是TListBox对象，则执行之
   if (::DragDetect(LBox->Handle, Point(X, Y)))
       {
       const int drag_index =
                  LBox->ItemAtPos(Point(X, Y), true);
       LBox->Tag = drag_index;
       if (drag_index != -1)
          {
          LBox->BeginDrag(false, 1);
          }
       }
}
//---------------------------------------------------------------------------
//ListBox共同的OnDragOver事件
void __fastcall TForm1::AllDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
//确定由ListBox拖曳来的数据
Accept = (bool)dynamic_cast<TListBox *>(Source);
}
//---------------------------------------------------------------------------
//ListBox共同的OnDragDrop事件
void __fastcall TForm1::AllDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{//动态取得送出数据的ListBox
TListBox *LBox1 = dynamic_cast<TListBox *>(Source);
//动态取得接收数据的ListBox
TListBox *LBox2 = dynamic_cast<TListBox *>(Sender);
//确认送出数据的ListBox是存在的，
//则在接收ListBox中插入拖曳字符串项目
if(Source == LBox1 && LBox1->Tag != -1)
   {
   const int drop_index =
            LBox2->ItemAtPos(Point(X, Y), true);
   LBox2->Items->Insert(
            drop_index,
            LBox1->Items->Strings[LBox1->Tag]
            );
   }
}
//---------------------------------------------------------------------------
