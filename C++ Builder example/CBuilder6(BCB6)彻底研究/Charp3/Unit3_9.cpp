//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3_9.h"
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


void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
   int I,J;

   // 假如按下的是Enter鍵
   if (Key==13) {

      J=1;

      for ( I = 0; I < Form1->ControlCount; I++) {
         TWinControl *Temp = dynamic_cast<TWinControl *>(Form1->Controls[I]);
         if (Temp)
           if (Temp->Focused()) J=I+1;
      }
      if (J==Form1->ControlCount) J=J-1;
      TWinControl *Temp = dynamic_cast<TWinControl *>(Form1->Controls[J]);

      Temp->SetFocus();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{

   Form1->KeyPreview=True;

}
//---------------------------------------------------------------------------

