//---------------------------------------------------------------------------
//Ŀ�ģ�������ť���л����ػ����ֿ�ݹ������������������п�ݷ�ʽͼʾ
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
{//�����������ԣ���Ϊ����ֵ
Button1->Default = true;
//ȡ�ÿ�ݹ����е�handle
hTaskBar = ::FindWindow("Shell_TrayWnd", NULL);
//ȡ�������������Ա��handle
hProgMan = ::FindWindowEx (0, 0, "Progman", 0);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{//������ر�ʱ��ȷ�ϻָ���ݹ������������ݷ�ʽͼʾԭò
::ShowWindow(hTaskBar, SW_SHOW);
::ShowWindow(hProgMan, SW_SHOW);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//������Ԫ����--�л����ػ���ʾָ������
(Button1->Default)?
(::ShowWindow(hTaskBar, SW_HIDE),::ShowWindow(hProgMan, SW_HIDE)):
(::ShowWindow(hTaskBar, SW_SHOW),::ShowWindow(hProgMan, SW_SHOW));
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

