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
//ɾ��Memo1����������
Memo1->Clear();

DWORD fa;
//����ComboBox1ָ�����ԣ�����ָ���ļ�����
switch(ComboBox1->ItemIndex)
  {
   case 0: fa = FILE_ATTRIBUTE_ARCHIVE;break;
   case 1: fa = FILE_ATTRIBUTE_HIDDEN ;break;
   case 2: fa = FILE_ATTRIBUTE_NORMAL ;break;
   case 3: fa = FILE_ATTRIBUTE_OFFLINE ;break;
   case 4: fa = FILE_ATTRIBUTE_READONLY ;break;
   case 5: fa = FILE_ATTRIBUTE_SYSTEM ;break;
   case 6: fa = FILE_ATTRIBUTE_TEMPORARY ;break;
  }
//��������ָ���ļ�������
if(::SetFileAttributes( FileListBox1->FileName.c_str(), fa ))
   Memo1->Lines->Add("����<" + ComboBox1->Text + ">���Գɹ���");
else
   Memo1->Lines->Add("�޷����ã�����ȷ�ϴ��ļ�·�������ơ�");
//����ָ���ļ�����
Memo1->Lines->Add("�ļ�����·����" + FileListBox1->FileName);
}
//---------------------------------------------------------------------------

