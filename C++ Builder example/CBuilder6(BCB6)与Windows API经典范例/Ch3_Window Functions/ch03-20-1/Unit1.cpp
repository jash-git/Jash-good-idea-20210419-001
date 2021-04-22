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
char scrt[MAX_PATH];
//��ϵͳ�ļ���ȡ���ض��ַ������ж���Ļ���������Ƿ��Ѿ�����
DWORD res = ::GetPrivateProfileString("boot",
                         "SCRNSAVE.EXE","",scrt,MAX_PATH,
                         "system.ini");
if(res==0 || strcmp(scrt,"")==0)
  ShowMessage("�����Ļû����\n��Ļ�������档");
else
  {
  //���ж�ϵͳ�����Բ�׽��Ļ��������handle
  if (ScreensaverNTor95()) return;
  //ȡ����ǰ�洰��handle���ͳ�������Ļ����������Ϣ
  HWND hfw = ::GetForegroundWindow();
  if(hfw==NULL)
    DefWindowProc(Handle,WM_SYSCOMMAND,SC_SCREENSAVE,0);
  else
    PostMessage(hfw,WM_SYSCOMMAND,SC_SCREENSAVE,0);
  }
}
//---------------------------------------------------------------------------
//���ж�ϵͳ�����Բ�׽��Ļ��������handle--�Զ��庯��
BOOL TForm1::ScreensaverNTor95()
{
BOOL isNT;
//ȡ�ô���ϵͳ��Ϣ���ж��Ƿ�ΪNT
OSVERSIONINFO ovi;
ovi.dwOSVersionInfoSize=sizeof(ovi);
::GetVersionEx(&ovi);
if(ovi.dwPlatformId==VER_PLATFORM_WIN32_NT) isNT=TRUE;
else isNT=FALSE;
//����NT����ȡ����Ļ�����������Ϣ��
//�ж���Ļ��������ɷ�ִ�У�������αֵ
if(!isNT)
  {
  UINT srunning=0,dummy;
  ::SystemParametersInfo(SPI_SCREENSAVERRUNNING,0,&srunning,0);
  ::SystemParametersInfo(SPI_SCREENSAVERRUNNING,srunning,&dummy,0);
  if (srunning==0) return FALSE;
  else return TRUE;
  }
//��ΪNT������NT�Ƕ���ϵͳ����Ļ�����������������һ��ִ����
//�ٳ���ȡ����Ļ��������handle
HWND hfw = ::GetForegroundWindow();
if (hfw==NULL) return TRUE;
LONG style = ::GetWindowLong(hfw,GWL_STYLE);
//��ʽ����POP��ʽ����ʾ�У������Ļ��������handle������αֵ
if ((style & 0xF0000000)!= (WS_POPUP|WS_VISIBLE)) return FALSE;
//����handle������ȫ��Ļ�������Ļ��������handle������αֵ
RECT rc;
::GetWindowRect(hfw,&rc);
if (rc.right-rc.left != ::GetSystemMetrics(SM_CXSCREEN) ||
    rc.bottom-rc.top != ::GetSystemMetrics(SM_CYSCREEN))
    return FALSE;
return TRUE;
}
//---------------------------------------------------------------------------
