//---------------------------------------------------------------------------
//Ŀ�ģ���סImage1��ҷʱ��ʵ���ǲ�׽��Image1�µĶ�̬Panel1����
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
{//Ĭ�ϱ�����ɫ��������ʾЧ��
Color = (TColor)RGB(200,255,200);
//��Image1����һ����ҷ����ƽ̨
panel = new TPanel(this);
panel->Parent = Form1;
//panel�߿��ǿ
panel->BevelInner = bvLowered;
panel->BevelOuter = bvLowered;
//���½�Panel����������
panel->Hide();
//����panel�� WM_ERASEBKGND ��Ϣ����
OldPanelWP = panel->WindowProc;
panel->WindowProc = NewPanelWP;
}
//---------------------------------------------------------------------------
//�����򱻴ݻ�ʱ���ͷ�panel�ڴ�
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
panel->WindowProc = OldPanelWP;
delete panel;
}
//---------------------------------------------------------------------------
//�ų�WM_ERASEBKGND��Ϣ
void __fastcall TForm1::NewPanelWP(TMessage &Msg)
{
if (Msg.Msg != WM_ERASEBKGND)
     OldPanelWP(Msg);
}
//---------------------------------------------------------------------------
//��갴סImage1ʱ��������panel
void __fastcall TForm1::Image1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
//����panel
panel->Show();
oldX = X;
oldY = Y;
//����panel����״̬
panel->Left = Image1->Left-2;
panel->Top = Image1->Top-2;
panel->Height = Image1->Height+4;
panel->Width = Image1->Width+4;
panel->Visible = true;

//����갴סImage1ʱ��ʵ�����ǰ�סpanel
::SetCapture(panel->Handle);
Image1->Parent = panel;
Image1->Left = 2;
Image1->Top = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//����������סImage1�ƶ�ʱ��ʵ�����ǰ�סpanel�ƶ�
if (Shift.Contains(ssLeft))
    {
    panel->Left = panel->Left + (X - oldX);
    panel->Top = panel->Top + (Y - oldY);
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Image1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
//�ͷ�panel����겶׽
::ReleaseCapture();
//����panel��Image1��
panel->Visible = false;
Image1->Left = panel->Left;
Image1->Top = panel->Top;
Image1->Parent = this;
}
//---------------------------------------------------------------------------

