//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCallHookForm *CallHookForm;
//---------------------------------------------------------------------------
HINSTANCE inst; //ָ�����hook�ṹ
//�����ڴ��У�dll��exe����Ľṹ�����ڴ��ݲ�׽����hook��Ϣ
struct POD
{
char text[256];
//...user����������˽ṹ��Ա��
} *buf; //ָ���ڴ湲�������ָ��
HANDLE MapHandle;//������ڴ�����handle
//��ʱȡ�������Ϣ
VOID CALLBACK MyTimerProc(HWND,UINT,UINT,DWORD);
//---------------------------------------------------------------------------
__fastcall TCallHookForm::TCallHookForm(TComponent* Owner)
    : TForm(Owner)
{
//����һ�����ڴ�����
MapHandle = ::CreateFileMapping( (HANDLE)0xffffffff, NULL,
                                 PAGE_READWRITE, 0,
                                 sizeof(POD), "MyMapName" );
//ȡ���ڴ湲������λ�ã�ת���ɿɲ�д�Ķ���ָ��
buf = (POD *)::MapViewOfFile( MapHandle, FILE_MAP_READ | FILE_MAP_WRITE,
                              0, 0, 0 );
//if ( ! buf ) return;
//���˹����ڴ����飨�ַ�������Ϊ��ֵ���������������Ϣ��
FillMemory(buf->text, sizeof(buf->text), '0');
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
//��CallHookFormά����������
FormStyle = fsStayOnTop;
}
//---------------------------------------------------------------------------
//����Hook���������ö�ʱ���ӹ����ڴ���ȡ�������Ϣ��
void __fastcall TCallHookForm::Button1Click(TObject *Sender)
{
//��mydll.dll�У�SetHook������ִ��ע��Hook���̵���Ϣ����
//��������һ��SetHook����
void (*SetHook)();
//����ͬһĿ¼�µ�ָ�������ļ�--mydll.dll
inst = ::LoadLibrary("mydll.dll");
//ȡ��dll��SetHook������ַ
(FARPROC &)SetHook = ::GetProcAddress(inst,"SetHook");
//ִ��ָ��dll�е�SetHook����
SetHook();
//���ö�ʱ����ÿ0.5��ӹ����ڴ���ȡ�������Ϣ
timer = ::SetTimer(NULL, 0, 200, (TIMERPROC)MyTimerProc);
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = false;
Button2->Enabled = true;
}
//---------------------------------------------------------------------------
//ж��Hook������ֹͣ��ʱ��
void __fastcall TCallHookForm::Button2Click(TObject *Sender)
{
//ֹͣ��ʱ������
::KillTimer(NULL, timer);
//��mydll.dll�У�RemoveHook������ִ�д���Ϣ����ж��Hook����
//����RemoveHook����
void (*RemoveHook)();
//����ͬһĿ¼�µ�ָ�������ļ�--mydll.dll
inst = ::LoadLibrary("mydll.dll");
//ȡ��dll��RemoveHook������ַ
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//ִ��ָ��dll�е�RemoveHook����
RemoveHook();
//�ͷ�dll
::FreeLibrary(inst);
//���Ϻ�ж��Hook�İ�ť״̬
Button1->Enabled = true;
Button2->Enabled = false;
}
//---------------------------------------------------------------------------
//Ԥ���û�����Hookʱ��δж��Hook��
void __fastcall TCallHookForm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
if(timer)//ֹͣ��ʱ������
  ::KillTimer(NULL, timer);

//��mydll.dll�У�RemoveHook������ִ�д���Ϣ����ж��Hook����
//����RemoveHook����
void (*RemoveHook)();
//����dll
inst = ::LoadLibrary("mydll.dll");
//ȡ��dll��RemoveHook������ַ
(FARPROC &)RemoveHook = ::GetProcAddress(inst,"RemoveHook");
//ִ��ָ��dll�е�RemoveHook����
RemoveHook();
//�ͷ�dll
::FreeLibrary(inst);
//�ͷ��ڴ�����
UnmapViewOfFile((void *)buf);
}
//---------------------------------------------------------------------------
//��ʱ��CALLBACK������ÿ0.5��ӹ����ڴ���ȡ�������Ϣ
VOID CALLBACK MyTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
CallHookForm->Edit1->Text=AnsiString(buf->text);
}
//---------------------------------------------------------------------------
