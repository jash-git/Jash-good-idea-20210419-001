//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ĭ�ϰ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
//Ԥ�ȹرռ�ʱ��
Timer1->Enabled = false;
Timer1->Interval = 100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��������C:\tempĿ¼�е��ļ��춯
hChange = ::FindFirstChangeNotification("C:\\temp",
                                        true,//������Ŀ¼
                                        FILE_NOTIFY_CHANGE_FILE_NAME);
//����Ŀ¼�����ڦs�b
if (hChange == INVALID_HANDLE_VALUE)
   {
   ListBox1->Items->Add("C:\tempĿ¼������or�޷��򿪣�");
   //�ͳ��ر���Ϣ����������
   Application->Terminate();
   }
else
   {
   //�л���ť״̬
   Button1->Enabled = false;
   Button2->Enabled = true;
   //��¼����ʱ��
   struct time st;
   gettime(&st);
   ListBox1->Items->Add("��������C:\\tempĿ¼�ļ��춯: " +
                        AnsiString(st.ti_hour) + "_" +
                        AnsiString(st.ti_min) + "_" +
                        AnsiString(st.ti_sec)
                        );

   //������ʱ��ʱ�������ļ��춯ֵ�ȹ���
   counter = 0;
   //������ʱ��
   Timer1->Enabled = true;
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//�ͷ�Ŀ¼handle
::FindCloseChangeNotification(hChange);
//�л���ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
//Ĭ�ϼ�ʱ��״̬
Timer1->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
//�����߳������ı�ʱ��������Ϣ
DWORD rc = ::WaitForSingleObject(hChange, 0);
//
if (rc == WAIT_OBJECT_0)
   {
   ListBox1->Items->Add( "���� " + AnsiString(++counter) + " ���ļ�����or����orɾ��");
   //ɾ������֪ͨ���ȴ���һ����֪ͨ
   ::FindNextChangeNotification(hChange);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//Ԥ��δ�ͷ�Ŀ¼handle
::FindCloseChangeNotification(hChange);
}
//---------------------------------------------------------------------------
 