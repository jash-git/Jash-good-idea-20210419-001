//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-字体对话框与打印对话框的callback函数----------------------------------------------------
UINT APIENTRY CFHookProc(HWND hdlg, UINT uiMsg,
                      WPARAM wParam, LPARAM lParam);
UINT APIENTRY PrintHookProc(HWND hdlg, UINT uiMsg,
                      WPARAM wParam, LPARAM lParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//LOGFONT结构为CHOOSEFONT结构的成员
LOGFONT lf;
::ZeroMemory(&lf, sizeof(&lf));
//设置CHOOSEFONT结构成员
CHOOSEFONT cf;
::ZeroMemory(&cf, sizeof(CHOOSEFONT));
cf.lStructSize = sizeof(CHOOSEFONT);
cf.hwndOwner = Handle;
cf.lpLogFont = &lf;
//指定callback函数CFHookProc
cf.lpfnHook = CFHookProc;
cf.Flags = CF_SCREENFONTS | CF_EFFECTS | CF_ENABLEHOOK | CF_SHOWHELP;
//打开字体对话框
if(::ChooseFont(&cf))
  {//改变StaticText1字体&尺寸
  StaticText1->Font->Handle =
            ::CreateFontIndirect(cf.lpLogFont);
    }
}
//---------------------------------------------------------------------------
//字体对话框CHOOSEFONT结构的callback函数
UINT APIENTRY CFHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam,
    LPARAM lParam)
{
//grp1,grp2,pshHelp,psh2定义在dlgs.h中，故需 #include <dlgs.h>
if (uiMsg == WM_INITDIALOG)
   {
   ::EnableWindow(::GetDlgItem(hdlg, grp1), false);//<效果>外框
   ::EnableWindow(::GetDlgItem(hdlg, grp2), false);//<范例>外框
   ::EnableWindow(::GetDlgItem(hdlg, pshHelp), false);//<说明>按钮
   ::EnableWindow(::GetDlgItem(hdlg, cmb2), false);//<字体样式>滚动条选单
   return true;
   }
return 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//PRINTDLG结构声明&清空内存
PRINTDLG pd;
::ZeroMemory(&pd, sizeof(PRINTDLG));
//设置PRINTDLG结构成员
pd.lStructSize = sizeof(PRINTDLG);
pd.hwndOwner = Handle;
pd.nCopies = 1;
pd.nFromPage = 0xFFFF;
pd.nToPage = 0xFFFF;
pd.nMinPage = 1;
pd.nMaxPage = 0xFFFF;
pd.Flags = PD_ENABLEPRINTHOOK;
pd.lpfnPrintHook = PrintHookProc;
//打开打印对话框
if(::PrintDlg(&pd))
  {
  //释放PRINTDLG结构中成员的全域性内存
  if(pd.hDevMode) ::GlobalFree(pd.hDevMode);
  if (pd.hDevNames) ::GlobalFree(pd.hDevNames);
  }
}
//---------------------------------------------------------------------------
//打印对话框PRINTDLG结构的callback函数
UINT APIENTRY PrintHookProc(HWND hdlg, UINT uiMsg, WPARAM wParam,
    LPARAM lParam)
{
if (uiMsg == WM_INITDIALOG)
  {//psh2定义在dlgs.h中，故需 #include <dlgs.h>
  //psh2即为<内容>按钮
  ::EnableWindow(::GetDlgItem(hdlg, chx1), false);//<打印到文件>选项
  ::EnableWindow(::GetDlgItem(hdlg, rad1), false);//<全部>选项
  ::EnableWindow(::GetDlgItem(hdlg, edt1), false);//<从>页数输入处
  return true;
  }
return 0;
}
//---------------------------------------------------------------------------



