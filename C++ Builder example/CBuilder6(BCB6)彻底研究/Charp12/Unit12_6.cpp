//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit12_6.h"
#include "Project12_5_TLB.h"
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
  DCOMConnection1->Connected=true;
  ClientDataSet1->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DCOMConnection1Login(TObject *Sender,
      AnsiString Username, AnsiString Password)
{
  ITest125ServerDisp srvr;
  Variant Ret;

  srvr.Bind(DCOMConnection1->GetServer());
  srvr.Login(WideString(Username),WideString(Password),Ret);
  if ((bool)Ret==false) {
    ShowMessage("使用者名称或密码错误, 请重新输入 !");
    DCOMConnection1->Connected=false;
  }
}
//---------------------------------------------------------------------------

