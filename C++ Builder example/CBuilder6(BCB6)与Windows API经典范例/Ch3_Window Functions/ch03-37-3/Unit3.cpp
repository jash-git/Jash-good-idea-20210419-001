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
//�޸Ĵ˵��ַ�������������ʣ����������Ŵ�С
DWORD dwStyle = ::GetWindowLong(Edit1->Handle, GWL_STYLE);
::SetWindowLong(Edit1->Handle, GWL_STYLE, dwStyle | WS_SIZEBOX);
//�����˵��ַ������������Form1�ϵ�ʵ�ʳߴ��뷶Χ
//�Ա�USERֱ�ӵ������ַ��������������
::MoveWindow(Edit1->Handle, Edit1->Left, Edit1->Top,
             Edit1->Width, Edit1->Height + 1, true);
}
//---------------------------------------------------------------------------
//����걣�ּ�ͷͼ��ʱ��Edit1���ɱ���ҷ
void __fastcall TForm1::Edit1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Edit1->Cursor == crArrow )
  {//�ͷ�ԭ����겶׽״̬��
  //��ͬʱ�ͳ���굥��λ�õ�ͬ�ڴ��ڱ���������ҷ���ڵ�����
  ::ReleaseCapture();
  SNDMSG(Edit1->Handle, WM_NCLBUTTONDOWN, HTCAPTION, 0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{//�����Edit1���ƶ�ʱ���Ա��ּ�ͷͼ��
Edit1->Cursor = crArrow;
}
//---------------------------------------------------------------------------
