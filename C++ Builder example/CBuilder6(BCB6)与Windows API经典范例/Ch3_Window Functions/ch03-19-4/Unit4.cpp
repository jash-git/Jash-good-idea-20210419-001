//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit4.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//�˺�������WNDCLASS�ṹ����Ϣ����-------------------------------------------
LONG APIENTRY MyWndProc(HWND HWnd, UINT Msg,
                        WPARAM WParam, LPARAM LParam);
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//������������Ϊ�½����ڵı���
Tag = 0;
}
//---------------------------------------------------------------------------
//������ť�󣬼����Զ��庯���½�һ�Զ��崰��
void __fastcall TForm1::Button1Click(TObject *Sender)
{
CreateWindowForm(::GetDesktopWindow());
}
//---------------------------------------------------------------------------
//�Զ��庯��--�½�һ�Զ��崰��
HWND TForm1::CreateWindowForm(HWND HWndParent)
{
//�ȹ滮��һ�´������WNDCLASS�ṹ����
WNDCLASS FormClass;
FormClass.style = CS_HREDRAW | CS_VREDRAW;
FormClass.lpfnWndProc = (WNDPROC)MyWndProc;
FormClass.cbClsExtra = 0;
FormClass.cbWndExtra = 0;
FormClass.hInstance = HInstance;
//���Զ���ͼʾ
ICONINFO icon = {true,
                 NULL, NULL,
                 Image2->Picture->Bitmap->Handle,
                 Image1->Picture->Bitmap->Handle
                 };
FormClass.hIcon = CreateIconIndirect(&icon);
//FormClass.hIcon = Application->Icon->Handle;//BCBĬ��ͼʾ
FormClass.hCursor = ::LoadCursor(NULL, IDC_ARROW);
//���ñ�����ɫ
FormClass.hbrBackground = ::CreateSolidBrush(RGB(255,210,110));
FormClass.lpszMenuName = "MyForm";
FormClass.lpszClassName = "MyForm";
//��¼һ�´������(MyForm)
::RegisterClass(&FormClass);
AnsiString name = "MyForm_" + AnsiString(++Tag);
//����MyForm������𣬽���һ�´���
HWND HForm = ::CreateWindowEx(WS_EX_LTRREADING,
                              "MyForm", name.c_str(),
                              WS_OVERLAPPEDWINDOW,
                              Tag*20,Tag*20,
                              150, 150,
                              HWndParent, NULL,
                              HInstance, NULL);
//���޷���������ֹͣ����
if (!HForm) return NULL;
//��������������ʾ����������
::ShowWindow(HForm, SW_SHOW);
::UpdateWindow(HForm);
return HForm;
}
//�˺���ΪWNDCLASS�ṹ����Ϣ����---------------------------------------------
LONG APIENTRY MyWndProc(HWND HWnd, UINT Msg,
                       WPARAM WParam, LPARAM LParam)
{
//������ԭĬ�ϴ�����Ϣ
return DefWindowProc(HWnd, Msg, WParam, LParam);
}
//---------------------------------------------------------------------------



