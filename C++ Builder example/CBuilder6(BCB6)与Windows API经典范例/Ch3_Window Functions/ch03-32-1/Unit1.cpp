//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Ĭ�Ͽ�ݼ���Ϣ����ֵ---------------------------------------------------------
const int WM_SELFHOTKEY = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//������̵߳�¼��ݼ�
::RegisterHotKey(Handle, WM_SELFHOTKEY, MOD_CONTROL, VK_F2);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//�ͷŴ��̵߳�¼֮��ݼ�
::UnregisterHotKey(Handle, WM_SELFHOTKEY);
}
//---------------------------------------------------------------------------
//��׽�Զ����ݼ���Ϣ
void __fastcall TForm1::HotKeys(TWMHotKey &Msg)
{
//����Ϣ����������������
TForm::Dispatch(&Msg);
//��׽���Զ����ݼ���ϢCrtl+F2��
if(Msg.HotKey == WM_SELFHOTKEY)
  {//�ж��Ƿ�Ϊ��С�����ڣ�����ʾ����С����
  if(::IsIconic(Application->Handle))
     ::ShowWindow(Application->Handle, SW_RESTORE);
  else
     ::ShowWindow(Application->Handle, SW_MINIMIZE);
  }
}
//---------------------------------------------------------------------------
