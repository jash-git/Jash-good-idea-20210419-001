//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "MessageDlg.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------
__fastcall TMainForm::TMainForm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void TMainForm::DrawFace(void)
{
   int iStartX,iStartY,iEndX,iEndY;
   int iOffSet;
   Canvas->Pen->Width=1 ;
   iOffSet=ClientHeight/15;
   Canvas->Rectangle(0,0,ClientWidth,ClientHeight);


   TColor BrushColor=TColor(RGB(193,224,242));
   TColor PenColor=clBlack;//TColor(RGB(166,182,193));
   iEndX= ClientWidth-iOffSet;
   iEndY= ClientHeight-iOffSet;
   
   iStartX=iOffSet;
   iStartY=iOffSet;
   Canvas->Pen->Width=2 ;
   Canvas->Pen->Color=PenColor;

   Canvas->Brush->Color=BrushColor ;
   Canvas->RoundRect(iStartX-3 ,iStartY-3,iEndX+3,iEndY+3,8,8);
   Canvas->Brush->Color=BrushColor;

   Canvas->Pen->Width=3 ;
   Canvas->Pen->Color=TColor(RGB(166,182,193));
   Canvas->RoundRect(iStartX ,iStartY,iEndX,iEndY,8,8);

}
//---------------------------------------------------------------------------
void __fastcall TMainForm::FormPaint(TObject *Sender)
{
   DrawFace();
}
//---------------------------------------------------------------------------
void __fastcall TMainForm::BtnOkClick(TObject *Sender)
{
    Close();        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::WMNCHitTest(TMessage &Msg)
{
   TPoint CurPos;
   GetCursorPos(&CurPos);

   if(GetAsyncKeyState(VK_LBUTTON)<0&&CurPos.x<Left+Width&&CurPos.y<Top+ClientHeight/10)
       Msg.Result=HTCAPTION;
   else
       Msg.Result=HTCLIENT;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MyMessage(TMessage &Msg)
{
   switch(Msg.WParam)
   {
        case LEFTBUTTON:
             ShowMessage("您单击了左按钮！");
             break;
        case RIGHTBUTTON:
             ShowMessage("您单击了右按钮！");
             break;
        default:
             break;
   }
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::BtnOpenClick(TObject *Sender)
{
    MessageForm->ShowModal();
}
//---------------------------------------------------------------------------

