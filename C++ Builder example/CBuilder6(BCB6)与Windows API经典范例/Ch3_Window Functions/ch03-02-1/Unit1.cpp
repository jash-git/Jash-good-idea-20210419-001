//---------------------------------------------------------------------------
//Ŀ�ģ�������ť����������С���Ӵ�����ƴͼ��ʽ����������ĸ�������½�
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
{//��Panel1���ۣ�ͻ���Ӵ���
Panel1->Color = (TColor)RGB(255,255,200);
}
//---------------------------------------------------------------------------
//�ڳ�������ʱ������4����ͬλ�õ���С״̬�Ӵ���
void __fastcall TForm1::FormShow(TObject *Sender)
{//��̬�����ĸ��Ӵ���
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Panel1;
   form->Name = "form_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   form->Show();
   form->WindowState = wsMinimized;
   //�ƶ���С״̬�Ӵ��ڵ�λ��
   ::MoveWindow(form->Handle,i*40,i*60,
                form->Width, form->Height,
                false);
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
void __fastcall TForm1::Button1Click(TObject *Sender)
{//��������С���Ӵ�����ƴͼ��ʽ��������
if(::ArrangeIconicWindows(Panel1->Handle))
   ShowMessage("�ɹ�����������С������");
}
//---------------------------------------------------------------------------

