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
//ɾ��ListBox1��������
ListBox1->Clear();
//�Ƚ�����·��(AnsiString)ת�� char�ַ���
int leng = FileListBox1->FileName.Length();
char filename[MAX_PATH];
for(int i=0;i<=leng;i++)
    {
    if(i==leng)
       filename[i] = '\0';
    else
       filename[i] = FileListBox1->FileName[i+1];
    }
//��ʾ�ļ�����·��
ListBox1->Items->Add("�ļ�����·��:");
ListBox1->Items->Add(AnsiString(filename));
OFSTRUCT ofs;
//ȡ��ָ���ļ�handle
HFILE HMyFile = ::OpenFile(filename, &ofs, OF_READ);
//��ȡ�ô��ļ���С
double fsize = (double)::GetFileSize((void *)HMyFile, NULL);

AnsiString strsize;
if ( fsize < 1024)
    {
    strsize = FloatToStrF(fsize, ffNumber, 20, 0);
    ListBox1->Items->Add("�ļ���С:" + strsize + "���ֽ���");
    }
else if (fsize < (1024*1024))
    {
    strsize = FloatToStrF((fsize/1024), ffNumber, 20, 0);
    ListBox1->Items->Add("�ļ���С " + strsize + " KB");
    }
else
    {
    strsize = FloatToStrF(fsize/(1024*1024),ffNumber, 20,2);
    ListBox1->Items->Add("�ļ���С " + strsize + " MB");
    }

}
//---------------------------------------------------------------------------
