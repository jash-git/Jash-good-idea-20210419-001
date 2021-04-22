//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include <vcl\printers.hpp>
#include "Unit21_2.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString Fname;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    if (OpenDialog1->Execute()) {
    	Fname=OpenDialog1->FileName;
        Label1->Caption="准备打印 "+Fname;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    AnsiString PageNum;
    int Ctr,i,PHeight,LineSpace,x;

    Printer()->BeginDoc();   // 启动一个新的印表工作
    x=0;             	     // 打印的 x 坐标
    Ctr=1;                   // 计算打印行数的变量
    PHeight=Printer()->PageHeight;
    LineSpace=PHeight / 60;
    PageNum=IntToStr(Printer()->PageNumber);
    Label1->Caption="现在正在印第"+PageNum+"页数据.....";
    Memo1->Lines->LoadFromFile(Fname);  // 读取打印的文本文件
	for(i=0; i<(Memo1->Lines->Count); i++) {  // 把文本文件一行一行打印出来
    	Printer()->Canvas->TextOut(0,x,Memo1->Lines->Strings[i]);
		x+=LineSpace;
        Ctr++;
        if (Ctr > 59) {		// 如果超过60行就跳页
        	Printer()->NewPage();  // 送出跳页句柄
			x=0;
            Ctr=0;
            PageNum=IntToStr(Printer()->PageNumber);
		    Label1->Caption="现在正在印第"+PageNum+"页数据.....";
        }
    }
    Printer()->EndDoc();
    Label1->Caption="打印完成！一共印了"+PageNum+"页。";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

