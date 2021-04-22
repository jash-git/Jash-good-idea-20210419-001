//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "UThread.h"
#include "Main.h"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall Unit2::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------

__fastcall TComputeThread::TComputeThread(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TComputeThread::Execute()
{
        //---- Place thread code here ----
    MainForm->ComputeTask();
}
//---------------------------------------------------------------------------
 