//---------------------------------------------------------------------------
//�����RichEdit1�У���tabs����(Ctrl+I ��ϼ�)ԭ�й��ܣ��ĳ��ܼ����ɫб�����幦��
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�� VK_I ����� I ��ֵ------------------------------------------------------
#define VK_I 0x49
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RichEdit1KeyPress(TObject *Sender, char &Key)
{
//����ϼ����������(tab)ʱ�� I ���ǵ���״̬����ɽ�����ع��ܸı�
if(Key == VK_TAB && (::GetAsyncKeyState(VK_I) < 0))
  {
  Key = 0;
  RichEdit1->SelAttributes->Style =
       RichEdit1->SelAttributes->Style << fsBold << fsItalic;
  RichEdit1->SelAttributes->Color = clRed;
  }
}
//---------------------------------------------------------------------------



