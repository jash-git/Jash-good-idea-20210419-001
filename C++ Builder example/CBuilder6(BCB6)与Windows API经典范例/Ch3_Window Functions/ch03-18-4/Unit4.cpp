//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//ComboBoxת�����Զ�����Ϣ
OldComboBoxWP = ComboBox1->WindowProc;
ComboBox1->WindowProc = NewComboBoxWP;
//����ComboBox1�ұ����¼�ͷ�İ����븡��״̬
FPushed = false;
}
//---------------------------------------------------------------------------
//���������ʱ���ظ�ԭ����Ϣ״̬
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
ComboBox1->WindowProc = OldComboBoxWP;
}
//---------------------------------------------------------------------------
//�Զ���ComboBox��Ϣ
void __fastcall TForm1::NewComboBoxWP(TMessage &Msg)
{
//�����������ComboBox1�ұ����¼�ͷ���������ػ涯�����A
//FPushedΪ��ʱ�������Ƴɰ���״̬
if(Msg.Msg == WM_LBUTTONDOWN) FPushed = true;
//FPushedΪαʱ�������Ƴɸ���״̬
if(Msg.Msg == WM_LBUTTONUP || Msg.Msg == CM_MOUSELEAVE)
  {
  FPushed = false;
  ComboBox1->Invalidate();//�����ػ涯��(WM_PAINT)
  }
if(Msg.Msg == WM_PAINT)
  {//
  PAINTSTRUCT ps;
  HDC Hdc = ::BeginPaint(ComboBox1->Handle, &ps);
  DrawComboBox(Hdc, FPushed);//�Զ��庯��
  //
  EndPaint(ComboBox1->Handle, &ps);
  Msg.Result = 0;
  return;
  }
//����ComboBox1��Ϣ��ԭ��ʽ����
OldComboBoxWP(Msg);
}
//---------------------------------------------------------------------------
//����ComboBox1--�Զ�����Ϣ
void TForm1::DrawComboBox(HDC Hdc, bool Pushed)
{
//ȡ��ComboBox1��Χ�ߴ�
RECT R;
::GetClientRect(ComboBox1->Handle, &R);
//ѡȡ<ȥ������>������ComboBox1��DC��
::SelectObject(Hdc, ::GetStockObject(NULL_BRUSH));

//��ʼ������ComboBox1����
LOGBRUSH lb;
lb.lbColor = RGB(255,220,140);
::SelectObject(Hdc, ::CreateBrushIndirect(&lb));
::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);
//�����ƿ�Χ����ͬʱ����2��λͼ
::InflateRect(&R, -2, -2);
lb.lbColor = RGB(160,220,255);
::SelectObject(Hdc, ::CreateBrushIndirect(&lb));
//::SelectObject(Hdc, ::GetStockObject(BLACK_PEN));
::Rectangle(Hdc, R.left, R.top, R.right, R.bottom);

//ȡ���ұ����¼�ͷ�Ŀ�ȣ����������Χ
int btnWidth = ::GetSystemMetrics(SM_CXVSCROLL);
RECT BtnRect = {R.right-btnWidth+2, R.top+2,
                R.right-2, R.bottom-2};

//�ж��������ұ����¼�ͷ�İ����븡��״̬
unsigned int style = DFCS_SCROLLCOMBOBOX;
if (Pushed) style = style | DFCS_PUSHED;
else style = style | DFCS_FLAT;
//�����ұ����¼�ͷ������
if (!ComboBox1->Enabled) style = style | DFCS_INACTIVE;

//����ǰ�����ã������ұ����¼�ͷ��Χ
::DrawFrameControl(Hdc, &BtnRect, DFC_SCROLL, style);
}
//---------------------------------------------------------------------------

