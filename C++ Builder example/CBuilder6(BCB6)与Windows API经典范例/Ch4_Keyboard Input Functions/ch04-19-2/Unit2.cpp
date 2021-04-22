//---------------------------------------------------------------------------
//目的：单击Esc键，则自动输入一行有大小写、空格符的字符串
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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Memo1KeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
//默认字符串
AnsiString str = "This is a test!";
//声明字符递增变量，AnsiString第一个字符为str[1]
int pass = 1;
//若USER按下Esc键，则仿真输入字符串
if(Key == VK_ESCAPE)
  {//启动循环，仿真输入字符串
  while(pass <= str.Length())
    {
    char ch = str[pass];
    //将指定的字符转换成虚拟键代码
    SHORT vks =  ::VkKeyScan(ch);
    //测试&观看用
    //Memo1->Lines->Add(AnsiString(HIBYTE(vks))+ ":" +
    //                  AnsiString(LOBYTE(vks)));

    //若同时按下Shift键时，16-bit高位是1
    if((int)HIBYTE(vks)== 1)
       ::keybd_event((BYTE)VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT, 0), 0, 0 );
    //若同时按下Ctrl键时，16-bit高位是2
    if((int)HIBYTE(vks)== 2)
       ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), 0, 0 );
    //若同时按下Alt键时，16-bit高位是4
    if((int)HIBYTE(vks)== 4)
       ::keybd_event((BYTE)VK_MENU, (BYTE)::MapVirtualKey(VK_MENU, 0), 0, 0 );
    //按下字符键
    ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), 0, 0);

    //反序逐一放开组合键
    ::keybd_event((BYTE)vks, (BYTE)::MapVirtualKey( vks,0), KEYEVENTF_KEYUP, 0);
    if((int)HIBYTE(vks)== 4)
       ::keybd_event((BYTE)VK_MENU, (BYTE)::MapVirtualKey(VK_MENU, 0), KEYEVENTF_KEYUP,0 );
    if((int)HIBYTE(vks)== 2)
       ::keybd_event((BYTE)VK_CONTROL, (BYTE)::MapVirtualKey(VK_CONTROL, 0), KEYEVENTF_KEYUP,0 );
    if((int)HIBYTE(vks)== 1)
      ::keybd_event((BYTE)VK_SHIFT, (BYTE)::MapVirtualKey(VK_SHIFT, 0), KEYEVENTF_KEYUP,0 );
    //若完成输入字符，则移位至下一位
    pass++;
    }
  }
}
//---------------------------------------------------------------------------




