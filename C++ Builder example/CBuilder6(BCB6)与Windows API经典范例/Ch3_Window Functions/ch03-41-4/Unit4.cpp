//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��̬�½�һ��POP�˵���������ʾ�����Panel1��Χ��λ��
popMenu = new TPopupMenu(this);
pop1 = new TMenuItem(this);
popMenu->Items->Add(pop1);
pop1->Caption = "����Panel1��Χ��";
//������������Ϊ����ֵ����
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{//ȡ��Panel1��ԭ����������
LONG ExStyle = ::GetWindowLong(Panel1->Handle, GWL_EXSTYLE);
//��Panel1��Ϊ͸��״̬
::SetWindowLong(Panel1->Handle, GWL_EXSTYLE,
                ExStyle | WS_EX_TRANSPARENT);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete pop1;
delete popMenu;
}
//---------------------------------------------------------------------------
//������ȡPanel1����������ʱ��ɾ��POP�˵��ϵ���ʾ�ַ���
void __fastcall TForm1::Panel1MouseUp(TObject *Sender, TMouseButton Button,
      TShiftState Shift, int X, int Y)
{
pop1->Caption = "";
}
//---------------------------------------------------------------------------
//������ȡPanel1����������ʱ��������λ�ò���ʾ��POPѡ���ϤW
void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
if(Button == mbLeft)
   popMenu->Popup(X+Left+Panel1->Left,Y+Top+Panel1->Top+25);
pop1->Caption = "����Panel1��Χ��X:"+AnsiString(X)+",Y:"+AnsiString(Y);
}
//---------------------------------------------------------------------------
//��Win32 Help�У���ѰButton Styles�ַ���������ȡ�������İ�ť��̬���
void __fastcall TForm1::Button1Click(TObject *Sender)
{//ȡ��Button1��ԭ����������
DWORD dwStyle = ::GetWindowLong(Button1->Handle, GWL_STYLE);
//�ɰ�ť�������л���ť�����������±�����״̬
if(Button1->Default)
  {dwStyle &= ~BS_LEFT & ~BS_TOP;
  dwStyle |= BS_RIGHT | BS_BOTTOM;
  Button1->Caption = "���²����";}
else
  {dwStyle &= ~BS_RIGHT & ~BS_BOTTOM;
  dwStyle |= BS_LEFT | BS_TOP;
  Button1->Caption ="���ϲ����";}
//���޸ĵ��������ݣ�����Button1����
::SetWindowLong(Button1->Handle, GWL_STYLE, dwStyle);
Button1->Refresh();//�ػ�Button1
//�л�����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

