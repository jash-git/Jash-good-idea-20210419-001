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
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�ڴ򿪴�����Ѱ��<���ӵ��Ի���>��
//���У��򷵻���handle
HWND handle = NULL;
handle = ::FindWindow( NULL, "������");
//ȷ�������ӵ����Ի����Ѵ򿪣����ᵽ��ǰ����ʾ
if(::IsWindow(handle))
   {
   ::ShowWindow( handle, SW_SHOWMINIMIZED);
   ::ShowWindow( handle, SW_SHOWNORMAL);
   Caption = "�����ӵ����Ի����Ѵ򿪲���ʾ��";
   }
else
   Caption = "�����ӵ����Ի���δ�򿪲���ʾ��";
}
//---------------------------------------------------------------------------
