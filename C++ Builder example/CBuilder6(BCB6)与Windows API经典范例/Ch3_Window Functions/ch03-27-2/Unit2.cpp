//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//标准的hook行程函数---------------------------------------------------------
UINT APIENTRY PageSetupHook(HWND, UINT, WPARAM, LPARAM);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//<设置打印格式>对话框结构声明
PAGESETUPDLG psd;
::ZeroMemory(&psd, sizeof(PAGESETUPDLG));
//设置结构成员
psd.lStructSize = sizeof(PAGESETUPDLG);
psd.hwndOwner = Handle;
//使打印格式hook函数有效
psd.Flags = PSD_ENABLEPAGESETUPHOOK;
//指派自定义的hook函数，进行自定义功能
psd.lpfnPageSetupHook = PageSetupHook;
//创造一新<设置打印格式>对话框
if(::PageSetupDlg(&psd))
  {
  HANDLE HMem;
  char device[MAX_PATH], driver[MAX_PATH], port[MAX_PATH];
  //user可直接打印
  Printer()->PrinterIndex = -1;
  Printer()->GetPrinter(device, driver, port, (int)HMem);
  Printer()->SetPrinter(device, driver, port, (int)psd.hDevMode);
  //此处即可撰写打印进行部分之程序代码....
  //Printer()->BeginDoc();
  //Printer()->Canvas->Rectangle(20,20,1000,1000);
  //Printer()->EndDoc();
  //释放全域性内存
  ::GlobalFree(HMem);
  ::GlobalFree(psd.hDevNames);
  }
}
//---------------------------------------------------------------------------
//当创造一新<设置打印格式>对话框时，即捕捉对话框初始化信息
UINT APIENTRY PageSetupHook(HWND HDlg, UINT uiMsg, WPARAM WParam,
    LPARAM LParam)
{
if(uiMsg == WM_INITDIALOG)
  {
  RECT FormRect, DialogRect;
  //取得信息转换成对话框结构
  LPPAGESETUPDLG lppsd = (LPPAGESETUPDLG)LParam;
  //取得Form1与对话框的范围
  ::GetWindowRect(lppsd->hwndOwner, &FormRect);
  ::GetWindowRect(HDlg, &DialogRect);
  //计算Form1与对话框的长宽
  int cxForm = FormRect.right - FormRect.left;
  int cyForm = FormRect.bottom - FormRect.top;
  int cxDialog = DialogRect.right - DialogRect.left;
  int cyDialog = DialogRect.bottom - DialogRect.top;
  //将对话框的移动至Form1居中出现
  ::MoveWindow(HDlg,
           (cxForm - cxDialog) / 2 + FormRect.left,
           (cyForm - cyDialog) / 2 + FormRect.top,
           cxDialog, cyDialog,
           true);
  }
return 0;
}
//---------------------------------------------------------------------------

