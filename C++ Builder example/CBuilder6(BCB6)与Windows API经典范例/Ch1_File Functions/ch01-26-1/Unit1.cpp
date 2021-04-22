//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm1 *Form1;
// �궨��----------------------------------------------------------------------
#define max(a, b)  (((a) > (b)) ? (a) : (b))
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
    : TForm(Owner)
{
//Ŀ¼�����Ҳ���ڸ������ Properties ��ֱ������
/*
  DirectoryListBox1->FileList = FileListBox1;
  DriveComboBox1->DirList = DirectoryListBox1;
*/
//Ĭ�ϳ���ʼʱ��Ŀ¼
DriveComboBox1->Drive = 'C';
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
//ȡ��ѡȡ��Ŀ¼·��
char* dir = DirectoryListBox1->GetItemPath(DirectoryListBox1->ItemIndex).c_str();
//Ԥ��ָ��ɾ�����ǰһĿ¼λ�ã�maxΪ�Զ����
int nextdir = max(DirectoryListBox1->ItemIndex - 1, 0);
//ɾ��ָ��Ŀ¼
if (::RemoveDirectory(dir))
   {
   if(MessageDlg("��Ҫɾ�����ָ��Ŀ¼��", mtConfirmation,
                 TMsgDlgButtons() << mbYes << mbNo,
                 0) == mrYes)
        {
         DirectoryListBox1->Update();
         //ȡ��ɾ�����ǰһĿ¼λ��
         DirectoryListBox1->ItemIndex = nextdir;
         //��ɾ�����ǰһĿ¼
         DirectoryListBox1->OpenCurrent();
        }
   }
else
    ShowMessage("ɾ�����ָ��Ŀ¼ǰ��\n����ɾ���ں��ļ���");

}
//---------------------------------------------------------------------------
