//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//设置调用本程序快捷键信息-----------------------------------------------------
const int CALL_ME_ID = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//程序启动时，即注册Crtl+F5快捷键
::RegisterHotKey(Handle, CALL_ME_ID, MOD_CONTROL, VK_F5);
//动态制作一文字对象，显示快捷键次数
label = new TLabel(Form1);
label->Parent = Form1;
label->Align = alClient;
label->Alignment = taCenter;
label->Color = (TColor)RGB(255,255,220);
label->Font->Size = 18;
label->Caption = "嗨！首次见面。";
//运用闲置属性作为递增变量
label->Tag = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//程序关闭时，即释放Crtl+F5快捷键与删除动态文字对象
::UnregisterHotKey(Handle, CALL_ME_ID);
delete label;
}
//---------------------------------------------------------------------------
//捕捉Crtl+F5快捷键送出的自定义信息
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{
//先将信息依默认处理
TForm::Dispatch(&Msg);
//检测Project1是否为最大化
if(::IsZoomed(Application->Handle))
  {//若是，则缩小到快捷工具栏上
  ::ShowWindow(Application->Handle, SW_MINIMIZE);
  label->Caption = "嗨！第"+AnsiString(++(label->Tag))+"次见面了。";
  ::SetForegroundWindow(Application->Handle);//将Project1带至最前面
  }
else//最大化Project1
  ::ShowWindow(Application->Handle, SW_MAXIMIZE);
}
//---------------------------------------------------------------------------

