//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//���õ��ñ������ȼ���Ϣ-----------------------------------------------------
const int CALL_ME_ID = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//��������ʱ����ע��Crtl+F2�ȼ�
::RegisterHotKey(Handle, CALL_ME_ID, MOD_CONTROL, VK_F2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//���ڿ�ݹ������ϵ�Project1����
::ShowWindow(Application->Handle,SW_HIDE);
//�ٽ�Project1����POP���ʵ��Ӵ���ȫ����������(��Form1)
::ShowOwnedPopups(Application->Handle,false);
}
//---------------------------------------------------------------------------
//����ر�ʱ�����ͷ�Crtl+F2��ݼ���ɾ����̬���ֶ���
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::UnregisterHotKey(Handle, CALL_ME_ID);
}
//---------------------------------------------------------------------------
//��׽Crtl+F2��ݼ��ͳ����Զ�����Ϣ
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{
//�Ƚ���Ϣ��Ĭ�ϴ���
TForm::Dispatch(&Msg);
//���ÿ�ݼ�����ʾProject1��Form1
::ShowWindow(Application->Handle, SW_SHOW);
::ShowWindow(Handle, SW_SHOW);
}
//---------------------------------------------------------------------------


