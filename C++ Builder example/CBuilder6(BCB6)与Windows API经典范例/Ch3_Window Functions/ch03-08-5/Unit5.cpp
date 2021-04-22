//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit5.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��ťĬ��ֵ
Button1->Enabled = true;
//����Form1��Tag����Ϊ������
Tag = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�̶�ѡ��λ�óߴ�
RECT R = {30, 40, 150, 80};
//����һ������ʽ�������˵�--�Զ��庯��
HComboBox = CreateComboBox(Handle, 0, &R, CBS_DROPDOWNLIST);
//�½��˵�ѡ��
if(HComboBox)
  {
  for(int a=1;a<11;a++)
     {
     AnsiString str = "�� " + AnsiString(a) + " ѡ��";
     SNDMSG(HComboBox, CB_ADDSTRING, 0,
           reinterpret_cast<LPARAM>(str.c_str()));
     }
  //�ͳ���Ϣ������ѡ��߶�
  const int item_height = SNDMSG(HComboBox, CB_GETITEMHEIGHT, 0, 0);
  const int list_height = item_height * 10;
  //����������ѡ���ܳ���
  ::SetWindowPos(HComboBox, NULL, 0, 0, 150, 40 + list_height,
                 SWP_NOZORDER | SWP_NOMOVE | SWP_NOREDRAW);
    }
//ֻ������һ���������˵�
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//����һ�¹������˵�
HWND TForm1::CreateComboBox(HWND HParent, int nID, RECT *r,
    unsigned int uiStyle)
{
return ::CreateWindow ("COMBOBOX", "",
                       WS_CHILD | WS_VISIBLE | uiStyle,
                       r->left, r->top,
                       r->right - r->left,
                       r->bottom - r->top,
                       HParent, reinterpret_cast<HMENU>(nID),
                       HInstance, NULL);
}
//---------------------------------------------------------------------------
//���¹�����ѡ������Ϣ����
void __fastcall TForm1::NewComboBoxClick(TMessage &Msg)
{
//��handle�ǹ�����������������˵��ı�ѡȡ����Ϣ��
//CBN_SELCHANGE��Ϣ����Combo Box Messages��ѯ��
if (reinterpret_cast<HWND>(Msg.LParam) == HComboBox &&
    HIWORD(Msg.WParam) == CBN_SELCHANGE)
   {
   char str[256];
   ::GetWindowText(HComboBox,str,256);
   StaticText2->Caption = "����ѡ��<" + AnsiString(str) +
                           ">���ѡ��,��ѡ" +
                           AnsiString(Tag++) + "��";
   }
//������Ϣ����ԭ����ִ��
TForm::Dispatch(&Msg);
}
//---------------------------------------------------------------------------

