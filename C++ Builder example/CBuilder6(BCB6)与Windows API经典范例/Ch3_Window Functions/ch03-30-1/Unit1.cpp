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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//��Ѱ<���±�>�Ƿ��
HWND hNpad = ::FindWindow(NULL, "δ���� - ���±�");
//��<���±�>�ڴ��У���������ǰ��
if(::ShowWindow(hNpad,SW_SHOWNORMAL))
   {
   ::BringWindowToTop(hNpad);
   }
else //��û�򿪣����<���±�>
   {
   //ȡ��WindowĿ¼λ��
   char WinDir[MAX_PATH];
   ::GetWindowsDirectory(WinDir, MAX_PATH);
   AnsiString sysdir = AnsiString(WinDir) + "\\Notepad.exe";
   //��<���±�>
   ::ShellExecute(NULL,"open",sysdir.c_str(),NULL,NULL,SW_SHOWNORMAL);
   //�ٴ��ҵ�<���±�>����
   hNpad = ::FindWindow(NULL, "δ���� - ���±�");
   }
//�����Զ��庯��
if(VaultWindowThreadID(hNpad))
  Memo1->Text = "����ڲ�ͬ�߳��г̼�Ĵ���ȡ�ý��㡣";
else
  Memo1->Text = "���ڴ�<���±�>����ִ�б�����";
}
//---------------------------------------------------------------------------
//�ڲ�ͬ�߳��г̼�Ĵ���ȡ�ý���
bool TForm1::VaultWindowThreadID(HWND hWnd)
{
bool Result;
DWORD fWinThreadID;
DWORD winThreadID;
//������Ĵ���handle��ͬ��������ǰ�洰��handle
if(hWnd == ::GetForegroundWindow())
   Result = true;
else
   {//ȡ��������ǰ�洰�ڵ��̴߳���ID
   fWinThreadID =
      ::GetWindowThreadProcessId(::GetForegroundWindow(), NULL);
   //ȡ�����ڴ��ڵ��߳�ID
   winThreadID = ::GetWindowThreadProcessId(hWnd, NULL);
   if(fWinThreadID != winThreadID)
      {//�����߲�ͬ�������������̵߳Ĵ��ڣ����ƶ�����ǰ��
      ::AttachThreadInput(fWinThreadID, winThreadID, true);
      Result = ::SetForegroundWindow(hWnd);//true
      //�ٽ⿪�˶��߲�ͬ�̵߳Ĺ���
      ::AttachThreadInput(fWinThreadID, winThreadID, false);
      }
   else//����ͬ����ֱ�ӽ��˴���������ǰ��
      Result = ::SetForegroundWindow(hWnd);
   //���ִ��ڵ������ϤW
   ::ShowWindow(hWnd, SW_RESTORE);
   return Result;
   }
return Result;
}
//---------------------------------------------------------------------------
