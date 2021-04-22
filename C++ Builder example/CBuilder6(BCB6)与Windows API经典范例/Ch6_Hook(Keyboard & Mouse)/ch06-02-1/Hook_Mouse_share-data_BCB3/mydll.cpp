//---------------------------------------------------------------------------
//���ϡ�ж��hook���������ڴ��й������鴫��hook����
//---------------------------------------------------------------------------
#include <vcl.h> //ԭ�е�ͷ�ļ�
#include <windows.h> //ԭ�е�ͷ�ļ�
#include <stdio.h> //����C++�ַ�����ͷ�ļ�
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
//...user����������˽ṹ��Ա
} *buf; //ָ���ڴ湲�������ָ��
HANDLE maphandle;//������ڴ�����handle
//---------------------------------------------------------------------------
//������C���Ա����DLL�������
extern "C" __declspec(dllexport) __stdcall void SetHook(void);
extern "C" __declspec(dllexport) __stdcall void RemoveHook(void);
//---------------------------------------------------------------------------
//���ص�MouseProc�����������ͳ����ȫ����Ϣ
LRESULT CALLBACK MouseProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL�Ĺ��캯������������
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
ghInst = hinst;
//����DLL�����û����
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
   case DLL_PROCESS_DETACH: //��DLL����������
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
  else
    MessageBox(NULL, "Sorry! �޷��ͷ�Hook��", "Hook DLL", MB_OK);
  }
else
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//���ص�MouseProc�����������ͳ����ȫ����Ϣ
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//��δ����Hook�����ͽ�����һ��hook��
if(nCode < 0)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//���Ѿ�����Hook�������������Ϣ��
if(hAppWnd != NULL)
  if(wParam==WM_MOUSEMOVE)
    {
    //����ȫ���COPYDATASTRUCT�ṹ���������Ϣ
    // 1.�й����ڴ�����ʱ�Ĵ��������Ϣ����
    char str[20];//, state[20];
    AnsiString state;
    MOUSEHOOKSTRUCT *lpmhs = (MOUSEHOOKSTRUCT*)lParam;
    //���Hook�ṹ
    POINT p = lpmhs->pt;
    //���ָ��
    ::GetClassName(lpmhs->hwnd,str,sizeof(str));
    //�� WinUser.h�е�����
    switch((int)lpmhs->wHitTestCode)
     {
     case -2: state = "HTERROR"; break;
     case -1: state = "HTTRANSPARENT"; break;
     case 0: state = "HTNOWHERE"; break;
     case 1: state = "HTCLIENT"; break;
     case 2: state = "HTCAPTION"; break;
     case 3: state = "HTSYSMENU"; break;
     case 4: state = "HTGROWBOX or HTSIZE"; break;
     case 5: state = "HTMENU"; break;
     case 6: state = "HTHSCROLL"; break;
     case 7: state = "HTVSCROLL"; break;
     case 8: state = "HTMINBUTTON or HTREDUCE"; break;
     case 9: state = "HTMAXBUTTON or HTZOOM"; break;
     case 10: state = "HTLEFT or HTSIZEFIRST"; break;
     case 11: state = "HTRIGHT"; break;
     case 12: state = "HTTOP"; break;
     case 13: state = "HTTOPLEFT"; break;
     case 14: state = "HTTOPRIGHT"; break;
     case 15: state = "HTBOTTOM"; break;
     case 16: state = "HTBOTTOMLEFT"; break;
     case 17: state = "HTBOTTOMRIGHT or HTSIZELAST"; break;
     case 18: state = "HTBORDER"; break;
     case 19: state = "HTOBJECT"; break;
     case 20: state = "HTCLOSE"; break;
     case 21: state = "HTHELP"; break;
   //  default : state = "       ";
     /*      //
     case -2: sprintf(state,"HTERROR"); break;
     case -1: sprintf(state,"HTTRANSPARENT"); break;
     case 0: sprintf(state,"HTNOWHERE"); break;
     case 1: sprintf(state,"HTCLIENT"); break;
     case 2: sprintf(state,"HTCAPTION"); break;
     case 3: sprintf(state,"HTSYSMENU"); break;
     case 4: sprintf(state,"HTGROWBOX or HTSIZE"); break;
     case 5: sprintf(state,"HTMENU"); break;
     case 6: sprintf(state,"HTHSCROLL"); break;
     case 7: sprintf(state,"HTVSCROLL"); break;
     case 8: sprintf(state,"HTMINBUTTON or HTREDUCE"); break;
     case 9: sprintf(state,"HTMAXBUTTON or HTZOOM"); break;
     case 10: sprintf(state,"HTLEFT or HTSIZEFIRST"); break;
     case 11: sprintf(state,"HTRIGHT"); break;
     case 12: sprintf(state,"HTTOP"); break;
     case 13: sprintf(state,"HTTOPLEFT"); break;
     case 14: sprintf(state,"HTTOPRIGHT"); break;
     case 15: sprintf(state,"HTBOTTOM"); break;
     case 16: sprintf(state,"HTBOTTOMLEFT"); break;
     case 17: sprintf(state,"HTBOTTOMRIGHT or HTSIZELAST"); break;
     case 18: sprintf(state,"HTBORDER"); break;
     case 19: sprintf(state,"HTOBJECT"); break;
     case 20: sprintf(state,"HTCLOSE"); break;
     case 21: sprintf(state,"HTHELP"); break;
     default : sprintf(state,"     ");
     */
     }

    sprintf(buf->text, "%s__%s__X=%i,Y=%i",str,state.c_str(),(int)p.x,(int)p.y);
    state = " ";
    // 2.�޹����ڴ�����ʱ�Ĵ��������Ϣ����
    /*
    COPYDATASTRUCT cds;
    cds.cbData = sizeof(MOUSEHOOKSTRUCT);
    cds.lpData = (MOUSEHOOKSTRUCT*)lParam;
    //���ض������ͳ���Ϣ
    SendMessage(hAppWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
    */
  }
return 0;
}
//---------------------------------------------------------------------------

