//---------------------------------------------------------------------------
//Ŀ�ģ�������Ҽ��ƶ���ť�ļ�������
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
Form1->Tag = 0;//�����ƶ���ť�ļƴ���
Button1->Tag = 0;//����������ť�ļƴ���
}
//---------------------------------------------------------------------------
//���հ�ť�ƶ�����
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{//��סForm1�м䣬��ͬ��סCaption�����ƶ�Form
::ReleaseCapture();
SendMessage(Form1->Handle,WM_NCLBUTTONDOWN,HTCAPTION,0);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{//������ڰ�ť�ϵ����Ҽ�����������ƶ�Button1λ��
if(Button == mbRight)
   {
   //�ͷ���겶׽Ȩ
   ::ReleaseCapture();
   //�ͳ����¶������Ϣ��ʹ��ť�����ƶ�������������
   Button1->Perform(WM_SYSCOMMAND, SC_MOVE + HTCAPTION, 0);
   //��ʾ�ƶ�����
   StaticText1->Color = (TColor)RGB(255,215,235);
   StaticText1->Caption = "���ǵ�"+AnsiString(++Tag)+" ���ƶ���ť" +
                          "���ٵ���һ�ΰ�ť����ʹ��ť�ָ�����";
   }
else //��ʾ��ť����
   {
   StaticText1->Color = (TColor)RGB(220,255,185);
   StaticText1->Caption ="���ǵ� "+AnsiString(++(Button1->Tag))+"�ε�����ť"+
                         "���ٵ���һ�ΰ�ť����ʹ��ť�ָ�����";
   }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::FormShow(TObject *Sender)
{
/*
   //�ͷ���겶׽Ȩ
   ::ReleaseCapture();
   //�ͳ����¶������Ϣ��ʹ��ť�����ƶ�������������
   Button1->Perform(WM_SYSCOMMAND, HTCAPTION, 0);
*/
}
//---------------------------------------------------------------------------

