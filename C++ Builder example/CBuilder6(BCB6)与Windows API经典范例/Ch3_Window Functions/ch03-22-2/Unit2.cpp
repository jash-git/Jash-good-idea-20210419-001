//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit2a.h"
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
//�����ڶ������ڣ��Թ����
void __fastcall TForm1::FormShow(TObject *Sender)
{
form = new TForm(this);
form->Caption = "���ǵڶ������ڣ�";
form->Width = 250; form->Height = 100;
form->Top = Top+Height; form->Left = Left+30;
form->Color = (TColor)RGB(255,210,110);
form->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
delete form;
}
//---------------------------------------------------------------------------
//������ת�Ƶ��ڶ��������ϣ��������Զ����ַ���
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ�ô�һ����handle����ת�ƽ���
HWND hwnd = ::GetNextWindow(Handle,GW_HWNDNEXT);
::SetFocus(hwnd);
//����ȡ�ý��㴰���ϣ������Զ����ַ���
RECT r = {30,30,250,250};
::DrawText(::GetDC(hwnd),"�ҵõ����㣡",12,&r,DT_SINGLELINE);
}
//---------------------------------------------------------------------------

