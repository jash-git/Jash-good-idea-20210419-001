//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::WMNotify(TMessage &Msg)
{
//ת����Ϣ����
LPNMHDR nmh = (NMHDR *)Msg.LParam;
//��ͨ������Ϣ������ToolBar��NM_CUSTOMDRAW��Ϣ
HWND HToolBar = ToolBar1->Handle;
if(nmh->code == NM_CUSTOMDRAW && nmh->hwndFrom == HToolBar)
  {
  //ת����NMTBCUSTOMDRAW�ṹ
  LPNMTBCUSTOMDRAW lptbcd = (NMTBCUSTOMDRAW *)Msg.LParam;
  //��������Ļ��˽ṹ<��������>��Ա��
  switch (lptbcd->nmcd.dwDrawStage)
  {
  //ȡ��ToolBar�ػ���Ϣ
  case CDDS_PREPAINT:
      {
      //ȡ��װ���豸��handle
      HDC HToolBarDC = lptbcd->nmcd.hdc;
      //ȡ��ToolBar��Χ
      RECT R;
      ::GetClientRect(HToolBar, &R);
      //ƴ��Image1ͼ��--�Զ��庯��--�����
      TileBmp(HToolBarDC,
              Image1->Picture->Bitmap->Width,
              Image1->Picture->Bitmap->Height,
              R,
              Image1->Picture->Bitmap->Canvas->Handle);
      //������Ϣ��֪ͨ���ڿ�ʼ����
      Msg.Result = CDRF_DODEFAULT;
      return;
      }
  }
  }
//��������Ϣ��ԭ��ʽ����
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//�Զ��庯��--����ƴ��ͼ��
void TForm1::TileBmp(HDC HDestDC, int w, int h,
                     RECT r, HDC HSourceDC)
{
for(int y = r.top; y < r.bottom; y = y + h)
   for(int x = r.left; x < r.right; x = x + w)
      ::BitBlt(HDestDC, x, y, w, h, HSourceDC, 0, 0, SRCCOPY);
}
//---------------------------------------------------------------------------


