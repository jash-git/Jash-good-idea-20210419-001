//---------------------------------------------------------------------------
//�ģ���׽������״̬����ס���ڵı���������ͬ�ڰ�ס������������ҷ�ƶ�
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
void __fastcall TForm1::WMNCHitTest(TMessage &Msg)
{
//ȡ��������Ϣ���
LRESULT DefResult = ::DefWindowProc( Handle, Msg.Msg,
                                     Msg.WParam, Msg.LParam);
//���������ڴ��ڱ�����ס���ţ���ͬ��ס������������ҷ�ƶ�Form1
if(::GetAsyncKeyState(VK_LBUTTON) < 0
    && (DefResult == HTCLIENT))
    {//��ס���ڱ���ʱ����ͬ��ס������
    Msg.Result = HTCAPTION;
    Color = (TColor)RGB(255,170,210);//�ۺ�ɫ
    }
else//��������Ϣ�վ�
    {
    Msg.Result = DefResult;
    Color = (TColor)RGB(200,255,150);//����ɫ
    }
}
//---------------------------------------------------------------------------


