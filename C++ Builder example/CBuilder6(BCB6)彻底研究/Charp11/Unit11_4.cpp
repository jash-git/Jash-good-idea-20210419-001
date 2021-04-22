//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit11_4.h"
#include "Project11_3_TLB.h"
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

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  DCOMConnection1->Connected=true;
  cdsCustomer->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ToolButton5Click(TObject *Sender)
{
  OleVariant CustVar;


  cdsCustomer->CheckBrowseMode();


  if(cdsCustomer->ChangeCount > 0)
    CustVar = cdsCustomer->Delta;
  else
    CustVar.ChangeType(VT_NULL);

  try
  {
    ITest113ServerDisp srvr;
    srvr.Bind(LPDISPATCH(DCOMConnection1->AppServer));
    srvr.ApplyUpdates(reinterpret_cast<VARIANTOBJ*>(&CustVar));
    ShowMessage("成功写入数据库!");
  }
  catch (Exception &exception)
  {
    Application->ShowException(&exception);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ToolButton6Click(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------

