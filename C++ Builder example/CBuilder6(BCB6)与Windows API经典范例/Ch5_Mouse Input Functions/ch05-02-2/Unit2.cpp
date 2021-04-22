//---------------------------------------------------------------------------
//Ŀ�ģ������ҷ�̶����(TrackBar)��ͷ��ʵʱ���ּ�ͷλ�õ���ʾ����
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
{//����TrackBarλ�á��ߴ�
TrackBar1->Width = ClientWidth;
TrackBar1->Top = (ClientHeight-TrackBar1->Height)/2;
TrackBar1->Left = 0;
TrackBar1->Max = 50;
//����ʼʱ���滻���Զ�����Ϣ����
OldTrackBarWP = TrackBar1->WindowProc;
TrackBar1->WindowProc = NewTrackBarWP;
//�½�һС��ʾ����
HintWindow = new THintWindow(this);
//ͻ��TrackBar��С��ʾ����
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------
//�������ʱ���ָ�ԭ����Ϣ����
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
TrackBar1->WindowProc = OldTrackBarWP;
delete HintWindow;
}
//---------------------------------------------------------------------------
//�Զ�����Ϣ����
void __fastcall TForm1::NewTrackBarWP(TMessage &Msg)
{//����굥��ʱ������׽סTrackBar
if(Msg.Msg == WM_LBUTTONDOWN)
  {
  ::SetCapture(TrackBar1->Handle);
  }
//���ƶ����ʱ�ҵ������״̬����������ʾ����
if(Msg.Msg == WM_MOUSEMOVE)
  {
  POINT P;
  ::GetCursorPos(&P);
  if(::GetCapture() == TrackBar1->Handle)
    {
    HintWindow->Invalidate();//���´��ڣ�����WM_PAINT��Ϣ
    //�����ʾ����ʾ���ڵ��ַ���
    AnsiString str = "�b "+AnsiString(TrackBar1->Position)+" λ��";
    //ȡ����ʾ���ڵ����ֽṹ���ݣ���������ʾ���ڷ�Χ
    TEXTMETRIC tm;
    ::GetTextMetrics(::GetDC(HintWindow->Handle), &tm);
    //ws���ַ����X�ַ���Ŀ(��ȥ���NULL�ַ�)
    int ws = (int)(tm.tmAveCharWidth*(str.Length()-1));
    //hs���ַ��߶ȣ��������Ƿ�����м��
    int hs = (int)(tm.tmHeight);// + tm.tmExternalLeading);
    RECT R = Rect(P.x, P.y, P.x+ ws, P.y + hs);
    //����ʾ����ƫ����������Ϸ�
    ::OffsetRect(&R, 0, -30);
    HintWindow->ActivateHint((TRect)R, str);//������ʾ����
    }
  }
//���������ſ�ʱ�����ͷ�TrackBar��׽Ȩ����ʾ����
if(Msg.Msg == WM_LBUTTONUP)
  {
  ::ReleaseCapture();
  HintWindow->ReleaseHandle();
  }
//�������ҷTraskBar�ƶ�ʱ��ʵʱ�ػ���ʾ������λ��
if(Msg.Msg == WM_PAINT && ActiveControl == TrackBar1)
  {
  HDC Hdc = ::GetDC(TrackBar1->Handle);
  RECT R = RECT(TrackBar1->ClientRect);
  HBRUSH HOldBrush = ::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));
  ::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
  ::SelectObject(Hdc, HOldBrush);
  ::ReleaseDC(TrackBar1->Handle, Hdc);
  }
//������Ϣ��ԭ��ʽ����
OldTrackBarWP(Msg);
}
//---------------------------------------------------------------------------

