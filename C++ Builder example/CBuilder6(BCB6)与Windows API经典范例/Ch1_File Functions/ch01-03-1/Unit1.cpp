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
// ���Ѿ�������·������
if(Edit1->Text !="")
   {
   AnsiString dir = DirectoryListBox1->Directory;
   //�U�ֱ��Ƿ��ڸ�Ŀ¼��
   if(dir.Length()>4)
      dir = dir + "\\" + Edit1->Text;
   else
      dir = dir + Edit1->Text;
   // �ڳ�������ʾ��Ŀ¼������·��
   StaticText1->Caption = "�½�Ŀ¼·����" + dir;
   //���½�Ŀ¼ʧ��
   if(!::CreateDirectory(dir.c_str(), NULL))
      ShowMessage("�½�Ŀ¼ʧ�ܣ�");
   //���½�Ŀ¼�ɹ����������ʾ
   DirectoryListBox1->Update();
   }
else
   ShowMessage("�հ���Ч����������ЧĿ¼���ơ�");
}
//---------------------------------------------------------------------------

