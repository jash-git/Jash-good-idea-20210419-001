//---------------------------------------------------------------------------
//Ŀ�ģ���ָ�������µ��Ӵ�����������Ϊͬһ��С��λ��
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
//ȷ��Form1Ϊһ����̬
FormStyle = fsNormal;
}
//---------------------------------------------------------------------------
//��̬����5����ɫ�����Ĵ���
void __fastcall TForm1::FormShow(TObject *Sender)
{
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
    form->Show();
    }
}
//---------------------------------------------------------------------------
//ɾ������ʼʱ������5����ɫ����
void __fastcall TForm1::FormDestroy(TObject *Sender)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//����HWND����
HWND *pHwnd = new HWND[5];
//����RECT�ṹ
RECT r = {40,40,250,150};
try
   {
   char name[5];
   //Ѱ��ָ�����Ƶ��Ӵ���
   for(int num=0;num<5;num++)
   {
   sprintf(name,"form%i",num+1);//#include <stdio.h>
   //ȡ���Ӵ���handle����
   for(int i=0;i<ComponentCount;i++)
     if(Components[i]->Name == name)
       {
       //��TComponentת��TForm��̬
       TForm *form = (TForm *)Components[i];
       pHwnd[num] = form->Handle;
       }
   }
   //���Ӵ���������������Ϊͬһ��С&λ��
   ::CascadeWindows(Handle, MDITILE_SKIPDISABLED,
                    &r, 5, pHwnd);
   }
catch (...)
   {
   delete [] pHwnd;
   }
delete [] pHwnd;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ȡ�����������г�����Ŀ
const int count = Screen->FormCount;
RECT r = {Screen->Width/5,Screen->Height/5,
          Screen->Width/5*4,Screen->Height/5*4};
//�����������г������������Ϊͬһ��С&λ��
::CascadeWindows(NULL, MDITILE_SKIPDISABLED, &r, count, NULL);
}
//---------------------------------------------------------------------------



