//---------------------------------------------------------------------------
//Ŀ�ģ�ȡ�ü�����ָ������״̬�����Կ��ƣ��ô˷���������Win9*ϵ��
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
{//������������Ϊboolֵ
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char key[256];
//ȡ�����ڼ���״̬
::GetKeyboardState((PBYTE)key);
//�ı� NUMLOCK�������ֵ����key[VK_CAPITAL]����Caps Lock��
key[VK_NUMLOCK] = (BYTE)Button1->Default;
//�������ڼ���״̬
::SetKeyboardState((PBYTE)key);
//��Ԫ����--��Memo1����ʾNum Lock��״̬
(Button1->Default)?(Caption="������Num Lock��<����>"):
                   (Caption="������Num Lock��<�ر���>");
//�����u����
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------


