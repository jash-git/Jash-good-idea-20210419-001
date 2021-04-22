//---------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop
#include <vcl\printers.hpp>
#include "Unit21_3.h"
//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TForm1 *Form1;
int PHeight,PWidth;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
	if (OpenDialog1->Execute()) {
    	Image1->Picture->LoadFromFile(OpenDialog1->FileName);
        Panel1->Caption="请选择开始打印文件........";
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
	TRect PrnRect,ImgRect;
    int CenterX,CenterY,X1,Y1,X2,Y2,SDiv;

	Panel1->Caption="い.....";
    Printer()->BeginDoc();

    PHeight=Printer()->PageHeight;
	PWidth=Printer()->PageWidth;
    CenterX=PWidth/2;
    CenterY=PHeight/2;

    SDiv=StrToInt(Edit1->Text);
    X1=CenterX-(PWidth / (SDiv*2));
    Y1=CenterY-(PHeight / (SDiv*2));
    X2=CenterX+(PWidth / (SDiv*2));
    Y2=CenterY+(PHeight / (SDiv*2));
    PrnRect=Rect(X1,Y1,X2,Y2);

    ImgRect=Rect(0,0,Image1->Width,Image1->Height);

    Printer()->Canvas->CopyRect(PrnRect,Form1->Canvas,ImgRect);
	Printer()->EndDoc();
    Panel1->Caption="打印中!!";
}
//---------------------------------------------------------------------------