//---------------------------------------------------------------------------
//���ϡ�ж��Keyboard hook���������Զ�����Ϣ����Hook���ݮ�
//---------------------------------------------------------------------------
#include <vcl.h> //ԭ��BCB ͷ�ļ�
#include <windows.h> // ԭ��window ͷ�ļ�
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
//�Զ���ļ�����Ϣ����ִ���ļ�TKeyHookForm���Զ���ļ�����Ϣ�໥��Ӧ
const int WM_KEYHOOK = WM_USER+100;
//---------------------------------------------------------------------------
//DLL�Ĺ̶������ŧi
HHOOK hHook;//���ϵ�hook handle
HWND hAppWnd;//ִ�д�dll���ض�exe����handle__"TKeyHookForm"
HINSTANCE inst;//�����ļ���ģ��handle���̶��г�
//---------------------------------------------------------------------------
//������C���Ա����DLL�������
extern "C" {
       __declspec(dllexport) __stdcall void SetHook(void);
       __declspec(dllexport) __stdcall void RemoveHook(void);
       }
//---------------------------------------------------------------------------
//���ص�KeyboardProc�����������ͳ�����ȫ����Ϣ��
LRESULT CALLBACK KeyboardProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL�Ĺ��캯������������
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
inst = hinst;
//����DLL������or������
switch (reason)
    {
    case DLL_PROCESS_ATTACH ://��DLL���캯��
         //ȡ��ִ�д�dll���ض�����handle
         hAppWnd = ::FindWindow("TKeyHookForm", 0);
         break;

    case DLL_PROCESS_DETACH://��DLL��������
         break;

    case DLL_THREAD_ATTACH: //��DLL���̹߳��캯��
         break;

    case DLL_THREAD_DETACH: //��DLL���߳���������
         break;
  }
return 1;
}
//---------------------------------------------------------------------------
//ע���Զ���hook��hook����
void __stdcall SetHook(void)
{//��Hook��δ������Ϣ�����򽫱������Ϣdllע����hook����
if(hHook == NULL)
  {
  hHook = ::SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, inst, 0);
  //��ʾ�Ƿ����hook�������ã��I
  if(hHook == NULL)
      MessageBox(NULL, "Sorry! �޷�����Hook��", "Hook DLL", MB_OK);
  else
      ::TextOut(GetDC(0),10,10,"����Hook��",10);
  }
}
//---------------------------------------------------------------------------
//��hook���У�����Զ����hook
void __stdcall RemoveHook(void)
{//��Hook�Ѿ�������Ϣ������ж�´�Hook��Ϣ
if(hHook != NULL)
  {
  if(::UnhookWindowsHookEx(hHook) != FALSE)
    {
    hHook = NULL;
    ::TextOut(GetDC(0),50,10,"�ͷ�Hook��",10);
    }
  else //�����ã��I
    MessageBox(NULL, "Sorry! �޷��ͷ�Hook��", "Hook DLL", MB_OK);
  }
else //�����ã�
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//���ص�KeyboardProc�����������ͳ�����ȫ����Ϣ��
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//��δ����Hook�����������Ϣ������ͽ�����һhook��
if((nCode < 0) || nCode == HC_NOREMOVE)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//����Ϣ�ظ�����������һhook��
if(lParam & 0x40000000)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//����DLL���캯���У�ȡ��ִ�д�dll���ض�����handle�����ͳ��Զ��������Ϣ��
if(hAppWnd != NULL)
  SendMessage(hAppWnd, WM_KEYHOOK, wParam, lParam);

return ::CallNextHookEx(hHook, nCode, wParam, lParam);
}
//---------------------------------------------------------------------------

