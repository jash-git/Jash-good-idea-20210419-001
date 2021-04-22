//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "UThread.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button1Click(TObject *Sender)
{
    ComputeTask();    
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::Button2Click(TObject *Sender)
{
     TComputeThread *ct=new  TComputeThread(true);
     ct->FreeOnTerminate=true;
     ct->Priority=tpLower;
     ct->Resume();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::ComputeTask()
{
        for(int i=0;i<100000;i++)
           {
            Canvas->Lock();
            Canvas->TextOut(20,20,i);
            Canvas->Unlock();
            Repaint();
           }
}
//---------------------------------------------------------------------------
