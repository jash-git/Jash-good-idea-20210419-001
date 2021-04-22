//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main_s.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMain_sForm *Main_sForm;
//---------------------------------------------------------------------------
__fastcall TMain_sForm::TMain_sForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMain_sForm::Property1Click(TObject *Sender)
{
   int i=0;
   Memo1->Lines->Clear();
   while (_environ[i])
   {
      AnsiString path;
      path=AnsiString(i)+" : "+ _environ[i++];
      Memo1->Lines->Add(path);
   }
}
//---------------------------------------------------------------------------

SignalImpl::SignalImpl(const char *object_name):
        _sk_Signal(object_name)                 
{                                   
}

void SignalImpl::GetSignal(CORBA::Long _n, CORBA::Long _fs,
  SignalType& _output)
{
    char *ptr;
   AnsiString s;
   s="Number:"+AnsiString(_n)+",Frequency:"+AnsiString(_fs)+
      FormatDateTime(" yyyy'/'m'/'d h':'m':'s''",Now())+
      "  Reply from:";
   ptr=getenv("ComputerName");
   s+=ptr;
   Main_sForm->Memo1->Lines->Add(s);

   _output.length(_n);
   for(CORBA::Long i=0;i<_n;i++)
     _output[i]=10*sin(2*3.1415926*64*i/_fs)+random(100)/10-5;
}

