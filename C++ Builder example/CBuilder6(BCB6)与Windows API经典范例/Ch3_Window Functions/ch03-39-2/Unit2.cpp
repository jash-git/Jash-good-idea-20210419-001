//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
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
void __fastcall TForm1::FormClick(TObject *Sender)
{
//ȡ����Ļ�����λ��
TPoint p;//��ͬ POINT p; �ṹ����
p.x = 0; p.y = 0;//��ֵ�ȹ���
p = ClientToScreen(p);
//��POP�˵�����ǿ�ִ�е�
if(PopupMenu1)
  {//����ȷ��Form1����ǰ�����
  ::SetForegroundWindow(Handle);
  //��ָ��λ����ʾPOP�˵����
  DWORD dwCmd = ::TrackPopupMenu(PopupMenu1->Handle,
                   TPM_LEFTALIGN | TPM_TOPALIGN |
                   TPM_NONOTIFY | TPM_RETURNCMD,
                   p.x-1, p.y+ClientHeight, 0, Handle, NULL);
  //�ͳ�NULL��Ϣ����ʱ�ų�������Ϣ
  SNDMSG(Handle, WM_NULL, 0,0);
  //ȷ������ʾPOP�˵������ѡ����һѡ��ִ�й��ܯ�
  TMenuItem *Item = PopupMenu1->FindItem(dwCmd, fkCommand);
  if (Item) Item->Click();//����OnClick�¼�
  Caption = "Form1����Ļ�����λ��X:"+AnsiString(p.x)+",Y:"+AnsiString(p.y);
  }
}
//---------------------------------------------------------------------------
//�ۺ�ɫ
void __fastcall TForm1::pop011Click(TObject *Sender)
{
Color = (TColor)RGB(255,200,255);
}
//---------------------------------------------------------------------------
//����ɫ
void __fastcall TForm1::pop021Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,255);
}
//---------------------------------------------------------------------------
//����ɫ
void __fastcall TForm1::pop031Click(TObject *Sender)
{
Color = (TColor)RGB(200,255,200);
}
//---------------------------------------------------------------------------

