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
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//���Ѵ򿪳�����Ѱ��<���±�>����
HWND Notepad = ::FindWindow("NotePad", NULL);
//��<���±�>�ڴ��У���������ǰ��
if(::ShowWindow(Notepad,SW_SHOWNORMAL))
   {
   //ȷ��<���±�>����������ǰ��&ȡ�ý���
   ::BringWindowToTop(Notepad);
   //������̼��룬��һ���ַ����͵�<���±�>��
   String Text("WELCOME TO NOTEPAD");
   for(int x = 1; x <= Text.Length(); x++)
      {
      keybd_event(Text[x], 0, 0, 0);
      keybd_event(Text[x], 0, KEYEVENTF_KEYUP, 0);
      }
   //��<���±�>�У�������һ��
   keybd_event(VK_RETURN, 0, 0, 0);
   keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
   }
else
   ShowMessage("��Ǹ�����ȴ�<���±�>��\n��ֻ�Ǹ����ܼ򵥵�С����");
}
//---------------------------------------------------------------------------

