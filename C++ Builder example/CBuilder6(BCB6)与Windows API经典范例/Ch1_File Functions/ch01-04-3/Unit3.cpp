//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
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
//此范例可改为由网络准备时间校正现在系统时间
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除所有项目
ListBox1->Clear();

char *FileName = "settings";
//文件时间结果声明
FILETIME LastWriteFT, LastWriteLFT;
//系统时间结果声明
SYSTEMTIME LastWriteST;
//取得“设置”文件的handle
HANDLE setFile = ::CreateFile( FileName,
                               GENERIC_READ | GENERIC_WRITE,
                               FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL,
                               CREATE_ALWAYS,
                               NULL,
                               NULL );

if ( setFile != INVALID_HANDLE_VALUE )
    {
    //若成功取得上次打开文件的时间
    if (::GetFileTime( setFile,  NULL, NULL, &LastWriteFT))
       {
       //若成功将上次打开文件的时间转换为区域文件时间与系统时间
       if (::FileTimeToLocalFileTime(&LastWriteFT,&LastWriteLFT))
         if(::FileTimeToSystemTime(&LastWriteLFT,&LastWriteST))
            {
            //重设系统日期
            struct date sysdate = { (int)LastWriteST.wYear,
                                    (char)LastWriteST.wDay,
                                    (char)LastWriteST.wMonth };
            setdate(&sysdate);
            //重设系统时间
            struct  time systime = { (unsigned char)LastWriteST.wMinute,/* minutes */
                                     (unsigned char)LastWriteST.wHour, /* hours */
                                     //unsigned char ti_hund, /* hundredths of seconds */
                                     //unsigned char ti_sec  /* seconds */
                                   };

            settime(&systime);
            //在ListBox1中显示修改时间
            ListBox1->Items->Add("由上次打开<设置>文件时间重新校正系统时间");
            ListBox1->Items->Add("年:" + AnsiString((int)LastWriteST.wYear));
            ListBox1->Items->Add("月:" + AnsiString((int)LastWriteST.wMonth));
            ListBox1->Items->Add("日:" + AnsiString((int)LastWriteST.wDay));
            ListBox1->Items->Add("时:" + AnsiString((int)LastWriteST.wHour));
            ListBox1->Items->Add("分:" + AnsiString((int)LastWriteST.wMinute));
            }
       }
    //释放handle
    CloseHandle( setFile );
    }
}
//---------------------------------------------------------------------------
