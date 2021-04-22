//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "Unit7_3.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
      TMemoryStatus vm;

      vm.dwLength=sizeof(TMemoryStatus);
      GlobalMemoryStatus(&vm);
      Label8->Caption=IntToStr(vm.dwMemoryLoad)+" %";
      Label9->Caption=IntToStr(vm.dwTotalPhys/1024)+" KB";
      Label10->Caption=IntToStr(vm.dwAvailPhys/1024)+" KB";
      Label11->Caption=IntToStr(vm.dwTotalPageFile/1024)+" KB";
      Label12->Caption=IntToStr(vm.dwAvailPageFile/1024)+" KB";
      Label13->Caption=IntToStr(vm.dwTotalVirtual/1024)+" KB";
      Label14->Caption=IntToStr(vm.dwAvailVirtual/1024)+" KB";
}
//---------------------------------------------------------------------------
