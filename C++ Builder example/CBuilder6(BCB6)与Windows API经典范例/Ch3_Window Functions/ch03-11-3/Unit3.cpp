//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
Button1->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
char buffer[MAX_PATH];
//ȡ�ÿ�ݹ������� handle
HWND HTray = ::FindWindow("Shell_TrayWnd", NULL);
//��ȡ�ÿ�ݹ���������ѡ��� handle
HWND HChild = ::GetWindow(HTray, GW_CHILD);
//��<��ʼ>��ѡ�����԰�ť��̬���֣���������ť���󼴿�
while (HChild)
   {
   ::GetClassName(HChild, buffer, sizeof(buffer));
   if (strcmp(buffer, "Button") == 0) break;
   //��ѡ�����ǰ�ť״̬���򷵻���һ��ѡ��handle
   HChild = ::GetWindow(HChild, GW_HWNDNEXT);
   }
HButton = HChild;
//��<��ʼ>��ťʧЧ
::EnableWindow(HButton, false);
Button1->Enabled = false;
}
//---------------------------------------------------------------------------
//�뿪����ʱ����<��ʼ>��ť��Ч
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
::EnableWindow(HButton, true);
}
//---------------------------------------------------------------------------
