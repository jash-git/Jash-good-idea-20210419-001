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
//Ĭ�ϰ�ťΪ��ִ��״̬
Button1->Default = true;
Button2->Default = true;
//����ʼʱ����ȡ�ÿ�ݹ�����handle
hTaskbarWnd = ::FindWindow("Shell_TrayWnd", NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
if(Button1->Default)//���ؿ�ݹ�����
   ::ShowWindow(hTaskbarWnd, SW_HIDE);
else //���ֿ�ݹ�����
   ShowWindow(hTaskbarWnd, SW_SHOW);
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//ȡ�ó������Աhandle����ȡ�õڶ����Ӵ���handle
//�ڶ����Ӵ���handle����������handle
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
//���ð�ť���л����ػ���ʾ����ͼʾ
if(Button2->Default)
   ::ShowWindow(hwnd, SW_HIDE);
else
   ::ShowWindow(hwnd, SW_SHOW);
Button2->Default = !Button2->Default;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
//�����û����ǻ�ԭԭ�д��ڻ���
//��������ͼʾ
hwnd = ::FindWindow("ProgMan",NULL);
hwnd = ::GetWindow(hwnd, GW_CHILD);
hwnd = ::GetWindow(hwnd, GW_CHILD);
::ShowWindow(hwnd, SW_SHOW);
//���ֿ�ݹ�����
::ShowWindow(hTaskbarWnd, SW_SHOW);
}
//---------------------------------------------------------------------------
