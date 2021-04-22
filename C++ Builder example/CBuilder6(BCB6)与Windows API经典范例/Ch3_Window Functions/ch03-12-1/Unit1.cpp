//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//- 2��ȡ���Ӵ��ڵı�׼callback����------------------------------------------
bool CALLBACK EnumProc(HWND, LPARAM);
bool CALLBACK EnumChildProc(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//©��״���
Screen->Cursor = crHourGlass;
//�������������ǰ������ס���»���
::LockWindowUpdate(Memo1->Handle);
//ɾ��Memo1�������֦r
Memo1->Clear();
//��һ��Ѱ�������д���handle
::EnumWindows(
    reinterpret_cast <WNDENUMPROC> (EnumProc),
    reinterpret_cast <LPARAM> (Memo1)
  );
//������������ס�Ĵ��ڸ���
::LockWindowUpdate(0);
//���ָ�Ĭ��ֵ
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
//����ɨ�����ڴ�����Ϣ��������ɨ���һ���Ӵ���
bool CALLBACK EnumProc(HWND HWin, LPARAM MemoAddress)
{
//���Խ�LPARAMת����Memo������̬
TMemo* Memo = reinterpret_cast <TMemo*> (MemoAddress);
//ȡ�ô�����Ϣ��������һ����ʾ
String Line = "\r\n";
//ȡ���ִ���handle���������
char Buffer[128];
if(::GetClassName(HWin, Buffer, sizeof(Buffer)))
    Line += Buffer;
//ȡ���ִ��ڵı�������or�ں�����
if(::GetWindowText(HWin, Buffer, sizeof(Buffer)))
    Line += (" (" + String(Buffer) + ")");
//��Memo1��ʾ����
Memo->Lines->Add(Line);
//����Ѱ�˴����µ��Ӵ��ڼ�����handle
::EnumChildWindows(
    HWin,
    reinterpret_cast <WNDENUMPROC> (EnumChildProc),
    MemoAddress
    );
//������ֵ����ִ֪���´�handleɨ��
return true;
}
//---------------------------------------------------------------------------
//���ô�ɨ���Ӵ��ڵ����Լ��������д�һ���Ӵ��ڶ�ɨ���Ϊֹ
bool CALLBACK EnumChildProc(HWND HWin, LPARAM MemoAddress)
{
//�̶���ַ�ı��������ƴ��Ӵ��ڽײ�λ��
static int Nesting = 0;
++Nesting;
//ȡ�����ڴ��Ӵ��ڵ��������
char NameBuffer[128];
if(::GetClassName(HWin, NameBuffer, sizeof(NameBuffer)))
   {
   TMemo* Memo = reinterpret_cast <TMemo*> (MemoAddress);
   String NextLine;
   for(int i = 0; i < Nesting; ++i)
      NextLine += "-\t";
   NextLine += NameBuffer;
   Memo->Lines->Add(NextLine);
   }
//�����Լ���ִ���ٴ�һ����Ӵ���ɨ�裬
//ֱ��û�д�һ���Ӵ���Ϊֹ
::EnumChildWindows(
    HWin,
    reinterpret_cast <WNDENUMPROC> (EnumChildProc),
    MemoAddress
    );
//�������Ӵ���
--Nesting;
//������ֵ����ִ֪���´�handleɨ��
return true;
}
//---------------------------------------------------------------------------

