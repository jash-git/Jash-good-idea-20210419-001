//---------------------------------------------------------------------------
#include <vcl.h>
#include <fcntl.h>
#include <io.h>
#include <sys\stat.h>
#include <stdlib.h>
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

// 把此函数 export 出来
extern "C" __declspec(dllexport) int __stdcall PCopyFile(char *sour, char*targ);

int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
    return 1;
}
//---------------------------------------------------------------------------

// 功能为复制文件的函数
int __stdcall PCopyFile(char *sour, char*targ)
{
   int in, out, buf_len;
   char *buf;

   buf =(char *) malloc(1026);
   if ((in = open(sour, O_RDONLY|O_BINARY, S_IREAD)) == -1)
   {
      ShowMessage("无法打开来源文件!!");
      return 1;
   }

   if ((out = open(targ, O_CREAT|O_BINARY|O_WRONLY, S_IWRITE)) == -1)
   {
      ShowMessage("无法打开目标文件!!");
      return 1;
   }

   while (!eof(in)) {
      buf_len=read(in, buf, 1024);
      write(out, buf, buf_len);
   }

   close(in);
   close(out);
   free(buf);
   return 0;
}
