//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-----ȡ���Ӵ��ڵı�׼callback����------------------------------------------
BOOL CALLBACK EnumChildProc(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1��������
Memo1->Clear();
//��Ѱ�˴����µ��Ӵ��ڼ�����handle
::EnumChildWindows(
      Handle,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
}
//---------------------------------------------------------------------------
//�����д�һ���Ӵ��ڶ�ɨ���Ϊֹ
BOOL CALLBACK EnumChildProc(HWND HWin, LPARAM)
{
char className[256], WinText[256];
//ȡ���ִ���handle���������
::GetClassName(HWin, className, sizeof(className));
//ȡ���ִ��ڵı�������or�ں�����
::GetWindowText(HWin, WinText, sizeof(WinText));
//��Memo1��ʾ����
Form1->Memo1->Lines->Add("���"+AnsiString(className));
Form1->Memo1->Lines->Add("���ݣ�"+AnsiString(WinText));
Form1->Memo1->Lines->Add("--------------------");
//ִ��ɨ������
return TRUE;
}
//---------------------------------------------------------------------------
