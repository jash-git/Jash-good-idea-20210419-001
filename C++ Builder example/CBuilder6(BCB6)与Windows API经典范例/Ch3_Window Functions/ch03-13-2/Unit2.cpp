//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�Զ����callback����---------------------------------------------------------
BOOL CALLBACK HuntWinClock(HWND, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ĭ��2����ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//���ؿ�ݹ������ϵ�ʱ����ʾ
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ�ÿ�ݹ�������handle
HWND HtrayWin = ::FindWindow("Shell_TrayWnd", NULL);
//��û�ҵ���ݹ�����������ָ�֪��Ϣ&ִֹͣ��
if(!::IsWindow(HtrayWin))
  {
  Caption = "��Ĵ�����û�п�ݹ�������";
  return;
  }
//��һ��Ѱ��ݹ������µ�ʱ����ʾ����֪ͨ������ʾ��ʱ
::EnumChildWindows(
    HtrayWin,
    reinterpret_cast <WNDENUMPROC> (HuntWinClock),
    SW_HIDE
    );
//����2����ť״̬
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//���Կ�ݹ������ϵ�ʱ����ʾ
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ȡ�ÿ�ݹ�������handle
HWND HtrayWin = ::FindWindow("Shell_TrayWnd", NULL);
//��û�ҵ���ݹ�����������ָ�֪��Ϣ&ִֹͣ��
if(!::IsWindow(HtrayWin))
  {
  Caption = "��Ĵ�����û�п�ݹ�������";
  return;
  }
//��һ��Ѱ��ݹ������µ�ʱ����ʾ����֪ͨ������ʾ��ʱ
::EnumChildWindows(
    HtrayWin,
    reinterpret_cast <WNDENUMPROC> (HuntWinClock),
    SW_RESTORE
    );
//����2����ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//�Զ����callback����
BOOL CALLBACK HuntWinClock( HWND HWin, LPARAM FlagSet)
{
//ȡ�ô���handle��������
char className[256];
::GetClassName(HWin, className, sizeof(className));
//����ʱ����ʾ��������ƣ�������ָ�����
if(lstrcmp(className, "TrayClockWClass") == 0)
   {
   ::ShowWindow(HWin, static_cast <int> (FlagSet));
   return FALSE;
   }
//����ʱ����ʾ�������ƣ��������һhandle����J
return TRUE;
}
//---------------------------------------------------------------------------
