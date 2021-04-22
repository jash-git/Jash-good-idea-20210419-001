//---------------------------------------------------------------------------
#include <vcl.h>
#include <fcntl.h>
#include <io.h>
#include <sys\stat.h>
#include <stdlib.h>
#include "Unit7_6.h"
#pragma hdrstop
//---------------------------------------------------------------------------
//   Important note about DLL memory management when your DLL uses the
//   static version of the RunTime Library:
//
//   If your DLL exports any functions that pass String objects (or structs/
//   classes containing nested Strings) as parameter or function results,
//   you will need to add the library MEMMGR.LIB to both the DLL project and
//   any other projects that use the DLL.  You will also need to use MEMMGR.LIB
//   if any other projects which use the DLL will be perfomring new or delete
//   operations on any non-TObject-derived classes which are exported from the
//   DLL. Adding MEMMGR.LIB to your project will change the DLL and its calling
//   EXE's to use the BORLNDMM.DLL as their memory manager.  In these cases,
//   the file BORLNDMM.DLL should be deployed along with your DLL.
//
//   To avoid using BORLNDMM.DLL, pass string information using "char *" or
//   ShortString parameters.
//
//   If your DLL uses the dynamic version of the RTL, you do not need to
//   explicitly add MEMMGR.LIB as this will be done implicitly for you
//---------------------------------------------------------------------------

USEFORM("Unit7_6.cpp", Form1);
//---------------------------------------------------------------------------
extern "C" __declspec(dllexport) void __stdcall CustomerForm(char *st);

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------

void __stdcall CustomerForm(char *st)
{
  // 动态建立Form 对象
  Form1=new TForm1(NULL);

  // 把调用者传来的
  Form1->Caption=AnsiString(st);

  // 显示 Form 对象
  Form1->ShowModal();

  // 释放Form 对象
  delete Form1;
}
