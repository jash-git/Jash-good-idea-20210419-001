//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
     double a,b;
     int i=0;
     try
     {
        a=StrToFloat(Edit1->Text);
        i++;
        b=StrToFloat(Edit2->Text);
        a=a*b;
        Label4->Caption=a;
      }
     catch(EConvertError &e)
     {
         if(i==0)
             ShowMessage("单价输入错误");
         else
             ShowMessage("数量输入错误");
     }
}
//---------------------------------------------------------------------------
