//---------------------------------------------------------------------------
//Ŀ�ģ�����һ���򣬲����������������ַ���
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
//��Ѱ<���±�>���޴�
HWND Npad = ::FindWindow(NULL, "δ���� - ���±�");
//�Y<�O�ƥ�>�b�}�Ҥ��A�Y�a��̫e��
if(::ShowWindow(Npad,SW_SHOWNORMAL))
   {
   ::BringWindowToTop(Npad);
   }
else //��û�򿪣����<���±�>
   {
   //ȡ��WindowĿ¼λ��
   char WinDir[MAX_PATH];
   ::GetWindowsDirectory(WinDir, MAX_PATH);
   AnsiString sysdir = AnsiString(WinDir) + "\\Notepad.exe";
   //��<���±�>
   ::ShellExecute(NULL,"open",sysdir.c_str(),NULL,NULL,SW_SHOWNORMAL);
   }
//��ȫ��<���±�>�󣬲��ͳ��ض�����
Sleep(100);
int x=0;
while(x<10)
   {
   for(int i = 'A'; i <= 'Z'; i++)
      {
      //�� a �� z
      keybd_event((char)i, 0, 0, 0);
      keybd_event((char)i, 0, KEYEVENTF_KEYUP, 0);
      //�� ! �� )
      int c = x + '0';
      keybd_event(VK_SHIFT, 0, 0, 0);
      keybd_event((char)c, 0, 0, 0);
      keybd_event((char)c, 0, KEYEVENTF_KEYUP, 0);
      keybd_event(VK_SHIFT, 0, KEYEVENTF_KEYUP, 0);
      }
   //ÿ���A��Z һ��ѭ��������һ��
   keybd_event(VK_RETURN, 0, 0, 0);
   keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
   x++;
   }
}
//---------------------------------------------------------------------------
