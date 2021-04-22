//---------------------------------------------------------------------------
//Ŀ�ģ�������ƶ�ʱ����Ĵ���handle�����ڼ��̽��㣬���㼴����form�����ϤW
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
{//��̬������ĸ��Ӵ���
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = Panel1;
   form->Name = "FORM_" + AnsiString(i);
   form->Width = 150; form->Height = 80;
   form->Top = i*60; form->Left = i*40;
   form->Color = (TColor)RGB(255-i*50,i*50,255);
   form->Show();
   //�Ӵ���ͨ�õ�OnMouseMove�¼�
   form->OnMouseMove = AllFormMouseMove;
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
//ͨ�õ�OnMouseMove�¼�
void __fastcall TForm1::AllFormMouseMove(TObject *Sender, TShiftState Shift,
    int X, int Y)
{
//ת����Ϣ�ɴ�����̬
TForm *form = dynamic_cast<TForm *>(Sender);
//������Ĵ���handle�����ڼ��̽��㣬���㼴����form�����ϤW
if(::GetFocus() != (HWND)form->Handle)
   {
   ::SetFocus(form->Handle);//����formΪ����
   ::BringWindowToTop(form->Handle);//�����ڴ�����ǰ��
   Caption = "����"+form->Caption+" ȡ�ý���";
   }
}
//---------------------------------------------------------------------------

