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
}
//---------------------------------------------------------------------------
//�޸�Form1��������
void __fastcall TForm1::CreateParams(TCreateParams &Params)
{
TForm::CreateParams(Params);
Params.ExStyle = Params.ExStyle | WS_EX_APPWINDOW;
Params.WndParent = ::GetDesktopWindow();
}
//---------------------------------------------------------------------------
//��Ϣ����ԭ��ʽ����
void __fastcall TForm1::WMSysCommand(TMessage &Msg)
{
DefaultHandler(&Msg);
}
//---------------------------------------------------------------------------
//��Form1��С����ݹ������C
void __fastcall TForm1::Button1Click(TObject *Sender)
{
::ShowWindow(Handle, SW_MINIMIZE);
}
//---------------------------------------------------------------------------

