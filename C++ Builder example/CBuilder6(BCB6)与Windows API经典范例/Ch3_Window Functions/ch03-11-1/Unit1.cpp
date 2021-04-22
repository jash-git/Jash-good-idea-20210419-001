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
{
//运用闲置属性为打印对话框中组件的handle ID 存取处
Form1->Tag = 0;
//判定打开打印对话框次数
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//若ListBox1上选项都未被选，则默认值
Form1->Tag = 0;
//第二次单击按钮时，开始启动
//取得ListBox1上选项的数字部分
if(!Button1->Default)
 for(int i=0; i<ListBox1->Items->Count; i++)
   if(ListBox1->Selected[i])
     {
     int y=0;
     AnsiString str = ListBox1->Items->Strings[i];
     AnsiString pstr = ",";
     y = str.Pos(pstr);
     str = str.SubString(1,y-1);
     Form1->Tag = str.ToInt();
     }
//打开打印对话框
if(PrinterSetupDialog1->Execute())
  Caption = "请由ListBox选取数值，使指定键失效!";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::PrinterSetupDialog1Show(TObject *Sender)
{
HWND handle = PrinterSetupDialog1->Handle;
//第一次仅搜寻打印对话框上的对象ID
if(Button1->Default)
  {//自定义函数，内容见最后函数
  GetFontBoxItemsID_Text(handle);
  }
else//第二次后即可由user自行指定失效功能
  {
  //防止打印对话框的<取消>键失效，其余都执行
  if(Form1->Tag != 2)
    ::EnableWindow(::GetDlgItem(handle, Form1->Tag), false);
  }
Button1->Default = false;
}
//---------------------------------------------------------------------------
//取得打印对话框中所有组件的handle ID 与显示文字
void TForm1::GetFontBoxItemsID_Text(HWND handle)
{
//扩大搜寻范围
for(int a=-3000;a<3000;a++)
  if(::GetDlgItem(handle,a))//若获取到handle存在，则通过
    {
    char str[256];
    //取得此handle的文字，即可判别选项ID，并由ListBox1列出
    ::GetDlgItemText(handle,a,str,256);
    ListBox1->Items->Add(AnsiString(a)+","+AnsiString(str));
    }
}
//---------------------------------------------------------------------------


