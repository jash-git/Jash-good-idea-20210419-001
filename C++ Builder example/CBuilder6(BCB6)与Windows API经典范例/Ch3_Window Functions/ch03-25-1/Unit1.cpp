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
//Ѱ�ҵ���ݹ�������������Ա��handle
HWND HTaskBar = ::FindWindow("Shell_TrayWnd", NULL);
HWND HDeskLV = ::FindWindow("ProgMan",NULL);
//ȡ��handle���Ӵ���handle
HTaskBar = ::GetWindow(HTaskBar, GW_CHILD);
HDeskLV = ::GetWindow(HDeskLV, GW_CHILD);
HDeskLV = ::GetWindow(HDeskLV, GW_CHILD);
//����ݹ�������������ʾ���ﵽ�ػ����Ŀ��
::ShowWindow(HTaskBar, SW_HIDE);
::ShowWindow(HTaskBar, SW_SHOW);
//ȡ�ó������Ա��Χ���ͳ�������Ϣ���ﵽ�ػ����Ŀ�Ī�
::InvalidateRect(HDeskLV, NULL, true);
//����Form1ȡ�ý���
::SetFocus(Handle);
}
//---------------------------------------------------------------------------
