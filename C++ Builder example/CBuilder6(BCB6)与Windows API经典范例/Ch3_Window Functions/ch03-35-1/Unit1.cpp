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
{//Ĭ��Form1Ϊĸ����
FormStyle = fsMDIForm;
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
   form->Name = "Child_" + AnsiString(i);
   form->Width = 150; form->Height = 50;
   form->Top = i*50; form->Left = i*15;
   }
}
//---------------------------------------------------------------------------
//���ð�ť�л����ػ���ʾ4���Ӵ���
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0;i<4;i++)
   {
   AnsiString name = "Child_" + AnsiString(i);
   HWND hwnd = ::FindWindow(NULL, name.c_str());
   ::DestroyWindow(hwnd);
   }
}
//---------------------------------------------------------------------------
//��ȡ��Form1�µĵ�һ���Ӵ���
void __fastcall TForm1::Button1Click(TObject *Sender)
{
char cls[256];
//��ȡ��Form1�µĵ�һ���Ӵ���
HWND hwnd = ::GetWindow(Handle, GW_CHILD);
//������Ѱ�Ӵ��ڣ�������ʾ�����ع��ܯ�
do{ //ȡ���Ӵ����������ƣ��ж��Ƿ����
  ::GetClassName(hwnd, cls, 255);
  if (! strcmp(cls, "MDIClient"))
   {//��Ԫ���㣬�ж��Ӵ����Ƿ�Ϊ����״̬
   ::ShowWindow(hwnd, ::IsWindowVisible(hwnd) ? SW_HIDE : SW_SHOW);
   (Caption=="�����Ӵ���")?(Caption="��ʾ�Ӵ���"):(Caption="�����Ӵ���");
   }
   //��ȡ����һ�Ӵ���handle�������ж�
   hwnd = ::GetWindow(hwnd, GW_HWNDNEXT);
   } while(hwnd);
}
//---------------------------------------------------------------------------

