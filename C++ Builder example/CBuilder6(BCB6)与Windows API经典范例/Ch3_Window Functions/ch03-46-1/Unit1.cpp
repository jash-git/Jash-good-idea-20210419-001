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
}
//---------------------------------------------------------------------------
//����ShowWindow �������ı�Project1ĸ��������״̬
//ShowWindow��״ֵ̬��winuser.h�н��ж��壬�����в鿴
void __fastcall TForm1::RadioGroup1Click(TObject *Sender)
{
int show;//��������
//�ɶ�ѡһѡ�ѡȡ����״̬
switch(RadioGroup1->ItemIndex)
   {
   case 0: show = SW_MAXIMIZE; break;
   case 1: show = SW_MINIMIZE; break;
   case 2: show = SW_RESTORE; break;
   case 3: show = SW_SHOW; break;
   case 4: show = SW_SHOWDEFAULT; break;
   case 5: show = SW_SHOWMAXIMIZED; break;
   case 6: show = SW_SHOWMINIMIZED; break;
   case 7: show = SW_SHOWMINNOACTIVE; break;
   case 8: show = SW_SHOWNA; break;
   case 9: show = SW_SHOWNOACTIVATE; break;
   case 10: show = SW_SHOWNORMAL; break;
   case 11: show = SW_HIDE; break;
   }
//�ı�Project1ĸ��������״̬
::ShowWindow(Application->Handle, show);
}
//---------------------------------------------------------------------------
