//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//���õ��ñ������ݼ���Ϣ-----------------------------------------------------
const int CALL_ME_ID = WM_USER + 101;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��������ʱ����ע��Crtl+F5��ݼ�
::RegisterHotKey(Handle, CALL_ME_ID, MOD_CONTROL, VK_F5);
//��̬����һ���ֶ�����ʾ��ݼ�����
label = new TLabel(Form1);
label->Parent = Form1;
label->Align = alClient;
label->Alignment = taCenter;
label->Color = (TColor)RGB(255,255,220);
label->Font->Size = 18;
label->Caption = "�ˣ��״μ��档";
//��������������Ϊ��������
label->Tag = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//����ر�ʱ�����ͷ�Crtl+F5��ݼ���ɾ����̬���ֶ���
::UnregisterHotKey(Handle, CALL_ME_ID);
delete label;
}
//---------------------------------------------------------------------------
//��׽Crtl+F5��ݼ��ͳ����Զ�����Ϣ
void __fastcall TForm1::WMHotKey(TMessage &Msg)
{
//�Ƚ���Ϣ��Ĭ�ϴ���
TForm::Dispatch(&Msg);
//���Project1�Ƿ�Ϊ���
if(::IsZoomed(Application->Handle))
  {//���ǣ�����С����ݹ�������
  ::ShowWindow(Application->Handle, SW_MINIMIZE);
  label->Caption = "�ˣ���"+AnsiString(++(label->Tag))+"�μ����ˡ�";
  ::SetForegroundWindow(Application->Handle);//��Project1������ǰ��
  }
else//���Project1
  ::ShowWindow(Application->Handle, SW_MAXIMIZE);
}
//---------------------------------------------------------------------------

