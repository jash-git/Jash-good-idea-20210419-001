//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit3_3.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
RichEdit1->SelAttributes->Size+=2;	
}
//---------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
RichEdit1->SelAttributes->Size-=2;	
}
//---------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
RichEdit1->SelAttributes->Color=clRed;
}
//---------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
RichEdit1->PlainText=false;
RichEdit1->Lines->SaveToFile(Edit1->Text);
}
//---------------------------------------------------------------------