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
//�㼯��Դ·��
AnsiString target = DirectoryListBox2->Directory+"\\"+FileEdit->Text;
//��ָ���ļ�������Ŀ��Ŀ¼��
if(::CopyFile(FileListBox1->FileName.c_str(),//Ŀ��·��
             target.c_str(),// ԭ��Դ·��λ��
             true) == 0)
         {
         ShowMessage("ָ��Ŀ¼������ͬ�ļ���\n�����޷������ļ���");
         }
//��Ŀ���������
FileListBox2->Update();
}
//---------------------------------------------------------------------------


