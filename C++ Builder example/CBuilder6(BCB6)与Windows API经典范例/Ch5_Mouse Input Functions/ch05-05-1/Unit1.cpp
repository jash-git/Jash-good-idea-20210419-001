//---------------------------------------------------------------------------
//目的：由鼠标右键移动按钮的简易做法
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
Color = (TColor)RGB(200,255,200);
Form1->Tag = 0;//当作移动按钮的计次器
Button1->Tag = 0;//当作正常按钮的计次器
}
//---------------------------------------------------------------------------
//对照按钮移动功能
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//按住Form1中间，如同按住Caption，可移动Form
::ReleaseCapture();
SendMessage(Form1->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{//当鼠标在按钮上单击右键，则可自由移动Button1位置
if(Button == mbRight)
   {
   //释放鼠标捕捉权
   ::ReleaseCapture();
   //送出重新定义的信息，使按钮具有移动、标题列性质
   Button1->Perform(WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
   //显示移动次数
   StaticText1->Color = (TColor)RGB(255,215,235);
   StaticText1->Caption = "这是第"+AnsiString(++Tag)+" 次移动按钮" +
                          "；再单击一次按钮，即使按钮恢复正常";
   }
else //显示按钮次数
   {
   StaticText1->Color = (TColor)RGB(220,255,185);
   StaticText1->Caption ="这是第 "+AnsiString(++(Button1->Tag))+"次单击按钮"+
                         "；再单击一次按钮，即使按钮恢复正常";
   }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormShow(TObject *Sender)
{
/*
   //释放鼠标捕捉权
   ::ReleaseCapture();
   //送出重新定义的信息，使按钮具有移动、标题栏性质
   Button1->Perform(WM_SYSCOMMAND, HTCAPTION, 0);
*/
}
//---------------------------------------------------------------------------

