//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�Զ����WM_HOTKEY��ݼ���Ϣ----------------------------------------------------
const int WM_MYID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//��¼Crtl+F1��ݼ����ɵ���Form1ִ�п�ݼ����ܯ�
::RegisterHotKey(Handle, WM_MYID, MOD_CONTROL, VK_F1);
Label1->Tag = 1;//�����������ԣ���Ϊ��������
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//�������ʱ�����Crtl+F1��ݼ����ܯ�
::UnregisterHotKey(Handle, WM_MYID);
}
//---------------------------------------------------------------------------
//��׽�Զ����WM_HOTKEY��ݼ���Ϣ����С��ظ�����λ��
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{//����С���ڻظ�ԭ��λ��
if(::OpenIcon(Handle))
  Label1->Caption = "�ˣ���"+AnsiString(++(Label1->Tag))+"�μ����ˡ�";
else
   ::ShowWindow(Handle, SW_MINIMIZE );
//����Ϣ��Ĭ�ϴ���
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
