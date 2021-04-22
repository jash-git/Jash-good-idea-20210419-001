//---------------------------------------------------------------------------
#include <stdio.h>
#include<stddef.h>
#include<process.h>
#include<conio.h>
//---------------------------------------------------------------------------
#pragma hdrstop
//---------------------------------------------------------------------------
#pragma argsused
//---------------------------------------------------------------------------
void  ThreadProc(void*);
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
    int i;
    unsigned  long  thread;
    for(i=1;i<5;i++)
    {
        thread=_beginthread(ThreadProc,4096,(void*)i);
        if((long)thread==-1)
        {
            printf("Error Creating  thread ");
        }
    }
    getchar();
    return 0;
}
//---------------------------------------------------------------------------
void  ThreadProc(void   *num)
{
   printf("第%d个线程已经运行，线程号%ld\n",(int)num,_threadid);
   _endthread();

}