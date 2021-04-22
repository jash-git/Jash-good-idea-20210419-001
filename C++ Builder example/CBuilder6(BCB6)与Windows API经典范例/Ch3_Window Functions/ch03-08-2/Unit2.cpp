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
//�°�ť��Ĭ�ϱ����밴ť����
str = "YES! ���Ƕ����Ҳ�ɫ�İ�ť��";
//Ĭ���°�ť�ߴ硢λ��
RECT btR = {0, 0, 100, 100};
//����һ���������֡����ƶ�����ɫ���֡���ɫ�����İ�ť����
HStatic = ::CreateWindow("BUTTON", str.c_str(),
                         WS_CAPTION | WS_VISIBLE | WS_CHILD
                         | SS_CENTER | WS_SIZEBOX
                         | BS_MULTILINE | BS_OWNERDRAW,
                         btR.left, btR.top,
                         btR.right - btR.left, btR.bottom - btR.top,
                         Handle, NULL, HInstance, NULL);
}
//---------------------------------------------------------------------------
//�°�ť���ػ�ʱ�����ͳ�����Ϣ
void __fastcall TForm1::WMDrawItem(TMessage &Msg)
{
//<1>������Ϣȡ��������
//��LParam��Ϣָ��ťLPDRAWITEMSTRUCT�ṹ
LPDRAWITEMSTRUCT lpdis = (DRAWITEMSTRUCT *)Msg.LParam;
//�����°�ť��������Ĭ����Ϣ����
if (lpdis->hwndItem != HStatic)
   {
   TForm::Dispatch(&Msg);
   return;
   }
//��DRAWITEMSTRUCT�ṹȡ��������Ϣ
HDC Hdc = lpdis->hDC;
RECT R = lpdis->rcItem;
//ȡ�ð�ť�Ƿ�����굥��ѡȡ״̬
unsigned int uState = lpdis->itemState;
//���ð�ťΪ����״̬
unsigned int uDrawSytle = DFCS_BUTTONPUSH;
//��ť���ֵ�ƫ����
int text_offset = 0;
//����ť����굥��ѡȡ״̬������س��ְ��ݹ�Ӱ��
//����ƫ���������·���3λͼ
if (uState & ODS_SELECTED)
  {
  uDrawSytle = uDrawSytle | DFCS_PUSHED;
  text_offset+=3;
  }
//<2>�Ȼ��ư�ť������߿�
//��������Ƴ�ָ����̬��״̬
::DrawFrameControl(Hdc, &R, DFC_BUTTON, uDrawSytle);
//��ť�����ķ�Χ
RECT r = {R.left+3,R.top+3,
          R.right-3,R.bottom-3};
//����һ�²�ɫ���ʣ�������ť����
HBRUSH hbr = ::CreateSolidBrush(RGB(200,0,200));
::FillRect(Hdc, &r, hbr);
//<3>�ٻ��ư�ť����
//���������屳��Ϊ͸��״̬
unsigned int iOldMode = ::SetBkMode(Hdc, TRANSPARENT);
//ȷ��ƫ����
::OffsetRect(&r, text_offset, text_offset);
//��������ɫ��
::SetTextColor( Hdc, RGB(180,230,255));
//::SetBkColor( Hdc, ColorToRGB(clBlue));
//�ڰ�ť�ϻ������
::DrawText(Hdc, str.c_str(),
           str.Length(),
           &r,
           DT_CENTER | DT_VCENTER | DT_WORDBREAK);
//�ָ�ԭ�б���
::SetBkMode(Hdc, iOldMode);
Msg.Result = true;
}
//---------------------------------------------------------------------------
