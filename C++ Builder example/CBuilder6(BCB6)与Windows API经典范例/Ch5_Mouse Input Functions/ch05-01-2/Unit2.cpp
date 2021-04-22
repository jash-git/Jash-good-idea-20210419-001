//---------------------------------------------------------------------------
//Ŀ�ģ�2�����ַ������󣬿��໥��ҷ���Է����г��½���Ŀ����
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
//������TListBox���������ͬ�¼�
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
//ListBox��ͬ��OnMouseDown�¼�
void __fastcall TForm1::AllMouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//��Sender����ת����TListBox����
TListBox *LBox = dynamic_cast<TListBox *>(Sender);
if(LBox)//��ȷ����굥��λ����TListBox������ִ��֮
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
//ListBox��ͬ��OnDragOver�¼�
void __fastcall TForm1::AllDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{
//ȷ����ListBox��ҷ��������
Accept = (bool)dynamic_cast<TListBox *>(Source);
}
//---------------------------------------------------------------------------
//ListBox��ͬ��OnDragDrop�¼�
void __fastcall TForm1::AllDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{//��̬ȡ���ͳ����ݵ�ListBox
TListBox *LBox1 = dynamic_cast<TListBox *>(Source);
//��̬ȡ�ý������ݵ�ListBox
TListBox *LBox2 = dynamic_cast<TListBox *>(Sender);
//ȷ���ͳ����ݵ�ListBox�Ǵ��ڵģ��A
//���ڽ���ListBox�в�����ҷ�ַ�����Ŀ
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
