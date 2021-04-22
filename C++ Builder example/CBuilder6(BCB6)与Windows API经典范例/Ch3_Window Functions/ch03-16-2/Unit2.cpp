//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//将此程序设为桌面最上层
FormStyle = fsStayOnTop;
//程序开始时，隐藏<快捷工具栏>
HWND hTaskbarWnd;
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
::ShowWindow(hTaskbarWnd, SW_HIDE);
//隐藏所有桌面对象，需调用2次GetWindow
HWND hwnd;
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_HIDE);
//将窗口切换盒(Alt+Tab组合键)失效
::SystemParametersInfo(SPI_SCREENSAVERRUNNING, true, &OldValue, 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//显现所有桌面对象，需调用2次GetWindow
HWND hwnd;
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_SHOW);

//程序关闭时，显现<快捷工具栏>
HWND hTaskbarWnd;
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
::ShowWindow(hTaskbarWnd, SW_SHOW);

//将窗口切换成(Alt+Tab组合键) 使之有效
::SystemParametersInfo(SPI_SCREENSAVERRUNNING, false, &OldValue, 0);
}
//---------------------------------------------------------------------------
//使此对话框无标题
void __fastcall TForm1::CreateParams(TCreateParams &Params)
{
TForm::CreateParams(Params); //调用Form1的基本型态函数
Params.Style &= ~WS_CAPTION; //将标题位置删除
}
// -------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(Edit1->Text != "1234")
  {
  Application->MessageBox("密码不对喔！","",MB_OK);
  Edit1->SetFocus();
  }
else
  {
  Application->MessageBox("密码正确！","",MB_OK);
  Form1->Close();//引发Form1的OnDestroy事件
  }
}
//---------------------------------------------------------------------------
//用键盘单击Enter键，如同单击Button1按钮
void __fastcall TForm1::Edit1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if(Key == VK_RETURN	)
   Button1Click(Sender);
}
//---------------------------------------------------------------------------


