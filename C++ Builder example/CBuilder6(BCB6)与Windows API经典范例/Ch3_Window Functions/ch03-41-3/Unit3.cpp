//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//-ȡ��CheckBox����Ϣֵ-----------------------------------------------------
#ifndef TVS_CHECKBOXES
#define TVS_CHECKBOXES 0x0100
#endif
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
// ȡ��ԭTreeView����������
DWORD dwStyle = ::GetWindowLong(TreeView1->Handle, GWL_STYLE);
// �ټ���CheckBox���͵�����Ϣֵ��
dwStyle = dwStyle | TVS_CHECKBOXES;
// �����TreeView����TreeView״̬������һ��״̬--CheckBox����
SetWindowLong(TreeView1->Handle, GWL_STYLE, dwStyle);
}
//---------------------------------------------------------------------------
