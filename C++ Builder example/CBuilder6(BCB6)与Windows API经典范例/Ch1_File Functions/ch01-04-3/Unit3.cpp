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
//�˷����ɸ�Ϊ������׼��ʱ��У������ϵͳʱ��
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��������Ŀ
ListBox1->Clear();

char *FileName = "settings";
//�ļ�ʱ��������
FILETIME LastWriteFT, LastWriteLFT;
//ϵͳʱ��������
SYSTEMTIME LastWriteST;
//ȡ�á����á��ļ���handle
HANDLE setFile = ::CreateFile( FileName,
                               GENERIC_READ | GENERIC_WRITE,
                               FILE_SHARE_READ | FILE_SHARE_WRITE,
                               NULL,
                               CREATE_ALWAYS,
                               NULL,
                               NULL );

if ( setFile != INVALID_HANDLE_VALUE )
    {
    //���ɹ�ȡ���ϴδ��ļ���ʱ��
    if (::GetFileTime( setFile,  NULL, NULL, &LastWriteFT))
       {
       //���ɹ����ϴδ��ļ���ʱ��ת��Ϊ�����ļ�ʱ����ϵͳʱ��
       if (::FileTimeToLocalFileTime(&LastWriteFT,&LastWriteLFT))
         if(::FileTimeToSystemTime(&LastWriteLFT,&LastWriteST))
            {
            //����ϵͳ����
            struct date sysdate = { (int)LastWriteST.wYear,
                                    (char)LastWriteST.wDay,
                                    (char)LastWriteST.wMonth };
            setdate(&sysdate);
            //����ϵͳʱ��
            struct  time systime = { (unsigned char)LastWriteST.wMinute,/* minutes */
                                     (unsigned char)LastWriteST.wHour, /* hours */
                                     //unsigned char ti_hund, /* hundredths of seconds */
                                     //unsigned char ti_sec  /* seconds */
                                   };

            settime(&systime);
            //��ListBox1����ʾ�޸�ʱ��
            ListBox1->Items->Add("���ϴδ�<����>�ļ�ʱ������У��ϵͳʱ��");
            ListBox1->Items->Add("��:" + AnsiString((int)LastWriteST.wYear));
            ListBox1->Items->Add("��:" + AnsiString((int)LastWriteST.wMonth));
            ListBox1->Items->Add("��:" + AnsiString((int)LastWriteST.wDay));
            ListBox1->Items->Add("ʱ:" + AnsiString((int)LastWriteST.wHour));
            ListBox1->Items->Add("��:" + AnsiString((int)LastWriteST.wMinute));
            }
       }
    //�ͷ�handle
    CloseHandle( setFile );
    }
}
//---------------------------------------------------------------------------
