//---------------------------------------------------------------------------
//Ŀ�ģ�������ť���л��ޱ��ⴰ��λ�����С
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
{//�޸�Form1�����ͣ�ȥ��������
DWORD dwStyle = ::GetWindowLong(Handle, GWL_STYLE);
dwStyle &= ~WS_DLGFRAME;
::SetWindowLong(Handle, GWL_STYLE, dwStyle);
//�����������ԣ���Ϊ����ֵ�л�
Tag = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int x, y, w, h;
//������Ԫ���㣬�л�����λ����ߴ�ı���
(Tag)?
(w=200,h=200,x=0,y=0,Tag=false):
(w=200,h=150,x=Screen->Width-200,y=Screen->Height-150,Tag=true);
//���ô���λ����ߴ�
::SetWindowPos(Handle,HWND_TOPMOST,
               x, y, w, h,
               SWP_SHOWWINDOW);
}
//---------------------------------------------------------------------------
//�رմ���
void __fastcall TForm1::Button2Click(TObject *Sender)
{
Close();
}
//---------------------------------------------------------------------------


