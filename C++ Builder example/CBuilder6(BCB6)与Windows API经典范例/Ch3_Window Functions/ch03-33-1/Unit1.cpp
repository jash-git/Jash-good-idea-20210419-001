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
//�Ƚ������©��ͼ��
Screen->Cursor = crHourGlass;
//����STARTUPINFO�ṹ�����ý�Ҫ�򿪳������ʾ״̬
STARTUPINFO start;
start.cb = sizeof(STARTUPINFO);
start.lpReserved = 0;//��ΪNULL����ʹ��CreateProcess
start.lpDesktop = 0;
start.lpTitle = 0;
start.dwX = Screen->Width/2;
start.dwY = Screen->Height/2;
start.dwXSize = Screen->Width/2;
start.dwYSize = Screen->Height/2;
//ʹ����ṹ���õ�λ�����С
start.dwFlags = STARTF_USEPOSITION | STARTF_USESIZE;
start.cbReserved2 = 0;//��ΪNULL
start.lpReserved2 = 0;//��ΪNULL
//����ס���滭����¶���
::LockWindowUpdate(::GetDesktopWindow());
//����CreateProcess���������˹�����Ϣ�ṹ
PROCESS_INFORMATION ProcessInfo;
//����һ�����������г̣���ָ������
::CreateProcess(0, "NotePad.exe", 0, 0, false,
                CREATE_DEFAULT_ERROR_MODE, 0, 0,
                &start,
                &ProcessInfo
                );
//���г̽����У���user��5����������Ϣ
::WaitForInputIdle(ProcessInfo.hProcess, 5000);
//��ɴ򿪳����Ѱ�Ҵ򿪵�<���±�>����
HWND hWnd = ::FindWindow("���±�", 0);
//�����ڴ˴��ڣ��������ǰ��
if(::IsWindow(hWnd))
   ::SetForegroundWindow(hWnd);
//�ָ����滭����²���
::LockWindowUpdate(NULL);
//�ָ����ΪĬ�ϼ�ͷͼ��
Screen->Cursor = crDefault;
}
//---------------------------------------------------------------------------
