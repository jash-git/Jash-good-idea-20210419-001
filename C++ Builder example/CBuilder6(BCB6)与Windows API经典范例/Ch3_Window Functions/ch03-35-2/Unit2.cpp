//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
///-�ر���Ļ��������callback����----------------------------------------------
BOOL __stdcall CALLBACK KillScreenSaverFunc(HWND, long);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
HDESK hdesk;
//����Ļ������������У����֮�ͳ��ر���Ϣ
hdesk = ::OpenDesktop("Screen-Saver",
                      DF_ALLOWOTHERACCOUNTHOOK,
                      false,
                      DESKTOP_READOBJECTS | DESKTOP_WRITEOBJECTS);
if(hdesk)
  {//����һ��������Ѱ��Ļ�������򣬲���callback�����ͳ��رճ�����Ϣ��
  ::EnumDesktopWindows(hdesk,(WNDENUMPROC)KillScreenSaverFunc, 0);
  //�ر�ָ�������߳�
  ::CloseDesktop(hdesk);
  Memo1->Text = "��NT�����񻷾��£��ɹ���ɹرձ�����Ļ����";
  }
else
  Memo1->Text = "��95,98���������£����ܿ������رձ�����Ļ����";
}
///-�ر���Ļ��������callback����----------------------------------------------
BOOL __stdcall CALLBACK KillScreenSaverFunc(HWND hwnd, long lParam)
{//����Ļ������������У����֮�ͳ��ر���Ϣ
if(::IsWindowVisible(hwnd))
   {
   PostMessage(hwnd, WM_CLOSE, 0, 0);
   return true;
   }
return false;
}
//---------------------------------------------------------------------------

