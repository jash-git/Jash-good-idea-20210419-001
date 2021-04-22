//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{//����һ�ε�����һ��ť�⣬����ֹ����ԭ<��ʼ>��ťͼ��
Button1->Default = true;
}
//---------------------------------------------------------------------------
//������ر�ʱ����ԭ��ݹ������µ�<��ʼ>��ťͼ��
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
SNDMSG(HButton, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)HOldBitmap);
::EnableWindow(HButton, true);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�Զ��庯������<��ʼ>��ťhandle
HButton = DesktopHandle("Shell_TrayWnd");
//��<��ʼ>��ť��Ч
::EnableWindow(HButton, true);
//�ͳ�����ͼ����Ϣ��������ԭͼ��ͼ��
HBITMAP tempBmp = (HBITMAP)SNDMSG(HButton, BM_SETIMAGE,
                            IMAGE_BITMAP,
                            (LPARAM)Image1->Picture->Bitmap->Handle);
//��һ�ΰ�ť�󣬼�ֹͣ����<��ʼ>ͼ��
if(Button1->Default) HOldBitmap = tempBmp;
Button1->Default = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//�Զ��庯������<��ʼ>��ťhandle
HButton = DesktopHandle("Shell_TrayWnd");
//��<��ʼ>��ťʧЧ
::EnableWindow(HButton, false);
//�ͳ�����ͼ����Ϣ��������ԭͼ��ͼ��
HBITMAP tempBmp = (HBITMAP)SNDMSG(HButton, BM_SETIMAGE,
                             IMAGE_BITMAP,
                             (LPARAM)Image2->Picture->Bitmap->Handle);
//��һ�ΰ�ť�󣬼�ֹͣ����<��ʼ>ͼ��
if(Button1->Default) HOldBitmap = tempBmp;
Button1->Default = false;
}
//---------------------------------------------------------------------------
//�Զ��庯��--����<��ʼ>��ťhandle
HWND TForm1::DesktopHandle(char *str)
{
char buffer[MAX_PATH];
//ȡ�ÿ�ݹ�������handle
HWND HTray = ::FindWindow(str, NULL);
//ȡ�ÿ�ݹ������µ��Ӵ���handle
HWND HChild = ::GetWindow(HTray, GW_CHILD);
//��һ��Ѱ��<��ʼ>��ť����handle
while(HChild)
   {
   ::GetClassName(HChild, buffer, sizeof(buffer));
   if (strcmp(buffer, "Button") == 0) break;
   //������ȡ����һ�Ӵ���handle
   HChild = ::GetWindow(HChild, GW_HWNDNEXT);
   }
//����<��ʼ>��ť����handle
return HChild;
}
//---------------------------------------------------------------------------


