//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//颜色变量先默认为铭黄色
fboxColor = (unsigned long)RGB(255,220,100);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//新建一自定义的字体对话框
TMyFontDialog *fbox = new TMyFontDialog(this);
//打开对话框，并执行设置，修改Memo1字体和颜色
if(fbox->Execute())
  {
  Memo1->Font = fbox->Font;
  Memo1->Font->Color = (TColor)fboxColor;
  }
delete fbox;
}
//---------------------------------------------------------------------------
//以下皆为自定义字体对话框函数设置
//---------------------------------------------------------------------------
//处理当打开字体对话框与接收和处理字体对话框选项的信息
void __fastcall TMyFontDialog::WndProc(TMessage& Msg)
{
switch (Msg.Msg)
  {
  //当打开字体对话框时，增加颜色选项，颜色对话框按钮
  case WM_INITDIALOG:
     {
     //以此自定义函数即取得<颜色选择滚动条>的handle ID = 1139
     //请见最后一个函数
     //GetFontBoxItemsID_Text(Handle);
     //<1> 在<颜色选择滚动条>中新建颜色选项
     COLORREF color = (COLORREF)Form1->fboxColor;
     HWND HColorCombo = ::GetDlgItem(Handle, 1139);
     int index = SNDMSG(HColorCombo, CB_INSERTSTRING, 0,
                       reinterpret_cast<LPARAM>("自定义颜色"));
     SNDMSG(HColorCombo, CB_SETITEMDATA, index, color);
     SNDMSG(HColorCombo, CB_SETCURSEL, index, 0);
     //<2>新建颜色对话框按钮
     int width, height;
     RECT R;
     //若user需要，则可重设字体对话框尺寸和新按钮位置
     if (::GetWindowRect(Handle, &R))
        {
        width = R.right - R.left;
        height = R.bottom - R.top;
        ::SetWindowPos(Handle, NULL, 0, 0,
                       width , height,
                       SWP_NOMOVE | SWP_NOZORDER);
        }
     //建立一新自定义按钮
     HNewBtn = ::CreateWindow("BUTTON", "自定义颜色...",
                            WS_CHILD | WS_VISIBLE | BS_LEFT ,
                            20, height-65, 85, 25,
                            Handle, NULL, HInstance, NULL);
     break;
     }
  //接收和处理字体对话框选项功能
  case WM_COMMAND:
     {
     //单击<自定义色彩>按钮时，则打开色彩对话框
     if (reinterpret_cast<HWND>(Msg.LParam) == HNewBtn &&
         Msg.WParamHi == BN_CLICKED)
        {
        ShowColorDialog();
        Form1->fboxColor = (unsigned long) Font->Color;
        }
     //若直接单击<颜色选择滚动条>颜色选项时
     HWND HColorCombo = ::GetDlgItem(Handle, 1139);
     if (reinterpret_cast<HWND>(Msg.LParam) == HColorCombo &&
         Msg.WParamHi == BN_CLICKED)
        {
        //重设颜色选择滚动条<自定义颜色>选项颜色
        COLORREF color = (COLORREF)SNDMSG(HColorCombo, CB_GETITEMDATA, 0, 0);
        Font->Color = (TColor) color;
        //将选取的色彩传给色彩共同变量
        Form1->fboxColor = (unsigned long) color;
        }
     break;
     }
  }
//其余信息依照原设置执行
TFontDialog::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//当单击<自定义颜色>按钮时
void __fastcall TMyFontDialog::ShowColorDialog()
{
//在内存中配置一个颜色对话框空间
std::auto_ptr<TColorDialog> ColorDialog(new TColorDialog(NULL));
//打开颜色对话框，执行user设置
if (ColorDialog->Execute())
    {
    COLORREF color = ColorToRGB(ColorDialog->Color);
    //取得字体对话框的颜色选择滚动条<ComboBox> handle
    HWND HColorCombo = ::GetDlgItem(Handle, 1139);
    //重设颜色选择滚动条<自定义色彩>选项颜色
    SNDMSG(HColorCombo, CB_SETITEMDATA, 0, color);
    SNDMSG(HColorCombo, CB_SETCURSEL, 0, 0);
    //更改字体对话框文字颜色并传给颜色共同变量
    Font->Color = ColorDialog->Color;
    Form1->fboxColor = (unsigned long) Font->Color;
    }
}
//---------------------------------------------------------------------------
//取得字体对话框中所有组件的handle ID 与显示文字
//以此函数即取得<颜色选择滚动条>的handle ID = 1139，
//填入与完成本程序新建自定义颜色功能
void TForm1::GetFontBoxItemsID_Text(HWND handle)
{
//扩大搜寻范围
for(int a=-3000;a<3000;a++)
  if(::GetDlgItem(handle,a))//若获取到handle存在，则通过
    {
    char str[256];
    //取得此handle的文字，即可判别选项ID，并由Memo1列出
    ::GetDlgItemText(handle,a,str,256);
    Form1->Memo1->Lines->Add(AnsiString(a)+","+AnsiString(str));
    }
}
//---------------------------------------------------------------------------


