//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
TForm1 *Form1;
//ȡ���Ӵ��ڵ�callback����---------------------------------------------------
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1�������֦r
Memo1->Clear();
//��һ��Ѱ�������д���handle
::EnumWindows(
  reinterpret_cast <WNDENUMPROC> (EnumWindowsProc),
  reinterpret_cast <LPARAM> (Memo1)
  );
}
//---------------------------------------------------------------------------
//���ô�ɨ���Ӵ��ڵ����Լ��������д�һ���Ӵ��ڶ�ɨ���Ϊֹ
BOOL CALLBACK EnumWindowsProc(HWND hwnd, LPARAM lParam)
{
//ȡ���ִ��ڵ��ں�����
char buf[256];
::GetWindowText(hwnd, buf, sizeof(buf));

if(TMemo* memo = reinterpret_cast <TMemo*> (lParam))
if (strlen(buf) > 0)
      memo->Lines->Add(buf);
//������ֵ����ִ֪���´�handleɨ��    
return TRUE;
}
//---------------------------------------------------------------------------

