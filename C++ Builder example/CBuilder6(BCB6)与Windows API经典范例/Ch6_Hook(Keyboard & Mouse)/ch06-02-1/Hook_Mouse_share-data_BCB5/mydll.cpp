//---------------------------------------------------------------------------
//���ϡ�ж��hook���������ڴ��й������鴫��Hook���ݮ�
//---------------------------------------------------------------------------
#include <vcl.h> //ԭ��ͷ�ļ�
#include <windows.h> //ԭ��ͷ�ļ�
#include <stdio.h> //����C++�ַ���ͷ�ļ�
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
//DLL�Ĺ̶�����
HHOOK hHook;//���ϵ�hook handle
HINSTANCE ghInst;//�����ļ���ģ��handle���̶�����
HWND hAppWnd;//ִ�д�dll���ض�exe����handle__"TMouseHookForm"
//�����ڴ��У�dll��exe����Ľṹ�����ڴ��ݲ�׽����hook��Ϣ
struct POD
{
char text[256];
//...user����������˽ṹ��Ա��
} *buf; //ָ���ڴ湲�������ָ��
HANDLE maphandle;//������ڴ�����handle
//---------------------------------------------------------------------------
//������C���Ա����DLL�������
extern "C" __declspec(dllexport) __stdcall void SetHook(void);
extern "C" __declspec(dllexport) __stdcall void RemoveHook(void);
//---------------------------------------------------------------------------
//���ص�MouseProc�����������ͳ����ȫ����Ϣ��
LRESULT CALLBACK MouseProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL�Ĺ��캯������������
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
ghInst = hinst;
//����DLL�����û������
switch(reason)
   {
   case DLL_PROCESS_ATTACH: //��DLL�Ĺ��캯��
         //ȡ��ִ�д�dll���ض�����handle
         hAppWnd = ::FindWindow("TCallHookForm", 0);
         //���Ѿ����ڵĹ����ڴ�����
         maphandle = ::OpenFileMapping( FILE_MAP_WRITE, false, "MyMapName");
         //if(!maphandle) return;
         //ת���ɿɲ�д�Ķ���ָ��
         buf = (POD *)::MapViewOfFile( maphandle,
                                       FILE_MAP_READ | FILE_MAP_WRITE,
                                       0, 0, 0 );
         //if(!buf) return;
         break;
   case DLL_PROCESS_DETACH: //��DLL��������
         //�ͷ��ڴ�����
         ::UnmapViewOfFile((void *)buf);
         break;
   }
return 1;
}
//---------------------------------------------------------------------------
//ע���Զ���hook��hook����
void __stdcall SetHook(void)
{//��Hook��δ�ҵ���Ϣ���У��򽫱������Ϣdllע�ᵽhook����
if(hHook == NULL)
  {
  hHook = ::SetWindowsHookEx(WH_MOUSE, (HOOKPROC)MouseProc, ghInst, 0);
  //��ʾ�Ƿ����hook
  if(hHook == NULL)
      MessageBox(NULL, "Sorry! �޷�����Hook�C", "Hook DLL", MB_OK);
  else
      ::TextOut(GetDC(0),10,10,"����Hook��",10);
  }
}
//---------------------------------------------------------------------------
//��hook���У�����Զ����hook
void __stdcall RemoveHook(void)
{//��Hook�Ѿ�������Ϣ������ж�´�Hook��Ϣ��
if(hHook != NULL)
  {
  if(::UnhookWindowsHookEx(hHook) != FALSE)
    {
    hHook = NULL;
    ::TextOut(GetDC(0),50,10,"�ͷ�Hook��",10);
    }
  else
    MessageBox(NULL, "Sorry! �޷��ͷ�Hook��", "Hook DLL", MB_OK);
  }
else
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//���ص�MouseProc�����������ͳ����ȫ����Ϣ��
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//��δ����Hook�����ͽ�����һ��hook��
if(nCode < 0)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//���Ѿ�����Hook�������������Ϣ��
if(hAppWnd != NULL)
  if(wParam==WM_MOUSEMOVE)
    {
    //����ȫ���COPYDATASTRUCT�ṹ���������Ϣ��
    // 1.�й����ڴ�����ʱ�Ĵ��������Ϣ����
    char str[20];
    MOUSEHOOKSTRUCT *lpmhs = (MOUSEHOOKSTRUCT*)lParam;
    POINT p = lpmhs->pt;
    ::GetClassName(lpmhs->hwnd,str,sizeof(str));
    sprintf(buf->text, "%s__X=%i,Y=%i",str,(int)p.x,(int)p.y);
    // 2.�޹����ڴ�����ʱ�Ĵ��������Ϣ����
    /*
    COPYDATASTRUCT cds;
    cds.cbData = sizeof(MOUSEHOOKSTRUCT);
    cds.lpData = (MOUSEHOOKSTRUCT*)lParam;
    //���ض������ͳ���Ϣ��
    SendMessage(hAppWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
    */
  }
return 0;
}
//---------------------------------------------------------------------------

