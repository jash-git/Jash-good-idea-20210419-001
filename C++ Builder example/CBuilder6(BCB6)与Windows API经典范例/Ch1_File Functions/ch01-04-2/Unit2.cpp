//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��������Ŀ
ListBox1->Clear();
//Ĭ�ϼ��COM�˿ڵķ���ֵ��
HANDLE h = INVALID_HANDLE_VALUE;
//��һ����COM �˿ڼ��
for(int i=1;i<=32;i++)
   {
   AnsiString comname = "\\\\.\\COM" + String(i);
   //��COM�˿ڣ������ؼ��ֵ
   h = ::CreateFile( comname.c_str(),
                     GENERIC_READ | GENERIC_WRITE,
                     0,
                     0,
                     OPEN_EXISTING,
                     FILE_ATTRIBUTE_NORMAL,
                     0);
   //���޷���ָ��COM �˿�
   if (h == INVALID_HANDLE_VALUE)
      {
      //ȡ�ô�����Ϣ
      DWORD err = ::GetLastError();
      //�� err Ϊ 2 ������COM�˿���δ��װ
      if (err!=2)
         {
         ListBox1->Items->Add("COM" + AnsiString(i) +
                              " ��δʹ�ã�������ϢΪ (" +
                              AnsiString((int)err) + ")");
         }
      }
   else
      {
      ListBox1->Items->Add("COM" + AnsiString(i) + " ����ʹ���У�");
      }
   //�ͷ�handle
   ::CloseHandle(h);
   }

}
//---------------------------------------------------------------------------
