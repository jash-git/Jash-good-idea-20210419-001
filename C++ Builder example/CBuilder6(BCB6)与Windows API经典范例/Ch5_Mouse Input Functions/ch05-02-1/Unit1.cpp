//---------------------------------------------------------------------------
//目的：鼠标移动下的MaskEdit对象取得焦点，若鼠标不在MaskEdit范围中，
//则从现在MaskEdit对象释放焦点，使得任一MaskEdit皆无焦点
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
{//将所有TListBox组件设置相同事件
for(int i=0; i < ComponentCount; i++)
   if(Components[i]->ClassNameIs("TMaskEdit"))
      {
      TMaskEdit *MaskEdit = (TMaskEdit *)Components[i];
      MaskEdit->OnMouseMove = AllMouseMove;
      }
}
//---------------------------------------------------------------------------
//MaskEdit共通的OnMouseMove事件
void __fastcall TForm1::AllMouseMove(TObject *Sender,
      TShiftState Shift, int X, int Y)
{//从信息转换回TMaskEdit组件
TMaskEdit *MaskEdit = dynamic_cast<TMaskEdit *>(Sender);
if(MaskEdit)
  {//若鼠标移动下的MaskEdit与取得焦点的对象不同，
  if(::GetCapture() != MaskEdit->Handle)
    {//则由鼠标移动下的MaskEdit取得焦点
    ::SetCapture(MaskEdit->Handle);
    ActiveControl = MaskEdit;
    }

  RECT R = static_cast<RECT>(MaskEdit->ClientRect);
  POINT P = Point(X, Y);
  //若鼠标不在MaskEdit范围中，则从现在对象释放焦点，
  //使得任一MaskEdit皆无焦点
  if(!::PtInRect(&R, P))
    {
    ::ReleaseCapture();
    ::SetFocus(NULL);
    }
  }
}
//---------------------------------------------------------------------------
