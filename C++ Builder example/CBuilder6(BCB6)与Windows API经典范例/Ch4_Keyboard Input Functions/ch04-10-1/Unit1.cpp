//---------------------------------------------------------------------------
//Ŀ�ģ���ťʱ�����ͬʱ�Ƿ�סShift������������ͬ���ܯ�
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
{//ɾ��Memo1������
Memo1->Text = "";
//��ťʱ�����ͬʱ�Ƿ�סShift����������ͬ���ܥ\��
if(HIBYTE(::GetKeyState(VK_SHIFT)))
  {
  Panel1->Show(); Panel2->Hide();
  Memo1->Lines->Add("������ťʱ��ͬʱ��סShift��");
  }
else
  {
  Panel1->Hide(); Panel2->Show();
  Memo1->Lines->Add("������ťʱ��δ��סShift��");
  }
//����&�ۿ���
Memo1->Lines->Add("��λ�����" +
                  AnsiString(HIBYTE(::GetKeyState(VK_SHIFT))));
Memo1->Lines->Add("��λ�����" +
                  AnsiString(LOBYTE(::GetKeyState(VK_SHIFT))));
}
//---------------------------------------------------------------------------
