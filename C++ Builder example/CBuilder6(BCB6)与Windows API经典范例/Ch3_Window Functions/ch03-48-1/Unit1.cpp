//---------------------------------------------------------------------------
//Ŀ�ģ������Ӵ�����ƴͼ��ʽ���������з�ʽ������ĸ����ָ����Χ��
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
//�ڳ�����ʾʱ������4���Ӵ���
void __fastcall TForm1::FormShow(TObject *Sender)
{
for(int i=0;i<4;i++)
   {
   TForm *form = new TForm(this);
   form->Parent = this;
   form->Name = "Child_" + AnsiString(i);
   form->Width = 150; form->Height = 40;
   form->Top = i*40+ToolBar1->Height; form->Left = i*15;
   form->Color = (TColor)RGB(255,i*50,255-i*50);
   form->Show();
   }
}
//---------------------------------------------------------------------------
//�ڳ���ر�ʱ���ر�4���Ӵ���
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
for(int i=0; i<MDIChildCount; i++)
    MDIChildren[i]->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ��Form1�м�����Χ
RECT sr = {0,ToolBar1->Height,
           ClientWidth,
           ClientHeight-StaticText1->Height};
//��ƴͼ��ʽ�����Ӵ���
if(Button1->Default)
   ::TileWindows(Handle,
                 MDITILE_VERTICAL,//�ų����к�����������Ӵ���
                 &sr,
                 NULL,//��ΪNULL����Ϊ�����Ӵ�����Ŀ
                 NULL //��ΪNULL����ָ�������Ӵ���handle����
                 );
else//�Ա������������з�ʽ�����Ӵ���
   ::CascadeWindows(Handle,
                    MDITILE_SKIPDISABLED,//�����Ωһ���
                    &sr,
                    NULL,//��ΪNULL����Ϊ�����Ӵ�����Ŀ
                    NULL //��ΪNULL����ָ�������Ӵ���handle����
                    );
//�л�����ֵ
Button1->Default = !Button1->Default;
}
//---------------------------------------------------------------------------

