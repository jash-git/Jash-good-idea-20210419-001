//---------------------------------------------------------------------------
//挂上、卸下hook，并运用内存中共享区块传递Hook数据
//---------------------------------------------------------------------------
#include <vcl.h> //原有头文件
#include <windows.h> //原有头文件
#include <stdio.h> //加入C++字符串头文件
#pragma hdrstop
#pragma argsused
//---------------------------------------------------------------------------
//DLL的固定声明
HHOOK hHook;//挂上的hook handle
HINSTANCE ghInst;//连接文件的模块handle，固定进程
HWND hAppWnd;//执行此dll的特定exe程序handle__"TMouseHookForm"
//存于内存中，dll和exe共享的结构，用于传递捕捉到的hook信息
struct POD
{
char text[256];
//...user可自行扩充此结构成员
} *buf; //指向内存共享区块的指针
HANDLE maphandle;//共享的内存区块handle
//---------------------------------------------------------------------------
//符合以C语言编译的DLL输出函数
extern "C" __declspec(dllexport) __stdcall void SetHook(void);
extern "C" __declspec(dllexport) __stdcall void RemoveHook(void);
//---------------------------------------------------------------------------
//重载的MouseProc函数，持续送出鼠标全域信息
LRESULT CALLBACK MouseProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL的构造函数与析构函数
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void* lpReserved)
{
ghInst = hinst;
//当此DLL被调用或结束
switch(reason)
   {
   case DLL_PROCESS_ATTACH: //此DLL的构造函数
         //取得执行此dll的特定程序handle
         hAppWnd = ::FindWindow("TCallHookForm", 0);
         //打开已经存在的共享内存区域
         maphandle = ::OpenFileMapping( FILE_MAP_WRITE, false, "MyMapName");
         //if(!maphandle) return;
         //转换成可擦写的对象指针
         buf = (POD *)::MapViewOfFile( maphandle,
                                       FILE_MAP_READ | FILE_MAP_WRITE,
                                       0, 0, 0 );
         //if(!buf) return;
         break;
   case DLL_PROCESS_DETACH: //此DLL析构函数
         //释放内存区块
         ::UnmapViewOfFile((void *)buf);
         break;
   }
return 1;
}
//---------------------------------------------------------------------------
//注册自定义hook到hook链中
void __stdcall SetHook(void)
{//若Hook尚未挂到信息链中，则将本鼠标信息dll注册到hook链中
if(hHook == NULL)
  {
  hHook = ::SetWindowsHookEx(WH_MOUSE, (HOOKPROC)MouseProc, ghInst, 0);
  //显示是否挂上hook
  if(hHook == NULL)
      MessageBox(NULL, "Sorry! 无法挂上Hook", "Hook DLL", MB_OK);
  else
      ::TextOut(GetDC(0),10,10,"挂上Hook。",10);
  }
}
//---------------------------------------------------------------------------
//在hook链中，解除自定义的hook
void __stdcall RemoveHook(void)
{//若Hook已经挂上信息链，则卸下此Hook信息
if(hHook != NULL)
  {
  if(::UnhookWindowsHookEx(hHook) != FALSE)
    {
    hHook = NULL;
    ::TextOut(GetDC(0),50,10,"释放Hook。",10);
    }
  else
    MessageBox(NULL, "Sorry! 无法释放Hook。", "Hook DLL", MB_OK);
  }
else
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//重载的MouseProc函数，持续送出鼠标全域信息
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//若未挂上Hook链，就交给下一个hook链
if(nCode < 0)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//若已经挂上Hook链，则检测鼠标信息
if(hAppWnd != NULL)
  if(wParam==WM_MOUSEMOVE)
    {
    //运用全域的COPYDATASTRUCT结构传递鼠标信息
    // 1.有共享内存设置时的传递鼠标信息做法
    char str[20];
    MOUSEHOOKSTRUCT *lpmhs = (MOUSEHOOKSTRUCT*)lParam;
    POINT p = lpmhs->pt;
    ::GetClassName(lpmhs->hwnd,str,sizeof(str));
    sprintf(buf->text, "%s__X=%i,Y=%i",str,(int)p.x,(int)p.y);
    // 2.无共享内存设置时的传递鼠标信息做法
    /*
    COPYDATASTRUCT cds;
    cds.cbData = sizeof(MOUSEHOOKSTRUCT);
    cds.lpData = (MOUSEHOOKSTRUCT*)lParam;
    //向特定程序送出信息
    SendMessage(hAppWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
    */
  }
return 0;
}
//---------------------------------------------------------------------------

