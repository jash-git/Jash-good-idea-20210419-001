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
//��Form1�����а�ť������ͬ��Form1��OnMouseMove�¼�
for(int i=0;i<ComponentCount; i++)
   {
   TButton *btn = (TButton *)Components[i];
   btn->OnMouseMove = Form1->OnMouseMove;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
POINT P;
char str[256];
//ȡ������������ڵ�λ��
::GetCursorPos(&P);
//ȡ�����λ�õĴ���handle
HWND hWnd = ::WindowFromPoint(P);
if(hWnd)
  {//�˴��ڼ�ȡ�ý�������ʾ������ַ���
  ::SetFocus(hWnd);
  ::GetWindowText(hWnd,str,256);
  Caption = "������_"+AnsiString(str)+"_ȡ�ý���";
  }
}
//---------------------------------------------------------------------------

