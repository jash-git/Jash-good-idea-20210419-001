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
//����Button1��Default���ԣ���Ϊbool����
Button1->Default = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ɾ��Memo1���������֦r
Memo1->Text = " ";
//��������RECT
RECT r = {0,0,1,1};
//����2�ֲ�ͬ����������
RECT r1 = {0,0,300,300};
RECT r2 = {0,0,200,200};
//���棬��r=r1���٣���r=r2
(Button1->Default)?r = r1:r = r2;
//�پ�ȷ�ص���������򳤿�
//������⡢�߿򡢲˵����
//dwStyle��������CreateWindow��������ϸ�г��C�X
::AdjustWindowRect(&r,
                   WS_CAPTION|WS_BORDER,
                   true);//����˵����
//����΢����ĳ���λ�ã��������ô���
::SetWindowPos(Handle,
               HWND_TOP,
               0,
               0,
               r.right-r.left,
               r.bottom-r.top,
               SWP_NOMOVE
               );
//��ʾ΢�����ʵ�ʳ���λ��
Memo1->Lines->Add("΢�����ʵ�ʳ���λ�ã�");
Memo1->Lines->Add("�� "+AnsiString(r.top)+",�� "+AnsiString(r.left)+
              ",�� "+AnsiString(r.right)+",�� "+AnsiString(r.bottom));
Memo1->Lines->Add("ԭ���õ�ʵ�ʳ���λ�ã�");
if(Button1->Default)
     Memo1->Lines->Add("�� "+AnsiString(r1.top)+",�� "+AnsiString(r1.left)+
                  ",�� "+AnsiString(r1.right)+",�� "+AnsiString(r1.bottom));
else
 Memo1->Lines->Add("�� "+AnsiString(r2.top)+",�� "+AnsiString(r2.left)+
              ",�� "+AnsiString(r2.right)+",�� "+AnsiString(r2.bottom));


//�л�2�ֳߴ�
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------
