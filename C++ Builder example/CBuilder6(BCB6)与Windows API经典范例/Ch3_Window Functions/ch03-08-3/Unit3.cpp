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
//����Button1���������ԣ���Ϊbool����
Button1->Default = true;
///����һ�µļ򵥴��ڣ��ṩλ�ø�AVI�ļ�����
HAnimation =
     ::CreateWindow(ANIMATE_CLASS, NULL,
                    WS_CHILD | WS_VISIBLE | ACS_TRANSPARENT,
                    30,
                    (Panel1->Height-Animate1->Height)/2,
                    0, 0,
                    Panel1->Handle, NULL,
                    HInstance, NULL);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//�ظ�������ť���ɴ򿪲���AVI�ļ���ر�AVI�ļ�
if(Button1->Default)
   {
   //��AVI�ļ�--��
   Animate_Open(HAnimation, "E:\\BCB--API\\0013 Window Functions\\Filecopy.avi");
   //����AVI�ļ�--��
   Animate_Play(HAnimation, 0, -1, 15);
   }
else//�رմ�AVI�ļ�--��
   Animate_Close(HAnimation);

Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------


