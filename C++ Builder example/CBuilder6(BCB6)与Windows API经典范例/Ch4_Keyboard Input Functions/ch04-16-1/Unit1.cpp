//---------------------------------------------------------------------------
//Ŀ�ģ���ϵͳ��¼�Զ����ȼ�������Ctrl+F1 �������ɵ��ó���ִ�й��ܯ�
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Ĭ���ȼ���Ϣ����ֵ---------------------------------------------------------
const int ID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//������̵߳�¼�ȼ�
//���˳����״̬������������һ����
//����Ctrl+F1 �������ɵ��ô˳���ȡ�ý��㣬����������ǰ��
::RegisterHotKey(Handle, ID, MOD_CONTROL, VK_F1);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{//�ͷŴ��̵߳�¼֮�ȼ�
::UnregisterHotKey(Handle, ID);
}
//---------------------------------------------------------------------------
//��׽�Զ����ȼ���Ϣ
void __fastcall TForm1::HotKeys(TMessage &Msg)
{//����Ϣ����������������
TForm::Dispatch(&Msg);
//���˳����Ѵ򿪣����ں��棻��������ǰ��
::SetForegroundWindow(Handle);
//���˳�������С��״̬����ָ�ԭ��״̬
if (::IsIconic(Application->Handle))
   ::ShowWindow(Application->Handle, SW_RESTORE);
else
   ::ShowWindow(Application->Handle, SW_MINIMIZE);
}
//---------------------------------------------------------------------------

