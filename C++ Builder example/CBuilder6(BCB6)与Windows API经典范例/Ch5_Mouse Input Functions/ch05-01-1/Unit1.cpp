//---------------------------------------------------------------------------
//Ŀ�ģ���������Edit�����ͬ�¼����жϼ������� ListBox1 ��ҷ�����������ݮ�
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
{//������TEdit���������ͬ��ҷ�¼�
for(int i=0; i < ComponentCount; i++)
   if(Components[i]->ClassNameIs("TEdit"))
      {
      TEdit *Edit = (TEdit *)Components[i];
      Edit->OnDragDrop = AllDragDrop;
      Edit->OnDragOver = AllDragOver;
      }
}
//---------------------------------------------------------------------------
//���������ڵ�ListBox��Ŀ�����Ƿ�����ҷ��
void __fastcall TForm1::ListBox1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if (::DragDetect(ListBox1->Handle, Point(X, Y)))
     ListBox1->BeginDrag(false);
}
//---------------------------------------------------------------------------
//Edit��ͬ��OnDragOver�¼�
void __fastcall TForm1::AllDragOver(TObject *Sender, TObject *Source,
      int X, int Y, TDragState State, bool &Accept)
{//ȷ����ListBox1��ҷ��������
Accept = (bool)dynamic_cast<TListBox *>(Source);
}
//---------------------------------------------------------------------------
//Edit��ͬ��OnDragDrop�¼�
void __fastcall TForm1::AllDragDrop(TObject *Sender, TObject *Source,
      int X, int Y)
{//������ListBox1��ҷ��������
TEdit *edit = dynamic_cast<TEdit *>(Sender);
if (edit)
    {
    edit->Text = ListBox1->Items->Strings[ListBox1->ItemIndex];
    int i = ListBox1->ItemIndex;
    edit->Color = (TColor)RGB(i*60,255,255-i*30);
    }
}
//---------------------------------------------------------------------------
