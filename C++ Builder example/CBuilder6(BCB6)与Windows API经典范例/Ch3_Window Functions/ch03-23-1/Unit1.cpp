//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//ԭ<��>�Ի����˵�����ִ���-------------------------------------------
#define IDLOOKIN 1091
#define IDFILENAME 1090
#define IDFILETYPE 1089
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
//��ԭ<��>�Ի�������
void __fastcall TForm1::Button1Click(TObject *Sender)
{
OpenDlg = new TOpenDialog(this);
//���Զ���OnShow����ָ�ɸ�OpenDlg
OpenDlg->OnShow = AllOpenDlgShow;
OpenDlg->Title = "�ı��˵Ĵ򿪶Ի���";
OpenDlg->Execute();
delete OpenDlg;
}
//---------------------------------------------------------------------------
//�Զ���OnShow�������ı�˵������
void __fastcall TForm1::AllOpenDlgShow(TObject *Sender)
{
//ȡ�ð�ť��ĸ���ڣ�������ָ������ı������֦r
HWND hd = ::GetParent(OpenDlg->Handle);
::SetDlgItemText( hd, IDOK, "ѡ�������");
::SetDlgItemText( hd, IDCANCEL, "�����ı䣡");
//�ͳ��ı�������ֵ���Ϣ
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDLOOKIN, (LPARAM)"�ҵ�������>");
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDFILENAME, (LPARAM)"�ҵ��ļ�����>");
SendMessage( hd, CDM_SETCONTROLTEXT,
             IDFILETYPE, (LPARAM)"�ҵ��ļ�����>");
}
//---------------------------------------------------------------------------
//����<��>�Ի��򣬲�����ʾ
void __fastcall TForm1::Button2Click(TObject *Sender)
{
TMySelectDlg *msd = new TMySelectDlg(this);
msd->Execute();
delete msd;
}
//---------------------------------------------------------------------------
//����<�򿪾��ļ�>�Ի������Ϣ������
void __fastcall TMySelectDlg :: WndProc(Messages::TMessage &Msg)
{
//��Ϣ����ԭ��ʽ����
TOpenDialog::WndProc(Msg);
//ȡ�ð�ť��ĸ���ڣ�������˶���ı������֦r
::SetDlgItemText(::GetParent(Handle), IDOK, "&Select?");
::SetDlgItemText(::GetParent(Handle), IDCANCEL, "&Cancel!");
}
//---------------------------------------------------------------------------

