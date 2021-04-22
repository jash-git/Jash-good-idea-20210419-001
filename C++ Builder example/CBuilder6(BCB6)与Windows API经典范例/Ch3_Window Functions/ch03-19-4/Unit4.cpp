//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//此函数赋予WNDCLASS结构的信息处理-------------------------------------------
LONG APIENTRY MyWndProc(HWND HWnd, UINT Msg,
                        WPARAM WParam, LPARAM LParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//将闲置属性作为新建窗口的变量
Tag = 0;
}
//---------------------------------------------------------------------------
//单击按钮后，即由自定义函数新建一自定义窗口
void __fastcall TForm1::Button1Click(TObject *Sender)
{
CreateWindowForm(::GetDesktopWindow());
}
//---------------------------------------------------------------------------
//自定义函数--新建一自定义窗口
HWND TForm1::CreateWindowForm(HWND HWndParent)
{
//先规划出一新窗口类别WNDCLASS结构数据
WNDCLASS FormClass;
FormClass.style = CS_HREDRAW | CS_VREDRAW;
FormClass.lpfnWndProc = (WNDPROC)MyWndProc;
FormClass.cbClsExtra = 0;
FormClass.cbWndExtra = 0;
FormClass.hInstance = HInstance;
//用自定义图示
ICONINFO icon = {true,
                 NULL, NULL,
                 Image2->Picture->Bitmap->Handle,
                 Image1->Picture->Bitmap->Handle
                 };
FormClass.hIcon = CreateIconIndirect(&icon);
//FormClass.hIcon = Application->Icon->Handle;//BCB默认图示
FormClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
//设置背景颜色
FormClass.hbrBackground = ::CreateSolidBrush(RGB(255,210,110));
FormClass.lpszMenuName = "MyForm";
FormClass.lpszClassName = "MyForm";
//登录一新窗口类别(MyForm)
::RegisterClass(&FormClass);
AnsiString name = "MyForm_" + AnsiString(++Tag);
//依附MyForm窗口类别，建立一新窗口
HWND HForm = ::CreateWindowEx(WS_EX_LTRREADING,
                              "MyForm", name.c_str(),
                              WS_OVERLAPPEDWINDOW,
                              Tag*20,Tag*20,
                              150, 150,
                              HWndParent, NULL,
                              HInstance, NULL);
//若无法建立，则停止继续
if (!HForm) return NULL;
//若建立出，则显示至窗口桌面
::ShowWindow(HForm, SW_SHOW);
::UpdateWindow(HForm);
return HForm;
}
//此函数为WNDCLASS结构的信息处理---------------------------------------------
LONG APIENTRY MyWndProc(HWND HWnd, UINT Msg,
                       WPARAM WParam, LPARAM LParam)
{
//仍沿用原默认处理信息
return DefWindowProc(HWnd, Msg, WParam, LParam);
}
//---------------------------------------------------------------------------



