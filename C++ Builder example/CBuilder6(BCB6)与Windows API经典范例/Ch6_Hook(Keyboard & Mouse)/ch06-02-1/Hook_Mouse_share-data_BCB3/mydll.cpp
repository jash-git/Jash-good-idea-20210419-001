//---------------------------------------------------------------------------
//挂上、卸下hook，并运用内存中共享区块传递hook数据
//---------------------------------------------------------------------------
#include <vcl.h> //原有的头文件
#include <windows.h> //原有的头文件
#include <stdio.h> //加入C++字符串的头文件
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
//...user可自行扩充此结构成员
} *buf; //指向内存共享区块的指针
HANDLE maphandle;//共享的内存区块handle
//---------------------------------------------------------------------------
//符合以C语言编译的DLL输出函数
extern "C" __declspec(dllexport) __stdcall void SetHook(void);
extern "C" __declspec(dllexport) __stdcall void RemoveHook(void);
//---------------------------------------------------------------------------
//重载的MouseProc函数，持续送出鼠标全域信息
LRESULT CALLBACK MouseProc(int, WPARAM, LPARAM);
//---------------------------------------------------------------------------
//DLL的构造函数和析构函数
int WINAPI DllEntryPoint(HINSTANCE hinst, unsigned long reason, void*)
{
ghInst = hinst;
//当此DLL被调用或结束
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
   case DLL_PROCESS_DETACH: //此DLL的析构函数
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
  else
    MessageBox(NULL, "Sorry! 无法释放Hook。", "Hook DLL", MB_OK);
  }
else
  ::TextOut(GetDC(0),80,10,"Hook isn't NULL",16);
}
//---------------------------------------------------------------------------
//重载的MouseProc函数，持续送出鼠标全域信息
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
//若未挂上Hook链，就交给下一个hook链
if(nCode < 0)
   return ::CallNextHookEx(hHook, nCode, wParam, lParam);
//若已经挂上Hook链，则检测鼠标信息
if(hAppWnd != NULL)
  if(wParam==WM_MOUSEMOVE)
    {
    //运用全域的COPYDATASTRUCT结构传递鼠标信息
    // 1.有共享内存设置时的传递鼠标信息做法
    char str[20];//, state[20];
    AnsiString state;
    MOUSEHOOKSTRUCT *lpmhs = (MOUSEHOOKSTRUCT*)lParam;
    //鼠标Hook结构
    POINT p = lpmhs->pt;
    //鼠标指针
    ::GetClassName(lpmhs->hwnd,str,sizeof(str));
    //在 WinUser.h中的声明
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
    // 2.无共享内存设置时的传递鼠标信息做法
    /*
    COPYDATASTRUCT cds;
    cds.cbData = sizeof(MOUSEHOOKSTRUCT);
    cds.lpData = (MOUSEHOOKSTRUCT*)lParam;
    //向特定程序送出信息
    SendMessage(hAppWnd, WM_COPYDATA, (WPARAM)NULL, (LPARAM)&cds);
    */
  }
return 0;
}
//---------------------------------------------------------------------------

