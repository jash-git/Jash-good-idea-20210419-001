//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_c.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_cForm *Main_cForm;
//---------------------------------------------------------------------------
__fastcall TMain_cForm::TMain_cForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain_cForm::Button1Click(TObject *Sender)
{
   try
  {
     PortableServer::ObjectId_var managerId = PortableServer::string_to_ObjectId("SignalManager");
     Signal_var tmp = Signal::_bind("/signal_poa", managerId);

    CORBA::Long n=NumberBox->Text.ToIntDef(1024);
    int fs=FreqBox->Text.ToIntDef(1024);
    SignalType out;
    Series1->Clear();
    tmp->GetSignal(n,fs,out);
    DrawChart(Chart1,out,n,fs);
  }
  catch(CORBA::Exception &e)
  {
    ShowMessage(e._name());
  }
}
//---------------------------------------------------------------------------

void __fastcall TMain_cForm::DrawChart(TChart *chart,SignalType signal,int N,float fs)
{
  float scale=1.5;
  float max=0.0;

  for(int i=0;i<N;i++)
    if(fabs(signal[i])>max) max=fabs(signal[i]);

    chart->LeftAxis->Automatic=false;
    chart->LeftAxis->Minimum=-scale*max;
    chart->LeftAxis->Maximum=scale*max;
    chart->BottomAxis->Automatic=false;
    chart->BottomAxis->Minimum=0.0;
    chart->BottomAxis->Maximum=N;
    chart->Series[0]->Clear();
    for(int i=0;i<N;i++)
      chart->Series[0]->AddXY(i,signal[i],"",clTeeColor);
}
//----------------------------------------------------------------------------
