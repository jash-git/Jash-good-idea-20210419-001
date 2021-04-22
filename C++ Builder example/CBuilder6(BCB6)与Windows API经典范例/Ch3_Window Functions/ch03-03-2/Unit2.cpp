//---------------------------------------------------------------------------
//Ŀ�ģ�����Ctrl+Tab �����������ε����Ӵ���ȡ�ý��㣬����ʾ����ǰ��
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Ĭ�Ͽ�ݼ���Ϣ����ֵ---------------------------------------------------------
const int ID = WM_USER + 100;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//��Form1���ۣ�ͻ���Ӵ���
Color = (TColor)RGB(255,255,200);
//Form1��Tag���ԣ������л��Ӵ��ڵı���
Tag = 1;
//��Form1��̬��ɿ�ӵ���Ӵ��ڵ�ĸ����
FormStyle = fsMDIForm;
//������̵߳�¼��ݼ�
//����Ctrl+Tab �������ɵ����Ӵ���ȡ�ý��㣬����ʾ����ǰ�歱
::RegisterHotKey(Handle, ID, MOD_CONTROL, VK_TAB);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//��̬�������ĸ��Ӵ���
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Form1;
   form->FormStyle = fsMDIChild;
   form->Name = "form_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
//�ͷŴ��̵߳�¼�Ŀ�ݼ�
::UnregisterHotKey(Handle, ID);
}
//---------------------------------------------------------------------------
//��׽�Զ����ݼ���Ϣ
void __fastcall TForm1::HotKeys(TMessage &Msg)
{
//����Ϣ����������������
TForm::Dispatch(&Msg);
//Ѱ��ָ�����Ƶ��Ӵ���
char name[6];
Form1->Tag++;
int num = Form1->Tag%4;
sprintf(name,"form_%i",num);//#include <stdio.h>
//�����Ӵ����ں��棬���ᵽ��ǰ��
for(int i=0;i<Form1->ComponentCount;i++)
  if(Components[i]->Name == name)
    {
    //��TComponentת��TForm��̬
    TForm *form = (TForm *)Components[i];
    ::BringWindowToTop(form->Handle);
    //���˳�������С��״̬����ָ�ԭ��״̬
    if (::IsIconic(form->Handle))
       ::ShowWindow(form->Handle, SW_RESTORE);
    }
}
//---------------------------------------------------------------------------


