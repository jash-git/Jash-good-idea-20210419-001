#include <vcl.h>
#pragma hdrstop

#include "Unit11_6.h"
#include "Project11_5_TLB.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
ITest115ServerDisp AdhcServ;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{

  DCOMConnection1->Connected = true;

  Variant DBNames;
  AdhcServ.Bind(DCOMConnection1->GetServer());
  DatabaseName->Items->Text=AnsiString(AdhcServ->GetDatabaseNames());


  DatabaseNameClick(this);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RunButtonClick(TObject *Sender)
{

  ClientDataSet->Close();


  ClientDataSet->CommandText=SQL->Lines->Text;


  ClientDataSet->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
  if (AdhcServ.IsBound())
    AdhcServ.Unbind();
  DCOMConnection1->Connected = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DatabaseNameClick(TObject *Sender)
{
  AnsiString Password,st;


  if(DatabaseName->Text != NULL)
  {
    ClientDataSet->Close();
    st=AdhcServ->SetDatabaseName(WideString(DatabaseName->Text),
                                 WideString(Password));

    if (st=="N")
    {
      if(InputQuery("Enter password", "Enter password", Password))
      {
        st=AdhcServ->SetDatabaseName(WideString(DatabaseName->Text),
                                     WideString(Password));
        if (st=="Y") ShowMessage("登入成功！");
          else ShowMessage("密码错误，登入失败！");
      }
    }
  }
}
//---------------------------------------------------------------------------


