//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_6.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
    String temp;

    switch (Button) {
    	case mbLeft:   temp="���"; break;
        case mbMiddle: temp="�м�"; break;
        case mbRight:  temp="�Ҽ�"; break;
    }
    Label10->Caption="�����������"+temp+"��";
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Panel1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
    Label7->Caption="("+IntToStr(X)+","+IntToStr(Y)+")";
    Label10->Caption="�������ƶ���꣡";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
    String temp;

    switch (Button) {
    	case mbLeft:   temp="���"; break;
        case mbMiddle: temp="�м�"; break;
        case mbRight:  temp="�Ҽ�"; break;
    }
    Label10->Caption="��ղŷſ����"+temp+"��";
}
//---------------------------------------------------------------------------
void __fastcall TForm2::FormCreate(TObject *Sender)
{
    Label6->Caption="("+IntToStr(Panel1->Width)+","+IntToStr(Panel1->Height)+")";
}
//---------------------------------------------------------------------------

