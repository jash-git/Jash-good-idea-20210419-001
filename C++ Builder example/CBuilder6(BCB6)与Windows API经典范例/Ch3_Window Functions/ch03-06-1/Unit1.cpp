//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//ȷ��Form1Ϊһ������
FormStyle = fsNormal;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormShow(TObject *Sender)
{
//��̬����5����ɫ�����Ĵ���
for(int i=0;i<5;i++)
    {
    TForm *form = new TForm(Form1);
    form->Parent = Form1;
    form->FormStyle = fsNormal;
    form->Name = "form" + AnsiString(i+1);
    form->Width = 150; form->Height = 40;
    form->Top = ToolBar1->Height + 40*i;
    form->Left = 40*i;
    form->Color = (TColor)RGB(255-i*50,i*50,255);
    //�����´������ƶ���꣬����Form1��OnMouseMove�¼�
    form->OnMouseMove = FormMouseMove;
    form->Show();
    //form2,form4��ΪʧЧ״̬
    if(i%2) form->Enabled = false;
    }
//��������������ƶ���꣬����Form1��OnMouseMove�¼�
StaticText1->OnMouseMove = FormMouseMove;
ToolBar1->OnMouseMove = FormMouseMove;
Button1->OnMouseMove = FormMouseMove;
Button2->OnMouseMove = FormMouseMove;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
char name[6];
//ɾ������ʼʱ������5����ɫ����
for(int num=0;num<ComponentCount;num++)
   {
   sprintf(name,"form%i",(num+1));//#include <stdio.h>
   for(int i=0;i<ComponentCount;i++)
     if(Components[i]->Name == name)
       {
       delete (TForm *)Components[i];
       }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
//ȡ�����λ��
POINT pd;
GetCursorPos(&pd);
pd = ScreenToClient(pd);
char name[256], text[256];
//�ų�ʧЧ���������λ�ö�ȡ��Form1�϶���handle
HWND h = ::ChildWindowFromPointEx(Handle, pd, CWP_SKIPDISABLED);
//�ɶ���handleȡ�ö��������Ϣ
::GetClassName(h,name,256);
::GetWindowText(h,text,256);
//ʵʱ��ʾ������Ϣ
StaticText2->Caption = "�ࣺ" + AnsiString(name) +
                       ",�ں����֣�"+AnsiString(text);
}
//---------------------------------------------------------------------------


