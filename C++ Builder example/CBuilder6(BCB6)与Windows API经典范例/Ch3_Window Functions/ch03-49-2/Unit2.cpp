//---------------------------------------------------------------------------
//Ŀ�ģ��ɶ�ʱ����ʱ��������Ļλ�ã���ѡȡ�Ӵ���
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
{//Ĭ�������������
CheckBox1->Checked = false;
CheckBox1->Caption = "�ѹر���껬��ѡȡ�Ӵ���";
CheckBox1->Width = 170; //�����㹻���
Timer1->Interval = 100; //��ʱ��Ƶ��
Timer1->Enabled = false; //�ȹرն�ʱ��
}
//---------------------------------------------------------------------------
//�ڳ�����ʾʱ������4���Ӵ���
void __fastcall TForm1::FormShow(TObject *Sender)
{
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Form1;
   form->FormStyle = fsMDIChild;
   form->Name = "form_" + AnsiString(i);
   form->Width = 120; form->Height = 60;
   form->Top = i*50; form->Left = i*30;
   form->Color = (TColor)RGB(255,i*50,255-i*50);
   }
}
//---------------------------------------------------------------------------
//�ڳ���ر�ʱ���ر�4���Ӵ���
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
//���ƶ�ʱ�����أ����޸�״̬˵���ַ���
void __fastcall TForm1::CheckBox1Click(TObject *Sender)
{
Timer1->Enabled = !Timer1->Enabled;
if (Timer1->Enabled)  CheckBox1->Caption ="��������껬��ѡȡ�Ӵ���";
else                  CheckBox1->Caption ="�ѹر���껬��ѡȡ�Ӵ���";
}
//---------------------------------------------------------------------------
//�ɶ�ʱ����ʱ��������Ļλ�ã���ѡȡ�Ӵ���
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
POINT P;
::GetCursorPos(&P);//ȡ�������Ļλ��
//ȡ�����λ���´���handle
HWND HWindow = ::WindowFromPoint(P);
//����������˴���
if (HWindow) ::SetFocus(HWindow);
}
//---------------------------------------------------------------------------

