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
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

for(int i=0; i<FileListBox1->Items->Count; i++)
   {
   //��һ����ѡȡ���ļ�
   if( FileListBox1->Selected[i] )
      {
      //ȡ������·��&����
      AnsiString FName = FileListBox1->Directory + "\\" + FileListBox1->Items->Strings[i];
      //ȡ������·��&����
      AnsiString billet = FileListBox2->Directory + "\\" + FileListBox1->Items->Strings[i];
      //���ƴ��ļ�����Ŀ¼��
      ::CopyFile( FName.c_str(), billet.c_str(), false);
      //ɾ��ԭĿ¼��ͬ�ļ�
      ::DeleteFile(FName.c_str());
      }
   }
//���ļ������
FileListBox1->Update();
FileListBox2->Update();
}
//---------------------------------------------------------------------------

