//---------------------------------------------------------------------------
//目的：单击Esc键，则模拟键入贴上(Ctrl+V)组合键相同功能
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//先制作出一字符串对象，复制至剪贴区中，以备执行仿真<贴上>功能
TCustomEdit *str = new TCustomEdit(this);
str->Parent = Form1;
str->Text = "模拟键入贴上(Ctrl+V)组合键";
str->SelectAll();
str->CopyToClipboard();
delete str;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyPress(TObject *Sender, char &Key)
{
//若单击Esc键，则如同单击Ctrl+V组合键
if(Key == VK_ESCAPE)
  {
  //将'V'字符转换成虚拟键代码
  SHORT vks =  ::VkKeyScan('V');
  //单击 Ctrl键
  ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), 0, 0 );
  //单击V键
  ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), 0, 0);
  //反序放开组合键
  ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), KEYEVENTF_KEYUP, 0);
  ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP,0 );
  }
}
//---------------------------------------------------------------------------


