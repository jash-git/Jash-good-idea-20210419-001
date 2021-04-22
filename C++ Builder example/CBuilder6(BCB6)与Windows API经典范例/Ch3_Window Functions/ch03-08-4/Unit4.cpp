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
//��ɫ������Ĭ��Ϊ����ɫ
fboxColor = (unsigned long)RGB(255,220,100);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�½�һ�Զ��������Ի���
TMyFontDialog *fbox = new TMyFontDialog(this);
//�򿪶Ի��򣬲�ִ�����ã��޸�Memo1�������ɫ
if(fbox->Execute())
  {
  Memo1->Font = fbox->Font;
  Memo1->Font->Color = (TColor)fboxColor;
  }
delete fbox;
}
//---------------------------------------------------------------------------
//���½�Ϊ�Զ�������Ի���������
//---------------------------------------------------------------------------
//����������Ի�������պʹ�������Ի���ѡ�����Ϣ
void __fastcall TMyFontDialog::WndProc(TMessage& Msg)
{
switch (Msg.Msg)
  {
  //��������Ի���ʱ��������ɫѡ���ɫ�Ի���ť
  case WM_INITDIALOG:
     {
     //�Դ��Զ��庯����ȡ��<��ɫѡ�������>��handle ID = 1139
     //������һ������
     //GetFontBoxItemsID_Text(Handle);
     //<1> ��<��ɫѡ�������>���½���ɫѡ��
     COLORREF color = (COLORREF)Form1->fboxColor;
     HWND HColorCombo = ::GetDlgItem(Handle, 1139);
     int index = SNDMSG(HColorCombo, CB_INSERTSTRING, 0,
                       reinterpret_cast<LPARAM>("�Զ�����ɫ"));
     SNDMSG(HColorCombo, CB_SETITEMDATA, index, color);
     SNDMSG(HColorCombo, CB_SETCURSEL, index, 0);
     //<2>�½���ɫ�Ի���ť
     int width, height;
     RECT R;
     //��user��Ҫ�������������Ի���ߴ���°�ťλ��
     if (::GetWindowRect(Handle, &R))
        {
        width = R.right - R.left;
        height = R.bottom - R.top;
        ::SetWindowPos(Handle, NULL, 0, 0,
                       width , height,
                       SWP_NOMOVE | SWP_NOZORDER);
        }
     //����һ���Զ��尴ť
     HNewBtn = ::CreateWindow("BUTTON", "�Զ�����ɫ...",
                            WS_CHILD | WS_VISIBLE | BS_LEFT ,
                            20, height-65, 85, 25,
                            Handle, NULL, HInstance, NULL);
     break;
     }
  //���պʹ�������Ի���ѡ���
  case WM_COMMAND:
     {
     //����<�Զ���ɫ��>��ťʱ�����ɫ�ʶԻ���
     if (reinterpret_cast<HWND>(Msg.LParam) == HNewBtn &&
         Msg.WParamHi == BN_CLICKED)
        {
        ShowColorDialog();
        Form1->fboxColor = (unsigned long) Font->Color;
        }
     //��ֱ�ӵ���<��ɫѡ�������>��ɫѡ��ʱ
     HWND HColorCombo = ::GetDlgItem(Handle, 1139);
     if (reinterpret_cast<HWND>(Msg.LParam) == HColorCombo &&
         Msg.WParamHi == BN_CLICKED)
        {
        //������ɫѡ�������<�Զ�����ɫ>ѡ����ɫ
        COLORREF color = (COLORREF)SNDMSG(HColorCombo, CB_GETITEMDATA, 0, 0);
        Font->Color = (TColor) color;
        //��ѡȡ��ɫ�ʴ���ɫ�ʹ�ͬ����
        Form1->fboxColor = (unsigned long) color;
        }
     break;
     }
  }
//������Ϣ����ԭ����ִ��
TFontDialog::Dispatch(&Msg);
}
//---------------------------------------------------------------------------
//������<�Զ�����ɫ>��ťʱ
void __fastcall TMyFontDialog::ShowColorDialog()
{
//���ڴ�������һ����ɫ�Ի���ռ�
std::auto_ptr<TColorDialog> ColorDialog(new TColorDialog(NULL));
//����ɫ�Ի���ִ��user����
if (ColorDialog->Execute())
    {
    COLORREF color = ColorToRGB(ColorDialog->Color);
    //ȡ������Ի������ɫѡ�������<ComboBox> handle
    HWND HColorCombo = ::GetDlgItem(Handle, 1139);
    //������ɫѡ�������<�Զ���ɫ��>ѡ����ɫ
    SNDMSG(HColorCombo, CB_SETITEMDATA, 0, color);
    SNDMSG(HColorCombo, CB_SETCURSEL, 0, 0);
    //��������Ի���������ɫ��������ɫ��ͬ����
    Font->Color = ColorDialog->Color;
    Form1->fboxColor = (unsigned long) Font->Color;
    }
}
//---------------------------------------------------------------------------
//ȡ������Ի��������������handle ID ����ʾ����
//�Դ˺�����ȡ��<��ɫѡ�������>��handle ID = 1139���A
//��������ɱ������½��Զ�����ɫ����
void TForm1::GetFontBoxItemsID_Text(HWND handle)
{
//������Ѱ��Χ
for(int a=-3000;a<3000;a++)
  if(::GetDlgItem(handle,a))//����ȡ��handle���ڣ���ͨ��
    {
    char str[256];
    //ȡ�ô�handle�����֣������б�ѡ��ID������Memo1�г��X
    ::GetDlgItemText(handle,a,str,256);
    Form1->Memo1->Lines->Add(AnsiString(a)+","+AnsiString(str));
    }
}
//---------------------------------------------------------------------------


