//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//��Project2a.exe������ͬ���Զ�����Ϣ------------------------------------------
static const UINT WM_TWOWINMSG = WM_APP + 0x750;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
HWND secWin = NULL;
//��Ѱ���򿪵�Project2a.exe
secWin = ::FindWindow(0, "�Զ���׽Form1���͵���Ϣ");
if(secWin)
  {//��Project2a.exe��С�ڿ�ݹ������ϣ�������
  if(!::IsWindow(secWin))
     ::ShowWindow(secWin, SW_SHOWNORMAL);
  //�ͳ��Զ�����Ϣ��Project2a.exe
  PostMessage(secWin, WM_TWOWINMSG,
              (WPARAM) 1234,//��Ϊ�����������Ϣ
              (LPARAM) 4321 //��Ϊ�����������Ϣ
              );
  }
else
  {
  ShowMessage("�뽫Project2a.exe����򿪣���������������Ϣ����");
  }
}
//---------------------------------------------------------------------------
