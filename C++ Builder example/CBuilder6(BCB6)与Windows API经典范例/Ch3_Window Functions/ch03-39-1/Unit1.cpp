//---------------------------------------------------------------------------
//程序目的：制造一状态栏小图标(TrayIcon)，并可执行POP菜单功能
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//当成功制作一新TrayIcon时的识别ID-------------------------------------------
const int WM_TRAYID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//-----------------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//新建一个图示，用来获取ImageList1中的图像
TrayIcon = new Graphics::TIcon;
//自定义函数--第一次即为快捷键自定义的TrayIcon
AddorChangeIcon(0);
//将快捷工具栏上的母窗口Project1隐藏
::ShowWindow(Application->Handle, SW_HIDE);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//对等于现存的TrayIcon结构数据
NOTIFYICONDATA tray;
tray.cbSize = sizeof(tray);
tray.uID =  WM_TRAYID;//自定义ID
tray.hWnd = Handle;
tray.hIcon = TrayIcon->Handle;
//依此结构，即进行删除此TrayIcon
::Shell_NotifyIcon(NIM_DELETE, &tray);
delete TrayIcon;//删除程序开始时新建的图标组件
ShowMessage("关闭本TrayIcon程序测试！");
}
//---------------------------------------------------------------------------
//新建或更新自定义的TrayIcon
void __fastcall TForm1::AddorChangeIcon(int iconNum)
{
//在程序结束前，将此布尔变量及整数变量的保存位置固定住
static bool AlreadyAdded = false;
static int IconAdded = -1;
//第一次启用本函数之后，即排除相同变量的重复执行
if (IconAdded == iconNum) return;
//声明及填入TrayIcon结构
NOTIFYICONDATA newIcon;
newIcon.cbSize = sizeof(newIcon);
newIcon.uID =  WM_TRAYID;//自定义识别ID
newIcon.hWnd = Handle;
//自定义此TrayIcon的callback信息
newIcon.uCallbackMessage = WM_TRAYICON;
//将字符串复制至"提示"中
lstrcpy(newIcon.szTip, "自定义TRAY_ICON测试");
//设置从ImageList1中取出的图示
ImageList1->GetIcon(iconNum, TrayIcon);
newIcon.hIcon = TrayIcon->Handle;
//决定是新建或修改TrayIcon
DWORD dwMessage;
(AlreadyAdded)?(dwMessage = NIM_MODIFY):(dwMessage = NIM_ADD);
//设置标志--允许送出自定义信息、自定义图标、自定义提示
newIcon.uFlags = NIF_MESSAGE | NIF_ICON | NIF_TIP;
//建立一新建或修改现有TrayIcon
::Shell_NotifyIcon(dwMessage, &newIcon);
//经过第一次是新建TrayIcon，以后都是更新修改
//此2值更新且保存固定地址，以供下次执行本函数使用
AlreadyAdded = true;
IconAdded = iconNum;
}
//------------------------------------------------------------------------------------
void __fastcall TForm1::WmNewTray(TMessage &Msg)
{//专为捕捉TrayIcon自定义信息
if(Msg.Msg == WM_TRAYICON)
 {
 switch(Msg.LParam)
  {//当鼠标双击此TrayIcon时，即切换显示或隐藏Form1窗口
  case WM_LBUTTONDBLCLK:
        {
        ::ShowWindow(Handle,::IsWindowVisible(Handle)?SW_HIDE:SW_SHOW);
        break;
        }
  case WM_RBUTTONUP://当用鼠标右键点击TrayIcon，则出现POP菜单
        {
        POINT p;
        ::GetCursorPos(&p);//取得屏幕坐标
        ::SetForegroundWindow(Handle);//将Form1提至最前面备用
        PopupMenu1->Popup(p.x, p.y);//显示POP菜单
        PostMessage(Handle, WM_NULL, 0,0);//删除未知信息
        break;
        }
  }
 }
//若有其他信息依默认处理
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//以下都是单击POP菜单时，应执行的功能，请user自行修改
void __fastcall TForm1::pop011Click(TObject *Sender)
{//自定义函数--修改自定义的TrayIcon图示
AddorChangeIcon(1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pop021Click(TObject *Sender)
{//自定义函数--修改自定义的TrayIcon图示
AddorChangeIcon(2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::pop031Click(TObject *Sender)
{//关闭本程序
Close();
}
//---------------------------------------------------------------------------

