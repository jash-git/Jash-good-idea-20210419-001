//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-----ȡ���Ӵ��ڵı�׼callback����------------------------------------------
BOOL CALLBACK EnumChildProc(HWND, LPARAM);
bool __stdcall PressClickBtn(HWND, LPARAM );
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ψ��͸��Button2��ť������ִ��Button3���ܥ\��
Button3->Hide();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1��������
Memo1->Clear();
//��һ��Ѱ�˴����µ��Ӵ��ڼ�����handle��
//��ִ��EnumChildProc����
::EnumChildWindows(
      Handle,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
}
//---------------------------------------------------------------------------
//�����д�һ���Ӵ��ڶ�ɨ���Ϊֹ
BOOL CALLBACK EnumChildProc(HWND hWnd, LPARAM)
{
//���ڴ˶�����ȡ�����룬��ԭ���ַ�
if(SendMessage(hWnd, EM_GETPASSWORDCHAR, 0, 0))
  {
  char buf[256], text[256];
  ::GetClassName( hWnd, buf, sizeof(buf));
  ::GetWindowText( hWnd, text, sizeof(text));
  SendMessage( hWnd, EM_SETPASSWORDCHAR, 0, 0);
  //��Memo1��ʾ����
  Form1->Memo1->Lines->Add("���"+AnsiString(buf));
  Form1->Memo1->Lines->Add("���룺"+AnsiString(text));
  }
//�˶���ȡ�ý���󣬼�������ʾ�ַ�
::SetFocus(hWnd);
//��һ��Ѱ�˴����µ��Ӵ��ڼ�����handle��
//��ִ��EnumChildProc����
::EnumChildWindows(
      hWnd,
      reinterpret_cast <WNDENUMPROC> (EnumChildProc),
      0L
      );
return TRUE;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ɾ��Memo1��������
Memo1->Clear();
//��Ѱ�˴����µ��Ӵ��ڼ�����handle
EnumChildWindows( Handle, (WNDENUMPROC)PressClickBtn, 0);
}
//---------------------------------------------------------------------------
//�˷�callback���������Կɷ���callback����(EnumChildWindows)��
//���д�һ�������Ѱ
bool __stdcall PressClickBtn( HWND hWnd, LPARAM )
{
char buffer [200];
//����handle��������
if(!hWnd) return false;
//����handle��Button3��ť�������㰴��ť��
//ִ��Button3����
::GetClassName( hWnd, buffer, sizeof(buffer));
if(strcmp(buffer,"TButton") == 0 )
   {
   ::GetWindowText( hWnd, buffer, sizeof(buffer));
   if (strcmp(buffer,"Button3") == 0 )
      {
      //����ߵ�λ���ݣ�XΪ��λ��YΪ��λ
      LPARAM pos = MAKELPARAM( 10, 10 );
      //�ͳ�������ť��Ϣ��
      PostMessage( hWnd, WM_LBUTTONDOWN, 0, pos );
      PostMessage( hWnd, WM_LBUTTONUP, 0, pos );
      return false;
      }
   }
//��һ��Ѱ�˴����µ��Ӵ��ڼ�����handle��
//��ִ��PressClickBtn����
EnumChildWindows( hWnd, (WNDENUMPROC)PressClickBtn, 0 );
//ִ����һɨ��
return true;
}
//---------------------------------------------------------------------------
//Button2���ܲ�����
void __fastcall TForm1::Button3Click(TObject *Sender)
{
Memo1->Color = (TColor)RGB(255,200,220);//�ۺ�ɫ
Memo1->Text = "Memo1�ı��ɫ��";
}
//---------------------------------------------------------------------------

