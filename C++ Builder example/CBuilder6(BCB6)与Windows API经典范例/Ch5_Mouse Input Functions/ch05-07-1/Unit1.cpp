//---------------------------------------------------------------------------
//Ŀ�ģ���סImage1��ҷʱ��ʵ���ǲ�׽��Image1�µĶ�̬Panel1����
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
//Ĭ�������OnClick������;����ִ�������¼���
//�ٽ���OnClickԭ���г�
CheckBox1->Checked = true;
//���棬��CheckBox1->CheckedΪ�棬�����˫���¼�
CheckBox2->Checked = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormDblClick(TObject *Sender)
{
//���棬��CheckBox1->CheckedΪ�棬�����˫���¼�
if(CheckBox2->Checked == true)
   {
   //��Form1��OnClick�¼�ʧЧ��
   //���������ĳ������
   Color = clRed;
   Canvas->TextOut(40, 40, "�Ƶ������˫���¼���");
   //���ƻ�OnClickִ�к���������
   CheckBox2->Checked = false;
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClick(TObject *Sender)
{
//��Ϊ����ɫ
Color = (TColor)RGB(170,225,255);
//����ʱ����Խ���������˫���¼���ʱ��
//���ⴥ��OnDblClick�¼�
::Sleep(::GetDoubleClickTime()+1);
//�ж����ڳ���ִ�У����Ƚ��������¼�����Ӧ
//�ٽ��к��湦��
if(CheckBox1->Checked)
   Application->ProcessMessages();

if(CheckBox2->Checked == false)
   {
   Color = (TColor)RGB(200,255,160);
   Canvas->TextOut(50, 50, "�ܿ������˫���¼���" + AnsiString(::GetDoubleClickTime()));
   }

}
//---------------------------------------------------------------------------


