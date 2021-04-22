//---------------------------------------------------------------------------
//挂上、卸下Keyboard hook，并运用自定义信息传递Hook数据
//---------------------------------------------------------------------------
#include <vcl.h> //原有BCB 头文件
#include <windows.h> // 原有window 头文件
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
//自定义的键盘信息，与执行文件TKeyHookForm中自定义的键盘信息相互对应
const int WM_KEYHOOK = WM_USER+100;
//---------------------------------------------------------------------------
//DLL的固定声明
HHOOK hHook;//挂上的hook handle
HWND hAppWnd;//执行此dll的特定exe程序handle__"TKeyHookForm"
HINSTANCE inst;//连接文件的模块handle，固定行程
//---------------------------------------------------------------------------
//符合以C语言编译的DLL输出函数
extern "C" {
       __declspec(dllexport) __stdcall void SetHook(void);
       __declspec(dllexport) __stdcall void RemoveHook(void);
       }
//---------------------------------------------------------------------------
//重载的KeyboardProc函数，持续送出键盘全域信息
LRESULT CALLBACK KeyboardProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL的构造函数和析构函数
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
inst = hinst;
//当此DLL被调用or结束
switch (reason)
    {
    case DLL_PROCESS_ATTACH ://此DLL构造函数
         //取得执行此dll的特定程序handle
         hAppWnd = ::FindWindow("TKeyHookForm", 0);
         break;

    case DLL_PROCESS_DETACH://此DLL析构函数
         break;

    case DLL_THREAD_ATTACH: //此DLL多线程构造函数
         break;

    case DLL_THREAD_DETACH: //此DLL多线程析构函数
         break;
  }
return 1;
}
//---------------------------------------------------------------------------
//注册自定义hook到hook链中
void __stdcall SetHook(void)
{//若Hook尚未挂上信息链，则将本鼠标信息dll注册至hook链中
if(hHook == NULL)
  {
  hHook = ::SetWindowsHookEx(WH_KEYBOARD, (HOOKPROC)KeyboardProc, inst, 0);
  //显示是否挂上hook，测试用！
  if(hHook == NULL)
      MessageBox(NULL, "Sorry! 无法挂上Hook。", "Hook DLL", MB_OK);
  else
      ::TextOut(GetDC(0),10,10,"挂上Hook。",10);
  }
}
//---------------------------------------------------------------------------
//在hook链中，解除自定义的hook
void __stdcall RemoveHook(void)
{//若Hook已经挂上信息链，则卸下此Hook信息
if(hHook != NULL)
  {
  if(::UnhookWindowsHookEx(hHook) != FALSE)
    {
    hHook = NULL;
    ::TextOut(GetDC(0),50,10,"释放Hook。",10);
    }
  else //测试用！
    MessageBox(NULL, "Sorry! 无法释放Hook。", "Hook DLL", MB_OK);
  }
else //测试用！
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//重载的KeyboardProc函数，持续送出键盘全域信息
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//若未挂上Hook链或键盘无信息输出，就交予下一hook链
if((nCode < 0) || nCode == HC_NOREMOVE)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//若信息重复，则跳至下一hook链
if(lParam & 0x40000000)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//若在DLL构造函数中，取得执行此dll的特定程序handle，即送出自定义键盘信息
if(hAppWnd != NULL)
  SendMessage(hAppWnd, WM_KEYHOOK, wParam, lParam);

return ::CallNextHookEx(hHook, nCode, wParam, lParam);
}
//---------------------------------------------------------------------------

