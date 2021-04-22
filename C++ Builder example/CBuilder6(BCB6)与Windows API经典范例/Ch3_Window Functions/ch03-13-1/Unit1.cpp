//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-----取得子窗口的标准callback函数------------------------------------------
BOOL CALLBACK EnumChildProc(HWND, LPARAM);
bool __stdcall PressClickBtn(HWND, LPARAM );
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//唯有透过Button2按钮，才能执行Button3功能
Button3->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//删除Memo1所有文字
Memo1->Clear();
//逐一搜寻此窗口下的子窗口及对象handle，
//并执行EnumChildProc函数
::EnumChildWindows(
      Handle,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
}
//---------------------------------------------------------------------------
//将所有次一层子窗口都扫描过为止
BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM)
{
//若在此对象能取得密码，则还原成字符
if(SendMessage(hWnd, EM_GETPASSWORDCHAR, 0, 0))
  {
  char buf[256], text[256];
  ::GetClassName( hWnd, buf, sizeof(buf));
  ::GetWindowText( hWnd, text, sizeof(text));
  SendMessage( hWnd, EM_SETPASSWORDCHAR, 0, 0);
  //由Memo1显示出来
  Form1->Memo1->Lines->Add("类别："+AnsiString(buf));
  Form1->Memo1->Lines->Add("密码："+AnsiString(text));
  }
//此对象取得焦点后，即更新显示字符
::SetFocus(hWnd);
//逐一搜寻此窗口下的子窗口及对象handle，
//并执行EnumChildProc函数
::EnumChildWindows(
      hWnd,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//删除Memo1所有文字
Memo1->Clear();
//搜寻此窗口下的子窗口及对象handle
EnumChildWindows( Handle, (WNDENUMPROC)PressClickBtn, 0);
}
//---------------------------------------------------------------------------
//此非callback函数，但仍可放入callback函数(EnumChildWindows)，
//进行次一层对象搜寻
bool __stdcall PressClickBtn( HWND hWnd, LPARAM )
{
char buffer [200];
//若无handle，则跳离
if(!hWnd) return false;
//若此handle是Button3按钮，则仿真点按此钮，
//执行Button3功能
::GetClassName( hWnd, buffer, sizeof(buffer));
if(strcmp(buffer,"TButton") == 0 )
   {
   ::GetWindowText( hWnd, buffer, sizeof(buffer));
   if (strcmp(buffer,"Button3") == 0 )
      {
      //重设高低位内容，X为低位，Y为高位
      LPARAM pos = MAKELPARAM( 10, 10 );
      //送出单击按钮信息，
      PostMessage( hWnd, WM_LBUTTONDOWN, 0, pos );
      PostMessage( hWnd, WM_LBUTTONUP, 0, pos );
      return false;
      }
   }
//逐一搜寻此窗口下的子窗口及对象handle，
//并执行PressClickBtn函数
EnumChildWindows( hWnd, (WNDENUMPROC)PressClickBtn, 0 );
//执行下一扫描
return true;
}
//---------------------------------------------------------------------------
//Button2功能测试用
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Memo1->Color = (TColor)RGB(255,200,220);//粉红色
Memo1->Text = "Memo1改变底色！";
}
//---------------------------------------------------------------------------

